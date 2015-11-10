#!/usr/bin/ruby
puts <<EOM
import java.util.Scanner;
import java.io.*;
fun main(args: Array<String>){
	val SIZE=9999999
	val z=ByteArray(SIZE)
EOM

print "	val p=Runtime.getRuntime().exec(arrayOf(\"ruby\",\"-e\",\""
$<.each{|e|
	l=e.strip
	break if l=='__END__'
	print l.gsub('"','\"').gsub("'",'\"')+';' if !l.start_with?('#')
}
puts "\"));"

puts <<EOM
	p.getOutputStream().write(z,0,System.`in`.read(z,0,SIZE))
	p.getOutputStream().close()
	val sc=Scanner(p.getInputStream())
	while(sc.hasNext())System.out.println(sc.nextLine())
}
EOM