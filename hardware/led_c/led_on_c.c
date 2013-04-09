#define GPBCON	(*(volatile unsigned long *)0x56000010)
#define GPBDAT	(*(volatile unsigned long *)0x56000014)
int main()
{
GPBCON = 0x15401;
GPBDAT = 0x000;
return 0;
}

