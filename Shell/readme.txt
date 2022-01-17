In order to use Myshell, make sure that you are logged on to your system. Open the default terminal and type the following commands :

gcc Myshell.c -lreadline
./a. out

The above mentioned commands are used to compile the C file by the name Myshell and ./a.out is the terminal command used to execute the executable file by name a.out..If you want to get more information or help for this command try following commands For e.g To see help, try command :
help

Concepts of System call

The interface between the operating system and the user program is defined by the set of the extended instructions that the operating system provides, and that set of instructions is called system calls. In other words, a system call is a way for programs to interact with the operating systems. Basically a computer program can request a service from the kernel of the operating system. Some of the system call used in program are as following :

fork()
To create a new process, it is done using the system call fork() which created a new “child” process which is an exact replica of the “parent” i.e the process which executed the system call. The child process begins executions at the point where the call to fork() returns. fork() returns 0 to the child process, and the child’s process ID (pid) to the parent.

wait()
When a process creates a child process, sometimes it becomes necessary that the parent process should execute only after the child has finished. The wait() system call does exactly the same. In other words the wait system call makes the parent wait for the child to be executed.

exit()
The exit terminates the myshell program and returns to the default terminal of the system.

pipe()
The pipe system call is used to transfer the output from the one process to the other process as input. In other words it is the form of redirection of the output from one process to another process for further processing.

exec() 
The exec() is a system call used to replace the entire current calling process with a new process. The main difference between fork() and exec() is, that the fork() generates a duplicated copy of the calling process whereas exec() replace the entire current calling process with a new program all together.

Program environment and background program execution
The program is used in the Ubuntu operating system. The default terminal is used to read the myshell.c which receives the user input from the terminal and generates output and passes it back to the terminal for display. However the program myshell.c is written in the C language in an IDE program called Clion.

