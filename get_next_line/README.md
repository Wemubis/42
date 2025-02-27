# get_next_line

## Introduction

This project was completed as part of the curriculum at the 42 School. The goal is to implement a function called "get_next_line" that allows reading a line from a file descriptor, whether it is a file or the standard input.

<br>

## Description

The function `get_next_line` must read a line from a file descriptor, store that line in a buffer, and return it with each call of the function. The project involves practicing dynamic memory management and handling file descriptors in C programming.

<br>

## Features

- Read a line from a file descriptor.
- Handle multiple file descriptors simultaneously.
- Dynamic memory management to avoid memory leaks.

<br>

## Implementation

The implementation of `get_next_line` requires managing the read buffer, handling newline characters, and dynamically managing memory. The function should be capable of handling arbitrarily large files and managing multiple file descriptors simultaneously.

<br>

## Usage

1. **Compile the project:**

    ```bash
    make
    ```

2. **Using it in your program:**

    ```c
    #include "get_next_line.h"

    int main() {
        int fd = open("example.txt", O_RDONLY);
        char *line;

        while (get_next_line(fd, &line) > 0) {
            printf("%s\n", line);
            free(line);
        }

        close(fd);
        return 0;
    }
    ```