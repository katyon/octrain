#pragma once
// �萔 ----------------------------------------------------------------

// �N���X --------------------------------------------------------------
class RESULT
{
public:
    int state = 0;
    int timer = 0;
    int bgHND = 0;
};

// �v���g�^�C�v�錾 -----------------------------------------------------
void result_init(void);      // �����ݒ�
void result_update(void);    // �X�V����
void result_draw(void);      // �`�揈��
void result_end(void);       // �I������