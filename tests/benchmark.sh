#!/bin/bash

CHECKER="../checker"

if [ $# -eq 0 ]; then
	NUMS=(100 500)
else
	NUMS=($1)
fi

echo
echo "Number of runs?"
read RUNS

make -C .. && make bonus -C .. && make -C .. clean

for N in "${NUMS[@]}"; do
	echo
	echo "Running with $N Numbers (x$RUNS):"

	BEST=999999999
	WORST=0
	TOTAL=0

	for ((i=1; i<=RUNS; i++)); do
		ARG=$(python3 -u rng.py "$N")
		OPS=$(../push_swap $ARG | wc -l)

		if [ "$OPS" -lt "$BEST" ]; then
			BEST=$OPS
		fi
		if [ "$OPS" -gt "$WORST" ]; then
			WORST=$OPS
		fi
		TOTAL=$((TOTAL + OPS))

		if [ -f "$CHECKER" ]; then
			RESULT=$(../push_swap "${ARG}" | $CHECKER "${ARG}")
			if [ "$RESULT" == "OK" ]; then
				echo "Checker verified push_swap output successfully!"
			else
				echo "Checker failed on run $i: $RESULT"
				exit 1
			fi
		else
			echo "No checker found, skipping verification!"
		fi
	done

	AVG=$((TOTAL / RUNS))

	echo "  Best   -> $BEST"
	echo "  Worst  -> $WORST"
	echo "  Avg    -> $AVG"
	echo
done
