#!/usr/bin/ruby
n=gets.to_i
gets
result=[[nil]*n,[nil]*n]
missing=[]
n.times{|i|
	a=gets.split
	if a[2].start_with?('Missing')
		missing<<[i,0]
	else
		result[0][i]=a[2].to_f
	end
	if a[3].start_with?('Missing')
		missing<<[i,1]
	else
		result[1][i]=a[3].to_f
	end
}
while missing.any?{|e,k|!result[k][e]}
	missing.each{|e,k|
		next if result[k][e]
		start=e-1
		start-=1 while !result[k][start]
		stop=(e+1)%result[k].size
		stop=(stop+1)%result[k].size while !result[k][stop]
		start-=result[k].size if start>stop
		siz=stop-start
		start_val=result[k][start]
		stop_val=result[k][stop]
		diff=(stop_val-start_val)/siz
		(start+1...stop).each{|i|
			result[k][i]=start_val+diff*(i-start)
		}
	}
end
missing.each{|e,k|p result[k][e]}