//usr/bin/env v run $0 $@;exit

// http://qiita.com/Nabetani/items/1c83005a854d2c6cbb69
// http://nabetani.sakura.ne.jp/hena/ord24eliseq/

import os

fn isqrt(n int) int{
	if n<=0 {return 0}
	if n<4 {return 1}
	mut x:=0
	mut y:=n
	for x!=y && x+1!=y {x=y y=(n/y+y)/2}
	return x
}
fn icbrt(n int) int{
	if n<0 {return -icbrt(-n)}
	if n==0 {return 0}
	if n<8 {return 1}
	mut x:=0
	mut y:=n
	for x!=y && x+1!=y {x=y y=(n/y/y+y*2)/3}
	return x
}

fn is_sq(n int) bool{
	x:=isqrt(n)
	return x*x==n
}
fn is_cb(n int) bool{
	x:=icbrt(n)
	return x*x*x==n
}
fn is_multiple(i int,n int) bool{ return i%n==0 }
fn is_le(i int,n int) bool{ return i<=n }

fn generate_impl(ch chan int){
	mut i:=1
	for {
		ch <- i
		i++
	}
}

fn generate() chan int{
	ch := chan int{}
	go generate_impl(ch)
	return ch
}

fn drop_prev_impl(check fn(int)bool,prev chan int,ch chan int){
	mut a:=<-prev
	mut b:=<-prev
	for {
		if !check(b) { ch<-a }
		a=b
		b=<-prev
	}
}

fn drop_prev(check fn(int)bool,prev chan int) chan int{
	ch := chan int{}
	go drop_prev_impl(check,prev,ch)
	return ch
}

fn drop_next_impl(check fn(int)bool,prev chan int,ch chan int){
	mut a:=<-prev
	mut b:=<-prev
	ch<-a
	for {
		if !check(a) { ch<-b }
		a=b
		b=<-prev
	}
}
	
fn drop_next(check fn(int)bool,prev chan int) chan int{
	ch := chan int{}
	go drop_next_impl(check,prev,ch)
	return ch
}

fn drop_n_impl(check fn(int,int)bool,n int,prev chan int,ch chan int){
	mut i:=0
	for {
		i++
		a:=<-prev
		if !check(i,n) { ch<-a }
	}
}

fn drop_n(check fn(int,int)bool,n int,prev chan int) chan int{
	ch := chan int{}
	go drop_n_impl(check,n,prev,ch)
	return ch
}

fn main(){
	mut f:=map[string]fn(_ chan int)chan int{}

	//this anonymous function somehow causes C error.
	f['S']=fn(prev chan int)chan int{return drop_next(is_sq,prev)}
	f['s']=fn(prev chan int)chan int{return drop_prev(is_sq,prev)}
	f['C']=fn(prev chan int)chan int{return drop_next(is_cb,prev)}
	f['c']=fn(prev chan int)chan int{return drop_prev(is_cb,prev)}
	f['h']=fn(prev chan int)chan int{return drop_n(is_le,100,prev)}

	f['2']=fn(prev chan int)chan int{return drop_n(is_multiple,2,prev)}
	f['3']=fn(prev chan int)chan int{return drop_n(is_multiple,3,prev)}
	f['4']=fn(prev chan int)chan int{return drop_n(is_multiple,4,prev)}
	f['5']=fn(prev chan int)chan int{return drop_n(is_multiple,5,prev)}
	f['6']=fn(prev chan int)chan int{return drop_n(is_multiple,6,prev)}
	f['7']=fn(prev chan int)chan int{return drop_n(is_multiple,7,prev)}
	f['8']=fn(prev chan int)chan int{return drop_n(is_multiple,8,prev)}
	f['9']=fn(prev chan int)chan int{return drop_n(is_multiple,9,prev)}
/*
	//v does not implement closure (yet)
	for i:=2;i<10;i++ {
		j:=i
		f[j.str()]=fn(prev chan int)chan int{return drop_n(is_multiple,j.int(),prev)}
	}
*/

	mut line:=os.get_line()
	for line!="" {
		//cS => f['S'](f['c'](generate()))
		mut ch := generate()
		for c in line {
			//somehow I need to assign first or the source will not compile.
			z:=f[c.ascii_str()]
			ch=z(ch)
		}
		for i:=0;i<10;i++ {
			if i>0 { print(',') }
			print(<-ch)
		}
		println('')
		os.flush()
		line=os.get_line()
	}
}
