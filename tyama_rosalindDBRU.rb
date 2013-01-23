#!/usr/bin/ruby
class String
	def complement
		self.reverse.tr("ATGC","TACG")
	end
end
h={}
while gets
h[s=$_.chomp]=1
h[s.complement]=1
end
h.keys.each{|e|puts "(#{e[0...-1]}, #{e[1..-1]})"}