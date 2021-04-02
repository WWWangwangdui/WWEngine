/// <summary>
/// �ļ����ƣ��������
/// ����ʱ�䣺2021/3/28/17:00
/// �����ˣ����Ŀ�
/// ������ʱ�䣺3/31
/// �ĵ�����������Ϊ������֮࣬�������������Ӵ�����
/// </summary>
#pragma once
#include"WWtype.h"
class WWmoduleBase
{
protected:
	//���ID���
	WWINT WWmoduleID;
	//������ WW_SEL_ACTIVE� WW_SEL_SLEEP˯��
	WWINT WWactivity;
	//�����
	std::string WWmoduleName;
public:
	/// <summary>
	/// ��ʼ��
	/// </summary>
	/// <param name="p">�ļ�</param>
	void virtual WWinit() = 0;
	/// <summary>
	/// �洢
	/// </summary>
	/// <param name="p">�ļ�</param>
	void virtual WWsave(FILE* p) = 0;
	/// <summary>
	/// ����
	/// </summary>
	void virtual WWupdate() = 0;
	/// <summary>
	/// ���ش洢
	/// </summary>
	/// <param name="p">�ļ�</param>
	void virtual WWload(FILE* p) = 0;
	/// <summary>
	/// �޸ĸ�����Ƿ�����;
	/// </summary>
	/// <param name="sel">sel=WW_SEL_ACTIVE � sel=WW_SEL_SLEEP˯��</param>
	void WWsetModuleActivity(WWSEL sel);
	/// <summary>
	/// �õ������ID
	/// </summary>
	/// <returns>ID���</returns>
	WWINT WWgetModuleID();
	/// <summary>
	/// �õ������
	/// </summary>
	/// <returns></returns>
	std::string& WWgetModuleName();
	/// <summary>
	/// �жϸ�������Ƿ��Ǵ����
	/// </summary>
	/// <param name="modulename">�����</param>
	/// <returns>������������Ӧ����1 ��֮����0</returns>
	WWBOOL WWfindModule(std::string modulename);

};