!PKU1006
!x=p(mod23)
!x=e(mod28)
!x=i(mod33)
!の最小解x0からdを引いた物を出力せよ(ただし0の場合21252(23*28*33)を出力)。
!
!http://www004.upp.so-net.ne.jp/s_honma/gauss/gauss.htm
!の方法を用いる。
!拙作Rubyライブラリ(is07kuno)のchinese(中国剰余定理solver)によると
!chinese([[5,23],[20,28],[34,33]]) により 5544 14421 1288 が出力されたのでこの値を計算に使用する。
!---以下235B---
integer p,e,i,d,j
j=0
goto 9
do while(p>=0)
j=j+1
d=mod(p*5544+e*14421+i*1288-d,21252)
if(d<=0)then
d=d+21252
endif
print "(a,i0,a,i0,a)","Case ",j,": the next triple peak occurs in ",d," days."
9 read(*,*)p,e,i,d
enddo
end