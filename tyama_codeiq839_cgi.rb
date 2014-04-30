#!/usr/bin/ruby
module Spacetalky
	def self.encode(s)
		return '?' if s.empty? || s!=s.downcase
		r=''
		s.each_char.chunk{|e|e}.each{|e|
			n=e[1].size
			while n>26
				r+=e[0]+122.chr
				n-=26
			end
			r+=e[0]+(96+n).chr
		}
		r
	end
	def self.decode(s)
		return 'X' if s.size%2==1
		s.scan(/../).map{|e|e[0]*(e[1].ord-96)}*''
	end
end

require 'cgi'
cgi=CGI.new

puts 'Content-Type: text/plain'
puts
puts Spacetalky.encode(cgi['input'])