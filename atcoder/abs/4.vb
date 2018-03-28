module ABC087B
	sub Main(ByVal args() as String)
		dim a,b,c,x,i,j,k,r as integer
		a=Console.ReadLine()
		b=Console.ReadLine()
		c=Console.ReadLine()
		x=Console.ReadLine()
		for i=0 to x\500
			for j=0 to (x-500*i)\100
				k=x-500*i-100*j
				if k mod 50=0 andalso c>=k\50 andalso a>=i andalso b>=j
					r+=1
				end if
			next
		next
		Console.WriteLine(r)
	end sub
end module
