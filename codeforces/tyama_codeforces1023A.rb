#!/usr/bin/ruby
_,a,b=$<.map &:chomp
if !a.index('*')
	puts a==b ? :Yes : :No
else
	x,y=a.split('*')
	x||='';y||=''
	puts b.start_with?(x) && b.end_with?(y) && b.size>=x.size+y.size ? :Yes : :No
end
#gets;aputs /^#{gets.chomp.gsub('*','.*?')}$/=~gets.chomp ? :Yes : :No
