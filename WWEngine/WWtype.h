/// <summary>
/// 文件名称: WWtype.h
/// 创建时间：2021/3/26
/// 创建人：	赵霄
/// 最后更新时间：2021/3/26
/// 文档描述：对所有类型的头文件集中包含
/// </summary>
#pragma once
#include"WWdefine.h"
/// <summary>
/// 定义一个位图
/// </summary>
struct WWBitmap
{
	//位图的源地址
	WWBIT bitsrc;
	//该位图位于源位图上的位置
	WWPT offpos;
	//该位图的大小
	WWPT size;
};
/// <summary>
/// 定义一个动画
/// </summary>
struct WWAnimation
{
	//位图的源地址
	WWBIT bitsrc;
	//动画第一帧位于源位图上的位置
	WWPT offpos;
	//动画的大小
	WWPT size;
	//动画总帧数
	WWINT frameCnt;
	//两帧之间的间隔时间
	WWTIME frameTime;
	//重复标记，该值为true则动画循环播放，否则仅播放一次
	WWBOOL cycle;
	//上一帧显示的时间
	WWTIME lastFrame;
	
};
/// <summary>
/// 定义一个用于绘制的文本段
/// </summary>
struct WWText
{
	//文本段对应的字符串
	WWSTR str;
	//文本段的字体
	WWSTR font;
	//文本段用的字体大小
	WWFLOAT size;
	//文本的颜色 
	WWCOLOR col;
};
/// <summary>
/// 定义一个图元，包括直线、椭圆、矩形
/// </summary>
struct WWGraph
{
	//对于直线，该点为起点；对于椭圆，该点为圆心；对于矩形，该点为左上角坐标
	WWPT pt1;
	//对于直线，改单为终点；对于椭圆，该点的x坐标为宽度，y坐标为高度；对于矩形，该点为右下角坐标
	WWPT pt2;
	//该图元的类型
	WWSEL type;
	//该图元的颜色
	WWCOLOR col;
	//该图元的线宽
	WWINT wide;
	//该图元是否需要填充
	WWBOOL fill;
};
/// <summary>
/// 定义一个小数点
/// </summary>
struct WWPTF
{
	//横坐标
	WWFLOAT x;
	//纵坐标
	WWFLOAT y;
};
/// <summary>
/// 定义一个键盘消息的计时器
/// </summary>
struct WWkeyTimer
{
	//键码
	WWINT keyID;
	//单击或者双击
	WWINT clickTime;
	//计时时间
	WWDB ti;
	//重载小于号，按时间排序
	bool operator<(const WWkeyTimer& A)const
	{
		return ti > A.ti;
	}
};