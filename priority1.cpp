#include<bits/stdc++.h>
using namespace std;
struct process {
    int id, at, bt, wt, ct, tat, priority;
    bool completed;
};
void priority(vector<process>& processes) {
    int n=processes.size(), currT=0, completed=0; 
    float totalT=0, totalW=0;
    for(int i=0; i<n; i++) {
        processes[i].completed = false;
        processes[i].id = i+1;
    }
    while(completed != n) {
        int idx = -1, highestpriority = INT_MAX;
        for(int i=0; i<n; i++) {
            if(!processes[i].completed && processes[i].at <= currT && processes[i].priority < highestpriority) {
                highestpriority = processes[i].priority;
                idx = i;
            }
        }
        if(idx == -1) {
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
    cout << "ID AT BT PR CT WT TAT" << endl;
    for (auto& p : processes) {
        cout << p.id << "  " << p.at << "  " << p.bt << "  " << p.priority << "  " << p.ct << "  " << p.wt << "  " << p.tat << endl;
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
        cout << "Arrival Time, Burst Time, and Priority for Process " << i + 1 << ": ";
        cin >> processes[i].at >> processes[i].bt >> processes[i].priority;
    }
    priority(processes);
    return 0;
}
