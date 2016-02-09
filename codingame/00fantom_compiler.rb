#!/usr/bin/ruby
# [Note] The donor must not try to detect EOF.
load File.expand_path(File.dirname(__FILE__))+'/000.rb'
puts "#!/usr/bin/env fan" if SCRIPTING
print "class K{static Void main(){p:=Process([\"#{COMMAND}\",\"-e"
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
print "\"]);p.in=Env.cur.in;p.run.join}}"