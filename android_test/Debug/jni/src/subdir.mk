################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../jni/src/android_gqweb_com_jni_TestJniCall.cpp 

OBJS += \
./jni/src/android_gqweb_com_jni_TestJniCall.o 

CPP_DEPS += \
./jni/src/android_gqweb_com_jni_TestJniCall.d 


# Each subdirectory must supply rules for building sources it contributes
jni/src/%.o: ../jni/src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


