//usr/bin/env swift $0 $@;exit
let arr=readLine()!.characters.split{$0==" "}.map{Int(String($0))!}
let n=arr[0]
let a=arr[1]
let b=arr[2]
var r=0
for i in 1...n {
	var j=i
	var s=0
	while j>0 {
		s+=j%10
		j/=10
	}
	if a<=s&&s<=b {r+=i}
}
print(r)
