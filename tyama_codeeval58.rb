#!/usr/bin/ruby
#It will take 10 hours to execute...
def maximum3(a)
	if a.length == 0 then return [nil,0] end
	ret = [a[0],0]
	1.step(a.length-1){|i|
		if ret[0] < a[i] then ret = [a[i],i] end
	}
	return ret
end

def alignment(x, y)
	#initialize
	a = Array.new(x.length+1){Array.new(y.length+1, 0)}
	back = Array.new(x.length+1){Array.new(y.length+1, 0)}
	tx = ""; ty = ""; t=""

	#DP
	1.step(a.length-1){|i| a[i][0] = a[i-1][0] - 1;back[i][0]=[i-1,0,  "a"]}
	1.step(a[0].length-1){|j| a[0][j] = a[0][j-1] - 1;back[0][j]=[0,  j-1,"b"]}
	1.step(a.length-1){|i|
		1.step(a[0].length-1){|j|
			z = maximum3([x[i-1].chr == y[j-1].chr ? a[i-1][j-1] : a[i-1][j-1]-1, a[i-1][j]-1, a[i][j-1]-1])
			a[i][j]=z[0];
			case z[1]
				when 0 then back[i][j]=[i-1,j-1,"c"]
				when 1 then back[i][j]=[i-1,j,  "a"]
				when 2 then back[i][j]=[i,  j-1,"b"]
			end
		}
	}

	return -a[x.length][y.length]
end

a=[]
while gets
a<<$_.chomp
end
f=[nil]*a.size
q=['hello']
while !q.empty?
	x=q.shift
	a.length.times{|i|
		if !f[i]&&alignment(x,a[i])==1
			f[i]=1
			q.push(a[i])
		end
	}
	#p f.count{|e|e}
end
p f.count{|e|e} #4844 (send as PHP).