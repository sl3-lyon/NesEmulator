#include "../include/graphics/graphics.h"

void draw_pixel(int x, int y, int color)
{
    draw_pixel(x, y, Color { color });
}

void draw_pixel(int x, int y, Color color)
{
    struct Point {
        int x;
        int y;
        Color color;
    };
    Point point { x, y, color };
    if (point.x < 0 || point.y < 0)
    {
        return;
    }
}
