chmod u+x filename 只有自己可以执行，其它人不能执行
chmod ug+x filename 只有自己以及同一群可以执行，其它人不能执行
chmod a+x filename 所有人都可以执行　　
软件名 -v查看版本信息  version
使用openjtag进行调试时需要注意：1把开发板和jtag接好2开发板上电3把openjtag连接到电脑的usb接口上
vim安装：sudo apt-get install vim-gnome -y
Gitthub的使用:sudo apt-get install git git-core 
1在github上建立自己的项目，再在本地建立自己的库，
baron@baron:~$ cd github/ 
baron@baron:~/github$ mkdir linux 
sudo apt-get install git git-core thub$ cd linux/ 
baron@baron:~/github/linux$ vi readme 
baron@baron:~/github/linux$ git init 
Reinitialized existing Git repository in /home/baron/github/linux/.git/ 
baron@baron:~/github/linux$ git add readme 
baron@baron:~/github/linux$ git commit -m first 
[master (root-commit) 2236b85] first 
 1 file changed, 1 insertion(+) 
	baron@baron:~/github/linux$ git remote add origin git@github.com:105678256/linux.git
	baron@baron:~/github/linux$ git push -u origin master 
	baron@baron:~/github/linux$ mv ~/documents/mydoc.odt . 
	baron@baron:~/github/linux$ git add mydoc.odt 
	baron@baron:~/github/linux$ git commit 
	baron@baron:~/github/linux$ git push 
	git pull    
	git status  查看状态
	git log  查看历史
	gitclone

	u-boot移植
	移植U-Boot.2010.09到友善之臂mini2440（一） 
	一、在U-Boot中建立自己的开发板类型，并测试编译。 
	(1) 在工作目录/public下解压U－Boot-2010.09 
	[baron@baron:~/public]$ tar -xjvf  u-boot-2010.09.tar.bz2 

	[baron@baron:~/public/u-boot-2010.09$]$  cp -r board/samsung/smdk2410/ board/samsung/mini2440 

	[baron@baron:~/public/u-boot-2010.09$]$ cp board/samsung/mini2440/smdk2410.c board/samsung/mini2440/mini2440.c 

	修改mini2440目录下的Makefile，将COBJS:= smdk2410.o改为COBJS:= mini2440.o  
 
	修改u-boot根目录下的boards_cfg，在他下面按照smdk2410_config的格式建立mini2440_config的编译选项 
	 在boards.cfg的65行的 
	 smdk2410      arm      arm920t     -           samsung        s3c24x0 
	 后面添加 
	 mini2440       arm      arm920t     -           samsung        s3c24x0 
	 前面一定要用tab开头 
	 各项的意思如下: 
	 arm: CPU的架构(ARCH)arm920t: CPU的类型(CPU)，其对应于cpu/arm920t子目录。 
	 mini2440: 开发板的型号(BOARD)，对应于board/ mini2440目录。NULL: 开发者/或经销商(vender),NULL为没有。s3c24x0: 片上系统(SOC)。 
	 注意下面要与自己的开发系统一致,一般是默认arm-linux-！ 
	 CROSS_COMPILE=arm-linux- gcc
	   
	   3 在include/configs/中建立开发板的配置头文件 
	   [baron@baron:~/public/u-boot-2010.09$]$ cp include/configs/smdk2410.h  include/configs/mini2440.h 
	   4 测试编译能否成功 
	   回到U-Boot主目录，(若之前有编译过，最好执行一下make clean)  make mini2440_config，再make，编译生成u-boot.bin成功。 
	     1、配置 
	     [root@localhost u-boot-2010.09]$ make  mini2440_config 
	     Configuring for mini2440 board... 
	    2、测试编译 
	     [root@localhost u-boot-2010.09]$ make 
    测试通过后进行下一步
修改arch/arm/cpu/arm920t/start.S
第141行 #else 改为#elif defined(CONFIG_S3C2410)||defined(CONFIG_S3C2440)
第147行添加# endif

#if defined(CONFIG_S3C2410)
#  define INTSUBMSK_val	0x3ff
#  define MPLLCON_val	((0x90 << 12) + (0x7 << 4) + 0x0)	/*  202.00 MHz */
#  define UPLLCON_val	((0x78 << 12) + (0x2 << 4) + 0x3)
#  define CLKDIVN_val	3 /*  FCLK:HCLK:PCLK = 1:2:4 */
#elif defined(CONFIG_S3C2440)
#  define INTSUBMSK_val	0xffff
#  define MPLLCON_val	((0x7f << 12) + (0x2 << 4) + 0x1)	/*  405.00 MHz */
#  define UPLLCON_val	((0x38 << 12) + (0x2 << 4) + 0x2)
#  define CLKDIVN_val	5 /*  FCLK:HCLK:PCLK = 1:3:6 */
#endif
第170行改为# if defined(CONFIG_S3C2410)||defined(CONFIG_S3C2440)
	ldr	r1, =0x3ff 改为	ldr	r1, =INTSUBMSK_val
175行添加	/*  Clock asynchronous mode */
	mrc	p15, 0, r1, c1, c0, 0
	orr	r1, r1, #0xc0000000
	mcr	p15, 0, r1, c1, c0, 0
			
			
#define LOCKTIME	0x4c000000
#define UPLLCON		0x4c000008
			
	ldr	r0, =LOCKTIME
	mov	r1, #0xffffff
	str	r1, [r0]
						

	ldr	r0, =UPLLCON
	ldr	r1, =UPLLCON_val
	str	r1, [r0]
										/*  Page 7-19, seven nops between UPLL and MPLL */
	nop
	nop
	nop
	nop
	nop
	nop
	nop
								
	ldr	r1, =MPLLCON_val
	str	r1, [r0, #-4]		/*  MPLLCON */
										207行mov	r1, #3改为	mov	r1, #CLKDIVN_val
215行后添加# ifndef CONFIG_LL_INIT_NAND_ONLY
218添加#endif
把adr	r0, _start 移到relocate:之前
把beq	stack_setup改为beq	done_relocate
在235行左右#endif /*CONFIG_SKIP_RELOCATE_UBOOT*/之前添加
	mov	r0, #0			/*  flush v3/v4 cache	*/
	mcr	p15, 0, r0, c7, c7, 0
	ldr	pc, _done_relocate	/*  jump to relocated code	    */
_done_relocate:
	.word	done_relocate
done_relocate:
start.S修改完毕
include/configs/mini2440.h
修改宏2410为2440
在最后再加一个宏#define CONFIG_LL_INIT_NAND_ONLY














		 
	     tftp服务器配置
	     sudo apt-get install tftp tftpd openbsd-inetd
	     sudo mkdir /tftpboot
	     sudo chmod -R 777 /tftpboot
	    sudo chown -R nobody /tftpboot
	     修改/etc/inetd.conf 文件，指定目录
	     ON
	        sudo /etc/init.d/openbsd-inetd restart
	 
	     Openocd安装及配置：sudo apt-get install openocd -y
	     http://sourceforge.net/projects/openocd/files/openocd/
	      sudo apt-get install libftdi-dev 
	 
	      baron@baron-desktop:/tmp$ tar xjvf /opt/tarball/openocd-0.6.0.tar.bz2 
	      baron@baron-desktop:/tmp/openocd-0.6.0$ ./configure --enable-ft2232_libftdi 
	    baron@baron-desktop:/tmp/openocd-0.6.0$ make&&sudo make install
	 
	      #
	      # Openmoko USB JTAG/RS232 adapter
	      #
 	      # http://wiki.openmoko.org/wiki/Debug_Board_v3
	      #
	     interface ft2232
	     ft2232_device_desc "USB<=>JTAG&RS232"
	      ft2232_layout jtagkey
	      ft2232_vid_pid 0x1457 0x5118
	      source [find target/samsung_s3c2440.cfg]
	      adapter_khz 6000
	      # speed up memory downloads
	      arm7_9 fast_memory_access enable
	 
	 
	 
	      arm-linux-insight安装及配置http://sources.redhat.com/insight/
	      baron@baron-desktop:~$ cd /tmp/ 
	      baron@baron-desktop:/tmp$ tar xjvf /opt/tarball/insight-6.8-1a.tar.bz2
	      baron@baron-desktop:/tmp$ cd insight-6.8-1/ 
	      baron@baron-desktop:/tmp/insight-6.8-1$ ./configure --target=arm-linux --enable-sim 
	      修改Makefile否则编译会出错
	      vi insight-6.8-1/gdb/Makefile
             WARN_CFLAGS =  -Wall -Wdeclaration-after-statement -Wpointer-arith -Wformat-nonliteral -Wno-pointer-sign -Wno-unused -Wno-switch -Wno-char-subscripts
	   /*  #WERROR_CFLAGS = -Werrorcd*/
	    上面一行要注释掉baron@baron-desktop:/tmp/insight-6.8-1$ make && sudo make install 
	 
	      arm-linux-gdb安装及配置官方网站：http://www.gnu.org/software/gdb/
	 
	      交叉编译器安装： 
	      tar xjvf arm-linux-gcc-4.3.2.tar.bz2 -C /，默认会安装到/usr/local/arm/4.3.2目录 
	      修改用户主目录下.bashrc添加 PATH=$PATH:/usr/local/arm/4.3.2/bin 然后注销，
	      或者执行. .bashrc(source .bashrc)，不过后者只对当前终端有效
	      kermit的使用
	      ckermit需要有一个配置文件，一般放到用户主目录下，文件名为/.kermrc，把下面内容copy到配置文件中
	      #set line /dev/ttyS0
	      set line /dev/ttyUSB0
	      set speed 115200
	      set carrier-watch off
	      set handshake none
	      set flow-control none
	      robust
	      set file type bin
	      set file name lit
	      set rec pack 1000
	      set send pack 1000
	      set window 5
	      注意上面的配置文件中
	      set line /dev/ttyUSB0指定使用的设备节点，这里使用的是usb转串口，如果直接使用串口（如pc机）这里就要指定为set line /dev/ttyS0
	      kermit -c 
	      离开kermit    ctrl+\再按c
	      再进入kermit   按c
	 
	      用usb烧写u-boot
	      首先启动方式拨到nor启动，连接好串口及usb，打开kermit，选a,
      给开发板上电,执行命令s3c2410_boot_usb  u-boot.bin,需要权限sudo  烧写完成把启动开关拨到nand启动，然后重启开发板，进入可以练习uboot命令.
	 
	       >halt
	       >reset
	       >resume
	       >step
	       >bp
	       >rbp
	       >rwp
	       >poll
	       >mdb ['phys'] address [count] 
	             display memory bytes 
	       >mdh ['phys'] address [count] 
	            display memory half-words 
	       >mdw ['phys'] address [count] 
	            display memory words
	       >mwb ['phys'] address value [count] 
	         write memory byte 
	       >mwh ['phys'] address value [count] 
	          write memory half-word 
	       >mww ['phys'] address value [count] 
	          write memory word
用openjtag烧录
1连接好开发板和jtag，然后给开发板上电，把jtag连接到电脑上，打开openocd
另开一窗口输入telnet localhost 4444     
 >halt
 >arm920t cp15 2 0
 >step
 >nand prove 0
 >nand list
 >nand write 0 /home/.../u-boot.bin 0
 >nand verify 0 /home/.../u-boot.bin 0
	 
     U-Boot
     常用命令
     help              saveenv                run                tftp                   bootm                     tftpboot               nand read                  nand write                   nand erase           set bootfile uImage  printenv       bdi          md
	 
  busybox版本: busybox-1.15.2.tar.bz2	(D5653E5B74B17DBB1EEECDA8B8F22C0A) 
 下载：http://busybox.net/downloads/busybox-1.15.2.tar.bz2 
	 //
make menuconfig 
选项配置  
 Build Options(arm-linux-) Cross Compiler prefix 
 Installation Options[*] Don't use /usr 
  make && make install 
udev版本: udev-139.tar.bz2			(7E705E237D29734C77BC26F6CCBC4594) 
  http://www.kernel.org/pub/linux/utils/kernel/hotplug/udev-139.tar.bz2 
	 //
 udev是用户管理设备的工具，用于替代原来的devfs 
   编译选项： ./configure --target=arm-linux --host=arm-linux LD=arm-linux-ld 
 编译完成后复制udevd和udevadm到自己的文件系统中相应目录下 
  cp udev/udevd nfsroot/sbin
  cp udev/udevadm nfsroot/sbin 
	 
  在启动脚本(如/etc/init.d/rcS)中加入以下语句： 
   if test -x /sbin/udevd 
   then 
 	echo "Starting udevd ..." 
/sbin/udevd --daemon 
	/sbin/udevadm trigger 
	/sbin/udevadm settle 
        fi 
udev的配置 
[rrr@localhost udev]$ pwd 
/home/rrr/nfsroot/etc/udev 
[rrr@localhost udev]$ ls 
rules.d  scripts  udev.conf 
	 
目录rules.d直接从udev-139/rules/rules.d复制过来，udev.conf是从udev-139/udev.conf复制得来的
scripts目录下的两个脚本是用于挂载SD卡和U盘的 
fdbai@localhost:/nfsroot/fdbai/root26/home/newroot26/etc/udev$ ls scripts/ 
mmc.sh  usb.sh 
                                       				'
