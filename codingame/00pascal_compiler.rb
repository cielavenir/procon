#!/usr/bin/ruby
puts "program PascalCompiler;"
puts "uses unix;"
puts "var s:ansistring;"
puts "begin"
print "fpsystem(ansistring('ruby -e '#39'"
$<.each{|e|
	l=e.strip
	break if l=='__END__'
	print l.gsub("'",'"')+';' if !l.start_with?('#')
}
puts "'#39''));"
puts "end."