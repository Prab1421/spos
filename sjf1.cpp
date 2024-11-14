#include <bits/stdc++.h>
using namespace std;
struct process {
    int id, at, wt, ct, tat, bt;
    bool completed;
};
void sjf(vector<process>&processes) {
    int n= processes.size(), currT = 0, completed=0;
    float totalT=0, totalW=0;
    for(int i=0; i<n; i++) {
        processes[i].completed = false;
        processes[i].id = (i+1);
    }
    while(completed !=n) {
        int idx = -1;
        int minBT = INT_MAX;
        for(int i=0; i<n; i++) {
            if(!processes[i].completed && processes[i].at <= currT && processes[i].bt < minBT) {
                minBT = processes[i].bt;
                idx = i;
            }
        }
        if(idx== -1) {
            currT++;
            continue;
        }
        currT += processes[idx].bt;
        processes[idx].ct = currT;
        processes[idx].tat = processes[idx].ct - processes[idx].at;
        processes[idx].wt = processes[idx].tat - processes[idx].bt;
        totalT += processes[idx].tat;
        totalW += processes[idx].wt;
        processes[idx].completed = true;
        completed++;
    }
    cout << "ID AT BT CT WT TAT" << endl;
    for (auto& p : processes) {
        cout << p.id << "  " << p.at << "  " << p.bt << "  " << p.ct << "  " << p.wt << "  " << p.tat << endl;
    }
    cout << "Average Waiting Time: " << totalW / n << endl;
    cout << "Average Turnaround Time: " << totalT / n << endl;
}
int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;
    vector<process> processes(n);
    for (int i = 0; i < n; i++) {
        cout << "Arrival Time and Burst Time for Process " << i + 1 << ": ";
        cin >> processes[i].at >> processes[i].bt;
    }
    sjf(processes);
    return 0;
}