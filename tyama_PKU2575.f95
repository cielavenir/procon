!pku 2575
implicit none
integer::abs !func

character*100000::str
integer::a,b,i,n,x
integer::list(0:3000),array(0:3000)
do while(.true.)
1000 read (*,"(a)",end=900,err=900), str

!very dirty workaround for some empty lines...
  read (str(1:10),*,end=1000,err=1000),n

  read (str(1:),*),(list(i),i=0,n)
  do i=1,n-1
    array(i)=0
  enddo
  do i=1,n-1
  x=abs(list(i)-list(i+1))
  if(x.gt.3000) then
    write (*,"(a)"),"Not jolly"
    goto 1000
  endif
  array(x)=1
  enddo
  do i=1,n-1
    if(array(i).eq.0) then
      write (*,"(a)"),"Not jolly"
      goto 1000
    endif
  enddo
  write (*,"(a)"),"Jolly"
enddo
900 end

integer function abs(n)
  integer::n
  abs=n
  if(n.lt.0) then
    abs=-n
  endif
end