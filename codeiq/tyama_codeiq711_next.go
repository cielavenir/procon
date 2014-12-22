//usr/bin/env go run $0 $@;exit
package main
import (
	"fmt"
	"sort"
)

func reverse(a sort.Interface,start int,size int){
	for end:=start+size-1;start<end;start++ {
		a.Swap(start,end)
		end--
	}
}
func next_permutation(a sort.Interface, n int) bool{
	if n<0||a.Len()<n {return false}
	reverse(a,n,a.Len()-n)
	i:=0
	for i=a.Len()-2;i>=0;i-- {if a.Less(i,i+1) {break}}
	if i<0 {
		reverse(a,0,a.Len())
		return false
	}
	k:=i
	for i=a.Len()-1;i>=k+1;i-- {if a.Less(k,i) {break}}
	l:=i
	a.Swap(k,l)
	reverse(a,k+1,a.Len()-(k+1))
	return true
}

func main(){
	N:=6
	e0:=make([]int,N*2)
	f0:=make([]int,N*2)
	i:=0
	r:=0
	for i=0;i<N;i++ {e0[N+i]=1;f0[N+i]=1}
	sort.Sort(sort.IntSlice(e0))
	sort.Sort(sort.IntSlice(f0))
	for {
		for {
			flg:=0
			zero1:=0
			zero2:=N
			one1:=0
			one2:=N
			for i:=0;i<N*2;i++ {
				if e0[i]==0 {zero1 += 1}
				if e0[i]==1 {one1  += 1}
				if f0[i]==0 {zero2 -= 1}
				if f0[i]==1 {one2  -= 1}
				if zero1==zero2 {flg+=1}
				if one1==one2 {flg+=1}
			}
			if flg>=2 {r+=1}
			if !next_permutation(sort.IntSlice(f0),len(f0)) {break}
		}
		if !next_permutation(sort.IntSlice(e0),len(e0)) {break}
	}
	fmt.Println(r)
}