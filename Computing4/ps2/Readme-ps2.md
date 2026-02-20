# PS2: Pythagorean Tree

## Contact
Name: AJ Audet
Section: 204
Time to Complete: 4 hours


## Description
This project was designed to create a Pythagorean Tree Fractal using recursion to generate the tree based off of an initial length and depth

### Features
The pTree function creates a base square for the branches to use, then it creates 3 seperate transformations, a parent transformation that tracks the initial rotation, size, position, then for the left and right branches it "moves" the other squares to the left/right most edge of the shape then rotates it by a fixed angle of 45 degrees.

The getBounds function is designed to find the outermost branch and then create a boundary mapping the width/height of the fractal that can then be used to construct the display window.

### Issues
I had issues with centering the tree at first, this is why I created the getBounds function. It had taken a bit of time to realize that my issue was that I was trying to build the tree for the window size and not the other way around, O needed to build the window for an already constructed tree.

Different angles do not work currently, I have completely hard-coded in the default 45 degree triangle. If I decide that I am going to recreate this project in the future that is one of the first things I will implement.

### Extra Credit
For the extra credit my tree uses a purple gradient pattern that starts at violet and ends with indigo.

## Acknowledgements
    - SFML Color documentation for gradient creation
    - SFML Transform documentation for rotation of shapes
    - SFML Rectangle Shape documentation for creation of "trunk" and "branches"

## Credits
    - https://www.sfml-dev.org/documentation/3.0.2/classsf_1_1Color.html
    - https://www.sfml-dev.org/documentation/3.0.2/classsf_1_1Transform.html
    - https://www.sfml-dev.org/documentation/3.0.2/classsf_1_1RectangleShape.html
