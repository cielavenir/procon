//usr/bin/env swift $0 $@;exit
while true {
	let enemy1 = readLine()!
	let dist1 = Int(readLine()!)!
	let enemy2 = readLine()!
	let dist2 = Int(readLine()!)!

	print(dist1<dist2 ? enemy1 : enemy2)
}