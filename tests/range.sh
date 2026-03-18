#!/bin/bash

OS_NAME="$(uname)"
if [[ "$OS_NAME" == "Darwin" ]]; then
    CHECKER="./checker_mac"
elif [[ "$OS_NAME" == "Linux" ]]; then
    CHECKER="./checker_linux"
else
    echo "Unsupported OS: $OS_NAME"
    exit 1
fi

make -C .. && make -C .. clean

for N in 500; do
	echo
	echo "Running push_swap with $N random numbers"

	ARG=$(python3 -u rng.py "$N")
	OPS=$(../push_swap $ARG)

	if [ -f "$CHECKER" ]; then
		RESULT=$(../push_swap $ARG | $CHECKER $ARG)
		if [ "$RESULT" != "OK" ]; then
			echo "Checker failed to run $N: $RESULT"
		fi
	fi
done

echo
echo "Success"
echo
