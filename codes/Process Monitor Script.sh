#!/bin/bash

echo "Monitoring processes for user: $USER"
echo "-----------------------------------"

while true; do
    clear
    echo "Active Processes:"
    ps -u $USER -o pid,comm,%cpu,%mem --sort=-%cpu | head -10
    sleep 5
done
