#!/usr/bin/ruby
puts ({-1=>:Ant,0=>:Draw,1=>:Bug}[gets.split.map{|e|e.to_i.abs}.reduce(:<=>)])
__END__
a,b=gets.split.map{|e|e.to_i.abs}
if a>b
	puts :Bug
elsif a<b
	puts :Ant
else
	puts :Draw
end