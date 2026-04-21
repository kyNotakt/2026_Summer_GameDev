#pragma once
#include "SceneBase.h"

class SceneTutorial : public SceneBase
{
public:
	SceneTutorial();
	~SceneTutorial();

	void Init(void) override;
	void Update(void) override;
	void Draw(void) override;
};