// scilab-cli -nb -f
n=scanf("%d")
while n<>0
	ma=0;mi=1000;s=0
	for i = 1:n
		x=scanf("%d")
		if x<mi then mi=x; end
		if x>ma then ma=x; end
		s=s+x
	end
	printf("%d\n",(s-mi-ma)/(n-2))
	n=scanf("%d")
end
exit