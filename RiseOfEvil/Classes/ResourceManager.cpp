#include "ResourceManager.h"

ResourceManager *ResourceManager::s_instance = nullptr;
ResourceManager::ResourceManager()
{
}

ResourceManager::~ResourceManager()
{
}

ResourceManager * ResourceManager::GetInstance()
{
	if (!s_instance)
	{
		s_instance = new ResourceManager();
	}
	return s_instance;
}

void ResourceManager::Init()
{
	Load("res/Data.bin");
}

void ResourceManager::Load(string fileName)
{
	auto content = FileUtils::getInstance()->getStringFromFile(fileName);
	//f.open(fileName);
	istringstream f(content);
	string off;
	int i;
	f >> off;
	f >> i;
	for (register int s = 0; s < i; s++)
	{
		int index;
		string pathSprite;
		f >> off;
		f >> index;
		f >> off;
		f >> pathSprite;
		//auto pinfo = AutoPolygon::generatePolygon(pathSprite);
		auto sp = Sprite::create(pathSprite);
		sp->retain();
		m_sprites.insert(pair<int, Sprite*>(index, sp));
	}
	f >> off;
	f >> i;
	for (register int b = 0; b < i; b++)
	{
		int index;
		string pathButtonNormal;
		string pathButtonPressed;
		f >> off;
		f >> index;
		f >> off;
		f >> pathButtonNormal;
		f >> off;
		f >> pathButtonPressed;
		ui::Button *bt = ui::Button::create(pathButtonNormal, pathButtonPressed);
		bt->retain();
		m_buttons.insert(pair<int, ui::Button*>(index, bt));
	}
	f >> off;
	f >> i;
	for (register int l = 0; l < i; l++)
	{
		int index;
		string pathFont;
		f >> off;
		f >> index;
		f >> off;
		f >> pathFont;
		Label *lb = Label::createWithTTF("", pathFont, 35);
		lb->retain();
		m_labels.insert(pair<int, Label*>(index, lb));
	}
}

Sprite * ResourceManager::GetSpriteById(int id)
{
	return m_sprites[id];
}

ui::Button * ResourceManager::GetButtonById(int id)
{
	return m_buttons.at(id);
}

Label * ResourceManager::GetLabelById(int id)
{
	return m_labels.at(id);
}

Sprite * ResourceManager::DuplicateSprite(Sprite *sprite)
{
	Sprite* pRet = Sprite::createWithTexture(sprite->getTexture());
	if (sprite->getChildrenCount() > 0)
	{
		for (int child = 0; child < sprite->getChildrenCount(); child++)
		{
			Sprite* spriteChild = (Sprite*)sprite->getChildren().at(child);
			Sprite* clone = DuplicateSprite((Sprite*)spriteChild);
			clone->boundingBox() = spriteChild->boundingBox();
			clone->setContentSize(spriteChild->getContentSize());
			clone->setPosition(spriteChild->getPosition());
			clone->setAnchorPoint(spriteChild->getAnchorPoint());
			pRet->addChild(clone, spriteChild->getZOrder(), spriteChild->getTag());
		}
	}
	return pRet;
}
