# 📜 Get Next Line

<div align="center">
  <img height="200" src="https://github.com/leogaudin/42_project_badges/blob/main/badges/get_next_line_bonus.webp"  />
</div>

**Get Next Line** is a C function that reads a single line from a file descriptor, regardless of its length. This project is commonly featured in programming courses to practice dynamic memory management and file handling in C.

---

## 📂 Project Structure

The project includes the following files:

| File                        | Description                                                                |
|-----------------------------|----------------------------------------------------------------------------|
| `get_next_line.c`           | Contains the main implementation of the `get_next_line` function.          |
| `get_next_line.h`           | Header file for the function, declaring necessary prototypes.              |
| `get_next_line_bonus.c`     | Bonus version of `get_next_line` (supports multiple file descriptors).      |
| `get_next_line_bonus.h`     | Header file for the bonus version.                                         |
| `get_next_line_utils.c`     | Contains utility functions used in `get_next_line`.                        |
| `get_next_line_utils_bonus.c` | Utility functions for the bonus version.                                 |

---

## 🚀 Features

1. Read a single line from a file or standard input.
2. Handle dynamic buffers for large files.
3. Bonus: Support multiple file descriptors.

---

## 🔧 Usage

### Compilation

To compile the project, use a compiler like `gcc`. Below are typical commands:

#### Basic Version:
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o gnl
```
#### Bonus Version:
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c -o gnl_bonus
```
#### ⚠️ Note: The BUFFER_SIZE macro must be defined at compile time to specify the buffer size.

#### Example Execution
```bash
./gnl < file.txt
```
#### Expected Function
```c
char *get_next_line(int fd);
```
#### Parameters:
fd: The file descriptor to read from.
#### Returns:
A string containing the next line, or NULL on error or EOF.

---

## 📜 Key Rules

1. Memory Management: All allocations must be freed to avoid memory leaks.
2. System Call Optimization: read should only be called when necessary.
3. Buffer Size: Behavior depends on the BUFFER_SIZE value.

---

## 🛠️ Testing

Use test files or standard input to verify the following:

\. Basic cases: Normal files, single lines, empty files. 

\. Complex cases: Large lines, multiple file descriptors (bonus). 

\. Stress tests: Large files, unusual BUFFER_SIZE values. 

---
## 🤝 Contributing
#### If you'd like to contribute to this project, feel free to fork the repository, make your changes, and submit a pull request!
---
## 🏆 Acknowledgments
#### A big thank you to the open-source community and all the resources that helped in the creation of this project.
---
