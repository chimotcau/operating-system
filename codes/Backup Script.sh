#!/bin/bash

SRC=$1
DEST=$2

if [ -z "$SRC" ] || [ -z "$DEST" ]; then
    echo "Usage: $0 source_directory destination_directory"
    exit 1
fi

TIMESTAMP=$(date +"%Y-%m-%d_%H-%M-%S")
BACKUP_NAME=$(basename "$SRC")_backup_$TIMESTAMP.tar.gz

echo "Creating backup..."
tar -czf "$DEST/$BACKUP_NAME" -C "$(dirname "$SRC")" "$(basename "$SRC")"

echo "Backup saved to $DEST/$BACKUP_NAME"
