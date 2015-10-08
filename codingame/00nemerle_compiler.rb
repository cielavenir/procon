#!/usr/bin/ruby
puts "using System.Runtime.InteropServices;"
puts "class NemerleCompiler{"
puts "[DllImport(\"msvcrt\", CallingConvention = CallingConvention.Cdecl)]"
puts "private static extern system(str:string):int;"
puts "static Main():void{"
print "system(\"ruby -e '"
$<.each{|e|
	l=e.strip
	break if l=='__END__'
	print l.gsub('"','\"').gsub("'",'\"')+';' if !l.start_with?('#')
}
puts "'\");}}"