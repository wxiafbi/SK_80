/*-------------------------------------------------*/
/*            超纬电子STM32系列开发板              */
/*-------------------------------------------------*/
/*                                                 */
/*             操作看门狗功能的源文件              */
/*                                                 */
/*-------------------------------------------------*/

#include "stm32f10x.h"  //包含需要的头文件

/*-------------------------------------------------*/
/*函数名：初始化独立看门狗                         */
/*参  数：prer:分频数:0~7                          */
/*参  数：rlr:自动重装载值                         */
/*返回值：无                                       */
/*-------------------------------------------------*/
void IWDG_Init(unsigned char prer,unsigned int rlr)
{
	IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable); //使能对看门狗的写权限	
	IWDG_SetPrescaler(prer);                      //设置看门狗分频系数
	IWDG_SetReload(rlr);                          //设置看门狗装载值
	IWDG_ReloadCounter();                         //加载计数	
	IWDG_Enable();                                //使能看门狗
}

/*-------------------------------------------------*/
/*函数名：喂狗                                     */
/*参  数：无                                       */
/*返回值：无                                       */
/*-------------------------------------------------*/
void IWDG_Feed(void)
{
	IWDG_ReloadCounter();                        //加载值
}
