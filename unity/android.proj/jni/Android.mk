LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := cocos2dlua_shared

LOCAL_MODULE_FILENAME := libLz4forUnity


LOCAL_SRC_FILES := \
				$(LOCAL_PATH)/../../Classes/base64.cc \
				$(LOCAL_PATH)/../../Classes/buffer.cc \
				$(LOCAL_PATH)/../../Classes/cellsLz4.cc \
				$(LOCAL_PATH)/../../Classes/UnityAPI.cc \
				$(LOCAL_PATH)/../../../lz4-lua/lz4/lz4.c \
				$(LOCAL_PATH)/../../../lz4-lua/lz4/lz4frame.c \
				$(LOCAL_PATH)/../../../lz4-lua/lz4/lz4hc.c \
				$(LOCAL_PATH)/../../../lz4-lua/lz4/xxhash.c \

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes \
					$(LOCAL_PATH)/../../../lz4-lua/lz4 \


LOCAL_STATIC_LIBRARIES += cocos2d_simulator_static

# _COCOS_LIB_ANDROID_BEGIN
# _COCOS_LIB_ANDROID_END

include $(BUILD_SHARED_LIBRARY)
# $(call import-add-path, $(LOCAL_PATH)/../../../cocos2d-x)
# $(call import-add-path, $(LOCAL_PATH)/../../../cocos2d-x/cocos)
# $(call import-add-path, $(LOCAL_PATH)/../../../cocos2d-x/extensions)
# $(call import-add-path, $(LOCAL_PATH)/../../../cocos2d-x/external)
# $(call import-add-path, $(LOCAL_PATH)/../../../cocos2d-x/cocos/platform)

# $(call import-module,scripting/lua-bindings/proj.android)
# $(call import-module,tools/simulator/libsimulator/proj.android)
