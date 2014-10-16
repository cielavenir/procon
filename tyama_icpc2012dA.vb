module icpc2007dA
    sub Main(ByVal args() as String)
        dim i,n as integer
        n=Console.ReadLine()
        for i=1 to n
			dim s(3) as string
			dim y,m,d as integer
			s=Split(Console.ReadLine())
			y=s(0):m=s(1):d=s(2)
			y-=1:m-=1
			Console.WriteLine(196471-y*195-int(y/3)*5-m*20+if(y mod 3<>2,int(m/2),0)-d)
		next
	end sub
end module