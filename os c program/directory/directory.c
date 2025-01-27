#include<stdio.h>
#include<dirent.h>
int main()
{
	DIR *dir;
	struct dirent *ptr1;
	char dir_name[100];
	printf("\n Enter the Directory name : ");
	scanf("%s", dir_name);
	dir = opendir(dir_name);
	if (dir == NULL)
	{
		perror("opendir");
		return 1;
	}
	printf("Inode  \t\t  Name  \n");
	printf("___________________________________ \n");
	while((ptr1 = readdir(dir)) != NULL)
		printf("%ld \t\t %s\n", ptr1->d_ino, ptr1->d_name);
	closedir(dir);
	return 0;
}
