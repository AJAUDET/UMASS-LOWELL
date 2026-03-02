# PS3: Sokoban

## Contact
Name: AJ Audet
Section: 204
Time to Complete: 7 hours


## Description
Explain what the project does.

This project, as is, creates a Sokoban level based off of an inputted .lvl file. Currently the levels are generated and the player sprite is just the head, there is no movement implementation yet, I will b eaddin that in part b.

### Features
Describe what your major decisions were and why you did things that way.

The Sokoban.hpp file is similar to the one given to us in sokoban.zip, the changes I made to that file were removal of the optional undo/redo functions as I might implement them in the future along side the moveCounter function.

The private variables that I decided to track were the level width, height. A matrix for the level grid, and a copy of that matrix to reset the level. A Vector2u to store the player's position. A SpriteSheet Pointer that stores the cropped tiles for use that a Texture variable will index through to find the correct tile for the level. An index function that allows for proper finding for the tile to the space in the matrix.

#### Part a

#### Part b

### Memory
Describe how you decided to store the level data including whether you used smart pointers.

As a base I used a unique pointer to a SpriteSheet object to store the tiles, my SpriteSheet implementation uses smart pointers to store a cropped Texture.

### Lambdas
Describe what <algorithm> functions you used and what lambda expressions you wrote.

I did not use any lambda functions.

### Issues
What did you have trouble with?  What did you learn?  What doesn't work?  Be honest.  You might be penalized if you claim something works and it doesn't.

I had trouble with not overwriting the tiles the player moved over, for instance if the player moved over a storage tile the tile would be replaced with a floor tile, I have since fixed the issue.

Another issue I has was player movement, the logic behing movement revolves around a check of the tile in front of the player, but when a box comes into play there is a check for the objct ahead of the box as well.

After eveyrhting though my Sokoban levels are complete, I am still having an issue with displaying a winning screen for the player as of 3-1-25 but I will work on it during the grace period

### Extra Credit
Anything special you did.  This is required to earn bonus points.

## Acknowledgements
List all sources of help including the instructor or TAs, classmates, and web pages.
If you used images or other resources than the ones provided, list them here.

AJ Audet SpriteSheet: ps1
AJ Audet SpriteBuilder: ps1

Kenney Sokoban Pack (CC0): https://kenney.nl/assets/sokoban
SFML Documentation: https://www.sfml-dev.org/documentation/3.0.2/annotated.html 
Hurmit Nerd Font: https://www.nerdfonts.com/font-downloads