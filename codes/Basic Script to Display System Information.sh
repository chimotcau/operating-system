#!/bin/bash

echo "System Information"
echo "------------------"
echo "Hostname: $(hostname)"
echo "Uptime: $(uptime -p)"
echo "Current User: $(whoami)"
echo "Kernel Version: $(uname -r)"
echo "Free Memory:"
free -h
