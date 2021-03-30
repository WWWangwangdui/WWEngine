/// <summary>
/// 文件名称：游戏对象基类
/// 创建时间：2021/3/28/17:00
/// 创建人：张炷俊
/// 最后更新时间：3/29/23:30
/// 文档描述：此类为游戏对象基类，不实现任何功能
/// </summary>
#pragma once
#include<vector>
#include"WWwindow.h"
#include"WWmoduleBase.h"
class WWobject
{
private:
	std::vector<WWmoduleBase*> WWmodules;
	std::vector<WWobject*> WWchildObject;
	WWINT WWobjectID;
	WWBOOL WWactivity;
public:
	//需要游戏导演进行注册
	WWobject();
	//主动要求游戏导演结束对象
	void WWover();

	//释放对象、子对象及组件
	void deleteAll();

	//在对象中查找组件
	WWmoduleBase* findModule(WWmoduleBase* module);
	//添加组件
	void virtual AddModule(WWmoduleBase *module);
	//删除已添加的组件
	void virtual RemoveModule(WWmoduleBase* module);
	/// <summary>
	/// 修改对象中的一个组件是否启用
	/// </summary>
	/// <param name="module">组件名</param>
	/// <param name="sel">sel =3 启用 sel = 4 关闭 不启用</param>
	void SetModuleActive(WWmoduleBase* module,WWSEL sel);
	/// <summary>
	/// 修改整个对象是否启用
	/// </summary>
	/// <param name="sel">sel=3 启用 sel = 4 关闭 不启用</param>
	void SetObjectActive(WWSEL sel);
	//更新函数，更新整个对象、子对对象的组件
	void update();
	//递归存储对象 
	void saveObject(FILE* fp);
	//存储对象的所有组件
	void saveModule(FILE* fp);
	//加载
	void load(FILE* fp);
	//初始化
	void init(FILE* fp);
};