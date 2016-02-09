#!/usr/bin/ruby
load File.expand_path(File.dirname(__FILE__))+'/000.rb'
s="".dup
s<<"call system(\"#{COMMAND} '-e"
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
s<<"'\")"
a=s.chars.each_slice(132-2).with_index.map{|e,i|(i==0?' ':'&')+e.join+'&'}
a.last.chop!
puts a
print "end"