#!/usr/bin/ruby
def TroubleSort(lst)
if false
	done = false
	while !done
		done = true
		(0..lst.size-3).each{|i|
			if lst[i] > lst[i+2]
				done = false
				lst[i..i+2]=lst[i..i+2].reverse
			end
		}
	end
	lst
else
	a=lst.each_slice(2).to_a
	x,y=a.shift.zip(*a).map{|e|e.compact.sort}
	x.zip(y).flat_map{|e|e}.compact
end
end

gets.to_i.times{|t|
	n=gets.to_i
	a=gets.split.map &:to_i
	print 'Case #%d: '%(t+1)
	a=TroubleSort(a)
	idx=(0..n-2).find{|i|
		a[i]>a[i+1]
	}
	puts idx ? idx : :OK
}
