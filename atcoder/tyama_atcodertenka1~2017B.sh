#!/bin/sh
echo $((`sort -n|tail -1|tr \  +`))
