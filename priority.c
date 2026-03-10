#include <stdio.h>

struct process{
    char pid[10];
    int at, bt, pr;
    int ct, wt, tat;
    int done;
};

int main()
{
    int n;
    scanf("%d",&n);

    struct process p[20];

    for(int i=0;i<n;i++)
    {
        scanf("%s %d %d %d",p[i].pid,&p[i].at,&p[i].bt,&p[i].pr);
        p[i].done=0;
    }

    int completed = 0;
int time = 0;
float avg_wt = 0, avg_tat = 0;

while(completed < n)
{
    int idx = -1;
    int max_pr = -1;

    for(int i = 0; i < n; i++)
    {
        if(p[i].at <= time && p[i].done == 0)
        {
            if(p[i].pr > max_pr)
            {
                max_pr = p[i].pr;
                idx = i;
            }
        }
    }

    if(idx == -1)
    {
        time++;
    }
    else
    {
        time += p[idx].bt;

        p[idx].ct = time;
        p[idx].tat = p[idx].ct - p[idx].at;
        p[idx].wt = p[idx].tat - p[idx].bt;

        avg_wt += p[idx].wt;
        avg_tat += p[idx].tat;

        p[idx].done = 1;
        completed++;
    }
}

    printf("Waiting Time:\n");
    for(int i=0;i<n;i++)
        printf("%s %d\n",p[i].pid,p[i].wt);

    printf("Turnaround Time:\n");
    for(int i=0;i<n;i++)
        printf("%s %d\n",p[i].pid,p[i].tat);

    printf("Average Waiting Time: %.2f\n",avg_wt/n);
    printf("Average Turnaround Time: %.2f\n",avg_tat/n);

    return 0;
}
