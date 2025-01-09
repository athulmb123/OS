#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        // Child Process
        printf("Hello from Child! (PID: %d)\n", getpid());
    } else {
        // Parent Process
        printf("Hello from Parent! (PID: %d, Child PID: %d)\n", getpid(), pid);
    }

    return 0;
}

