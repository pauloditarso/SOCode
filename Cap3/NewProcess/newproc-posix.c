/**
 * Esse programa gera um processo separado usando as chamadas de sistema fork()/exec().
 *
 * Figura 3.10
 *
 * @author Gagne, Galvin, Silberschatz
 * Fundamentos de Sistemas Operacionais - Oitava Edição
 * Copyright John Wiley & Sons - 2011
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
pid_t pid;

	/* gera um processo filho */
	pid = fork();

	if (pid < 0) { /* ocorreu um erro */
		fprintf(stderr, "Fork Failed\n");
		exit(-1);
	}
	else if (pid == 0) { /* processo filho */
		printf("I am the child %d\n",pid);
		execlp("/bin/ls","ls",NULL);
	}
	else { /* processo pai */
		/* o pai esperará o filho terminar */
		printf("I am the parent %d\n",pid);
		wait(NULL);
		
		printf("Child Complete\n");
		exit(0);
	}
}