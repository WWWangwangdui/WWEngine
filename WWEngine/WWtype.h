/// <summary>
/// 文件名称: WWtype.h
/// 创建时间：2021/3/26
/// 创建人：	赵霄
/// 最后更新时间：2021/3/26
/// 文档描述：对所有类型的头文件集中包含
/// </summary>
#pragma once
#include<afx.h>
#include"WWdefine.h"
/// <summary>
/// 定义一个位图
/// </summary>
struct WWBitmap
{
	//位图的源地址
	WWBIT* bitsrc;
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
	WWBIT* bitsrc;
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