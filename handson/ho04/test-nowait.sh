#!/bin/bash
max=1000
n_failed=0
n_passed=0
EXPECTED=$(./act10)
for i in `seq 1 $max`
do
    TEST=$(./act10 &)
    if [ "$TEST" != "$EXPECTED" ]
    then
        n_failed=`expr $n_failed + 1`
    else
        n_passed=`expr $n_passed + 1`
    fi
done

echo "passed: $n_passed out of $max."
echo "failed: $n_failed out of $max."