integer x,y,n,i,step
read(*,*)n
do i=1,n
read(*,*)x,y
print "(i0)",step(y-x)
enddo
end

integer function step(n)
  integer n,i,ret;
  if(n<=2) then
    step=n
    return
  endif
  i=1;ret=0
  do while(.true.)
    ret=ret+2*i;
    if(n-ret.le.0) then
      step=2*i
      return
    endif
    if(n-ret.le.i+1) then
      step=2*i+1
      return
    endif
    i=i+1
  enddo
end