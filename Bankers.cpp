#include <iostream>
using namespace std;

const int MAX = 10;

int main() {
    int n, m; // n = number of processes, m = number of resources
    int alloc[MAX][MAX], max[MAX][MAX], avail[MAX];
    int need[MAX][MAX], finish[MAX] = {0};
    int safeSequence[MAX], index = 0;

    cout << "Enter number of processes: ";
    cin >> n;
    cout << "Enter number of resources: ";
    cin >> m;

    cout << "Enter allocation matrix:\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << i << ": ";
        for (int j = 0; j < m; j++) {
            cin >> alloc[i][j];
        }
    }

    cout << "Enter maximum matrix:\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << i << ": ";
        for (int j = 0; j < m; j++) {
            cin >> max[i][j];
        }
    }

    cout << "Enter available resources: ";
    for (int i = 0; i < m; i++) {
        cin >> avail[i];
    }

    // Calculate need matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    // Banker's algorithm
    for (int count = 0; count < n; count++) {
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                bool canAllocate = true;
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) {
                        canAllocate = false;
                        break;
                    }
                }

                if (canAllocate) {
                    for (int j = 0; j < m; j++)
                        avail[j] += alloc[i][j];

                    safeSequence[index++] = i;
                    finish[i] = 1;
                    found = true;
                }
            }
        }

        if (!found) {
            cout << "\nSystem is not in a safe state.\n";
            return 0;
        }
    }

    cout << "\nSystem is in a safe state.\nSafe sequence is: ";
    for (int i = 0; i < n; i++)
        cout << "P" << safeSequence[i] << (i == n - 1 ? "\n" : " -> ");

    return 0;
}
