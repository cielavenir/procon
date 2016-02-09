#!/usr/bin/ruby
load File.expand_path(File.dirname(__FILE__))+'/000.rb'
puts "with Interfaces.C; use Interfaces.C;"
puts "procedure K is"
puts "function Sys(s:char_array) return integer;"
puts "pragma Import(C,Sys,\"system\");"
puts "ret:integer;"
puts "begin"
print "ret:=Sys(To_C(\"#{COMMAND} '-e"
first=true
$<.each{|e|
	l=e.strip
	break if l=='__END__'
	if !l.empty? && !l.start_with?('#')
		print ';' if !first
		first=false
		print l.gsub('"','""').gsub("'",'""')
	end
}
puts "'\"));"
print "end;"