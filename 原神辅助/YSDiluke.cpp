#include "YSDiluke.h"
#include "main.h"
#include "YSHotKey.h"

int dilukeBuzhou = 1;
DWORD changeDilukeTime = 0;//�л�����¬�˵�ʱ��
DWORD diluke_E_or_A_Time2 = 0;
DWORD diluke_E_Time = 0;//��¬����һ��E��ʱ��

void dilukeDown(int selectedCharacterCodeAfter){
	if(selectedCharacterCodeBefore != selectedCharacterCodeAfter){
		changeDilukeTime = nowTime;
		diluke_E_or_A_Time2 = changeDilukeTime;
		diluke_E_Time = nowTime + changeDelay - 400;
	}

}

void dilukeHold(int selectedCharacterCodeAfter){
	//�ȴ��л�Ӳֱʱ��
	if(nowTime - changeDilukeTime < changeDelay){
		return;
	}

	switch(dilukeBuzhou){
	case 1:
		if(nowTime - diluke_E_Time >= 1200){
			keybd_event(VirtualCode_E, ScanCode_E, 0, 0);//����E��
			keybd_event(VirtualCode_E, ScanCode_E, KEYEVENTF_KEYUP, 0);//����E��
			diluke_E_Time = nowTime;
		}
		else{
			mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);//����������
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);//�ɿ�������
		}
		dilukeBuzhou = 2;
		diluke_E_or_A_Time2 = nowTime;
		break;

	case 2:
		if(nowTime - diluke_E_or_A_Time2 >= 100){
			dilukeBuzhou = 1;
		}
		break;
	}
}

void dilukeUp(int selectedCharacterCodeAfter){

}
