#!/usr/bin/ruby
puts "#!/usr/bin/env rdmd"
puts "import std.process;"
puts "void main(){"
print "system(\"ruby -e '"
$<.each{|e|
	l=e.strip
	break if l=='__END__'
	print l.gsub('"','\"').gsub("'",'\"')+';' if !l.start_with?('#')
}
puts "'\");}"