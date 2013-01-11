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
	n:=scanint()
	for i:=0; i<n; i++{
		y:=scanint()-1
		m:=scanint()-1
		d:=scanint()
		r:=0
		if y%3!=2{r=m/2}
		fmt.Printf("%d\n",196471-y*195-y/3*5-m*20+r-d)
	}
}