#pragma once
// �萔 ----------------------------------------------------------------

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
    int timer = 0;
    int pl_posX = 0;
    int pl_posY = 0;
    int pl_subposX = 0; // player�̉E���̍��W
    int pl_subposY = 0;
    int pl_speed = 0;
    int plHND = 0;
};