### Algorithm: 16-bit by 8-bit Division

1.  **Initialize** a source pointer (`SI`) to address `0500` and a destination pointer (`DI`) to `0600`.
2.  **Load** the 8-bit **divisor** from memory `[0500]` into register `BL`.
3.  **Load** the 16-bit **dividend** from the next memory location `[0501]` into register `AX`.
4.  **Divide** the dividend in `AX` by the divisor in `BL`.
    * The resulting 8-bit **quotient** is automatically stored in `AL`.
    * The resulting 8-bit **remainder** is automatically stored in `AH`.
5.  **Store** the entire `AX` register (containing the quotient and remainder) into memory at the destination `[0600]`.
6.  **Stop**.