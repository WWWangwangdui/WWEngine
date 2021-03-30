/// <summary>
/// �ļ����ƣ���Ϸ�������
/// ����ʱ�䣺2021/3/28/17:00
/// �����ˣ����Ŀ�
/// ������ʱ�䣺3/29/23:30
/// �ĵ�����������Ϊ��Ϸ������࣬��ʵ���κι���
/// </summary>
#pragma once
#include<vector>
#include"WWwindow.h"
#include"WWmoduleBase.h"
class WWobject
{
private:
	std::vector<WWmoduleBase*> WWmodules;
	std::vector<WWobject*> WWchildObject;
	WWINT WWobjectID;
	WWBOOL WWactivity;
public:
	//��Ҫ��Ϸ���ݽ���ע��
	WWobject();
	//����Ҫ����Ϸ���ݽ�������
	void WWover();

	//�ͷŶ����Ӷ������
	void deleteAll();

	//�ڶ����в������
	WWmoduleBase* findModule(WWmoduleBase* module);
	//������
	void virtual AddModule(WWmoduleBase *module);
	//ɾ������ӵ����
	void virtual RemoveModule(WWmoduleBase* module);
	/// <summary>
	/// �޸Ķ����е�һ������Ƿ�����
	/// </summary>
	/// <param name="module">�����</param>
	/// <param name="sel">sel =3 ���� sel = 4 �ر� ������</param>
	void SetModuleActive(WWmoduleBase* module,WWSEL sel);
	/// <summary>
	/// �޸����������Ƿ�����
	/// </summary>
	/// <param name="sel">sel=3 ���� sel = 4 �ر� ������</param>
	void SetObjectActive(WWSEL sel);
	//���º������������������ӶԶ�������
	void update();
	//�ݹ�洢���� 
	void saveObject(FILE* fp);
	//�洢������������
	void saveModule(FILE* fp);
	//����
	void load(FILE* fp);
	//��ʼ��
	void init(FILE* fp);
};