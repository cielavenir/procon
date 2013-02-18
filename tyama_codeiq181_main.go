package main

import "fmt"
import "./comb"

func main(){
	strs := []string{"A", "B", "C", "D", "E"}
	for i := range comb.CombinationGenerator(5,2){
		var actual []string
		i.Index(strs,&actual)
		fmt.Printf("%v\n", actual)
	}
}