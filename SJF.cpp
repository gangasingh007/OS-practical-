// SJF - non Premptive

#include <iostream>
using namespace std;

int main() {
    int A[100][4];  
    int i, j, m, total = 0, index, temp;
    float avg_tat = 0, avg_wt = 0;

    cout << "Enter number of processes: ";
    cin >> m;

    cout << "Enter burst time:\n";
    for (i = 0; i < m; i++) {
        cout << "P[" << i + 1 << "]: ";
        cin >> A[i][1]; 
        A[i][0] = i + 1; 
    }


    for (i = 0; i < m; i++) {
        index = i;
        for (j = i + 1; j < m; j++) {
            if (A[j][1] < A[index][1]) {
                index = j;
            }
        }
    
        temp = A[i][1];
        A[i][1] = A[index][1];
        A[index][1] = temp;

        temp = A[i][0];
        A[i][0] = A[index][0];
        A[index][0] = temp;
    }

    A[0][2] = 0; 


    for (i = 1; i < m; i++) {
        A[i][2] = 0;
        for (j = 0; j < i; j++) {
            A[i][2] += A[j][1];
        }
        total += A[i][2];
    }

    avg_wt = (float)total / m;
    total = 0;

    
    for (i = 0; i < m; i++) {
        A[i][3] = A[i][1] + A[i][2]; 
        total += A[i][3];
    }

    avg_tat = (float)total / m;

 
    cout << "\nPID\tBT\tWT\tTAT\n";
    for (i = 0; i < m; i++) {
        cout << "P[" << A[i][0] << "]\t" << A[i][1] << "\t" << A[i][2] << "\t" << A[i][3] << "\n";
    }

    cout << "\nAverage Waiting Time: " << avg_wt;
    cout << "\nAverage Turnaround Time: " << avg_tat << endl;

    return 0;
}
