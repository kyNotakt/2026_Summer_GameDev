#include <DxLib.h>
#include "../Manager/InputManager.h"
#include "../Manager/SceneManager.h"
#include "SceneTutorial.h"

SceneTutorial::SceneTutorial()
{
}

SceneTutorial::~SceneTutorial()
{
}

void SceneTutorial::Init(void)
{
}

void SceneTutorial::Update(void)
{
	InputManager& ins = InputManager::GetInstance();
	if (ins.IsTrgDown(KEY_INPUT_RETURN))
	{
		SceneManager::GetInstance().ChangeScene(SceneManager::SCENE_ID::GAME);
	}
}

void SceneTutorial::Draw(void)
{
	DrawString(10, 10, "sceneTutorial", 0xffffff, true);
}
