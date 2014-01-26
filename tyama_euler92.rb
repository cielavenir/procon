#!/usr/bin/ruby
$h={}
class Integer
	def cycle
		r=self
		if r<999
			while r!=1 && r!=89
				r=r.to_s.chars.map(&:to_i).reduce(0){|s,e|s+e**2}
				#if $h[r] then $h[self]=$h[r];return $h[r]==89 end
			end
			$h[self]=r
			return r==89
		else
			r=r.to_s.chars.map(&:to_i).reduce(0){|s,e|s+e**2}
			raise "#{self}" if r>999
			return $h[r]==89
		end
	end
end
p 1.step(10000000).count(&:cycle)