## **Algorithm: Assembler Pass 2**

1. **Start**

2. Open files:

   * `intermediate.sic`, `optab`, `symtab`, `output`, `listfile.sic`.
   * If any file fails to open → print error and **exit**.

3. Load `optab` into memory.

4. Load `symtab` into memory.

5. Load intermediate file lines into `itr[]`.

6. Initialize `text record` buffer as empty.

7. Extract **program name** from first line.

   * If no label present, assign `"NONAME"`.
   * Save **starting address** and compute **program length**.

8. Write **Header record** to output file.

9. Write first line (START line) to listing file.

10. **For each line in intermediate file (except START):**

    * Initialize `objhex = ""` and `objbytes = 0`.
    * Search `optab` for opcode:

      * If **found**:

        * Convert opcode to hex.
        * Search `symtab` for operand symbol:

          * If found → get address.
          * If not found → print error (undefined symbol) and exit.
        * Form **object code = opcode + address**.
        * Append object code to text record.
      * Else if opcode = `BYTE`:

        * Convert constant (C'..' or X'..') into hex.
        * Append object code to text record.
      * Else if opcode = `WORD`:

        * Convert operand to 3-byte hex.
        * Append object code to text record.
      * Else if opcode = `RESB` or `RESW`:

        * Flush text record to output file.
      * Else if opcode = `END`:

        * Do nothing (end processing).
      * Else:

        * Flush text record.
    * Write current line to listing file with corresponding object code (if any).

11. After processing all lines:

    * Flush any remaining text record to output file.

12. Write **End record** to output file with starting address.

13. Print confirmation messages:

    * `"Object Code Saved in output"`
    * `"Listing file Saved in listfile.sic"`.

14. Close all files.

15. **Stop**.