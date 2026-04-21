#include <DxLib.h>
#include "../Manager/InputManager.h"
#include "../Manager/SceneManager.h"
#include "../Manager/ResourceManager.h"
#include "SceneGameOver.h"

SceneGameOver::SceneGameOver():
	gameOver_(-1)
{
}

SceneGameOver::~SceneGameOver()
{
}

void SceneGameOver::Init(void)
{
	// ゲームオーバー画像の初期化
	gameOver_ = ResourceManager::GetInstance().Load(ResourceManager::SRC::GAME_OVER).handleId_;

	SceneBase::Init();
}

void SceneGameOver::Update(void)
{
	InputManager& ins = InputManager::GetInstance();
	SceneBase::Update();

	// 決定処理
	if (ins.IsTrgDown(KEY_INPUT_RETURN))
	{
		if (selectedId_ == 0)
		{
			SceneManager::GetInstance().ChangeScene(SceneManager::SCENE_ID::TITLE);
		}
		else if (selectedId_ == 1)
		{
			Application::GetInstance().SetEnd(true);
		}
	}
}

void SceneGameOver::Draw(void)
{
	DrawString(10, 10, "sceneGameOver", 0xffffff, true);

	DrawGraph(Application::SCREEN_SIZE_X / 5, 0, gameOver_, true);
	
	const char* labels[2] = { "タイトルへ", "ゲーム終了" };
	for (int i = 0; i < 2; ++i)
	{
		int buttonX = centerX - buttonWidth / 2;
		int buttonY = startY + i * spacing;

		// 選択中ならハイライト付きの枠(三項演算子を使用)
		unsigned int borderColor = (selectedId_ == i) ? GetColor(255, 255, 0) : GetColor(100, 100, 100);
		unsigned int textColor = (selectedId_ == i) ? GetColor(255, 255, 255) : GetColor(180, 180, 180);
		unsigned int fillColor = (selectedId_ == i) ? GetColor(50, 50, 50) : GetColor(30, 30, 30);

		// ボタンの背景と枠
		DrawBox(buttonX, buttonY, buttonX + buttonWidth, buttonY + buttonHeight, fillColor, true);
		DrawBox(buttonX, buttonY, buttonX + buttonWidth, buttonY + buttonHeight, borderColor, false);

		// 文字を中央に描画
		int textWidth = GetDrawStringWidth(labels[i], strlen(labels[i]));
		int textX = centerX - textWidth / 2;
		int textY = buttonY + (buttonHeight - 16) / 2;

		DrawString(textX, textY, labels[i], textColor);
	}
}
