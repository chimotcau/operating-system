#!/bin/bash

THRESHOLD=80

echo "Checking disk usage..."
df -h | awk 'NR>1 {if ($5+0 > '"$THRESHOLD"') print "WARNING: "$6" is at "$5" usage"}'
