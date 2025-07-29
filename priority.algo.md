

### **Algorithm: Priority-Based Process Scheduling (Non-Preemptive)**

1. **Input** the number of processes `n`.

2. **For** each process `i` from `0` to `n-1`, do:

   * **Input** the burst time `bt[i]` and priority `pri[i]`.
   * **Assign** process ID `pid[i] = i`.

3. **Sort** the processes in **ascending order of priority** (lower number means higher priority):

   * **For** `i = 0` to `n-1`:

     * **For** `j = 0` to `n-i-2`:

       * **If** `pri[j] > pri[j+1]`, then **swap** the entire process `pr[j]` and `pr[j+1]`.

4. **Initialize** `cur_t = 0` (current time).

5. **For** each process `i` from `0` to `n-1`, do:

   1. Set `wt[i] = cur_t` (waiting time).
   2. Update `cur_t = cur_t + bt[i]` (advance time).
   3. Set `tat[i] = cur_t` (turnaround time).

6. **Display** the results:

   * Print process ID, burst time, priority, waiting time, and turnaround time for each process.
   * Calculate and print:

     * **Average Waiting Time** = total of all `wt[i]` / `n`
     * **Average Turnaround Time** = total of all `tat[i]` / `n`

7. **End**

