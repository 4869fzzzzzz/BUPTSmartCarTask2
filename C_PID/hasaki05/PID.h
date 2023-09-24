#ifndef PID_H
#define PID_H

typedef struct
{
    float ki;
    float kp;
    float kd;
}PID;

typedef struct
{
    float error;
    float pre_error;
    float pre_pre_error;
    float sum_error;
}ERROR;

int PID_Init(void);//��ʼ��PID�ṹ

int ERROR_Init(void);//��ʼ��error

int PID_SetParameter(PID* pid_set);      //����PID����

float PID_PostionalPID(void);      //λ��ʽPIDʵ��
float PID_IncrementalPID(void);    //����ʽPIDʵ��

int error_get_p(void);//error��ȡ
int error_get_i(void);

float move_p(float u_p);//�ƶ�
float move_i(float u_i);



#endif