#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int id;
    char *sm;
    if ((id = shmget((key_t)1222, 1024, 0666 | IPC_CREAT)) == -1) {
        perror("Error: shmget failed");
        return 1;
    }
    printf("Key of Shared Memory: %d\n", id);
    if ((sm = shmat(id, NULL, 0)) == (void *)-1) {
        perror("Error: shmat failed");
        return 2;
    }
    printf("Process attached at %p\n", sm);
    printf("Enter the data to be written:\n");
    fgets(sm, 100, stdin);
    printf("Written Data is:\n%s", sm);
    return 0;
}

