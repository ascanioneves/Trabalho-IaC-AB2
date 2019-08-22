#include <stdio.h>
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/wait.h>    // libraries
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[], char *envp[]) //main function with the arguments
{
	int i = 0 ; // loop counter
	int pid = fork(); // variable who's saves the return (integer) of the fork function
	char convert[200], command[200]; //convert -> array that saves the pid in string format 
					//command -> array that saves the final bash command in string format
	if(pid < 0) // an error has occurred
	{
		perror("Erro: "); // error message
		exit(-1); // end of the program in this case
	}
	else if(pid == 0) // I am the child process
	{
		if(strcmp(argv[1], "cpu") == 0) // main argument is "cpu"
		{
			for(;;)
			{
				// maximum CPU utilization loop
			}	
		}
		else if(strcmp(argv[1], "cpu-mem") == 0) // main argument is "cpu-mem"
		{
			for(;;)
			{
				malloc(sizeof(char) / 8);// maximum cpu and memory utilization loop
			}
		}
	}
	else // I am the father process
	{
		sprintf(convert, "%d", pid); // conversion of pid to string
		if(strcmp(argv[1], "cpu") == 0) // main argument is "cpu"
		{
			printf("  PID / CPU(%%)\n"); // to organize the program
			strcpy(command, "ps -e -o pid,pcpu | grep ");// put a part of the CPU monitoring command in the string 
			strcat(command, convert);// concatenates the string command with pid already transformed into string
		}
		else if(strcmp(argv[1], "cpu-mem") == 0) // main argument is "cpu-mem"
		{
			printf("  PID / CPU%%\n"); // to organize the program
			strcpy(command, "ps -e -o pid,pcpu | grep ");// put a part of the CPU monitoring command in the string 
			strcat(command, convert); // concatenates the string command with pid already transformed into string
			strcat(command, ";pmap ");// put a part of the memory monitoring command in the string 
			strcat(command, convert);// concatenates the string command with pid already transformed into string
			strcat(command, " | grep -i total"); // final part of the memory monitoring command
		}

		while(i < 10) // the execution of the program with a limit of 10 seconds
		{
			system(command); // running the command in bash
			sleep(1); // wait 1 second
			i++; // increment 1 in the counter
		}

		strcpy(command, "kill "); // saving the string ("kill ") in the string command to kill the child process
		strcat(command, convert); // concatenating a command string ("kill ") with the child pid
		system(command); // killing the child process

	}

	perror ("") ; // show the status of the program execution

	printf ("Tchau !\n") ; // show the message "Tchau !"
	exit(0) ; // successfully finished of the process
}
