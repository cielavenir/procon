<?php
function process($s){
    $bidx=strpos($s,'(');
    while($bidx!==FALSE){
        $count=1;
        $eidx=$bidx+1;
        for(;$count;$eidx++){
            if($s{$eidx}=='(')$count++;
            if($s{$eidx}==')')$count--;
        }
        $s=substr($s,0,$bidx).process(substr($s,$bidx+1,$eidx-1-($bidx+1))).substr($s,$eidx);
        $bidx=strpos($s,'(');
    }
    $matches=null;
    while(preg_match("/^(.*?)(-?\\d+)([*\\/])(-?\\d+)(.*)$/",$s,$matches)){
        if($matches[3]=='*')
            $s=$matches[1].($matches[2]*$matches[4]).$matches[5];
        else
            $s=$matches[1].intval($matches[2]/$matches[4]).$matches[5];
    }
    while(preg_match("/^(.*?)(-?\\d+)([+Z])(-?\\d+)(.*)$/",$s,$matches)){
        if($matches[3]=='+')
            $s=$matches[1].($matches[2]+$matches[4]).$matches[5];
        else
            $s=$matches[1].($matches[2]-$matches[4]).$matches[5];
    }
    return $s;
}
$a=process(str_replace(' ','',$s));
?>