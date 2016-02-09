#!/usr/bin/ruby
load File.expand_path(File.dirname(__FILE__))+'/000.rb'
puts "using System.Runtime.InteropServices;"
puts "class K{"
puts "[DllImport(\"msvcrt\",CallingConvention=CallingConvention.Cdecl)]static extern system(s:string):int;"
print "static Main():void{system(\"#{COMMAND} '-e"
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
print "'\");}}"