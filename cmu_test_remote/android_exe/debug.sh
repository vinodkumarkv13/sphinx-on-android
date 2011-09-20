#!/bin/sh
#

cgdb -d /home/q/Workspace/Andriod/NDK/toolchains/arm-linux-androideabi-4.4.3/prebuilt/linux-x86/bin/arm-linux-androideabi-gdb /home/q/Workspace/sphinx-on-android/trunk/cmu_test_remote/android_exe/Debug/libandroid_exe.so


#target remote :5039
#gdbserver :5039 --attach   