/// <summary>
/// 文件名称：组件基类
/// 创建时间：2021/3/28/17:00
/// 创建人：张炷俊
/// 最后更新时间：3/31
/// 文档描述：此类为组件基类，之后所有组件都会从此派生
/// </summary>
#pragma once
#include"WWtype.h"
class WWmoduleBase
{
protected:
	//组件ID编号
	WWINT WWmoduleID;
	//组件活动性 WW_SEL_ACTIVE活动 WW_SEL_SLEEP睡眠
	WWINT WWactivity;
	//组件名
	std::string WWmoduleName;
public:
	/// <summary>
	/// 初始化
	/// </summary>
	/// <param name="p">文件</param>
	void virtual WWinit() = 0;
	/// <summary>
	/// 存储
	/// </summary>
	/// <param name="p">文件</param>
	void virtual WWsave(FILE* p) = 0;
	/// <summary>
	/// 更新
	/// </summary>
	void virtual WWupdate() = 0;
	/// <summary>
	/// 加载存储
	/// </summary>
	/// <param name="p">文件</param>
	void virtual WWload(FILE* p) = 0;
	/// <summary>
	/// 修改该组件是否启用;
	/// </summary>
	/// <param name="sel">sel=WW_SEL_ACTIVE 活动 sel=WW_SEL_SLEEP睡眠</param>
	void WWsetModuleActivity(WWSEL sel);
	/// <summary>
	/// 得到组件的ID
	/// </summary>
	/// <returns>ID编号</returns>
	WWINT WWgetModuleID();
	/// <summary>
	/// 得到组件名
	/// </summary>
	/// <returns></returns>
	std::string& WWgetModuleName();
	/// <summary>
	/// 判断该组件名是否是此组件
	/// </summary>
	/// <param name="modulename">组件名</param>
	/// <returns>组件与组件名对应返回1 反之返回0</returns>
	WWBOOL WWfindModule(std::string modulename);

};