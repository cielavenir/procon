#!/usr/bin/ruby
n,*a=`dd`.split.map &:to_i
*s=0
n.times{|i|s<<s[i]+a[i]}
f=->l,r{a[l]==a[r-1]||!f[l,t=a.bsearch_index{|e|e>=(s[r]-s[l]+r+~l)/(r-l)}]||!f[t,r]}
puts f[0,n]?:First: :Second
