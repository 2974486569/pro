#ifndef __ZDT_X42_V2_H
#define __ZDT_X42_V2_H

#include "main.h"

/**********************************************************
*** ZDT_X42_V2.0�����ջ���������
*** ��д���ߣ�ZHANGDATOU
*** ����֧�֣��Ŵ�ͷ�ջ��ŷ�
*** �Ա����̣�https://zhangdatou.taobao.com
*** CSDN���ͣ�http s://blog.csdn.net/zhangdatou666
*** qq����Ⱥ��262438510
**********************************************************/

#define		ABS(x)		((x) > 0 ? (x) : -(x)) 
typedef enum {
	S_VER2   = 0,			/* ��ȡ�̼��汾�Ͷ�Ӧ��Ӳ���汾 */
	S_RL2    = 1,			/* ��ȡ��ȡ���������� */
	S_PID2   = 2,			/* ��ȡPID���� */
	S_VBUS2  = 3,			/* ��ȡ���ߵ�ѹ */
	S_CPHA2  = 5,			/* ��ȡ����� */
	S_ENCL2  = 7,			/* ��ȡ�������Ի�У׼��ı�����ֵ */
	S_TPOS2  = 8,			/* ��ȡ���Ŀ��λ�ýǶ� */
	S_VEL2   = 9,			/* ��ȡ���ʵʱת�� */
	S_CPOS2  = 10,			/* ��ȡ���ʵʱλ�ýǶ� */
	S_PERR2  = 11,			/* ��ȡ���λ�����Ƕ� */
	S_FLAG2  = 13,			/* ��ȡʹ��/��λ/��ת״̬��־λ */
	S_Conf2  = 14,			/* ��ȡ�������� */
	S_State2 = 15,			/* ��ȡϵͳ״̬���� */
	S_ORG2   = 16,     /* ��ȡ���ڻ���/����ʧ��״̬��־λ */
}SysParams_t2;


typedef enum {
  S_VER1   = 0,      /* ��ȡ�̼��汾�Ͷ�Ӧ��Ӳ���汾 */
  S_RL1    = 1,      /* ��ȡ��ȡ���������� */
  S_PID1   = 2,      /* ��ȡPID���� */
  S_ORG1   = 3,      /* ��ȡ������� */
  S_VBUS1  = 4,      /* ��ȡ���ߵ�ѹ */
  S_CBUS1  = 5,      /* ��ȡ���ߵ��� */
  S_CPHA1  = 6,      /* ��ȡ����� */
  S_ENC1   = 7,      /* ��ȡ������ԭʼֵ */
  S_CPUL1  = 8,      /* ��ȡʵʱ������������ʵʱλ�ü���õ����������� */
  S_ENCL1  = 9,      /* ��ȡ�������Ի�У׼��ı�����ֵ */
  S_TPUL1  = 10,     /* ��ȡ���������� */
  S_TPOS1  = 11,     /* ��ȡ���Ŀ��λ�� */
  S_OPOS1  = 12,     /* ��ȡ���ʵʱ�趨��Ŀ��λ�ã�����ģʽ��ʵʱλ�ã� */
  S_VEL1   = 13,     /* ��ȡ���ʵʱת�� */
  S_CPOS1  = 14,     /* ��ȡ���ʵʱλ�ã����ڽǶȱ������ۼӵĵ��ʵʱλ�ã� */
  S_PERR1  = 15,     /* ��ȡ���λ����� */
  S_TEMP1  = 16,     /* ��ȡ���ʵʱ�¶� */
  S_SFLAG1 = 17,     /* ��ȡ״̬��־λ */
  S_OFLAG1 = 18,     /* ��ȡ����״̬��־λ */
  S_Conf1  = 19,     /* ��ȡ�������� */
  S_State1 = 20,     /* ��ȡϵͳ״̬���� */
}SysParams_t1;

void ZDT_X42_V2_Reset_CurPos_To_Zero(uint8_t addr); // ����ǰλ������
void ZDT_X42_V2_Reset_Clog_Pro(uint8_t addr); // �����ת����
//void ZDT_X42_V2_Read_Sys_Params(uint8_t addr, SysParams_t1 s); // ��ȡ����
void ZDT_X42_V2_Modify_Ctrl_Mode(uint8_t addr, bool svF, uint8_t ctrl_mode); // ���������л�����/�ջ�����ģʽ
void ZDT_X42_V2_En_Control(uint8_t addr, bool state, uint8_t snF); // ���ʹ�ܿ���
void ZDT_X42_V2_Torque_Control(uint8_t addr, uint8_t sign, uint16_t t_ramp, uint16_t torque, uint8_t snF); // ����ģʽ����
void ZDT_X42_V2_Velocity_Control(uint8_t addr, uint8_t dir, uint16_t v_ramp, float velocity, uint8_t snF); // �ٶ�ģʽ����
void ZDT_X42_V2_Bypass_Position_LV_Control(uint8_t addr, uint8_t dir, float velocity, float position, uint8_t raf, uint8_t snF); // ֱͨ����λ��ģʽ����
//void ZDT_X42_V2_Traj_Position_Control(uint8_t addr, uint8_t dir, uint16_t acc, uint16_t dec, float velocity, float position, uint8_t raf, uint8_t snF); // �������߼Ӽ���λ��ģʽ����
void ZDT_X42_V2_Stop_Now(uint8_t addr, uint8_t snF); // �õ������ֹͣ�˶�
void ZDT_X42_V2_Synchronous_motion(uint8_t addr); // �������ͬ����ʼ�˶�
void ZDT_X42_V2_Origin_Set_O(uint8_t addr, bool svF); // ���õ�Ȧ��������λ��
void ZDT_X42_V2_Origin_Modify_Params(uint8_t addr, bool svF, uint8_t o_mode, uint8_t o_dir, uint16_t o_vel, uint32_t o_tm, uint16_t sl_vel, uint16_t sl_ma, uint16_t sl_ms, bool potF); // �޸Ļ������
void ZDT_X42_V2_Origin_Trigger_Return(uint8_t addr, uint8_t o_mode, bool snF); // �������������
void ZDT_X42_V2_Origin_Interrupt(uint8_t addr); // ǿ���жϲ��˳�����
void ZDT_X42_V2_Receive_Data(uint8_t *rxCmd, uint8_t *rxCount); // �������ݽ��պ���
void ZDT_X42_V2_Traj_Position_Control5(uint8_t addr, uint8_t dir, uint16_t acc, uint16_t dec, float velocity, float position, uint8_t raf, uint8_t snF); // �������߼Ӽ���λ��ģʽ����
//void ZDT_X42_V2_Read_Sys_Params5(uint8_t addr, SysParams_t1 s); // ��ȡ����


void ZDT_X42_V2_Traj_Position_Control(uint8_t addr, uint8_t dir, uint16_t vel, uint8_t acc, uint32_t clk, bool raF, bool snF);
void ZDT_X42_V2_Read_Sys_Params(uint8_t addr, SysParams_t2 s);
#endif
