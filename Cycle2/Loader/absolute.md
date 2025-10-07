### Algorithm: Process Object Code File

1.  **Start**
2.  **Open** the object code file named `objcode`.
3.  **Check** if the file was opened successfully. If not, print an error and **exit**.
4.  Initialize a location counter `locctr`.
5.  **Read** the file character by character until the end of the file is reached.
6.  **Process** the character read:
    * If the character is **'H'** (Header Record):
        1.  Read the **Program Name**, **Start Address**, and **Program Length**.
        2.  Set `locctr` to the **Start Address**.
        3.  Print the Program Name, Start Address, and Program Length.
    * If the character is **'T'** (Text Record):
        1.  Read the record's **Start Address** and **Length**.
        2.  **Loop** `Length` number of times to read each byte of object code:
            a. Read the next two characters (one byte).
            b. Print the current `locctr` value followed by the two characters.
            c. Increment `locctr`.
7.  **Stop**