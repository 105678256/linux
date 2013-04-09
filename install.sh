# make menuconfig
sudo apt-get install libncurses5-dev -y

# ckermit
sudo apt-get install ckermit automake -y

#安装IBus框架，在终端输入以下命令：
sudo apt-get install ibus ibus-clutter ibus-gtk ibus-gtk3 ibus-qt4
#启动IBus框架，在终端输入：
im-switch -s ibus
#IBus拼音
sudo apt-get install ibus-pinyin
#IBUS五笔
sudo apt-get install ibus-table-wubi
#谷歌拼音输入法
sudo apt-get install ibus-googlepinyin
#设置IBus框架  www.2cto.com  
ibus-setu
# 显示输入法
ibus-daemon -drx

#ftdi
 sudo apt-get install libftdi-dev

 # openocd
 sudo apt-get install openocd -y

 # Chromium, fast and best browser
 sudo apt-get install chromium-browser -y

# vim安装：
 sudo apt-get install vim-gnome -y

# tftp服务器配置
 sudo apt-get install tftp tftpd openbsd-inetd
 sudo mkdir /tftpboot
 sudo chmod -R 777 /tftpboot
 sudo chown -R nobody /tftpboot
# Ktouch打字练习
sudo apt-get install ktouch
#TypeSpeed
sudo apt-get install typespeed
#Gitthub
sudo apt-get install git git-core
更新文件
sudo apt-get update
