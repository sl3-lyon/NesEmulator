#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <algorithm> // std::fill
#include <array>     // std::array
#include <cassert>   // assert
#include <vector>    // std::vector
#include <initializer_list>
#include <SFML/Graphics.hpp> // sf::RenderWindow, sf::Sprite

#include "../tools/NonCopyable.h"

namespace constants {
    const int screen_width  = 256;
    const int screen_height = 240;
} // constants

namespace graphics {
    void init();
    void show();
    void draw(const sf::Sprite& sprite);
} // graphics

namespace colors {
    // TODO - A revoir (palette serait une map<int, int>)
    const std::array<int, 64> palette
    {{
        0x7C7C7C, 0x0000FC, 0x0000BC, 0x4428BC, 0x940084, 0xA80020, 0xA81000, 0x881400,
        0x503000, 0x007800, 0x006800, 0x005800, 0x004058, 0x000000, 0x000000, 0x000000,
        0xBCBCBC, 0x0078F8, 0x0058F8, 0x6844FC, 0xD800CC, 0xE40058, 0xF83800, 0xE45C10,
        0xAC7C00, 0x00B800, 0x00A800, 0x00A844, 0x008888, 0x000000, 0x000000, 0x000000,
        0xF8F8F8, 0x3CBCFC, 0x6888FC, 0x9878F8, 0xF878F8, 0xF85898, 0xF87858, 0xFCA044,
        0xF8B800, 0xB8F818, 0x58D854, 0x58F898, 0x00E8D8, 0x787878, 0x000000, 0x000000,
        0xFCFCFC, 0xA4E4FC, 0xB8B8F8, 0xD8B8F8, 0xF8B8F8, 0xF8A4C0, 0xF0D0B0, 0xFCE0A8,
        0xF8D878, 0xD8F878, 0xB8F8B8, 0xB8F8D8, 0x00FCFC, 0xF8D8F8, 0x000000, 0x000000
    }};
    
    inline std::string getTileCode(unsigned fb, unsigned sb);
} // colors

struct Color : public NonCopyable
{
    Color() : Color(0, 0, 0) {}
    explicit Color(int red, int green, int blue) : r(red), g(green), b(blue) {}
    Color(int color) : r((color >> 16) & 0xff), g((color >> 8) & 0xff), b(color & 0xff) {}
    Color& operator=(const int) = delete;
    int r, g, b;
};

template <int W, int H>
class Matrix : public NonCopyable
{
public:
    Matrix();
    int& operator()(int x, int y);
    int operator()(int x, int y) const;
    inline int width() const;
    inline int height() const;
private:
    int _width;
    int _height;
    std::array<int, W * H> _array;
};

#include "matrix.tpp"

typedef Matrix<constants::screen_width, constants::screen_height> Screen;

#endif // GRAPHICS_H
