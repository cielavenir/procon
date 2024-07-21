#!/usr/bin/lua
reverse=function(a,start,size)
	local end_=start+size-1
	for i=0,size/2-1 do
		z=a[start+i]
		a[start+i]=a[end_-i]
		a[end_-i]=z
	end
end
next_permutation=function(a,n)
	if not n then n=#a end
	if n<0 or #a<n then
		return false
	end
	local i=0
	reverse(a,n,#a+1-n)
	i=#a-1
	while i>=1 do
		if a[i]<a[i+1] then break end
		i=i-1
	end
	if i<1 then
		reverse(a,1,#a)
		return false
	end
	local k=i
	i=#a
	while i>=k+1 do
		if a[k]<a[i] then break end
		i=i-1
	end
	local l=i
	local z=a[k]
	a[k]=a[l]
	a[l]=z
	reverse(a,k+1,#a+1-(k+1))
	return true
end

n=io.read("*n")
k=io.read("*n")
io.read("*l")
s=io.read("*l")
a={}
for i=1,n do
	a[i]=s:byte(i)
end
table.sort(a)
r=0
repeat
	i=n-k+1
	while i>0 do
		x=i
		y=i+k-1
		while x<y do
			if a[x]~=a[y] then
				break
			end
			x=x+1
			y=y-1
		end
		if x>=y then
			break
		end
		i=i-1
	end
	if i<=0 then
		r=r+1
	end
until not next_permutation(a)
print(r)
