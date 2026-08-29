# Victor_Shell

There's an simple and high customizable shell. You can change, but be careful with the Apache-2.0 license. Great Luck and Enjoy the ride.

---

# How it Works

A shell needs to compute and input, and based on this transfer it to the kernel working as a middle layer between the user, and the kernel. So, it's a essencial and great exercise for understand the low-communication level between
a program and the kernel.

The program begins with:

```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

//Definindo o macro do buffer_size
#define MAX_INPUT 1024
#define MAX_ARGS 64

```

The stdio.h library is the fundamental lib that permite us to get some input's and output's commands. As the fgets, printf, scanf, getchar() function.
