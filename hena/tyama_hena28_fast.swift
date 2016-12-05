//usr/bin/env swift $0 $@;exit
// http://qiita.com/Nabetani/items/23ebddb44f0234e7fb15
// http://nabetani.sakura.ne.jp/hena/ord28spirwa/

import CoreFoundation
let dir="ESWN"
var	n=0,e=0,s=0,w=0;
var days: Int64=0
while (withUnsafePointer(&n){vscanf("%d",getVaList([COpaquePointer($0)]))}>0) {
	withUnsafePointer(&e){vscanf(",%d",getVaList([COpaquePointer($0)]))}
	withUnsafePointer(&s){vscanf(",%d",getVaList([COpaquePointer($0)]))}
	withUnsafePointer(&w){vscanf(",%d",getVaList([COpaquePointer($0)]))}
	withUnsafePointer(&days){vscanf(":%lld",getVaList([COpaquePointer($0)]))}
	days+=1
	let l=[e,s,w,n]
	var	f=1
	var i=0
	while f != 0 {
		let a=l[i%4]+((i+3)%4/3)
		let b=(i/4+1)*2
		let c=l[i%4]-(i%4/3)
		let x=[a,b,c]
		for var j in 0..<3 {
			if days-x[j]<0 {
				print(dir[dir.startIndex.advancedBy((i+j)%4)])
				f=0
				break
			}
			days-=x[j]
		}
		i+=1
	}
	fflush(stdout)
}
