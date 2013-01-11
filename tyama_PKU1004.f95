integer i,q
real r,t
r=0.0
do i=1,12
read(*,*)t
r=r+t
enddo
r=r/12
q=int(r*100.0)
print "(a,i0,a,i2)","$",q/100,".",mod(q,100)
end