#!/usr/bin/ruby
n=gets.to_i
result=[nil]*n
missing=[]
n.times{|i|
	a=gets.split
	if a[2].start_with?('Missing')
		missing<<i
	else
		result[i]=a[2].to_f
	end
}
while missing.any?{|e|!result[e]}
	missing.each{|e|
		next if result[e]
		start=e-1
		start-=1 while !result[start]
		stop=(e+1)%result.size
		stop=(stop+1)%result.size while !result[stop]
		start-=result.size if start>stop

		siz=stop-start
		start_val=result[start]
		stop_val=result[stop]
		diff=(stop_val-start_val)/siz
		(start+1...stop).each{|i|
			result[i]=start_val+diff*(i-start)
		}
	}
end
missing.each{|e|p result[e]}