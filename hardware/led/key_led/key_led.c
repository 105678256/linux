#define GPBCON (*(volatile unsigned long *)0x56000010)
#define GPBDAT (*(volatile unsigned long *)0x56000014)
#define GPGCON (*(volatile unsigned long *)0x56000060)
#define GPGDAT (*(volatile unsigned long *)0x56000064)


/* LED1-4 对应 GPB5-8 */ 
#define GPB5_out (1<<(5*2))
#define GPB6_out (1<<(6*2))
#define GPB7_out (1<<(7*2))
#define GPB8_out (1<<(8*2))


/* K1对应GPG0,K2对应GPG3 K3对应GPG5  K4 对应GPG6 K5对应GPG7 K6对应 GPG11  */ 
#define GPG0_in ~(3<<(0*2))
#define GPG3_in ~(3<<(3*2))
#define GPG5_in ~(3<<(5*2))
#define GPG6_in ~(3<<(6*2))


int main()
{
unsigned long dwDat;
	GPBCON =GPB5_out | GPB6_out | GPB7_out | GPB8_out ;


	GPGCON &= GPG0_in & GPG3_in & GPG5_in & GPG6_in ;
	while(1){

	GPBDAT = ((GPGDAT & 0x01)<<5)|((GPGDAT & 0x08) << 3)|((GPGDAT & 0x60)<<2);
#if 0	 //若Kn为0(表示按下)，则令LEDn为0(表示点亮)
            dwDat = GPGDAT;             // 读取GPG管脚电平状态
        
            if (dwDat & (1<<0))        // K1没有按下
                GPBDAT |= (1<<5);       // LED1熄灭
            else    
                GPBDAT &= ~(1<<5);      // LED1点亮
                
            if (dwDat & (1<<3))         // K2没有按下
                GPBDAT |= (1<<6);       // LED2熄灭
            else    
                GPBDAT &= ~(1<<6);      // LED2点亮
    
            if (dwDat & (1<<5))         // K3没有按下
                GPBDAT |= (1<<7);       // LED3熄灭
            else    
                GPBDAT &= ~(1<<7);      // LED3点亮
    
            if (dwDat & (1<<6))         // K4没有按下
                GPBDAT |= (1<<8);       // LED4熄灭
            else    
                GPBDAT &= ~(1<<8);      // LED4点亮
    
#endif
	}


	return 0;
}
