################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/libsphinxbase/feat/agc.c \
../src/libsphinxbase/feat/cmn.c \
../src/libsphinxbase/feat/cmn_prior.c \
../src/libsphinxbase/feat/feat.c \
../src/libsphinxbase/feat/lda.c 

OBJS += \
./src/libsphinxbase/feat/agc.o \
./src/libsphinxbase/feat/cmn.o \
./src/libsphinxbase/feat/cmn_prior.o \
./src/libsphinxbase/feat/feat.o \
./src/libsphinxbase/feat/lda.o 

C_DEPS += \
./src/libsphinxbase/feat/agc.d \
./src/libsphinxbase/feat/cmn.d \
./src/libsphinxbase/feat/cmn_prior.d \
./src/libsphinxbase/feat/feat.d \
./src/libsphinxbase/feat/lda.d 


# Each subdirectory must supply rules for building sources it contributes
src/libsphinxbase/feat/%.o: ../src/libsphinxbase/feat/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-linux-androideabi-gcc -nostdinc -I/home/q/Workspace/sphinx-on-android/trunk/cmu_test_remote/adpocketsphinx/include/ -I/home/q/Workspace/sphinx-on-android/trunk/cmu_test_remote/adsphinxbase/include/ -I/home/q/Workspace/Andriod/NDK/platforms/android-9/arch-arm/usr/include -I/home/q/Workspace/Andriod/NDK/toolchains/arm-linux-androideabi-4.4.3/prebuilt/linux-x86/include -I/home/q/Workspace/Andriod/NDK/toolchains/arm-linux-androideabi-4.4.3/prebuilt/linux-x86/arm-linux-androideabi/include -I/home/q/Workspace/Andriod/NDK/toolchains/arm-linux-androideabi-4.4.3/prebuilt/linux-x86/lib/gcc/arm-linux-androideabi/4.4.3/include -I/home/q/Workspace/Andriod/NDK/toolchains/arm-linux-androideabi-4.4.3/prebuilt/linux-x86/lib/gcc/arm-linux-androideabi/4.4.3/include-fixed/ -I/home/q/Workspace/Andriod/NDK/sources/cxx-stl/stlport/stlport/ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


