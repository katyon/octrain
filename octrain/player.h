#pragma once
// �萔 ----------------------------------------------------------------
#define PL_WIDTH    (200)
#define PL_HEIGHT   (300)

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
    int posX = 0;
    int posY = 0;
    int sub_posX = 0; // player�̉E���̍��W
    int sub_posY = 0;
    int speed = 0;
    int plHND[4] = { 0 };
};