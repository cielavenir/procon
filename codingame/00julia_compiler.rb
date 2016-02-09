#!/usr/bin/ruby
load File.expand_path(File.dirname(__FILE__))+'/000.rb'
puts "#!/usr/bin/env julia" if SCRIPTING
print "run(`#{COMMAND} '-e"
first=true
$<.each{|e|
	l=e.strip
	break if l=='__END__'
	if !l.empty? && !l.start_with?('#')
		print ';' if !first
		first=false
		print l
	end
}
print "'`)"