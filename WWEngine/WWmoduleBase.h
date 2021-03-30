/// <summary>
/// 文件名称：组件基类
/// 创建时间：2021/3/28/17:00
/// 创建人：张炷俊
/// 最后更新时间：3/29/23:30
/// 文档描述：此类为组件基类，之后所有组件都会从此派生
/// </summary>
#pragma once
#include<fstream>
#include "WWdefine.h"
class WWmoduleBase
{
private:
	WWINT WWmoduleID;
	WWBOOL WWactivity;
public:
	//初始化
	void virtual init(FILE *p) = 0;
	//存储
	void virtual save(FILE* p) = 0;
	//更新响应
	void virtual update() = 0;
	//加载存储
	void virtual load(FILE* p) = 0;
	/// <summary>
	/// 修改该组件是否启用;
	/// </summary>
	/// <param name="sel">sel=3 启用 sel=4 关闭不启用</param>
	void SetModuleActivity(WWSEL sel);
	//得到组件的ID
	WWINT getMoudulceID();
};