#pragma once
#include <windows.h>
#include <iostream>

#define VirtualCode_1 0x31 //1��������
#define VirtualCode_2 0x32 //2��������
#define VirtualCode_3 0x33 //3��������
#define VirtualCode_4 0x34 //4��������
#define VirtualCode_E 0x45 //E��������
#define VirtualCode_Q 0x51 //Q��������
#define VirtualCode_F8 0x77 //F8��������
#define VirtualCode_F9 0x78 //F9��������
#define VirtualCode_F10 0x79 //F10��������
#define VirtualCode_F11 0x7A //F11��������
#define VirtualCode_F12 0x7B //F12��������
#define VirtualCode_Space 0x20 //�ո��������
#define VirtualCode_MouseLeftButton 0x01 //���1�Ų��������
#define VirtualCode_MouseSideButton1 0x05 //���1�Ų��������
#define VirtualCode_MouseSideButton2 0x06 //���2�Ų��������
#define VirtualCode_R 0x52 //���2�Ų��������
#define ScanCode_E 18 //E��ɨ����
#define ScanCode_Q 56 //Q��ɨ����

class YSHotKey{
	YSHotKey();
	unsigned char virtualCode;//������
	unsigned char scanCode;//ɨ����
	SHORT stateBefore{ 0 };//
	SHORT stateAfter{ 0 };//

public:
	const char* name;
	void getHotKeyStateAndCallback();
	void (*hotKeyDownCallback)(unsigned char virtualCode);
	void (*hotKeyHoldCallback)(unsigned char virtualCode);
	void (*hotKeyUpCallback)(unsigned char virtualCode);
	YSHotKey(const char* name,
			 unsigned char virtualCode,
			 unsigned char scanCode,
			 void (*hotKeyDownCallback)(unsigned char virtualCode),
			 void (*hotKeyHoldCallback)(unsigned char virtualCode),
			 void (*hotKeyUpCallback)(unsigned char virtualCode));
};
