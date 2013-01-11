//tested with gccgo-4.6

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
	for num:=scanint(); num!=0; num=scanint(){
		sum:=0
		max:=0
		min:=1000
		for i:=0; i<num; i++{
			x:=scanint()
			sum+=x
			if min>x{min=x}
			if max<x{max=x}
		}
		fmt.Printf("%d\n",(sum-max-min)/(num-2))
	}
}