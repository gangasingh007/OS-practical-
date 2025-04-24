#include <iostream>
#include <algorithm>
using namespace std;

struct Process {
    int pid;        
    int bt;         
    int priority; 
};


bool comparison(Process a, Process b) {
    return (a.priority > b.priority);
}


void findWaitingTime(Process proc[], int n, int wt[]) {
    wt[0] = 0;
    for (int i = 1; i < n; i++) {
        wt[i] = proc[i - 1].bt + wt[i - 1];
    }
}


void findTurnAroundTime(Process proc[], int n, int wt[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = proc[i].bt + wt[i];
    }
}


void findAverageTime(Process proc[], int n) {
    int wt[n], tat[n];
    float total_wt = 0, total_tat = 0;

    // Sort by priority
    sort(proc, proc + n, comparison);

    findWaitingTime(proc, n, wt);
    findTurnAroundTime(proc, n, wt, tat);

    cout << "\nPID\tBurst\tPriority\tWT\tTAT\n";
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        cout << proc[i].pid << "\t" << proc[i].bt << "\t" << proc[i].priority
             << "\t\t" << wt[i] << "\t" << tat[i] << endl;
    }

    cout << "\nAverage Waiting Time = " << total_wt / n;
    cout << "\nAverage Turnaround Time = " << total_tat / n << endl;
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    Process proc[n];
    for (int i = 0; i < n; i++) {
        proc[i].pid = i + 1;
        cout << "Enter Burst Time and Priority for P" << proc[i].pid << ": ";
        cin >> proc[i].bt >> proc[i].priority;
    }

    findAverageTime(proc, n);
    return 0;
}
