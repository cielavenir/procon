#!/usr/bin/ruby
[*'a'..'z'].repeated_permutation(2){|a|
	if ('tanaka'+a*'').crypt('89')=='89B1pK00C26w6'
		puts 'tanaka'+a*''+'_garbage' #This 'garbage' stuff is the crypt(DES)'s vuln.
		exit
	end
}