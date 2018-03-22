//usr/bin/env swift $0 $@;exit
let n=Int(readLine()!)!
var t=0
var x=0
var y=0
var r="Yes"
for i in 0..<n {
	let arr=readLine()!.characters.split{$0==" "}.map{Int(String($0))!}
	let t0=arr[0]
	let x0=arr[1]
	let y0=arr[2]
	let dt=t0-t
	let dx=x0-x
	let dy=y0-y
	if dx+dy>dt || (dt-dx-dy)%2>0 {r="No"}
	t=t0
	x=x0
	y=y0
}
print(r)
