#pragma once
#include <vector>
#include <string>

class Reel
{
public:
	Reel();
	~Reel();

	void Spin();
	void Stop(int index);
	std::string getSymbol();
	int findSymbolIndex(const std::string& target);

private:
	std::vector<std::string> symbols_;
	int pos_;
};