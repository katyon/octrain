#pragma once

#define PL_BULLET_MAX   (256)
#define PL_BULLET_SPEED (20)
#define BOSS_BULLET_MAX (256)


class BULLET //’e
{
public:
    void init(BULLET* p);       // ‰Šúİ’è
    void pl_update(BULLET* p);  // XVˆ—
    void pl_draw(BULLET* p);    // •`‰æˆ—
    void boss_updete(BULLET* p, int pattern_num);
    void boss_draw(BULLET* p, int pattern_num);
    void end(BULLET* p);        // I—¹ˆ—
    int get_posX(BULLET* p);
    int get_posY(BULLET* p);
    bool get_pl_exist(BULLET* p);
    bool get_boss_exist(BULLET* p);
    void set_pl_exist(BULLET* p, bool b);
    void set_boss_exist(BULLET* p, bool b);

private:
    int state = 0;
    float posX = 0;
    float posY = 0;
    float speed = 0;
    int range = 0;
    int angle = 0;
    int angle_speed = 0;
    float fsin[360] = { 0 };
    float fcos[360] = { 0 };
    bool pl_exist = false;
    bool boss_exist = false;
    bool reverse_buf = false;

};