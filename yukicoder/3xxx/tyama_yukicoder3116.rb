#!/usr/bin/ruby
h=gets.chomp.chars.tally
if h.include?('C')
	puts 'T'*h['T'].to_i+'C'*h['C']+'P'*h['P'].to_i
else
	puts 'P'*h['P'].to_i+'T'*h['T'].to_i
end
