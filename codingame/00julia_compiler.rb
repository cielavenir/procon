#!/usr/bin/ruby
puts "#!/usr/bin/env julia"
print "run(`ruby -e '"
$<.each{|e|
	l=e.strip
	break if l=='__END__'
	print l+';' if !l.start_with?('#')
}
puts "'`)"