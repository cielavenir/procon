#!/usr/bin/ruby
puts "with Interfaces.C; use Interfaces.C;"
puts "procedure AdaCompiler is"
puts "function Sys(s:char_array) return integer;"
puts "pragma Import(C,Sys,\"system\");"
puts "ret:integer;"
puts "begin"
print "ret:=Sys(To_C(\"ruby -e '"
$<.each{|e|
	l=e.strip
	break if l=='__END__'
	print l.gsub('"','\"').gsub("'",'\"')+';' if !l.start_with?('#')
}
puts "'\"));"
puts "end AdaCompiler;"