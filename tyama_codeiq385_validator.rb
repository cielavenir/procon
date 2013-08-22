#!/usr/bin/ruby

#grab data.txt from
#http://codeiq.hatenablog.com/entry/2013/08/22/145214
#https://dl.dropboxusercontent.com/u/110505645/CodeIQ/2013/08/blog/data.zip

if $stdin.tty? || ARGV.size<1
	$stderr.puts "385.exe | ruby tyama_codeiq385_validator.rb data.txt"
	exit
end
ok=0
ng=0
File.open(ARGV[0],'rb'){|f|
	while f.gets
		_f=$_.split[2].to_f
		line=$stdin.gets.chomp.split
		if (line[2].to_f-_f).abs>0.2
			ng+=1
			puts (line+[_f])*' '
		else
			ok+=1
		end
	end
}
puts (ok*100).to_f/(ok+ng)