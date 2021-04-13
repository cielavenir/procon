#!/bin/bash
read a b c d e
echo $(((a*b+c-d)%e))
