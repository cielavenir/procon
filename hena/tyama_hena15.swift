//usr/bin/env xcrun swift $0 $@;exit

//#!/usr/bin/env xcrun swift
//http://qiita.com/Nabetani/items/cba03c96d1ea55f6e861
//http://nabetani.sakura.ne.jp/hena/ord15elebubo/
import Darwin
var v:[UInt]=[0,0] // I cannot specify the array size...
var i=0,j=0
for ;(withUnsafePointer(&v[0]){vscanf("%08x",getVaList([COpaquePointer($0)]))}>0); {
	withUnsafePointer(&v[1]){vscanf("/%08x",getVaList([COpaquePointer($0)]))}
	var a:[[Int]]=[[],[]]
	for i=0;i<2;i++ {
		for j=0;j<32;j++ {
			a[i].append( Int((v[i]>>(31-j))&1) )
		}
		a[i].append(0)
		a[i].append(0)
	}

	for i=0;i<32; {
		if a[0][i] == 0 && a[1][i] == 0 {
			i++
		} else if a[0][i] != 0 && a[1][i] != 0 { //need space; otherwise treated as "a[0][i]!"
			if a[0][i+1] != 0 {
				if a[0][i+2] != 0 {
					print("N")
					i+=3
				} else {
					print("R")
					i+=2
				}
			} else if a[1][i+1] != 0 {
				if a[1][i+2] != 0 {
					print("U")
					i+=3
				}else{
					print("L")
					i+=2
				}
			}
		} else if a[0][i] != 0 {
			if a[0][i+2] != 0 {
				print("T")
				i+=3
			} else { //if a[1][i+2] != 0
				print("Z")
				i+=3
			}
		} else {
			if a[0][i+2] != 0 {
				print("S")
				i+=3
			} else {
				print("J")
				i+=2
			}
		}
	}
	println()
	fflush(stdout)
}