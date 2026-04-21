#include "../Manager/ResourceManager.h"
#include "../Manager/InputManager.h"
#include "SceneBase.h"

SceneBase::SceneBase(void) :
	resMng_(ResourceManager::GetInstance()), selectedId_(0), waitFrame_(0)
{
}

SceneBase::~SceneBase()
{
}

void SceneBase::Init(void)
{	
	// 選択中項目の初期化
	selectedId_ = 0;

	// 待ちフレームの初期化
	waitFrame_ = 0;
}

void SceneBase::Update(void)
{
	InputManager& ins = InputManager::GetInstance();

	// 入力受付待ち
	if (waitFrame_ < 10)
	{
		waitFrame_++;
		return;
	}

	//選択肢の上下移動処理
	if (ins.IsTrgDown(KEY_INPUT_DOWN))
	{
		selectedId_ = (selectedId_ + 1) % 2;
		waitFrame_ = 0;
	}
	else if (ins.IsTrgDown(KEY_INPUT_UP))
	{
		selectedId_ = (selectedId_ + 1) % 2;
		waitFrame_ = 0;
	}
}

void SceneBase::Draw(void)
{
}