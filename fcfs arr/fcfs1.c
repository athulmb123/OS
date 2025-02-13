#include <stdio.h>

void findWaitingTime(int processes[], int n, int bt[], int wt[]) {
    wt[0] = 0;  // First process does not wait

    // Calculate waiting time for each process
    for (int i = 1; i < n; i++) {
        wt[i] = bt[i - 1] + wt[i - 1];  // Waiting time is sum of burst times of previous processes
    }
}

void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    // Calculate turnaround time for each process
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];  // Turnaround time = Burst Time + Waiting Time
    }
}

void findAvgTime(int processes[], int n, int bt[]) {
    int wt[n], tat[n];

    // Find Waiting Times
    findWaitingTime(processes, n, bt, wt);

    // Find Turnaround Times
    findTurnAroundTime(processes, n, bt, wt, tat);

    int total_wt = 0, total_tat = 0;

    // Print process details
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i], bt[i], wt[i], tat[i]);
    }

    // Print average waiting time and average turnaround time
    printf("\nAverage Waiting Time: %.2f", (float)total_wt / n);
    printf("\nAverage Turnaround Time: %.2f\n", (float)total_tat / n);
}

void ganttChart(int processes[], int n, int bt[]) {
    printf("\nGantt Chart:\n");
    printf("--------------------------------------------------\n");

    int current_time = 0;
    for (int i = 0; i < n; i++) {
        printf("| P%d ", processes[i]);
        current_time += bt[i];
    }
    printf("|\n");
    
    current_time = 0;
    printf("0");
    for (int i = 0; i < n; i++) {
        current_time += bt[i];
        printf("    %d", current_time);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int processes[n], burst_time[n];

    // Assign process IDs
    for (int i = 0; i < n; i++) {
        processes[i] = i + 1;  // Process IDs P1, P2, P3, ...
    }

    // Input burst times for each process
    printf("Enter burst times for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Burst time for P%d: ", processes[i]);
        scanf("%d", &burst_time[i]);
    }

    // Calculate average times and Gantt chart
    findAvgTime(processes, n, burst_time);
    ganttChart(processes, n, burst_time);

    return 0;
}

