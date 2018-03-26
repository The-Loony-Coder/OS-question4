
// trial version of round robin implementation
//defined functions to be used and main function 

using namespace std;
void findWaitingTime(int processes[], int n,int bt[], int wt[], int quantum)
{	int rem_bt[n];
    for (int i = 0 ; i < n ; i++)
        rem_bt[i] =  bt[i];
 
    int t = 0; 

    for (int i = 0; i < n ; i++)
        tat[i] = bt[i] + wt[i];
}
 
// Function to calculate average time
void findavgTime(int processes[], int n, int bt[],
                                     int quantum)
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
 
    // Function to find waiting time of all processes
    findWaitingTime(processes, n, bt, wt, quantum);
 
    // Function to find turn around time for all processes
    findTurnAroundTime(processes, n, bt, wt, tat);
 
    // Display processes along with all details
    cout << "Processes "<< " Burst time "
         << " Waiting time " << " Turn around time\n";
 
    // Calculate total waiting time and total turn
    // around time
    for (int i=0; i<n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << " " << i+1 << "\t\t" << bt[i] <<"\t "
             << wt[i] <<"\t\t " << tat[i] <<endl;
    }
 
    cout << "Average waiting time = "
         << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "
         << (float)total_tat / (float)n;
}
 
// main code
int main()
{
    // process id's
    int processes[] = { 1, 2, 3};
    int n = sizeof processes / sizeof processes[0];
 
    // Burst time of all processes
    int burst_time[] = {10, 5, 8};
 
    // Time quantum
    int quantum = 2;
    findavgTime(processes, n, burst_time, quantum);
    return 0;
}

