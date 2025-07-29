
### **Algorithm: FCFS (First-Come, First-Served) Process Scheduling**

1. **Input** the number of processes `n`.

2. **For** each process `i` from `0` to `n-1`, do:

   * **Input** the burst time `bt[i]`.
   * **Assign** process ID `pid[i] = i`.

3. **Initialize** `cur_t = 0` (current time).

4. **For** each process `i` from `0` to `n-1`, do:

   1. Set `wt[i] = cur_t` (waiting time is current time before execution).
   2. Update `cur_t = cur_t + bt[i]` (increment current time by burst time).
   3. Set `tat[i] = cur_t` (turnaround time is time at which process completes).

5. **Display** the results:

   * Print process ID, burst time, waiting time, and turnaround time for each process.
   * Calculate and print:

     * **Average Waiting Time** = total of all `wt[i]` / `n`
     * **Average Turnaround Time** = total of all `tat[i]` / `n`

6. **End**

