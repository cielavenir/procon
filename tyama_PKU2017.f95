!pku 2017
implicit none
integer::routine
integer::n,tmp
do while(.true.)
  read(*,*),n
  if(n.eq.-1) then
    exit
  endif
  tmp=routine(n)
  enddo
end

integer function routine(n)
  integer::n
  integer::a,b,i,before,total
  i=0
  before=0
  total=0
  do while(i.lt.n)
    read(*,*),a,b
    b=b-before
    before=before+b
    total=total+a*b
    i=i+1
  enddo
  write(*,"(i0,a)"),total," miles"
end