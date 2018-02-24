#!/bin/bash

if [ "$#" -eq 0 ]; then
    echo "Illegal number of parameters"
    exit 1
fi

TASK_NAME=$1

# Shift arguments by 1.
shift

cd bin
# echo "Running task: $(pwd)/$TASK_NAME";
$(echo "./$TASK_NAME $@")
