#include "YSKeli.h"
#include "main.h"
#include "YSHotKey.h"

//������E��E��A��һ��+�ػ�
int keliBuzhou = 1;
DWORD changeKeliTime = 0;//�л��������ɫ��ʱ��
DWORD keli_E_Time = 0;
DWORD keliFirst_A_Time = 0;
DWORD keliSecond_A_Time = 0;
DWORD keliBuzhou2_Time = 0;
DWORD keliBuzhou5_Time = 0;
DWORD keliBuzhou6_Time = 0;
void keliDown(int selectedCharacterCodeAfter){
	if(selectedCharacterCodeBefore != selectedCharacterCodeAfter){
		selectedCharacterCodeBefore = selectedCharacterCodeAfter;
		changeKeliTime = timeGetTime();
	}
	keliBuzhou = 1;
}

void keliHold(int selectedCharacterCodeAfter){
	//�ȴ��л�Ӳֱʱ��
	if(nowTime - changeKeliTime < changeDelay){
		return;
	}

	switch(keliBuzhou){
	case 1:
		keybd_event(VirtualCode_E, ScanCode_E, 0, 0);
		keybd_event(VirtualCode_E, ScanCode_E, KEYEVENTF_KEYUP, 0);
		keli_E_Time = nowTime;
		keliBuzhou = 2;
		break;

	case 2:
		if(nowTime - keli_E_Time >= 100){
			keliBuzhou = 3;
		}
		break;

	case 3:
		keybd_event(VirtualCode_E, ScanCode_E, 0, 0);
		keybd_event(VirtualCode_E, ScanCode_E, KEYEVENTF_KEYUP, 0);
		mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);//����������
		mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);//�ɿ�������
		keliFirst_A_Time = nowTime;
		keliBuzhou = 4;
		break;

	case 4:
		if(nowTime - keliFirst_A_Time >= 200){
			keliBuzhou2_Time = nowTime;
			keliBuzhou = 5;
		}
		break;

	case 5:
		mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);//����������
		keliBuzhou5_Time = nowTime;
		keliBuzhou = 6;
		break;

	case 6:
		if(nowTime - keliBuzhou5_Time > 900){
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);//�ɿ�������
			keliBuzhou6_Time = nowTime;
			keliBuzhou = 7;
		}
		break;

	case 7:
		if(nowTime - keliBuzhou6_Time >= 100){
			keliBuzhou = 1;
		}
		break;
	}
}

void keliUp(int selectedCharacterCodeAfter){
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);//�ɿ�������
}