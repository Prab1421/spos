#include<bits/stdc++.h>
using namespace std;

struct Process{
  int id;
  int at;
  int bt;
  int ct;
  int wt;
  int tat;
};

void fcfs(vector<Process>& processes)
{
    int n=processes.size();
    float avgWT,avgTAT;
    int currentTime=0;
    
    sort(processes.begin(),processes.end(),[](Process a , Process b)
    {
        return a.at<b.at;
    });
    
    for(int i=0 ; i<n ; ++i)
    {
        if(currentTime<processes[i].at)
        {
            currentTime=processes[i].at;
        }
        processes[i].ct=currentTime+processes[i].bt;
        processes[i].wt=currentTime-processes[i].at;
        processes[i].tat=processes[i].wt+processes[i].bt;
        
        avgWT+=processes[i].wt;
        avgTAT+=processes[i].tat;
        
        currentTime+=processes[i].bt;
    }
    
    for(auto &process:processes)
    {
        cout<<process.id<<" "<<process.at<<" "<<process.bt<<" "<<process.ct<<" "<<process.wt<<" "<<process.tat<<endl;
    }
    cout<<"avgWT:"<<avgWT/n<<"avgTAT:"<<avgTAT/n<<endl;
}

int main()
{
    int n;
    cout<<"Enter number of processes:";
    cin>>n;
    vector<Process> processes(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter Process ID, Arrival Time and Burst Time for Process " << i + 1 << ": ";
        cin >> processes[i].id >> processes[i].at >> processes[i].bt;
    }
    fcfs(processes);
    return 0;
}