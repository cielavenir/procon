//usr/bin/env swift $0 $@;exit
import CoreFoundation
let arr=readLine()!.characters.split{$0==" "}.map{Int(String($0))!}
let n=arr[0]
let y=arr[1]
for i in 0...n {
	for j in 0...n-i {
		let k=n-i-j
		if i*1000+j*5000+k*10000==y {
			print(k,terminator:" ")
			print(j,terminator:" ")
			print(i)
			exit(0)
		}
	}
}
print("-1 -1 -1")
