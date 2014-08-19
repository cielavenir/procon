#!/usr/bin/ruby
class Fixnum
	def pow_binary_mod(y)
		x = self
		z = 1
		while y != 0
			while y % 2 == 0
				x = x * x % $N
				#y = y / 2
				y = y >> 1
			end
			y = y - 1
			z = z * x % $N
		end
		z
	end
	def /(n)
		m=(n%$N+$N)%$N
		raise if m==0
		self*m.pow_binary_mod($N-2)%$N
	end
end
loop{
	n,exp=gets.chomp.gsub(' ','').split(':')
	$N=n.to_i
	break if $N==0
	begin
		puts "#{exp} = #{(eval(exp)%$N+$N)%$N} (mod #{$N})"
	rescue
		puts :NG
	end
}