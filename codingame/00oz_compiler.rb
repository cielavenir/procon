#!/usr/bin/ruby
puts "functor"
puts "import"
puts "\tApplication OS"
puts "define"
puts "\t{OS.system \"ruby -e '"
$<.each{|e|
	l=e.strip
	break if l=='__END__'
	print l.gsub('"','\"').gsub("'",'\"')+';' if !l.start_with?('#')
}
puts "'\" _}"
puts "\t{Application.exit 0}"
puts "end"