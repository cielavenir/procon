//usr/bin/env swift $0 $@;exit
let n=Int(readLine()!)!
var arr=readLine()!.characters.split{$0==" "}.map{Int(String($0))!}
#if swift(>=3.0)
arr=arr.sorted{$0>$1}
#else
arr=arr.sort{$0>$1}
#endif
var r=0
var t=1
for i in 0..<n {
	r+=t*arr[i]
	t=(-t)
}
print(r)
