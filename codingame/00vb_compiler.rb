#!/usr/bin/ruby
load File.expand_path(File.dirname(__FILE__))+'/000.rb'
puts "imports System.Runtime.InteropServices"
puts "module K"
puts "<DllImport(\"msvcrt\",CallingConvention:=CallingConvention.Cdecl)>shared function system(s as string) as integer"
puts "end function"
puts "sub Main()"
print "system(\"#{COMMAND} '-e"
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
puts "'\")"
puts "end sub"
print "end module"