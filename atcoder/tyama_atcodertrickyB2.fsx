open System
open System.Runtime.InteropServices

[<Literal>]
let libc_="libc.so.6"
module libc=
 [<DllImport(libc_,CallingConvention=CallingConvention.Cdecl,EntryPoint="scanf")>]
 extern int scanf1(string format, int& a)
 [<DllImport(libc_,CallingConvention=CallingConvention.Cdecl,EntryPoint="scanf")>]
 extern int scanf3(string format, int64& a, int64& b, int64& c)
 [<DllImport(libc_,CallingConvention=CallingConvention.Cdecl,EntryPoint="printf")>]
 extern unit printf0(string format)
 [<DllImport(libc_,CallingConvention=CallingConvention.Cdecl,EntryPoint="printf")>]
 extern unit printf1(string format, double a)
 [<DllImport(libc_,CallingConvention=CallingConvention.Cdecl,EntryPoint="printf")>]
 extern unit printf2(string format, double a, double b)

let mutable T=0
libc.scanf1("%d",&T)
for i in 1..T do
 let mutable a:int64=0L
 let mutable b:int64=0L
 let mutable c:int64=0L
 libc.scanf3("%lld%lld%lld",&a,&b,&c);
 if a=0L then
  if b=0L then
   libc.printf0(if c=0L then "3\n" else "0\n")
  else
   libc.printf1("1 %.12f\n",double(-c)/double(b))
 else
  if a<0L then
   a <- -a
   b <- -b
   c <- -c
  let d=double(b*b)-4.0*double(a*c)
  if Math.Abs(d)<1e-9 then
   libc.printf1("1 %.12f\n",double(-b)/2.0/double(a))
  elif d<0.0 then
   libc.printf0("0\n")
  else
   // acknowledgement: http://tricky.contest.atcoder.jp/submissions/120839
   let mutable x=0.0
   let mutable y=0.0
   if b>0L then
    x <- (double(-b)-Math.Sqrt(d))/2.0/double(a)
    y <- double(c)/double(a)/x
   else
    y <- (double(-b)+Math.Sqrt(d))/2.0/double(a)
    x <- double(c)/double(a)/y
   libc.printf2("2 %.12f %.12f\n",x,y)