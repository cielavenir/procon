#!/usr/bin/ruby
#mono /Applications/Unity/Unity.app/Contents/Frameworks/Mono/lib/mono/2.0/booc.exe
load File.expand_path(File.dirname(__FILE__))+'/000.rb'
puts "import System.Runtime.InteropServices"
puts "[DllImport(\"msvcrt\",CallingConvention:CallingConvention.Cdecl)]"
puts "def system(s as string)as int:\n pass"
print "system(\"#{COMMAND} '-e"
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