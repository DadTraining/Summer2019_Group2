#include "Wave.h"

Wave::Wave(int stage)
{
	m_stage = stage;
	Load();
}

Wave::~Wave()
{
}

void Wave::Load()
{
	auto finalWaveInfo = FileUtils::getInstance()->getStringFromFile("finalWave.bin");
	istringstream finalWave(finalWaveInfo);
	int sizeOfWave;
	int typeOfMonster;
	finalWave >> sizeOfWave;
	for (int i = 0; i < sizeOfWave; i++)
	{
		finalWave >> typeOfMonster;
		finalWaveeInfo.push_back(typeOfMonster);
	}
	auto content = FileUtils::getInstance()->getStringFromFile("Stage"+to_string(m_stage)+"Info.bin");
	istringstream f(content);
	int size;
	int type;
	f >> road1;
	f >> road2;
	f >> size;
	for (int i = 0; i < size; i++) {
		f >> type;
		Wave1.push_back(type);
	}
	f >> size;
	for (int i = 0; i < size; i++) {
		f >> type;
		Wave2.push_back(type);
	}
	f >> size;
	for (int i = 0; i < size; i++) {
		f >> type;
		Wave3.push_back(type);
	}
	f >> size;
	for (int i = 0; i < size; i++) {
		f >> type;
		Wave4.push_back(type);
	}
	f >> size;
	for (int i = 0; i < size; i++) {
		f >> type;
		Wave5.push_back(type);
	}
	f >> size;
	for (int i = 0; i < size; i++)
	{
		f >> type;
		Wave6.push_back(type);
	}
	f >> size;
	for (int i = 0; i < size; i++)
	{
		f >> type;
		Wave7.push_back(type);
	}
	f >> size;
	for (int i = 0; i < size; i++)
	{
		f >> type;
		Wave8.push_back(type);
	}
}

vector<int> Wave::getWave(int numOfWave)
{
	switch (numOfWave)
	{
	case 1:
		return Wave1;
		break;
	case 2:
		return Wave2;
		break;
	case 3:
		return Wave3;
		break;
	case 4:
		return Wave4;
		break;
	case 5:
		return Wave5;
		break;
	case 6:
		return Wave6;
		break;
	case 7:
		return Wave7;
		break;
	case 8:
		return Wave8;
		break;
	case 10:
		return finalWaveeInfo;
		break;
	default:
		break;
	}
}

int Wave::getRoad1TotalPoint()
{
	return road1;
}

int Wave::getRoad2TotalPoint()
{
	return road2;
}
