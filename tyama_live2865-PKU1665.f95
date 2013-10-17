real x,d,t
integer r,i
i=0
do while(.true.)
read(*,*)d,r,t
if(r==0)then
exit
endif
i=i+1
x=d*r*3.1415927/63360
print "(a,i0,a,i0,f0.2,a,f0.2)","Trip #",i,": ",int(x),x-int(x)," ",x*3600/t
enddo
end