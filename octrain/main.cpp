// �C���N���[�h -------------------------------------------------------------------------------------
#include "DxLib.h"

#include "common.h"
#include "input.h"
#include "player.h"
#include "scene_game.h"
#include "scene_result.h"
#include "scene_title.h"

// �ϐ� --------------------------------------------------------------------------------------------
// �V�[���؂�ւ��p�ϐ�
int curScene;
int nextScene;


// �C���X�^���X�錾 ---------------------------------------------------------------------------------
COMMON common;

// WinMain -----------------------------------------------------------------------------------------
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // �E�C���h�E���[�h�ŋN��
    ChangeWindowMode(TRUE);

    // �t���X�N���[�����[�h�ŋN��
    //ChangeWindowMode(FALSE);

    // �Q�[����ʂ̉𑜓x��ݒ�(32�r�b�g�J���[(�t���J���[))
    SetGraphMode(GAME_SCREEN_WIDTH, GAME_SCREEN_HEIGHT, 32);

    // �w�i������
    SetBackgroundColor(0, 0, 0);

    // �E�C���h�E�̃^�C�g����ݒ�
    SetMainWindowText("test");

    // �u�����h���[�h�̐ݒ�(�m�[�u�����h)
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

    // �Q�[���V�[���̐ݒ�
    curScene = SCENE_TITLE;
    nextScene = SCENE_TITLE;

    // ���C�u�����̏�����
    if (DxLib_Init() < 0)
        return -1;

    // �^�C�g���̏����ݒ�
    title_init();

    // �t�H���g�f�[�^�̓ǂݍ���
    common.font = CreateFontToHandle("GauFontLoveRocketNeo", 70, 1, DX_FONTTYPE_ANTIALIASING);

    // �`���𗠉�ʂɂ���
    SetDrawScreen(DX_SCREEN_BACK);

    // InputClass
    Input::Create();
    Input::GetInstance()->Init();

    // ESC�L�[��������邩�A�E�C���h�E��������܂Ń��[�v
    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        // ��ʂ��N���A
        ClearDrawScreen();

        clsDx();

        // �Q�[���V�[���؂�ւ�
        if (nextScene != curScene)
        {
            // ���V�[���̏I���������s��
#pragma region NowEnd
            switch (curScene)
            {
            case SCENE_TITLE:
                title_end();
                break;
            case SCENE_GAME:
                game_end();
                break;
            case SCENE_RESULT:
                result_end();
                break;
            }
#pragma endregion
            // ���V�[���̏��������s��
#pragma region NextInitialize
            switch (nextScene)
            {
            case SCENE_TITLE:
                title_init();
                break;
            case SCENE_GAME:
                game_init();
                break;
            case SCENE_RESULT:
                result_init();
                break;
            }
#pragma endregion
            curScene = nextScene;
        }

        // ���݂̃V�[���̍X�V����
#pragma region NowUpdate
        switch (curScene)
        {
        case SCENE_TITLE:
            title_update();
            break;
        case SCENE_GAME:
            game_update();
            break;
        case SCENE_RESULT:
            result_update();
            break;
        }
#pragma endregion

        // ���݂̃V�[���̕`�揈��
#pragma region NowDraw
        switch (curScene)
        {
        case SCENE_TITLE:
            title_draw();
            break;
        case SCENE_GAME:
            game_draw();
            break;
        case SCENE_RESULT:
            result_draw();
            break;
        }
#pragma endregion

        // ����ʂ̓��e��\��ʂɔ��f
        ScreenFlip();
    }

    // ���݂̃V�[���̏I������
#pragma region NowEnd
    switch (curScene)
    {
    case SCENE_TITLE:
        title_end();
        break;
    case SCENE_GAME:
        game_end();
        break;
    case SCENE_RESULT:
        result_end();
        break;
    }
#pragma endregion

    // ���Еt��
    Input::Destroy();

    // �S�O���t�B�b�N�̍폜
    DxLib::InitGraph();

    // �S���f�[�^�̍폜
    InitSoundMem();

    // ���C�u�����̏I������
    DxLib::DxLib_End();

    // �\�t�g�I��
    return 0;
}