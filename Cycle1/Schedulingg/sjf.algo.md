Here’s the **algorithm** for your **SJF (Shortest‑Job‑First, non‑pre‑emptive) Process Scheduling** program, in the same structured format as all the previous ones:

---

### **Algorithm: SJF (Shortest‑Job‑First) Process Scheduling**

1. **Input** the number of processes `n`.

2. **For** each process `i` from `0` to `n ‑ 1`, do
     a. **Input** the burst time `bt[i]`.
     b. **Assign** process ID `pid[i] = i`.

3. **Sort** the processes in **ascending order of burst time**:
     For `i = 0` to `n ‑ 2`
      For `j = 0` to `n ‑ i ‑ 2`
       If `bt[j] > bt[j+1]`, swap the entire process records `pr[j]` and `pr[j+1]`.

4. **Initialize** `cur_t = 0` (current time).

5. **For** each process `i` in the sorted list, do
     a. Set `wt[i] = cur_t` (waiting time before it starts).
     b. Update `cur_t = cur_t + bt[i]` (advance current time by this process’s burst).
     c. Set `tat[i] = cur_t` (turn‑around time when it finishes).

6. **Display** results for all processes: PID, burst time, waiting time, and turnaround time.

7. **Compute** and **print**:
     • **Average Waiting Time** = Σ `wt[i]` / `n`
     • **Average Turn‑Around Time** = Σ `tat[i]` / `n`

8. **End**

---

All set! Let me know if there’s another program you’d like an algorithm for.
