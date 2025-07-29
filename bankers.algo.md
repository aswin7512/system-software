
### **Algorithm: Banker's Algorithm to Find Safe Sequence**

1. **Input** the number of processes `np` and number of resources `nr`.

2. **For** each process `i` from `0` to `np-1`, do:

   1. **Input** the allocated resources array `alloc[i]` of size `nr`.
   2. **Input** the maximum required resources array `max[i]` of size `nr`.
   3. **Calculate** `need[i][j] = max[i][j] - alloc[i][j]` for all `j = 0` to `nr-1`.
   4. **Initialize** execution flag `exec[i] = 0`.

3. **Input** the available resources array `avl` of size `nr`.

4. **Initialize**:

   * `comp = 0` (number of completed processes)
   * `dl = 0` (deadlock flag)
   * `safe[]` as an empty array to store the safe sequence
   * `sp = 0` (safe sequence pointer)

5. **While** `comp < np` and `dl == 0`, do:

   1. Set `dl = 1`
   2. **For** each process `i` from `0` to `np-1`, do:

      1. **If** `exec[i] == 0` and `need[i][j] <= avl[j]` for all `j = 0` to `nr-1`, then:

         * **Add** process `i+1` to `safe[sp++]`
         * **Increment** `comp` by 1
         * **Set** `exec[i] = 1`
         * **Update** available resources:
           `avl[j] = avl[j] + alloc[i][j]` for all `j = 0` to `nr-1`
         * **Set** `dl = 0`

6. **Print** the need matrix for all processes.

7. **If** `dl == 1`, then:

   * **Print** "System is not in Safe State..."

8. **Else**, do:

   * **Print** "Safe Sequence: " followed by processes in `safe[]`, ending with "Halt".

9. **End**
