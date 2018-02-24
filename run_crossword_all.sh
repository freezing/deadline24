#!/bin/bash

TEST_DIR="C_Crossword"
FILENAME="crossword"
START_TEST_SET=1
END_TEST_SET=1

if [ "$#" -eq 0 ]; then
    echo "Running template tests: [$START_TEST_SET, $END_TEST_SET]";
elif [ "$#" -eq 2 ]; then
    START_TEST_SET=$1
    END_TEST_SET=$2
fi

./build.sh

for test_set_num in $(seq ${START_TEST_SET} ${END_TEST_SET}); do
    # Figure out filename:
    if [ ${test_set_num} -lt 10 ]
    then
        filename="${TEST_DIR}/${FILENAME}0${test_set_num}"
    else
        filename="${TEST_DIR}/${FILENAME}${test_set_num}"
    fi

    input_filename=$(echo "$filename.in")
    output_filename=$(echo "$filename.out")

    echo "./run_task.sh C < ${input_filename} > ${output_filename}"
    ./run_task.sh C < ${input_filename} > ${output_filename}
done