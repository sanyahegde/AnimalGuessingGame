# Animal Guessing Game

DESCRIPTION: This Animal Guessing Game is an interactive and adaptive guessing game where the binary tree structure evolves based on user input, allowing the program to improve its capabilities with each playthrough. 
The game tries to guess the animal the user thinks of by a series of yes/no questions. If the computer guesses correctly, it wins,but if not it learns from the user. The game will continue until the user stops playing. 



**How to Play:** 
1. The program asks the user to press Enter to begin the game.
2. The game then presents a series of questions, and the user responds (yes/no) based on whether the statement applies to their chosen animal.
3. The program uses the binary tree structure to navigate through the questions and narrows down its guess until it reaches a leaf node containing the guessed animal.
4. If the program correctly guesses the animal, it declares victory. Otherwise, it asks the user for the correct animal and a yes/no question that differentiates the guessed animal from the correct one.
5. The program incorporates the user's input to update the binary tree structure, improving its future guessing capabilities.
6. The game loop allows the user to play multiple rounds, and they can choose to continue playing or exit when asked at the end of each round.

**Code Overview:**
 - **`AnimalNode`** struct: Defines the structure of nodes in the binary tree, with **`data`**, **`left`**, and **`right`** properties representing the question/animal, left child, and right child, respectively.
- **`PlayGame`** function: For a single round of the game, asks questions and navigates through the tree to guess the animal.
 - **`UpdateTree`** function: Updates the binary tree based on user input to improve guessing for future rounds.
  - **`main`** function: Initializes the binary tree with initial questions and animals, and starts the game loop. User decides whether to loop again. 

**Helpful Notes:** 
Execute the following C++ code on your system. 
