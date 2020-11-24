# Simple_Shell

## Description

The main perposoutpe of this project is to recreate a simple shell for learning perposes. It is meant to recreate a prompt and execute commands from a few built in functions and any program stored in locations connected through the environment variable.

Below are the list of files used within the project.

| File | Description |
| ------ | ------ |
|shell.h| Header file to connect all files and standard libraries.|
|main.c| The main file housing the main function and other connected functions.|
|helperfunctions.c| Several functions that convert strings to double pointers, combine elements and return envrionment strings.
|strfunctions.c| small string manipulating function recreations like _strlen and _strcpy.
## Getting Started
TLDR: Pull the latest version of the 'main' branch and compile all .c files.
### Prerequisties
```
Ubuntu LTS v14.04
GCC version 5.5.0 or higher
Basic knowledge of UNIX shells
```
### Installing
1. Clone the "main" branch from the repository into your desired directory.
```
git clone https://github.com/epaschke22/simple_shell.git
```
2. Go into the simple_shell directory.
```
cd simple_shell
```
3. Compile all .c files in the simple_shell directory.
```
gcc *.c -o willy_shell
```
4. Run the output file (willy_shell) locally.
```
./willy_shell
```
At this point, you will enter willy_shell and can do basic commands on a whole different shell!
## Usage
Once all files are compiled together, inputing commands through the prompt with the '$' symbol will execute just like a regular simple shell.

Current working built in commands inlcude:
| Built-in | Description |
| ------ | ------ |
|"exit"| to exit the program|
|"env"| to print out the environment|

## Examples output
```c
$ ls
README.md  a.out  execute.c  helperfunctions1.c  main.c  shell.h  strfunctions.c
$ echo "text"
"text"
$ pwd
/home/simple_shell
$ ls -la
total 48
drwxr-xr-x  3 root root  4096 Nov 20 04:25 .
drwxr-xr-x 12 root root  4096 Nov 16 15:11 ..
drwxr-xr-x  8 root root  4096 Nov 19 20:41 .git
-rw-r--r--  1 root root     0 Nov 11 15:18 README.md
-rwxr-xr-x  1 root root 13978 Nov 20 04:25 willy_shell
-rw-r--r--  1 root root   619 Nov 19 18:03 execute.c
-rw-r--r--  1 root root  2321 Nov 20 03:54 helperfunctions1.c
-rw-r--r--  1 root root  1917 Nov 20 03:37 main.c
-rw-r--r--  1 root root   667 Nov 19 20:29 shell.h
-rw-r--r--  1 root root  1462 Nov 19 20:28 strfunctions.c
$
```

## Interactive vs Non Interactive Mode
For this shell, we were required to allow the user run the shell in interactive or non interactive mode. Below is a nutshell the differences between the two:

### Interactive Mode
Interactive mode is a command line which displays the prompt in front of the user and shows the input. It also shows the previous fed commands or statements in memory of the computer.

### Non Interactive Mode
Non Interactive mode is used to run scripts without displaying the command line prompt for the user. This means the command has to be supplied or piped into the shell program to receive an output. The shell behaves exatcly the same in non interactive compared to interactive mode.
### Example of Interactive mode
```
$ ls
willy_shell  shell.h  main.c. helperfunctions1.c
```

### Example of Non Interactive mode
```
$ echo "ls" | ./willy_shell
willy_shell  shell.h  main.c. helperfunctions1.c
```
## Built With
* [Emacs](https://www.gnu.org/software/emacs/) - A common text editor.
* [Vim](https://www.vim.org/) - The better text editor.
* [Vagrant](https://www.vagrantup.com/) - Development environment menagement.
* [Virtual Box](https://www.virtualbox.org/) - VM manager.
* [Cowsay](https://en.wikipedia.org/wiki/Cowsay) - A great program.
##### Created by:
Erickson Paschke and Jonny Wang
