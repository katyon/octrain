#pragma once
// �萔 ----------------------------------------------------------------
#include "shot.h"

// �N���X --------------------------------------------------------------
class GAME
{
public:
    static int timer;
    static int spriteHND;
    static bool zoom_mode;  // true�ŃY�[��

    static void init(void);      // �����ݒ�
    static void update(void);    // �X�V����
    static void draw(void);      // �`�揈��
    static void end(void);       // �I������
    static bool hitcheck_rect(float ax, float ay, int aw, int ah, float bx, float by, int bw, int bh);
    static bool hitcheck_circle(float ax, float ay, int ar, float bx, float by, int br);

private:
    int state = 0;
    int bgHND = 0;
    int zoomHND = 0;
};