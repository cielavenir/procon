#!/usr/bin/ruby
$><<([[3,-3+n=gets.to_i],[5,n-5]].find{|x,y|(y&y-1)>0}||[-1])*' '
__END__
h={};[*0..64].map{|i|h[1<<i]=1}
n=gets.to_i
(1..999).map{|i|
	if i<=n-i&&!h[i]&&!h[n-i]
		puts [i,n-i]*' '
		exit
	end
}
p -1
