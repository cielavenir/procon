//usr/bin/env swift $0 $@;exit
let arr=readLine()!.characters.split{$0==" "}.map{Int(String($0))!}
let a=arr[0]
let b=arr[1]
print(a*b%2>0 ? "Odd" : "Even")
