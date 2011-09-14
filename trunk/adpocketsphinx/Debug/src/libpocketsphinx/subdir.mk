################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/libpocketsphinx/acmod.c \
../src/libpocketsphinx/bin_mdef.c \
../src/libpocketsphinx/blkarray_list.c \
../src/libpocketsphinx/dict.c \
../src/libpocketsphinx/dict2pid.c \
../src/libpocketsphinx/fsg_history.c \
../src/libpocketsphinx/fsg_lextree.c \
../src/libpocketsphinx/fsg_search.c \
../src/libpocketsphinx/hmm.c \
../src/libpocketsphinx/mdef.c \
../src/libpocketsphinx/ms_gauden.c \
../src/libpocketsphinx/ms_mgau.c \
../src/libpocketsphinx/ms_senone.c \
../src/libpocketsphinx/ngram_search.c \
../src/libpocketsphinx/ngram_search_fwdflat.c \
../src/libpocketsphinx/ngram_search_fwdtree.c \
../src/libpocketsphinx/phone_loop_search.c \
../src/libpocketsphinx/pocketsphinx.c \
../src/libpocketsphinx/ps_alignment.c \
../src/libpocketsphinx/ps_lattice.c \
../src/libpocketsphinx/ps_mllr.c \
../src/libpocketsphinx/ptm_mgau.c \
../src/libpocketsphinx/s2_semi_mgau.c \
../src/libpocketsphinx/state_align_search.c \
../src/libpocketsphinx/tmat.c \
../src/libpocketsphinx/vector.c 

OBJS += \
./src/libpocketsphinx/acmod.o \
./src/libpocketsphinx/bin_mdef.o \
./src/libpocketsphinx/blkarray_list.o \
./src/libpocketsphinx/dict.o \
./src/libpocketsphinx/dict2pid.o \
./src/libpocketsphinx/fsg_history.o \
./src/libpocketsphinx/fsg_lextree.o \
./src/libpocketsphinx/fsg_search.o \
./src/libpocketsphinx/hmm.o \
./src/libpocketsphinx/mdef.o \
./src/libpocketsphinx/ms_gauden.o \
./src/libpocketsphinx/ms_mgau.o \
./src/libpocketsphinx/ms_senone.o \
./src/libpocketsphinx/ngram_search.o \
./src/libpocketsphinx/ngram_search_fwdflat.o \
./src/libpocketsphinx/ngram_search_fwdtree.o \
./src/libpocketsphinx/phone_loop_search.o \
./src/libpocketsphinx/pocketsphinx.o \
./src/libpocketsphinx/ps_alignment.o \
./src/libpocketsphinx/ps_lattice.o \
./src/libpocketsphinx/ps_mllr.o \
./src/libpocketsphinx/ptm_mgau.o \
./src/libpocketsphinx/s2_semi_mgau.o \
./src/libpocketsphinx/state_align_search.o \
./src/libpocketsphinx/tmat.o \
./src/libpocketsphinx/vector.o 

C_DEPS += \
./src/libpocketsphinx/acmod.d \
./src/libpocketsphinx/bin_mdef.d \
./src/libpocketsphinx/blkarray_list.d \
./src/libpocketsphinx/dict.d \
./src/libpocketsphinx/dict2pid.d \
./src/libpocketsphinx/fsg_history.d \
./src/libpocketsphinx/fsg_lextree.d \
./src/libpocketsphinx/fsg_search.d \
./src/libpocketsphinx/hmm.d \
./src/libpocketsphinx/mdef.d \
./src/libpocketsphinx/ms_gauden.d \
./src/libpocketsphinx/ms_mgau.d \
./src/libpocketsphinx/ms_senone.d \
./src/libpocketsphinx/ngram_search.d \
./src/libpocketsphinx/ngram_search_fwdflat.d \
./src/libpocketsphinx/ngram_search_fwdtree.d \
./src/libpocketsphinx/phone_loop_search.d \
./src/libpocketsphinx/pocketsphinx.d \
./src/libpocketsphinx/ps_alignment.d \
./src/libpocketsphinx/ps_lattice.d \
./src/libpocketsphinx/ps_mllr.d \
./src/libpocketsphinx/ptm_mgau.d \
./src/libpocketsphinx/s2_semi_mgau.d \
./src/libpocketsphinx/state_align_search.d \
./src/libpocketsphinx/tmat.d \
./src/libpocketsphinx/vector.d 


# Each subdirectory must supply rules for building sources it contributes
src/libpocketsphinx/%.o: ../src/libpocketsphinx/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-linux-androideabi-gcc -nostdinc -I/home/q/Workspace/my_test/adsphinxbase/include/ -I/home/q/Workspace/my_test/adpocketsphinx/include/ -I/home/q/Workspace/Andriod/NDK/platforms/android-9/arch-arm/usr/include -I/home/q/Workspace/Andriod/NDK/toolchains/arm-linux-androideabi-4.4.3/prebuilt/linux-x86/include -I/home/q/Workspace/Andriod/NDK/toolchains/arm-linux-androideabi-4.4.3/prebuilt/linux-x86/arm-linux-androideabi/include -I/home/q/Workspace/Andriod/NDK/toolchains/arm-linux-androideabi-4.4.3/prebuilt/linux-x86/lib/gcc/arm-linux-androideabi/4.4.3/include -I/home/q/Workspace/Andriod/NDK/toolchains/arm-linux-androideabi-4.4.3/prebuilt/linux-x86/lib/gcc/arm-linux-androideabi/4.4.3/include-fixed/ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


