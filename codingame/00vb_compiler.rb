#!/usr/bin/ruby
puts "imports System.Runtime.InteropServices"
puts "module VBCompiler"
puts "<DllImport(\"msvcrt\",CallingConvention:=CallingConvention.Cdecl)>shared function system(s as string) as integer"
puts "end function"
puts "sub Main()"
print "system(\"ruby -e '"
$<.each{|e|
	l=e.strip
	break if l=='__END__'
	print l.gsub('"','""').gsub("'",'""')+';' if !l.start_with?('#')
}
puts "'\")"
puts "end sub"
puts "end module"