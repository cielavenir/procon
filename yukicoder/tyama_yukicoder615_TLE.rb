#!/usr/bin/env ruby
$memo={}
def dfs(a,k,i)
  return a[-1]-a[i] if k==1
  $memo[[k,i]]||=(i..a.size-k).map{|j|a[j]-a[i]+dfs(a,k-1,j+1)}.min
end
n,k,*a=`dd`.split.map &:to_i
a.sort!
p dfs(a,k,0)
