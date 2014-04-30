imports System
imports System.Collections.Generic
module CodeIQRoute
	iterator function permutation(of T as IComparable)(ByVal x as List(of T),optional ByVal _n as integer?=Nothing) as IEnumerable(of List(of T))
		dim n as integer=if(_n.HasValue,_n,x.Count)
		if n<0 orelse x.Count<n
			return
		end If
		dim a as List(of T)=new List(of T)(x)
		a.Sort()
		dim i as integer
		yield a.GetRange(0,n)
		while true
			a.Reverse(n,a.Count-n)
			for i=a.Count-2 to 0 step -1
				if a(i).CompareTo(a(i+1))<0
					exit for
				end if
			next
			if i<0
				a.Reverse(0,a.Count)
				return
			end if
			dim k as integer=i
			for i=a.Count-1 to k+1 step -1
				if a(k).CompareTo(a(i))<0
					exit for
				end if
			next
			dim l as integer=i
			dim z as T=a(k):a(k)=a(l):a(l)=z
			a.Reverse(k+1,a.Count-(k+1))
			yield a.GetRange(0,n)
		end while
	end function

	const N=6
	sub Main(ByVal args() as String)
		dim r,i as integer
		dim e0 as List(of integer)=new List(of integer)()
		dim f0 as List(of integer)=new List(of integer)()
		for i=0 to N-1
			e0.Add(0)
			f0.Add(0)
		next
		for i=0 to N-1
			e0.Add(1)
			f0.Add(1)
		next
		for each _e as List(of integer) in permutation(e0)
			for each _f as List(of integer) in permutation(f0)
				dim flg as integer=0
				dim zero1 as int=0
				dim zero2 as integer=N
				dim one1 as integer=0
				dim one2 as integer=N
				for i=0 to N*2-1
					if _e(i)==0
						zero1+=1
					end if
					if _e(i)==1
						one1+=1
					end if
					if _f(N*2-1-i)==0
						zero2-=1
					end if
					if _f(N*2-1-i)==1
						one2-=1
					end if
					if zero1==zero2
						flg+=1
					end if
					if one1==one2
						flg+=1
					end if
				next
				if flg>=2
					r+=1
				end if
			next
		next
		Console.WriteLine(r)
	end sub
end module