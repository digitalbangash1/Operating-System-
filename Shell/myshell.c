
#include "myshell.h"






/*---------- introduction to our shell-------------*/
void OurSHEll() {
    printf("\n----------------Welcome to our shell-------------------");
    printf("     i\\\n"
           "     I \\\n"
           "     I  \\\n"
           "     I*--\\\n"
           "     I    \\\n"
           "     I     \\\n"
           "     I______\\\n"
           "_____I__O______\n"
           "\\     ( )     /\n"
           "^^^^^^^^^^^^^^^^\n"
           "_______________________ ");
    char *username = getenv("USER");
    printf("\n\n\nUSER is: @%s", username);
    printf("\n\n\n\n");
    sleep(3);
    clear();
}



    //


// -------------Function to take input----------
    int takeInput(char* str) {
        char* buf;

        buf = readline("\n>>>Our Shell>>> ");
        if (strlen(buf) != 0) {
            add_history(buf);
            strcpy(str, buf);
            return 0;
        } else {
            return 1;
        }
    }
//Help command
void openHelp()
{
    puts("\n***WELCOME TO MY SHELL HELP***"
         "\nList of Commands supported:"
         "\n>cd"
         "\n>ls"
         "\n>exit"
         "\n>pipe handling"
         );

    return;
}




    // Function to print Current Directory.
    void printDir()
    {
        char cwd[1024];
        getcwd(cwd, sizeof(cwd));
        printf("\nDir: %s", cwd);
    }




    // Function where the system command is executed
    /*''''''''''''''''''''''''''' here we use fork() function''''''''''''''''''''''''*/
    void execArgs(char** parsed)
    {
        // Forking a child
        pid_t pid = fork();

        if (pid == -1) {
            printf("\nFailed forking child..");
            return;
        } else if (pid == 0) {
            if (execvp(parsed[0], parsed) < 0) { /* Here we used exec system where if the parsed < 0 should print
 *                                                    "Could not execute command, try again pls "*/
                printf("\nCould not execute command, try again pls ");
            }
            exit(0);
        } else {
            // Here we use wait to waiting for child to terminate
            wait(NULL);
            return;
        }
    }



    // Function where the piped system commands is executed
    /*'''''''''''''''''''''' here we use pipe function''''''''''''''''''''''''''*/
    void execArgsPiped(char** parsed, char** parsedpipe)
    {
        // 0 is read and 1 is write
        int pipefd[2];
        pid_t p1, p2;

        if (pipe(pipefd) < 0) {
            printf("\nPipe could not be created");
            return;
        }
        p1 = fork();
        if (p1 < 0) {
            printf("\nCould not fork");
            return;
        }

        if (p1 == 0) {
            // ---------------Child 1 executing----------

            close(pipefd[0]);
            dup2(pipefd[1], STDOUT_FILENO);
            close(pipefd[1]);

            if (execvp(parsed[0], parsed) < 0) {
                printf("\nCould not execute command 1..");
                exit(0);
            }
        } else {
            // Parent executing
            p2 = fork();

            if (p2 < 0) {
                printf("\nCould not fork");
                return;
            }

            // Child 2 executing..
            // It only needs to read at the read end
            if (p2 == 0) {
                close(pipefd[1]);
                dup2(pipefd[0], STDIN_FILENO);
                close(pipefd[0]);
                if (execvp(parsedpipe[0], parsedpipe) < 0) {
                    printf("\nCould not execute command 2..");
                    exit(0);
                }
            } else {
                // parent executing, waiting for two children
                wait(NULL);
                wait(NULL);
            }
        }
    }




    // Function to execute builtin commands
    int ownCmdHandler(char** parsed)
    {
        int NoOfOwnCmds = 3, i, switchOwnArg = 0;
        char* ListOfOwnCmds[NoOfOwnCmds];
        char* username;

        ListOfOwnCmds[0] = "exit";
        ListOfOwnCmds[1] = "cd";
        ListOfOwnCmds[2] = "help";


        for (i = 0; i < NoOfOwnCmds; i++) {
            if (strcmp(parsed[0], ListOfOwnCmds[i]) == 0) {
                switchOwnArg = i + 1;
                break;
            }
        }

        switch (switchOwnArg) {
            case 1:
                printf("\nGoodbye\n");
                exit(0);
            case 2:
                chdir(parsed[1]);
                return 1;
            case 3:
                openHelp();
                return 1;

            default:
                break;
        }

        return 0;
    }

   // function for finding pipe
    int parsePipe(char* str, char** strpiped)
    {
        int i;
        for (i = 0; i < 2; i++) {
            strpiped[i] = strsep(&str, "|");
            if (strpiped[i] == NULL)
                break;
        }

        if (strpiped[1] == NULL)
            return 0; // returns zero if no pipe is found.
        else {
            return 1;
        }
    }

    // function for parsing command words
    void parseSpace(char* str, char** parsed)
    {
        int i;

        for (i = 0; i < 1000; i++) {
            parsed[i] = strsep(&str, " ");

            if (parsed[i] == NULL)
                break;
            if (strlen(parsed[i]) == 0)
                i--;
        }
    }

    int processString(char* str, char** parsed, char** parsedpipe)
    {

        char* strpiped[2];
        int piped = 0;

        piped = parsePipe(str, strpiped);

        if (piped) {
            parseSpace(strpiped[0], parsed);
            parseSpace(strpiped[1], parsedpipe);

        } else {

            parseSpace(str, parsed);
        }

        if (ownCmdHandler(parsed))
            return 0;
        else
            return 1 + piped;
    }

    int main()
    {
        char inputString[100], *parsedArgs[1000];
        char* parsedArgsPiped[1000];
        int execFlag = 0;
        OurSHEll();


        while (1) {
            // print shell line
            printDir();
            // take input
            if (takeInput(inputString))
                continue;
            // process
            execFlag = processString(inputString,
                                     parsedArgs, parsedArgsPiped);
            // execflag returns zero if there is no command
            // or it is a builtin command,
            // 1 if it is a simple command
            // 2 if it is including a pipe.

            // execute
            if (execFlag == 1)
                execArgs(parsedArgs);

            if (execFlag == 2)
                execArgsPiped(parsedArgs, parsedArgsPiped);
        }
        return 0;
    }
