//usr/bin/env swift $0 $@;exit
let s=Array(readLine()!.characters)
var c=0
for i in 0..<3 {
	if s[i]==Character("1") {
		c+=1
	}
}
print(c)
