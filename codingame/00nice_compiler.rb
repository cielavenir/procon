#!/usr/bin/ruby
load File.expand_path(File.dirname(__FILE__))+'/000.rb'
puts "void main(String[]args){"
print "	String[] l=[\"#{COMMAND}\",\"-e"
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
print "\"];"

puts <<EOM
	int SIZE=9999999;
	byte[] z=new byte[SIZE];
	Process p=Runtime.getRuntime().exec(l);
	p.getOutputStream().write(z,0,System.in.read(z,0,SIZE));
	p.getOutputStream().close();
	java.io.BufferedReader R=new java.io.BufferedReader(new java.io.InputStreamReader(p.getInputStream()));
	for(;;){?String s=R.readLine();if(s==null)break;System.out.println(notNull(s));}
EOM
print '}'