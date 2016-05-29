#!/bin/sh
sed 's/./&\n/g'|sort -r|tr -d '\n'