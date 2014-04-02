
DISPLAY_ENGINE = FB
FONT_ENGINE    = DEFAULT
IM_ENGINE      = NONE


COMPILE = 
CC     	= $(COMPILE)gcc
CPP    	= $(COMPILE)g++
AR     	= $(COMPILE)ar
LD     	= $(COMPILE)ld
OBJCOPY	= $(COMPILE)objcopy
NM      = $(COMPILE)nm
OBJDUMP	= $(COMPILE)objdump
CHMOD  	= chmod
PWD     = $(shell pwd)/..


CFLAGS += -DHAS_PNG -DHAS_JPEG -DHAS_BMP -DFTK_SUPPORT_C99 -DFTK_SHARED_CANVAS -DFTK_HAS_DLOPEN
CFLAGS += -DHAVE_CONFIG_H -DLINUX -DHAVE_CONFIG_FTK_H -DUSE_LINEBREAK 
CFLAGS += -DDATA_DIR="\"$(PWD)/data/\"" -DLOCAL_DATA_DIR="\"$(PWD)/data/\"" -DFTK_DATA_ROOT="\"$(PWD)/data/\""  -DTESTDATA_DIR="\"$(PWD)/testdata/\"" -DFTK_CNF="\"$(PWD)/data/ftk.cnf\""

CFLAGS += -g -O2 -fPIC
CFLAGS += -I. \
          -Iim/gpinyin/include/  \
          -Iim/gpinyin/ftk \
		  -Ifont \
          -Idisplay/fb \
		  -Idisplay/x11

ifeq ($(IM_ENGINE), PINYIN)
	CFLAGS += -DUSE_GPINYIN
endif

ifeq ($(FONT_ENGINE),DEFAULT)
	CFLAGS += -DFTK_FONT="\"gb2312.fnt\"" -DUSE_DEFAULT_FONT
endif

ifeq ($(FONT_ENGINE),FREETYPE)
	CFLAGS += -DFTK_FONT="\"font.ttf\"" -DUSE_FREETYPE -I/usr/include/freetype2
endif

ifeq ($(DISPLAY_ENGINE), FB)
	CFLAGS += -DUSE_LINUX_FB -DUSE_LINUX_NATIVE 
else
	CFLAGS += -DUSE_LINUX_X11 -DDISPLAY_PARAM="\"linux-x11:480x272\""
endif

CPPFLAGS += $(CFLAGS)

LDFLAGS += -shared

SOURCE += $(wildcard *.c)

ifeq ($(IM_ENGINE), PINYIN)
	SOURCE += $(wildcard im/gpinyin/share/*.cpp)
	SOURCE += $(wildcard im/gpinyin/ftk/*.cpp)
else
	SOURCE += $(wildcard im/default/*.c)
endif

ifeq ($(DISPLAY_ENGINE), FB)
	SOURCE += $(wildcard display/fb/*.c)
else
	SOURCE += $(wildcard display/x11/*.c)
endif

ifeq ($(FONT_ENGINE),FREETYPE)
	SOURCE += font/ftk_font_freetype.c
endif

ifeq ($(FONT_ENGINE),DEFAULT)
	SOURCE += font/ftk_font_default.c font/fontdata.c
endif

OBJS += $(addsuffix .o, $(basename $(SOURCE)))

all : $(OBJS)
	$(CC) ${LDFLAGS} -o libftk.so ${OBJS}

clean:
	rm -rf *.o im/gpinyin/share/*.o im/gpinyin/ftk/*.o  im/default/*.o display/fb/*.o display/x11/*.o font/*.o

