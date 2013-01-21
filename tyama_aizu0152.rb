#!/usr/bin/ruby
while(n=gets.to_i)>0
	n.times.map{
		a=gets.split.map(&:to_i)
		n=a.shift
		b=[]
		f=0
		a.each{|e|
			b.push(e)
			if e==10&&f==0 then b.push(0) else f^=1 end
		}
		b=b.each_slice(2).to_a
		if b[9]==[10,0] then b[9]=[10] end
		if b[10]==[10,0] then b[10]=[10] end
		if b[11]==[10,0] then b[11]=[10] end
		while b.size>10
			b[9]+=b.pop
		end
		c=[]
		0.step(8){|i|
			if b[i][0]==10
				if b[i+1][0]==10&&i<8 then c[i]=20+b[i+2][0] else c[i]=10+b[i+1][0]+b[i+1][1] end
			else
				c[i]=b[i][0]+b[i][1]
				if c[i]==10 then c[i]+=b[i+1][0] end
			end
		}
		c[9]=b[9].reduce(:+)
		[-c.reduce(:+),n]
	}.sort.each{|e|
		puts "#{e[1]} #{-e[0]}"
	}
end