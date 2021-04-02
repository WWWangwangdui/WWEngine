#pragma once
#include"WWtype.h"
#include"WWmoduleBase.h"
class WWtransform: 
	public WWmoduleBase
{
private:
	///坐标
	WWINT WWposX, WWposY;
	//旋转
	WWINT WWrotate;
	//缩放
	WWFLOAT WWscaleX, WWscaleY;
	//跟随相机比例
	WWFLOAT WWfollowrate;
	//是否跟随相机
	WWBOOL WWfollow;
public:
	/// <summary>
	/// 构造函数 x，y坐标（0，0） 角度0 比例100%
	/// </summary>
	WWtransform();
	/// <summary>
	/// 修改坐标
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	void WWsetPoint(WWINT x,WWINT y);
	/// <summary>
	/// 获取坐标
	/// </summary>
	/// <returns></returns>
	WWPT WWgetPos();
	/// <summary>
	/// 获取比例
	/// </summary>
	/// <returns></returns>
	WWPTF WWgetScale();
	/// <summary>
	/// 获取旋转角度
	/// </summary>
	/// <returns></returns>
	WWINT WWgetRotate();
	/// <summary>
	/// 修改角度
	/// </summary>
	/// <param name="angle"></param>
	void WWsetRotate(WWINT angle);
	/// <summary>
	/// 修改比例
	/// </summary>
	/// <param name="ratio"></param>
	void WWsetScale(WWFLOAT scaleX, WWFLOAT scaleY);
	/// <summary>
	/// 给当前组件加一个位移向量
	/// </summary>
	/// <param name="dx">向量的第一维（横坐标）</param>
	/// <param name="dy">向量的第二维（纵坐标）</param>
	void WWmove(WWINT dx, WWINT dy);
	/// <summary>
	/// 初始化
	/// </summary>
	/// <param name="moduleID">组件ID编号</param>
	/// <param name="modulename">组件名</param>
	void WWinit();
	/// <summary>
	/// 存储
	/// </summary>
	/// <param name="p">文件</param>
	void WWsave(FILE* fp);
	/// <summary>
	/// 更新
	/// </summary>
	void WWupdate();
	/// <summary>
	/// 加载存储
	/// </summary>
	/// <param name="f">文件</param>
	void WWload(FILE* fp);
	/// <summary>
	/// 获取组件跟随相机的跟随值
	/// </summary>
	/// <returns></returns>
	WWFLOAT WWgetFollowRate();
};

