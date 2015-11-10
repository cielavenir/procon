#!/usr/bin/ruby
# [Note] The donor must not handle EOF.
puts "#!/usr/bin/env fan"
print "class FantomCompiler{static Void main(){p:=Process([\"ruby\",\"-e\",\""
$<.each{|e|
	l=e.strip
	break if l=='__END__'
	print l.gsub('"','\"').gsub("'",'\"')+';' if !l.start_with?('#')
}
puts "\"]);p.in=Env.cur.in;p.run.join}}"