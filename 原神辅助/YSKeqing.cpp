#include "YSKeqing.h"
#include "main.h"
#include "YSHotKey.h"

/*
����1 E����һ��
����2 �ȴ�50���룬��һ��
����3 �����������һ��
����4 ����ػ�����������������7��������ȴ�50���룬��һ��
����5 ����ػ�����������������7��������E����һ��
����6 ����ػ�����������������7��������ȴ�50����ص���5��
����7 �ȴ�50����ص���3��
*/
int keqingBuzhou = 1;
DWORD changeKeqingTime = 0;//�л��������ʱ��
DWORD keqing_E_Time = 0;
DWORD keqing_MouseDown_Time = 0;
DWORD keqing_MouseUp_Time = 0;

void keqingDown(int selectedCharacterCodeAfter){
	if(selectedCharacterCodeBefore != selectedCharacterCodeAfter){
		changeKeqingTime = timeGetTime();
	}
	keqingBuzhou = 1;
}

void keqingHold(int selectedCharacterCodeAfter){
	//�ȴ��л�Ӳֱʱ��
	if(nowTime - changeKeqingTime < changeDelay){
		return;
	}

	switch(keqingBuzhou){
	case 1:
		keybd_event(VirtualCode_E, ScanCode_E, 0, 0);//����E��
		keybd_event(VirtualCode_E, ScanCode_E, KEYEVENTF_KEYUP, 0);//����E��
		keqing_E_Time = nowTime;
		keqingBuzhou = 2;
		break;

	case 2:
		if(nowTime - keqing_E_Time >= 50){
			keqingBuzhou = 3;
		}
		break;

	case 3:
		mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);//����������
		keqing_MouseDown_Time = nowTime;
		keqingBuzhou = 4;
		break;

	case 4:
		if(nowTime - keqing_MouseDown_Time >= 400){
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);//����������
			keqing_MouseUp_Time = nowTime;
			keqingBuzhou = 7;
		}
		else if(nowTime - keqing_MouseDown_Time > 50){
			keqingBuzhou = 5;
		}
		break;

	case 5:
		if(nowTime - keqing_MouseDown_Time >= 400){
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);//����������
			keqing_MouseUp_Time = nowTime;
			keqingBuzhou = 7;
		}
		else{
			keybd_event(VirtualCode_E, ScanCode_E, 0, 0);//����E��
			keybd_event(VirtualCode_E, ScanCode_E, KEYEVENTF_KEYUP, 0);//����E��
			keqing_E_Time = nowTime;
			keqingBuzhou = 6;
		}
		break;

	case 6:
		if(nowTime - keqing_MouseDown_Time >= 400){
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);//����������
			keqing_MouseUp_Time = nowTime;
			keqingBuzhou = 7;
		}
		else if(nowTime - keqing_E_Time >= 50){
			keqingBuzhou = 5;
		}
		break;

	case 7:
		if(nowTime - keqing_MouseUp_Time >= 100){
			keqingBuzhou = 3;
		}
		break;
	}
}

void keqingUp(int selectedCharacterCodeAfter){
	if(keqingBuzhou == 4 || keqingBuzhou == 5 || keqingBuzhou == 6){
		mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);//����������
	}
}