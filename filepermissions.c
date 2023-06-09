#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>

int main(int c,char **args)
{
    char path[100];
    struct stat fileStat;
    int i;

    if(c==1)
    {
       printf("Enter the file names to check\n");
       return 0;
    }

    // Get the file/directory permissions

    for(i=1;i<=c;i++)
    {
    if(args[i]==NULL)
    {
       continue;
    }
    if (stat(args[i], &fileStat) < 0)
         {
        printf("Error: Failed to get file/directory status of %s .\n",args[i]);
        continue;
    }

    // Check the file type
    if (S_ISREG(fileStat.st_mode)) {
        printf("%s is a regular file.\n", args[i]);
    } else if (S_ISDIR(fileStat.st_mode)) {
        printf("%s is a directory.\n", args[i]);
    } else {
        printf("%s is neither a file nor a directory.\n", args[i]);
    }

    // Check the file/directory permissions
    printf("Permissions:\n");
    printf("Read permission: %s\n", (fileStat.st_mode & S_IRUSR) ? "Yes" : "No");
    printf("Write permission: %s\n", (fileStat.st_mode & S_IWUSR) ? "Yes" : "No");
    printf("Execute permission: %s\n", (fileStat.st_mode & S_IXUSR) ? "Yes" : "No");
    }
    return 0;
}
