#include <DxLib.h>
#include "../Manager/InputManager.h"
#include "../Manager/SceneManager.h"
#include "SceneGame.h"

SceneGame::SceneGame()
{
}

SceneGame::~SceneGame()
{
}

void SceneGame::Init(void)
{
}

void SceneGame::Update(void)
{
	InputManager& ins = InputManager::GetInstance();
	if (ins.IsTrgDown(KEY_INPUT_RETURN))
	{
		SceneManager::GetInstance().ChangeScene(SceneManager::SCENE_ID::RESULT);
	}
}

void SceneGame::Draw(void)
{
	DrawString(10, 10, "sceneGame", 0xffffff, true);
}
