!Why is iostat required...?
!
!umm... I prefer end=*... And pi is satisfied with 3.1.
real x,y
integer i,n
read(*,*)n
do i=1,n
read(*,*,end=9)x,y
9 print "(a,i0,a,i0,a)","Property ",i,": This property will begin eroding in year ",int(0.031*(x*x+y*y))+1,"."
enddo
print "(a)","END OF OUTPUT."
end