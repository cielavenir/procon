module ABC083B
	sub Main(ByVal args() as String)
		dim n,a,b,r,i,j,s as integer
		dim arr(3) as string
		arr=Split(Console.ReadLine())
		n=arr(0):a=arr(1):b=arr(2)
		r=0
		for i=1 to n
			s=0
			j=i
			while j>0
				s+=j mod 10
				j\=10
			end while
			if a<=s andalso s<=b
				r+=i
			end if
		next
		Console.WriteLine(r)
	end sub
end module
