obj-m += Hello.o

KDIR = /usr/src/linux-headers-4.9.0-9-amd64

all:
     $(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules 
     
clean:
     rm -rf *.o *.ko *.mod.* *.symvers *.order
