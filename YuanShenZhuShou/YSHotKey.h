#pragma once
#include <windows.h>
#include <iostream>

#define VirtualCode_1 0x31 //1��������
#define VirtualCode_2 0x32 //2��������
#define VirtualCode_3 0x33 //3��������
#define VirtualCode_4 0x34 //4��������
#define VirtualCode_E 0x45 //E��������
#define VirtualCode_Q 0x51 //Q��������
#define VirtualCode_F8 VK_F8 //F8��������
#define VirtualCode_F9 VK_F9 //F9��������
#define VirtualCode_F10 VK_F10 //F10��������
#define VirtualCode_F11 VK_F11 //F11��������
#define VirtualCode_F12 VK_F12 //F12��������
#define VirtualCode_MouseSideButton1 VK_XBUTTON1 //���1�Ų��������
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
	void (*hotKeyDownCallback)();
	void (*hotKeyHoldCallback)();
	void (*hotKeyUpCallback)();
	YSHotKey(const char* name,
			 unsigned char virtualCode,
			 unsigned char scanCode,
			 void (*hotKeyDownCallback)(),
			 void (*hotKeyHoldCallback)(),
			 void (*hotKeyUpCallback)());
};
