integer t,s(0:1023,0:1023),i1,i2,i3,i4,i,j
read(*,*)i1,i2
do while(.true.)
  read(*,"(i1)",advance="no"),t
  if(t==3) then
    exit
  elseif(t==1) then
    read(*,*)i1,i2,i3
    s(i1,i2)=s(i1,i2)+i3
  else
    t=0
    read(*,*)i1,i2,i3,i4
    do i=i1,i3
      do j=i2,i4
        t=t+s(i,j)
      enddo
    enddo
    print "(i0)",t
  endif
enddo
end