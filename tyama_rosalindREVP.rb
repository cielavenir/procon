#!/usr/bin/ruby
class String
	def complement
		self.reverse.tr("ATGC","TACG")
	end
	def indexes(str)
		(0..self.size-str.size).select{|i|self[i,str.size]==str}
	end
end
s=$<.drop(1).map(&:chomp)*''
s.size.times{|i|
	[4,6,8,10,12].each{|j|
		break if i+j>s.size
		puts "#{i+1} #{j}" if s[i,j]==s[i,j].complement
	}
}