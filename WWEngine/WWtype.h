/// <summary>
/// �ļ�����: WWtype.h
/// ����ʱ�䣺2021/3/26
/// �����ˣ�	����
/// ������ʱ�䣺2021/3/26
/// �ĵ����������������͵�ͷ�ļ����а���
/// </summary>
#pragma once
#include<afx.h>
#include"WWdefine.h"
/// <summary>
/// ����һ��λͼ
/// </summary>
struct WWBitmap
{
	//λͼ��Դ��ַ
	WWBIT* bitsrc;
	//��λͼλ��Դλͼ�ϵ�λ��
	WWPT offpos;
	//��λͼ�Ĵ�С
	WWPT size;
};
/// <summary>
/// ����һ������
/// </summary>
struct WWAnimation
{
	//λͼ��Դ��ַ
	WWBIT* bitsrc;
	//������һ֡λ��Դλͼ�ϵ�λ��
	WWPT offpos;
	//�����Ĵ�С
	WWPT size;
	//������֡��
	WWINT frameCnt;
	//��֮֡��ļ��ʱ��
	WWTIME frameTime;
	//�ظ���ǣ���ֵΪtrue�򶯻�ѭ�����ţ����������һ��
	WWBOOL cycle;
	//��һ֡��ʾ��ʱ��
	WWTIME lastFrame;
	
};