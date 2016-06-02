#!/usr/bin/ruby
load File.expand_path(File.dirname(__FILE__))+'/000.rb'
puts "        identification division."
puts "        program-id. k."
puts "        procedure division."
s="".dup
s<<"call \"system\" using \"#{COMMAND} '-e"
first=true
$<.each{|e|
	l=e.strip
	break if l=='__END__'
	if !l.empty? && !l.start_with?('#')
		s<<';' if !first
		first=false
		s<<l.gsub('"','""').gsub("'",'""')
	end
}
s<<"'\"."
a=s.chars.each_slice(72-8).with_index.map{|e,i|(i==0?'        ':'      -"')+e.join}
puts a
print "        stop run."