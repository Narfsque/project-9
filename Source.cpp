#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    const string imgPath = "D:/25.11.6563/materi/dragon/dragon/";
    const int totalFrames = 9;
    sf::Texture textures[9];
    sf::Sprite sprite;

    sf::RenderWindow window(sf::VideoMode(800, 600), "Animasi Naga Terbang");

    for (int i = 0; i < 9; i++)
    {
        string file = imgPath + to_string(i) + ".png";
        if (!textures[i].loadFromFile(file))
        {
            cout << "Error: " << file << endl;
            return 1;
        }
        cout << "Loaded: " << file << endl;
    }

    int frame = 0;
    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed) window.close();

        window.clear(sf::Color::White);

        sprite.setTexture(textures[frame]);
        sprite.setPosition(350, 250);  // Tengah
        window.draw(sprite);

        if (clock.getElapsedTime().asSeconds() >= 0.1f)
        {
            frame = (frame + 1) % 9;
            clock.restart();
        }

        window.display();
    }

    return 0;
}