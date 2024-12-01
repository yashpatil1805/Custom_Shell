# Custom_Shell
This project implements a custom shell in C that executes basic system commands and includes a count utility. Users can run commands with arguments or use count to calculate characters, words, or lines in a file. It leverages system calls like fork and execlp for process handling and supports interactive input for dynamic execution.
Files to Include:
myshell.c: The main C program.
.gitignore: To exclude unnecessary files like object files or executables.
README.md: Documentation for the project.
Example README.md Content:
Custom Shell and File Counter
Description:
This project implements a basic shell in C with functionality for command execution and a custom count command. The shell supports running system commands, as well as counting characters, words, or lines in a given file.

Features:
Execute basic shell commands like ls, cat, etc.
Supports argument passing for commands.
Custom count command:
count c <filename>: Counts characters in the file.
count w <filename>: Counts words in the file.
count l <filename>: Counts lines in the file.
Setup Instructions:
Clone the Repository:

bash
Copy code
git clone https://github.com/your-username/Custom_Shell_File_Counter.git
cd Custom_Shell_File_Counter
Compile the Program: Use gcc to compile the program:

bash
Copy code
gcc myshell.c -o myshell
Run the Program: Execute the compiled binary:

bash
Copy code
./myshell
Usage:
Basic Shell Commands:

Enter any system command like ls, cat filename, mkdir newdir, etc., and press Enter.
Example:
bash
Copy code
myshell$ ls
Custom count Command:

Format:
bash
Copy code
count <option> <filename>
Options:
c: Count characters.
w: Count words.
l: Count lines.
Example:
bash
Copy code
myshell$ count w sample.txt
File Descriptions:
myshell.c: The main C program implementing the shell and file counter.
.gitignore: Excludes unnecessary files like .o and compiled binaries.
Example Output:
System Command:

bash
Copy code
myshell$ ls
file1.txt file2.txt myshell.c
Custom count Command:

bash
Copy code
myshell$ count w sample.txt
Total number of words=42
Dependencies:
GCC Compiler
Linux/Unix environment (for fork, execlp, and system calls).
