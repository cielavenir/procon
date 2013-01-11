integer i
real r,s
read(*,*)r
do while(.true.)
read(*,*)s
if(s>=999)then
exit
endif
i=nint(100*(s-r))
if(i<0)then
print "(a,$)","-"
i=-i
endif
print "(i0,a,i0.2)",i/100,".",mod(i,100)
r=s
enddo
print "(a)","End of Output"
end