# Nucleo WB15CC - BLE HR Example

This example is mostly taken from the STM32CubeWB repository (added as a submodule under `../../lib`)

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
