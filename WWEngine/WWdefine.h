/// <summary>
/// 文件名称: WWdefine.h
/// 创建时间：2021/3/26
/// 创建人：	赵霄
/// 最后更新时间：2021/3/26
/// 文档描述：引擎中所有宏定义，数据类型重命名以及结构体的定义
/// </summary>
#pragma once
#include"WWwindow.h"
/*******************************************************************************************
以下代码块进行宏定义，注意格式
#define NAME			VALUE			//COMMENT
*******************************************************************************************/
#define WW_ESC			0				//ESC键的内部键码

#define WW_SEL_W		0				//宽度
#define WW_SEL_H		1				//高度
#define WW_SEL_X		2				//横坐标
#define WW_SEL_Y		3				//纵坐标
#define WW_SEL_ACTIVE	4				//处于活动状态
#define WW_SEL_SLEEP	5				//处于睡眠状态（非活动状态）



/*******************************************************************************************
以下代码块进行长宏定义
*******************************************************************************************/
#ifdef _DEBUG

#define WWDEBUG(x) WWframe::debug(__FILE__,__LINE__,x)	
#define WWERROR(x) WWframe::error(__FILE__,__LINE__,x)	
#define WWLOG(x) WWframe::WWlog(__FILE__,__LINE__,x)
#define WWNEWLINE WWframe::WWlogNewLine()

#endif // _DEBUG



/*******************************************************************************************
以下代码块进行结构体数据的定义
*******************************************************************************************/

/*******************************************************************************************
以下代码块进行数据类型重命名，注意格式
typedef	SRCNAME		NEWNAME			；		//COMMENT
*******************************************************************************************/
typedef int			WWINT			;		//
typedef float		WWFLOAT			;		//
typedef short		WWSHORT			;		//
typedef double		WWDB			;		//
typedef long long	WWLL			;		//
typedef char		WWCH			;		//
typedef bool		WWBOOL			;		//
typedef int			WWSEL			;		//该类型的含义为选择，例如作为WWwindow::WWgetSize的参数时代表获取窗口的宽度还是高度，其值通常使用宏定义