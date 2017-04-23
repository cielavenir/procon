#!/usr/bin/ruby
(1..gets.to_i).each{|i|
	print 'Case #%d: '%i
	a=gets.chomp.chars.map(&:to_i)
	n=a.size
	loop{
		if (1..n-1).each{|j|
			if a[j-1].to_i>a[j].to_i
				(j..n-1).each{|k|a[k]=9}
				(j-1).downto(0){|k|
					a[k]-=1
					if a[k]==-1
						a[k]=9
					else
						break
					end
				}
				break
			end
		}
			break
		end
	}
	puts a.join.sub(/^0+/,'')
}
