#!/usr/bin/ruby
puts <<EOM
//usr/bin/env scala $0 $@;exit
import java.util.Scanner
object Solution{
	def main(args:Array[String]){
		val SIZE=9999999
		val z=new Array[Byte](SIZE)
EOM

print "		val p=Runtime.getRuntime().exec(Array[String](\"ruby\",\"-e\",\""
$<.each{|e|
	l=e.strip
	break if l=='__END__'
	print l.gsub('"','\"').gsub("'",'\"')+';' if !l.start_with?('#')
}
puts "\"))"

puts <<EOM
		p.getOutputStream().write(z,0,System.in.read(z,0,SIZE))
		p.getOutputStream().close()
		val sc=new Scanner(p.getInputStream())  		
		while(sc.hasNext())println(sc.nextLine())
	}
}
EOM