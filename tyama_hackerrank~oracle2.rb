#!/usr/bin/ruby
n,p,l,k,utmost=gets.split.map(&:to_i)
cnt=gets.to_i
raise if n%2==1
a=$<.map(&:chomp)
head=[0,0]
maj=Array.new(k+2){[]};maj[1]=[0]
min=Array.new(k+2){[]};min[0]=0.step(n-1).to_a
a.each{|e|
	b=e.split
	idx=1.step(k).find{|i|head[i]==b[0].to_i}
	if b[2]=='YES'
		maj[idx]<<b[1].to_i
	else
		if !head[idx+1]
			head[idx+1]=b[1].to_i
			maj[idx+1]<<b[1].to_i
		end
		min[idx]<<b[1].to_i
	end
}
0.step(k-1){|i|
	if min[i].size>maj[i+1].size+min[i+1].size
		puts "#{head[i+1]} #{min[i][maj[i+1].size+min[i+1].size]}"
		exit
	end
}
p maj.max_by(&:size).first