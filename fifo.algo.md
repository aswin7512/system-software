
### **Algorithm: FIFO Page Replacement**

1. **Input** the length of the reference string `n` and the frame width `w`.

2. **Input** the reference string array `rs[]` of length `n`.

3. **Initialize**:

   * Frame array `f[]` of size `w` with all values set to `-1`
   * `fp = 0` (frame pointer to indicate the next replacement index)
   * `hc = 0` (hit count)
   * `fc = 0` (fault count)

4. **For** each page `rs[i]` from `i = 0` to `n-1`, do:

   1. **Check** if `rs[i]` is present in frame `f[]` using linear search:

      * **If found**:

        * Increment `hc` (hit count)
        * Mark result as "Hit"
      * **Else**:

        * Replace `f[fp]` with `rs[i]` (FIFO replacement)
        * Increment `fc` (fault count)
        * Update `fp = (fp + 1) % w` (circularly move to next frame index)
        * Mark result as "Fault"
   2. **Display**:

      * Current accessed page
      * Current state of page frame `f[]` (show `'*'` for empty)
      * "Hit" or "Fault" status

5. **After processing all pages**, print:

   * Total number of hits (`hc`)
   * Total number of faults (`fc`)

6. **End**
