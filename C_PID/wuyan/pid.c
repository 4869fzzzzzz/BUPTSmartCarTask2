#define _CRT_SECURE_NO_WARNINGS
#include "pid.h"


static void limit(float* i, float max)
{
    if (*i > max) *i = max;
    if (*i < -max) *i = -max;
}

int PID_Init(PID* pid, float p, float i, float d, float maxI, float maxOut)
{
    pid->kp = p;
    pid->ki = i;
    pid->kd = d;
    pid->maxInteg = maxI;
    pid->maxOutput = maxOut;
    return 0;
}

int PID_SetParameter(PID* pid)
{
    float p, i, d, maxI, maxOut;
    printf("��ϣ����Kp��"); scanf(" %f", &p);
    printf("��ϣ����Ki��"); scanf(" %f",&i);
    printf("��ϣ����Kd��"); scanf(" %f",&d);
    printf("�����޷���"); scanf(" %f",&maxI);
    printf("����޷���"); scanf(" %f",&maxOut);
    pid->kp = p;
    pid->ki = i;
    pid->kd = d;
    pid->maxInteg = maxI;
    pid->maxOutput = maxOut;
    return 0;
}

int PID_PostionalPID(PID* pid, float target, float current)//λ��ʽPID
{
    pid->lastError = pid->error;
    pid->error = target - current;  // ���㵱ǰ���
    float Poutput = pid->error * pid->kp;//����
    float Doutput = (pid->error - pid->lastError) * pid->kd;//΢��
    pid->integ += pid->ki * pid->error;  // ����
    pid->integ = pid->integ > pid->maxInteg ? pid->maxInteg : pid->integ;
    pid->integ = pid->integ < -pid->maxInteg ? -pid->maxInteg : pid->integ;
    pid->output = Poutput + Doutput + pid->integ;
    return 0;
}

int PID_IncrementalPID(PID* pid, float target, float current)//����ʽPID
{
    pid->priError = pid->lastError;
    pid->lastError = pid->error;
    pid->error = target - current;  // ���㵱ǰ���
    float Poutput = (pid->error - pid->lastError) * pid->kp;//����
    float Doutput = (pid->error + pid->priError - 2 * pid->lastError) * pid->kd;//΢��
    pid->integ = pid->error * pid->ki;//����
    //pid->integ = pid->integ > pid->maxInteg ? pid->maxInteg:pid->integ;
    //pid->integ = pid->integ < -pid->maxInteg ? -pid->maxInteg : pid->integ;
    limit(&pid->integ, pid->maxInteg);
    pid->output += Poutput + Doutput + pid->integ;
    return 0;
}

int PID_Imitate(float* current, PID* pid)
{
    *current += pid->output;
    return 0;
}

