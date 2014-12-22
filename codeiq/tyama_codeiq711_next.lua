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

N=6
e0={}
f0={}
r=0
for i=1,N do
	e0[i]=0
	f0[i]=0
	e0[N+i]=1
	f0[N+i]=1
end
table.sort(e0)
table.sort(f0)
repeat
	repeat
		flg=0
		zero1=0
		zero2=N
		one1=0
		one2=N
		for i=1,N*2 do
			if e0[i]==0 then zero1=zero1+1 end
			if e0[i]==1 then one1=one1+1 end
			if f0[N*2+1-i]==0 then zero2=zero2-1 end
			if f0[N*2+1-i]==1 then one2=one2-1 end
			if zero1==zero2 then flg=flg+1 end
			if one1==one2 then flg=flg+1 end
		end
		if flg>=2 then r=r+1 end
	until not next_permutation(f0)
until not next_permutation(e0)
print(r)