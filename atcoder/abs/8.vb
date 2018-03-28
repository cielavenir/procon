module ABC085C
	sub Main(ByVal args() as String)
		dim n,y,i,j,k as integer
		dim arr(2) as string
		arr=Split(Console.ReadLine())
		n=arr(0):y=arr(1)
		for i=0 to n
			for j=0 to n-i
				k=n-i-j
				if i*1000+j*5000+k*10000=y
					Console.WriteLine("{0} {1} {2}",k,j,i)
					return
				end if
			next
		next
		Console.WriteLine("-1 -1 -1")
	end sub
end module
