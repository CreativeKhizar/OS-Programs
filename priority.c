#include<stdio.h>
void fcfs(int b[],int p[],int n)
{
        int i;
        int wt=0;
        int tat=0;
        int swt=0;
        int stat=0;
        printf("Gantt Chart\n");
        for(i=0;i<n;i++)
        {
                if(i>0)
                {
                        wt=wt+b[i-1];
                }
                printf("P%d  %d-%d\n",p[i],wt,(wt+b[i]));
                tat=tat+b[i];
                swt+=wt;
                stat+=tat;
        }

        float awt=(float)swt/n;
        float atat=(float)stat/n;

        printf("Average Waiting Time is %f\n",awt);
        printf("Average Turn Around Time is %f\n",atat);

}
void sort(int b[],int p[],int pr[],int n)
{
        int i,j;
        int temp;
        for(i=n-1;i>0;i--)
        {
                for(j=0;j<i;j++)
                {
                        if(pr[j]>pr[j+1])
                        {
                                temp=pr[j];
                                pr[j]=pr[j+1];
                                pr[j+1]=temp;

                                temp=b[j];
                                b[j]=b[j+1];
                                b[j+1]=temp;

                                temp=p[j];
                                p[j]=p[j+1];
                                p[j+1]=temp;
                        }
                }
        }
}
int main()
{
        int i,n;
        int b[20];
        int p[20];
        int pr[20];
        printf("Enter the total number of Processes : ");
        scanf("%d",&n);
        printf("Enter the Priority of Process : ");
        for(i=0;i<n;i++)
        {
                scanf("%d",&pr[i]);
        }
        printf("Enter the Burst Time of each Process \n");
        for(i=0;i<n;i++)
        {
                p[i]=i+1;
                scanf("%d",&b[i]);
        }
        sort(b,p,pr,n);
        fcfs(b,p,n);
        return 0;
}
