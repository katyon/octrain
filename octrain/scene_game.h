#pragma once
// �萔 ----------------------------------------------------------------

// �N���X --------------------------------------------------------------
class GAME
{
public:
    static int timer;

    static void init(void);      // �����ݒ�
    static void update(void);    // �X�V����
    static void draw(void);      // �`�揈��
    static void end(void);       // �I������
    static bool hitcheck_rect(int ax, int ay, int aw, int ah, int bx, int by, int bw, int bh);
    static bool hitcheck_circle(int ax, int ay, int ar, int bx, int by, int br);

private:
    int state = 0;
    int bgHND = 0;
};