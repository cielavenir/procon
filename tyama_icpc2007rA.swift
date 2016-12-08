//usr/bin/env swift $0 $@;exit
import CoreFoundation
var n=0,k=0,m=0,r=0,i=0
_=withUnsafeMutablePointer(to:&n){withVaList([OpaquePointer($0)]){vscanf("%d",$0)}}
while n>0 {
	_=withUnsafeMutablePointer(to:&k){withVaList([OpaquePointer($0)]){vscanf("%d",$0)}}
	_=withUnsafeMutablePointer(to:&m){withVaList([OpaquePointer($0)]){vscanf("%d",$0)}}
	r=0
	for i in 1..<n {r+=k;r%=i}
	print((r+m)%n+1)
	_=withUnsafeMutablePointer(to:&n){withVaList([OpaquePointer($0)]){vscanf("%d",$0)}}
}
