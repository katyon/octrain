#pragma once
// �萔 ----------------------------------------------------------------
#include "shot.h"

enum LEVEL
{
    LEVEL1,
    LEVEL2,
    LEVEL3,
    LEVEL4,
    LEVEL5,
    LEVEL6,
};

// �N���X --------------------------------------------------------------
class GAME
{
public:
    static int state;
    static int timer;
    static int spriteHND;
    static bool zoom_mode;  // true�ŃY�[��

    static int tutorial_lv;

    static void init(void);      // �����ݒ�
    static void game_init(void);
    static void update(void);    // �X�V����
    static void draw(void);      // �`�揈��
    static void end(void);       // �I������
    static bool hitcheck_rect(float ax, float ay, int aw, int ah, float bx, float by, int bw, int bh);
    static bool hitcheck_circle(float ax, float ay, int ar, float bx, float by, int br);
    static bool hitcheck_circle_withrect(float ax, float ay, int ar, float bx, float by, int bw, int bh);

private:
    int bgHND = 0;
    int zoomHND = 0;
    int efHND = 0;

    static int bgmHND;
    static int clearHND0;
    static int gameoverHND;


    static int decision_seHND; //���艹
    static int select_seHND;

    static int damage_seHND;
    static int shot_attackHND;
};