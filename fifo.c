#include<stdio.h>
#include<stdbool.h>

bool check(int a[],int n,int val)
{
        int i;
        for(i=0;i<n;i++)
        {
                if(val==a[i])
                {
                        return true;
                }
        }
        return false;
}
void set(int a[],int n,int val,int s)
{
        int index=s%n;
        a[index]=val;
}
void set999(int a[],int n)
{
        int i;
        for(i=0;i<n;i++)
                a[i]=999;
}
void main()
{
        int i,n,s;
        int a[30];
        int pgs;
        int pgh=0;
        int pgf=0;
        int pg[10];
        s=0;
        printf("Enter the total number of pages\n");
        scanf("%d",&n);

        printf("Enter the pages\n");
        for(i=0;i<n;i++)
        {
                scanf("%d",&a[i]);
        }
         printf("Enter the page size : ");
        scanf("%d",&pgs);
        set999(pg,pgs);
        for(i=0;i<n;i++)
        {
                if(check(pg,pgs,a[i]))
                {
                        pgh++;
                }
                else
                {
                        set(pg,pgs,a[i],s);
                        pgf++;
                        s++;
                }
        }
        printf("\nThe number of Page Faults are : %d",pgf);
        printf("\nThe number of Page Hits are : %d",pgh);
}
                           
