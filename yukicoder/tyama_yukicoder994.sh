#!/bin/sh
sed -n 1p|awk '$0=$1<$2?-1:$2-1a'
