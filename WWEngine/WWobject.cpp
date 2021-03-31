#include"WWobject.h"
WWobject::WWobject()
{
	//需要在游戏导演模块进行注册
	/////
}

void WWobject::WWover()
{
}



void WWobject::deleteAll()
{
	
}

WWmoduleBase* WWobject::findModule(WWmoduleBase* module)
{
	for (auto it = WWmodules.begin(); it != WWmodules.end(); it++)
	{
		if (*it = module)
		{
			return *it;
		}
	}
#ifdef _DEBUG
	WWDEBUG("在对象中未找到该组件");
#endif
	return NULL;
	
}

void WWobject::AddModule(WWmoduleBase *module)
{
	WWmodules.push_back(module);
}

void WWobject::RemoveModule(WWmoduleBase* module)
{
	for (auto it = WWmodules.begin(); it!=WWmodules.end() ; it++)
	{
		if (*it == module)
		{
			WWmodules.erase(it);
			return;
		}
	}
#ifdef _DEBUG
	WWDEBUG("不存在该组件，无法删除");
#endif
	
}

void WWobject::SetModuleActive(WWmoduleBase *module,WWSEL sel)
{
	WWmoduleBase* tmp = findModule(module);
	if (tmp != NULL)
	{
		tmp->SetModuleActivity(sel);
		return;
	}
#ifdef _DEBUG
	WWDEBUG("未找到该组件");
#endif
}

void WWobject::SetObjectActive(WWSEL sel)
{
	WWactivity = sel;
}

void WWobject::update()
{
	if (!WWactivity) return;
	for (auto it = WWchildObject.begin(); it != WWchildObject.end(); it++)
	{
		(*it)->update();
	}
	for (auto it = WWmodules.begin(); it != WWmodules.end(); it++)
	{
		(*it)->update();
	}
}

void WWobject::saveObject(FILE* fp)
{
	fprintf(fp, "%d ", WWobjectID);
	for (auto it = WWchildObject.begin(); it != WWchildObject.end(); it++)
	{
		(*it)->saveObject(fp);
		fprintf(fp, "end");
	}
	
}

void WWobject::saveModule(FILE* fp)
{
	for (auto it : WWmodules)
	{
		it->save(fp);
	}
}

void WWobject::load(FILE* fp)
{
}

void WWobject::init(FILE* fp)
{
}

WWmoduleBase* WWobject::WWgetMoudule(WWSTR modulename)
{
	return nullptr;
}

