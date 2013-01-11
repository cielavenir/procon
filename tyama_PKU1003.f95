!pku 1003
implicit none
integer::n,tmp
real::len,now
do while(.true.)
  read(*,*),len
  if(len.eq.0.0) then
    exit
  endif
  n=1
  now=0.0
  do while(now.lt.len)
    now=now+(1.0/(n+1))
    n=n+1
  end do
  write(*,"(i0,a)"),(n-1)," card(s)"
end do
end