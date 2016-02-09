#!/usr/bin/ruby
load File.expand_path(File.dirname(__FILE__))+'/000.rb'
puts <<EOM
import java.util.Scanner;
import java.io.*;
fun main(args: Array<String>){
	val SIZE=9999999
	val z=ByteArray(SIZE)
EOM

print "	val p=Runtime.getRuntime().exec(arrayOf(\"#{COMMAND}\",\"-e"
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
print "\"));"

puts <<EOM
	p.getOutputStream().write(z,0,System.`in`.read(z,0,SIZE))
	p.getOutputStream().close()
	val sc=Scanner(p.getInputStream())
	while(sc.hasNext())System.out.println(sc.nextLine())
EOM
print '}'