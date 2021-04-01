/// <summary>
/// 文件名称：游戏对象基类
/// 创建时间：2021/3/28/17:00
/// 创建人：张炷俊
/// 最后更新时间：3/31
/// 文档描述：此类为游戏对象基类，不实现任何功能
/// </summary>
#pragma once
#include<afx.h>
#include<vector>
#include"WWwindow.h"
#include"WWmoduleBase.h"
class WWobject
{
private:
	//组件容器
	std::vector<WWmoduleBase*> WWmodules;
	//子对象容器
	std::vector<WWobject*> WWchildObject;
	//对象ID编号
	WWINT WWobjectID;
	//对象活动性 4活动 5睡眠
	WWBOOL WWactivity;
public:
	/// <summary>
	/// 需要游戏导演进行注册
	/// </summary>
	WWobject();
	/// <summary>
	/// 主动要求游戏导演结束对象
	/// </summary>
	void WWover();
	/// <summary>
	/// 释放对象、子对象及组件
	/// </summary>
	void WWdeleteAll();
	/// <summary>
	/// 在对象容器中根据组件查找
	/// </summary>
	/// <param name="module">组件</param>
	/// <returns>组件</returns>
	WWmoduleBase* WWfindModule(WWmoduleBase* module);
	/// <summary>
	/// 通过组件名获取对象中的组件
	/// </summary>
	/// <param name="modulename"></param>
	/// <returns>组件</returns>
	WWmoduleBase* WWgetMoudule(WWSTR modulename);
	/// <summary>
	/// 在对象容器中添加组件
	/// </summary>
	/// <param name="module">组件</param>
	void WWaddModule(WWmoduleBase* module);
	/// <summary>
	/// 删除在对象中已添加的组件
	/// </summary>
	/// <param name="module">组件</param>
	void WWremoveModule(WWmoduleBase* module);
	/// <summary>
	/// 根据组件名删除组件
	/// </summary>
	/// <param name="modulename">组件名</param>
	void WWremoveModule(WWSTR modulename);
	/// <summary>
	/// 修改对象容器中的一个组件是否启用
	/// </summary>
	/// <param name="module">组件名</param>
	/// <param name="sel">sel =4 活动 sel = 5睡眠</param>
	void WWsetModuleActive(WWmoduleBase* module, WWSEL sel);
	/// <summary>
	/// 修改整个对象是否启用
	/// </summary>
	/// <param name="sel">sel=4 活动 sel = 5睡眠</param>
	void WWsetObjectActive(WWSEL sel);

	/// <summary>
	/// 根据组件名来设置该组件的活动性
	/// </summary>
	/// <param name="modulename">组件名</param>
	/// <param name="sel">4 活动 5睡眠</param>
	void WWsetObjectActive(WWSTR modulename, WWSEL sel);



	/// <summary>
	/// 更新函数，更新整个对象、子对对象的组件
	/// </summary>
	void WWupdate();
	/// <summary>
	/// 递归存储对象 
	/// </summary>
	/// <param name="fp">文件</param>
	void WWsaveObject(FILE* fp);
	/// <summary>
	/// 递归存储对象 
	/// </summary>
	/// <param name="fp">文件</param>
	void WWsaveModule(FILE* fp);
	/// <summary>
	/// 加载
	/// </summary>
	/// <param name="fp">文件</param>
	void WWload(FILE* fp);
	/// <summary>
	/// 初始化
	/// </summary>
	/// <param name="fp">文件</param>
	void WWinit(FILE* fp);


};