# 💾 Get Next Line: Persistent File Descriptor Reading

## 42 Project | Static Variables, File Descriptors, and Buffering

Get Next Line is a fundamental project that requires programming a function capable of reading a line from any given file descriptor. The main challenge is to manage data persistence across multiple function calls, introducing the critical concept of static variables in C programming. This project teaches proper handling of read buffering, memory allocation, and the flexibility required to read from different sources (files, standard input, etc.).

## 🎯 Project Objective

The goal is to write a single function, get_next_line(), that can be called in a loop to read the text pointed to by a file descriptor, one line at a time.

The function must return the line that was read, including the terminating newline character (\n), unless the end of the file is reached without one. It must return NULL if nothing else remains to be read or an error occurs.

## ✨ Prototype and Functionality

**Function Name** --> get_next_line

**Prototype** --> 	char *get_next_line(int fd); 

**Parameters** --> fd: The file descriptor to read from 

**Return Value** --> Read line (correct behavior) / NULL (EOF or error) 

**External Functions** -> 	read, malloc, free

## ⚙️ Mandatory Requirements and Challenges

### Buffering Management 
The program must handle reading with various BUFFER_SIZE values, which are defined at compilation time using the -D BUFFER_SIZE=n flag.

### Persistence 
The most complex aspect is using a static variable to save any leftover data from the buffer between calls to the function, allowing the next call to start where the previous one left off.

### Efficiency
The function is required to read as little data as possible each time it is called, returning the current line immediately once a newline character is encountered.

### Flexibility
Must work correctly when reading from a regular file and when reading from the standard input (STDIN).

## 🚀 Bonus Part: Multi-File Descriptor

If the mandatory part is perfect, the bonus part requires enhancing get_next_line() to handle simultaneous reading from multiple file descriptors.

### Simultaneous Handling
The function must manage multiple file descriptors (e.g., fd 3, 4, and 5) at the same time.

### State Integrity
A call to read from one file descriptor must not affect the reading state of any other file descriptor.

### Single Static Variable
The entire bonus implementation must be developed using only one static variable.

## 🚫 Forbidden Elements (Constraints)

**Global Variables** 

**lseek()**

**Using libft** (Helper functions must be created manually in a separate file ).

