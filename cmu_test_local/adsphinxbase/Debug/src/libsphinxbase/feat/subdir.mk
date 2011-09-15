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
	@echo 'Invoking: GCC C Compiler'
	gcc -I/home/q/Workspace/cmu_test_local/adsphinxbase/include/ -O0 -g3 -Wall -c -fmessage-length=0 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


