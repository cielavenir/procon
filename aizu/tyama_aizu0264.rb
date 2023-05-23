#!/usr/bin/ruby
Fixnum=Integer if !defined?(Fixnum)
class Fixnum
	def pow_binary_mod(y)
		x = self
		z = 1
		while y!=0
			z=z*x%$N if y&1!=0
			x=x*x%$N
			y>>=1
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
