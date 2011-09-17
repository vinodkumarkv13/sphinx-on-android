################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/libsphinxbase/lm/fsg_model.c \
../src/libsphinxbase/lm/jsgf.c \
../src/libsphinxbase/lm/jsgf_parser.c \
../src/libsphinxbase/lm/jsgf_scanner.c \
../src/libsphinxbase/lm/lm3g_model.c \
../src/libsphinxbase/lm/ngram_model.c \
../src/libsphinxbase/lm/ngram_model_arpa.c \
../src/libsphinxbase/lm/ngram_model_dmp.c \
../src/libsphinxbase/lm/ngram_model_dmp32.c \
../src/libsphinxbase/lm/ngram_model_set.c 

OBJS += \
./src/libsphinxbase/lm/fsg_model.o \
./src/libsphinxbase/lm/jsgf.o \
./src/libsphinxbase/lm/jsgf_parser.o \
./src/libsphinxbase/lm/jsgf_scanner.o \
./src/libsphinxbase/lm/lm3g_model.o \
./src/libsphinxbase/lm/ngram_model.o \
./src/libsphinxbase/lm/ngram_model_arpa.o \
./src/libsphinxbase/lm/ngram_model_dmp.o \
./src/libsphinxbase/lm/ngram_model_dmp32.o \
./src/libsphinxbase/lm/ngram_model_set.o 

C_DEPS += \
./src/libsphinxbase/lm/fsg_model.d \
./src/libsphinxbase/lm/jsgf.d \
./src/libsphinxbase/lm/jsgf_parser.d \
./src/libsphinxbase/lm/jsgf_scanner.d \
./src/libsphinxbase/lm/lm3g_model.d \
./src/libsphinxbase/lm/ngram_model.d \
./src/libsphinxbase/lm/ngram_model_arpa.d \
./src/libsphinxbase/lm/ngram_model_dmp.d \
./src/libsphinxbase/lm/ngram_model_dmp32.d \
./src/libsphinxbase/lm/ngram_model_set.d 


# Each subdirectory must supply rules for building sources it contributes
src/libsphinxbase/lm/%.o: ../src/libsphinxbase/lm/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-linux-androideabi-gcc -nostdinc -I/home/q/Workspace/sphinx-on-android/trunk/cmu_test_remote/adpocketsphinx/include/ -I/home/q/Workspace/sphinx-on-android/trunk/cmu_test_remote/adsphinxbase/include/ -I/home/q/Workspace/Andriod/NDK/platforms/android-9/arch-arm/usr/include -I/home/q/Workspace/Andriod/NDK/toolchains/arm-linux-androideabi-4.4.3/prebuilt/linux-x86/include -I/home/q/Workspace/Andriod/NDK/toolchains/arm-linux-androideabi-4.4.3/prebuilt/linux-x86/arm-linux-androideabi/include -I/home/q/Workspace/Andriod/NDK/toolchains/arm-linux-androideabi-4.4.3/prebuilt/linux-x86/lib/gcc/arm-linux-androideabi/4.4.3/include -I/home/q/Workspace/Andriod/NDK/toolchains/arm-linux-androideabi-4.4.3/prebuilt/linux-x86/lib/gcc/arm-linux-androideabi/4.4.3/include-fixed/ -I/home/q/Workspace/Andriod/NDK/sources/cxx-stl/stlport/stlport/ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


