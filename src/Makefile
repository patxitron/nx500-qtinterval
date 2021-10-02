SYSROOT = $(BUILDROOT)/output/host/arm-buildroot-linux-musleabihf/sysroot
INCLUDEPATH = $(SYSROOT)/usr/include
LIBPATH = $(SYSROOT)/usr/lib
QTPLUGINS = $(LIBPATH)/qt/plugins
BINARIES = $(BUILDROOT)/output/host/bin
PREFIX = arm-buildroot-linux-musleabihf-

CXX = $(BINARIES)/$(PREFIX)g++
LD = $(BINARIES)/$(PREFIX)g++
STRIP = $(BINARIES)/$(PREFIX)strip

DBGFLAGS = -g
OPTFLAGS = -Os
CXXFLAGS = -fno-exceptions -fno-rtti -ffunction-sections -fdata-sections \
           -std=c++14 -Wall -pedantic -I$(INCLUDEPATH) -I$(INCLUDEPATH)/qt5 \
           -I$(INCLUDEPATH)/qt5/QtGui -I$(INCLUDEPATH)/qt5/QtCore \
           -I$(INCLUDEPATH)/qt5/QtWidgets
LDFLAGS = -static -Wl,--gc-sections
STRIPFLAGS = --strip-all --remove-section=.comment --remove-section=.note

QT_INCLUDES = mwin.hpp
CXXSOURCES = mwin.cpp main.cpp
LIBS = -L$(QTPLUGINS)/platforms -lqxcb -lQt5XcbQpa -lQt5Xml -lQt5Widgets \
       -lQt5Gui -lQt5EdidSupport -lQt5XkbCommonSupport -lQt5FontDatabaseSupport \
       -lQt5EventDispatcherSupport -lQt5ThemeSupport -lQt5ServiceSupport \
       -lQt5Core -lxcb-render -lxcb-render-util -lxcb-randr -lxcb-xinerama \
       -lxcb-shape -lxcb-image -lxcb-xfixes -lxcb-shm -lxcb-xkb -lxcb-xinput \
       -lxcb-util -lxcb-sync -lxcb-icccm -lxcb-keysyms -lxcb -lxdo -lXtst \
       -lxkbcommon-x11 -lxkbcommon -lXinerama -lXext -lXau -lXcursor -lXdmcp \
       -lX11-xcb -lX11 -lSM -lICE -lfontconfig -lfreetype -lfontenc -lexpat \
       -luuid -ljpeg -lpng -lz -lbz2 -lpcre2-16
TARGET = qtinterval

MOCSOURCES = $(QT_INCLUDES:%.hpp=build/moc_%.cpp)
CXXOBJECTS = $(CXXSOURCES:%.cpp=build/%.o) 
MOCOBJECTS = $(MOCSOURCES:build/%.cpp=build/%.o)

.PHONY: all clean

all: release

release: CXXFLAGS := $(OPTFLAGS) $(CXXFLAGS)
release: LDFLAGS := $(OPTFLAGS) $(LDFLAGS)
release: $(TARGET)
	$(STRIP) $(STRIPFLAGS) $(TARGET)

debug: CXXFLAGS := $(DBGFLAGS) $(CXXFLAGS)
debug: LDFLAGS := $(DBGFLAGS) $(LDFLAGS)
debug: $(TARGET)

build:
	@mkdir -p build

$(TARGET): $(MOCOBJECTS) $(CXXOBJECTS)
	@echo Linking $@
	$(LD) -o $@ $(LDFLAGS) $(CXXOBJECTS) $(MOCOBJECTS) $(LIBS)

$(MOCOBJECTS): $(MOCSOURCES)
$(MOCOBJECTS): build/%.o: build/%.cpp
	@echo Compiling $@
	$(CXX) -o $@ $(CXXFLAGS) $(INCLUDES) -c $<

$(CXXOBJECTS): build
$(CXXOBJECTS): build/%.o: %.cpp
	@echo Compiling $@
	$(CXX) -o $@ $(CXXFLAGS) $(INCLUDES) -c $<

$(MOCSOURCES): build
$(MOCSOURCES): build/moc_%.cpp: %.hpp
	@echo Meta-compiling $@
	$(MOC) -o $@ $<

clean:
	rm -rf build $(TARGET) core
