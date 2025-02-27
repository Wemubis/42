# Pipex

## Introduction

This project was completed as part of the curriculum at the 42 School. The goal is to understand and handle redirections and pipelines in Unix system programming by implementing a program called "pipex" that replicates the functionality of the "pipe" shell command.

<br>

## Description

Pipex simulates the behavior of the "pipe" shell command, which allows the standard output of one command to be redirected to the standard input of another. The objective is to create an executable program that handles two commands passed as arguments, redirecting the output of the first command to the input of the second using pipes.

<br>

## Features

- Execute two commands in parallel with the redirection of the output from the first command to the input of the second.
- Handle input and output from files or standard streams.
- Error handling and appropriate message display.

<br>

## Implementation

The implementation of Pipex is divided into several steps. The program must create a number of pipes, duplicate the necessary file descriptors, execute the commands in child processes, and manage the redirection of streams between the commands.

<br>

## Usage

1. **Compilation:**

    ```bash
    make
    ```

2. **Execution:**

    ```bash
    ./pipex file1 "cmd1" "cmd2" file2
    ```

    Replace "file1", "cmd1", "cmd2", and "file2" with the appropriate file names and commands.

<br>

## Example Usage

```bash
./pipex infile "ls -l" "wc -l" outfile
```
