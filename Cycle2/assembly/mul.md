### Algorithm: 16-bit Multiplication

1.  **Load** the first number from memory `[0300]` into `AX`.
2.  **Load** the second number from memory `[3002]` into `BX`.
3.  **Multiply** `AX` by `BX`. (The 32-bit result is placed in registers `DX:AX`, with the high part in `DX` and the low part in `AX`).
4.  **Store** the **low 16 bits** of the result from `AX` into memory `[3004]`.
5.  **Copy** the second number from `BX` back into `AX`.
6.  **Store** the value from `AX` (which is now the original second number) into memory `[3006]`.
7.  **Stop**.