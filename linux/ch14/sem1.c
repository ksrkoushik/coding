#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/sem.h>
//sys/sem.h usually relies on two other header files sys/types.h and sys/ipc.h
//which are automaically included by sys/sem.h
#include "semun.h"

static int set_semvalue(void);
static void del_semvalue(void);
static int semaphore_p(void);
static int semaphore_v(void);
static int sem_id;

int main(int argc, char *argv[])
{
	int i;
	int pause_time;
	char op_char = 'O';
	srand((unsigned int)getpid());
	sem_id = semget((key_t)1234, 1, 0666 | IPC_CREAT);
        //semget fn creates a new semaphore or obtains the semaphore key of an existing semaphore
	//1st argument allows unrelated processes to access the same semaphore
	//2nd argument is the number of semaphores required
	//3dr argument is setting flags much like the flags of open function
	//The semget fn returns a positive(non-zero) value on success and on error it returns -1
	if (argc > 1)
	{
		if(!set_semvalue())
		{
			fprintf(stderr, "Failed to initialize semaphore\n");
			exit(EXIT_FAILURE);
		}
		op_char = 'X';
		sleep(2);
	}

	for(i=0;i<10;i++)
	{
		if(!semaphore_p()) exit(EXIT_FAILURE);
		printf("%c", op_char);
		fflush(stdout);
		pause_time = rand() % 3;
		sleep(pause_time);
		printf("%c", op_char);
		fflush(stdout);
		if(!semaphore_v()) exit(EXIT_FAILURE);
		pause_time= rand() % 2;
		sleep(pause_time);
	}
	printf("\n%d -finished\n", getpid());
	if(argc > 1)
	{
		sleep(10);
		del_semvalue();
	}
	exit(EXIT_SUCCESS);
}
static int set_semvalue(void)
{
	union semun sem_union;
	sem_union.val = 1;
	//semctl fn allows direct control of semaphore infon
	//1st arg is sem identifer obtained from semget
	//2nd arg is sem number
	//3rd arg is the command that is used to take the action(here it is SETVAL)
	//4th arg is a union, taken from semun.h header file
	if(semctl(sem_id, 0, SETVAL, sem_union) ==-1) return (0);
	return(1);
}
static void del_semvalue(void)
{
	union semun sem_union;
	if(semctl(sem_id, 0, IPC_RMID, sem_union) == -1)
		fprintf(stderr, "Failed to delete semaphore\n");
}
static int semaphore_p(void)
{
	struct sembuf sem_b;
	sem_b.sem_num = 0;
	sem_b.sem_op = -1;
	sem_b.sem_flg = SEM_UNDO;
	//semop fn is used for changing the value of the semaphore
	//1st arg is the semaphore identifier as returned by semget
	//2nd arg is a pointer to an array of structures with members sem_num, sem_op and sem_flg
	if(semop(sem_id, &sem_b, 1) == -1)
	{
		fprintf(stderr, "semaphore_p failed\n");
		return(0);
	}
	return(1);
}
static int semaphore_v(void)
{
	struct sembuf sem_b;
	sem_b.sem_num = 0;
	sem_b.sem_op = 1;
	sem_b.sem_flg = SEM_UNDO;
	if(semop(sem_id, &sem_b, 1) == -1)
	{
		fprintf(stderr, "semaphore_v failed\n");
		return(0);
	}
	return(1);
}

