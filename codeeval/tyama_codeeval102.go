//usr/bin/env go run $0 $@;exit
package main
import(
	"os"
	"bufio"
	"encoding/json"
	"fmt"
)
type Item struct{
	Id int
	Label *string
}
type Menu struct{
	Header *string
	Items []*Item
}
type Data struct{
	Menu Menu
}

func main(){
	reader:=bufio.NewReader(os.Stdin)
	for {
		s,err := reader.ReadString('\n')
		if err!=nil { break }
		var data Data
		err = json.Unmarshal([]byte(s),&data)
		r:=0
		if err==nil {
			for _,item := range data.Menu.Items {
				if item!=nil && item.Label!=nil { r+=item.Id }
			}
		}
		fmt.Println(r)
	}
}