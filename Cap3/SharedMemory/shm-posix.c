#include <stdio.h>
#include <sys/shm.h>
#include <sys/stat.h>

int main()
{
	int segment_id;

	char* shared_memory;

	const int segment_size = 4096;

	segment_id = shmget(IPC_PRIVATE, segment_size, S_IRUSR | S_IWUSR);

	shared_memory = (char *) shmat(segment_id, NULL, 0);
	printf("shared memory segment %d attached at address %p\n", segment_id, shared_memory);

	sprintf(shared_memory, "Hi there!");

	printf("*%s*\n", shared_memory);

	if ( shmdt(shared_memory) == -1) {
		fprintf(stderr, "Unable to detach\n");
	}

	shmctl(segment_id, IPC_RMID, NULL); 

	return 0;
}
