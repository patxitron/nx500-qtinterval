#$(shell mkdir -p build >/dev/null)
#$(shell rm -f build/main.o)
PROJECT_DIR = $(dir $(realpath $(firstword $(MAKEFILE_LIST))))
export BUILDROOT := $(PROJECT_DIR)/buildroot-2021.02.5
export MOC := $(PROJECT_DIR)/buildroot-2021.02.5/output/host/usr/bin/moc

TARGET := src/qtinterval

.PHONY: $(TARGET)

all: release

debug: ARG := debug
debug: $(TARGET)

release: ARG := release
release: $(TARGET)

$(TARGET): $(MOC)
	$(MAKE) -C src $(ARG)

$(MOC):
	$(PROJECT_DIR)/do-submodule.sh buildroot-2021.02.5

clean:
	$(MAKE) -C src clean
