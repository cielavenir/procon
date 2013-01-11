integer i,a(3)
read(*,*)(a(i),i=1,3)
do i=1,3
if(a(i)<=168)then
print "(a,i0)","CRASH ",a(i)
goto 9
endif
enddo
print "(a)","NO CRASH"
9 end