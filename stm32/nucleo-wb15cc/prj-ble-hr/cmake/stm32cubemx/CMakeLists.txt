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
    ../../STM32_WPAN/App
    ../../../../lib/STM32CubeWB/Drivers/STM32WBxx_HAL_Driver/Inc
    ../../../../lib/STM32CubeWB/Drivers/STM32WBxx_HAL_Driver/Inc/Legacy
    ../../../../lib/STM32CubeWB/Utilities/lpm/tiny_lpm
    ../../../../lib/STM32CubeWB/Middlewares/ST/STM32_WPAN
    ../../../../lib/STM32CubeWB/Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread
    ../../../../lib/STM32CubeWB/Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread/tl
    ../../../../lib/STM32CubeWB/Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread/shci
    ../../../../lib/STM32CubeWB/Middlewares/ST/STM32_WPAN/utilities
    ../../../../lib/STM32CubeWB/Middlewares/ST/STM32_WPAN/ble/core
    ../../../../lib/STM32CubeWB/Middlewares/ST/STM32_WPAN/ble/core/auto
    ../../../../lib/STM32CubeWB/Middlewares/ST/STM32_WPAN/ble/core/template
    ../../../../lib/STM32CubeWB/Middlewares/ST/STM32_WPAN/ble/svc/Inc
    ../../../../lib/STM32CubeWB/Middlewares/ST/STM32_WPAN/ble/svc/Src
    ../../../../lib/STM32CubeWB/Drivers/CMSIS/Device/ST/STM32WBxx/Include
    ../../../../lib/STM32CubeWB/Utilities/sequencer
    ../../../../lib/STM32CubeWB/Middlewares/ST/STM32_WPAN/ble
    ../../../../lib/STM32CubeWB/Drivers/CMSIS/Include
)

target_sources(stm32cubemx INTERFACE
    ../../Core/Src/main.c
    ../../Core/Src/app_entry.c
    ../../Core/Src/app_debug.c
    ../../Core/Src/hw_timerserver.c
    ../../Core/Src/hw_uart.c
    ../../Core/Src/stm32_lpm_if.c
    ../../Core/Src/standby.c
    ../../Core/Src/stm32wbxx_it.c
    ../../Core/Src/stm32wbxx_hal_msp.c
    ../../STM32_WPAN/Target/hw_ipcc.c
    ../../STM32_WPAN/App/app_ble.c
    ../../STM32_WPAN/App/dis_app.c
    ../../STM32_WPAN/App/hrs_app.c
    ../../../../lib/STM32CubeWB/Drivers/STM32WBxx_HAL_Driver/Src/stm32wbxx_hal_hsem.c
    ../../../../lib/STM32CubeWB/Drivers/STM32WBxx_HAL_Driver/Src/stm32wbxx_hal_rcc.c
    ../../../../lib/STM32CubeWB/Drivers/STM32WBxx_HAL_Driver/Src/stm32wbxx_ll_rcc.c
    ../../../../lib/STM32CubeWB/Drivers/STM32WBxx_HAL_Driver/Src/stm32wbxx_hal_rcc_ex.c
    ../../../../lib/STM32CubeWB/Drivers/STM32WBxx_HAL_Driver/Src/stm32wbxx_hal_flash.c
    ../../../../lib/STM32CubeWB/Drivers/STM32WBxx_HAL_Driver/Src/stm32wbxx_hal_flash_ex.c
    ../../../../lib/STM32CubeWB/Drivers/STM32WBxx_HAL_Driver/Src/stm32wbxx_hal_gpio.c
    ../../../../lib/STM32CubeWB/Drivers/STM32WBxx_HAL_Driver/Src/stm32wbxx_hal_dma.c
    ../../../../lib/STM32CubeWB/Drivers/STM32WBxx_HAL_Driver/Src/stm32wbxx_hal_dma_ex.c
    ../../../../lib/STM32CubeWB/Drivers/STM32WBxx_HAL_Driver/Src/stm32wbxx_hal_pwr.c
    ../../../../lib/STM32CubeWB/Drivers/STM32WBxx_HAL_Driver/Src/stm32wbxx_hal_pwr_ex.c
    ../../../../lib/STM32CubeWB/Drivers/STM32WBxx_HAL_Driver/Src/stm32wbxx_hal_cortex.c
    ../../../../lib/STM32CubeWB/Drivers/STM32WBxx_HAL_Driver/Src/stm32wbxx_hal.c
    ../../../../lib/STM32CubeWB/Drivers/STM32WBxx_HAL_Driver/Src/stm32wbxx_hal_exti.c
    ../../../../lib/STM32CubeWB/Drivers/STM32WBxx_HAL_Driver/Src/stm32wbxx_hal_ipcc.c
    ../../../../lib/STM32CubeWB/Drivers/STM32WBxx_HAL_Driver/Src/stm32wbxx_hal_rng.c
    ../../../../lib/STM32CubeWB/Drivers/STM32WBxx_HAL_Driver/Src/stm32wbxx_hal_rtc.c
    ../../../../lib/STM32CubeWB/Drivers/STM32WBxx_HAL_Driver/Src/stm32wbxx_hal_rtc_ex.c
    ../../../../lib/STM32CubeWB/Drivers/STM32WBxx_HAL_Driver/Src/stm32wbxx_hal_tim.c
    ../../../../lib/STM32CubeWB/Drivers/STM32WBxx_HAL_Driver/Src/stm32wbxx_hal_tim_ex.c
    ../../../../lib/STM32CubeWB/Drivers/STM32WBxx_HAL_Driver/Src/stm32wbxx_hal_uart.c
    ../../../../lib/STM32CubeWB/Drivers/STM32WBxx_HAL_Driver/Src/stm32wbxx_hal_uart_ex.c
    ../../Core/Src/system_stm32wbxx.c
    ../../../../lib/STM32CubeWB/Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread/tl/tl_mbox.c
    ../../../../lib/STM32CubeWB/Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread/shci/shci.c
    ../../../../lib/STM32CubeWB/Middlewares/ST/STM32_WPAN/utilities/dbg_trace.c
    ../../../../lib/STM32CubeWB/Middlewares/ST/STM32_WPAN/utilities/otp.c
    ../../../../lib/STM32CubeWB/Middlewares/ST/STM32_WPAN/utilities/stm_list.c
    ../../../../lib/STM32CubeWB/Middlewares/ST/STM32_WPAN/utilities/stm_queue.c
    ../../../../lib/STM32CubeWB/Middlewares/ST/STM32_WPAN/ble/core/template/osal.c
    ../../../../lib/STM32CubeWB/Middlewares/ST/STM32_WPAN/ble/core/auto/ble_gap_aci.c
    ../../../../lib/STM32CubeWB/Middlewares/ST/STM32_WPAN/ble/core/auto/ble_gatt_aci.c
    ../../../../lib/STM32CubeWB/Middlewares/ST/STM32_WPAN/ble/core/auto/ble_hal_aci.c
    ../../../../lib/STM32CubeWB/Middlewares/ST/STM32_WPAN/ble/core/auto/ble_hci_le.c
    ../../../../lib/STM32CubeWB/Middlewares/ST/STM32_WPAN/ble/core/auto/ble_l2cap_aci.c
    ../../../../lib/STM32CubeWB/Middlewares/ST/STM32_WPAN/ble/svc/Src/hrs.c
    ../../../../lib/STM32CubeWB/Middlewares/ST/STM32_WPAN/ble/svc/Src/dis.c
    ../../../../lib/STM32CubeWB/Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread/tl/hci_tl.c
    ../../../../lib/STM32CubeWB/Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread/tl/hci_tl_if.c
    ../../../../lib/STM32CubeWB/Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread/tl/shci_tl.c
    ../../../../lib/STM32CubeWB/Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread/tl/shci_tl_if.c
    ../../../../lib/STM32CubeWB/Middlewares/ST/STM32_WPAN/ble/svc/Src/svc_ctl.c
    ../../../../lib/STM32CubeWB/Utilities/lpm/tiny_lpm/stm32_lpm.c
    ../../../../lib/STM32CubeWB/Utilities/sequencer/stm32_seq.c
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


