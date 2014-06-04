var n=0
scanf("%d".UTF8String(),&n)
while n>0 {
	var ma=0
	var mi=1000
	var sum=0
	var s=0
	var sum=0
	for i in 0..n {
		scanf("%d".UTF8String(),&n)
		if ma<s {ma=s}
		if mi>s {mi=s}
		sum+=s
	}
	printf("%d\n".UTF8String(), (sum-ma-mi)/(n-2))
	scanf("%d".UTF8String(),&n)
}