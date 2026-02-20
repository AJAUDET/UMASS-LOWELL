## Author
    Name: AJ Audet
    Section: 204
## Randomizing Sprites
    - The way sprites are chosen is by using the crop window function from TextureView on the textures in order to get this crop the seed will modify the "starting location" for the cropped window 
## Tests
    - The new tests I created center around how the logic for SpriteBuilder works
        - 1st Test: Tests a seeded SpriteBuilder against an identical one and will only pass if they match
        - 2nd Test: Tests unseeded SpriteBuilder against another one using chrono and time_since_epoch to create a random seed value for each instance
        -3rd Test: Checks that the SpriteBuilders do not reroll seeds for the generated sprites
## Credits
    - Spritesheets provided by Keeney under the CC0 License
    - SFML Documentation for 3.0.2 syntax, and how to use sf::Window, sf::RenderStates, sf::RenderTarget in conjunction with a scale value for the sprites
## Sources
    - https://kenney.nl/assets/playing-cards-pack
    - https://kenney.nl/assets/roguelike-characters
    - https://www.sfml-dev.org/documentation/3.0.2/structsf_1_1RenderStates.html
    - https://www.sfml-dev.org/documentation/3.0.2/
    - https://www.sfml-dev.org/documentation/3.0.2/classsf_1_1RenderTarget.html 
    - https://www.sfml-dev.org/documentation/3.0.2/classsf_1_1Window.html
