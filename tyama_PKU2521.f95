!pku 2521
!N,M,P,C
!N=buy
!M=sell
!M+C=money customer paid
!P=fake money
!M+C-P=true money
!N+C-(M+C-P)=N-M+P=output
!
!We do not have to read c because at the read of fortran the file-pointer goes to next line.
implicit none

integer n,m,p
goto 9
do while(n/=0)
print "(i0)",n-m+p
9 read(*,*)n,m,p
enddo
end