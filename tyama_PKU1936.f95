!pku 1936
implicit none
character*100000::s,t
integer::i,j,ret
do while(.true.)
  i=1
  j=1
  ret=0
  read(*,*,err=900,end=900),s,t
  do while(t(j:j).ne." ")
    if(s(i:i).eq.t(j:j)) then
      i=i+1
      if(s(i:i).eq." ") then
        ret=1
        exit
      endif
    endif
    j=j+1
  enddo
  if (ret.eq.0) then
    write (*,"(a)"),"No"
  else
    write (*,"(a)"),"Yes"
  endif
enddo
900 end