# Push_swap

## Introduction

This project was completed as part of the curriculum at the 42 School. The main objective is to create an efficient algorithm to sort a stack of integers using a limited set of instructions, while minimizing the total number of instructions.

<br>

## Description

Push_swap implements a sorting algorithm that takes a stack of integers as input and uses two stacks (A and B) along with various operations to sort the integers in ascending order. The allowed operations include, among others, `sa` (swap a), `sb` (swap b), `ss` (swap a and b), `pa` (push a), `pb` (push b), `ra` (rotate a), `rb` (rotate b), `rr` (rotate a and b), `rra` (reverse rotate a), and `rrb` (reverse rotate b).

<br>

## Features

- Efficient sorting of the stack of integers.
- Minimization of the total number of instructions.
- Handling of a small number of integers (about 5 to 500 elements).

<br>

## Implementation

The algorithm uses a combination of insertion sort and other techniques to minimize the number of instructions required. The approach involves several steps, including dividing the initial stack into segments, sorting those segments, and then merging the sorted segments to obtain the final sorted stack.

<br>

## Usage

1. **Compile:**
```bash
  make
```

2. **Run the program:**
```bash
  ./push_swap 3 2 1
```

3. **Verify with the checker:**
```bash
  ./push_swap 3 2 1 | ./checker 3 2 1
```

<br>

## Resources

- [Push_swap project subject](https://github.com/42Paris/push_swap/blob/master/en.subject.pdf)
- [Insertion Sort algorithm](https://en.wikipedia.org/wiki/Insertion_sort)
- [Push_swap wiki: rules and operations](https://github.com/toniandreas/push_swap/wiki/Rules-and-operations)
