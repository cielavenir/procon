#!/usr/bin/ruby
load File.expand_path(File.dirname(__FILE__))+'/000.rb'
puts "//usr/bin/env scala $0 $@;exit" if SCRIPTING
puts <<EOM
import java.util.Scanner
object Solution{
	def main(args:Array[String]){
		val SIZE=9999999
		val z=new Array[Byte](SIZE)
EOM

print "		val p=Runtime.getRuntime().exec(Array[String](\"#{COMMAND}\",\"-e"
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
puts "\"))"

puts <<EOM
		p.getOutputStream().write(z,0,System.in.read(z,0,SIZE))
		p.getOutputStream().close()
		val sc=new Scanner(p.getInputStream())
		while(sc.hasNext())println(sc.nextLine())
	}
EOM
print '}'