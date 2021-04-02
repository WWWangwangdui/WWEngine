#include "WWdirector.h"
#include "WWobject.h"
#include"WWwindow.h"
#include"WWrenderer.h"
WWINT WWdirector::WWlastID;
std::vector<WWobject*>WWdirector::WWobjVec;
std::priority_queue<WWINT, std::vector<WWINT>, std::greater<WWINT>>WWdirector::WWdelVec;
void WWdirector::WWinit()
{
	WWlastID = 1;
}

WWobject* WWdirector::WWfindObj(const WWCH* name)
{
	WWINT len = strlen(name);
	WWINT tmp = 0, left = 0;
	for (; left < len; left++)
	{
		if (name[left] == '/')break;
		tmp *= 10;
		tmp += name[left] - '0';
	}
	if (left >= 9)
	{
		WWDEBUG("查询对象失败，对象编号输入有误，查询路径：");
		WWDEBUG(name);
		WWLOG("查询对象失败，对象编号输入有误，查询路径：");
		WWLOG(name);
		return nullptr;
	}
	for (auto it : WWobjVec)
	{
		if (it->WWgetID() == tmp)
		{
			return it->WWgetObj(name + left);
		}
	}
}

WWmoduleBase* WWdirector::WWfindModule(const WWCH* name)
{
	WWINT len = strlen(name);
	WWINT tmp = 0, left = 0;
	for (; left < len; left++)
	{
		if (name[left] == '/')break;
		tmp *= 10;
		tmp += name[left] - '0';
	}
	if (left >= 9 || left == len)
	{
		WWDEBUG("查询组件失败，对象编号输入有误，查询路径：");
		WWDEBUG(name);
		WWLOG("查询组件失败，对象编号输入有误，查询路径：");
		WWLOG(name);
		return nullptr;
	}
	for (auto it : WWobjVec)
	{
		if (it->WWgetID() == tmp)
		{
			return it->WWgetMoudule(name + left + 1);
		}
	}
}

WWINT WWdirector::WWaddObj()
{
	WWobject* NEW = new WWobject();
	NEW->WWsetID(WWlastID++);
	WWobjVec.push_back(NEW);
	return NEW->WWgetID();
}

void WWdirector::WWdeleteObj(WWINT id)
{
	WWdelVec.push(id);
}

void WWdirector::WWsave()
{

}

void WWdirector::WWload()
{

}

void WWdirector::WWupdate()
{
	for (std::vector<WWobject*>::iterator it = WWobjVec.begin(); it != WWobjVec.end();)
	{
		if (!WWdelVec.empty())
		{
			if ((*it)->WWgetID() == WWdelVec.top())
			{
				(*it)->WWdeleteAll();
				delete (*it);
				it = WWobjVec.erase(it);
				WWdelVec.pop();
				continue;
			}
		}
		if ((*it)->WWgetActivity())
		{
			(*it)->WWupdate();
		}
		it++;
	}
	while (!WWdelVec.empty())WWdelVec.pop();
	WWrenderer::update();
}

void WWdirector::WWuiUpdate()
{
}
