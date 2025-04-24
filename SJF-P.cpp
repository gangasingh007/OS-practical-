#include <iostream>
#include <climits>
using namespace std;

void findWaitingTime(int n, int bt[], int at[], int wt[]) {
    int rt[n];
    for (int i = 0; i < n; i++)
        rt[i] = bt[i];

    int complete = 0, t = 0, minm = INT_MAX;
    int shortest = 0;
    bool check = false;

    while (complete != n) {
        for (int j = 0; j < n; j++) {
            if ((at[j] <= t) && (rt[j] < minm) && rt[j] > 0) {
                minm = rt[j];
                shortest = j;
                check = true;
            }
        }

        if (!check) {
            t++;
            continue;
        }

        rt[shortest]--;
        minm = rt[shortest];
        if (minm == 0)
            minm = INT_MAX;

        if (rt[shortest] == 0) {
            complete++;
            check = false;

            int finish_time = t + 1;
            wt[shortest] = finish_time - bt[shortest] - at[shortest];

            if (wt[shortest] < 0)
                wt[shortest] = 0;
        }

        t++;
    }
}

void findTurnAroundTime(int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

void findAverageTime(int processes[], int n, int bt[], int at[]) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    findWaitingTime(n, bt, at, wt);
    findTurnAroundTime(n, bt, wt, tat);

    cout << "\nProcesses\tAT\tBT\tWT\tTAT\n";
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        cout << "P" << processes[i] << "\t\t" << at[i] << "\t" << bt[i]
             << "\t" << wt[i] << "\t" << tat[i] << endl;
    }

    cout << "\nAverage Waiting Time = " << (float)total_wt / n;
    cout << "\nAverage Turnaround Time = " << (float)total_tat / n << endl;
}

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int processes[n], bt[n], at[n];
    for (int i = 0; i < n; i++) {
        processes[i] = i + 1;
        cout << "Enter arrival time and burst time for P" << processes[i] << ": ";
        cin >> at[i] >> bt[i];
    }

    findAverageTime(processes, n, bt, at);
    return 0;
}
