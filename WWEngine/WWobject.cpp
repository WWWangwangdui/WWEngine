#include"WWobject.h"
#include"WWmoduleBase.h"
#include"WWwindow.h"
WWobject::WWobject()
{
	//��Ҫ����Ϸ����ģ�����ע��
	/////
	WWactivity = true;
}

void WWobject::WWover()
{
}



void WWobject::WWdeleteAll()
{

}


void WWobject::WWaddModule(WWmoduleBase* module)
{
	WWmodules.push_back(module);
}


void WWobject::WWremoveModule(const WWCH* modulename)
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
	WWDEBUG("�����ڸ�������޷�ɾ��");
#endif

}

void WWobject::WWsetModuleActive(const WWCH* moduleName, WWSEL sel)
{
	WWmoduleBase* tmp = WWgetMoudule(moduleName);
	if (tmp != NULL)
	{
		tmp->WWsetModuleActivity(sel);
		return;
	}
#ifdef _DEBUG
	WWDEBUG("δ�ҵ������");
#endif
}

void WWobject::WWsetObjectActive(WWSEL sel)
{
	WWactivity = sel;
}

void WWobject::WWsetSonObjectActive(const WWCH* objname, WWSEL sel)
{
	WWobject* tmp = WWgetObj(objname);
	if (tmp != NULL) tmp->WWsetObjectActive(sel);
	else
	{
#ifdef _DEBUG
		WWDEBUG("�ڶ�����δ�ҵ����Ӷ���");
#endif
	}

}

WWINT WWobject::WWgetID()
{
	return WWobjectID;
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

void WWobject::WWinit()
{
}

void WWobject::WWsetID(WWINT id)
{
	WWobjectID = id;
}

bool WWobject::WWgetActivity()
{
	return WWactivity;
}

WWobject* WWobject::WWgetObj(const WWCH* name)
{
	WWINT len = strlen(name);
	if (len == 0)return this;
	WWINT tmp = 0, left = 0;
	if (name[0] == '/')left++;
	for (; left < len; left++)
	{
		if (name[left] == '/')break;
		tmp *= 10;
		tmp += name[left] - '0';
	}
	for (WWobject* it : WWchildObject)
	{
		if (it->WWgetID() == tmp)
		{
			return it->WWgetObj(name + left);
		}
	}
	return nullptr;
}

WWmoduleBase* WWobject::WWgetMoudule(const WWCH* modulename)
{
	for (auto it = WWmodules.begin(); it != WWmodules.end(); it++)
	{
		if ((*it)->WWgetModuleName() == modulename)
		{
			return *it;
		}
	}
#ifdef _DEBUG
	WWDEBUG("�ڶ�����δ�ҵ������");
#endif
	return NULL;
}

