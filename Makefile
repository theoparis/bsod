obj-m += bsod.o

ROOT=$(PWD)
MODULES_DIR=$(PWD)/install/lib/modules/6.6.0-rc5-next-20231013
ARCH=riscv

all:
	mkdir -p build
	+make -C $(MODULES_DIR)/build LLVM=1 ARCH=$(ARCH) M=$(ROOT)/build src=$(ROOT) modules

clean:
	+make -C $(MODULES_DIR)/build LLVM=1 ARCH=$(ARCH) M=$(ROOT)/build src=$(ROOT) clean

install: all
	+make -C $(MODULES_DIR)/build LLVM=1 ARCH=$(ARCH) M=$(ROOT)/build src=$(ROOT) modules_install INSTALL_MOD_PATH=$(ROOT)/install
