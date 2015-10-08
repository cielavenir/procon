#!/usr/bin/ruby
puts "#!/usr/bin/php"
puts "<?php"
puts "$s=<<<'EOM'"
print "ruby -e '"
$<.each{|e|
	l=e.strip
	break if l=='__END__'
	print l+';' if !l.start_with?('#')
}
puts "'"
puts "EOM;"
puts "system($s);"