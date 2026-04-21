#pragma once
#include "SceneBase.h"

class SceneGameClear : public SceneBase
{
public:
	SceneGameClear();
	~SceneGameClear();

	void Init(void) override;
	void Update(void) override;
	void Draw(void) override;

private:
	int gameClear_;
};

