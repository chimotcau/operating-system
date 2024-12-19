#!/bin/bash

LOGFILE="/var/log/login_tracker.log"

echo "Monitoring user logins. Log file: $LOGFILE"

if [ ! -f "$LOGFILE" ]; then
    touch "$LOGFILE"
fi

tail -Fn0 /var/log/auth.log | while read line; do
    echo "$line" | grep "session opened for user" >> "$LOGFILE"
done
