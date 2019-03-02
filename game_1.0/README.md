01. The game starts
02. Create an instance of the sudoku class and initiate it with puzzle using a constructor
03. Print the unsolved sudoku
04. call the solve method
05. call the create empty list method
06. check for index 0-80 if zero i.e empty
07. make an entry in the empty node
08. create the probability list
09. for values 1-9 check the probability of the for the index call checkIndex method
10. checkRow method
11. checkCol method
12. checkBox method
13. if all return 1 then return true
14. If true make an entry in the probability list and goto 09 for next value
15. return the probability list head
16. store in the empty list
17. return the empty list head
19. count the number for probable values in the for each index value
20. if the number is 1 make the value entry in the puzzle
21. goto step 05 repeat until the puzzle is solved
22. print the solved puzzle
