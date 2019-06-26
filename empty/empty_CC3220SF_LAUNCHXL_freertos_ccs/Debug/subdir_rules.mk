################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"E:/ti/ccs/tools/compiler/ti-cgt-arm_18.12.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=vfplib -me --include_path="E:/workspace/empty_CC3220SF_LAUNCHXL_freertos_ccs" --include_path="C:/ti/simplelink_cc32xx_sdk_3_10_00_04/source" --include_path="C:/ti/simplelink_cc32xx_sdk_3_10_00_04/source/ti/posix/ccs" --include_path="E:/ti/FreeRTOSv10.0.1/FreeRTOS/Source/include" --include_path="E:/ti/FreeRTOSv10.0.1/FreeRTOS/Source/portable/CCS/ARM_CM3" --include_path="E:/workspace/freertos_builds_CC3220SF_LAUNCHXL_release_ccs" --include_path="E:/ti/ccs/tools/compiler/ti-cgt-arm_18.12.1.LTS/include" -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


