#!/usr/bin/ruby
#http://www.checkio.org/mission/spaceship-landing-strip/ verifier.
#sadly TLE for aizu0116

def checkio(data)
	y=data.size
	x=data[0].size
	m=Array.new(y){[0]*x}
	y.times{|j|
		r=0
		x.times{|i|
			#if data[j][i,1]=='.'
			if data[j][i]==1
				r+=1
			else
				r=0
			end
			m[j][i]=r
		}
	}
	r=0
	x.times{|i|
		y.times{|j|
			ma=9999999
			j.step(y-1){|k|
				ma=[ma,m[k][i]].min
				r=[r,ma*(k-j+1)].max
			}
		}
	}
	r
end

if $0==__FILE__
	if false
		while(y,x=gets.split.map(&:to_i))!=[0,0]
			data=y.times.map{gets.chomp}
			puts checkio(data)
		end
	else
		gets.to_i.times{
			data=5.times.map{gets.split.map(&:to_i)}
			puts checkio(data)
			gets
		}
	end
end