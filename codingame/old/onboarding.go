//usr/bin/env go run $0 $@;exit
package main
import "fmt"

func main() {
	for {
		name := ""
		mi := 9999999
		var count int
		fmt.Scan(&count)

		for i := 0; i < count; i++ {
			var enemy string
			var dist int
			fmt.Scan(&enemy, &dist)
			if mi>dist {
				mi=dist
				name=enemy
			}
		}
		fmt.Println(name)
	}
}