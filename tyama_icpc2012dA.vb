module icpc2007dA
    sub Main(ByVal args() as String)
        dim i,n as integer
        n=Console.ReadLine()
        for i=1 to n
			dim s(3) as string
			dim a(3) as integer
			s=Split(Console.ReadLine())
			a(0)=s(0):a(1)=s(1):a(2)=s(2)
			a(0)-=1:a(1)-=1
			Console.WriteLine(196471-a(0)*195-int(a(0)/3)*5-a(1)*20+if(a(0) mod 3<>2,int(a(1)/2),0)-a(2))
		next
	end sub
end module