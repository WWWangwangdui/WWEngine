/// <summary>
/// �ļ����ƣ���Ϸ�������
/// ����ʱ�䣺2021/3/28/17:00
/// �����ˣ����Ŀ�
/// ������ʱ�䣺3/31
/// �ĵ�����������Ϊ��Ϸ������࣬��ʵ���κι���
/// </summary>
#pragma once
#include<afx.h>
#include<vector>
#include"WWwindow.h"
#include"WWmoduleBase.h"
class WWobject
{
private:
	//�������
	std::vector<WWmoduleBase*> WWmodules;
	//�Ӷ�������
	std::vector<WWobject*> WWchildObject;
	//����ID���
	WWINT WWobjectID;
	//������ 4� 5˯��
	WWBOOL WWactivity;
public:
	/// <summary>
	/// ��Ҫ��Ϸ���ݽ���ע��
	/// </summary>
	WWobject();
	/// <summary>
	/// ����Ҫ����Ϸ���ݽ�������
	/// </summary>
	void WWover();
	/// <summary>
	/// �ͷŶ����Ӷ������
	/// </summary>
	void WWdeleteAll();
	/// <summary>
	/// �ڶ��������и����������
	/// </summary>
	/// <param name="module">���</param>
	/// <returns>���</returns>
	WWmoduleBase* WWfindModule(WWmoduleBase* module);
	/// <summary>
	/// ͨ���������ȡ�����е����
	/// </summary>
	/// <param name="modulename"></param>
	/// <returns>���</returns>
	WWmoduleBase* WWgetMoudule(WWSTR modulename);
	/// <summary>
	/// �ڶ���������������
	/// </summary>
	/// <param name="module">���</param>
	void WWaddModule(WWmoduleBase* module);
	/// <summary>
	/// ɾ���ڶ���������ӵ����
	/// </summary>
	/// <param name="module">���</param>
	void WWremoveModule(WWmoduleBase* module);
	/// <summary>
	/// ���������ɾ�����
	/// </summary>
	/// <param name="modulename">�����</param>
	void WWremoveModule(WWSTR modulename);
	/// <summary>
	/// �޸Ķ��������е�һ������Ƿ�����
	/// </summary>
	/// <param name="module">�����</param>
	/// <param name="sel">sel =4 � sel = 5˯��</param>
	void WWsetModuleActive(WWmoduleBase* module, WWSEL sel);
	/// <summary>
	/// �޸����������Ƿ�����
	/// </summary>
	/// <param name="sel">sel=4 � sel = 5˯��</param>
	void WWsetObjectActive(WWSEL sel);

	/// <summary>
	/// ��������������ø�����Ļ��
	/// </summary>
	/// <param name="modulename">�����</param>
	/// <param name="sel">4 � 5˯��</param>
	void WWsetObjectActive(WWSTR modulename, WWSEL sel);



	/// <summary>
	/// ���º������������������ӶԶ�������
	/// </summary>
	void WWupdate();
	/// <summary>
	/// �ݹ�洢���� 
	/// </summary>
	/// <param name="fp">�ļ�</param>
	void WWsaveObject(FILE* fp);
	/// <summary>
	/// �ݹ�洢���� 
	/// </summary>
	/// <param name="fp">�ļ�</param>
	void WWsaveModule(FILE* fp);
	/// <summary>
	/// ����
	/// </summary>
	/// <param name="fp">�ļ�</param>
	void WWload(FILE* fp);
	/// <summary>
	/// ��ʼ��
	/// </summary>
	/// <param name="fp">�ļ�</param>
	void WWinit(FILE* fp);


};