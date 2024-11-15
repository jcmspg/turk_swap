# Push Swap
---
---
## A Double Stack Sorting Algorithm
---
![Stonkers](stonkers.jpeg)
---

Push Swap is a sorting algorithm project for the 42 School that involves sorting a stack of integers using a limited set of operations. The goal is to sort the stack with the minimum number of operations.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Algorithm Description](#algorithm-description)
- [Functions](#functions)
- [Contributing](#contributing)
- [License](#license)

## Introduction

This project is part of the 42 curriculum. It involves sorting a stack of integers using a limited set of operations: `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, and `rrr`. The goal is to sort the stack with the minimum number of operations.

## Features

- Sorting algorithm for stacks
- Handles edge cases such as empty stacks and stacks with duplicate values
- Efficiently sorts stacks with a large number of elements
- Debugging output to trace the state of the stacks
- Modular design with helper functions for each step of the algorithm
- checker program to validate the sorting operations (Bonus part)

## Installation

To install and run the project, follow these steps:

1. Clone the repository:
    ```sh
    git clone https://github.com/yourusername/push_swap.git
    ```

2. Navigate to the project directory:
    ```sh
    cd push_swap
    ```

3. Compile the project:
    ```sh
    make
    ```
4. Compile the checker program:
    ```sh
    make bonus
    ```




## Usage

To run the sorting algorithm, use the following command:

```sh
./push_swap $(shuf -i 1-50 -n 50 | tr '\n' ' ')
```


```sh
./push_swap $(shuf -i 1-50 -n 50 | tr '\n' ' ') | wc -l -> to count the number of operations
```

To validate the sorting operations, use the checker program:

```sh
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```


## Algorithm Description

The Push Swap algorithm works by using two stacks, `A` and `B`, and a set of operations to sort the elements in stack `A`.
It works by identifying the target positions for each element in stack `A` and moving elements to stack `B` to sort them. Once the elements are sorted in stack `B`, they are moved back to stack `A` in the correct order.

We are implementing a sorting algorithm that uses two stacks, `A` and `B`, to sort a list of integers. The algorithm aims to sort the elements in stack `A` using a limited set of operations, such as `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, and `rrr`.

The algorithm used is called Turk Algorithm by A. Yigit Ogun , which is a variation of the Quick Sort algorithm. It works by identifying the target positions for each element in stack `A` and moving elements to stack `B` to sort them. Once the elements are sorted in stack `B`, they are moved back to stack `A` in the correct order. You can find more about the algorithm [here](https://medium.com/@ayogun/push-swap-c1f5d2d41e97).

The targeting works as follows:

- For each element in stack `A`, the algorithm identifies the target position for that element in stack `B`.
- Every node in stack `A` has a target node in stack `B`, and vice versa.
- The algorithm calculates the target positions based on the closest smaller number. If there is none, it assigns as target the largest number in the other stack.
- It then finds the "cheapest" element to move from stack `A` to stack `B` based on the cost of moving each element to its correct position.
- The "cheapest" element is moved to stack `B`, and the process is repeated until all elements except 3 are moved to stack `B`.
- The remaining elements in stack `A` are sorted directly using a simple sorting method.
- The elements in stack `B` are moved back to stack `A` in the correct order, and final adjustments are made to ensure the smallest element is at the top of stack `A`.

The main steps of the algorithm are as follows:

1. **Initial Checks**: 
    - The algorithm starts by checking if stack `A` is already sorted. If it is, no further operations are needed.
    - If stack `A` contains a small number of elements (e.g., 3 or fewer), the algorithm handles these cases separately using a simpler sorting method.

2. **Pushing to Stack B**: 
    - The algorithm identifies and pushes elements from stack `A` to stack `B` based on certain criteria, such as the "cheapest" element to move. The "cheapest" element is determined by calculating the cost of moving each element to its correct position in stack `B`.
    - The `find_cheapest` function is used to find the element with the minimum push cost.
    - The `send_to_b` function handles the actual movement of the "cheapest" element from stack `A` to stack `B`. It prepares both stacks for the move by performing necessary rotations and then pushes the element to stack `B`.

3. **Sorting Stack A**: 
    - Once the size of stack `A` is reduced to a manageable size (e.g., 3 elements), the algorithm sorts these elements directly using a simple sorting method.
    - The `sort_3` function is typically used to sort 3 elements in stack `A`.

4. **Moving Back to Stack A**: 
    - The algorithm then moves elements from stack `B` back to stack `A` in the correct order. This involves finding the appropriate target positions for each element in stack `B` and using rotations to place them correctly in stack `A`.
    - The `locking_targets_a` and `locking_targets_b` functions are used to determine the target positions for each element.
    - The `send_to_a` function handles the actual movement of elements from stack `B` to stack `A`. It prepares stack `A` for the move by performing necessary rotations and then pushes the element to stack `A`.

5. **Final Adjustments**: 
    - After all elements are moved back to stack `A`, the algorithm makes final adjustments to ensure the smallest element is at the top of the stack.
    - The `move_min_to_top` function is used to move the smallest element to the top of stack `A`. It calculates the number of rotations needed and decides whether to use `rotate_a` or `reverse_rotate_a` based on the position of the smallest element relative to the middle of the stack.

### Detailed Steps

#### Initial Checks

- **is_sorted**: Checks if stack `A` is already sorted.
- **ft_parser**: Parses the input and initializes stack `A`.
- **assign_index**: Assigns indices to nodes in stack `A` and marks nodes above the median.

#### Pushing to Stack B

- **find_cheapest**: Finds the node with the minimum push cost in stack `A`.
- **send_to_b**: Moves the "cheapest" node from stack `A` to stack `B`.
  - **double_rotate_top**: Performs simultaneous rotations of both stacks if needed.
  - **double_rev_rotate_top**: Performs simultaneous reverse rotations of both stacks if needed.
  - **get_a_ready**: Prepares stack `A` for the move.
  - **get_b_ready**: Prepares stack `B` for the move.
  - **push_b**: Pushes the node from stack `A` to stack `B`.

#### Sorting Stack A

- **sort_3**: Sorts 3 elements in stack `A`.

#### Moving Back to Stack A

- **locking_targets_a**: Locks target nodes in stack `B` for each node in stack `A`.
- **locking_targets_b**: Locks target nodes in stack `A` for each node in stack `B`.
- **send_to_a**: Moves the top node from stack `B` to stack `A`.
  - **get_a_ready**: Prepares stack `A` for the move.
  - **push_a**: Pushes the node from stack `B` to stack `A`.

#### Final Adjustments

- **move_min_to_top**: Moves the smallest node to the top of stack `A`.
  - **rotate_a**: Rotates stack `A`.
  - **reverse_rotate_a**: Reverse rotates stack `A`.

### Checker Program

The checker program is used to validate the sorting operations performed by the Push Swap algorithm. It reads the input and the list of operations, applies the operations to the input, and checks if the input is sorted after the operations are applied.

The checker program performs the following steps:

1. **Parsing Input**: Parses the input and initializes stack `A`.
2. **Applying Operations**: Reads the list of operations and applies them to the input.
3. **Checking Sorting**: Checks if the input is sorted after applying the operations.
4. **Output**: Prints `OK` if the input is sorted, `KO` otherwise.

The checker program is useful for testing the correctness of the sorting algorithm and ensuring that the operations are applied correctly.

## Conclusion
By following these steps, the Push Swap algorithm efficiently sorts the elements in stack `A` using a limited set of operations. The use of helper functions ensures that each part of the algorithm is modular and easy to understand.
You can find the full implementation of the Push Swap algorithm in the `push_swap.c` file, along with the helper functions used in the sorting process.
You can also find the checker program in the `checker.c` file, which validates the sorting operations performed by the algorithm.

## Functions

### Push Swap Overview
The Push Swap algorithm is implemented using a set of functions that handle different parts of the sorting process. These functions are organized into main functions and helper functions to make the algorithm modular and easy to understand.

#### Main Stack Operations

- `sa`: Swaps the top two elements of stack A.
- `sb`: Swaps the top two elements of stack B.
- `ss`: Swaps the top two elements of both stacks.
- `pa`: Moves the top element of stack B to stack A.
- `pb`: Moves the top element of stack A to stack B.
- `ra`: Rotates stack A (shifts up all elements by one).
- `rb`: Rotates stack B (shifts up all elements by one).
- `rr`: Rotates both stacks.
- `rra`: Reverse rotates stack A (shifts down all elements by one).
- `rrb`: Reverse rotates stack B (shifts down all elements by one).
- `rrr`: Reverse rotates both stacks.

#### Main Functions

- `ft_turk`: Main sorting function that orchestrates the sorting process.
- `send_to_b`: Moves the "cheapest" node from stack A to stack B.
- `send_to_a`: Moves the top node from stack B to stack A.
- `move_min_to_top`: Moves the smallest node to the top of stack A.

#### Helper Functions

- `ft_parser`: Parses the input and initializes stack A.
- `is_sorted`: Checks if stack A is already sorted.
- `find_cheapest`: Finds the node with the minimum push cost in a stack.
- `find_min_node`: Finds the node with the minimum value in a stack.
- `assign_index`: Assigns indices to nodes in a stack and marks nodes above the median.
- `locking_targets_a`: Locks target nodes in stack B for each node in stack A.
- `locking_targets_b`: Locks target nodes in stack A for each node in stack B.
- `get_a_ready`: Prepares stack A for the move.
- `get_b_ready`: Prepares stack B for the move.

### Checker Program Overview
The checker program is implemented using a set of functions that read the input, apply the operations, and check if the input is sorted after the operations are applied. These functions are organized into main functions and helper functions to make the program modular and easy to understand.

#### Main Functions

- `main`: Main function that reads the input, applies the operations, and checks the sorting.
- `get_next_line`: Reads the next line from the input.
- `parse_commands`: Parses the list of operations.

### Conclusion
By using these functions, the Push Swap algorithm and the checker program are implemented in a modular and organized way. The main functions handle the main operations, while the helper functions provide support for specific tasks within the algorithm. This design makes the code easier to read, understand, and maintain.


### Contributing

Contributions are welcome! Please follow these steps to contribute:

1. Fork the repository.
2. Create a new branch:
    ```sh
    git checkout -b feature-branch
    ```
3. Make your changes and commit them:
    ```sh
    git commit -m "Description of your changes"
    ```
4. Push to the branch:
    ```sh
    git push origin feature-branch
    ```
5. Create a pull request.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
