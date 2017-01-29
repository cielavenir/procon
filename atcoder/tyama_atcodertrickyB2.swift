//usr/bin/env swift $0 $@;exit
import CoreFoundation
//import Foundation
//Note: String(format:) is not implemented on Linux
var T=0
var a:Int64=0
var b:Int64=0
var c:Int64=0
_=withUnsafePointer(to:&T){withVaList([OpaquePointer($0)]){vscanf("%d",$0)}}
//=Int(readLine()!)!
for var i in 0..<T {
	_=withUnsafePointer(to:&a){withVaList([OpaquePointer($0)]){vscanf("%lld",$0)}}
	_=withUnsafePointer(to:&b){withVaList([OpaquePointer($0)]){vscanf("%lld",$0)}}
	_=withUnsafePointer(to:&c){withVaList([OpaquePointer($0)]){vscanf("%lld",$0)}}
	//var _a=readLine()!.characters.split{$0==" "}
	//a=Int64(String(_a[0]))!
	//b=Int64(String(_a[1]))!
	//c=Int64(String(_a[2]))!
	if a==0 {
		if b==0 {print(c != 0 ? "0" : "3")}
		else {
			_=withVaList([-Double(c)/Double(b)]){vprintf("1 %.12f\n",$0)}
			//print(String(format:"1 %.12f",-Double(c)/Double(b)))
		}
	} else{ 
		if a<0 {
			a = -a
			b = -b
			c = -c
		}
		var d=Double(b)*Double(b)-4.0*Double(a)*Double(c)
		if fabs(d)<1e-9 {
			_=withVaList([-Double(b)/2.0/Double(a)]){vprintf("1 %.12f\n",$0)}
			//print(String(format: "1 %.12f",-Double(b)/2.0/Double(a)))
		}
		else if d<0 {print("0")}
		else{
			// acknowledgement: http://tricky.contest.atcoder.jp/submissions/120839
			var x=0.0,y=0.0;
			if b>0 {
				x = (-Double(b)-sqrt(d))/2/Double(a)
				y = Double(c)/Double(a)/x
			}else{
				y = (-Double(b)+sqrt(d))/2/Double(a)
				x = Double(c)/Double(a)/y
			}
			_=withVaList([x]){vprintf("2 %.12f ",$0)}
			_=withVaList([y]){vprintf("%.12f\n",$0)}
			//print(String(format: "2 %.12f %.12f",x,y))
		}
	}
}
