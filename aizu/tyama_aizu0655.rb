#!/usr/bin/ruby
n=gets.to_i
a=gets.split.map &:to_i
sea=[true]+a.map{|e|e<=0}+[true]
cur=0
1.upto(n){|i|cur+=1 if !sea[i]&&sea[i-1]}
r=cur
o=n.times.select{|i|a[i]>0}.map{|i|[a[i],i+1]}.sort
o.each_with_index{|(x,y),i|
    sea[y]=true
    if sea[y-1]&&sea[y+1]
        cur-=1
    elsif !sea[y-1]&&!sea[y+1]
        cur+=1
    end
    if i+1==o.size||x<o[i+1][0]
        r=[r,cur].max
    end
}
p r
