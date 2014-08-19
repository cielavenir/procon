#!/usr/bin/ruby
A=['>','<','<=','>=']
min=-10**9-1
max=10**9+1
gets.to_i.times{
line=gets.split
line[0]=A.index(line[0])
line[0]^=2 if line[2]=='N'
line[1]=line[1].to_i
if line[0]==0
	min=[line[1]+1,min].max
elsif line[0]==1
	max=[line[1]-1,max].min
elsif line[0]==2
	max=[line[1],max].min
else
	min=[line[1],min].max
end
}
puts min<=max ? min : 'Impossible'