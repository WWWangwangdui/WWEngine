/// <summary>
/// �ļ�����: WWdefine.h
/// ����ʱ�䣺2021/3/26
/// �����ˣ�	����
/// ������ʱ�䣺2021/3/26
/// �ĵ����������������к궨�壬���������������Լ��ṹ��Ķ���
/// </summary>
#pragma once
#pragma comment(lib, "winmm.lib")
#include <afx.h>
#include <d2d1.h>
/*******************************************************************************************
���´������к궨�壬ע���ʽ
#define NAME			VALUE			//COMMENT
*******************************************************************************************/
#define WW_ESC			0				//ESC�����ڲ�����

#define WW_SEL_W		0				//���
#define WW_SEL_H		1				//�߶�
#define WW_SEL_X		2				//������
#define WW_SEL_Y		3				//������
#define WW_SEL_ACTIVE	4				//���ڻ״̬
#define WW_SEL_SLEEP	5				//����˯��״̬���ǻ״̬��
#define WW_SEL_SOUND	6				//����
#define WW_SEL_STR		7				//�ַ���
#define WW_SEL_BIT		8				//λͼ
#define WW_SEL_ANIMAT	9				//����
#define WW_SEL_RECT		10				//����
#define WW_SEL_LINE		11				//ֱ��
#define WW_SEL_CIRCLE	12				//��Բ


/*******************************************************************************************
���´������г��궨��
*******************************************************************************************/
#ifdef _DEBUG

#define WWDEBUG(x) WWframe::debug(__FILE__,__LINE__,x)	
#define WWERROR(x) WWframe::error(__FILE__,__LINE__,x)	
#define WWNEWLINE WWframe::WWlogNewLine()

#else
#define WWDEBUG(x)
#define WWERROR(x)
#define WWNEWLINE

#endif // _DEBUG

#define WWLOG(x) WWframe::WWlog(__FILE__,__LINE__,x)
#define WWDELETE(x) SafeRelease(&x)

/*******************************************************************************************
���´������нṹ�����ݵĶ���
*******************************************************************************************/

/*******************************************************************************************
���´�����������������������ע���ʽ
typedef	SRCNAME				NEWNAME			��		//COMMENT
*******************************************************************************************/
typedef int					WWINT			;		//
typedef float				WWFLOAT			;		//
typedef short				WWSHORT			;		//
typedef double				WWDB			;		//
typedef long long			WWLL			;		//
typedef char				WWCH			;		//
typedef bool				WWBOOL			;		//
typedef wchar_t				WWWCH			;		//unicode������ַ�
typedef int					WWSEL			;		//�����͵ĺ���Ϊѡ��������ΪWWwindow::WWgetSize�Ĳ���ʱ�����ȡ���ڵĿ�Ȼ��Ǹ߶ȣ���ֵͨ��ʹ�ú궨��
typedef const wchar_t*		WWSTR			;		//Unicode������ַ���
typedef IWICBitmapSource*	WWBIT			;		//������Ⱦ��ʹ�õ�λͼ����
typedef CFile				WWSOUND			;		//�洢���ֵ��ڴ���
typedef POINT				WWPT			;		//����һ����ά�����	
