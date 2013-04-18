#!/usr/bin/ruby

#corpus is changeable
corpus=<<EOM
Mary had a little lamb its fleece was white as snow;
And everywhere that Mary went, the lamb was sure to go. 
It followed her to school one day, which was against the rule;
It made the children laugh and play, to see a lamb at school.
And so the teacher turned it out, but still it lingered near,
And waited patiently about till Mary did appear.
"Why does the lamb love Mary so?" the eager children cry;"Why, Mary loves the lamb, you know" the teacher did reply."
EOM

#a is reversible
a=corpus.gsub(/[^0-9a-zA-Z]/,' ').split

while gets
sum=0
h=Hash.new(0)
n,s=$_.chomp.split(',')
n=n.to_i
a.each_cons(n){|a|if a[0..n-2]==s.split then h[a[n-1]]+=1;sum+=1 end}
b=[]
h.each{|k,v|b<<[k,v.to_f/sum]}
puts b.sort{|a,b|x=b[1]<=>a[1];x=a[0]<=>b[0] if x==0;x}.map{|e|[e[0],sprintf('%.3f',e[1])]*','}*';'
end