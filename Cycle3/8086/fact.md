### ⌨️ `read` Procedure

**Algorithm:**
* **Step 1:** Start the procedure.
* **Step 2:** Initialize an accumulator to 0 by pushing 0 onto the stack.
* **Step 3:** **[Loop Start]** Read one character from the keyboard.
* **Step 4:** If the character is 'Enter', go to Step 10.
* **Step 5:** Convert the character from ASCII to a numeric digit by subtracting `30h`.
* **Step 6:** Retrieve the current accumulated value from the stack.
* **Step 7:** Multiply the accumulated value by 10.
* **Step 8:** Add the new digit to the accumulated value.
* **Step 9:** Save the new value back onto the stack and go to Step 3.
* **Step 10:** **[Loop End]** Pop the final value from the stack into the `AX` register.
* **Step 11:** Return from the procedure.

***

### 🖥️ `display` Procedure

**Algorithm:**
* **Step 1:** Start with the number to display in `AX`.
* **Step 2:** Initialize a counter (`CX`) to zero.
* **Step 3:** **[Conversion Loop]** Divide `AX` by 10. The remainder goes to `DX`, the quotient to `AX`.
* **Step 4:** Convert the remainder in `DX` to an ASCII character by adding `30h`.
* **Step 5:** Push the character onto the stack.
* **Step 6:** Increment the counter (`CX`).
* **Step 7:** If `AX` is not zero, repeat from Step 3.
* **Step 8:** **[Display Loop]** Pop a character from the stack into `DX`.
* **Step 9:** Print the character in `DX`.
* **Step 10:** Repeat the display loop until `CX` is zero.
* **Step 11:** Return from the procedure.

***

### 🔢 `factorial` Procedure

**Algorithm:**
* **Step 1:** Start the procedure.
* **Step 2:** Initialize the result register (`AX`) to 1.
* **Step 3:** Load the input number (`num1`) into the counter register (`CX`).
* **Step 4:** **[Loop Start]** Multiply `AX` by `CX`. The result is stored in the `DX:AX` register pair.
* **Step 5:** Decrement the counter (`CX`).
* **Step 6:** If `CX` is not zero, jump back to Step 4 to continue multiplying.
* **Step 7:** **[Loop End]** Call the `display` procedure to print the lower 16 bits of the result from `AX`.
* **Step 8:** Return from the procedure.

***

### 📜 Main Program (`start`)

**Algorithm:**
* **Step 1:** Start.
* **Step 2:** Initialize the Data Segment (DS) register.
* **Step 3:** Display the prompt "Enter no: ".
* **Step 4:** Call the `read` procedure to get the number.
* **Step 5:** Store the result from the `AX` register into `num1`.
* **Step 6:** Display the message "Factorial is: ".
* **Step 7:** Call the `factorial` procedure to calculate and display the result.
* **Step 8:** Terminate the program.
* **Step 9:** Stop.