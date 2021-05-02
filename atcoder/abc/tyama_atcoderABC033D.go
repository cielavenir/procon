//usr/bin/env go run $0 $@;exit
package main
import(
	"fmt"
	"runtime"
)

var x [2000]int
var y [2000]int
var tbl [2000][2000]int
func S(n int) int{return n*n}
func main(){
	var N int
	fmt.Scanf("%d",&N)
	ch0 := make(chan int)
	ch1 := make(chan int)
	ch2 := make(chan int)
	for i:=0;i<N;i++ {fmt.Scanf("%d%d",&x[i],&y[i])}
	for i:=0;i<N;i++ {for j:=0;j<i;j++ {tbl[i][j]=S(x[i]-x[j])+S(y[i]-y[j])}}

	threads:=runtime.NumCPU()
	runtime.GOMAXPROCS(threads) // not required in Go 1.5+
	f:=func(start int){
		r0:=0
		r1:=0
		r2:=0
		for i:=start;i<N;i+=threads {for j:=0;j<i;j++ {for k:=0;k<j;k++ {
			a:=tbl[i][j]
			b:=tbl[j][k]
			c:=tbl[i][k]
			m:=a
			if m<b {m=b}
			if m<c {m=c}
			m=a+b+c-m-m
			if m>0 {
				r0++
			}else if m==0 {
				r1++
			}else if m<0 {
				r2++
			}
		}}}
		ch0<-r0
		ch1<-r1
		ch2<-r2
	}

	for start:=0;start<threads;start++ {
		go f(start)
	}
	//f(0) // avoid context switch //!?
	r0:=0
	r1:=0
	r2:=0
	for start:=0;start<threads;start++ {
		r0+=<-ch0
		r1+=<-ch1
		r2+=<-ch2
	}
	fmt.Printf("%d %d %d\n",r0,r1,r2);
}
