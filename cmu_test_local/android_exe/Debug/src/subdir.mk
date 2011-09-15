################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/gqandroidrecordsl.cpp \
../src/gqandroidsphinx.cpp \
../src/gqrecordalsa.cpp \
../src/main.cpp 

OBJS += \
./src/gqandroidrecordsl.o \
./src/gqandroidsphinx.o \
./src/gqrecordalsa.o \
./src/main.o 

CPP_DEPS += \
./src/gqandroidrecordsl.d \
./src/gqandroidsphinx.d \
./src/gqrecordalsa.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D_DEBUG_ -I/home/q/Workspace/cmu_test_local/adsphinxbase/include/ -I/home/q/Workspace/cmu_test_local/adpocketsphinx/include/ -I/home/q/Workspace/cmu_test_local/android_exe/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


