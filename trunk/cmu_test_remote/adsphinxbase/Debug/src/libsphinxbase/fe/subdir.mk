################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/libsphinxbase/fe/fe_interface.c \
../src/libsphinxbase/fe/fe_sigproc.c \
../src/libsphinxbase/fe/fe_warp.c \
../src/libsphinxbase/fe/fe_warp_affine.c \
../src/libsphinxbase/fe/fe_warp_inverse_linear.c \
../src/libsphinxbase/fe/fe_warp_piecewise_linear.c \
../src/libsphinxbase/fe/fixlog.c 

OBJS += \
./src/libsphinxbase/fe/fe_interface.o \
./src/libsphinxbase/fe/fe_sigproc.o \
./src/libsphinxbase/fe/fe_warp.o \
./src/libsphinxbase/fe/fe_warp_affine.o \
./src/libsphinxbase/fe/fe_warp_inverse_linear.o \
./src/libsphinxbase/fe/fe_warp_piecewise_linear.o \
./src/libsphinxbase/fe/fixlog.o 

C_DEPS += \
./src/libsphinxbase/fe/fe_interface.d \
./src/libsphinxbase/fe/fe_sigproc.d \
./src/libsphinxbase/fe/fe_warp.d \
./src/libsphinxbase/fe/fe_warp_affine.d \
./src/libsphinxbase/fe/fe_warp_inverse_linear.d \
./src/libsphinxbase/fe/fe_warp_piecewise_linear.d \
./src/libsphinxbase/fe/fixlog.d 


# Each subdirectory must supply rules for building sources it contributes
src/libsphinxbase/fe/%.o: ../src/libsphinxbase/fe/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-linux-androideabi-gcc -nostdinc -I/home/q/Workspace/cmu_test_remote/adsphinxbase/include/ -I/home/q/Workspace/Andriod/NDK/platforms/android-9/arch-arm/usr/include -I/home/q/Workspace/Andriod/NDK/toolchains/arm-linux-androideabi-4.4.3/prebuilt/linux-x86/include -I/home/q/Workspace/Andriod/NDK/toolchains/arm-linux-androideabi-4.4.3/prebuilt/linux-x86/arm-linux-androideabi/include -I/home/q/Workspace/Andriod/NDK/toolchains/arm-linux-androideabi-4.4.3/prebuilt/linux-x86/lib/gcc/arm-linux-androideabi/4.4.3/include -I/home/q/Workspace/Andriod/NDK/toolchains/arm-linux-androideabi-4.4.3/prebuilt/linux-x86/lib/gcc/arm-linux-androideabi/4.4.3/include-fixed/ -I/home/q/Workspace/Andriod/NDK/sources/cxx-stl/stlport/stlport/ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


