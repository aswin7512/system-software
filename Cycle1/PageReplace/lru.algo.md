
### **Algorithm: LRU Page Replacement**

1. **Start**
2. **Initialize**:
   * Frame array `f[]` of size `w` with all values set to `-1`
   * Last accessed time array `lat[]` of size `w` with all values set to `-1`
   * `hc = 0` (hit count)
   * `fc = 0` (fault count)

3. **For** each page `rs[i]` from `i = 0` to `n-1`, do:

   1. **Check** if `rs[i]` is present in frame `f[]`:

      * **If found** at index `pos`:

        * Increment `hc` (hit count)
        * Update `lat[pos] = i` (mark current time as last used)
        * Mark result as "Hit"
      * **Else** (page fault occurs):

        1. Find the index `min_in` of the frame with the **least recent use** (smallest value in `lat[]`)
        2. Replace `f[min_in]` with `rs[i]`
        3. Set `lat[min_in] = i` (update last accessed time)
        4. Increment `fc` (fault count)
        5. Mark result as "Fault"

   2. **Display**:

      * Current accessed page
      * Current state of page frame `f[]` (show `'*'` for empty)
      * "Hit" or "Fault" status

4. **After processing all pages**, print:

   * Total number of hits (`hc`)
   * Total number of faults (`fc`)

5. **End**

