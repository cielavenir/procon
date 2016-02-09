#!/usr/bin/ruby
load File.expand_path(File.dirname(__FILE__))+'/000.rb'
puts "#!/usr/bin/env tclsh" if SCRIPTING
print "puts [exec #{COMMAND} \"-e"
first=true
$<.each{|e|
	l=e.strip
	break if l=='__END__'
	if !l.empty? && !l.start_with?('#')
		print ';' if !first
		first=false
		print l.gsub('"','\"').gsub('$','\$').gsub('[','\[').gsub(']','\]')
	end
}
print "\" 2>/dev/null]"