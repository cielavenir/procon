#!/usr/bin/ruby
load File.expand_path(File.dirname(__FILE__))+'/000.rb'
puts "functor"
puts "import"
puts "\tApplication OS"
puts "define"
puts "\t{OS.system \"#{COMMAND} '-e"
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
puts "'\" _}"
puts "\t{Application.exit 0}"
print "end"