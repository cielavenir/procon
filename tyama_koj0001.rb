#!/usr/bin/ruby
a=13.times.map{|i|2**(i/12.0)*440)}
r=['Ra','Ra#','Ti','Do','Do#','Re','Re#','Mi','Fa','Fa#','So','So#','Ra']
while(p=gets.to_f)!=-1
	o=Math.log(p/440,2).floor
	p/=2**o
	13.times{|i|
		if p<=a[i]
			puts "#{r[i]} #{i<3?o:o+1}"
			break
		end
	}
end