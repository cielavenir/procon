#!/usr/bin/ruby
require 'rational'
def gauss(a)
	if !a || a.length==0 then return nil end
	n=a.length
	n.times{|i|
		if a[i][i]==0
			if (i+1).step(n-1){|j|
				if a[j][i]!=0
					i.step(n){|k| a[i][k]+=a[j][k]}
					break
				end
			}
				return nil
			end
		end
		n.times{|j|
			if j!=i then
				r = a[j][i].is_a?(Rational) || a[i][i].is_a?(Rational) ? a[j][i]/a[i][i] : Rational(a[j][i],a[i][i])
				i.step(n){|k| a[j][k] = a[j][k] - a[i][k]*r}
			end
		}
	}

	n.times{|i|
		x=Rational(a[i][i],1)
		a[i].length.times{|j|
			a[i][j] /= x
		}
	}

	return a
end

uaz=gets.split.map(&:to_i)
enemy=[0]+gets.split.map(&:to_i).zip(uaz).map{|x,y|-x+y}
b0=[1]+gets.split.map(&:to_i).zip(uaz).map{|x,y|x-y}
b1=[1]+gets.split.map(&:to_i).zip(uaz).map{|x,y|x-y}
b2=[1]+gets.split.map(&:to_i).zip(uaz).map{|x,y|x-y}
sol=gauss([b0,b1,b2,enemy,[1,0,0,0]].transpose)
puts sol && sol.map(&:last).all?{|e|0<=e&&e<=1} ? :MISS : :HIT