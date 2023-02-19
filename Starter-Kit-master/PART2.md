# Part 2

## Video Demo

[Please provide the YouTube link to your [Video Demo](https://youtube.com).](https://youtu.be/NiAl3fY34SU)

## Minimum Requirements

### Completed

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
18. Added save and load commands.


## Additional Features

1. Nuke command: Hitting every zombie in the map with a damage of 50.
2. New command: Restarting the game with a new randomly generated objects and coordinates.
3. Added stamina: Alien have 5 stamina and it depletes by one, everytime the alien changes the direction of an arrow.

## Contributions

### Abdelrahman Mohamed Hassan Mohamed (1211305311)

1. Added every objects in the game and programmed every objects.
2. Fixed many zombie and alien movement bugs.
3. Helped with alien movements
4. Fixed updated map bugs.
5. Helped with winning/losing feature.
6. Tested and identified some bugs.

### Amgad Elrashid Gurashi Eltayeb (1211307882)

1. Updated the map.
2. Modified alien movement.
3. Implemented save and load feature.
4. Completed all zombie related functions including, movements, attack, dying and pushing them into the map. And fixing their errors, such as zombie moving out of map border.
5. Added winning, losing, play again features
6. Implemented trails generating random objects around the map.
7. Added arrow command, allowing the user to redirect it to whatever way they desire.
8. Fixed some of the bugs in Nuke feature.
9. Fixed loading and saving errors.
10. Added 'help' command.
11. Fixed the pod object.

### Balchi Maher M.  N. (1221302826)

1. Fixed error regarding change settings input.
2. Fixed generate a random map each playthrough.
3. Added attribute output.
4. Fixed randomly generated attribute error.
5. Added Nuke feature.
6. Added Stamina feature.
7. Added 'new' game command.
8. Worked on most parts of zombie movement.
9. Updated help command.

## Problems Encountered & Solutions
1. The issue with the zombie not attacking the alien within range was due to the fact that the zombie was only checking on one block instead of all the blocks within the range. The solution was to modify the code to make the zombie check all blocks within the range.

2. The problem with the zombie's movements was that it was going out of the border, and the code was overly complex. The solution was to update the code so that the zombie would only move towards certain objects around the map.

3. Users were able to change arrows to any direction they wanted, even if the arrow did not exist on the map. This problem was resolved by implementing an error message that would prevent users from changing arrows that do not exist.

4. A random attribute would randomize each turn. It was fixed by calling the function before displayIntro in main.

5. The problem of the zombie spawning in place of the alien was fixed by ensuring that the alien was placed first in the map before the zombie.

6. The removeTrail function was not removing the trails with the correct coordinates. The solution was to develop a specific formula that would ensure the function removed the correct trails by matching the correct symbol ('.').
