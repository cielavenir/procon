#!/usr/bin/ruby
s=$<.read.gsub("\n",' ');
if s.include?('#include')
	puts 'C'
elsif s.include?('print ')||s.include?('#')
	puts 'Python'
else
	puts 'Java'
end