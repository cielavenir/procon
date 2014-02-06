#!/usr/bin/ruby
N=gets.to_i
a=(N+2).times.map{'.'*(N+2)}
$<.each_with_index{|e,i|
	a[i+1][1,N]=e.chomp
}
(1..N).each{|i|
	(1..N).each{|j|
		if a[i][j,1]=='#'
			if a[i+1][j-1,1]!='#' || a[i+1][j,1]!='#' || a[i+1][j+1,1]!='#' || a[i+2][j,1]!='#'
				puts :NO
				exit
			end
			a[i+1][j-1,1]=a[i+1][j,1]=a[i+1][j+1,1]=a[i+2][j,1]='.'
		end
	}
}
puts :YES