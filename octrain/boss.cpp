// インクルード -------------------------------------------------------------------------------------
#include "DxLib.h"

#include "common.h"
#include "input.h"
#include "boss.h"

// 変数 --------------------------------------------------------------------------------------------

// インスタンス宣言 ---------------------------------------------------------------------------------
BOSS boss;

// 関数実体 ----------------------------------------------------------------------------------------
// 初期設定
void BOSS::init(void)
{

}

// 更新処理
void BOSS::update(void)
{

}

// 描画処理
void BOSS::draw(void)
{
    DrawExtendGraph(boss.bs_posX, boss.bs_posY, boss.bs_subposX, boss.bs_subposY, boss.bsHND, true);
}

// 終了処理
void BOSS::end(void)
{
    DeleteGraph(boss.bsHND);
}

