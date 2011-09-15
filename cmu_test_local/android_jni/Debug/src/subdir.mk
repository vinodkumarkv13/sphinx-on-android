################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/android_gqweb_com_jni_TestJniCall.cpp 

OBJS += \
./src/android_gqweb_com_jni_TestJniCall.o 

CPP_DEPS += \
./src/android_gqweb_com_jni_TestJniCall.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	arm-linux-androideabi-g++ -I/home/q/Workspace/my_test/android_jni/include -I/home/q/Workspace/Andriod/NDK/platforms/android-9/arch-arm/usr/include -I/home/q/Workspace/Andriod/NDK/toolchains/arm-linux-androideabi-4.4.3/prebuilt/linux-x86/include -I/home/q/Workspace/Andriod/NDK/toolchains/arm-linux-androideabi-4.4.3/prebuilt/linux-x86/arm-linux-androideabi/include -I/home/q/Workspace/Andriod/NDK/toolchains/arm-linux-androideabi-4.4.3/prebuilt/linux-x86/lib/gcc/arm-linux-androideabi/4.4.3/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


