#include <stdio.h>

int main() {
    int i, n, time = 0, remain, tq;
    int at[10], bt[10], rt[10], wt[10], tat[10], ct[10];
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n); 
    remain = n;   

    for (i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time for Process %d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    int completed = 0;
    int queue_empty = 0;

    while (completed < n) {
        queue_empty = 1;
        for (i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] > 0) {
                queue_empty = 0;
                if (rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    time += rt[i];
                    ct[i] = time; 
                    wt[i] = time - at[i] - bt[i];
                    tat[i] = time - at[i];
                    rt[i] = 0;
                    completed++;
                }
            }
        }
        if (queue_empty)
            time++; 
    }


    printf("\nProcess\tAT\tBT\tCT\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        avg_wt += wt[i];
        avg_tat += tat[i];
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat / n);

    return 0;
}
