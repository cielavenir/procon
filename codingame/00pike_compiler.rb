#!/usr/bin/ruby
puts "#!/usr/bin/pike"
print "int main(){Stdio.File o=Stdio.File();Process.create_process(({\"ruby\",\"-e\",\""
$<.each{|e|
	l=e.strip
	break if l=='__END__'
	print l.gsub('"','\"').gsub("'",'\"')+';' if !l.start_with?('#')
}
puts "\"}),([\"stdout\":o->pipe()]));write(o->read());}"