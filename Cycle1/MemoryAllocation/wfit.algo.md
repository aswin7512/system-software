### **Algorithm: Worst Fit Memory Allocation**

1. **Start**

2. **Initialize** an array `alloc[]` of size `np` with all values set to `-1` (indicating not allocated).

3. **For** each process `i` from `0` to `np-1`, do:

   1. **For** each block `j` from `0` to `nb-1`, do:

      * **If** `alloc[i] == -1` and `proc[i] <= block[j]`, then:

        * Set `alloc[i] = j` (tentatively allocate to block `j`)
      * **Else if** `proc[i] <= block[j]` and `block[j] > block[alloc[i]]`, then:

        * Update `alloc[i] = j` (choose worse fitting block — i.e., largest)
   2. **If** `alloc[i] != -1`, then:

      * Allocate process `i` to `alloc[i]`
      * Subtract `proc[i]` from `block[alloc[i]]`

4. **Print** the allocation results:

   * **For** each process `i` from `0` to `np-1`, do:

     * **If** `alloc[i] == -1`, print process `i+1`, size `proc[i]`, and `"NA"` (Not Allocated)
     * **Else**, print process `i+1`, size `proc[i]`, and `alloc[i] + 1` (allocated block number)

5. **End**

