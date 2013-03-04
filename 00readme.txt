rosalind:
mgap/need are broken.

1.
mjudge_old is: http://judge.maximum.vc/
mjudge is: http://m-judge.maximum.vc/
ljudge is: http://www.edu.ics.saitama-u.ac.jp/~s06dm003/problemset/
Possibly mjudge(new)-8 is removed when moving from ljudge.

2.
HNUでCをコンパイルする場合はreturn 0;が必要です。
また、%lldではなく%I64dを使う必要があります(msvcrtの仕様)。

3.
aizuでCをコンパイルする場合return 0;が必要です。
また、ヘッダファイルを#includeしないと通りません。おそらく
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
で大丈夫だと思います。 -- Fixed on 090710

4.
このFortranコードはg95(http://ftp.g95.org/)用です。その証拠として拡張子が.f95になっております。
(拡張子をfにしてしまうとFortran77(固定)形式としてコンパイルしようとして失敗します)。
従いまして、g77でコンパイルするには次の関数を通して特殊な出力をする必要があります。また各行6文字空ける必要があります(固定形式)

      integer function output(n)
        integer::n
        if(n.ge.1000000000) then
        write(*,"(i10)"),n
        elseif(n.ge.100000000) then
        write(*,"(i9)"),n
        elseif(n.ge.10000000) then
        write(*,"(i8)"),n
        elseif(n.ge.1000000) then
        write(*,"(i7)"),n
        elseif(n.ge.100000) then
        write(*,"(i6)"),n
        elseif(n.ge.10000) then
        write(*,"(i5)"),n
        elseif(n.ge.1000) then
        write(*,"(i4)"),n
        elseif(n.ge.100) then
        write(*,"(i3)"),n
        elseif(n.ge.10) then
        write(*,"(i2)"),n
        else
        write(*,"(i1)"),n
        endif
        output=0
        return
      end