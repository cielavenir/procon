//usr/bin/env swift $0 $@;exit
import CoreFoundation
func reversedArray<T>(_ a:[T]) -> [T] {
#if swift(>=3.0)
	return a.reversed()
#else
	return a.reverse()
#endif
}

let T=["dream","dreamer","erase","eraser"].map{reversedArray(Array($0.characters))}
let s=reversedArray(Array(readLine()!.characters))
var c=0
while c<s.count {
	var k:[Character]?=nil
	for e in T {
		let se=e.count
		let ss=s.count-c
		if se<=ss {
#if swift(>=4.0)
			//swift4は下でもいいんですがこちらのほうが読みやすいですよね
			if Array(s[c..<c+se])==e {
				k=e
				break
			}
#else
			var ce=0
			while ce<se {
				if s[c+ce] != e[ce] {break}
				ce+=1
			}
			if ce==se {
				k=e
				break
			}
#endif
		}
	}
	if k==nil {
		print("NO")
		exit(0)
	}
	c+=k!.count
}
print("YES")
