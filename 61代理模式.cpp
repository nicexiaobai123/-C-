#include <iostream>
#include <string>
#include <memory>
using namespace std;
#if 0
// #1 ������
class VideoSite
{
public:
	virtual void freeMoive() = 0;
	virtual void vipMoive() = 0;
	virtual void ticketMoive() = 0;
};
// #2 ί����  ������ʵ�ʹ��ܵ���
class AQYVideoSite :public VideoSite
{
public:
	void freeMoive() { cout << "���ڹۿ���ѵ�Ӱ��" << endl; }
	void vipMoive() { cout << "���ڹۿ�VIP��Ӱ��" << endl; }
	void ticketMoive() { cout << "������ȯ�ۿ���Ӱ��" << endl; }
};
// #3 ������  ��ͨ�û�Ȩ��
class FreeVideoSiteProxy : public VideoSite
{
public:
	FreeVideoSiteProxy() :pVideo(new AQYVideoSite) { }
	~FreeVideoSiteProxy() { delete  pVideo; }
	// ���Ʒ���Ȩ�ޣ�ֱ��ί�� ���� ���⴦��
	void freeMoive() { pVideo->freeMoive(); }
	void vipMoive() { cout << "Ŀǰ����ͨ�û������ܹۿ�vip��Ӱ��" << endl; }
	void ticketMoive() { cout << "Ŀǰ��Ʊ�����ۿ���ȯ��Ӱ��" << endl; }
private:
	// #4 ��ί�й�ϵ(ָ��)������Ϲ�ϵ(����)
	VideoSite* pVideo;
	//AQYVideoSite video;
};
// ������  VIP�û�Ȩ��
class VipVideoSiteProxy : public VideoSite
{
public:
	VipVideoSiteProxy() :pVideo(new AQYVideoSite) { }
	~VipVideoSiteProxy() { delete  pVideo; }
	// ���Ʒ���Ȩ�ޣ�ֱ��ί�� ���� ���⴦��
	void freeMoive() { pVideo->freeMoive(); }
	void vipMoive() { pVideo->vipMoive(); }
	void ticketMoive() { cout << "Ŀǰ��Ʊ�����ۿ���ȯ��Ӱ��" << endl; }
private:
	VideoSite* pVideo;
};
// ������
int main()
{
	// �����ʹ�ô�����(����)��ֱ��ʹ��ί����(�ϰ�)
	// �����㲻��vip�û� �� ��ͨ�û���������
	unique_ptr<VideoSite> p1(new AQYVideoSite);
	p1->freeMoive();
	p1->vipMoive();
	p1->ticketMoive();

	// #5 �ͻ�ֱ��ʹ�ô�����󣬿��Ʒ���Ȩ��
	cout << "--------------------------" << endl;
	unique_ptr<VideoSite> p2(new FreeVideoSiteProxy);
	p2->freeMoive();
	p2->vipMoive();
	p2->ticketMoive();

	// ʹ��vipȨ�޴�����
	cout << "--------------------------" << endl;
	unique_ptr<VideoSite> p3(new VipVideoSiteProxy);
	p3->freeMoive();
	p3->vipMoive();
	p3->ticketMoive();

	return 0;
}
#endif