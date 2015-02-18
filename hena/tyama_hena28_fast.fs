// http://qiita.com/Nabetani/items/23ebddb44f0234e7fb15
// http://nabetani.sakura.ne.jp/hena/ord28spirwa/

open System
open System.Runtime.InteropServices

module libc =
 [<DllImport("c", CallingConvention = CallingConvention.Cdecl)>]
 extern int scanf(string format, int& a, int& b, int& c, int& d, int64& e)

let dir="ESWN"
let mutable n=0
let mutable e=0
let mutable s=0
let mutable w=0
let mutable days:int64=0L
while libc.scanf("%d,%d,%d,%d:%lld",&n,&e,&s,&w,&days)=5 do
 days<-days+1L
 let l:int array=[|e;s;w;n|]
 let mutable f=true
 let mutable i=0
 while f do
  let x:int array=[|l.[i%4]+(if i%4=0 then 1 else 0);(i/4+1)*2;l.[i%4]-(if i%4=3 then 1 else 0)|]
  let mutable j=0
  while j<3 && days-int64(x.[j])>=0L do
   days<-days-int64(x.[j])
   j<-j+1
  if j<3 then
   Console.WriteLine(dir.[(i+j)%4])
   f<-false
  i<-i+1
 Console.Out.Flush()