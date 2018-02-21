#!/usr/bin/ruby
f=->*e{STDOUT.syswrite"%d %d\n"%e;r=gets.to_i;r==0&&exit;r}
a=f[0,0]
b=f[0,a]
f[b/2,a-b/2]
