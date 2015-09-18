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
			a[i].append( Int((v[i]>>UInt(31-j))&1) )
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
					print("N",terminator:"")
					i+=3
				} else {
					print("R",terminator:"")
					i+=2
				}
			} else if a[1][i+1] != 0 {
				if a[1][i+2] != 0 {
					print("U",terminator:"")
					i+=3
				}else{
					print("L",terminator:"")
					i+=2
				}
			}
		} else if a[0][i] != 0 {
			if a[0][i+2] != 0 {
				print("T",terminator:"")
				i+=3
			} else { //if a[1][i+2] != 0
				print("Z",terminator:"")
				i+=3
			}
		} else {
			if a[0][i+2] != 0 {
				print("S",terminator:"")
				i+=3
			} else {
				print("J",terminator:"")
				i+=2
			}
		}
	}
	print("")
	fflush(stdout)
}