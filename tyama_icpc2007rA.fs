open System
let mutable arg:String array=Console.ReadLine().Split(' ')
let mutable n=int(arg.[0])
while n>0 do
 let mutable r=0
 let k=int(arg.[1])
 let m=int(arg.[2])
 for i in 1..n-1 do
  r<-(r+k)%i
 Console.WriteLine((r+m)%n+1)
 arg<-Console.ReadLine().Split(' ')
 n<-int(arg.[0])