//usr/bin/env fsharpi $0 $@;exit
open System.Runtime.InteropServices
module libc =
 [<DllImport("libc.so.6", CallingConvention = CallingConvention.Cdecl)>]
 extern int system(string str)
libc.system("ruby -e 'a,b=gets.split.map(&:to_i);a*=b;r=0;a.times{|i|r+=a/(i+1.0)};p r;'")