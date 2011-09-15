################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/libsphinxbase/util/bio.c \
../src/libsphinxbase/util/bitvec.c \
../src/libsphinxbase/util/blas_lite.c \
../src/libsphinxbase/util/case.c \
../src/libsphinxbase/util/ckd_alloc.c \
../src/libsphinxbase/util/cmd_ln.c \
../src/libsphinxbase/util/dtoa.c \
../src/libsphinxbase/util/err.c \
../src/libsphinxbase/util/errno.c \
../src/libsphinxbase/util/f2c_lite.c \
../src/libsphinxbase/util/filename.c \
../src/libsphinxbase/util/genrand.c \
../src/libsphinxbase/util/glist.c \
../src/libsphinxbase/util/hash_table.c \
../src/libsphinxbase/util/heap.c \
../src/libsphinxbase/util/huff_code.c \
../src/libsphinxbase/util/info.c \
../src/libsphinxbase/util/listelem_alloc.c \
../src/libsphinxbase/util/logmath.c \
../src/libsphinxbase/util/matrix.c \
../src/libsphinxbase/util/mmio.c \
../src/libsphinxbase/util/pio.c \
../src/libsphinxbase/util/profile.c \
../src/libsphinxbase/util/sbthread.c \
../src/libsphinxbase/util/slamch.c \
../src/libsphinxbase/util/slapack_lite.c \
../src/libsphinxbase/util/strfuncs.c \
../src/libsphinxbase/util/string_wce.c \
../src/libsphinxbase/util/unlimit.c \
../src/libsphinxbase/util/utf8.c 

OBJS += \
./src/libsphinxbase/util/bio.o \
./src/libsphinxbase/util/bitvec.o \
./src/libsphinxbase/util/blas_lite.o \
./src/libsphinxbase/util/case.o \
./src/libsphinxbase/util/ckd_alloc.o \
./src/libsphinxbase/util/cmd_ln.o \
./src/libsphinxbase/util/dtoa.o \
./src/libsphinxbase/util/err.o \
./src/libsphinxbase/util/errno.o \
./src/libsphinxbase/util/f2c_lite.o \
./src/libsphinxbase/util/filename.o \
./src/libsphinxbase/util/genrand.o \
./src/libsphinxbase/util/glist.o \
./src/libsphinxbase/util/hash_table.o \
./src/libsphinxbase/util/heap.o \
./src/libsphinxbase/util/huff_code.o \
./src/libsphinxbase/util/info.o \
./src/libsphinxbase/util/listelem_alloc.o \
./src/libsphinxbase/util/logmath.o \
./src/libsphinxbase/util/matrix.o \
./src/libsphinxbase/util/mmio.o \
./src/libsphinxbase/util/pio.o \
./src/libsphinxbase/util/profile.o \
./src/libsphinxbase/util/sbthread.o \
./src/libsphinxbase/util/slamch.o \
./src/libsphinxbase/util/slapack_lite.o \
./src/libsphinxbase/util/strfuncs.o \
./src/libsphinxbase/util/string_wce.o \
./src/libsphinxbase/util/unlimit.o \
./src/libsphinxbase/util/utf8.o 

C_DEPS += \
./src/libsphinxbase/util/bio.d \
./src/libsphinxbase/util/bitvec.d \
./src/libsphinxbase/util/blas_lite.d \
./src/libsphinxbase/util/case.d \
./src/libsphinxbase/util/ckd_alloc.d \
./src/libsphinxbase/util/cmd_ln.d \
./src/libsphinxbase/util/dtoa.d \
./src/libsphinxbase/util/err.d \
./src/libsphinxbase/util/errno.d \
./src/libsphinxbase/util/f2c_lite.d \
./src/libsphinxbase/util/filename.d \
./src/libsphinxbase/util/genrand.d \
./src/libsphinxbase/util/glist.d \
./src/libsphinxbase/util/hash_table.d \
./src/libsphinxbase/util/heap.d \
./src/libsphinxbase/util/huff_code.d \
./src/libsphinxbase/util/info.d \
./src/libsphinxbase/util/listelem_alloc.d \
./src/libsphinxbase/util/logmath.d \
./src/libsphinxbase/util/matrix.d \
./src/libsphinxbase/util/mmio.d \
./src/libsphinxbase/util/pio.d \
./src/libsphinxbase/util/profile.d \
./src/libsphinxbase/util/sbthread.d \
./src/libsphinxbase/util/slamch.d \
./src/libsphinxbase/util/slapack_lite.d \
./src/libsphinxbase/util/strfuncs.d \
./src/libsphinxbase/util/string_wce.d \
./src/libsphinxbase/util/unlimit.d \
./src/libsphinxbase/util/utf8.d 


# Each subdirectory must supply rules for building sources it contributes
src/libsphinxbase/util/%.o: ../src/libsphinxbase/util/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I/home/q/Workspace/cmu_test_local/adsphinxbase/include/ -O0 -g3 -Wall -c -fmessage-length=0 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


