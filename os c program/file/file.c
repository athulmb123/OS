#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main() {
    char buf[128];
    int fd = open("file.txt", O_RDWR | O_CREAT, 0644);
    if (fd < 0) { 
        perror("open"); 
        return 1; 
    }
    printf("Enter text: ");
    fgets(buf, sizeof(buf), stdin); 
    write(fd, buf, strlen(buf)); 
    printf("Text written into file successfully!\n");
    close(fd);
    fd = open("file.txt", O_RDWR); 
    if (fd < 0) {
        perror("open");
        return 1;
    }
    printf("File contents:\n");
    read(fd, buf, sizeof(buf));
    printf("%s\n", buf); 
    close(fd);
    return 0;
}
