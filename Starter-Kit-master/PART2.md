# Part 2

## Video Demo

Please provide the YouTube link to your [Video Demo](https://youtube.com).

## Minimum Requirements

### Completed

List all the features completed.

1. Modified alien movements.
2. Alien now stops after countering a rock or a border before it.
3. Updated the map.
4. Modified the character attributes into a vector.
5. Arrows now redirect alien movements accordingly.
6. Trails are now removed when the alien movement is stopped and replaced by randomly generated objects.
7. The player can now change the directions of the arrow in the map.
8. Zombies are now pushed in the map according to their numbers.
9. All zombies have different attributes.
10. Zombies move in random directions and not crossing the borders.
11. Pods deals damage to the closest zombie.
12. Alien now damages zombies directly and stops if zombie is alive.
13. Zombies are now removed from the map when their hp reaches 0.
14. Zombies now can detect alien and attack according to their range.
15. Added arrow, help, quit commands.
16. Alien wins if all zombies are dead, Alien loses if its life is = 0.
17. Added play again after winning or losing.

### To Do

List all the features not yet done. Remove this section if there is no incomplete requirements.

1. To make sure the zombies does not overwrite the alien.
2. *add more*

## Additional Features

Describe the additional features that has been implemented.

## Contributions

List down the contribution of each group members.


### Abdelrahman Mohamed Hassan Mohamed (1211305311)

1. Created the default settings and board change settings.
2. Added many error check to make sure the user does not close the program by mistyping.
3. Participated in many error fixing, such as the board abnormality errors, alien movements and the new board errors, and many other errors.

### Amgad Elrashid Gurashi Eltayeb (1211307882)

1. Created the board and new boards.
2. Implemented the alien movements.
3. Randomly generate objects in the map.
4. Fixed the new board, alien movement, map abnormality errors.

### Balchi Maher M.  N. (1221302826)

1. Fixed error regarding change settings input.
2. Implemented generate a random map each playthrough.
3. Added attribute output.
4. Added randomly generated error.
5. Add Nuke feature.
6. Add Stamina feature.
7. Add new game command.
8. Worked on zombie movement.
9. updated help command.

## Problems Encountered & Solutions
1. The issue with the zombie not attacking the alien within range was due to the fact that the zombie was only checking on one block instead of all the blocks within the range. The solution was to modify the code to make the zombie check all blocks within the range.

2. The problem with the zombie's movements was that it was going out of the border, and the code was overly complex. The solution was to update the code so that the zombie would only move towards certain objects around the map.

3. Users were able to change arrows to any direction they wanted, even if the arrow did not exist on the map. This problem was resolved by implementing an error message that would prevent users from changing arrows that do not exist.

4. A random attribute would randomize each turn. It was fixed by calling the function before displayIntro in main.

5. The problem of the zombie spawning in place of the alien was fixed by ensuring that the alien was placed first in the map before the zombie.

6. The removeTrail function was not removing the trails with the correct coordinates. The solution was to develop a specific formula that would ensure the function removed the correct trails by matching the correct symbol ('.').
