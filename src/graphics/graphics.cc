#include "graphics.h"

#include <bitset>    // std::bitset
#include <exception>
#include <iostream>
#include <thread>
#include <string>    // std::string
#include <vector>

sf::RenderWindow *window;
std::thread main_thread;

/*
 * TODO - 1. Charger liste de sprites à la lecture de la ROM (+ attribuer un ID à chaque sprite)
 *        2. Afficher le sprite correspondant selon l'opcode
 */

namespace color {

    inline std::string getTileCode(unsigned fb, unsigned sb)
    {
        auto firstByte = std::bitset<8>(fb).to_string();
        auto secondByte = std::bitset<8>(sb).to_string();
        std::string code;
        for (unsigned i{}; i < 8; i++)
        {
            if (firstByte[i] == '1' && secondByte[i] == '0')
            {
                code += "1";
            }
            else if (secondByte[i] == '1' && firstByte[i] == '0') {
                code += "2";
            }
            else {
                code += "3";
            }
        }
        return std::string(code.rbegin(), code.rend());
    }

}
void graphics::show()
{
    // TEST
    sf::Texture texture;
    texture.loadFromFile("sfml.png");
    sf::Sprite sprite(texture);
    sprite.setPosition(sf::Vector2f(10.f, 10.f));
    std::vector<sf::Sprite> sprites { sprite };
    const auto video_mode = sf::VideoMode(constants::screen_width * 2, constants::screen_height * 2);
    sf::RenderWindow w(video_mode, "NES Emulator", sf::Style::Close);
    window = &w;
    // FIN TEST
    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window->close();
                return;
            }
        }
        for (const auto& s : sprites)
        {
            window->draw(s);
        }
        window->display();
        window->clear();
    }
}

