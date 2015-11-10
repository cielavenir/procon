#!/usr/bin/ruby
#mono /Applications/Unity/Unity.app/Contents/Frameworks/Mono/lib/mono/2.0/booc.exe
puts "import System.Runtime.InteropServices"
puts "[DllImport(\"msvcrt\",CallingConvention:CallingConvention.Cdecl)]"
puts "def system(s as string)as int:\n pass"
print "system(\"ruby -e '"
$<.each{|e|
	l=e.strip
	break if l=='__END__'
	print l.gsub('"','\"').gsub("'",'\"')+';' if !l.start_with?('#')
}
puts "'\")"