BASE_PATH := $(call my-dir)
LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)


LOCAL_SRC_FILES:= \
	src/os/linux/ftk_linux.c


LOCAL_SHARED_LIBRARIES := \
	libc

LOCAL_C_INCLUDES += \
	$(LOCAL_PATH)/src/os/linux \
	$(LOCAL_PATH)/src


LOCAL_MODULE:= libftk

include $(BUILD_SHARED_LIBRARY)
