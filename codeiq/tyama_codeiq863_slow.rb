#!/usr/bin/ruby
$m=0
$ma=[]
def dfs(a,i)
	if $m<a.size
		puts a.size.to_s+' '+a.map{|e|e[0]}*' '
		$ma=a.dup
		$m=a.size
	end
	i.step($data.size-1){|j|
		if a.last[2]<$data[j][1]
			dfs(a+[$data[j]],j+1)
		end
	}
end
$data=$<.map{|e|
	a=e.split
	a[1]=~/^(\d+)\/(\d+)-(\d+)\/(\d+)$/
	[a[0],$1.to_i*100+$2.to_i,$3.to_i*100+$4.to_i]
}.sort_by{|e|e[1]}
$data.size.times{|i|
	p i
	dfs([$data[i]],i+1)
}