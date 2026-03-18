#!/bin/bash

CHECKER="../checker"

make -C .. && make bonus -C .. && make -C .. clean

for N in 500; do
	echo
	echo "Running push_swap with $N random numbers"

	ARG=$(python3 -u rng.py "$N")
	OPS=$(../push_swap $ARG)

	if [ -f "$CHECKER" ]; then
		RESULT=$(../push_swap "${ARG}" | $CHECKER "${ARG}")
		if [ "$RESULT" == "OK" ]; then
			echo "Checker verified push_swap output successfully!"
		else
			echo "Checker failed to run $N: $RESULT"
			exit 1
		fi
	else
		echo "No checker found, skipping verification!"
	fi
done
