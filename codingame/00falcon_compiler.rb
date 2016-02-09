#!/usr/bin/ruby
#Looks like not working on 32bit(ideone)
load File.expand_path(File.dirname(__FILE__))+'/000.rb'
puts "#!/usr/bin/env falcon -M" if SCRIPTING
puts "load process"
print "system(\"#{COMMAND} '-e"
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
print "'\")"