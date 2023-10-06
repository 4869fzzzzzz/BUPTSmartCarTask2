#pragma once
#ifndef __PID_H
#define __PID_H




#include <stdio.h>
#include<time.h>
#include<windows.h>
typedef struct
{
    float kp, ki, kd;
    float error, lastError, priError;//���ϴ������ϴ����
    float integ, maxInteg;//���֡������޷�
    float output, maxOutput;//���������޷�
}PID;

//��ʼ���ṹ��(Ĭ��ֵp=1,i=0.5,d=0.1,maxI=200,maxOut=300)
int PID_Init(PID* pid, float p, float i, float d, float maxI, float maxOut);

//��������
int PID_SetParameter(PID* pid);

//λ��ʽPID
int PID_PostionalPID(PID* pid, float target, float current);

//����ʽPID
int PID_IncrementalPID(PID* pid, float target, float current);

//ģ�����������current
int PID_Imitate(float* current, PID* pid);

#endif // !__PID_H