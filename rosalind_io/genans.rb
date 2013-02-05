#!/usr/bin/ruby
if RUBY_PLATFORM=~/darwin/
CC="gcc" #lol
CXX="clang++ -std=c++11 -stdlib=libc++"
else
CC="gcc"
CXX="g++ -std=c++11"
end
PREFIX=ENV['HOME']+'/procon/tyama_rosalind'
a=Dir.glob('*').select{|e|e.start_with?('rosalind_')&&e.end_with?('.txt')}.map{|e|e=~/rosalind_([a-z0-9]+).txt/;$1}
a.each{|e|
	next if File.exist?("rosalind_#{e}.ans")
	if File.exist?(s=PREFIX+e.upcase+'.c')
		puts %Q(#{CC} -O2 "#{s}")
		system(%Q(#{CC} -O2 "#{s}"))
		puts %Q(./a.out < rosalind_#{e}.txt > rosalind_#{e}.ans)
		system(%Q(./a.out < rosalind_#{e}.txt > rosalind_#{e}.ans))
		File.unlink('a.out')
	elsif File.exist?(s=PREFIX+e.upcase+'.cpp')
		puts %Q(#{CXX} -O2 "#{s}")
		system(%Q(#{CXX} -O2 "#{s}"))
		puts %Q(./a.out < rosalind_#{e}.txt > rosalind_#{e}.ans)
		system(%Q(./a.out < rosalind_#{e}.txt > rosalind_#{e}.ans))
		File.unlink('a.out')
	elsif File.exist?(s=PREFIX+e.upcase+'.rb')
		puts %Q(ruby "#{s}" < rosalind_#{e}.txt > rosalind_#{e}.ans)
		system(%Q(ruby "#{s}" < rosalind_#{e}.txt > rosalind_#{e}.ans))
	else
		puts "solution for rosalind_#{e}.txt not found"
	end
}