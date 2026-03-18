import sys
import random

def main():
    if len(sys.argv) != 2:
        print(f"Usage: {sys.argv[0]} <number_of_random_numbers>")
        sys.exit(1)

    try:
        n = int(sys.argv[1])
    except ValueError:
        print("Please provide a valid integer.")
        sys.exit(1)

    min_int = -2147483648
    max_int = 2147483647

    total_possible = max_int - min_int + 1
    if n > total_possible:
        print(f"Cannot generate {n} unique numbers between {min_int} and {max_int}.")
        sys.exit(1)

    generated = set()
    while len(generated) < n:
        num = random.randint(min_int, max_int)
        generated.add(num)

    print(" ".join(str(num) for num in generated))

if __name__ == "__main__":
    main()

