//usr/bin/env swift $0 $@;exit
let a=Int(readLine()!)!
let arr=readLine()!.characters.split{$0==" "}.map{Int(String($0))!}
let b=arr[0]
let c=arr[1]
print(a+b+c,terminator:"")
print(" ",terminator:"")
print(readLine()!)
