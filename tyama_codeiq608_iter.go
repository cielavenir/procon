//usr/bin/env go run $0 $@;exit
package main
import (
	"fmt"
	"sort"
	"reflect"
)

/*
func compare(a interface{},b interface{}) int{ // a and b must have the same type. If different, runtime error will be triggered. will be fixed after generics is introduced.
	switch reflect.ValueOf(a).Kind() {
		case reflect.Int:
			n1:=reflect.ValueOf(a).Int()
			n2:=reflect.ValueOf(b).Int()
			if n1<n2 {return -1} else if n1>n2 {return 1} else {return 0}
		case reflect.Float32: case reflect.Float64:
			n1:=reflect.ValueOf(a).Float()
			n2:=reflect.ValueOf(b).Float()
			if n1<n2 {return -1} else if n1>n2 {return 1} else {return 0}
		case reflect.String:
			n1:=reflect.ValueOf(a).String()
			n2:=reflect.ValueOf(b).String()
			if n1<n2 {return -1} else if n1>n2 {return 1} else {return 0}
	}
	return 0 //lol
}
func reflect_reverse(a reflect.Value,start int,size int){
	for end:=start+size-1;start<end;start++ {
		z:=a.Index(start).Interface()
		a.Index(start).Set(a.Index(end))
		a.Index(end).Set(reflect.ValueOf(z))
		end--
	}
}
func permutation(x interface{}, n int) <- chan reflect.Value{
	ch := make(chan reflect.Value)
	go func(){
		if 0<=n&&n<=reflect.ValueOf(x).Len() {
			a:=reflect.MakeSlice(reflect.TypeOf(x),reflect.ValueOf(x).Len(),reflect.ValueOf(x).Len())
			reflect.Copy(a,reflect.ValueOf(x))
			//sort.Sort(sort.IntSlice(a)); //interface{} cannot be sorted, so you must sort the array prior.
			ch <- a
			for {
				reflect_reverse(a,n,a.Len()-n)
				i:=0
				for i=a.Len()-2;i>=0;i-- {if compare(a.Index(i).Interface(),a.Index(i+1).Interface())<0 {break}}
				if i<0 {
					//reflect_reverse(a,0,a.Len())
					break
				}
				k:=i
				for i=a.Len()-1;i>=k+1;i-- {if compare(a.Index(k).Interface(),a.Index(i).Interface())<0 {break}}
				l:=i
				z:=a.Index(k).Interface()
				a.Index(k).Set(a.Index(l))
				a.Index(l).Set(reflect.ValueOf(z))
				reflect_reverse(a,k+1,a.Len()-(k+1))
				ch <- a
			}
		}
		close(ch)
	}()
	return ch
}
*/
func reverse(a sort.Interface,start int,size int){
	for end:=start+size-1;start<end;start++ {
		a.Swap(start,end)
		end--
	}
}
func permutation(a sort.Interface, n int) <- chan reflect.Value{
	ch := make(chan reflect.Value)
	go func(){
		if 0<=n&&n<=a.Len() {
			sort.Sort(a); // a is modified directly, so never write to it within the block
			ch <- reflect.ValueOf(a)
			for {
				reverse(a,n,a.Len()-n)
				i:=0
				for i=a.Len()-2;i>=0;i-- {if a.Less(i,i+1) {break}}
				if i<0 {
					reverse(a,0,a.Len())
					break
				}
				k:=i
				for i=a.Len()-1;i>=k+1;i-- {if a.Less(k,i) {break}}
				l:=i
				a.Swap(k,l)
				reverse(a,k+1,a.Len()-(k+1))
				ch <- reflect.ValueOf(a)
			}
		}
		close(ch)
	}()
	return ch
}

func main(){
	N:=6
	e0:=make([]int,N*2)
	f0:=make([]int,N*2)
	i:=0
	r:=0
	for i=0;i<N;i++ {e0[N+i]=1;f0[N+i]=1}
	e:=make([]int,N*2+1);
	f:=make([]int,N*2+1);
	for _e:=range permutation(sort.IntSlice(e0),len(e0)) {
		for i=0;i<N*2;i++ {e[i+1]=e[i]+_e.Index(i).Interface().(int)}
		for _f:=range permutation(sort.IntSlice(f0),len(f0)) {
			for i=0;i<N*2;i++ {
				f[i+1]=f[i]+_f.Index(i).Interface().(int)
				if e[i]==f[i]&&e[i+1]==f[i+1] {break}
			}
			if i==N*2 {r++}
		}
	}
	fmt.Println(r)
}