#pragma once
#include <windows.h>
//��ǰ��ɫ
#define SelectedCharacter_Diluke 1001		//��¬��
#define SelectedCharacter_Keqing 1002		//����
#define SelectedCharacter1_E_A 2001			//��1��λ�ģ��̰�E�Ľ�ɫ
#define SelectedCharacter2_E_A 2002			//��2��λ�ģ��̰�E�Ľ�ɫ
#define SelectedCharacter3_E_A 2003			//��3��λ�ģ��̰�E�Ľ�ɫ
#define SelectedCharacter4_E_A 2004			//��4��λ�ģ��̰�E�Ľ�ɫ
#define SelectedCharacter1_LongE 3001		///��1��λ�ģ�����E�Ľ�ɫ
#define SelectedCharacter2_LongE 3002		///��2��λ�ģ�����E�Ľ�ɫ
#define SelectedCharacter3_LongE 3003		///��3��λ�ģ�����E�Ľ�ɫ
#define SelectedCharacter4_LongE 3004		///��4��λ�ģ�����E�Ľ�ɫ
#define SelectedCharacter1_Q_E 4001			//��1��λ�ģ���Q��E�Ľ�ɫ
#define SelectedCharacter2_Q_E 4002			//��2��λ�ģ���Q��E�Ľ�ɫ
#define SelectedCharacter3_Q_E 4003			//��3��λ�ģ���Q��E�Ľ�ɫ
#define SelectedCharacter4_Q_E 4004			//��4��λ�ģ���Q��E�Ľ�ɫ
#define SelectedCharacter1_E_Q 5001			//��1��λ�ģ���Q��E�Ľ�ɫ
#define SelectedCharacter2_E_Q 5002			//��2��λ�ģ���Q��E�Ľ�ɫ
#define SelectedCharacter3_E_Q 5003			//��3��λ�ģ���Q��E�Ľ�ɫ
#define SelectedCharacter4_E_Q 5004			//��4��λ�ģ���Q��E�Ľ�ɫ
#define SelectedCharacter_Keli 6001			//����
#define SelectedCharacter_Youla 7001        //��ǉ

extern DWORD changeDelay; //�л�Ӳֱʱ��
extern int selectedCharacterCodeBefore;
extern int selectedCharacterCodeAfter;
extern int(*pSelectedTeam)[4];
extern DWORD nowTime;