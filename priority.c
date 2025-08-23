#include <stdio.h>

int main() {
    int n, i, time = 0, smallest, count = 0;
    int at[10], bt[10], prio[10], ct[10], tat[10], wt[10], bt_left[10], completed[10];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Process %d - Arrival Time, Burst Time, Priority: ", i + 1);
        scanf("%d %d %d", &at[i], &bt[i], &prio[i]);
        bt_left[i] = bt[i];
        completed[i] = 0;
    }

    while (count < n) {
        int idx = -1;
        int min_prio = 9999;

        for (i = 0; i < n; i++) {
            if (at[i] <= time && completed[i] == 0 && bt_left[i] > 0) {
                if (prio[i] < min_prio) {
                    min_prio = prio[i];
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            bt_left[idx]--;
            time++;

            if (bt_left[idx] == 0) {
                completed[idx] = 1;
                ct[idx] = time;
                tat[idx] = ct[idx] - at[idx];
                wt[idx] = tat[idx] - bt[idx];
                count++;
            }
        } else {
            time++; // CPU idle
        }
    }

    // Display output
    printf("\nPID\tAT\tBT\tPRIO\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i], prio[i], ct[i], tat[i], wt[i]);
    }

    return 0;
}
