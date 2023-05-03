#include<stdio.h>
void fcfs(int b[],int n)
{
        int i;
        int wt=0;
        int tat=0;
        int swt=0;
        int stat=0;
        int a[10];
        printf("Process BurstTime TurnAroundTime WaitingTime\n");
        for(i=0;i<n;i++)
        {
                if(i>0)
                {
                        wt=wt+b[i-1];
                }
                printf("P%d      %d           %d            %d\n",(i+1),b[i],(wt+b[i]),wt);
                tat=tat+b[i];
                swt+=wt;
                stat+=tat;
                a[i]=wt;
        }
        a[i]=tat;
        float awt=(float)swt/n;
        float atat=(float)stat/n;

        printf("Average Waiting Time is %f\n",awt);
        printf("Average Turn Around Time is %f\n",atat);
        printf("Ghant Chart\n");
        printf("________________________\n");
        printf("|");
        for(i=0;i<n;i++)
        {
                printf(" P%d |",(i+1));
        }
        printf("\n");
        printf("_______________________\n");
        for(i=0;i<=n;i++)
        {
                printf("%d   ",a[i]);
        }
}
int main()
{
        int i,n;
        int b[20];
        printf("Enter the total number of Processes : ");
        scanf("%d",&n);
        printf("Enter the Burst Time of each Process \n");
        for(i=0;i<n;i++)
        {
                scanf("%d",&b[i]);
        }
        fcfs(b,n);
        return 0;
}
