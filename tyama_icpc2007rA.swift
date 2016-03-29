//usr/bin/env swift $0 $@;exit
import CoreFoundation
var n=0,k=0,m=0,r=0,i=0
withUnsafeMutablePointer(&n){withVaList([COpaquePointer($0)]){vscanf("%d",$0)}}
while n>0 {
	withUnsafeMutablePointer(&k){withVaList([COpaquePointer($0)]){vscanf("%d",$0)}}
	withUnsafeMutablePointer(&m){withVaList([COpaquePointer($0)]){vscanf("%d",$0)}}
	r=0
	for i=0;++i<n;r%=i {r+=k}
	print((r+m)%n+1)
	withUnsafeMutablePointer(&n){withVaList([COpaquePointer($0)]){vscanf("%d",$0)}}
}