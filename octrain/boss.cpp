// �C���N���[�h -------------------------------------------------------------------------------------
#include "DxLib.h"

#include "common.h"
#include "input.h"
#include "boss.h"

// �ϐ� --------------------------------------------------------------------------------------------

// �C���X�^���X�錾 ---------------------------------------------------------------------------------
BOSS boss;

// �֐����� ----------------------------------------------------------------------------------------
// �����ݒ�
void BOSS::init(void)
{

}

// �X�V����
void BOSS::update(void)
{

}

// �`�揈��
void BOSS::draw(void)
{
    DrawExtendGraph(boss.bs_posX, boss.bs_posY, boss.bs_subposX, boss.bs_subposY, boss.bsHND, true);
}

// �I������
void BOSS::end(void)
{
    DeleteGraph(boss.bsHND);
}

