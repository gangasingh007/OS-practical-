// first come first served if the arrival time is given

#include <iostream>
using namespace std;

void findWaitingTime(int processes[], int n, int bt[], int wt[], int at[]) {
    wt[0] = 0;

    for (int i = 1; i < n; i++) {
        int finish_time = at[i - 1] + bt[i - 1] + wt[i - 1];
        wt[i] = finish_time - at[i];
        
        
        if (wt[i] < 0)
            wt[i] = 0;
    }
}

void findTurnAroundTime(int processes[], int n, int wt[], int bt[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
    }
}

void findAvgTime(int processes[], int n, int bt[], int at[]) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    findWaitingTime(processes, n, bt, wt, at);
    findTurnAroundTime(processes, n, wt, bt, tat);

    cout << "Processes  Arrival time  Burst time  Waiting time  Turn around time\n";

    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        cout << "   " << processes[i] << "\t\t" << at[i] << "\t    " << bt[i]
             << "\t    " << wt[i] << "\t\t  " << tat[i] << endl;
    }

    cout << "\nAverage waiting time = " << (float)total_wt / n;
    cout << "\nAverage turn around time = " << (float)total_tat / n;
}

int main() {
    int processes[] = {1, 2, 3};
    int n = sizeof(processes) / sizeof(processes[0]);

    int burst_time[] = {5, 3, 8};
    int arrival_time[] = {0, 1, 2};

    findAvgTime(processes, n, burst_time, arrival_time);

    return 0;
}
