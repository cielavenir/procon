#!/bin/sh
awk '$0=$1<$2?"Better":"Worse"'