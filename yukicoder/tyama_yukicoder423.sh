#!/bin/sh
awk '$0=$0($0=="ham"?"":"ham")'
