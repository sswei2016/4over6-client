LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := backend_jni
LOCAL_SRC_FILES := pipe.c sock.c main.c message.c stream.c
LOCAL_LDLIBS := -llog



include $(BUILD_SHARED_LIBRARY)

