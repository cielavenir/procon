implicit none
integer::a,b
character(99)::s
read(*,*) a,b,s
write(*,'(i0," ",a)') a+b,trim(s)
end