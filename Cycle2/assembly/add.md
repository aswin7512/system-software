### Algorithm: Add Two Numbers with Carry Check

1.  **Initialize** a counter (`CX`) to **0**.
2.  **Load** the first number from memory address `[0500]` into `AX`.
3.  **Load** the second number from memory address `[0600]` into `BX`.
4.  **Add** the two numbers (`AX` + `BX`).
5.  **Check for Carry**: If the addition resulted in an overflow (carry):
    * Increment the counter (`CX`) by 1.
6.  **Store** the sum from `AX` into memory `[0700]`.
7.  **Store** the counter value from `CX` into memory `[0800]`.
8.  **Stop**.