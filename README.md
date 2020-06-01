# CS 100 Programming Project
A) Group Members: Mariam Razak (mraza008@ucr.edu) and Maya Fall (mfall003@ucr.edu)

B) Title of Project: Hangman

C) What it is: What it is: We will be working on a hangman game in terminal. The user will guess letters of a work and either be correct in which case a space of the blank will be filled in, or be incorrect in which case the next part of the 'man' will be drawn. 

D) This game will be interesting because it will help the reader increase their spelling and word recognition abilities. It will also allow the user to choose themed words (ie Shakespere or Harry Potter), making the game more personalized and fun for the individual. 

E) We plan to use C++, GitHub, textfiles, and PuTTy/terminal. 

F) The input is the user input from the keys guessing (letters), and the output is what is drawn on the screen and added to the blank (where the letters will be filled in as the user guesses). 



We are using the abstract factory pattern by having an abstract base class (board) and concrete classes fullboard and emptyboard. We are using the strategy pattern by having different versions of draw_board in that act in different ways based on whether it is the first guess or there have been no correct guesses, or if correct guesses have been made. Finally, we are using the visitor pattern to change behavior. The object, guess, must be affected by user input. The guess class accepts input and modifies its behavior based on what is taken in. 

To view this code’s tests, run cmake3 . and then make. The test executable is ./test, and to play the game, run ./play.



Some correct and incorrect guesses. 


A finished, successful game. 

A finished, failed game. 
