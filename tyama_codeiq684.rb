#!/usr/bin/ruby
class Array
	def permutation3
		return to_enum(:permutation3) unless block_given?
		a=self.sort
		k=0
		loop{
			(k...self.size).each{|i|yield a[0..i]}
			k=(a.size-2).downto(0).find{|i|a[i]<a[i+1]}
			break if !k
			l=(a.size-1).downto(k+1).find{|i|a[k]<a[i]}
			a[k],a[l]=a[l],a[k]
			a=a[0,k+1]+a[k+1..-1].reverse
		}
	end
end
if false
	'aaabcc'.split('').permutation3.with_index(1){|e,i|puts "#{i}:#{e*''}"}
else
	p 'abbbbcddddeefggg'.split('').permutation3.with_index(1).find{|e,i|
		e.size==8&&e*''=='eagcdfbe'
	}.last
end