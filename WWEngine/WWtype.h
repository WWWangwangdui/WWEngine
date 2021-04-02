/// <summary>
/// �ļ�����: WWtype.h
/// ����ʱ�䣺2021/3/26
/// �����ˣ�	����
/// ������ʱ�䣺2021/3/26
/// �ĵ����������������͵�ͷ�ļ����а���
/// </summary>
#pragma once
#include"WWdefine.h"
/// <summary>
/// ����һ��λͼ
/// </summary>
struct WWBitmap
{
	//λͼ��Դ��ַ
	WWBIT bitsrc;
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
	WWBIT bitsrc;
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
/// <summary>
/// ����һ�����ڻ��Ƶ��ı���
/// </summary>
struct WWText
{
	//�ı��ζ�Ӧ���ַ���
	WWSTR str;
	//�ı��ε�����
	WWSTR font;
	//�ı����õ������С
	WWFLOAT size;
	//�ı�����ɫ 
	WWCOLOR col;
};
/// <summary>
/// ����һ��ͼԪ������ֱ�ߡ���Բ������
/// </summary>
struct WWGraph
{
	//����ֱ�ߣ��õ�Ϊ��㣻������Բ���õ�ΪԲ�ģ����ھ��Σ��õ�Ϊ���Ͻ�����
	WWPT pt1;
	//����ֱ�ߣ��ĵ�Ϊ�յ㣻������Բ���õ��x����Ϊ��ȣ�y����Ϊ�߶ȣ����ھ��Σ��õ�Ϊ���½�����
	WWPT pt2;
	//��ͼԪ������
	WWSEL type;
	//��ͼԪ����ɫ
	WWCOLOR col;
	//��ͼԪ���߿�
	WWINT wide;
	//��ͼԪ�Ƿ���Ҫ���
	WWBOOL fill;
};
/// <summary>
/// ����һ��С����
/// </summary>
struct WWPTF
{
	//������
	WWFLOAT x;
	//������
	WWFLOAT y;
};
/// <summary>
/// ����һ��������Ϣ�ļ�ʱ��
/// </summary>
struct WWkeyTimer
{
	//����
	WWINT keyID;
	//��������˫��
	WWINT clickTime;
	//��ʱʱ��
	WWDB ti;
	//����С�ںţ���ʱ������
	bool operator<(const WWkeyTimer& A)const
	{
		return ti > A.ti;
	}
};