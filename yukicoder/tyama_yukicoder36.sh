#!/bin/bash
a=(NO YES);echo ${a[((`factor|wc -w`>3))]}