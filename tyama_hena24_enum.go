package main
import (
	"fmt"
	"math"
	"bufio"
	"os"
)

func generate() <-chan int{
	ch := make(chan int)
	go func(){
		i:=1
		for {
			ch <- i
			i++
		}
	}()
	return ch
}

func drop_prev_square(prev <-chan int) <-chan int{
	ch := make(chan int)
	go func(){
		a:=<-prev
		b:=<-prev
		for {
			x:=int(math.Sqrt(float64(b)))
			if x*x!=b { ch<-a }
			a=b
			b=<-prev
		}
	}()
	return ch
}

func drop_next_square(prev <-chan int) <-chan int{
	ch := make(chan int)
	go func(){
		a:=<-prev
		b:=<-prev
		ch<-a
		for {
			x:=int(math.Sqrt(float64(a)))
			if x*x!=a { ch<-b }
			a=b
			b=<-prev
		}
	}()
	return ch
}

func drop_prev_cubic(prev <-chan int) <-chan int{
	ch := make(chan int)
	go func(){
		a:=<-prev
		b:=<-prev
		for {
			x:=int(math.Cbrt(float64(b)))
			if x*x*x!=b { ch<-a }
			a=b
			b=<-prev
		}
	}()
	return ch
}

func drop_next_cubic(prev <-chan int) <-chan int{
	ch := make(chan int)
	go func(){
		a:=<-prev
		b:=<-prev
		ch<-a
		for {
			x:=int(math.Cbrt(float64(a)))
			if x*x*x!=a { ch<-b }
			a=b
			b=<-prev
		}
	}()
	return ch
}

func drop_num(n int,prev <-chan int) <-chan int{
	ch := make(chan int)
	go func(){
		i:=0
		for {
			i++
			a:=<-prev
			if i%n!=0 { ch<-a }
		}
	}()
	return ch
}

func drop_cnt(n int,prev <-chan int) <-chan int{
	ch := make(chan int)
	go func(){
		i:=0
		for {
			i++
			a:=<-prev
			if i>n { ch<-a }
		}
	}()
	return ch
}

func main(){
	f:=map[int]func(<-chan int)<-chan int{
		'S': drop_next_square,
		's': drop_prev_square,
		'C': drop_next_cubic,
		'c': drop_prev_cubic,
		'h': func(prev <-chan int)<-chan int{return drop_cnt(100,prev)},
	}
	for i:=2;i<10;i++ {
		j:=i //寿命が短いスコープを作ることで、ラムダ式のキャプチャでバグらないようにする。
		f[j+'0']=func(prev <-chan int)<-chan int{return drop_num(j,prev)}
	}

	sin:=bufio.NewReader(os.Stdin)
	_line,_,_:=sin.ReadLine()
	line:=string(_line)
	for line!="" {
		ch := generate()
		for _,c:=range(line) {
			ch=f[int(c)](ch)
		}
		for i:=0;i<10;i++ {
			if i>0 { fmt.Print(",") }
			a:=<-ch
			fmt.Printf("%d",a)
		}
		fmt.Println()
		_line,_,_=sin.ReadLine()
		line=string(_line)
	}
}