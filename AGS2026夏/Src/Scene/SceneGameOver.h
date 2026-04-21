#pragma once
#include "SceneBase.h"

class SceneGameOver : public SceneBase
{
public:
	SceneGameOver();
	~SceneGameOver();

	void Init(void) override;
	void Update(void) override;
	void Draw(void) override;

private:
	int gameOver_;
};

