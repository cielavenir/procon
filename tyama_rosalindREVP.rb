#!/usr/bin/ruby
class String
	def complement
		self.reverse.tr("ATGC","TACG")
	end
	def indexes(str)
		(0..self.length-str.length).select{|i|self[i,str.length]==str}
	end
end
s=gets.chomp
s.length.times{|i|
	[4,6,8,10,12].each{|j|
		break if i+j>s.length
		puts "#{i+1} #{j}" if s[i,j]==s[i,j].complement
	}
}