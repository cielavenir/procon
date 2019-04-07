#!/usr/bin/ruby
def getarchive(f)
	arc={}
	seq=''
	line=f.gets
	line.chomp!
	name=line[1..-1]
	while line=f.gets
		line.chomp!
		if line[0,1]=='>'
			arc[name]=seq.strip
			seq=''
			name=line[1..-1]
		else
			seq+=line+"\n"
		end
	end
	arc[name]=seq.strip
	arc
end
arc=getarchive(DATA)
puts arc[gets.chomp]

#fasta-like editable text archive
__END__
>1000 1000
2000 abcdefg
>51
1
2
Fizz
4
Buzz
Fizz
7
8
Fizz
Buzz
11
Fizz
13
14
FizzBuzz
16
17
Fizz
19
Buzz
Fizz
22
23
Fizz
Buzz
26
Fizz
28
29
FizzBuzz
31
32
Fizz
34
Buzz
Fizz
37
38
Fizz
Buzz
41
Fizz
43
44
FizzBuzz
46
47
Fizz
49
Buzz
Fizz
>Let's enjoy
Hello World!
>96
4656
>10
5942201175040512342
>100
4240983281189952799
