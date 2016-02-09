#!/usr/bin/ruby
load File.expand_path(File.dirname(__FILE__))+'/000.rb'
puts "#!/usr/bin/awk -f" if SCRIPTING
print "BEGIN{system(\"#{COMMAND} '-e"
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
print "'\")}"