#include "Wave.h"

Wave::Wave()
{
	Load();
}

Wave::~Wave()
{
}

void Wave::Load()
{
	auto content = FileUtils::getInstance()->getStringFromFile("Stage1Info.bin");
	istringstream f(content);
	int size;
	int type;
	f >> size;
	for (int i = 0; i < size; i++) {
		f >> type;
		Wave1.push_back(type);
	}
}

vector<int> Wave::getWave(int numOfWave)
{
	switch (numOfWave)
	{
	case 1:
		return Wave1;
		break;
	}
	return Wave1;
}