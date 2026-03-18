*This project has been created as part of the 42 curriculum by mmittelb.*

# push_swap

## Description

`push_swap` is a sorting program that takes a list of integers as parameters and sorts them in ascending order using only two stacks (**Stack A** and **Stack B**) and a limited set of allowed operations.  

The goal of this project is to sort data efficiently, minimizing the number of operations. It also helps develop a deep understanding of data structures (especially linked lists), stack manipulation, and algorithm optimization in C.

The program is evaluated based on its performance with datasets of size 3, 4, 5, 100, and 500.

### Allowed Operations

The program manipulates the stacks with the following operations:  
- `sa` / `sb` – swap the first two elements of **Stack A** or **B**  
- `ss` – `sa` and `sb` at the same time  
- `pa` / `pb` – push the top element from **Stack A** to **B** or from **B** to **A**  
- `ra` / `rb` – rotate **Stack A** or **B** upwards (first element becomes last)  
- `rr` – `ra` and `rb` at the same time  
- `rra` / `rrb` – rotate **Stack A** or **B** downwards (last element becomes first)  
- `rrr` – `rra` and `rrb` at the same time  

### Sorting Strategy

1. **Chunking**

	- The list is divided into several chunks depending on the total number of elements.
	- Smaller inputs use fewer chunks, while larger inputs use more. 

2. **Push to Stack B in Chunks**

   	- The program iterates through **Stack A** and pushes the elements that belong to the current chunk to **Stack B**.
	- To improve efficiency:
		- If a pushed value is in the lower half of the chunk, **STACK B** is rotated.
		- If the next target element in **Stack A** is not at the top, both stacks are rotated simultaneously using `rr`.
	- This step is repeated until all elements of the current chunk are in **Stack A** and we repeat the process for the next chunk.

3. **Rebuilding Stack A**
 
   - Once all elements are in **Stack B**, the three largest numbers are pushed back to **Stack A**, even if they are not yet in order.
   - They are then reordered using a short sequence of operations, including temporary moves back to **Stack B** if necessary, until the three elements are sorted in ascending order.
   - This process is repeated until all elements have been moved back to **Stack A**.

### Bonus Program Overview

- The bonus program verifies whether a given sequence of operations correctly sorts the numbers provided as arguments.
- It reads operations from standard input using `get_next_line()` and prints OK if the list is sorted, or KO otherwise.

## Instructions

### Compile mandatory part

```bash
make
```
This will create the executable `push_swap`.

### Run mandatory part

To run `push_swap`, pass a list of integers as arguments. The program prints the operations needed to sort the numbers in ascending order.

Example:

```bash
./push_swap 3 2 5 1 4
pb
pb
sa
pa
pa
```

### Compile bonus part

```bash
make bonus
```
This will create the executable `checker`.

### Run bonus part

Example:

```bash
./checker 3 2 1
```

Enter operations:

```bash
sa
rra
```

Press Ctrl + D to end input.

### Example of using push_swap with checker:

```bash
ARG=$(shuf -i 1-10000 -n 500 | tr '\n' ' ')    
./push_swap $ARG | ./checker $ARG
```

## More Testing

A `tests/` folder is provided for easier testing and benchmarking. It contains:

- `rng.py` – generates a list of random integers.  
- `range.sh` – script to run `push_swap` on a default set of numbers and verify sorting.  
- `benchmark.sh` – script to run `push_swap` multiple times, gather statistics, and verify sorting. 

### Running the range script

```bash
./range.sh
```

- The script runs `push_swap` on a set of random numbers (500 by default) and uses the `checker` program  to verify that the output is correctly sorted.

### Running the benchmark script

```bash
./benchmark.sh
```

- The script uses the `checker` program to verify that the numbers are sorted correctly.
- It will prompt for the number of runs and generate random test cases.
- At the end, it will report **Best**, **Worst**, and **Average** number of operations.

## Visualization

You can also visually inspect how the sorting algorithm performs using an external visualizer project.