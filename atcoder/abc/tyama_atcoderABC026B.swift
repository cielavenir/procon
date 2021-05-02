//usr/bin/env swift $0 $@;exit

//import CoreFoundation
#if _runtime(_ObjC)
import Darwin
#else
import Glibc
#endif

func getInt()->Int{
	var n:Int=0
	withUnsafeMutablePointer(&n){withVaList([COpaquePointer($0)]){vscanf("%d",$0)}}
	return n
	//return Int(readLine()!)!
}
var n=getInt()
var a=[Int](count:n,repeatedValue:0)
for i in 0..<n {
	a[i]=getInt()
}
a.sortInPlace{$0>$1}
var r=0
var f=1
for i in 0..<n {
	r+=a[i]*a[i] * f
	f = -f
}
print(Double(r)*M_PI)