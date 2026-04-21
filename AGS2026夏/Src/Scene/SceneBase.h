#pragma once
#include "../Application.h"
class ResourceManager;

class SceneBase
{

public:

	// コンストラクタ
	SceneBase(void);

	// デストラクタ
	virtual ~SceneBase(void) = 0;

	// 初期化処理
	virtual void Init(void) = 0;

	// 更新ステップ
	virtual void Update(void) = 0;

	// 描画処理
	virtual void Draw(void) = 0;



protected:

	// リソース管理
	ResourceManager& resMng_;

	// ボタン範囲
	const int buttonWidth = 300;
	const int buttonHeight = 60;
	const int centerX = Application::SCREEN_SIZE_X / 2;
	const int startY = Application::SCREEN_SIZE_Y / 2+150;
	const int spacing = 80;

	int selectedId_;// 選択中の項目
	int waitFrame_;//　待ちフレーム

};