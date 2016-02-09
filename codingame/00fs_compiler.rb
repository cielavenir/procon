#!/usr/bin/ruby
load File.expand_path(File.dirname(__FILE__))+'/000.rb'
#puts "//usr/bin/env fsharpi $0 $@;exit" #fsharpi cannot resolve DllImport
puts "open System.Runtime.InteropServices"
puts "module libc ="
puts " [<DllImport(\"msvcrt\",CallingConvention=CallingConvention.Cdecl)>]extern int system(string s)"
print "libc.system(\"#{COMMAND} '-e"
first=true
$<.each{|e|
	l=e.strip
	break if l=='__END__'
	if !l.empty? && !l.start_with?('#')
		print ';' if !first
		first=false
		print l.gsub('"','\"').gsub("'",'\"')
	end
}
print "'\")"