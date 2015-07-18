!pku 2683
implicit none
integer::data
integer::n,i,tmp

read(*,*),n
do i=1,n
  tmp=data()
enddo
end

integer function data()
  integer::m,m0,y,n,i,r,x,parse
  read(*,*),m,y,n
  r=m
  do i=1,n
    m0=m !because the ByRef problem in Fortran...
    x=parse(m0,y)
    if(x>r) then
      r=x
    endif
  enddo
  write(*,"(i0)"),r
  data=0
  return
end

integer function parse(m,y)
  integer::m,y
  integer::t,c,i,dm
  real::r
  dm=0
  read(*,*),t,r,c
  if(t.ne.0) then
    do i=1,y
      dm=int(r*m)
      m=m+dm-c
    enddo
  else
    do i=1,y
      dm=dm+int(r*m)
      m=m-c
    enddo
    m=m+dm
  endif
  parse=m
end