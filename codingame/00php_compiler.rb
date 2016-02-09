#!/usr/bin/ruby
load File.expand_path(File.dirname(__FILE__))+'/000.rb'
puts "#!/usr/bin/php" if SCRIPTING
puts "<?php"
puts "$s=<<<'EOM'"
print "#{COMMAND} '-e"
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
puts "'"
puts "EOM;"
print "system($s);"