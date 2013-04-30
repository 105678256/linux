#define	GPBCON				(*(volatile unsigned long *)0x56000010)
#define	GPBDAT				(*(volatile unsigned long *)0x56000014)

#define	GPB7_out	(1<<(7*2))
#define	GPB8_out	(1<<(8*2))
#define	GPB5_out	(1<<(5*2))
#define	GPB6_out	(1<<(6*2))

 
static unsigned long m_RandSeed;

/* 随机函数 */
inline unsigned long  Rand()  
{
    return (m_RandSeed=1664525L*m_RandSeed+1013904223L)>>5;
}

void wait(unsigned long dly)
{
	for(; dly > 0; dly--);
}

int main()
{
	unsigned long i = 0;
 
	GPBCON	 = GPB7_out|GPB8_out|GPB5_out|GPB6_out;

	while(1){
		wait(10000);
		GPBDAT = (~(i<<5));	//不必太计较这两句，随便写的
		i =  Rand();				//让LED随机闪烁
	}

	return 0;
}
