#define GPBCON (*(volatile unsigned long *)0x56000010)
#define GPBDAT (*(volatile unsigned long *)0x56000014)
#define GPGCON (*(volatile unsigned long *)0x56000060)
#define GPGDAT (*(volatile unsigned long *)0x56000064)
/*
 *led1-4 分别对应GPB5-8
 */
#define GPB5_out (1<<(5*2))
#define GPB6_out (1<<(6*2))
#define GPB7_out (1<<(7*2))
#define GPB8_out (1<<(8*2))  
/*
 * key1-4 对应 GPG0 GPG3 GPG5 GPG6
 */
#define GPG0_in ~(3<<(0*2))
#define GPG3_in ~(3<<(3*2))
#define GPG5_in ~(3<<(5*2))
#define GPG6_in ~(3<<(6*2))
int main(void)
{
	unsigned long dat;
	//设置Led1-4为输出
	GPBCON=GPB5_out|GPB6_out|GPB7_out|GPB8_out;
	//设置key1-4为输入
	GPGCON=GPG0_in&GPG3_in&GPG5_in&GPG6_in;
	GPBDAT=0xffff;
	while(1) //轮询方式
	{
		dat=GPGDAT;
		if(dat&(1)) //k1没有按下
		{
			GPBDAT|=(1<<5);    //熄灭led1
		}
		else
		{
			GPBDAT&=~(1<<5);   //点亮Led1
		}
		if(dat&(1<<3)) //k2没有按下
		{
			GPBDAT|=(1<<6);    //熄灭led2
		}
		else
		{
			GPBDAT&=~(1<<6);   //点亮Led2
		}
		if(dat&(1<<5)) //k3没有按下
		{
			GPBDAT|=(1<<7);    //熄灭led3
		}
		else
		{
			GPBDAT&=~(1<<7);   //点亮Led3
		}
		if(dat&(1<<6)) //k4没有按下
		{
			GPBDAT|=(1<<8);    //熄灭led4
		}
		else
		{
			GPBDAT&=~(1<<8);   //点亮Led4
		}
	}     
	return 0;
}
