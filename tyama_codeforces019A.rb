h=Hash.new
(n=gets.to_i).times{|i|
  h[s=gets.chomp]=[0,0,0,s]
}
(n*(n-1)/2).times{|i|
  gets=~/(\w+)-(\w+) (\d+):(\d+)/
  _3=$3.to_i;_4=$4.to_i;
  if _3>_4 then h[$1][0]+=3;h[$1][1]+=_3-_4;h[$2][1]+=_4-_3;h[$1][2]+=_3;h[$2][2]+=_4 end
  if _3<_4 then h[$2][0]+=3;h[$1][1]+=_3-_4;h[$2][1]+=_4-_3;h[$1][2]+=_3;h[$2][2]+=_4 end
  if _3==_4 then h[$1][0]+=1;h[$2][0]+=1;h[$1][2]+=_3;h[$2][2]+=_4 end
}
a=Array.new
h.values.sort[n/2,n/2].each{|i|
  a.push i[3]
}
a.sort.each{|s|puts s}