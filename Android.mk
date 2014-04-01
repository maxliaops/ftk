BASE_PATH := $(call my-dir)
LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_CFLAGS += -DLINUX
LOCAL_CFLAGS += -DUSE_LINUX_NATIVE
LOCAL_CFLAGS += -DHAS_PNG
LOCAL_CFLAGS += -DHAS_JPEG
LOCAL_CFLAGS += -DTESTDATA_DIR=\"$(LOCAL_PATH)/testdata\"
LOCAL_CFLAGS += -DFTK_DATA_ROOT=\"/data/ndroid/ftk\"
LOCAL_CFLAGS += -DLOCAL_DATA_DIR=\"$(LOCAL_PATH)\"
LOCAL_CFLAGS += -DDATA_DIR=\"/data/ndroid/ftk/base\"
LOCAL_CFLAGS += -DFTK_FONT=\"unicode.fnt\"
LOCAL_CFLAGS += -Wno-sign-compare -Wno-missing-field-initializers

LOCAL_SRC_FILES:= \
	src/os/linux/ftk_linux.c \
	src/os/linux/ftk_mmap_linux.c \
	src/ftk_canvas.c \
	src/ftk_source_primary.c \
	src/ftk_wnd_manager_default.c \
	src/ftk_label.c \
	src/ftk_source_timer.c \
	src/ftk_bitmap.c \
	src/ftk_main_loop.c \
	src/ftk_util.c \
	src/ftk_bitmap_factory.c \
	src/ftk_image_jpeg_decoder.c \
	src/ftk_image_png_decoder.c \
	src/ftk_source_idle.c \
	src/ftk_widget.c \
	src/ftk.c \
	src/ftk_window.c \
	src/ftk_sources_manager.c \
	src/ftk_globals.c \
	src/ftk_button.c \
	src/ftk_image.c \
	src/ftk_log.c \
	src/ftk_dialog.c \
	src/ftk_status_item.c \
	src/ftk_status_panel.c \
	src/ftk_menu_panel.c \
	src/ftk_menu_item.c \
	src/ftk_app_window.c \
	src/ftk_entry.c \
	src/ftk_text_buffer.c \
	src/ftk_icon_cache.c \
	src/ftk_animator_expand.c \
	src/ftk_progress_bar.c \
	src/ftk_radio_group.c \
	src/ftk_check_button.c \
	src/ftk_gesture.c \
	src/ftk_wait_box.c \
	src/ftk_scroll_bar.c \
	src/ftk_sprite.c \
	src/ftk_display.c \
	src/ftk_xml_parser.c \
	src/ftk_xul.c \
	src/ftk_expr.c \
	src/ftk_list_view.c \
	src/ftk_list_model_default.c \
	src/ftk_list_render_default.c \
	src/ftk_icon_view.c \
	src/ftk_theme.c \
	src/ftk_painter.c \
	src/ftk_text_view.c \
	src/fontdata.c \
	src/ftk_font_default.c \
	src/backend/fb/ftk_display_fb.c \
	src/backend/fb/ftk_source_input.c \
	src/backend/fb/ftk_backend_fb.c


LOCAL_STATIC_LIBRARIES := \
	libpng \

LOCAL_SHARED_LIBRARIES := \
	libc \
	libjpeg \
	libz

LOCAL_C_INCLUDES += \
	$(LOCAL_PATH)/src/os/linux \
	$(LOCAL_PATH)/src/backend/fb \
	$(LOCAL_PATH)/src \
	external/libpng \
	external/jpeg \
	external/zlib

LOCAL_MODULE:= libftk

include $(BUILD_SHARED_LIBRARY)
