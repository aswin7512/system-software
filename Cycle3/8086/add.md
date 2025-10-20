### ⌨️ `read` Procedure

**Algorithm:**
* **Step 1:** Start the procedure.
* **Step 2:** Initialize an accumulator to 0 by pushing 0 onto the stack.
* **Step 3:** **[Loop Start]** Read one character from the keyboard.
* **Step 4:** Check if the character is the 'Enter' key. If yes, go to Step 10.
* **Step 5:** Convert the character from ASCII to a numeric digit by subtracting `30h`.
* **Step 6:** Retrieve the current accumulated value from the stack.
* **Step 7:** Multiply the accumulated value by 10.
* **Step 8:** Add the new digit (from Step 5) to the accumulated value.
* **Step 9:** Save the new accumulated value back onto the stack and go back to Step 3.
* **Step 10:** **[Loop End]** Pop the final value from the stack into the `AX` register.
* **Step 11:** Return from the procedure.

---

### 🖥️ `display` Procedure

**Algorithm:**
* **Step 1:** Start the procedure with the number to be displayed in `AX`.
* **Step 2:** Initialize a counter (`CX`) to zero.
* **Step 3:** **[Conversion Loop Start]** Divide the number in `AX` by 10. The remainder goes into `DX`, and the quotient stays in `AX`.
* **Step 4:** Convert the remainder (digit) in `DX` to an ASCII character by adding `30h`.
* **Step 5:** Push the ASCII character onto the stack to reverse its order.
* **Step 6:** Increment the digit counter (`CX`).
* **Step 7:** If the quotient in `AX` is not zero, repeat from Step 3.
* **Step 8:** **[Display Loop Start]** Pop a character from the stack into `DX`.
* **Step 9:** Print the character in `DX` to the screen.
* **Step 10:** Repeat the display loop (Step 8-9) until the counter (`CX`) is zero.
* **Step 11:** Return from the procedure.

---

### ➕ `addtn` Procedure

**Algorithm:**
* **Step 1:** Start the procedure.
* **Step 2:** Move the value of `num1` into the `AX` register.
* **Step 3:** Move the value of `num2` into the `BX` register.
* **Step 4:** Add the value in `BX` to `AX`. The sum is now stored in `AX`.
* **Step 5:** Call the `display` procedure to print the sum held in `AX`.
* **Step 6:** Return from the procedure.

---

### 📜 Main Program (`start`)

**Algorithm:**
* **Step 1:** Start.
* **Step 2:** Initialize the Data Segment (DS) register.
* **Step 3:** Display the prompt "Enter no: ".
* **Step 4:** Call the `read` procedure to get the first number.
* **Step 5:** Store the result from `AX` into the variable `num1`.
* **Step 6:** Display the prompt "Enter no: " again.
* **Step 7:** Call the `read` procedure to get the second number.
* **Step 8:** Store the result from `AX` into the variable `num2`.
* **Step 9:** Display the message "Sum is: ".
* **Step 10:** Call the `addtn` procedure to perform the calculation and display the result.
* **Step 11:** Terminate the program.
* **Step 12:** Stop.

