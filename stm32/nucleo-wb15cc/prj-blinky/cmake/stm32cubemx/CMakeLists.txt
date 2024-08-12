cmake_minimum_required(VERSION 3.22)

project(stm32cubemx)
add_library(stm32cubemx INTERFACE)

# Enable CMake support for ASM and C languages
enable_language(C ASM)

target_compile_definitions(stm32cubemx INTERFACE 
	USE_HAL_DRIVER 
	STM32WB15xx
    $<$<CONFIG:Debug>:DEBUG>
)

target_include_directories(stm32cubemx INTERFACE
    ../../Core/Inc
    ../../../../lib/STM32CubeWB/Drivers/STM32WBxx_HAL_Driver/Inc
    ../../../../lib/STM32CubeWB/Drivers/STM32WBxx_HAL_Driver/Inc/Legacy
    ../../../../lib/STM32CubeWB/Drivers/CMSIS/Device/ST/STM32WBxx/Include
    ../../../../lib/STM32CubeWB/Drivers/CMSIS/Include
)

target_sources(stm32cubemx INTERFACE
    ../../Core/Src/main.c
    ../../Core/Src/stm32wbxx_it.c
    ../../Core/Src/stm32wbxx_hal_msp.c
    ../../../../lib/STM32CubeWB/Drivers/STM32WBxx_HAL_Driver/Src/stm32wbxx_hal_rcc.c
    ../../../../lib/STM32CubeWB/Drivers/STM32WBxx_HAL_Driver/Src/stm32wbxx_ll_rcc.c
    ../../../../lib/STM32CubeWB/Drivers/STM32WBxx_HAL_Driver/Src/stm32wbxx_hal_rcc_ex.c
    ../../../../lib/STM32CubeWB/Drivers/STM32WBxx_HAL_Driver/Src/stm32wbxx_hal_flash.c
    ../../../../lib/STM32CubeWB/Drivers/STM32WBxx_HAL_Driver/Src/stm32wbxx_hal_flash_ex.c
    ../../../../lib/STM32CubeWB/Drivers/STM32WBxx_HAL_Driver/Src/stm32wbxx_hal_gpio.c
    ../../../../lib/STM32CubeWB/Drivers/STM32WBxx_HAL_Driver/Src/stm32wbxx_hal_hsem.c
    ../../../../lib/STM32CubeWB/Drivers/STM32WBxx_HAL_Driver/Src/stm32wbxx_hal_dma.c
    ../../../../lib/STM32CubeWB/Drivers/STM32WBxx_HAL_Driver/Src/stm32wbxx_hal_dma_ex.c
    ../../../../lib/STM32CubeWB/Drivers/STM32WBxx_HAL_Driver/Src/stm32wbxx_hal_pwr.c
    ../../../../lib/STM32CubeWB/Drivers/STM32WBxx_HAL_Driver/Src/stm32wbxx_hal_pwr_ex.c
    ../../../../lib/STM32CubeWB/Drivers/STM32WBxx_HAL_Driver/Src/stm32wbxx_hal_cortex.c
    ../../../../lib/STM32CubeWB/Drivers/STM32WBxx_HAL_Driver/Src/stm32wbxx_hal.c
    ../../../../lib/STM32CubeWB/Drivers/STM32WBxx_HAL_Driver/Src/stm32wbxx_hal_exti.c
    ../../../../lib/STM32CubeWB/Drivers/STM32WBxx_HAL_Driver/Src/stm32wbxx_hal_tim.c
    ../../../../lib/STM32CubeWB/Drivers/STM32WBxx_HAL_Driver/Src/stm32wbxx_hal_tim_ex.c
    ../../Core/Src/system_stm32wbxx.c
    ../../Core/Src/sysmem.c
    ../../Core/Src/syscalls.c
    ../../startup_stm32wb15xx_cm4.s
)

target_link_directories(stm32cubemx INTERFACE
)

target_link_libraries(stm32cubemx INTERFACE
)

# Validate that STM32CubeMX code is compatible with C standard
if(CMAKE_C_STANDARD LESS 11)
    message(ERROR "Generated code requires C11 or higher")
endif()


