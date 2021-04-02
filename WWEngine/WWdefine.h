/// <summary>
/// �ļ�����: WWdefine.h
/// ����ʱ�䣺2021/3/26
/// �����ˣ�	����
/// ������ʱ�䣺2021/3/26
/// �ĵ����������������к궨�壬���������������Լ��ṹ��Ķ���
/// </summary>
#pragma once

#include<afx.h>
#include<d2d1.h>
#include<dwrite.h>
#include<map>
#include<vector>
#include<string>
#include<queue>
#include<iostream>
#include<fstream>
#include<ctime>
#pragma comment(lib,"d2d1.lib")
#pragma comment(lib,"dwrite.lib")
#pragma comment(lib, "winmm.lib")

class WWasCtrl;
class WWcamera;
class WWdefine;
class WWkeyIO;
class WWmoduleBase;
class WWobject;
class WWrenderer;
class WWrenderUnit;
class WWtransform;
class WWframe;
class WWwindow;


/*******************************************************************************************
���´������к궨�壬ע���ʽ
#define NAME				VALUE			//COMMENT
*******************************************************************************************/
#define WW_LBD			1               //������
#define WW_RBD			2               //����Ҽ�
#define WW_CANCLE		3               //cancel
#define WW_MBD  		4               //����м�
#define WW_BACK 		8               //
#define WW_TAB  		9               //
#define WW_CLEAR		12              //
#define WW_ENTER		13              //
#define WW_SHIFT		16              //
#define WW_CTRL		    17              //
#define WW_ALT		    18              //
#define WW_PAUSE		19              //
#define WW_CAPLSK		20              //
#define WW_KANA         21              //
#define WW_HANGUL       21              //
#define WW_JUNJA	    23              //
#define WW_FINAL	    24              //
#define WW_HANJA	    25              //
#define WW_KANJI	    25              //
#define WW_ESC    		27              //
#define WW_CONVERT	    28              //
#define WW_NONCONVERT	29              //
#define WW_ACCEPT	    30              //
#define WW_MODECHANGE	31              //
#define WW_SPACE        32              //
#define WW_PAGEUP       33              //
#define WW_PAGEDOWN     34              //
#define WW_END          35              //
#define WW_HOME         36              //
#define WW_LEFT         37              //��
#define WW_UP           38              //��
#define WW_RIGHT        39              //��
#define WW_DOWN         40              //��
#define WW_SELECT       41              //
#define WW_PRINT        42              //
#define WW_EXECUTE      43              //
#define WW_INS          45              //
#define WW_K_DELETE     46              //
#define WW_HELP         47              //
#define WW_K0           48              //�����ϵ����ֲ���
#define WW_K1           49              //
#define WW_K2           50              //
#define WW_K3           51              //
#define WW_K4           52              //
#define WW_K5           53              //
#define WW_K6           54              //
#define WW_K7           55              //
#define WW_K8           56              //
#define WW_K9           57              //
#define WW_A            65              //��ĸ
#define WW_B            66              //
#define WW_C            67              //
#define WW_D            68              //
#define WW_E            69              //
#define WW_F            70              //
#define WW_G            71              //
#define WW_H            72              //
#define WW_I            73              //
#define WW_J            74              //
#define WW_K            75              //
#define WW_L            76              //
#define WW_M            77              //
#define WW_N            78              //
#define WW_O            79              //
#define WW_P            80              //
#define WW_Q            81              //
#define WW_R            82              //
#define WW_S            83              //
#define WW_T            84              //
#define WW_U            85              //
#define WW_V            86              //
#define WW_W            87              //
#define WW_X            88              //
#define WW_Y            89              //
#define WW_Z            90              //
#define WW_LWIN	        91              //
#define WW_RWIN	        92              //
#define WW_APPS	        93              //
#define WW_SLEEP	    95              //
#define WW_Kz0          96              //С���̰���
#define WW_Kz1          97              //
#define WW_Kz2          98              //
#define WW_Kz3          99              //
#define WW_Kz4          100             //
#define WW_Kz5          101             //
#define WW_Kz6          102             //
#define WW_Kz7          103             //
#define WW_Kz8          104             //
#define WW_Kz9          105             //
#define WW_zplus        107             //
#define WW_zcheng       106             //
#define WW_zenter       108             //
#define WW_zjian        109             //
#define WW_zdian        110             //
#define WW_zchu         111             //
#define WW_KF1          112             //F1--F12
#define WW_KF2          113             //
#define WW_KF3          114             //
#define WW_KF4          115             //
#define WW_KF5          116             //
#define WW_KF6          117             //
#define WW_KF7          118             //
#define WW_KF8          119             //
#define WW_KF9          120             //
#define WW_KF10         121             //
#define WW_KF11         122             //
#define WW_KF12         123             //
#define WW_F13	        124             //
#define WW_F14	        125             //
#define WW_F15	        126             //
#define WW_F16	        127             //
#define WW_F17	        128             //
#define WW_F18	        129             //
#define WW_F19	        130             //
#define WW_F20	        131             //
#define WW_F21	        132             //
#define WW_F22	        133             //
#define WW_F23	        134             //
#define WW_F24	        135             //
#define WW_NUMLOCK		144	            //Num Lock��
#define WW_SCROLL		145	            //Scroll Lock��
#define WW_LSHIFT		160	            //��Shift��
#define WW_RSHIFT		161	            //��Shift��
#define WW_LCONTROL		162	            //��Ctrl��
#define WW_RCONTROL		163	            //��Ctrl��
#define WW_LMENU		164	            //��Alt��
#define WW_RMENU		165	            //��Alt��
#define WW_COLON        186             //;
#define WW_PLUS         187             //=+
#define WW_UNDERLINE    189             //_-
#define WW_QUESTION     191             //?
#define WW_zuoshang     192             //~��`
#define WW_LBRACE       219             //{
#define WW_BIAS         220             //|
#define WW_RBRACE       221             //}
#define WW_QUOTATION    222             //""
#define WW_OEM_8	    223             //
#define WW_OEM_102	    226             //
#define WW_PACKET	    231             //
#define WW_PSK      	229             //
#define WW_ATTN	        246             //
#define WW_CRSEL	    247             //
#define WW_EXSEL	    248             //
#define WW_EREOF	    249             //
#define WW_PLAY	        250             //
#define WW_ZOOM      	251             //
#define WW_NONAME	    252             //
#define WW_PA1	        253             //
#define WW_OEM_CLEAR	254             //
#define WW_SEL_W		0				//���
#define WW_SEL_H		1				//�߶�
#define WW_SEL_X		2				//������
#define WW_SEL_Y		3				//������
#define WW_SEL_ACTIVE	4				//���ڻ״̬
#define WW_SEL_SLEEP	5				//����˯��״̬���ǻ״̬��
#define WW_SEL_SOUND	6				//����
#define WW_SEL_STR		7				//�ַ���
#define WW_SEL_BIT		8				//λͼ

#define WW_SEL_W			0				//���
#define WW_SEL_H			1				//�߶�
#define WW_SEL_X			2				//������
#define WW_SEL_Y			3				//������
#define WW_SEL_ACTIVE		4				//���ڻ״̬
#define WW_SEL_SLEEP		5				//����˯��״̬���ǻ״̬��
#define WW_SEL_SOUND		6				//����
#define WW_SEL_STR			7				//�ַ���
#define WW_SEL_BIT			8				//λͼ
#define WW_SEL_ANIMAT		9				//����
#define WW_SEL_RECT			10				//����
#define WW_SEL_LINE			11				//ֱ�߿���
#define WW_SEL_CIRCLE		12				//��Բ����
#define WW_SEL_RECTFILL		13				//�������
#define WW_SEL_CIRCLEFILL	14				//Բ���
#define WW_SEL_EMPTY		15				//��	
#define WW_SEL_GRAPH		16				//ͼԪ
#define WW_SEL_ANI			17				//����	


/*******************************************************************************************
���´������г��궨��
*******************************************************************************************/

#ifndef Assert
#if defined( DEBUG ) || defined( _DEBUG )
#define Assert(b) do {if (!(b)) {OutputDebugStringA("Assert: " #b "\n");}} while(0)
#else
#define Assert(b)
#endif //DEBUG || _DEBUG
#endif

#ifndef HINST_THISCOMPONENT
EXTERN_C IMAGE_DOS_HEADER __ImageBase;
#define HINST_THISCOMPONENT ((HINSTANCE)&__ImageBase)
#endif

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
#define WWDELETE(x) if(x != nullptr) { delete x ;  x = nullptr;}
#define WWRELEASE(x)  if (*x != nullptr) {(*x)->Release();   (*x) = nullptr; }
#define WWBADPTR(x) 


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
typedef ID2D1Bitmap*		WWBIT			;		//������Ⱦ��ʹ�õ�λͼ����
typedef CFile				WWSOUND			;		//�洢���ֵ��ڴ���
typedef POINT				WWPT			;		//����һ����ά�����	
typedef ULONGLONG			WWTIME			;		//ʱ��������룩
typedef COLORREF			WWCOLOR			;		//��ɫ