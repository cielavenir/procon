int main(){
double m;
int r,y;
scanf("%d%lf%d",&r,&m,&y);
for(;y;y--)m*=1+0.01*r;
printf("%d",(int)m);
return 0;
}

/* Why this fortran program got incorrect?
!pku 2390
implicit none
real::m
integer::r,y,i

read(*,*)r,m,y
do i=1,y
  m=m*(1+0.01*r)
enddo
print "(i0,$)",nint(m)
end
*/