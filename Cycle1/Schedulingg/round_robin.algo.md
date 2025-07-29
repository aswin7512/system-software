Here is the **algorithm** for your **Round Robin Process Scheduling** program, written in your preferred structured format:

---

### **Algorithm: Round Robin Process Scheduling**

1. **Input** the number of processes `n`.

2. **For** each process `i` from `0` to `n-1`, do:

   * **Input** arrival time `at[i]` and burst time `bt[i]`
   * **Initialize**:

     * `rbt[i] = bt[i]` (remaining burst time)
     * `pid[i] = i`
     * `ct[i] = -1` (completion time)

3. **Input** the time quantum `tq`.

4. **Initialize**:

   * `cur_t = 0` (current time)
   * `comp = 0` (number of completed processes)
   * `wq[]` (ready queue)
   * `wqp = 0` (write pointer for queue)
   * `wqt = 0` (read pointer for queue)
   * `wqn = 0` (number of processes in queue)

5. **Add** all processes that have `at[i] <= cur_t` into the ready queue `wq`.

6. **While** `comp < n`, do:

   1. **Set** `i = wq[wqt]` (index of the process at front of queue)
   2. **If** `rbt[i] > tq`, then:

      * Execute for `tm = tq` time units
      * Subtract `tq` from `rbt[i]`
      * Add newly arrived processes to queue:
        **For** each process `j`:
        **If** `at[j] > cur_t` and `at[j] <= cur_t + tm` and `ct[j] == -1`, then add `j` to `wq`
      * Add process `i` back to end of queue
   3. **Else**:

      * Execute for `tm = rbt[i]` time units
      * Set `rbt[i] = 0`
      * Set `ct[i] = cur_t + tm`
      * Increment `comp`
      * Add newly arrived processes during execution to queue
   4. **Update** `cur_t = cur_t + tm`
   5. **Move** queue read pointer `wqt = (wqt + 1) % n`

7. **For** each process `i`, calculate:

   * `tat[i] = ct[i] - at[i]`
   * `wt[i] = tat[i] - bt[i]`

8. **Display**:

   * Process ID, arrival time, burst time, waiting time, and turnaround time
   * Calculate and print:

     * **Average Waiting Time** = total of all `wt[i]` / `n`
     * **Average Turnaround Time** = total of all `tat[i]` / `n`

9. **End**

---

That wraps up the Round Robin algorithm! Send over the next one if you’ve got it.
