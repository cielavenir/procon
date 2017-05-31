#!/usr/bin/ruby
N,*A=`dd`.split.map &:to_i;r={};B=[*1..N].sort_by{|i|r[A[i-1]-1]=i;A[i-1]};s=Hash.new 0
z=[];N.times{|i|n=B[N-i-1];z=[n]*~-n+z+[B[i]]*(N-B[i])}
puts (N*N).times.any?{|i|z<<x=r[i]||z.shift;s[x]+=1;r[i]&&x!=s[x]}?:No:[:Yes,z]
#"Yes\n"+z*' '
#z=N.times.flat_map{|i|[B[i]]*~-B[i]}+N.times.flat_map{|i|[B[i]]*(N-B[i])}
