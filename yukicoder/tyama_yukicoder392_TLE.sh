#!/bin/bash
awk 'NR>1{system("dc -e?1+2op<<<"$0"|sed -es/.//|tr 01 LR")}'
