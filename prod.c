#include <stdio.h>
#include <stdlib.h>

int mutex = 1, full = 0, empty = 3, x = 0;

int signal(int s) { return ++s; }
int wait(int s) { return --s; }

void producer() {
    empty = wait(empty);
    mutex = wait(mutex);
    printf("\nProducer produces item %d", ++x);
    mutex = signal(mutex);
    full = signal(full);
}

void consumer() {
    full = wait(full);
    mutex = wait(mutex);
    printf("\nConsumer consumes item %d", x--);
    mutex = signal(mutex);
    empty = signal(empty);
}

int main() {
    while (1) {
        int n;
        printf("\n1. Producer\n2. Consumer\n3. Exit\nEnter your Choice: ");
        scanf("%d", &n);

        if (n == 1) {
            if (mutex == 1 && empty)
                producer();
            else if (empty == 0)
                printf("\nBuffer is FULL!\n");
        } 
        else if (n == 2) {
            if (mutex == 1 && full)
                consumer();
            else if (full == 0)
                printf("\nBuffer is EMPTY!\n");
        } 
        else if (n == 3) exit(0);
        else printf("\nInvalid choice! Please try again.\n");
    }
    return 0;
}
