//usr/bin/env go run $0 $@;exit
package main
import(
	"fmt"
	"os"
	"text/scanner"
	"strconv"
)

var sin scanner.Scanner
func scanint() int{
	sin.Scan()
	ret,_ := strconv.Atoi(sin.TokenText())
	return ret
}
func main(){
	sin.Init(os.Stdin)
	for {
		n:=scanint()
		k:=scanint()
		m:=scanint()
		if n==0 {break}
		r:=0
		for i:=1;i<n;i++ {r=(r+k)%i}
		fmt.Printf("%d\n",(r+m)%n+1)
	}
}