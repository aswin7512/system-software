
### **Algorithm: First Fit Memory Allocation**

1. **Start**

2. **Initialize** an array `alloc[]` of size `np` with all values as `-1` to indicate unallocated.

3. **For** each process `i` from `0` to `np-1`, do:

   1. **For** each block `j` from `0` to `nb-1`, do:

      * **If** `proc[i] <= block[j]`, then:

        1. Allocate process `i` to block `j`
        2. Reduce `block[j]` by `proc[i]`
        3. Set `alloc[i] = j + 1` (to represent block number)
        4. **Break** the inner loop (move to next process)

4. **Print** the allocation result:

   * **For** each process `i` from `0` to `np-1`, do:

     * **If** `alloc[i] == -1`, print process `i+1`, size `proc[i]`, and `"NA"` (not allocated)
     * **Else**, print process `i+1`, size `proc[i]`, and `alloc[i]` (allocated block number)

5. **End**

