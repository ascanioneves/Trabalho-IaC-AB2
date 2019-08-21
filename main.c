#include <stdio.h>
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/wait.h> 
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[], char *envp[])
{
	int i = 0 ; //contador do loop
	int pid = fork(); //criando o processo filho e guardando o identificador
	char convert[200], comand[200]; //convert -> variavel pra armazenar o pid convertido pra string
									//comand -> o comando final do linux para monitorar
	if(pid < 0)
	{
		perror("Erro: ");
		exit(-1);
	}
	else if(pid == 0) //filho
	{
		if(strcmp(argv[1], "cpu") == 0)
		{
			for(;;)
			{

			}	
		}
		else if(strcmp(argv[1], "cpu-mem") == 0)
		{
			for(;;)
			{
				malloc(sizeof(char) / 9);	
			}
		}
	}
	else //pai
	{
		sprintf(convert, "%d", pid);
		if(strcmp(argv[1], "cpu") == 0)
		{
			printf("  PID / CPU(%%)\n");
			strcpy(comand, "ps -e -o pid,pcpu | grep ");//coloca uma parte do comando linux na string comand
			strcat(comand, convert);//concatena a string comand com o pid ja transformado em string
		}
		else if(strcmp(argv[1], "cpu-mem") == 0)
		{
			printf("  PID / CPU%%\n");
			strcpy(comand, "ps -e -o pid,pcpu | grep ");////coloca uma parte do comando linux na string comand
			strcat(comand, convert);
			strcat(comand, ";pmap ");//concatena a string comand com o ; que indica o final do comando da cpu e com o pmap para o uso da memória
			strcat(comand, convert);//concatena a string comand com o pid ja transformado em string
			strcat(comand, " | grep -i total");
		}

		while(i < 10		) //10 segundos
		{
			system(comand);
			sleep(1); //espera 1 segundo
			i++;
		}

		strcpy(comand, "kill "); //guardando a string kill na string comand, para matar o pid do filho
		strcat(comand, convert); //concatenando a string comand("kill ") com o pid do filho
		system(comand); //matando o filho

	}

	perror ("") ; /* execve não funcionou */

	printf ("Tchau !\n") ;
	exit(0) ; /* encerra o processo com sucesso (código 0) */
}
