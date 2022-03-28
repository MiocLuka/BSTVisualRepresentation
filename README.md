# BSTVisualRepresentation
The program creates a binary search tree based on the input parameters, and shows the tree structure in the program

How to run it?

Compile and run the program with no command line arguments.
Enter the elements which you want to sort in a binary search tree (any order, duplicates branch to the left)
The program will output the elements in sorted order and a visual representation of the binary search tree.

EXAMPLE:

./BSTPrint
Enter the numbers to be stored: 12 4 5 10 15 45 8 6 2 

The numbers in sorted order: 2 4 5 6 8 10 12 15 45 
----------------------------------------------
|    |    |    |    |    |    |  12|    |    |
----------------------------------------------
|    |   4|    |    |    |    |    |  15|    |
----------------------------------------------
|   2|    |   5|    |    |    |    |    |  45|
----------------------------------------------
|    |    |    |    |    |  10|    |    |    |
----------------------------------------------
|    |    |    |    |   8|    |    |    |    |
----------------------------------------------
|    |    |    |   6|    |    |    |    |    |
----------------------------------------------
