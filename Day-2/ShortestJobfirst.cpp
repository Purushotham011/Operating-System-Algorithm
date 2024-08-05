// Shortest Job First (SJF) Scheduling
//  05.08.2024
#include <stdio.h>

void waitingTime(int n, int bt[], int wt[])
{
    wt[0] = 0;

    for (int i = 1; i < n; i++)
        wt[i] = bt[i - 1] + wt[i - 1];
}

void turnAroundTime(int n, int bt[], int wt[], int tat[])
{
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

void avgTime(int n, int processes[], int bt[])
{
    int wt[n], tat[n];
    waitingTime(n, bt, wt);
    turnAroundTime(n, bt, wt, tat);

    int total_wt = 0, total_tat = 0;

    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++)
    {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i], bt[i], wt[i], tat[i]);
    }

    printf("Average waiting time = %f\n", (float)total_wt / (float)n);
    printf("Average turn around time = %f\n", (float)total_tat / (float)n);
}

void sortBurstTime(int n, int processes[], int bt[])
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (bt[j] > bt[j + 1])
            {
                int temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                int temp_process = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp_process;
            }
        }
    }
}

int main()
{
    // Number of processes
    int processes[] = {1, 2, 3, 4, 5};
    int n = sizeof(processes) / sizeof(processes[0]); // Process IDs
    int bt[] = {6, 2, 8, 3, 4};                       // Burst times of processes

    sortBurstTime(n, processes, bt);
    avgTime(n, processes, bt);

    return 0;
}