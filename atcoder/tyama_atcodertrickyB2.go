//usr/bin/env go run $0 $@;exit
package main
/*
//acknowledgement: http://stackoverflow.com/questions/20128297/use-variadic-c-functions-in-go
#include <stdio.h>
long long scanlld(){
	long long a;
	scanf("%lld",&a);
	return a;
}
*/
import "C"
import(
	"fmt"
	"math"
)

//acknowledgement: https://stackoverflow.com/questions/19979178/what-is-the-idiomatic-go-equivalent-of-cs-ternary-operator/#45886594
func IIf(statement bool, a, b interface{}) interface{}{
	if statement {
		return a
	}
	return b
}

func main(){
	T:=int(C.scanlld())
	for ;T>0;T-- {
		a:=int64(C.scanlld())
		b:=int64(C.scanlld())
		c:=int64(C.scanlld())
		if a==0 {
			fmt.Println(IIf(b==0,
				IIf(c==0,"3","0"),
				fmt.Sprintf("1 %.12f",float64(-c)/float64(b)),
			).(string))
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
