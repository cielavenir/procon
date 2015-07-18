!PKU3173
implicit none
integer::t(20,20)
integer::n,s,i,j
read(*,*),n,s
do i=1,n
  do j=1,i
    t(i,j)=s
    s=mod(s,9)+1
  enddo
enddo

do i=1,n
  s=0
  do j=1,n
    if(s.ne.0) then
      write(*,"(a,$)")," "
    endif
    s=1

    if(j.lt.i) then
      write(*,"(a,$)")," "
    else
      write(*,"(i0,$)"),t(j,i)
    endif
  enddo
  write(*,"(a)"),""
enddo
end