#!/usr/bin/ruby
l=gets
name=l.chomp[1..-1]
seq=''
max_gc=0
max_name=''
while l=gets
	if l[0,1]=='>'
		gc=seq.scan(/[GC]/).size.to_f*100/seq.size
		if max_gc<gc
			max_gc=gc
			max_name=name
		end
		name=l.chomp[1..-1]
		seq=''
	else
		seq+=l.chomp
	end
end
		gc=seq.scan(/[GC]/).size.to_f*100/seq.size
		if max_gc<gc
			max_gc=gc
			max_name=name
		end
puts"%s\n%f%%"%[max_name,max_gc]