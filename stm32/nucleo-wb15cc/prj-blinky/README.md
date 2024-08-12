# STM32WB15CC Blinky Example (from scratch)

This is an example project that aims to blink a LED on the Nucleo-WB15CC Development Board.

The goal here is to demonstrate how to set the project up from scratch. The process will be documented in the next 
section.

Resources required:

- [Nucleo-WB15CC Schematic](https://www.st.com/en/evaluation-tools/nucleo-wb15cc.html#cad-resources)
- [STM32WB15_CM4.svd](https://www.st.com/en/microcontrollers-microprocessors/stm32wb15cc.html#cad-resources)
  - System View Description for debugging

## Project Setup from Scratch - Follow-Along

### 1. STM32CubeMX Code Generation

1. Start STM32CubeMX, create a new project for STM32WB15CCU6 (New Project for MCU) and save to the project directory (`.ioc` will inherit name of folder).

2. Set-Up Pins & Config (inspect schematic)
   1. Pins
      1. PIN `PB5` = BLUE LED
         - --> GPIO_OUTPUT
         - Rename to `LED_BLUE`
         - No need for setting pull-up / pull-down resistors
      2. PIN `PB0` = GREEN LED
         - --> GPIO_OUTPUT
         - Rename to `LED_GREEN`
         - No need for setting pull-up / pull-down resistors
      3. PIN `PB1` = RED LED
         - --> GPIO_OUTPUT
         - Rename to `LED_RED`
         - No need for setting pull-up / pull-down resistors
      4. HSE Clock Source: 32MHZ Ext Osc *without* caps = `OSC_IN` and `OSC_OUT`
         - --> RCC_OSC_IN
         - --> RCC_OSC_OUT
         - used for RF Subsystem and potentially System Clock Source
      5. LSE Clock Source: 32MHZ Ext Osc *with* caps = `PC14-OSC32_IN` and `PC15-OSC32_OUT`
         - --> RCC_OSC32_IN
         - --> RCC_OSC32_OUT
         - used for RTC and calib of int. OSCs
      6. PIN PA13 = SWDIO
         - --> SYS_JTMS-SWDIO
      7. PIN PA14 = SWDCLK
         - --> SYS_JTCK-SWCLK
   2. Configuration of Serial Wire Debug
      - System Core -> SYS -> Debug: Serial Wire
      - This also turns Pins PA13 and PA14 green in the Pinout view

3. Clock Configuration
   1. LSE Input Frequency --> 32.768 KHz (should be already set, if not, set it manually)
      - This is not really needed here as the RTC is not used
   2. HSE Input Frequency --> 32 MHz
      - HSE PRES = /1
      - System Clock MUX = HSE_SYS
      - Don't enable CSS
      - All Downstream prescalers = /1
      - --> All Downstream Clocks should equal 32MHz if set correctly
   3. SMPS Clock MUX --> HSE
      - SMPS Div = /4
      - --> SMPS Step Down = 4 MHz

4. Project Manager
   1. Project
      1. Project Settings -> Toolchain / IDE = CMake
      2. MCU and Firmware Package -> Use Default Firmware Location = Unchecked
      3. MCU and Firmware Package -> Firmware Relative Path = `<YOUR_PROJECT_FOLDER_PATH>/../../lib/STM32CubeWB`
         - This of course varies depending on where you have the STM32CubeWB project cloned. I recommend to add it as a submodule to the repo, under a `lib` folder.
         - Note: Specifying a relative path only works when you prefix the projects root directory first.
   2. Code Generator
      1. STM32Cube MCU packages and embedded software packs = Add necessary library files as reference ...
      2. Generated Files
         1. Keep User Code when re-generating = Check

5. GENERATE CODE
   1. Save Project and click *GENERATE CODE*
   2. Replace the absolute paths in the generated `./cmake/stm32cubemx/CMakeLists.txt` with only the relative part we already prepared
      - By running `sed -i '' "s|$(pwd)/|../../|g" ./cmake/stm32cubemx/CMakeLists.txt`
      - Note that an additional two `../` are added to make `../../../../` due to the nesting of that particular `CMakeLists.txt` inside `cmake/stm32cubemx`
      - You can always re-generate the code from STM32CubeMX if you want to try again.
      - Of course you can also leave it as absolute paths (which I don't recommend when checking into git) or do it manually.
      - You can test if it worked by running the `cmake` command below.

6. Build project
   1. Run `cmake -S . -B build`
   2. Go to build dir `cd build`
   3. Run `make`

### 2. Flash & MCU Debugging Setup

1. Copy the svd `STM32WB15_CM4.svd` file mentioned above to the root dir of the project.

2. Create the openocd config `openocd_st_nucleo_wb15.cfg`, fixing a bug for this board with reset behaviour & the workarea size being set wrongly.

3. Create the `.vscode/launch.json` config file and ensure the [marus25.cortex-debug](https://marketplace.visualstudio.com/items?itemName=marus25.cortex-debug) plugin is installed.
   - Note the following lines:
     - `"executable": "./build/prj-blinky.elf",`
     - `"device": "STM32WB15CCUx",`
     - `"configFiles": ["./openocd_st_nucleo_wb15.cfg"],`
     - `"svdFile": "./STM32WB15_CM4.svd",`

4. Create the `.vscode/c_cpp_properties.json` config file.
   - Note that this refers to the env var `ARMGCC_DIR` which should be set to the directory where you're `arm-none-eabi-gcc` binary is located in.
   - For me it is set in my `~/.bashrc` as `export ARMGCC_DIR=/Applications/ArmGNUToolchain/13.3.rel1/arm-none-eabi/bin`

5. Open the project folder in a new VSCode Window (this is important for the launch script to work)

6. Connect the Nucleo-WB15CC Board while pressing Button-4 (to pull-down the NRST Pin while startup to enter Debugger Mode)

7. Try uploading the compiled firmware by running `openocd -f ./openocd_st_nucleo_wb15.cfg -c "program ./build/prj-blinky.elf verify reset exit"` from the projects root directory

8. Press `F5` to launch the VSCode Debugger

> [!tip] Note the tasks.json file
> This defines build, flash, and respective clean tasks. The `launch.json` also refers to one of these tasks in the line
>
> - `"preLaunchTask": "Build and Flash",`

### 3. Write the actual Blinky Application Code

In the `while(1)` loop of the `main()` function in `main.c`, add the following lines.

```c
HAL_GPIO_TogglePin(LED_BLUE_GPIO_Port, LED_BLUE_Pin);
HAL_Delay(333);
HAL_GPIO_TogglePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin);
HAL_Delay(333);
HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
HAL_Delay(333);
```

Now press `F5` or run the task *"Build and Flash"* to see the LEDs blinking!

---
> [!tip] Running Tasks
> To easily run tasks, use the VSCode Command Prompt by pressing `CMD + Shift + P` (on Mac), or `Ctrl + Shift + P` (on Windows),
> then type in `Tasks: Run Task` press Enter and select the task you want to run from the list!

---
> [!note] Tasks & CMake Extension
> The tasks.json is using shell commands, as I have found that using the CMake VSCode extension to not be too reliable.
>
> The extension brings some benefits like easily choosing between CMake profiles, but this I don't need.
