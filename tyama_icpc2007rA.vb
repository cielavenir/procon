module icpc2007rA
	sub Main(ByVal args() as String)
		dim n,k,m,r,i as integer
		while true
			dim s(3) as string
			s=Split(Console.ReadLine())
			n=s(0):k=s(1):m=s(2):r=0
			if n=0
				exit while
			end if
			for i=1 to n-1
				r=(r+k) mod i
			next
			Console.WriteLine((r+m) mod n + 1)
		end while
	end sub
end module