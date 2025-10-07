### Algorithm: Compare and Store if Greater

1.  **Load** the first 8-bit number from memory address `[0500]` into a register (`AL`).
2.  **Load** the second 8-bit number from the next address, `[0501]`, into another register (`BL`).
3.  **Compare** the two numbers.
4.  **Check the condition**:
    * **If** the first number is **less than** the second number, store the second (larger) number into memory address `[0502]`.
    * **Otherwise**, do nothing.
5.  **Stop** the program.