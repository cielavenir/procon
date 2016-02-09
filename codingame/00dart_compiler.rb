#!/usr/bin/ruby
load File.expand_path(File.dirname(__FILE__))+'/000.rb'
puts "#!/usr/bin/env dart" if SCRIPTING
puts "import 'dart:io';"
puts "import 'dart:convert';"
print "main(){Process.start('#{COMMAND}',[\"-e"
first=true
$<.each{|e|
	l=e.strip
	break if l=='__END__'
	if !l.empty? && !l.start_with?('#')
		print ';' if !first
		first=false
		print l.gsub('"','\"').gsub("'",'\"').gsub('$','\$')
	end
}
puts "\"]).then((Process process){"
puts "process.stdout.transform(UTF8.decoder).listen((data){print(data);});"
print "stdin.pipe(process.stdin);});}"