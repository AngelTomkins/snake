#pragma once

#include <cstdint>
namespace snake{
class genericObj{
public:
    uint8_t x, y {10};

    genericObj() : x(10), y(10) {}
    genericObj(uint8_t p_x, uint8_t p_y) : x(p_x), y(p_y){}
};

class controller : public genericObj{
public:
    unsigned char dir {'R'};

    controller() {}
    controller(uint8_t p_x, uint8_t p_y) : genericObj{p_x, p_y} {}
    controller(uint8_t p_x, uint8_t p_y, unsigned char p_dir) : genericObj{p_x, p_y}, dir(p_dir) {}

};
}