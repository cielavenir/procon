#!/usr/bin/lua
while true do
	n=io.read("*n")
	k=io.read("*n")
	m=io.read("*n")
	if n==0 then break end
	r=0
	for i=1,n-1 do r=(r+k)%i end
	print((r+m)%n+1)
end