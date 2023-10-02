#include <stdio.h>
#include "PID.h"

int main()
{
    //����PID��������
    PID* pid_set_point;
    PID pid_set;
    pid_set_point = &pid_set;

    //���ڽ���pid��������ֵ
    float u_p = 0;
    float u_i = 0;

    //������ʾerror�仯
    float error_print_p = 0;
    float error_print_i = 0;
    
    //����pidֵ
    printf("����P��");
    scanf_s("%f", &pid_set.kp);

    printf("����I��");
    scanf_s("%f", &pid_set.ki);
    
    printf("����D��");
    scanf_s("%f", &pid_set.kd);
   
    //��ʼ��
    PID_Init();
    ERROR_Init();

    PID_SetParameter(pid_set_point);

    printf("λ��ʽPID��                ����ʽPID��\n");
    while (1)
    {
        //��ȡerror
        error_get_p();
        error_get_i();
        
        //��ȡ�ƶ���
        u_p = PID_PostionalPID();
        u_i = PID_IncrementalPID();

        //�ƶ�
        error_print_p = move_p(u_i);
        error_print_i = move_i(u_p);
        
        //��ʾerror�仯
        printf("%f                         %f \n", error_print_p,error_print_i);
        
        system("pause");//ͣһ�£�Ҫ��Ȼ��̫����
    }
    return 0;
}