#pragma once
#include"WWtype.h"
#include"WWmoduleBase.h"
class WWtransform: 
	public WWmoduleBase
{
private:
	///����
	WWINT WWposX, WWposY;
	//��ת
	WWINT WWrotate;
	//����
	WWFLOAT WWscaleX, WWscaleY;
	//�����������
	WWFLOAT WWfollowrate;
	//�Ƿ�������
	WWBOOL WWfollow;
public:
	/// <summary>
	/// ���캯�� x��y���꣨0��0�� �Ƕ�0 ����100%
	/// </summary>
	WWtransform();
	/// <summary>
	/// �޸�����
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	void WWsetPoint(WWINT x,WWINT y);
	/// <summary>
	/// ��ȡ����
	/// </summary>
	/// <returns></returns>
	WWPT WWgetPos();
	/// <summary>
	/// ��ȡ����
	/// </summary>
	/// <returns></returns>
	WWPTF WWgetScale();
	/// <summary>
	/// ��ȡ��ת�Ƕ�
	/// </summary>
	/// <returns></returns>
	WWINT WWgetRotate();
	/// <summary>
	/// �޸ĽǶ�
	/// </summary>
	/// <param name="angle"></param>
	void WWsetRotate(WWINT angle);
	/// <summary>
	/// �޸ı���
	/// </summary>
	/// <param name="ratio"></param>
	void WWsetScale(WWFLOAT scaleX, WWFLOAT scaleY);
	/// <summary>
	/// ����ǰ�����һ��λ������
	/// </summary>
	/// <param name="dx">�����ĵ�һά�������꣩</param>
	/// <param name="dy">�����ĵڶ�ά�������꣩</param>
	void WWmove(WWINT dx, WWINT dy);
	/// <summary>
	/// ��ʼ��
	/// </summary>
	/// <param name="moduleID">���ID���</param>
	/// <param name="modulename">�����</param>
	void WWinit();
	/// <summary>
	/// �洢
	/// </summary>
	/// <param name="p">�ļ�</param>
	void WWsave(FILE* fp);
	/// <summary>
	/// ����
	/// </summary>
	void WWupdate();
	/// <summary>
	/// ���ش洢
	/// </summary>
	/// <param name="f">�ļ�</param>
	void WWload(FILE* fp);
	/// <summary>
	/// ��ȡ�����������ĸ���ֵ
	/// </summary>
	/// <returns></returns>
	WWFLOAT WWgetFollowRate();
};

