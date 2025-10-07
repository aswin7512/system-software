### Algorithm: Simple Relocating Loader

1.  **Start**
2.  **Initialize**:
    * Prompt user for a **New Starting Address**.
    * Initialize the location counter (`locctr`) with this new address.
3.  **Read Header Record ('H')**:
    * Open the object file.
    * Read the **Original Start Address** from the header.
    * Calculate the **Relocation Factor** = (New Starting Address - Original Start Address).
4.  **Process Text Records ('T')**:
    * Read a Text Record to get the machine code, its length, and the **Relocation Bitmask**.
    * Convert the bitmask into a binary string (e.g., "011010...").
    * **For each instruction** in the record:
        a. Check the corresponding bit in the bitmask.
        b. **If the bit is '1'**: Add the **Relocation Factor** to the instruction's address part.
        c. **Print** the modified (or original) instruction byte by byte, preceded by the current `locctr`.
        d. Increment `locctr` for each byte printed.
5.  **Repeat** Step 4 for all Text Records in the file.
6.  **End**