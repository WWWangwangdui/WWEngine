/// <summary>
/// �ļ����ƣ��������
/// ����ʱ�䣺2021/3/28/17:00
/// �����ˣ����Ŀ�
/// ������ʱ�䣺3/29/23:30
/// �ĵ�����������Ϊ������֮࣬�������������Ӵ�����
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
	//��ʼ��
	void virtual init(FILE *p) = 0;
	//�洢
	void virtual save(FILE* p) = 0;
	//������Ӧ
	void virtual update() = 0;
	//���ش洢
	void virtual load(FILE* p) = 0;
	/// <summary>
	/// �޸ĸ�����Ƿ�����;
	/// </summary>
	/// <param name="sel">sel=3 ���� sel=4 �رղ�����</param>
	void SetModuleActivity(WWSEL sel);
	//�õ������ID
	WWINT getMoudulceID();
};