//usr/bin/env swift $0 $@;exit
let a=Int(readLine()!)!
let b=Int(readLine()!)!
let c=Int(readLine()!)!
let x=Int(readLine()!)!
var r=0
for i in 0...x/500 {
	for j in 0...(x-500*i)/100 {
		let k=x-500*i-100*j
		if k%50==0&&c>=k/50&&a>=i&&b>=j {r+=1}
	}
}
print(r)
