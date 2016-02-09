#!/usr/bin/ruby
load File.expand_path(File.dirname(__FILE__))+'/000.rb'
puts "program K;"
puts "uses unix;"
puts "var s:ansistring;"
puts "begin"
print "fpsystem(ansistring('#{COMMAND} '#39'-e"
first=true
$<.each{|e|
	l=e.strip
	break if l=='__END__'
	if !l.empty? && !l.start_with?('#')
		print ';' if !first
		first=false
		print l.gsub("'",'"')
	end
}
puts "'#39''));"
print "end."