
#define	GPBCON		(*(volatile unsigned long *)0x56000010)
#define	GPBDAT		(*(volatile unsigned long *)0x56000014)

#define	GPGCON		(*(volatile unsigned long *)0x56000060)
#define	GPGDAT		(*(volatile unsigned long *)0x56000064)

/*
LED1-4��ӦGPB5-8
*/

#define	GPB5_out	(1<<(5*2))
#define	GPB6_out	(1<<(6*2))
#define	GPB7_out	(1<<(7*2))
#define	GPB8_out	(1<<(8*2))

/*
K1-K4��ӦGPF0 3 5 6
*/
#define	GPG0_in		~(3<<(0*2))
#define	GPG3_in		~(3<<(3*2))
#define	GPG5_in		~(3<<(5*2))
#define	GPG6_in		~(3<<(6*2))


int main()
{

	GPBCON	 =GPB5_out | GPB6_out | GPB7_out | GPB8_out ;	//LED1-LED4��Ӧ��4��������Ϊ���
	GPGCON &= GPG0_in & GPG3_in & GPG5_in & GPG6_in ;		//K1-K4��Ӧ��4��������Ϊ����

	while(1){
		GPBDAT	= ((GPGDAT & 0x01)<<5) | ((GPGDAT & 0x08)<<3)|((GPGDAT&0x060)<<2);	//��KnΪ0(��ʾ����)������LEDnΪ0(��ʾ����)
	}

	return 0;
}
