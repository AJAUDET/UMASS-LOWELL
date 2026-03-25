# PS4: AniPlayer

## Contact
Name: AJ Audet
Section: 204

Partner Name: Hoang Bach Nguyen
Partner Section: 201

Time to Complete: 8 Hours

## Description
Displays a static image based off of given data in a json file. There are plans to make it a non static animation player in part B of the assignment.

### Features

#### Part a
Describe what your major decisions were and why you did things that way.

AniPlayer: Based off of the given information from a json file, creates shapes, or images to display onto a SFML Window.
Component: Parses through a json file looking for key information such as "shape", "width", "height", "radius", "keyframes", etc.
KeyFrame: Moves a given object by an ammount specified in the "keyframes" section in a json file.

The major design decision was using a static factory function Component::fromJson() to construct the appropriate subclass based on the "shape" field in the JSON. This keeps construction logic in one place so that AniPlayer and CompositeComponent do not need
to know which concrete type they are creating.

Color parsing supports both hex strings (6-digit RGB and 8-digit RGBA, with or without a leading #) and named colors.

CircleComponent and ImageComponent are drawn centered at their KeyFrame position. RectangleComponent uses its own "x" and "y" fields as a local offset applied via setPosition, drawing from the top-left. TextComponent draws from the top-left corner.

Child components in a CompositeComponent are drawn relative to their parent by accumulating transforms through sf::RenderStates. The parent's keyframe transform is applied to states first, then each child's own transform is applied on top, so children are positioned in the parent's local coordinate space.

#### Part b

### Memory

All components are stored on the heap and all smart pointers, specifically they are unique pointers. AniPlayer holds a std::unique_ptr<Component> to store the type of Component being used. CompositeComponent holds a std::vector<std::unique_ptr<Component>> for its children. There are no dangling pointers anywhere in the code, so there are no memory leaks because the pointers are deallocated after the program finishes running.

### Issues
What did you have trouble with?  What did you learn?  What doesn't work?  Be honest.  You might be penalized if you claim something works and it doesn't.

There were issues initially when it came to understanding how JSON files are read and used. Especially when designing the different Component classes we had vauge ideas from the instuctions on how the JSON was supposed to be structured so we could parse through it, but after a while it clicked and we were able to overcome that issue. 

As is the Static Animation Player does not have any errors and eveyrthing works as intended.

### Extra Credit

Background music: reads the optional "bgm" field from the top-level JSON or any component and plays it using sf::Music. Silently ignored if the field is absent or the file cannot be opened.

Named colors: parseColor supports SFML basic colors

## Pair Programming
Working with a partner helped divide the work as one person focused on the components hierarchy and constructors while the other handled JSON parsing and the keyframe transform logic rendering. We gave code review between each others to solve on bugs.

## Acknowledgements
List all sources of help including the instructor or TAs, classmates, and web pages.
If you used images or other resources than the ones provided, list them here.

Kenney Shape Characters (CC0): https://kenney.nl/assets/shape-characters
"Morning Mood" By Edvard Grieg, performed by Musopen Symphony Orchestra (CC-PDM): https://en.wikipedia.org/wiki/Morning_Mood
Roboto font by Christian Robertson (SIL Open Font License): https://fonts.google.com/specimen/Roboto/license
SFML 3.0.2 Documentation Page: https://www.sfml-dev.org/documentation/3.0.2/