imports System
imports System.Runtime.InteropServices

module TrickyB
	const libc as string="libc.so.6"
	<DllImport(libc,CallingConvention:=CallingConvention.Cdecl)>
	shared function scanf(format as string, byref a as integer) as integer
	end function
	<DllImport(libc,CallingConvention:=CallingConvention.Cdecl)>
	shared function scanf(format as string, byref a as long, byref b as long, byref c as long) as integer
	end function
	<DllImport(libc,CallingConvention:=CallingConvention.Cdecl)>
	shared function printf(format as string) as integer
	end function
	<DllImport(libc,CallingConvention:=CallingConvention.Cdecl)>
	shared function printf(format as string, a as double) as integer
	end function
	<DllImport(libc,CallingConvention:=CallingConvention.Cdecl)>
	shared function printf(format as string, a as double, b as double) as integer
	end function

	' concat newline as "&Environment.NewLine"
	sub Main()
		dim T,i as integer
		' scanf("%d",T)
		T=integer.Parse(Console.ReadLine())
		for i=1 to T
			dim Z() as string
			Z=Console.ReadLine().Split(" "c)
			dim a,b,c as long
			' scanf("%lld%lld%lld",a,b,c)
			a=long.Parse(Z(0))
			b=long.Parse(Z(1))
			c=long.Parse(Z(2))
			if a=0 then
				if b=0 then
					Console.WriteLine(if(c=0,"3","0"))
				else
					Console.WriteLine(String.Format("1 {0:f12}",-c*1.0/b))
				end if
			else
				if a<0 then
					a=-a
					b=-b
					c=-c
				end if
				dim d as double=b*b-4.0*a*c
				if Math.Abs(d)<1e-9 then
					Console.WriteLine(String.Format("1 {0:f12}",-b/2.0/a))
				elseif d<0 then
					Console.WriteLine("0")
				else
					'acknowledgement: http://tricky.contest.atcoder.jp/submissions/120839
					dim x,y as double
					if b>0 then
						x = (-b-Math.Sqrt(d))/2/a
						y = c*1.0/a/x
					else
						y = (-b+Math.Sqrt(d))/2/a
						x = c*1.0/a/y
					end if
					Console.WriteLine(String.Format("2 {0:f12} {1:f12}",x,y))
				end if
			end if
		next
	end sub
end module
