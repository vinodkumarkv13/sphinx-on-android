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
	@echo 'Invoking: GCC C Compiler'
	gcc -I/home/q/Workspace/cmu_test_local/adsphinxbase/include/ -O0 -g3 -Wall -c -fmessage-length=0 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


