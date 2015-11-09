#!/usr/bin/ruby
#puts "//usr/bin/env fsharpi $0 $@;exit" #fsharpi cannot resolve DllImport
puts "open System.Runtime.InteropServices"
puts "module libc ="
puts " [<DllImport(\"msvcrt\",CallingConvention=CallingConvention.Cdecl)>]extern int system(string s)"
print "libc.system(\"ruby -e '"
$<.each{|e|
	l=e.strip
	break if l=='__END__'
	print l.gsub('"','\"').gsub("'",'\"')+';' if !l.start_with?('#')
}
puts "'\")"