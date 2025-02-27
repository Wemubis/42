# Libft - 42 School Project

The Libft project at 42 School aims to create a standard library of functions in the C programming language, along with bonus functionalities, to strengthen C programming skills. This library becomes an essential resource for later projects within the school.

<br>

## Description

The Libft library offers a variety of standard C functions, equivalent to those in the standard library. These functions include string manipulation, memory management, character operations, and much more. The design of these functions allows for a deep understanding of how they work, thus reinforcing the fundamentals of programming.

<br>

## Basic Functions

### 1. Strings (`ft_str`)

String manipulation functions include operations such as copying, concatenation, searching, and comparison. They simplify the handling of strings in C.

- **ft_strlen**: Calculates the length of a string.
- **ft_strcpy**: Copies one string into another.
- **ft_strcat**: Concatenates two strings.
- **ft_strcmp**: Compares two strings.
- ...

### 2. Memory (`ft_mem`)

Memory manipulation functions provide tools to allocate and free memory, as well as to manipulate its contents.

- **ft_memset**: Fills a memory area with a specific value.
- **ft_memcpy**: Copies a memory area from a source to a destination.
- ...

### 3. Characters (`ft_char`)

Character operations include converting between uppercase and lowercase, checking a character's category, etc.

- **ft_isalpha**: Checks if a character is a letter.
- **ft_isdigit**: Checks if a character is a digit.
- **ft_tolower**: Converts a letter to lowercase.
- ...

<br>

## Bonus Features

### 1. Linked Lists (`ft_lst`)

Linked lists are dynamic data structures that allow for the flexible storage and organization of data. The Libft library provides functions to manipulate these structures.

- **ft_lstnew**: Creates a new list element.
- **ft_lstadd_front**: Adds an element to the front of the list.
- **ft_lstsize**: Returns the size of the list.
- ...

### 2. ft_printf

The ft_printf function is a customized version of the printf function in C, with extended format specifiers and the ability to modify the color when displaying.

```c
ft_printf("%sNumber: %d, String: %s%s\n", CYAN, 42, "libft", COLOR_OFF);
```

The available colors are: `BLACK`, `RED`, `GREEN`, `YELLOW`, `BLUE`, `PURPLE`, `CYAN`, `WHITE`, `COLOR_OFF`.

<br>

## Usage

### 1. Compile the Library:

```bash
make
```

### 2. Examples
Here are some examples of using the Libft library:

```c
#include "libft.h"

int main() {
    // Using standard functions
    ft_putstr("Hello, World!\n");

    // Using bonus functions (linked lists)
    t_list *list = ft_lstnew("42");
    ft_lstadd_front(&list, ft_lstnew("School"));

    // Using ft_printf with color
    ft_printf("%sNumber: %d, String: %s%s\n", CYAN, 42, "libft", COLOR_OFF);

    return 0;
}
```