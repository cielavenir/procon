#!/usr/bin/ruby
#gemstring fast solution
#based on https://gist.github.com/tatt61880/8958003

=begin
class Array

	# yields all Arrays with enumerating "all elements from each elements".
	#
	#   [[1,2,3],[4,5,6]].choices.to_a
	#   #=> [[1, 4], [1, 5], [1, 6], [2, 4], [2, 5], [2, 6], [3, 4], [3, 5], [3, 6]]

	def choices(a=[],d=0,&block)
		return to_enum(:choices,[],0) if !block_given?
		if d==self.size
			yield a
		else
			self[d].size.times{|i|
				choices(a+[self[d][i]],d+1,&block)
			}
		end
	end

end
=end

class Integer
	def fact() (1..self).reduce(1,:*) end
end

counts=Hash.new(0)
'abbbbcddddeefggg'.chars{|c|counts[c.ord-'a'.ord]+=1}
r=0
desired='eagcdfbe'.chars.map{|c|c.ord-'a'.ord}
desired.each{|n|
	r+=1
	n.times{|i|
		counts[i]-=1
		val=counts.values.map{|e|[*0..e]}
		#val.choices{|e|
		val[0].product(*val[1..-1]).each{|e|
			r+=e.reduce(:+).fact / e.map(&:fact).reduce(:*)
		}
		counts[i]+=1
	}
	counts[n]-=1
}
p r