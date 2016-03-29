//usr/bin/env swift $0 $@;exit
import CoreFoundation
var n=0
withUnsafeMutablePointer(&n){withVaList([COpaquePointer($0)]){vscanf("%d",$0)}}
while n>0 {
	var ma=0
	var mi=1000
	var sum=0
	var s=0
	for i in 0..<n {
		withUnsafeMutablePointer(&s){withVaList([COpaquePointer($0)]){vscanf("%d",$0)}}
		if ma<s {ma=s}
		if mi>s {mi=s}
		sum+=s
	}
	print((sum-ma-mi)/(n-2))
	withUnsafeMutablePointer(&n){withVaList([COpaquePointer($0)]){vscanf("%d",$0)}}
}