//usr/bin/env swift $0 $@;exit
let n=Int(readLine()!)!
var arr:[Int]=[]
for _ in 0..<n {
	arr.append(Int(readLine()!)!)
}
#if swift(>=3.0)
arr=arr.sorted()
#else
arr=arr.sort()
#endif
var r=1
var t=arr[0]
for i in 1..<n {
	if t != arr[i] {
		t=arr[i]
		r+=1
	}
}
print(r)
