#!/usr/bin/awk -f
{printf"%f",$1*$2/($1+$2)}
