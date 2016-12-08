//usr/bin/env swift $0 $@;exit
var n=Int(readLine()!)!
while n>0 {
	var ma=0
	var mi=1000
	var sum=0
	for i in 0..<n {
		var s=Int(readLine()!)!
		if ma<s {ma=s}
		if mi>s {mi=s}
		sum+=s
	}
	print((sum-ma-mi)/(n-2))
	n=Int(readLine()!)!
}
