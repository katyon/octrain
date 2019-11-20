#pragma once
#include <math.h>

struct BULLET //’e
{
private:
    float bullet_posX;
    float bullet_posY;
    float bullet_speed;
    int angle;
    int range;
    float fsin[360];
    float fcos[360];

public:
    static void init(void);      // ‰Šúİ’è
    static void update(void);    // XVˆ—
    static void draw(void);      // •`‰æˆ—
    static void end(void);       // I—¹ˆ—
};