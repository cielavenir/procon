#!/usr/bin/ruby
N,K=gets.split.map &:to_i
a=[]
$<.map{|e|n=e.to_i
t=(0...a.size).bsearch{|i|a[i]>=n.abs}||a.size
a.delete_at(t)if n<0&&a[t]==-n
a.insert(t,n)if n>0&&a.size-t<K}
p a.size