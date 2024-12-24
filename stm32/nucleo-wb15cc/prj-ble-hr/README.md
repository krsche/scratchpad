# Nucleo WB15CC - BLE HR Example

This example is mostly taken from the STM32CubeWB repository (added as a submodule under `../../lib`)
Therefore the software in this folder falls under and complies with STs [SLA0044](https://www.st.com/resource/en/license_agreement/dm00216740.pdf) license.

## HowTo

__Reconfigure with STM32CubeMX__:  

1. Open the prj-ble-hr.ioc project in STM32CubeMX and re-generate the code, this is a _cmake_ project.
2. Replace all absolute paths in `./cmake/stm32cubemx/CMakeLists.txt` with relative paths to `../../../../lib/STM32CubeWB`.
3. Run CMake and Build.

__Build__:  

```bash
rm -r build
cmake -S . -B build
cd build
make
```

__Flash__:

```bash
openocd -f ./openocd_st_nucleo_wb15.cfg -c "program ./build/prj-ble-hr.elf verify reset exit"
```

__Debug__:

1. Open this folder in a new vscode window
2. Ensure to have `marus25.cortex-debug` extension installed
3. Press _F5_ to launch VSCode Debugging


## Explaination of the project and code

This project demonstrates a BLE application that publishes a "Heart Rate" to a smartphone. The Heartrate is not measured, it's generated (65 + something derived from RTC).

Documentation from ST can be found [here](https://wiki.st.com/stm32mcu/wiki/Connectivity:STM32WB_HeartRate).

__Functional Characteristics:__

- Device starts, advertises BLE in FAST mode for 60s, then LP mode afterwards
- Once connected, HR is sent once every second
- Buttons control Pairing
- MCU is put into Stop Mode in between BLE transmissions

__Code Characteristics:__

- Set up with Code generated via STM32CubeMX, using
  - __STM32_WPAN__ Middleware "Wireless Personal Area Network" (BLE)
  
  - __Sequencer__ (a basic task scheduler, but not a RTOS, sequencer does not support preemtion)
    - Tasks in the sequencer must be set (started) manually by calling `UTIL_SEQ_SetTask(...)`
    - This either happens on events, or triggered by the TimerServer
  
  - __TimerServer__ (an RTC-based Timer), that triggers the Sequencer Tasks on defined schedules.
  
  - __Tiny_LPM__ (Low Power Management) is used to control Power States
    - Stop Mode is entered whenever the Sequencers "Idle" function is called, or if HAL_Delay would be called (but HAL_Delay is not called anywhere in the example)

### How does the Sequencer work?

STM's Documentation can be found [here](https://wiki.st.com/stm32mcu/wiki/Utility:Sequencer)

