//usr/bin/env go run $0 $@;exit
package main
import(
	"fmt"
	"math"
)

func main(){
	T:=0
	fmt.Scan(&T)
	for ;T>0;T-- {
		a:=int64(0)
		b:=int64(0)
		c:=int64(0)
		fmt.Scan(&a,&b,&c)
		if a==0 {
			if b==0 {
				if c==0 {
					fmt.Println("3")
				} else {
					fmt.Println("0")
				}
			} else {
				fmt.Printf("1 %.12f\n",float64(-c)/float64(b))
			}
		} else {
			if a<0 {
				a=-a
				b=-b
				c=-c
			}
			d:=float64(b*b)-4.0*float64(a*c)
			a2:=float64(a*2)
			if math.Abs(d)<1e-9 {
				fmt.Printf("1 %.12f\n",float64(-b)/a2)
			} else if d<0 {
				fmt.Println("0")
			} else {
				// acknowledgement: http://tricky.contest.atcoder.jp/submissions/120839
				x:=0.0
				y:=0.0
				if b>0 {
					x=(float64(-b)-math.Sqrt(d))/a2
					y=float64(c)/float64(a)/x
				} else {
					y=(float64(-b)+math.Sqrt(d))/a2
					x=float64(c)/float64(a)/y
				}
				fmt.Printf("2 %.12f %.12f\n",x,y)
			}
		}
	}
}