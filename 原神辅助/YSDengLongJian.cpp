#include "YSDengLongJian.h"
#include "main.h"
#include "YSHotKey.h"

//������
void dengLongJian(unsigned char virtualCode){
	mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);//��������Ҽ�
	DWORD time1 = timeGetTime();
	while(timeGetTime() - time1 < 64);
	mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);//��������Ҽ�
	time1 = timeGetTime();
	while(timeGetTime() - time1 < 64);
	keybd_event(VirtualCode_Space, 0, 0, 0);//���¿ո��
	time1 = timeGetTime();
	while(timeGetTime() - time1 < 64);
	keybd_event(VirtualCode_Space, 0, KEYEVENTF_KEYUP, 0);//����ո��
	time1 = timeGetTime();
	while(timeGetTime() - time1 < 128);
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);//����������
	time1 = timeGetTime();
	while(timeGetTime() - time1 < 64);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);//����������
	time1 = timeGetTime();
	while(timeGetTime() - time1 < 64);
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);//����������
	time1 = timeGetTime();
	while(timeGetTime() - time1 < 64);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);//����������
	time1 = timeGetTime();
	while(timeGetTime() - time1 < 64);
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);//����������
	time1 = timeGetTime();
	while(timeGetTime() - time1 < 64);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);//����������
	time1 = timeGetTime();
	while(timeGetTime() - time1 < 64);
}