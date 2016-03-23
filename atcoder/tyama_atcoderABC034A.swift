//usr/bin/env swift $0 $@;exit
import CoreFoundation

func getInt()->Int{
	var n:Int=0
	withUnsafeMutablePointer(&n){withVaList([COpaquePointer($0)]){vscanf("%d",$0)}}
	return n
}
var x=getInt(),y=getInt()
print(x<y ? "Better" : "Worse")