#!/bin/bash

#NOTE: Working directory must be root of the project.

if [ "$#" -eq 0 ]; then
    echo "Illegal number of parameters"
    echo ""
    echo "Example usage: ./run_task.sh template template/template01.in template/template01.out"
    echo "Example usage: ./run_task.sh template < ./template/template01.in"
    echo "Example usage: ./run_task.sh template < ./template/template01.in > ./template/template01.out"
    echo ""
    echo "NOTE: Working directory must be root of the project";
    exit 1
fi

TASK_NAME=$1

# Shift arguments by 1.
shift

$(echo "./bin/$TASK_NAME $@")
