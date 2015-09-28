################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Graphics/UI.cpp \
../src/Graphics/WindowEntity.cpp \
../src/Graphics/entity.cpp \
../src/Graphics/ntsa.cpp 

OBJS += \
./src/Graphics/UI.o \
./src/Graphics/WindowEntity.o \
./src/Graphics/entity.o \
./src/Graphics/ntsa.o 

CPP_DEPS += \
./src/Graphics/UI.d \
./src/Graphics/WindowEntity.d \
./src/Graphics/entity.d \
./src/Graphics/ntsa.d 


# Each subdirectory must supply rules for building sources it contributes
src/Graphics/%.o: ../src/Graphics/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++0x -D__GXX_EXPERIMENTAL_CXX0X__ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


