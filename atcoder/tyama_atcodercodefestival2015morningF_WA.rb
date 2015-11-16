#!/usr/bin/ruby
#ソートして貪欲だとだめなやつだった

n,k=gets.split.map &:to_i
a=gets.split.each_with_index.map{|e,i|[e.to_i,i]}.sort.reverse+[[0,0]]

if true
# O(n)
diff=[0]*n
i=0
while i<n
	d=a[i][0]-a[i+1][0]
	if d>0
		diff[i]=d
		k-=d*(i+1)
		break if k<=0
	end
	i+=1
end
s=0
(n-1).downto(0){|j|s+=diff[j];a[j][0]-=s}
k=-k
(i+1).times{|j|
	a[j][0] += k/(i+1) + (j<k%(i+1) ? 1 : 0)
}
else
# O(k) (TLE)
cur=0
k.times{
	a[cur][0]-=1
	if cur<n-1 && a[cur][0]<a[cur+1][0]
		cur+=1
	else
		cur=0
	end
}
end

b=[0]*n
n.times{|i|b[a[i][1]]=a[i][0]}
r=b.reduce(:+)*2+b.size+b[0]+b[n-1]
b.each_cons(2){|x,y|r+=(x-y).abs}
p r