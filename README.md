# CS303Assignment-1
Assignment 1 Program

This program allows users to read data into a vector, as if it is an array, from a file they provide and perform operations like searching, modifying, adding, and removing elements in the vector.  
main.cpp— the main driver code that prompts the user's input and calls functions
function.h— contains function declarations that are used to manipulate the array
function.cpp— contains function definitions 

Enter the name of your file when the program prompts you to, the file should contain integers, of any amount, separated by spaces as an array. The program will read the data into the vector "array". A menu will be displayed with a variety of choices, you are to choose an operation by entering whichever number it is on the menu. Follow the prompts to enter any required input values. The program will call the appropriate functions and modify the data of the original file. Exi the program when done. There is error handling, exceptions are thrown if invalid indices are provided by the user and are displayed so the user is aware of what error has occurred. 

functions
findInteger — searches for an integer in the vector
modifyInteger — updates the integer value at a given index
addInteger — add a new integer to the end of the vector
removeReplace — remove or replace the integer @ a given index.

