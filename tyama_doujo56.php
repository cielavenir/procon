#!/usr/bin/php
<?php
$s1='フラペチーノふらぺちーの';
$hiragana=preg_split("//u",'あいうえおかきくけこさしすせそたちつてとなにぬねのはひふへほまみむめもやゆよらりるれろわをんぁぃぅぇぉっゃゅょがぎぐげござじずぜぞだぢづでどばびぶべぼぱぴぷぺぽ',-1,PREG_SPLIT_NO_EMPTY);
$katakana=preg_split("//u",'アイウエオカキクケコサシスセソタチツテトナニヌネノハヒフヘホマミムメモヤユヨラリルレロワヲンァィゥェォッャュョガギグゲゴザジズゼゾダヂヅデドバビブベボパピプペポ',-1,PREG_SPLIT_NO_EMPTY);
$trans=array();
for($i=0;$i<count($hiragana);$i++){
    $trans[$hiragana[$i]]=$katakana[$i];
	$trans[$katakana[$i]]=$hiragana[$i];
}
$s2=strtr($s1,$trans);
echo $s1."\n";
echo $s2."\n";
?>