### Algorithm: One-Pass Assembler

1.  **Initialization**:
    * Initialize the location counter (`locctr`), an empty symbol table, and an object code buffer.
    * Open the input assembly file, an output listing file, and an output object file.

2.  **Process Assembly Code**:
    * Read the source file line by line.
    * For each line, parse it into `[label]`, `opcode`, and `[operand]`.
    * **If a `label` exists**:
        * Insert the label and the current `locctr` value into the symbol table.
        * If this label was used before it was defined (a forward reference), go back and fix the placeholder addresses in the object code buffer (backpatching).
    * **Process the `opcode`**:
        * **If it's an instruction** (like `LDA`, `ADD`):
            * Look up the `operand`'s address in the symbol table.
            * If the operand is not yet defined, record the current location as a forward reference and use a temporary address (e.g., 0).
            * Assemble the machine code (instruction opcode + operand address) into the object code buffer.
            * Increment `locctr` by the instruction size (e.g., 3).
        * **If it's a directive** (like `RESW`, `BYTE`):
            * Reserve space or assemble the data value into the object code buffer.
            * Increment `locctr` by the size of the data.
    * Write the processed line and its address to the listing file.
    * Continue until the `END` directive is found.

3.  **Generate Object File**:
    * Calculate the total program length.
    * Write a **Header (H) record** containing the program name, start address, and length.
    * Write the contents of the object code buffer into one or more **Text (T) records**.
    * Write an **End (E) record** with the program's starting execution address.

4.  **Finalization**:
    * Check for any symbols that were used but never defined and print warnings.
    * Close all files.