#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    int id;
    char *sm;
    
    if ((id = shmget((key_t)1222, 1024, 0666)) == -1) {
        perror("Error: shmget failed");
        return 1;
    }
   
    printf("Key of Shared Memory: %d\n", id);
    if ((sm = shmat(id, NULL, 0)) == (void *)-1) {
        perror("Error: shmat failed");
        return 2;
     }
        printf("Shared memory attached at address %p\n", sm);
    printf("Data read from shared memory: %s\n", sm);
    if (strlen(sm) < 3 || sm[1] != ' ') {
        printf("Invalid data format in shared memory.\n");
        return 3;
    }
    int a = sm[0] - '0';
    int b = sm[2] - '0';
    printf("The Sum is %d\n", a + b);
    return 0;
}
