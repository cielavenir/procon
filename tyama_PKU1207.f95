!pku 1207
!Be careful, for all params are ByRef in Fortran...
implicit none
integer::cycle
integer::m,n,ma,tmp,i,x

do while(.true.)
  read (*,*,end=9),m,n
  write (*,"(i0,a,i0,a,$)"),m," ",n," "

  if(m.gt.n) then
    tmp=m
    m=n
    n=tmp
  endif
 
  i=m+1
  ma=cycle(m)
  do while(i.le.n)
    x=i
    tmp=cycle(x)
    if(tmp.gt.ma) then
      ma=tmp
    endif
    i=i+1
  enddo

  write (*,"(i0)"),ma
enddo
9 end

integer function cycle(m)
  integer::m
  cycle=1
  do while(m.gt.1)
    if(iand(m,1).eq.0) then
      m=m/2
    else
      m=3*m+1
    endif
    cycle=cycle+1
  enddo
end