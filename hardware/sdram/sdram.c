
#define	GPBCON		(*(volatile unsigned long *)0x56000010)
#define	GPBDAT		(*(volatile unsigned long *)0x56000014)

#define	GPB5_out	(1<<(5*2))
#define	GPB6_out	(1<<(6*2))
#define	GPB7_out	(1<<(7*2))
#define	GPB8_out	(1<<(8*2))

void wait(unsigned long dly)
{
	for(; dly > 0; dly--);
}

int main()
{
	unsigned long i = 0;

	GPBCON	 = GPB5_out|GPB6_out|GPB7_out|GPB8_out;

	while(1){
		wait(3000);
		GPBDAT = (~(i<<5));
		if(++i == 16)
			i = 0;
	}

	return 0;
}
