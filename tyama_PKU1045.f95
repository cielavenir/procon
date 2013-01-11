!pku1045
integer::n,i,x
real::v,r,c,w
read(*,*),v,r,c,n
do i=1,n
  read(*,*),w
  x=nint(v/sqrt(r*r+1/w/w/c/c)*r*1000)
  write(*,"(i0,a,i3.3)"),x/1000,".",mod(x,1000)
enddo
end