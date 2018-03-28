module ABC081B
	sub Main(ByVal args() as String)
		dim i,n,x,r as integer
		r=1<<29
		n=Console.ReadLine()
		dim arr(n) as string
		arr=Split(Console.ReadLine())
		for i=1 to n
			dim r0 as integer
			r0=0
			x=arr(i-1)
			while (x mod 2)<1
				r0+=1
				x\=2
			end while
			if r>r0
				r=r0
			end if
		next
		Console.WriteLine(r)
	end sub
end module
