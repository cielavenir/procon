#!/usr/bin/ruby
mode=:codeeval49
#mode=:codeiq171
x=[]

if mode==:codeeval49
	h=Hash.new{|h,k|h[k]={}}
	while gets
		a=$_.chomp.split
		h[a[-2]][a[-1]]=1
		x<<[a[-1],a[-2]] if h[a[-1]][a[-2]]
	end
else
	while gets
		a,b=$_.chomp.split('=')
		x<<[a,b]
	end
end

h=[]
x.each{|a,b|
	an=nil;bn=nil
	h.each_with_index{|e,i|
		an=i if e.index(a)
		bn=i if e.index(b)
	}
	if !an&&!bn
		h<<[a,b]
	elsif !an
		h[bn]<<a
	elsif !bn
		h[an]<<b
	elsif an!=bn
		h[an]|=h[bn]
		h.delete_at(bn)
	end
}

if mode==:codeeval49
	puts h.select{|e|e.uniq.size>2}.map{|e|e.sort.join(', ')}.sort.join("\n")
else
	puts h.map{|e|e.sort.join('=')}.sort.join("\n")
end
__END__
A=B
C=D
B=C
=> A=B=C=D