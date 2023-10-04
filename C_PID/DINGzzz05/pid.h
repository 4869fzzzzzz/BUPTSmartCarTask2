#pragma once
#ifndef _PID_H
#define _PID_H

typedef struct {

	float
		output,           //���ֵ
		target,           //Ŀ��ֵ
		current,          //ʵ��ֵ
		error,            //���ֵ
		error_sum,        //����ֵ
		error_last,       //�ϴ����ֵ
		error_llast,      //���ϴ����ֵ
		error_sum_max,    //�����޷�
		Kp, Ki, Kd;       //PIDϵ��

}PID;

PID* PID_Init();              //��ʼ��PID�ṹ��
PID* PID_SetParameter(PID* popid);      //����PID����
void PID_PostionalPID(PID* pid);      //λ��ʽPIDʵ��
void PID_IncrementalPID(PID* pid);    //����ʽPIDʵ��

#endif
