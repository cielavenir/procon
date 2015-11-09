#!/usr/bin/ruby
puts "#!/usr/bin/env nim"
puts "import osproc"
print "var r=execCmd(\"ruby -e '"
$<.each{|e|
	l=e.strip
	break if l=='__END__'
	print l.gsub('"','\"').gsub("'",'\"')+';' if !l.start_with?('#')
}
puts "'\")"