module ABC086C
	sub Main(ByVal args() as String)
		dim i,n,t,x,y as integer
		dim arr(3) as string
		n=Console.ReadLine()
		t=x=y=0
		for i=1 to n
			arr=Split(Console.ReadLine())
			dim t0,x0,y0 as integer
			t0=arr(0):x0=arr(1):y0=arr(2)
			dim dt,dx,dy as integer
			dt=t0-t:dx=x0-x:dy=y0-y
			if dx+dy>dt orelse (dt-dx-dy) mod 2>0
				Console.WriteLine("No")
				return
			end if
			t=t0:x=x0:y=y0
		next
		Console.WriteLine("Yes")
	end sub
end module
