#!/usr/bin/ruby
if RUBY_PLATFORM=~/darwin/
CC="gcc" #lol. clang cannot be used for short coding.
CXX="clang++ -std=c++11 -stdlib=libc++"
else
CC="gcc"
CXX="g++ -std=c++11"
end
LIBS=""
#LIBS="-lstree"
DIR=File.dirname(__FILE__)
PREFIX=DIR+'/../tyama_stepic'
a=Dir.glob('*').select{|e|e.start_with?('stepic_')&&e.end_with?('.txt')}.map{|e|e=~/stepic_([a-zA-Z0-9]+).txt/;$1}
a.each{|e|
	next if File.exist?("stepic_#{e}.ans")
	if File.exist?(s=PREFIX+e.upcase+'.c')
		puts %Q(#{CC} -O2 "#{s}" #{LIBS})
		system(%Q(#{CC} -O2 "#{s}" #{LIBS}))
		puts %Q(./a.out < stepic_#{e}.txt > stepic_#{e}.ans)
		system(%Q(./a.out < stepic_#{e}.txt > stepic_#{e}.ans))
		File.unlink('a.out')
	elsif File.exist?(s=PREFIX+e.upcase+'.cpp')
		puts %Q(#{CXX} -O2 "#{s}" #{LIBS})
		system(%Q(#{CXX} -O2 "#{s}" #{LIBS}))
		puts %Q(./a.out < stepic_#{e}.txt > stepic_#{e}.ans)
		system(%Q(./a.out < stepic_#{e}.txt > stepic_#{e}.ans))
		File.unlink('a.out')
	elsif File.exist?(s=PREFIX+e.upcase+'.rb')
		puts %Q(ruby "#{s}" < stepic_#{e}.txt > stepic_#{e}.ans)
		system(%Q(ruby "#{s}" < stepic_#{e}.txt > stepic_#{e}.ans))
	else
		puts "solution for stepic_#{e}.txt not found"
	end
}
