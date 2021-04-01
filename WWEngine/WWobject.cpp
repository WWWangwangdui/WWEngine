#include"WWobject.h"
WWobject::WWobject()
{
	//需要在游戏导演模块进行注册
	/////
}

void WWobject::WWover()
{
}



void WWobject::WWdeleteAll()
{

}

WWmoduleBase* WWobject::WWfindModule(WWmoduleBase* module)
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

void WWobject::WWaddModule(WWmoduleBase* module)
{
	WWmodules.push_back(module);
}

void WWobject::WWremoveModule(WWmoduleBase* module)
{
	for (auto it = WWmodules.begin(); it != WWmodules.end(); it++)
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

void WWobject::WWremoveModule(WWSTR modulename)
{
	for (auto it = WWmodules.begin(); it != WWmodules.end(); it++)
	{
		if ((*it)->WWgetModuleName() == modulename)
		{
			WWmodules.erase(it);
			return;
		}
	}
#ifdef _DEBUG
	WWDEBUG("不存在该组件，无法删除");
#endif

}

void WWobject::WWsetModuleActive(WWmoduleBase* module, WWSEL sel)
{
	WWmoduleBase* tmp = WWfindModule(module);
	if (tmp != NULL)
	{
		tmp->WWsetModuleActivity(sel);
		return;
	}
#ifdef _DEBUG
	WWDEBUG("未找到该组件");
#endif
}

void WWobject::WWsetObjectActive(WWSEL sel)
{
	WWactivity = sel;
}

void WWobject::WWsetObjectActive(WWSTR modulename, WWSEL sel)
{
	WWmoduleBase* tmp = WWgetMoudule(modulename);
	if (tmp != NULL) tmp->WWsetModuleActivity(sel);
	else
	{
#ifdef _DEBUG
		WWDEBUG("在对象中未找到该组件");
#endif
	}

}

void WWobject::WWupdate()
{
	if (!WWactivity) return;
	for (auto it = WWchildObject.begin(); it != WWchildObject.end(); it++)
	{
		(*it)->WWupdate();
	}
	for (auto it = WWmodules.begin(); it != WWmodules.end(); it++)
	{
		(*it)->WWupdate();
	}
}

void WWobject::WWsaveObject(FILE* fp)
{
	/*fprintf(fp, "%d ", WWobjectID);
	for (auto it = WWchildObject.begin(); it != WWchildObject.end(); it++)
	{
		(*it)->WWsaveObject(fp);
		fprintf(fp, "end");
	}*/

}

void WWobject::WWsaveModule(FILE* fp)
{
	/*for (auto it : WWmodules)
	{
		it->WWsave(fp);
	}*/
}

void WWobject::WWload(FILE* fp)
{
}

void WWobject::WWinit(FILE* fp)
{
}

WWmoduleBase* WWobject::WWgetMoudule(WWSTR modulename)
{
	for (auto it = WWmodules.begin(); it != WWmodules.end(); it++)
	{
		if ((*it)->WWgetModuleName() == modulename)
		{
			return *it;
		}
	}
#ifdef _DEBUG
	WWDEBUG("在对象中未找到该组件");
#endif
	return NULL;
}

