//usr/bin/env go run $0 $@;exit
package main
import(
	"os"
	"bufio"
	"fmt"
	"strings"
	"regexp"
)

func main(){
	reader:=bufio.NewReader(os.Stdin)
	pat:=regexp.MustCompile(`X(\.*?)Y`)
	for {
		s,err := reader.ReadString('\n')
		//if err!=nil {break}
		a:=strings.Split(s,",")
		ret:=999
		for _,x:=range(a) {
			s=pat.FindString(x)
			if ret>len(s) {ret=len(s)}
		}
		fmt.Println(ret-2)
		if err!=nil {break}
	}
}