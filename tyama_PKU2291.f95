!PKU2291
implicit none
integer::i,t,n,i0,i1,tmp
integer*2,dimension(1000)::a
read(*,*),t
do i=1,t
  read(*,*),n,(a(tmp),tmp=1,n)
  do i0=1,n-1
    do i1=i0+1,n
      if(a(i0).lt.a(i1)) then
        tmp=a(i0);a(i0)=a(i1);a(i1)=tmp
      endif
    enddo
  enddo
  
  tmp=0
  do i0=1,n
    if(tmp.lt.a(i0)*i0) then
      tmp=a(i0)*i0
    endif
  enddo
  write(*,"(i0)"),tmp
  
enddo
end