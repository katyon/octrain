#pragma once
// �萔 ----------------------------------------------------------------

// �N���X --------------------------------------------------------------
class GAME
{
public:
    static void init(void);      // �����ݒ�
    static void update(void);    // �X�V����
    static void draw(void);      // �`�揈��
    static void end(void);       // �I������

private:
    int state = 0;
    int timer = 0;
    int bgHND = 0;
    int brackHND = 0;
};