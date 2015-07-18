open System
let n=int(Console.ReadLine())
for i in 1..n do
 let arg:String array=Console.ReadLine().Split(' ')
 let y=int(arg.[0])-1
 let m=int(arg.[1])-1
 let d=int(arg.[2])
 Console.WriteLine(196471-y*195-y/3*5-m*20+(if y%3<2 then m/2 else 0)-d)