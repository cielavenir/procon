#!/usr/bin/ruby
load File.expand_path(File.dirname(__FILE__))+'/000.rb'
puts "#!/usr/bin/env node" if SCRIPTING
print "s=require('child_process').spawn;c=s('#{COMMAND}',[\"-e"
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
print "\"]);c.stdout.pipe(process.stdout);c.stdin.write(require('fs').readFileSync('/dev/stdin'));c.stdin.end()"
