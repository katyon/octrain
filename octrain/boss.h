#pragma once
// �萔 ----------------------------------------------------------------

// �N���X --------------------------------------------------------------
class BOSS
{
private:
    int state = 0;
    int timer = 0;
    int bs_posX = 0;
    int bs_posY = 0;
    int bs_subposX = 0; // player�̉E���̍��W
    int bs_subposY = 0;
    int bs_speed = 0;
    int bsHND = 0;

public:
    static void init(void);      // �����ݒ�
    static void update(void);    // �X�V����
    static void draw(void);      // �`�揈��
    static void end(void);       // �I������

    //static void shot(int shot_posX, int shot_posY);

};