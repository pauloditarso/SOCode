/**
 * Programa simples quwe demonstra a memória compartilhada em sistemas POSIX.
 *
 * Figura 3.16
 *
 * @author Gagne, Galvin, Silberschatz
 * Fundamentos de Sistemas Operacionais - Oitava Edição
 * Copyright John Wiley & Sons - 2011.
 */

#include <stdio.h>
#include <sys/shm.h>
#include <sys/stat.h>

int main()
{
	/* identificador do segmento de memória compartilhada */
	int segment_id;
	/* ponteiro do segmento de memória compartilhada */
	char* shared_memory;
	/* tamanho (em bytes) do segmento de memória compartilhada */ 
	const int segment_size = 4096;

	/** aloca um segmento de memória compartilhada */
	segment_id = shmget(IPC_PRIVATE, segment_size, S_IRUSR | S_IWUSR);

	/** anexa o segmento de memória compartilhada*/
	shared_memory = (char *) shmat(segment_id, NULL, 0);
	printf("shared memory segment %d attached at address %p\n", segment_id, shared_memory);

	/** grava uma mensagem no segmento de memória compartilhada   */
	sprintf(shared_memory, "Hi there!");

	/** agora exibe a string a partir da memória compartilhada */
	printf("*%s*\n", shared_memory);

	/** desanexa o segmento de memória compartilhada */ 
	if ( shmdt(shared_memory) == -1) {
		fprintf(stderr, "Unable to detach\n");
	}

	/** remove o segmento de memória compartilhada */
	shmctl(segment_id, IPC_RMID, NULL); 

	return 0;
}