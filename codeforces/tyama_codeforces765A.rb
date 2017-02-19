#!/usr/bin/ruby
targets=[]
backs=Hash.new 0
n=gets.to_i
s=gets.chomp
n.times{
	a,b=gets.chomp.split('->')
	targets<<b if a==s
	backs[a]+=1 if b==s
}
targets.each{|target|
	if backs[target]==0
		puts :contest
		exit
	end
	backs[target]-=1
}
puts :home
