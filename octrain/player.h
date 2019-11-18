#pragma once
// �萔 ----------------------------------------------------------------
#define PL_WIDTH    (240)
#define PL_HEIGHT   (332)

// �N���X --------------------------------------------------------------
class PLAYER
{
public:
    static void init(void);      // �����ݒ�
    static void update(void);    // �X�V����
    static void draw(void);      // �`�揈��
    static void end(void);       // �I������

private:
    int state = 0;
    float posX = 0;
    float posY = 0;
    float sub_posX = 0; // player�̉E���̍��W
    float sub_posY = 0;
    float pivot_posX = 0; // player�̒��S���W
    float pivot_posY = 0;
    float speed = 0;
    int init_hp = 0;
    int hp = 0;
    int sub_hp = 0;
    int init_bullet = 0;
    int bullet = 0;
    int power = 0;
    int plHND[4] = { 0 };
    int bulletHND = 0;
    int hpHND = 0;
    int sub_hpHND = 0;
    int zoomHND = 0;
};