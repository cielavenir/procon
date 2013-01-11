integer i,n,a,b,c,d
read(*,*)n
do i=1,n
read(*,*)d
a=d/25
d=mod(d,25)
b=d/10
d=mod(d,10)
c=d/5
d=mod(d,5)
print "(i0,a,i0,a,i0,a,i0,a,i0,a)",i," ",a," QUARTER(S), ",b," DIME(S), ",c," NICKEL(S), ",d," PENNY(S)"
enddo
end