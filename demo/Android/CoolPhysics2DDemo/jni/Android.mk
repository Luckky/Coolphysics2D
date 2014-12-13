LOCAL_PATH:=$(call my-dir)

include $(CLEAR_VARS)
LOCAL_STATIC_LIBRARIES := \
	android_native_app_glue
LOCAL_LDLIBS := -llog -landroid -lEGL -lGLESv1_CM
LOCAL_MODULE:=nativeactivity
LOCAL_SRC_FILES:=native_activity.cpp
include $(BUILD_SHARED_LIBRARY)

$(call import-module,android/native_app_glue) 