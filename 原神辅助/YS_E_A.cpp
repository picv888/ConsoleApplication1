#include "YS_E_A.h"
#include "main.h"
#include "YSHotKey.h"

int E_A_Buzhou = 0;
DWORD change_E_A_Time = 0;//�л��������ɫ��ʱ��
DWORD E_Time = 0;//E��ʱ��
DWORD A_Time = 0;//A��ʱ��
void E_A_Down(int selectedCharacterCodeAfter){
	if(selectedCharacterCodeBefore != selectedCharacterCodeAfter){
		selectedCharacterCodeBefore = selectedCharacterCodeAfter;
		change_E_A_Time = timeGetTime();
	}
	E_A_Buzhou = 0;
}

void E_A_Hold(int selectedCharacterCodeAfter){


	//�ȴ��л�Ӳֱʱ��
	if(nowTime - change_E_A_Time < changeDelay){
		return;
	}

	switch(E_A_Buzhou){
	case 0:
		keybd_event(VirtualCode_E, ScanCode_E, 0, 0);//����E��
		keybd_event(VirtualCode_E, ScanCode_E, KEYEVENTF_KEYUP, 0);//����E��
		E_A_Buzhou = 1;
		E_Time = nowTime;
		break;

	case 1:
		if(nowTime - E_Time >= 100){
			E_A_Buzhou = 2;
		}
		break;

	case 2:
		mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);//����������
		mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);//�ɿ�������
		E_A_Buzhou = 3;
		A_Time = nowTime;
		break;

	case 3:
		if(nowTime - A_Time >= 100){
			E_A_Buzhou = 0;
		}
		break;
	}
}

void E_A_Up(int selectedCharacterCodeAfter){

}