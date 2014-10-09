package comb
import "reflect"
//import "fmt"

//reference: https://github.com/mjard/combination/
//Mine is more optimized and I prefer chan-type API, which is more general.
type Combination []int
func CombinationGenerator(n int, k int) <- chan Combination {
	ch := make(chan Combination)
	go func(){
		if k<0 {k=0}
		if n<k {n=k} //fixme
		indexes := make([]int,k)
		for i := 0; i < k; i++ {
			indexes[i] = i
		}
		for indexes[0] <= n-k {
			c := make(Combination,k)
			//c.indexes = make([]int,k)
			for i := 0; i < k; i++ {
				c[i] = indexes[i]
			}
			ch <- c

			var i int
			for i=k-1;i>0&&indexes[i]==n-k+i;i-- {}
			indexes[i]++
			for i=i+1;i<k;i++ {
				indexes[i] = indexes[i-1] + 1
			}
		}
		close(ch)
	}()
	return ch
}

//reflect version: identical to original version.
func (comb Combination) Index(strs interface{},actual interface{}){
	s:=reflect.MakeSlice(reflect.TypeOf(strs),len(comb),len(comb))
	for i:=0;i<len(comb);i++ {
		s.Index(i).Set(reflect.ValueOf(strs).Index(comb[i]))
	}
	reflect.ValueOf(actual).Elem().Set(s)
}

/*
//original version
func (comb Combination) Index(strs []string,actual *[]string){
	s:=make([]string,len(comb))
	for i:=0;i<len(comb);i++ {
		s[i]=strs[comb[i]]
	}
	*actual=s
}
*/