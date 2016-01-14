#!/usr/bin/ruby
h,w,n,f,c,x,y,e=gets.split.map &:to_i
E=Hash.new{|h,k|h[k]=[]}
e.times{a,b=gets.split.map &:to_i;E[a]<<b}
E[f]<<c
loop{
	f,c,d=gets.split;f=f.to_i;c=c.to_i
	if d!='NONE'&&E[f].empty?
		E[f]<<c
		puts 'ELEVATOR'
	else
		puts (d=='LEFT'&&c<E[f].min)||(d=='RIGHT'&&c>E[f].max) ? :BLOCK : :WAIT
	end
	STDOUT.flush
}