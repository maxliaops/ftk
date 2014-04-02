
COMPILE = 
CC     	= $(COMPILE)gcc
AR     	= $(COMPILE)ar
LD     	= $(COMPILE)ld
OBJCOPY	= $(COMPILE)objcopy
NM      = $(COMPILE)nm
OBJDUMP	= $(COMPILE)objdump
CHMOD  	= chmod
STRIP   = $(COMPILE)strip
PWD     = $(shell pwd)/..


CFLAGS += -DHAVE_CONFIG_H -DLINUX

CFLAGS += -g -O2 
CFLAGS += -I../lib \
		  -I../lib/fb -I../lib/x11

LDFLAGS += -lpng -ljpeg -ldl -L../lib -lktk
LDFLAGS += -lX11 -lfreetype

all : $(OBJS)
	$(CC) $(CFLAGS) demo_label.c -o demo_label.out $(LDFLAGS)
	$(CC) $(CFLAGS) demo_button.c -o demo_button.out $(LDFLAGS)
	$(CC) $(CFLAGS) demo_keyboard.c -o demo_keyboard.out $(LDFLAGS)
	$(CC) $(CFLAGS) demo_ime.c -o demo_ime.out $(LDFLAGS)
	$(CC) $(CFLAGS) demo_wait_box.c -o demo_wait_box.out $(LDFLAGS)
	$(CC) $(CFLAGS) demo_dialog.c -o demo_dialog.out $(LDFLAGS)
	$(CC) $(CFLAGS) demo_transparent.c -o demo_transparent.out $(LDFLAGS)
	$(CC) $(CFLAGS) demo_text_view.c -o demo_text_view.out $(LDFLAGS)
	$(CC) $(CFLAGS) demo_scroll_bar.c -o demo_scroll_bar.out $(LDFLAGS)

clean:
	rm -rf *.o *.out

