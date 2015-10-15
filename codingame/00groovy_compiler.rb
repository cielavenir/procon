#!/usr/bin/ruby
puts "#!/usr/bin/env groovy"
puts "int SIZE=9999999"
puts "byte[] z=new byte[SIZE]"
print "Process p=Runtime.getRuntime().exec([\"ruby\",\"-e\",\""
$<.each{|e|
	l=e.strip
	break if l=='__END__'
	print l.gsub('"','\"').gsub("'",'\"').gsub('$','\$')+';' if !l.start_with?('#')
}
puts "\"] as String[])"
puts "p.getOutputStream().write(z,0,System.in.read(z,0,SIZE))"
puts "p.getOutputStream().close()"
puts "Scanner sc=new Scanner(p.getInputStream())"
puts "for(;sc.hasNext();)System.out.println(sc.nextLine())"