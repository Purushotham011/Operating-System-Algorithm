// Priority Scheduling
//  12.08.2024

#include <stdio.h>
struct Process
{
    int pid;
    int arrival;
    int burst;
    int priority;
    int completion;
    int waiting;
    int turnaround;
};

void swap(struct Process *xp, struct Process *yp)
{
    struct Process temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sort(struct Process proc[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (proc[j].arrival > proc[j + 1].arrival)
            {
                swap(&proc[j], &proc[j + 1]);
            }
        }
    }
}
void calculateCompletionTime(struct Process proc[], int n)
{
    int temp, val;
    proc[0].completion = proc[0].arrival + proc[0].burst;
    proc[0].turnaround = proc[0].completion - proc[0].arrival;
    proc[0].waiting = proc[0].turnaround - proc[0].burst;
    for (int i = 1; i < n; i++)
    {
        temp = proc[i - 1].completion;
        int low = proc[i].burst;
        for (int j = i; j < n; j++)
        {
            if (temp >= proc[j].arrival && low >= proc[j].burst)
            {
                low = proc[j].burst;
                val = j;
            }
        }
        proc[val].completion = temp + proc[val].burst;
        proc[val].turnaround = proc[val].completion - proc[val].arrival;
        proc[val].waiting = proc[val].turnaround - proc[val].burst;
        swap(&proc[val], &proc[i]);
    }
}

void printGanttChart(struct Process proc[], int n)
{
    printf("Gantt Chart\n");
    for (int i = 0; i < n; i++)
    {
        printf("|P%d |\t", proc[i].pid);
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("| %d |\t ", proc[i].completion);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct Process proc[n];
    for (int i = 0; i < n; i++)
    {
        proc[i].pid = i + 1;
        printf("Enter the arrival time of process %d: ", i + 1);
        scanf("%d", &proc[i].arrival);
        printf("Enter the burst time of process %d: ", i + 1);
        scanf("%d", &proc[i].burst);
        printf("Enter the priority of process %d: ", i + 1);
        scanf("%d", &proc[i].priority);
    }
    sort(proc, n);
    calculateCompletionTime(proc, n);
    printGanttChart(proc, n);
    printf("Process\tArrival\tBurst\tPriority\tCompletion\tTurnaround\tWaiting\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].arrival, proc[i].burst, proc[i].priority, proc[i].completion, proc[i].turnaround, proc[i].waiting);
    }
    return 0;
}