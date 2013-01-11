!2007 Domestic A
implicit none
integer::judge
integer::n,tmp
do while(.true.)
  read(*,*),n
  if(n.eq.0) then
    exit
  endif
  tmp=judge(n)
end do
end

integer function judge(n)
  integer::n
  integer::ma,mi,s,x,i,result
  ma=0
  mi=1000
  s=0
  i=0
  do while(i.lt.n)
    read(*,*),x
    if(x.lt.mi) then
      mi=x
    endif
    if(x.gt.ma) then
      ma=x
    endif
    s=s+x
    i=i+1
  end do
  result=(s-ma-mi)/(n-2)
  write(*,"(i0)"),result
  judge=0
  return
end