### **Algorithm: Pass 1 of SIC Assembler**

1. **Read first line from input file**

   * If `OPCODE == "START"`
     → Save operand as starting address
     → Set `locctr = start`
     → Write line to intermediate file
     → Read next line

2. **If not START**, set `locctr = 0`

3. **While `OPCODE != "END"`**, repeat:

   * If line is **not a comment**:

     * If `LABEL` is present:

       * Search `SYMTAB` (symbol table)
       * If label **exists** → Error: duplicate symbol
       * Else → Insert `(LABEL, LOCTR)` into SYMTAB

     * **Search OPTAB** for OPCODE:

       * If found → `locctr += 3` (instruction length)
       * Else if:

         * `OPCODE == "WORD"` → `locctr += 3`
         * `OPCODE == "RESW"` → `locctr += 3 * operand`
         * `OPCODE == "RESB"` → `locctr += operand`
         * `OPCODE == "BYTE"` → `locctr += length of constant`
         * Else → Error: invalid opcode

   * Write line to intermediate file

   * Read next line

4. After loop ends:

   * Write final line to intermediate file
   * Save program length: `program length = locctr - start`

5. Close All files...
6. **Stop**.