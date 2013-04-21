#!/usr/bin/ruby
$a=50000.times.map{|e|e*(e+1)/2+1}

class Integer
	def toX
		$a.size.times{|i|
			if $a[i]>self
				x=$a[i]-self
				return [x,i+1-x]
			end
		}
	end
end

class Array
	def toY
		x=self[0]+self[1]-2
		return $a[x]+self[1]-1
	end
end

p gets.split.map(&:to_i).map(&:toX).reduce{|a,b|a.size.times.map{|i|a[i]+b[i]}}.toY