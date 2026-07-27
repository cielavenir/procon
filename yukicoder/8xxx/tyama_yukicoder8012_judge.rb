#!/usr/bin/ruby
#ARGV=input_file_path,output_file_path,source_path
#STDIN=program output
IO.popen(%w[gcc -c -ocatch.o -xc -],'w'){|io|
	io.write DATA.read
}
if !File.exist?('catch.o')
	exit(2)
end
code=STDIN.read
first=code.split("\n")[0].strip
opt=first.start_with?('//') ? first[2..-1].split : []
IO.popen(%w[g++ -oprog catch.o -xc++ -]+opt,'w'){|io|
	io.write code
}
if !File.exist?('prog')
	File.unlink('catch.o')
	exit(3)
end
ret=IO.popen(%w[./prog],'r'){|io|
	io.read
}
File.unlink('catch.o')
File.unlink('prog')
exit(ret.chomp=='FLAG_CPP-KEYWORD-CALLER' ? 0 : 1)

__END__
#include <stdio.h>
void catch(){
	puts("FLAG_CPP-KEYWORD-CALLER");
}