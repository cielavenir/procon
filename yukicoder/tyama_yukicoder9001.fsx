//usr/bin/env fsharpi $0 $@;exit
open System;
let a:String array=Console.ReadLine().Split(' ')
Console.Write(int(a.[0])+int(a.[1]))
Console.WriteLine(" "+Console.ReadLine())