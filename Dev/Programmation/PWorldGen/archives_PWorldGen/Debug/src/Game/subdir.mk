################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Game/entity.cpp \
../src/Game/level.cpp \
../src/Game/ntsa.cpp 

OBJS += \
./src/Game/entity.o \
./src/Game/level.o \
./src/Game/ntsa.o 

CPP_DEPS += \
./src/Game/entity.d \
./src/Game/level.d \
./src/Game/ntsa.d 


# Each subdirectory must supply rules for building sources it contributes
src/Game/%.o: ../src/Game/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -O0 -g3 -pg -Wall -Wextra -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


