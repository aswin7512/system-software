
### **Algorithm: Banker's Algorithm to Find Safe Sequence**

1. **Start**

2. **Initialize**:

   * `comp = 0` (number of completed processes)
   * `dl = 0` (deadlock flag)
   * `safe[]` as an empty array to store the safe sequence
   * `sp = 0` (safe sequence pointer)

3. **While** `comp < np` and `dl == 0`, do:

   1. Set `dl = 1`
   2. **For** each process `i` from `0` to `np-1`, do:

      1. **If** `exec[i] == 0` and `need[i][j] <= avl[j]` for all `j = 0` to `nr-1`, then:

         * **Add** process `i+1` to `safe[sp++]`
         * **Increment** `comp` by 1
         * **Set** `exec[i] = 1`
         * **Update** available resources:
           `avl[j] = avl[j] + alloc[i][j]` for all `j = 0` to `nr-1`
         * **Set** `dl = 0`

4. **Print** the need matrix for all processes.

5. **If** `dl == 1`, then:

   * **Print** "System is not in Safe State..."

6. **Else**, do:

   * **Print** "Safe Sequence: " followed by processes in `safe[]`, ending with "Halt".

7. **End**
