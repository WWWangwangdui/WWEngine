/// <summary>
/// �ļ����ƣ���Ϸ�������
/// ����ʱ�䣺2021/3/28/17:00
/// �����ˣ����Ŀ�
/// ������ʱ�䣺3/31
/// �ĵ�����������Ϊ��Ϸ������࣬��ʵ���κι���
/// </summary>
#pragma once
#include"WWtype.h"
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
	/// ͨ���������ȡ�����е����
	/// </summary>
	/// <param name="modulename"></param>
	/// <returns>���</returns>
	WWmoduleBase* WWgetMoudule(const WWCH* modulename);
	/// <summary>
	/// �ڶ���������������
	/// </summary>
	/// <param name="module">���</param>
	void WWaddModule(WWmoduleBase* module);
	/// <summary>
	/// ���������ɾ�����
	/// </summary>
	/// <param name="modulename">�����</param>
	void WWremoveModule(const WWCH* modulename);
	/// <summary>
	/// �޸Ķ��������е�һ������Ƿ�����
	/// </summary>
	/// <param name="module">�����</param>
	/// <param name="sel">sel =4 � sel = 5˯��</param>
	void WWsetModuleActive(const WWCH* moduleName, WWSEL sel);
	/// <summary>
	/// �޸����������Ƿ�����
	/// </summary>
	/// <param name="sel">sel=4 � sel = 5˯��</param>
	void WWsetObjectActive(WWSEL sel);

	/// <summary>
	/// ����������������Ӷ���Ļ��
	/// </summary>
	/// <param name="modulename">�����</param>
	/// <param name="sel">4 � 5˯��</param>
	void WWsetSonObjectActive(const WWCH* objname, WWSEL sel);

	/// <summary>
	/// ��ȡ��Ϸ�����ID
	/// </summary>
	/// <returns>��Ϸ����ID</returns>
	WWINT WWgetID();

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
	void WWinit();
	/// <summary>
	/// ������Ϸ����ı��
	/// </summary>
	/// <param name="id"></param>
	void WWsetID(WWINT id);
	/// <summary>
	/// ���ظö����Ƿ��ڻ״̬
	/// </summary>
	/// <returns></returns>
	bool WWgetActivity();
	/// <summary>
	/// ��ȡ��������Ӷ���
	/// </summary>
	/// <param name="name">��������·��</param>
	WWobject* WWgetObj(const WWCH* name);
};