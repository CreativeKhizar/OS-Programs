#include <stdio.h>
 int main(int argc, char *argv[], char * envp[])
 {
        int i;

        printf("argc value is %d\n",argc);

        printf("Argument values are\n");

        for(i=0;i<argc;i++)
        {
                printf("%s\n",argv[i]);
        }
        for (i = 0; envp[i] != NULL; i++)
        {
                printf("\n%s", envp[i]);
        }
        return 0;
}
