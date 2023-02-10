#include <iostream>
#include <string>
#include <memory>
using namespace std;
#if 0
// ������ģʽ:�����ò����ݵĽӿ�һ����
// ����  ---  ��Ҫ�ӿ�ͶӰ��  ---  ͶӰ����   

// �ӿ��� VGA
class VGA {
public:
	virtual void play() = 0;
};
// �ӿ��� HDMI
class HDMI {
public:
	virtual void play() = 0;
};

// ͶӰ����(�ӿ���VGA�ӿ�)
class TV01 :public VGA {
public:
	void play() { cout << "ͨ�� VGA �ӿ�����ͶӰ�ǣ�������Ƶ����" << endl; }
};
// �µ�ͶӰ����(�ӿ���HDMI�ӿ�)����Ҫʹ���µ�ͶӰ��
class TV02 :public HDMI {
public:
	void play() { cout << "ͨ�� HDMI �ӿ�����ͶӰ�ǣ�������Ƶ����" << endl; }
};

// ������(ֻ��ʹ��VGA�ӿ�)
class Computer {
public:
	// ���ڵ���ֻ֧��VGA�ӿڣ�ʹ�÷����Ĳ���Ҳֻ����VGA�ӿڵ�ָ��
	void playVideo(VGA* pVGA) { pVGA->play(); }
};
// ����������
class VgaAdapter : public VGA {
public:
	VgaAdapter(HDMI* p) :pHdmi(p) { }
	void play() { pHdmi->play(); }
private:
	// ��Ҫһ���½ӿ�(��Ҫʹ�õ�),�ͳ��� VGA -> HDMI
	HDMI* pHdmi;
};
// ������
int main()
{
	// VGA�ӿڵĵ��� �� VGA�ӿڵ�ͶӰ������ֱ��ʹ�õ�
	Computer pc01;
	VGA* ptv01 = new TV01;
	pc01.playVideo(ptv01);

	// VGA�ӿڵĵ��� �� HDMI�ӿڵ�ͶӰ
	// ����ֱ��ʹ��HDMI�ӿڵ�ͶӰ���ӿڲ����ݣ���Ҫʹ��������
	Computer pc02;
	HDMI* ptv02 = new TV02;
	// pc02.playVideo(ptv02);
	VGA* pAdapter = new VgaAdapter(ptv02);
	pc02.playVideo(pAdapter);

	delete ptv01;
	delete ptv02;
	delete pAdapter;
	return 0;
}
#endif