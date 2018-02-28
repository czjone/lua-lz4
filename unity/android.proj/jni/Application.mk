APP_STL := gnustl_static
NDK_TOOLCHAIN_VERSION = 4.8
APP_PLATFORM := android-19

APP_CPPFLAGS := -frtti -DCC_ENABLE_CHIPMUNK_INTEGRATION=1 -std=c++11 -fsigned-char
APP_LDFLAGS := -latomic
APP_ABI := armeabi armeabi-v7a x86
