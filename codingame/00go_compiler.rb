#!/usr/bin/ruby
puts "//usr/bin/env go run $0 $@;exit"
puts "package main"
puts "import \"syscall\""
puts "func main(){"
#exec() rather than system(). not general...
print "syscall.Exec(\"/usr/bin/ruby\",[]string{\"ruby\",\"-e\",\""
$<.each{|e|
	l=e.strip
	break if l=='__END__'
	print l.gsub('"','\"').gsub("'",'\"')+';' if !l.start_with?('#')
}
puts "\"},[]string{})}"