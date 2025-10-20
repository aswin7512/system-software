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

### ➗ `divide` Procedure

**Algorithm:**

* **Step 1:** Start the procedure.
* **Step 2:** Move the dividend (`num1`) into the `AX` register.
* **Step 3:** Move the divisor (`num2`) into the `BX` register.
* **Step 4:** Clear the `DX` register. The `div` instruction uses the 32-bit pair `DX:AX` as the dividend.
* **Step 5:** Divide `DX:AX` by `BX`. The quotient is stored in `AX`, and the remainder is in `DX`.
* **Step 6:** Call the `display` procedure to print the quotient from `AX`.
* **Step 7:** Return from the procedure.

***

### 📜 Main Program (`start`)

**Algorithm:**

* **Step 1:** Start.
* **Step 2:** Initialize the Data Segment (DS) register.
* **Step 3:** Display the prompt "Enter no: ".
* **Step 4:** Call the `read` procedure to get the dividend.
* **Step 5:** Store the result from the `AX` register into `num1`.
* **Step 6:** Display the prompt "Enter no: " again.
* **Step 7:** Call the `read` procedure to get the divisor.
* **Step 8:** Store the result from `AX` into `num2`.
* **Step 9:** Display the message "Quotient is: ".
* **Step 10:** Call the `divide` procedure to calculate and display the result.
* **Step 11:** Terminate the program.
* **Step 12:** Stop.