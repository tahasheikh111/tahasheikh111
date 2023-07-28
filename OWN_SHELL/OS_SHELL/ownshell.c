#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

// ls | grep .txt   Pipe output of ls to input of grep

// ls > files.txt   Redirect output of ls to file

// sort < files.txt    Redirect input of sort from file

// ls 2> error.log   Redirect error output of ls to file

void display()
{

    system("clear");

    printf("                                    ROCKET  🚀       SHELL\n");
}

void lineprint()
{

    printf("\n----🚀----🚀----🚀----🚀----🚀----🚀----🚀----🚀----🚀----🚀----🚀----🚀----\n");
}

void successfullyrun()
{
    // printf("RUN SUCCESSFUL\n\n\n");
}

int main()
{
    display();
    char buffer[100];
    pid_t pid;
    int changedirectory = 0;
    int checkpartb = 0;
    char *arguments_arr[11] = {NULL};
    // initialize to NULL
    char history_array[100][100];
    int counter_history = 0;
    int last10 = 0;
    int commandno = 0;
    int countpipes = 0;
    int arr_pipe_present[10];
    int index_pipe_present = 0;
    int count_input_redirect = 0;
    int arr_stdin[10];
    int index_stdin_present = 0;
    int arr_stdout[10];
    int count_output_redirect = 0;
    // for tokenizatio

    int count_arguments = 0;

    // char* arguments[12] = {"ls", "--color=auto", NULL}; // initialize with "--color=auto"
    while (1)
    {
        printf("Enter Command: ");

        fgets(buffer, sizeof(buffer), stdin);
        buffer[strlen(buffer) - 1] = '\0';
        // assignment2 part

        if (sizeof(buffer) != 0)
        {
            // printf("NOTHING ENTERs\n");
            if (strcmp(buffer, "History") != 0 && strcmp(buffer, "history") != 0 && strcmp(buffer, "HISTORY") != 0 && strcmp(buffer, "!!") != 0 && strcmp(buffer, " !!") != 0 && strcmp(buffer, " !! ") != 0 && buffer[0] != '!')
            {
                // checkall possible cases
                strncpy(history_array[counter_history], buffer, 100); // add in history array

                counter_history++;
            }
        }

        // printf("Before Check Flag\n");
        //  int loop=0;
        //  for(;buffer[loop]!='\0';loop++){
        //      printf("%c",buffer[loop]);
        //  }
        if (buffer[strlen(buffer) - 1] == '&')
        {

            checkpartb = 1; // printf("FLAGS ON \n");

            buffer[strlen(buffer) - 1] = '\0';
        }
        else if (buffer[strlen(buffer) - 2] == '&' && buffer[strlen(buffer) - 1] == ' ')
        {

            checkpartb = 1; // printf("FLAGS ON \n");

            buffer[strlen(buffer) - 2] = '\0';
        }
        // printf("CHECK PART B %d \n", checkpartb);
        //  printf("After check flag\n");

        // printf("YOU WRITE: %s \n ", buffer);

        if (strcmp(buffer, "!!") == 0 || strcmp(buffer, " !!") == 0 || strcmp(buffer, " !! ") == 0)
        {
            strncpy(buffer, history_array[counter_history - 1], 100); // only last command enter in history array again

            strncpy(history_array[counter_history], buffer, 100); // added in history
            counter_history++;
        }
        if (buffer[0] == '!' && strcmp(buffer, "!!") != 0 && strcmp(buffer, " !!") != 0 && strcmp(buffer, " !! ") != 0)
        {

            int i = 1;
            //to_maintain_history 
            char history_NO[5];

            int a = 0;
            for (; i < strlen(buffer); i++)
            {
                history_NO[a] = buffer[i];
                a++;
            }
            commandno = atoi(history_NO);

            printf("COMMAND NO iS %d \n", commandno);
            memset(history_NO, 0, sizeof(history_NO)); // clear the char array

            if (commandno > 0 && commandno <= counter_history)
            {
                strncpy(buffer, history_array[commandno - 1], 100);

                strncpy(history_array[counter_history], buffer, 100);

                counter_history++;
            }
            else
            {
                // printf("History NO FOund\n");
            }
        }
        if (strcmp(buffer, "History") == 0 || strcmp(buffer, "history") == 0 || strcmp(buffer, "HISTORY") == 0)
        {

            if (counter_history == 0)
            {
                printf("Empty\n");
            }
            int i = counter_history - 1;

            for (; i >= 0; i--)
            {
                printf("📝 %d : ", i + 1);

                printf("%s \n", history_array[i]);
            }
        }
        if (strcmp(buffer, "exit") == 0)
        {
            break;
        }
        else
        {

            char *args = NULL;

            int countspaces = 0;

            char *token;

            // printf("%d Spaces \n", countspaces);

            count_arguments = 0;

            args = NULL;

            token = strtok(buffer, " ");
            // printf("tokens: %s \n", token);
            // printf("Before loop\n");
            while (token != NULL)
            { // limit the number of arguments to 10
                // printf("In loop\n");
                arguments_arr[count_arguments] = token;
                // printf("argument index: %s \n", arguments[index]);
                count_arguments++;
                token = strtok(NULL, " ");
                // printf("tokens 2 : %s \n", token);
            }
            arguments_arr[count_arguments] = NULL; // add NULL terminator
            // countpipes
            // countredirection
            countpipes = 0;

            count_input_redirect = 0;

            count_output_redirect = 0;
            int i = 0;

            for (; i < count_arguments; i++)
            {
                if (strcmp(arguments_arr[i], "|") == 0)
                {
                    countpipes++;
                }
                else if ((strcmp(arguments_arr[i], "<") == 0 || strcmp(arguments_arr[i], "0<") == 0))
                {
                    count_input_redirect++;
                }
                else if ((strcmp(arguments_arr[i], ">") == 0 || strcmp(arguments_arr[i], "1>") == 0 || strcmp(arguments_arr[i], ">>") == 0) || strcmp(arguments_arr[i], "2>") == 0)
                {
                    count_output_redirect++;
                }
            }
            i = 0;
            // printf("Total noof pipes %d \n", countpipes);
            // printf("Total noof inputredirection %d \n", inputredirect);
            // printf("Total noof outputredirection %d \n", outputredirect);
            // printf("Indexes for pipes array \n");
            // for (; i < a1; i++)
            // {
            //     printf("Present at : %d \n", arr_pipe_present[i]);
            // }
            // printf("Indexes for input redirection array \n");
            // i = 0;
            // for (; i < a2; i++)
            // {
            //     printf("Present at : %d \n", arr_stdin[i]);
            // }
            // printf("Indexes for output redirection array \n");
            // i = 0;
            // for (; i < a3; i++)
            // {
            //     printf("Present at : %d \n", arr_stdout[i]);
            // }
            // cd commands
            if (arguments_arr[0] != NULL && strcmp(arguments_arr[0], "cd") == 0)
            {
                if (arguments_arr[1] != NULL)
                {
                    if (chdir(arguments_arr[1]) == -1)
                    {
                        perror("cd");
                    }
                    else
                    {
                        printf("DIRECTOR CHANGE SUCCESSFULL\n");
                    }
                }
                else
                {
                    chdir(getenv("HOME"));
                }
            }
            else if (arguments_arr[0] != NULL && strcmp(arguments_arr[0], "mkfifo") == 0)
            {
                printf("MAKE FIFO RUNS\n ");
                if (arguments_arr[1] != NULL)
                {
                    int er = mkfifo(arguments_arr[1], 0666);
                    if (er < 0)
                    {
                        printf("Already Present \n");
                    }
                }
                else
                {
                    printf("INcomplete\n");
                }
            }
            else
            {
                // for child process
                // execute execvp
                // for assignment1
                if (countpipes == 0 && count_input_redirect == 0 && count_output_redirect == 0)
                {
                    pid = fork();

                    if (pid == 0)
                    {
                        // printf("%d In Child Pid() \n", getpid());
                        // printf("IN CHILD \n");
                        printf("\n");
                        if (strcmp(arguments_arr[0], "History") == 0 || strcmp(arguments_arr[0], "history") == 0 || strcmp(arguments_arr[0], "HISTORY") == 0)
                        {
                            exit(1);
                        }
                        if (execvp(arguments_arr[0], arguments_arr) == -1)
                        {
                            perror("Error");
                            exit(1);
                        }
                    }
                    else if (pid > 0)
                    {
                        // printf("IN PARENT \n");
                        // printf("%d In Parent Pid() \n", getpid());
                        if (checkpartb == 0)
                        {
                            wait(NULL);
                            // printf("Wait Running command '%s' in background (PID=%d)\n", arguments[0], pid);
                        }
                        else
                        {
                            printf("NO WAIT..\n");
                            // printf("No Wait Running command '%s' in background (PID=%d)\n", arguments[0], pid);
                        }
                        checkpartb = 0;
                    }
                    else
                    {
                        printf("Error in fork()\n");
                        exit(1);
                    }
                }    ///////////////////////////////////////////////////////////////////////////
                else // assignment2 // yani pipes exist kerta inputoutput redirect
                {

                    int max_arguments = 256;
                    int max_commands = 256;
                    char *commands[max_arguments][max_commands];
                    char *input_files[max_commands];
                    char *output_files[max_commands];
                    char *append_files[max_commands];
                    char *error_file[max_commands];
                    int num_commands = 0;
                    int i = 0;
                    int fd_pipe_2d[max_commands - 1][2];
                    int status;
                    int pid;
                    int j = 0;
                    i = 0;
                    // Parse the input command into a sequence of smaller commands
                    for (; i < count_arguments; i++)
                    {
                        if (strcmp(arguments_arr[i], "<") == 0 || strcmp(arguments_arr[i], "0<") == 0)
                        {

                            i++; // Input redirection
                            input_files[num_commands] = arguments_arr[i];

                            // printf("INPUT FILE : %s \n",in_files[num_commands]);
                        }
                        else if (strcmp(arguments_arr[i], ">") == 0 || strcmp(arguments_arr[i], "1>") == 0)
                        {

                            i++; // Output redirection
                            output_files[num_commands] = arguments_arr[i];

                            // printf("OUTPUT FILE : %s \n",out_files[num_commands]);
                        }
                        else if (strcmp(arguments_arr[i], ">>") == 0)
                        {
                            i++; // Output with append mode redirection
                            append_files[num_commands] = arguments_arr[i];
                        }
                        else if (strcmp(arguments_arr[i], "2>") == 0)
                        {
                            i++; // Error redirection
                            error_file[num_commands] = arguments_arr[i];
                        }
                        else if (strcmp(arguments_arr[i], "|") == 0)
                        {
                            // Pipe
                            // printf("PIPE CALLED FOR %d \n",num_commands-1);
                            pipe(fd_pipe_2d[num_commands - 1]); // just like int fd[2]; piped(fd)
                        }
                        else
                        {
                            // Command argument
                            commands[num_commands][j++] = arguments_arr[i];
                            // printf("%s \n",arguments[i]);
                        }

                        if (arguments_arr[i + 1] == NULL || strcmp(arguments_arr[i + 1], "|") == 0)
                        {
                            // or when it is a pipe symbol indicating that the next argument belongs to a new command
                            //  End of a command
                            // printf("PLACED NULL\n");
                            commands[num_commands][j] = NULL;
                            num_commands++;
                            j = 0;
                        }
                    }
                    // printf("NO OF COMMANDS %d \n",num_commands);

                    // Execute each command in the pipeline
                    i = 0;
                    for (; i < num_commands; i++)
                    {
                        // printf("i--> %d \n",i);
                        pid = fork();

                        if (pid == 0)
                        {
                            // Child process
                            if (i > 0)
                            {
                                // printf("IN LOOP i>0 %d > 0 \n",i);
                                //  Redirect standard input to the read end of the pipe
                                // After duplicating the file descriptor, we no longer need to keep the original file descriptor pipe_fds[i - 1][0] open. Therefore, we close it using close(pipe_fds[i - 1][0]). Similarly, we also close the write end of the pipe pipe_fds[i - 1][1] using close(pipe_fds[i - 1][1]) because we do not need it anymore in the current command.
                                dup2(fd_pipe_2d[i - 1][0], STDIN_FILENO); // previous end

                                close(fd_pipe_2d[i - 1][0]);

                                close(fd_pipe_2d[i - 1][1]);
                                // printf("AFTER DUP2 in loop i>0 %d > \n",i);
                            }
                            if (i < num_commands - 1)
                            {
                                //-------------------------------------------------
                                //|read_end|                              |write_end|
                                //-------------------------------------------------
                                // printf("IN LOOP i<num_commands-1 %d< \n",i);
                                // Redirect standard output to the write end of the pipe
                                dup2(fd_pipe_2d[i][1], STDOUT_FILENO);

                                close(fd_pipe_2d[i][0]);
                                
                                close(fd_pipe_2d[i][1]);
                                // printf("AFTER DUP2 in loop i<num_commands-1 %d< \n",i);
                            }
                            // printf("BEfore Execute COMMAND FUNCTION %d \n",i);
                            // execute_command(commands[i], in_files[i], out_files[i],append_files[i],err_file[i]);
                            // printf("===========================Execute command Function\n");
                            // printf("ARGUMENT IS %s \n",args[0]);
                            // printf("Input FILE : %s \n",in_file);
                            // printf("Output File : %s \n",out_file);
                            // printf("APPEND FILE : %s \n",append_file);
                            // printf("Error FILE : %s \n",err_file);
                            int input_fd;  // = STDIN_FILENO;
                            int output_fd; // = STDOUT_FILENO;
                            int error_fd;  // =STDERR_FILENO;
                            int apend_fd;
                            char **args = commands[i];
                            char *in_file = input_files[i];
                            char *out_file = output_files[i];
                            char *append_file = append_files[i];
                            char *err_fi = error_file[i];
                            int appflag = 0;
                            if (in_file != NULL)
                            {
                                input_fd = open(in_file, O_RDONLY);
                                dup2(input_fd, STDIN_FILENO);
                            }
                            if (out_file != NULL)
                            {
                                output_fd = open(out_file, O_CREAT | O_WRONLY | O_TRUNC, 0666);
                                dup2(output_fd, STDOUT_FILENO);
                            }
                            if (append_file != NULL)
                            {
                                apend_fd = open(append_file, O_CREAT | O_WRONLY | O_APPEND, 0666);
                                dup2(apend_fd, STDOUT_FILENO);
                            }
                            if (err_fi != NULL)
                            {
                                error_fd = open(err_fi, O_CREAT | O_WRONLY | O_TRUNC, 0666);
                                dup2(error_fd, STDERR_FILENO);
                            }

                            execvp(args[0], args);
                        }
                        else
                        {
                            // Parent process
                            if (i > 0)
                            {
                                // Close the read end of the previous pipe

                                close(fd_pipe_2d[i - 1][0]);

                                close(fd_pipe_2d[i - 1][1]);
                            }
                            // printf("======Parent having pid %d \n",getpid());
                            waitpid(pid, &status, 0);
                        }
                    }
                    dup2(2, STDERR_FILENO);
                    dup2(1, STDOUT_FILENO);
                    dup2(0, STDIN_FILENO);
                    memset(commands, 0, sizeof(commands));
                    memset(input_files, 0, sizeof(input_files));
                    memset(output_files, 0, sizeof(output_files));
                    memset(append_files, 0, sizeof(append_files));
                    memset(error_file, 0, sizeof(error_file));
                    num_commands = 0;
                    i = 0;
                    memset(fd_pipe_2d, 0, sizeof(fd_pipe_2d));
                }

                //  wait(NULL);
                // printf("%d Id in Parent \n", getpid());
                // checkpartb=0;
                // sleep(1);
            }

            lineprint();
            successfullyrun();
        }
    }

    printf("TAHA SHEIKH\n");
    system("clear");
    return 0;
}