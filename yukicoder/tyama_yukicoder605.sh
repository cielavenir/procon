#!/bin/sh
tr '\n' ' '|awk '{printf("%.6f",6.2831853*($2-$1))}'
