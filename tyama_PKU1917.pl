#!/usr/bin/perl --

=pod
tyama_poetry.pl 070702
TUD Programming Contest 2001
http://tud-pc.informatik.tu-darmstadt.de/archive/Darmstadt2001/web/html/
5. Automatic Poetry

regexほすぃなー。
というわけで、これはC(++)には移植できませんので解答だと思わないことw

#Javaにはjava.util.regexがあるらしいですが。。。まあぼちぼちと

[in]
5
ein <r>eisender braucht <sch>uhe
ein ...
kentucky <f>reit <sch>icken
...
darf ich sie an die <t>heke <b>itten
darf ich sie an ...
<><>
...
a<a>a<a>
a...

[out]
ein reisender braucht schuhe
ein scheisender braucht ruhe
kentucky freit schicken
schreit ficken
darf ich sie an die theke bitten
darf ich sie an bheke titten


aaaa
aaaa

#こういう入出力なんで実行時間は当然0.00秒と
=cut

$n = <>;
while($n--){
$s = <>;
$s =~ /(.*)\<(.*)\>(.*)\<(.*)\>(.*)/;
($s1, $s2, $s3, $s4, $s5) = ($1, $2, $3, $4, $5);
$s = <>;
$s =~ /(.*)\s?\.\.\./;
print <<"EOM";
$s1$s2$s3$s4$s5
$1$s4$s3$s2$s5
EOM
}
exit;