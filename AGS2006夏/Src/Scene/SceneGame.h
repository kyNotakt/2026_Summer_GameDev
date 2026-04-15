#pragma once
#include "SceneBase.h"
class SceneGame:public SceneBase
{
public:
	SceneGame();
	~SceneGame();

	void Init(void) override;
	void Update(void) override;
	void Draw(void) override;
};

