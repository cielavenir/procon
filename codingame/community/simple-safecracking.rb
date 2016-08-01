#!/usr/bin/ruby
a=gets.chomp.split(': ')
puts a[1].split('-').map{|e|
	if e.size==5
		if e[3]==e[4]
			3
		elsif e[1]==e[3]
			7
		else
			8
		end
	elsif e.size==4
		if e[0]==e[2]
			9
		elsif e[1]==a[0][21] # use small trick below...
			5
		elsif e[1]==a[0][2]
			0
		else
			4
		end
	else
		if e[2]==a[0][2]
			1
		elsif e[1]==a[0][21]
			6
		else
			2
		end
	end
}*''
__END__
After checking someone else's code,
I noticed that the input is just caeser cipher (not complete substitution).
But I keep my implementation here...