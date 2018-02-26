#!/usr/bin/env crystal
#It is completely unknown why this code does not work properly...

B=6000
def k(a)
	r=Array(Array(Int32)).new
	((a.size+B-1)/B).times{|i|
		Process.run("factor"){|process|
			process.input.puts a[B*i...B*-~i].join("\n")
			process.input.close
			r+=process.output.gets_to_end.chomp.split("\n").map{|e|e.split[1..-1].map(&.to_i).uniq}
		}
	}
	r
end
a=`dd`.split.map &.to_i
n,m=a.shift(2)
h=Hash(Int32,Int32).new 0
r=[0]*m
k(a).each{|x|
	(0...1<<x.size).each{|j|
		d=1;s=1
		x.size.times{|k|d*=x[k]**(j>>k&1);s=s*(-1)**(j>>k&1)}
		h[d]+=s
	}
}
1.upto(m){|i|i.step(to: m,by: i){|j|r[j-1]+=h[i]}}
puts r.join("\n")
