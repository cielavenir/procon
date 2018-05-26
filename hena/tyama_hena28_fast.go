//usr/bin/env go run $0 $@;exit
// http://qiita.com/Nabetani/items/23ebddb44f0234e7fb15
// http://nabetani.sakura.ne.jp/hena/ord28spirwa/

package main
/*
//acknowledgement: http://stackoverflow.com/questions/20128297/use-variadic-c-functions-in-go
#include <stdio.h>
int myscanf(int *a,int *b,int *c,int *d,long long *e){
	return scanf("%d,%d,%d,%d:%lld",a,b,c,d,e);
}
*/
import "C"
import (
	"unsafe"
	"fmt"
	"os"
)

func main(){
	dir:="ESWN";
	n:=0;e:=0;s:=0;w:=0;
	var days int64;
	for ;; {
		//c,_:=fmt.Scanf("%d,%d,%d,%d:%lld",&n,&e,&s,&w,&days)
		c:=int(C.myscanf((*C.int)(unsafe.Pointer(&n)),(*C.int)(unsafe.Pointer(&e)),(*C.int)(unsafe.Pointer(&s)),(*C.int)(unsafe.Pointer(&w)),(*C.longlong)(unsafe.Pointer(&days))))
		if c<5 {break}

		days+=1
		l:=[4]int{e,s,w,n}
		f:=1
		for i:=0;f!=0;i++ {
			x:=[3]int{l[i%4]+((i+3)%4/3),(i/4+1)*2,l[i%4]-(i%4/3)}
			for j:=0;j<3;j++ {
				if days-int64(x[j])<0 {
					fmt.Printf("%c\n",dir[(i+j)%4])
					f=0
					break
				}
				days-=int64(x[j])
			}
		}
		os.Stdout.Sync()
	}
}
