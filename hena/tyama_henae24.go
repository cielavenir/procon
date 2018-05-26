//usr/bin/env go run $0 $@;exit
//http://nabetani.sakura.ne.jp/hena/orde24tancho/
//https://qiita.com/Nabetani/items/928d6a94d83c21ef64d7

package main
import (
	"fmt"
	"os"
)

//acknowledgement: https://stackoverflow.com/questions/19979178/what-is-the-idiomatic-go-equivalent-of-cs-ternary-operator/#45886594
func IIf(statement bool, a, b interface{}) interface{}{
	if statement {
		return a
	}
	return b
}

func comb(n int,k int) int64{
	var r int64=1
	for i:=0;i<k;i++ {
		r=r*int64(n-i)/int64(i+1)
	}
	return r
}
func main(){
	b:=0
	var n int64
	for ;; {
		c,_:=fmt.Scanf("%d,%d",&b,&n)
		if c<2 {break}
		b-=1
		n-=1
		topdigit:=1
		for ;; {
			x:=comb(b,topdigit)
			if b<topdigit || x>n {break}
			n-=x
			topdigit++
		}
		if(b<topdigit){
			fmt.Print("-\n")
			os.Stdout.Sync()
			continue;
		}
		topdigit--
		curnumber:=0
		for d:=topdigit;d>=0;d-- {
			curnumber++
			for ;; {
				x:=comb(b-curnumber,d)
				if x>n {break}
				n-=x
				curnumber++
			}
			fmt.Printf("%c",curnumber+IIf(curnumber<10,48,87).(int));
		}
		fmt.Print("\n");
		os.Stdout.Sync()
	}
}
