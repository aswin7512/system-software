
### **Algorithm: Best Fit Memory Allocation**

1. **Input** the number of processes `np` and number of memory blocks `nb`.

2. **Input** the sizes of all `np` processes into the array `proc[]`.

3. **Input** the sizes of all `nb` memory blocks into the array `block[]`.

4. **Initialize** an array `alloc[]` of size `np` with all values set to `-1` (indicating not allocated).

5. **For** each process `i` from `0` to `np-1`, do:

   1. **For** each block `j` from `0` to `nb-1`, do:

      * **If** `alloc[i] == -1` and `proc[i] <= block[j]`, then:

        * Set `alloc[i] = j` (tentatively allocate to block `j`)
      * **Else if** `proc[i] <= block[j]` and `block[j] < block[alloc[i]]`, then:

        * Update `alloc[i] = j` (choose better fitting block)
   2. **If** `alloc[i] != -1`, then:

      * Allocate process `i` to `alloc[i]`
      * Subtract `proc[i]` from `block[alloc[i]]`

6. **Print** the allocation results:

   * **For** each process `i` from `0` to `np-1`, do:

     * **If** `alloc[i] == -1`, print process `i+1`, size `proc[i]`, and `"NA"` (Not Allocated)
     * **Else**, print process `i+1`, size `proc[i]`, and `alloc[i] + 1` (allocated block number)

7. **End**
