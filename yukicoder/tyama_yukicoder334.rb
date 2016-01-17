#!/usr/bin/ruby
n,*a=$<.read.split.map &:to_i
f=->u{[*0...n].combination(3).find{|i,j,k|v=1<<i|1<<j|1<<k;(a[i]-a[j])*(a[j]-a[k])<0&&(u&v)==0&&!f[u|v]}}
$><<(f[0]||[-1])*' '