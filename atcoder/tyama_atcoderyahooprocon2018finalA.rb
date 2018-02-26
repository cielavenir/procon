#!/usr/bin/ruby
#f=->n{n.prime_division.map &:first}
k=->a{
	B=6000
	r=[]
	((a.size+B-1)/B).times{|i|
		IO.popen('factor','r+b'){|io|
			io.puts a[B*i...B*-~i]
			io.close_write
			r+=io.readlines.map{|e|e.split[1..-1].map(&:to_i).uniq}
		}
	}
	r
}
n,m,*a=`dd`.split.map &:to_i
h=Hash.new 0
r=[0]*m
k[a].each{|x|
	#x=f[e]
	(0...1<<x.size).each{|j|
		d=1;s=1
		x.size.times{|k|d*=x[k]**j[k];s=s*(-1)**j[k]}
		h[d]+=s
	}
}
1.upto(m){|i|i.step(m,i){|j|r[j-1]+=h[i]}}
puts r
