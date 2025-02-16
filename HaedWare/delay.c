#include "delay.h"

/**********************************************************
***	Emm_V5.0步进闭环控制例程
***	编写作者：ZHANGDATOU
***	技术支持：张大头闭环伺服
***	淘宝店铺：https://zhangdatou.taobao.com
***	CSDN博客：http s://blog.csdn.net/zhangdatou666
***	qq交流群：262438510
**********************************************************/
/**
	*	@brief		毫秒级延时
	*	@param		int32_t u32Cnt
	*	@retval		无
	*/
void delay_ms(int32_t i32Cnt)
{
	__IO int32_t i32end = 0;

	SysTick->LOAD = 0xFFFFFF;
	SysTick->VAL  = 0;
	SysTick->CTRL = (SysTick_CTRL_ENABLE_Msk | SysTick_CTRL_CLKSOURCE_Msk);

	while(i32Cnt > 0)
	{
		SysTick->VAL = 0;
		i32end = 0x1000000 - (SystemCoreClock / 1000);
		while(SysTick->VAL > i32end);
		--i32Cnt;
	}

	SysTick->CTRL = (SysTick->CTRL & (~SysTick_CTRL_ENABLE_Msk));
}

/**
	*	@brief		软件延时
	*	@param		int32_t u32Cnt
	*	@retval		无
	*/
void delay_cnt(int32_t i32Cnt)
{
	while(i32Cnt > 0) { i32Cnt--; }
}
int compare(int a, int b)
{
	int tmp;
	if(a <= b)
	{
		tmp = a;
	}
	else
	{tmp = b;}
	return tmp;
}


void my_delay_us(uint32_t us)
{//对于stm32f4系列 168mhz大致是1us
		uint8_t i = 0;
		while(us--)
		{
			i = 42;
			while(i--);
		};
}
 
void my_delay_ms(uint32_t ms)
{//对于stm32f4系列 168mhz大致是1ms
		uint16_t i = 0;
		while(ms--)
		{
			i = 41750;
			while(i--);
		};
}
