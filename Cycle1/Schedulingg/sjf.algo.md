### **Algorithm: SJF (Shortest‑Job‑First) Process Scheduling**

1. **Start**

2. **Sort** the processes in **ascending order of burst time**:
     For `i = 0` to `n ‑ 2`
      For `j = 0` to `n ‑ i ‑ 2`
       If `bt[j] > bt[j+1]`, swap the entire process records `pr[j]` and `pr[j+1]`.

3. **Initialize** `cur_t = 0` (current time).

4. **For** each process `i` in the sorted list, do
     a. Set `wt[i] = cur_t` (waiting time before it starts).
     b. Update `cur_t = cur_t + bt[i]` (advance current time by this process’s burst).
     c. Set `tat[i] = cur_t` (turn‑around time when it finishes).

5. **Display** results for all processes: PID, burst time, waiting time, and turnaround time.

6. **Compute** and **print**:
     • **Average Waiting Time** = Σ `wt[i]` / `n`
     • **Average Turn‑Around Time** = Σ `tat[i]` / `n`

7. **End**