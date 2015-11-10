#!/usr/bin/ruby
puts "use std::process::{Command,Stdio};fn main(){"
print "let o=Command::new(\"ruby\").arg(\"-e\").arg(\""
$<.each{|e|
	l=e.strip
	break if l=='__END__'
	print l.gsub('"','\"').gsub("'",'\"')+';' if !l.start_with?('#')
}
puts "\").stdin(Stdio::inherit()).output().unwrap_or_else(|e|panic!(\"{}\",e));"
puts "print!(\"{}\",String::from_utf8_lossy(&o.stdout));}"