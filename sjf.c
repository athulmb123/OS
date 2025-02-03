#include <stdio.h>

void findWaitingTime(int processes[], int n, int bt[], int at[], int wt[], int ct[]) {
    wt[0] = 0;
    int completion_time[n];
    completion_time[0] = at[0] + bt[0];
    ct[0] = completion_time[0];

    for (int i = 1; i < n; i++) {
        completion_time[i] = at[i];
        for (int j = 0; j < i; j++) {
            if (completion_time[j] > at[i]) {
                completion_time[i] = completion_time[j];
            }
        }
        ct[i] = completion_time[i] + bt[i];
        wt[i] = ct[i] - at[i] - bt[i];  // Waiting time = Completion time - Arrival time - Burst time
    }
}

void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];  // Turnaround time = Burst Time + Waiting Time
    }
}

void findAvgTime(int processes[], int n, int bt[], int at[]) {
    int wt[n], tat[n], ct[n];
    findWaitingTime(processes, n, bt, at, wt, ct);
    findTurnAroundTime(processes, n, bt, wt, tat);

    int total_wt = 0, total_tat = 0;
    printf("\nProcess\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\tCompletion Time\n");

    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i], bt[i], at[i], wt[i], tat[i], ct[i]);
    }

    printf("\nAverage Waiting Time: %.2f", (float)total_wt / n);
    printf("\nAverage Turnaround Time: %.2f\n", (float)total_tat / n);
}

void ganttChart(int processes[], int n, int bt[], int at[], int ct[]) {
    printf("\nGantt Chart:\n");
    printf("--------------------------------------------------\n");

    int current_time = 0;
    for (int i = 0; i < n; i++) {
        if (current_time < at[i]) {
            printf("| IDLE ");
            current_time = at[i];
        }
        printf("| P%d ", processes[i]);
        current_time += bt[i];
    }
    printf("|\n");

    current_time = 0;
    printf("0");
    for (int i = 0; i < n; i++) {
        if (current_time < at[i]) {
        printf("       ");
            current_time = at[i];
        }
        current_time += bt[i];
        printf("    %d", current_time);
    }
    printf("\n");
}

void sortProcessesByArrivalTime(int processes[], int bt[], int at[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (at[i] > at[j]) {
                int temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
}

void sortProcessesByBurstTime(int processes[], int bt[], int at[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (bt[i] > bt[j] && at[i] <= at[j]) {
                int temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;

                temp = at[i];
                at[i] = at[j];
                at[j] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int processes[n], burst_time[n], arrival_time[n];
    
    for (int i = 0; i < n; i++) {
        processes[i] = i + 1;
    }

    printf("Enter arrival times for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Arrival time for P%d: ", processes[i]);
        scanf("%d", &arrival_time[i]);
    }

    printf("Enter burst times for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Burst time for P%d: ", processes[i]);
        scanf("%d", &burst_time[i]);
    }

    sortProcessesByArrivalTime(processes, burst_time, arrival_time, n);
    sortProcessesByBurstTime(processes, burst_time, arrival_time, n);

    findAvgTime(processes, n, burst_time, arrival_time);
    ganttChart(processes, n, burst_time, arrival_time, arrival_time);

    return 0;
}
