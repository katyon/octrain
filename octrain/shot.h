#pragma once
#include <math.h>

struct BULLET //’e
{
private:
    int bullet_posX;
    int bullet_posY;
    int bullet_subposX;
    int bullet_subposY;
    int bullet_speed;
    int angle;
    int range;
    float fsin[360];
    float fcos[360];
    int bulletHND;

public:
    static void init(void);      // ‰Šúİ’è
    static void update(void);    // XVˆ—
    static void draw(void);      // •`‰æˆ—
    static void end(void);       // I—¹ˆ—
};