#!/usr/bin/ruby
load File.expand_path(File.dirname(__FILE__))+'/000.rb'
puts "#!/usr/bin/env groovy" if SCRIPTING
puts "int SIZE=9999999"
puts "byte[] z=new byte[SIZE]"
print "Process p=Runtime.getRuntime().exec([\"#{COMMAND}\",\"-e"
first=true
$<.each{|e|
	l=e.strip
	break if l=='__END__'
	if !l.empty? && !l.start_with?('#')
		print ';' if !first
		first=false
		print l.gsub('"','\"').gsub("'",'\"').gsub('$','\$')
	end
}
puts "\"] as String[])"
puts "p.getOutputStream().write(z,0,System.in.read(z,0,SIZE))"
puts "p.getOutputStream().close()"
puts "Scanner sc=new Scanner(p.getInputStream())"
print "for(;sc.hasNext();)System.out.println(sc.nextLine())"