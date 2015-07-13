#!/usr/bin/ruby
def parse(s)
	a,b=s.split(':').map(&:to_i)
	a*60+b
end
$h=Hash.new{|h,k|h[k]={}}
def dfs(lst,goal)
	if lst.last==goal
		0
	else
		$h[lst.last].each{|k,v|
			if !lst.include?(k)
				r=dfs(lst+[k],goal)
				if r
					return r+v
				end
			end
		}
		nil
	end
end
		
A=gets.chomp
L=gets.split
gets.to_i.times{
	a,b,c,d=gets.split
	n=parse(b)-parse(d)
	$h[a][c]=n
	$h[c][a]=-n
}
B=gets.chomp
T=parse(gets)
puts L[(dfs([A],B)+T)%1440/60]