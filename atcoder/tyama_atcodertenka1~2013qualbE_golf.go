//usr/bin/env go run $0 $@;exit
package main
import "fmt"
func main(){
	fmt.Println(100)
	fmt.Println("1 0")
	for i:=99;i>1;i-- {fmt.Printf("%d 0\n",i)}
	fmt.Println("0 0")
}