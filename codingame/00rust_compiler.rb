#!/usr/bin/ruby
load File.expand_path(File.dirname(__FILE__))+'/000.rb'
puts "use std::process::{Command,Stdio};fn main(){"
print "let o=Command::new(\"#{COMMAND}\").arg(\"-e"
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
puts "\").stdin(Stdio::inherit()).output().unwrap_or_else(|e|panic!(\"{}\",e));"
print "print!(\"{}\",String::from_utf8_lossy(&o.stdout));}"