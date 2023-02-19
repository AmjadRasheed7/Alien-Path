# Part 1

## Video Demo

[https://www.youtube.com/watch?v=UicshVxMjfg](https://youtu.be/NiAl3fY34SU)

## Minimum Requirements

Overview of Alien vs. Zombie
Game Board
Game Characters
-   Attributes
Game Objects
Game Controls
-   up, down, left, right

### Completed

1. Default settings.
2. Created the game board successfully with the title.
3. Made sure the new Board with the new settings also prints out successfully.
4. Allowing the user to change the rows and columns settings of the board.
5. Added error messages for most invalid inputs from the user.
6. Added movement commands for the alien to move around the map.
7. Printing out the alien and zombie attributes.


### To Do

1. Fix the zombie life, attack, range arrays and printing them out correctly.
2. Modify the alien movement, making him move in one direction until it reaches a certain border or object.
3. Modifying the life, attack and range, to make sure it changes whenever the player damages a zombie or a zombie damages a player and such.
4. Adding save, load, quit and help commands.
5. Giving the objects in the map a purpose.
6. Adding collisions for the Alien and the Zombies.

## Additional Features

Adding error messages to make sure the code does not stop running with mistypes.

## Contributions

### Abdelrahman Mohamed Hassan Mohamed (1211305311)

1. Created the default settings and board change settings.
2. Added many error check to make sure the user does not close the program by mistyping.
3.  Participated in many error fixing, such as the board abnormality errors, alien movements and the new board errors, and many other errors.

### Amgad Elrashid Gurashi Eltayeb (1211307882)

1. Created the board and new boards.
2. Implemented the alien movements.
3. Randomly generate objects in the map.
4. Fixed the new board, alien movement, map abnormality errors.

### Balchi Maher M.  N. (1221302826)

1. Fixed error regarding change settings input.
2. Implemented generate a random map each playthrough.
3. Added attribute output.

## Problems Encountered & Solutions

### Describe the problems encountered and provide the solutions / plan for the solutions.

### Board abnormality:
The board was generating random characters and not structured correctly, this is due to the user changing the default settings and using the old board that carries
the old values of rows and columns. This was fixed by creating a newBoard, reinitializing the map before displaying it.

### Error messages:
When the user enters a letter in a *cin >> int rows* or else. It prints infinite number of messages for a certain reason. However, it was fixed by simply ignoring the maximum values
*INT_MAX*.

### Alien movement changes the new Board structure:
When the alien moves, we repeatedly print a newer board. However, every alien movement caused the board abnormality, this is because when the user changes the default
settings. The display function still carries the old values every alien movement. This is was fixed by modifying the newBoard function. Basically the mapinit will run once to make sure
that it does not change the objects position every alien movement, and i put the display
function in a while loop until the user is done playing then we will probably add a break if statement.
