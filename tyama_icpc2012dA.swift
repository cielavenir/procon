//usr/bin/env swift $0 $@;exit
import CoreFoundation
var t=0,y=0,m=0,d=0
_=withUnsafeMutablePointer(to:&t){withVaList([OpaquePointer($0)]){vscanf("%d",$0)}}
for i in 0..<t {
	_=withUnsafeMutablePointer(to:&y){withVaList([OpaquePointer($0)]){vscanf("%d",$0)}}
	_=withUnsafeMutablePointer(to:&m){withVaList([OpaquePointer($0)]){vscanf("%d",$0)}}
	_=withUnsafeMutablePointer(to:&d){withVaList([OpaquePointer($0)]){vscanf("%d",$0)}}
	y-=1
	m-=1
	print(196471-y*195-y/3*5-m*20+(y%3-2>0 ? m/2 : 0)-d)
}
