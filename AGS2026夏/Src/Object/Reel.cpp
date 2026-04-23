#include "Reel.h"

Reel::Reel()
{
	symbols_ =
	{
		"リプレイ",
		"ベル",
		"弱チェリー",
		"強チェリー",
		"弱スイカ",
		"強スイカ",
		"ハズレ"
	};

	pos_ = 0;
}

Reel::~Reel()
{
}

void Reel::Spin()
{
	pos_++;
	if (pos_ >= symbols_.size())
	{
		pos_ = 0;
	}
}

void Reel::Stop(int index)
{
	if (index >= 0 && index < symbols_.size())
	{
		pos_ = index;
	}
}

std::string Reel::getSymbol()
{
	return symbols_[pos_];
}

int Reel::findSymbolIndex(const std::string& target)
{
	for (int i = 0; i < symbols_.size(); i++) 
	{
		if (symbols_[i] == target)
		{
			return i;
		}
	}
	return 0; // 見つからない場合
}
