# get_next_line

A C function that reads and returns one line at a time from a given file descriptor.
This is a 42 school project designed to teach static variables, dynamic memory
management, and file I/O in C.

## Technologies

- C (C99)
- Standard libraries: `unistd.h`, `stdlib.h`, `stddef.h`

## Build Instructions

Compile the source files alongside your own program:

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o program
```

The `BUFFER_SIZE` macro controls how many bytes are read per `read()` call.
It defaults to 42 if not specified at compilation.

## Usage

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int   fd;
    char  *line;

    fd = open("example.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

Each call to `get_next_line` returns the next line from the file (including `\n`),
or `NULL` when the end of file is reached or an error occurs.

## Key Technical Concepts

- **Static variable**: a persistent buffer (stash) retains leftover data between calls.
- **Dynamic memory allocation**: each returned line is heap-allocated; the caller must free it.
- **Buffered reading**: data is read in chunks of `BUFFER_SIZE` bytes for efficiency.
- **Edge-case handling**: supports files with no trailing newline, empty files, and invalid file descriptors.

## Author

rbourkai - 42 student
