real r
integer w,s,c
goto 9
do while(s/=0)
c=0
if(r<=4.5.and.w>=150.and.s>=200)then
print "(a,$)","Wide Receiver "
c=1
endif
if(r<=6.0.and.w>=300.and.s>=500)then
print "(a,$)","Lineman "
c=1
endif
if(r<=5.0.and.w>=200.and.s>=300)then
print "(a,$)","Quarterback "
c=1
endif
if(c==0)then
print "(a,$)","No positions"
c=1
endif
print "(a)",""
9 read(*,*)r,w,s
enddo
end