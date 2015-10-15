#!/usr/bin/ruby
puts "#!/usr/bin/env dart"
puts "import 'dart:io';"
puts "import 'dart:convert';"
print "main(){Process.start('ruby',['-e',\""
$<.each{|e|
	l=e.strip
	break if l=='__END__'
	print l.gsub('"','\"').gsub("'",'\"').gsub('$','\$')+';' if !l.start_with?('#')
}
puts "\"]).then((Process process){"
puts "process.stdout.transform(UTF8.decoder).listen((data){print(data);});"
puts "stdin.pipe(process.stdin);});}"