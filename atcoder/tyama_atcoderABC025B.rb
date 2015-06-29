#!/usr/bin/ruby
n,a,b=gets.split.map(&:to_i)
coor=0
n.times{
	s,d=gets.split.zip([->e{e},:to_i.to_proc]).map{|x,y|y.call(x)}
	d=a if d<a
	d=b if b<d
	d=-d if s=='West'
	coor+=d
}
if coor==0
	puts 0
elsif coor<0
	puts 'West %d'%-coor
else
	puts 'East %d'%coor
end