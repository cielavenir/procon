//usr/bin/env swift $0 $@;exit
let n=Int(readLine()!)!
var arr=readLine()!.characters.split{$0==" "}.map{Int(String($0))!}
var r=1<<30
for i in 0..<n {
	var r0=0
	while (arr[i]%2)<1 {
		arr[i]/=2
		r0+=1
	}
	if r>r0 {r=r0}
}
print(r)
