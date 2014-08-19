#!/usr/bin/ruby
class String
	def complement
		self.reverse.tr("ATGC","TACG")
	end
end
h=Hash.new(0)
a=[]
while gets
a<<$_.chomp
h[[a.last,a.last.complement].min]+=1
end
a.each{|e|
	next if h[[e,e.complement].min]>1
	s=e.dup
	s.size.times{|j|
		c=s[j,1]
		break if "ACGT".chars.any?{|i|
			next if i==c
			s[j,1]=i
			h[[s,s.complement].min]>1
		}
		s[j,1]=c
	}
	puts "#{e}->#{s}"
}