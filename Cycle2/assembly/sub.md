### Algorithm: Subtract Two Numbers with Borrow Check

1.  **Initialize** a borrow counter (`CX`) to **0**.
2.  **Load** the first number (minuend) from memory `[0500]` into `AX`.
3.  **Load** the second number (subtrahend) from memory `[0600]` into `BX`.
4.  **Subtract** the second number from the first (`AX` - `BX`).
5.  **Check for Borrow**: If the subtraction required a borrow (i.e., if the second number was larger than the first):
    * Increment the borrow counter (`CX`) by 1.
6.  **Store** the result from `AX` into memory `[0700]`.
7.  **Store** the borrow counter from `CX` into memory `[0800]`.
8.  **Stop**.