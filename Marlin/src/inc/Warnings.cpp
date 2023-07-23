/**
 * Marlin 3D打印机固件
 * 版权所有 (c) 2021 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * 基于Sprinter和grbl
 * 版权所有 (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * 本程序是自由软件：您可以在自由软件基金会发布的GNU通用公共许可证的条款下重新分发和/或修改
 * 它，无论是许可证的第三版还是（根据您的选择）任何以后的版本。
 *
 * 本程序的发布是希望它是有用的，
 * 但是没有任何明示或暗示的担保；甚至没有适销性或适用于特定用途的暗示保证。详见
 * GNU通用公共许可证获取更多细节。
 *
 * 您应该随同本程序收到一份GNU通用公共许可证的副本
 * 如果没有，请参阅<https://www.gnu.org/licenses/>。
 *
 */

/**
 * Warnings.cpp
 * 测试配置值并在编译时给出警告。
 */

#include "MarlinConfig.h"

//
// 警告！这里放置警告，以便它们只会在构建输出中出现一次。
//

#if ENABLED(MARLIN_DEV_MODE)
  #warning "警告！禁用MARLIN_DEV_MODE以进行最终构建！"
#endif

#if ENABLED(LA_DEBUG)
  #warning "警告！禁用LA_DEBUG以进行最终构建！"
#endif

#if NUM_AXES_WARNING
  #warning "注意：NUM_AXES现在基于*_DRIVER_TYPE设置，因此您可以从Configuration.h中删除NUM_AXES。"
#endif

// 安全功能
#if DISABLED(USE_WATCHDOG)
  #warning "安全警告！启用USE_WATCHDOG以进行最终构建！"
#endif
#if HAS_HOTEND && DISABLED(THERMAL_PROTECTION_HOTENDS)
  #warning "安全警告！启用THERMAL_PROTECTION_HOTENDS以进行最终构建！"
#endif
#if HAS_HEATED_BED && DISABLED(THERMAL_PROTECTION_BED)
  #warning "安全警告！启用THERMAL_PROTECTION_BED以进行最终构建！"
#endif
#if HAS_HEATED_CHAMBER && DISABLED(THERMAL_PROTECTION_CHAMBER)
  #warning "安全警告！启用THERMAL_PROTECTION_CHAMBER以进行最终构建！"
#endif
#if HAS_COOLER && DISABLED(THERMAL_PROTECTION_COOLER)
  #warning "安全警告！启用THERMAL_PROTECTION_COOLER以进行最终构建！"
#endif
#if ANY_THERMISTOR_IS(998) || ANY_THERMISTOR_IS(999)
  #warning "警告！不要在最终构建中使用虚拟热敏电阻（998/999）！"
#endif

#if NONE(HAS_RESUME_CONTINUE, HOST_PROMPT_SUPPORT)
  #warning "您的配置没有提供用户反馈的方法！"
#endif

#if MB(DUE3DOM_MINI) && PIN_EXISTS(TEMP_2) && !TEMP_SENSOR_BOARD
  #warning "BOARD_DUE3DOM_MINI的内置温度传感器已从TEMP_SENSOR_2（TEMP_2_PIN）移动到TEMP_SENSOR_BOARD（TEMP_BOARD_PIN）."
#elif MB(BTT_SKR_E3_TURBO) && PIN_EXISTS(TEMP_2) && !TEMP_SENSOR_BOARD
  #warning "BOARD_BTT_SKR_E3_TURBO的内置温度传感器已从TEMP_SENSOR_2（TEMP_2_PIN）移动到TEMP_SENSOR_BOARD（TEMP_BOARD_PIN）."
#endif

#ifndef NO_AUTO_ASSIGN_WARNING

  #if AUTO_ASSIGNED_LCD_SERIAL
    #warning "注意：自动分配了LCD_SERIAL_PORT。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
  #endif

  #if AUTO_ASSIGNED_X2_STEPPER
    #warning "注意：自动分配了X2 STEP/DIR/ENABLE_PINs到未使用的En_STEP/DIR/ENABLE_PINs。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
  #endif
  #if AUTO_ASSIGNED_X2_MS1
    #warning "注意：自动分配了X2_MS1_PIN到未使用的En_MS1_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
  #endif
  #if AUTO_ASSIGNED_X2_MS2
    #warning "注意：自动分配了X2_MS2_PIN到未使用的En_MS2_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
  #endif
  #if AUTO_ASSIGNED_X2_MS3
    #warning "注意：自动分配了X2_MS3_PIN到未使用的En_MS3_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
  #endif
  #if AUTO_ASSIGNED_X2_CS
    #warning "注意：自动分配了X2_CS_PIN到未使用的En_CS_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
  #endif
  #if AUTO_ASSIGNED_X2_DIAG
    #if X2_STOP_PIN == X_MIN_PIN
      #warning "注意：自动分配了X2感应式终点开关到X_MIN_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
    #elif X2_STOP_PIN == X_MAX_PIN
      #warning "注意：自动分配了X2感应式终点开关到X_MAX_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
    #elif X2_STOP_PIN == X_STOP_PIN
      #warning "注意：自动分配了X2感应式终点开关到X_STOP_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
    #elif X2_STOP_PIN == Y_MIN_PIN
      #warning "注意：自动分配了X2感应式终点开关到Y_MIN_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
    #elif X2_STOP_PIN == Y_MAX_PIN
      #warning "注意：自动分配了X2感应式终点开关到Y_MAX_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
    #elif X2_STOP_PIN == Y_STOP_PIN
      #warning "注意：自动分配了X2感应式终点开关到Y_STOP_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
    #elif X2_STOP_PIN == Z_MIN_PIN
      #warning "注意：自动分配了X2感应式终点开关到Z_MIN_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
#elif X2_STOP_PIN == Z_MAX_PIN
      #warning "注意：自动分配X2无传感器停止端点给Z_MAX_PIN。（定义NO_AUTO_ASSIGN_WARNING来屏蔽此警告。）"
    #elif X2_STOP_PIN == Z_STOP_PIN
      #warning "注意：自动分配X2无传感器停止端点给Z_STOP_PIN。（定义NO_AUTO_ASSIGN_WARNING来屏蔽此警告。）"
    #elif X2_STOP_PIN == E0_DIAG_PIN
      #warning "注意：自动分配X2无传感器停止端点给E0_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING来屏蔽此警告。）"
    #elif X2_STOP_PIN == E1_DIAG_PIN
      #warning "注意：自动分配X2无传感器停止端点给E1_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING来屏蔽此警告。）"
    #elif X2_STOP_PIN == E2_DIAG_PIN
      #warning "注意：自动分配X2无传感器停止端点给E2_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING来屏蔽此警告。）"
    #elif X2_STOP_PIN == E3_DIAG_PIN
      #warning "注意：自动分配X2无传感器停止端点给E3_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING来屏蔽此警告。）"
    #elif X2_STOP_PIN == E4_DIAG_PIN
      #warning "注意：自动分配X2无传感器停止端点给E4_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING来屏蔽此警告。）"
    #elif X2_STOP_PIN == E5_DIAG_PIN
      #warning "注意：自动分配X2无传感器停止端点给E5_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING来屏蔽此警告。）"
    #elif X2_STOP_PIN == E6_DIAG_PIN
      #warning "注意：自动分配X2无传感器停止端点给E6_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING来屏蔽此警告。）"
    #elif X2_STOP_PIN == E7_DIAG_PIN
      #warning "注意：自动分配X2无传感器停止端点给E7_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING来屏蔽此警告。）"
    #endif
  #endif
  #if AUTO_ASSIGNED_Y2_STEPPER
    #warning "注意：自动分配Y2步进/方向/使能针脚给未使用的En_STEP/DIR/ENABLE_PIN。（定义NO_AUTO_ASSIGN_WARNING来屏蔽此警告。）"
  #endif
  #if AUTO_ASSIGNED_Y2_MS1
    #warning "注意：自动分配Y2_MS1_PIN给未使用的En_MS1_PIN。（定义NO_AUTO_ASSIGN_WARNING来屏蔽此警告。）"
  #endif
  #if AUTO_ASSIGNED_Y2_MS2
    #warning "注意：自动分配Y2_MS2_PIN给未使用的En_MS2_PIN。（定义NO_AUTO_ASSIGN_WARNING来屏蔽此警告。）"
  #endif
  #if AUTO_ASSIGNED_Y2_MS3
    #warning "注意：自动分配Y2_MS3_PIN给未使用的En_MS3_PIN。（定义NO_AUTO_ASSIGN_WARNING来屏蔽此警告。）"
  #endif
  #if AUTO_ASSIGNED_Y2_CS
    #warning "注意：自动分配Y2_CS_PIN给未使用的En_CS_PIN。（定义NO_AUTO_ASSIGN_WARNING来屏蔽此警告。）"
  #endif
  #if AUTO_ASSIGNED_Y2_DIAG
    #if Y2_USE_ENDSTOP == X_MIN_PIN
      #warning "注意：自动分配Y2无传感器停止端点给X_MIN_PIN。（定义NO_AUTO_ASSIGN_WARNING来屏蔽此警告。）"
    #elif Y2_STOP_PIN == X_MAX_PIN
      #warning "注意：自动分配Y2无传感器停止端点给X_MAX_PIN。（定义NO_AUTO_ASSIGN_WARNING来屏蔽此警告。）"
    #elif Y2_STOP_PIN == X_STOP_PIN
      #warning "注意：自动分配Y2无传感器停止端点给X_STOP_PIN。（定义NO_AUTO_ASSIGN_WARNING来屏蔽此警告。）"
    #elif Y2_USE_ENDSTOP == Y_MIN_PIN
      #warning "注意：自动分配Y2无传感器停止端点给Y_MIN_PIN。（定义NO_AUTO_ASSIGN_WARNING来屏蔽此警告。）"
    #elif Y2_STOP_PIN == Y_MAX_PIN
      #warning "注意：自动分配Y2无传感器停止端点给Y_MAX_PIN。（定义NO_AUTO_ASSIGN_WARNING来屏蔽此警告。）"
    #elif Y2_STOP_PIN == Y_STOP_PIN
      #warning "注意：自动分配Y2无传感器停止端点给Y_STOP_PIN。（定义NO_AUTO_ASSIGN_WARNING来屏蔽此警告。）"
    #elif Y2_USE_ENDSTOP == Z_MIN_PIN
      #warning "注意：自动分配Y2无传感器停止端点给Z_MIN_PIN。（定义NO_AUTO_ASSIGN_WARNING来屏蔽此警告。）"
    #elif Y2_STOP_PIN == Z_MAX_PIN
      #warning "注意：自动分配Y2无传感器停止端点给Z_MAX_PIN。（定义NO_AUTO_ASSIGN_WARNING来屏蔽此警告。）"
    #elif Y2_STOP_PIN == Z_STOP_PIN
      #warning "注意：自动分配Y2无传感器停止端点给Z_STOP_PIN。（定义NO_AUTO_ASSIGN_WARNING来屏蔽此警告。）"
    #elif Y2_STOP_PIN == E0_DIAG_PIN
      #warning "注意：自动分配Y2无传感器停止端点给E0_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING来屏蔽此警告。）"
    #elif Y2_STOP_PIN == E1_DIAG_PIN
      #warning "注意：自动分配Y2无传感器停止端点给E1_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING来屏蔽此警告。）"
    #elif Y2_STOP_PIN == E2_DIAG_PIN
      #warning "注意：自动分配Y2无传感器停止端点给E2_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING来屏蔽此警告。）"
    #elif Y2_STOP_PIN == E3_DIAG_PIN
      #warning "注意：自动分配Y2无传感器停止端点给E3_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING来屏蔽此警告。）"
    #elif Y2_STOP_PIN == E4_DIAG_PIN
      #warning "注意：自动分配Y2无传感器停止端点给E4_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING来屏蔽此警告。）"
#elif Y2_STOP_PIN == E5_DIAG_PIN
      #warning "注意：自动分配Y2无传感器停止端点给E5_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING来屏蔽此警告。）"
    #elif Y2_STOP_PIN == E6_DIAG_PIN
      #warning "注意：自动分配Y2无传感器停止端点给E6_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING来屏蔽此警告。）"
    #elif Y2_STOP_PIN == E7_DIAG_PIN
      #warning "注意：自动分配Y2无传感器停止端点给E7_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING来屏蔽此警告。）"
    #endif
  #endif
  #if AUTO_ASSIGNED_Z2_STEPPER
    #warning "注意：自动分配Z2步进/方向/使能针脚给未使用的En_STEP/DIR/ENABLE_PIN。（定义NO_AUTO_ASSIGN_WARNING来屏蔽此警告。）"
  #endif
  #if AUTO_ASSIGNED_Z2_MS1
    #warning "注意：自动分配Z2_MS1_PIN给未使用的En_MS1_PIN。（定义NO_AUTO_ASSIGN_WARNING来屏蔽此警告。）"
  #endif
  #if AUTO_ASSIGNED_Z2_MS2
    #warning "注意：自动分配Z2_MS2_PIN给未使用的En_MS2_PIN。（定义NO_AUTO_ASSIGN_WARNING来屏蔽此警告。）"
  #endif
  #if AUTO_ASSIGNED_Z2_MS3
    #warning "注意：自动分配Z2_MS3_PIN给未使用的En_MS3_PIN。（定义NO_AUTO_ASSIGN_WARNING来屏蔽此警告。）"
  #endif
  #if AUTO_ASSIGNED_Z2_CS
    #warning "注意：自动分配Z2_CS_PIN给未使用的En_CS_PIN。（定义NO_AUTO_ASSIGN_WARNING来屏蔽此警告。）"
  #endif
  #if AUTO_ASSIGNED_Z2_DIAG
    #if Z2_USE_ENDSTOP == X_MIN_PIN
      #warning "注意：自动分配Z2无传感器停止端点给X_MIN_PIN。（定义NO_AUTO_ASSIGN_WARNING来屏蔽此警告。）"
    #elif Z2_STOP_PIN == X_MAX_PIN
      #warning "注意：自动分配Z2无传感器停止端点给X_MAX_PIN。（定义NO_AUTO_ASSIGN_WARNING来屏蔽此警告。）"
    #elif Z2_STOP_PIN == X_STOP_PIN
      #warning "注意：自动分配Z2无传感器停止端点给X_STOP_PIN。（定义NO_AUTO_ASSIGN_WARNING来屏蔽此警告。）"
    #elif Z2_USE_ENDSTOP == Y_MIN_PIN
      #warning "注意：自动分配Z2无传感器停止端点给Y_MIN_PIN。（定义NO_AUTO_ASSIGN_WARNING来屏蔽此警告。）"
    #elif Z2_STOP_PIN == Y_MAX_PIN
      #warning "注意：自动分配Z2无传感器停止端点给Y_MAX_PIN。（定义NO_AUTO_ASSIGN_WARNING来屏蔽此警告。）"
    #elif Z2_STOP_PIN == Y_STOP_PIN
      #warning "注意：自动分配Z2无传感器停止端点给Y_STOP_PIN。（定义NO_AUTO_ASSIGN_WARNING来屏蔽此警告。）"
    #elif Z2_USE_ENDSTOP == Z_MIN_PIN
      #warning "注意：自动分配Z2无传感器停止端点给Z_MIN_PIN。（定义NO_AUTO_ASSIGN_WARNING来屏蔽此警告。）"
    #elif Z2_STOP_PIN == Z_MAX_PIN
      #warning "注意：自动分配Z2无传感器停止端点给Z_MAX_PIN。（定义NO_AUTO_ASSIGN_WARNING来屏蔽此警告。）"
    #elif Z2_STOP_PIN == Z_STOP_PIN
      #warning "注意：自动分配Z2无传感器停止端点给Z_STOP_PIN。（定义NO_AUTO_ASSIGN_WARNING来屏蔽此警告。）"
    #elif Z2_STOP_PIN == E0_DIAG_PIN
      #warning "注意：自动分配Z2无传感器停止端点给E0_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING来屏蔽此警告。）"
    #elif Z2_STOP_PIN == E1_DIAG_PIN
      #warning "注意：自动分配Z2无传感器停止端点给E1_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING来屏蔽此警告。）"
    #elif Z2_STOP_PIN == E2_DIAG_PIN
      #warning "注意：自动分配Z2无传感器停止端点给E2_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING来屏蔽此警告。）"
    #elif Z2_STOP_PIN == E3_DIAG_PIN
      #warning "注意：自动分配Z2无传感器停止端点给E3_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING来屏蔽此警告。）"
    #elif Z2_STOP_PIN == E4_DIAG_PIN
      #warning "注意：自动分配Z2无传感器停止端点给E4_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING来屏蔽此警告。）"
    #elif Z2_STOP_PIN == E5_DIAG_PIN
      #warning "注意：自动分配Z2无传感器停止端点给E5_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING来屏蔽此警告。）"
    #elif Z2_STOP_PIN == E6_DIAG_PIN
      #warning "注意：自动分配Z2无传感器停止端点给E6_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING来屏蔽此警告。）"
    #elif Z2_STOP_PIN == E7_DIAG_PIN
      #warning "注意：自动分配Z2无传感器停止端点给E7_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING来屏蔽此警告。）"
    #endif
  #endif
  #if AUTO_ASSIGNED_Z3_STEPPER
    #warning "注意：自动分配Z3步进/方向/使能针脚给未使用的En_STEP/DIR/ENABLE_PIN。（定义NO_AUTO_ASSIGN_WARNING来屏蔽此警告。）"
  #endif
  #if AUTO_ASSIGNED_Z3_CS
    #warning "注意：自动分配Z3_CS_PIN给未使用的En_CS_PIN。（定义NO_AUTO_ASSIGN_WARNING来屏蔽此警告。）"
  #endif
  #if AUTO_ASSIGNED_Z3_MS1
    #warning "注意：自动分配Z3_MS1_PIN给未使用的En_MS1_PIN。（定义NO_AUTO_ASSIGN_WARNING来屏蔽此警告。）"
  #endif
  #if AUTO_ASSIGNED_Z3_MS2
    #warning "注意：自动分配Z3_MS2_PIN给未使用的En_MS2_PIN。（定义NO_AUTO_ASSIGN_WARNING来屏蔽此警告。）"
  #endif
  #if AUTO_ASSIGNED_Z3_MS3
    #warning "注意：自动分配Z3_MS3_PIN给未使用的En_MS3_PIN。（定义NO_AUTO_ASSIGN_WARNING来屏蔽此警告。）"
  #endif
#if AUTO_ASSIGNED_Z3_DIAG
    #if Z3_USE_ENDSTOP == X_MIN_PIN
      #warning "注意：自动分配了Z3无感应限位开关到X_MIN_PIN。 (定义NO_AUTO_ASSIGN_WARNING以忽略此警告。)"
    #elif Z3_STOP_PIN == X_MAX_PIN
      #warning "注意：自动分配了Z3无感应限位开关到X_MAX_PIN。 (定义NO_AUTO_ASSIGN_WARNING以忽略此警告。)"
    #elif Z3_STOP_PIN == X_STOP_PIN
      #warning "注意：自动分配了Z3无感应限位开关到X_STOP_PIN。 (定义NO_AUTO_ASSIGN_WARNING以忽略此警告。)"
    #elif Z3_USE_ENDSTOP == Y_MIN_PIN
      #warning "注意：自动分配了Z3无感应限位开关到Y_MIN_PIN。 (定义NO_AUTO_ASSIGN_WARNING以忽略此警告。)"
    #elif Z3_STOP_PIN == Y_MAX_PIN
      #warning "注意：自动分配了Z3无感应限位开关到Y_MAX_PIN。 (定义NO_AUTO_ASSIGN_WARNING以忽略此警告。)"
    #elif Z3_STOP_PIN == Y_STOP_PIN
      #warning "注意：自动分配了Z3无感应限位开关到Y_STOP_PIN。 (定义NO_AUTO_ASSIGN_WARNING以忽略此警告。)"
    #elif Z3_USE_ENDSTOP == Z_MIN_PIN
      #warning "注意：自动分配了Z3无感应限位开关到Z_MIN_PIN。 (定义NO_AUTO_ASSIGN_WARNING以忽略此警告。)"
    #elif Z3_STOP_PIN == Z_MAX_PIN
      #warning "注意：自动分配了Z3无感应限位开关到Z_MAX_PIN。 (定义NO_AUTO_ASSIGN_WARNING以忽略此警告。)"
    #elif Z3_STOP_PIN == Z_STOP_PIN
      #warning "注意：自动分配了Z3无感应限位开关到Z_STOP_PIN。 (定义NO_AUTO_ASSIGN_WARNING以忽略此警告。)"
    #elif Z3_STOP_PIN == E0_DIAG_PIN
      #warning "注意：自动分配了Z3无感应限位开关到E0_DIAG_PIN。 (定义NO_AUTO_ASSIGN_WARNING以忽略此警告。)"
    #elif Z3_STOP_PIN == E1_DIAG_PIN
      #warning "注意：自动分配了Z3无感应限位开关到E1_DIAG_PIN。 (定义NO_AUTO_ASSIGN_WARNING以忽略此警告。)"
    #elif Z3_STOP_PIN == E2_DIAG_PIN
      #warning "注意：自动分配了Z3无感应限位开关到E2_DIAG_PIN。 (定义NO_AUTO_ASSIGN_WARNING以忽略此警告。)"
    #elif Z3_STOP_PIN == E3_DIAG_PIN
      #warning "注意：自动分配了Z3无感应限位开关到E3_DIAG_PIN。 (定义NO_AUTO_ASSIGN_WARNING以忽略此警告。)"
    #elif Z3_STOP_PIN == E4_DIAG_PIN
      #warning "注意：自动分配了Z3无感应限位开关到E4_DIAG_PIN。 (定义NO_AUTO_ASSIGN_WARNING以忽略此警告。)"
    #elif Z3_STOP_PIN == E5_DIAG_PIN
      #warning "注意：自动分配了Z3无感应限位开关到E5_DIAG_PIN。 (定义NO_AUTO_ASSIGN_WARNING以忽略此警告。)"
    #elif Z3_STOP_PIN == E6_DIAG_PIN
      #warning "注意：自动分配了Z3无感应限位开关到E6_DIAG_PIN。 (定义NO_AUTO_ASSIGN_WARNING以忽略此警告。)"
    #elif Z3_STOP_PIN == E7_DIAG_PIN
      #warning "注意：自动分配了Z3无感应限位开关到E7_DIAG_PIN。 (定义NO_AUTO_ASSIGN_WARNING以忽略此警告。)"
    #endif
#endif
#if AUTO_ASSIGNED_Z4_STEPPER
    #warning "注意：自动分配了Z4 STEP/DIR/ENABLE_PIN到未使用的En_STEP/DIR/ENABLE_PIN。 (定义NO_AUTO_ASSIGN_WARNING以忽略此警告。)"
#endif
#if AUTO_ASSIGNED_Z4_CS
    #warning "注意：自动分配了Z4_CS_PIN到未使用的En_CS_PIN。 (定义NO_AUTO_ASSIGN_WARNING以忽略此警告。)"
#endif
#if AUTO_ASSIGNED_Z4_MS1
    #warning "注意：自动分配了Z4_MS1_PIN到未使用的En_MS1_PIN。 (定义NO_AUTO_ASSIGN_WARNING以忽略此警告。)"
#endif
#if AUTO_ASSIGNED_Z4_MS2
    #warning "注意：自动分配了Z4_MS2_PIN到未使用的En_MS2_PIN。 (定义NO_AUTO_ASSIGN_WARNING以忽略此警告。)"
#endif
#if AUTO_ASSIGNED_Z4_MS3
    #warning "注意：自动分配了Z4_MS3_PIN到未使用的En_MS3_PIN。 (定义NO_AUTO_ASSIGN_WARNING以忽略此警告。)"
#endif
#if AUTO_ASSIGNED_Z4_DIAG
    #if Z4_USE_ENDSTOP == X_MIN_PIN
        #warning "注意：自动分配了Z4无感应限位开关到X_MIN_PIN。 (定义NO_AUTO_ASSIGN_WARNING以忽略此警告。)"
    #elif Z4_STOP_PIN == X_MAX_PIN
        #warning "注意：自动分配了Z4无感应限位开关到X_MAX_PIN。 (定义NO_AUTO_ASSIGN_WARNING以忽略此警告。)"
    #elif Z4_STOP_PIN == X_STOP_PIN
        #warning "注意：自动分配了Z4无感应限位开关到X_STOP_PIN。 (定义NO_AUTO_ASSIGN_WARNING以忽略此警告。)"
    #elif Z4_USE_ENDSTOP == Y_MIN_PIN
        #warning "注意：自动分配了Z4无感应限位开关到Y_MIN_PIN。 (定义NO_AUTO_ASSIGN_WARNING以忽略此警告。)"
    #elif Z4_STOP_PIN == Y_MAX_PIN
        #warning "注意：自动分配了Z4无感应限位开关到Y_MAX_PIN。 (定义NO_AUTO_ASSIGN_WARNING以忽略此警告。)"
    #elif Z4_STOP_PIN == Y_STOP_PIN
        #warning "注意：自动分配了Z4无感应限位开关到Y_STOP_PIN。 (定义NO_AUTO_ASSIGN_WARNING以忽略此警告。)"
    #elif Z4_USE_ENDSTOP == Z_MIN_PIN
        #warning "注意：自动分配了Z4无感应限位开关到Z_MIN_PIN。 (定义NO_AUTO_ASSIGN_WARNING以忽略此警告。)"
    #elif Z4_STOP_PIN == Z_MAX_PIN
        #warning "注意：自动分配了Z4无感应限位开关到Z_MAX_PIN。 (定义NO_AUTO_ASSIGN_WARNING以忽略此警告。)"
    #elif Z4_STOP_PIN == Z_STOP_PIN
        #warning "注意：自动分配了Z4无感应限位开关到Z_STOP_PIN。 (定义NO_AUTO_ASSIGN_WARNING以忽略此警告。)"
    #elif Z4_STOP_PIN == E0_DIAG_PIN
        #warning "注意：自动分配了Z4无感应限位开关到E0_DIAG_PIN。 (定义NO_AUTO_ASSIGN_WARNING以忽略此警告。)"
    #elif Z4_STOP_PIN == E1_DIAG_PIN
        #warning "注意：自动分配了Z4无感应限位开关到E1_DIAG_PIN。 (定义NO_AUTO_ASSIGN_WARNING以忽略此警告。)"
    #elif Z4_STOP_PIN == E2_DIAG_PIN
        #warning "注意：自动分配了Z4无感应限位开关到E2_DIAG_PIN。 (定义NO_AUTO_ASSIGN_WARNING以忽略此警告。)"
    #elif Z4_STOP_PIN == E3_DIAG_PIN
        #warning "注意：自动分配了Z4无感应限位开关到E3_DIAG_PIN。 (定义NO_AUTO_ASSIGN_WARNING以忽略此警告。)"
    #elif Z4_STOP_PIN == E4_DIAG_PIN
        #warning "注意：自动分配了Z4无感应限位开关到E4_DIAG_PIN。 (定义NO_AUTO_ASSIGN_WARNING以忽略此警告。)"
    #elif Z4_STOP_PIN == E5_DIAG_PIN
        #warning "注意：自动分配了Z4无感应限位开关到E5_DIAG_PIN。 (定义NO_AUTO_ASSIGN_WARNING以忽略此警告。)"
    #elif Z4_STOP_PIN == E6_DIAG_PIN
        #warning "注意：自动分配了Z4无感应限位开关到E6_DIAG_PIN。 (定义NO_AUTO_ASSIGN_WARNING以忽略此警告。)"
    #elif Z4_STOP_PIN == E7_DIAG_PIN
        #warning "注意：自动分配了Z4无感应限位开关到E7_DIAG_PIN。 (定义NO_AUTO_ASSIGN_WARNING以忽略此警告。)"
    #endif
  #endif
  #if AUTO_ASSIGNED_I_STEPPER
      #warning "注意：自动分配了I STEP/DIR/ENABLE_PIN到未使用的En_STEP/DIR/ENABLE_PIN。 (定义NO_AUTO_ASSIGN_WARNING以忽略此警告。)"
  #endif
  #if AUTO_ASSIGNED_I_CS
      #warning "注意：自动分配了I_CS_PIN到未使用的En_CS_PIN。 (定义NO_AUTO_ASSIGN_WARNING以忽略此警告。)"
  #endif
  #if AUTO_ASSIGNED_I_MS1
      #warning "注意：自动分配了I_MS1_PIN到未使用的En_MS1_PIN。 (定义NO_AUTO_ASSIGN_WARNING以忽略此警告。)"
  #endif
  #if AUTO_ASSIGNED_I_MS2
      #warning "注意：自动分配了I_MS2_PIN到未使用的En_MS2_PIN。 (定义NO_AUTO_ASSIGN_WARNING以忽略此警告。)"
  #endif
#if AUTO_ASSIGNED_I_MS3
    #warning "注意：将I_MS3_PIN自动分配给未使用的En_MS3_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
#endif
#if AUTO_ASSIGNED_I_DIAG
    #if I_STOP_PIN == X_MIN_PIN
        #warning "注意：将I无感结束开关自动分配给X_MIN_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
    #elif I_STOP_PIN == X_MAX_PIN
        #warning "注意：将I无感结束开关自动分配给X_MAX_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
    #elif I_STOP_PIN == X_STOP_PIN
        #warning "注意：将I无感结束开关自动分配给X_STOP_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
    #elif I_STOP_PIN == Y_MIN_PIN
        #warning "注意：将I无感结束开关自动分配给Y_MIN_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
    #elif I_STOP_PIN == Y_MAX_PIN
        #warning "注意：将I无感结束开关自动分配给Y_MAX_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
    #elif I_STOP_PIN == Y_STOP_PIN
        #warning "注意：将I无感结束开关自动分配给Y_STOP_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
    #elif I_STOP_PIN == Z_MIN_PIN
        #warning "注意：将I无感结束开关自动分配给Z_MIN_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
    #elif I_STOP_PIN == Z_MAX_PIN
        #warning "注意：将I无感结束开关自动分配给Z_MAX_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
    #elif I_STOP_PIN == Z_STOP_PIN
        #warning "注意：将I无感结束开关自动分配给Z_STOP_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
    #elif I_STOP_PIN == E0_DIAG_PIN
        #warning "注意：将I无感结束开关自动分配给E0_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
    #elif I_STOP_PIN == E1_DIAG_PIN
        #warning "注意：将I无感结束开关自动分配给E1_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
    #elif I_STOP_PIN == E2_DIAG_PIN
        #warning "注意：将I无感结束开关自动分配给E2_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
    #elif I_STOP_PIN == E3_DIAG_PIN
        #warning "注意：将I无感结束开关自动分配给E3_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
    #elif I_STOP_PIN == E4_DIAG_PIN
        #warning "注意：将I无感结束开关自动分配给E4_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
    #elif I_STOP_PIN == E5_DIAG_PIN
        #warning "注意：将I无感结束开关自动分配给E5_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
    #elif I_STOP_PIN == E6_DIAG_PIN
        #warning "注意：将I无感结束开关自动分配给E6_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
    #elif I_STOP_PIN == E7_DIAG_PIN
        #warning "注意：将I无感结束开关自动分配给E7_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
    #endif
#endif
#if AUTO_ASSIGNED_J_STEPPER
    #warning "注意：将J STEP/DIR/ENABLE_PIN自动分配给未使用的En_STEP/DIR/ENABLE_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
#endif
#if AUTO_ASSIGNED_J_CS
    #warning "注意：将J_CS_PIN自动分配给未使用的En_CS_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
#endif
#if AUTO_ASSIGNED_J_MS1
    #warning "注意：将J_MS1_PIN自动分配给未使用的En_MS1_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
#endif
#if AUTO_ASSIGNED_J_MS2
    #warning "注意：将J_MS2_PIN自动分配给未使用的En_MS2_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
#endif
#if AUTO_ASSIGNED_J_MS3
    #warning "注意：将J_MS3_PIN自动分配给未使用的En_MS3_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
#endif
#if AUTO_ASSIGNED_J_DIAG
    #if J_STOP_PIN == X_MIN_PIN
        #warning "注意：将J无感结束开关自动分配给X_MIN_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
    #elif J_STOP_PIN == X_MAX_PIN
        #warning "注意：将J无感结束开关自动分配给X_MAX_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
    #elif J_STOP_PIN == X_STOP_PIN
        #warning "注意：将J无感结束开关自动分配给X_STOP_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
    #elif J_STOP_PIN == Y_MIN_PIN
        #warning "注意：将J无感结束开关自动分配给Y_MIN_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
    #elif J_STOP_PIN == Y_MAX_PIN
        #warning "注意：将J无感结束开关自动分配给Y_MAX_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
#elif J_STOP_PIN == Y_STOP_PIN
      #warning "注意：自动将J传感器无端点分配给Y_STOP_PIN。（定义NO_AUTO_ASSIGN_WARNING以取消此警告。）"
    #elif J_STOP_PIN == Z_MIN_PIN
      #warning "注意：自动将J传感器无端点分配给Z_MIN_PIN。（定义NO_AUTO_ASSIGN_WARNING以取消此警告。）"
    #elif J_STOP_PIN == Z_MAX_PIN
      #warning "注意：自动将J传感器无端点分配给Z_MAX_PIN。（定义NO_AUTO_ASSIGN_WARNING以取消此警告。）"
    #elif J_STOP_PIN == Z_STOP_PIN
      #warning "注意：自动将J传感器无端点分配给Z_STOP_PIN。（定义NO_AUTO_ASSIGN_WARNING以取消此警告。）"
    #elif J_STOP_PIN == E0_DIAG_PIN
      #warning "注意：自动将J传感器无端点分配给E0_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING以取消此警告。）"
    #elif J_STOP_PIN == E1_DIAG_PIN
      #warning "注意：自动将J传感器无端点分配给E1_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING以取消此警告。）"
    #elif J_STOP_PIN == E2_DIAG_PIN
      #warning "注意：自动将J传感器无端点分配给E2_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING以取消此警告。）"
    #elif J_STOP_PIN == E3_DIAG_PIN
      #warning "注意：自动将J传感器无端点分配给E3_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING以取消此警告。）"
    #elif J_STOP_PIN == E4_DIAG_PIN
      #warning "注意：自动将J传感器无端点分配给E4_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING以取消此警告。）"
    #elif J_STOP_PIN == E5_DIAG_PIN
      #warning "注意：自动将J传感器无端点分配给E5_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING以取消此警告。）"
    #elif J_STOP_PIN == E6_DIAG_PIN
      #warning "注意：自动将J传感器无端点分配给E6_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING以取消此警告。）"
    #elif J_STOP_PIN == E7_DIAG_PIN
      #warning "注意：自动将J传感器无端点分配给E7_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING以取消此警告。）"
    #endif
  #endif
  #if AUTO_ASSIGNED_K_STEPPER
    #warning "注意：自动将K STEP/DIR/ENABLE_PIN分配给未使用的En_STEP/DIR/ENABLE_PIN。（定义NO_AUTO_ASSIGN_WARNING以取消此警告。）"
  #endif
  #if AUTO_ASSIGNED_K_CS
    #warning "注意：自动将K_CS_PIN分配给未使用的En_CS_PIN。（定义NO_AUTO_ASSIGN_WARNING以取消此警告。）"
  #endif
  #if AUTO_ASSIGNED_K_MS1
    #warning "注意：自动将K_MS1_PIN分配给未使用的En_MS1_PIN。（定义NO_AUTO_ASSIGN_WARNING以取消此警告。）"
  #endif
  #if AUTO_ASSIGNED_K_MS2
    #warning "注意：自动将K_MS2_PIN分配给未使用的En_MS2_PIN。（定义NO_AUTO_ASSIGN_WARNING以取消此警告。）"
  #endif
  #if AUTO_ASSIGNED_K_MS3
    #warning "注意：自动将K_MS3_PIN分配给未使用的En_MS3_PIN。（定义NO_AUTO_ASSIGN_WARNING以取消此警告。）"
  #endif
  #if AUTO_ASSIGNED_K_DIAG
    #if K_STOP_PIN == X_MIN_PIN
      #warning "注意：自动将K传感器无端点分配给X_MIN_PIN。（定义NO_AUTO_ASSIGN_WARNING以取消此警告。）"
    #elif K_STOP_PIN == X_MAX_PIN
      #warning "注意：自动将K传感器无端点分配给X_MAX_PIN。（定义NO_AUTO_ASSIGN_WARNING以取消此警告。）"
    #elif K_STOP_PIN == X_STOP_PIN
      #warning "注意：自动将K传感器无端点分配给X_STOP_PIN。（定义NO_AUTO_ASSIGN_WARNING以取消此警告。）"
    #elif K_STOP_PIN == Y_MIN_PIN
      #warning "注意：自动将K传感器无端点分配给Y_MIN_PIN。（定义NO_AUTO_ASSIGN_WARNING以取消此警告。）"
    #elif K_STOP_PIN == Y_MAX_PIN
      #warning "注意：自动将K传感器无端点分配给Y_MAX_PIN。（定义NO_AUTO_ASSIGN_WARNING以取消此警告。）"
    #elif K_STOP_PIN == Y_STOP_PIN
      #warning "注意：自动将K传感器无端点分配给Y_STOP_PIN。（定义NO_AUTO_ASSIGN_WARNING以取消此警告。）"
    #elif K_STOP_PIN == Z_MIN_PIN
      #warning "注意：自动将K传感器无端点分配给Z_MIN_PIN。（定义NO_AUTO_ASSIGN_WARNING以取消此警告。）"
    #elif K_STOP_PIN == Z_MAX_PIN
      #warning "注意：自动将K传感器无端点分配给Z_MAX_PIN。（定义NO_AUTO_ASSIGN_WARNING以取消此警告。）"
    #elif K_STOP_PIN == Z_STOP_PIN
      #warning "注意：自动将K传感器无端点分配给Z_STOP_PIN。（定义NO_AUTO_ASSIGN_WARNING以取消此警告。）"
    #elif K_STOP_PIN == E0_DIAG_PIN
      #warning "注意：自动将K传感器无端点分配给E0_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING以取消此警告。）"
#elif K_STOP_PIN == E1_DIAG_PIN
      #warning "注意：将K传感器无感应终止点自动分配给E1_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
    #elif K_STOP_PIN == E2_DIAG_PIN
      #warning "注意：将K传感器无感应终止点自动分配给E2_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
    #elif K_STOP_PIN == E3_DIAG_PIN
      #warning "注意：将K传感器无感应终止点自动分配给E3_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
    #elif K_STOP_PIN == E4_DIAG_PIN
      #warning "注意：将K传感器无感应终止点自动分配给E4_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
    #elif K_STOP_PIN == E5_DIAG_PIN
      #warning "注意：将K传感器无感应终止点自动分配给E5_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
    #elif K_STOP_PIN == E6_DIAG_PIN
      #warning "注意：将K传感器无感应终止点自动分配给E6_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
    #elif K_STOP_PIN == E7_DIAG_PIN
      #warning "注意：将K传感器无感应终止点自动分配给E7_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
    #endif
  #endif

  #if AUTO_ASSIGNED_U_STEPPER
    #warning "注意：将U_STEP/DIR/ENABLE_PIN自动分配给未使用的En_STEP/DIR/ENABLE_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
  #endif
  #if AUTO_ASSIGNED_U_CS
    #warning "注意：将U_CS_PIN自动分配给未使用的En_CS_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
  #endif
  #if AUTO_ASSIGNED_U_MS1
    #warning "注意：将U_MS1_PIN自动分配给未使用的En_MS1_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
  #endif
  #if AUTO_ASSIGNED_U_MS2
    #warning "注意：将U_MS2_PIN自动分配给未使用的En_MS2_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
  #endif
  #if AUTO_ASSIGNED_U_MS3
    #warning "注意：将U_MS3_PIN自动分配给未使用的En_MS3_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
  #endif
  #if AUTO_ASSIGNED_U_DIAG
    #if U_STOP_PIN == X_MIN_PIN
      #warning "注意：将U传感器无感应终止点自动分配给X_MIN_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
    #elif U_STOP_PIN == X_MAX_PIN
      #warning "注意：将U传感器无感应终止点自动分配给X_MAX_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
    #elif K_STOP_PIN == Y_MIN_PIN
      #warning "注意：将U传感器无感应终止点自动分配给Y_MIN_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
    #elif U_STOP_PIN == Y_MAX_PIN
      #warning "注意：将U传感器无感应终止点自动分配给Y_MAX_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
    #elif U_STOP_PIN == Z_MIN_PIN
      #warning "注意：将U传感器无感应终止点自动分配给Z_MIN_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
    #elif U_STOP_PIN == Z_MAX_PIN
      #warning "注意：将U传感器无感应终止点自动分配给Z_MAX_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
    #elif U_STOP_PIN == E0_DIAG_PIN
      #warning "注意：将U传感器无感应终止点自动分配给E0_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
    #elif U_STOP_PIN == E1_DIAG_PIN
      #warning "注意：将U传感器无感应终止点自动分配给E1_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
    #elif U_STOP_PIN == E2_DIAG_PIN
      #warning "注意：将U传感器无感应终止点自动分配给E2_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
    #elif U_STOP_PIN == E3_DIAG_PIN
      #warning "注意：将U传感器无感应终止点自动分配给E3_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
    #elif U_STOP_PIN == E4_DIAG_PIN
      #warning "注意：将U传感器无感应终止点自动分配给E4_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
    #elif U_STOP_PIN == E5_DIAG_PIN
      #warning "注意：将U传感器无感应终止点自动分配给E5_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
    #elif U_STOP_PIN == E6_DIAG_PIN
      #warning "注意：将U传感器无感应终止点自动分配给E6_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
    #elif U_STOP_PIN == E7_DIAG_PIN
      #warning "注意：将U传感器无感应终止点自动分配给E7_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
    #endif
  #endif
  #if AUTO_ASSIGNED_V_STEPPER
    #warning "注意：将V_STEP/DIR/ENABLE_PIN自动分配给未使用的En_STEP/DIR/ENABLE_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
  #endif
#if AUTO_ASSIGNED_V_CS
    #warning "注意：自动将V_CS_PIN分配给未使用的En_CS_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
#endif
#if AUTO_ASSIGNED_V_MS1
    #warning "注意：自动将V_MS1_PIN分配给未使用的En_MS1_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
#endif
#if AUTO_ASSIGNED_V_MS2
    #warning "注意：自动将V_MS2_PIN分配给未使用的En_MS2_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
#endif
#if AUTO_ASSIGNED_V_MS3
    #warning "注意：自动将V_MS3_PIN分配给未使用的En_MS3_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
#endif
#if AUTO_ASSIGNED_V_DIAG
    #if V_STOP_PIN == X_MIN_PIN
        #warning "注意：自动将V无感应限位开关分配给X_MIN_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
    #elif V_STOP_PIN == X_MAX_PIN
        #warning "注意：自动将V无感应限位开关分配给X_MAX_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
    #elif V_STOP_PIN == Y_MIN_PIN
        #warning "注意：自动将V无感应限位开关分配给Y_MIN_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
    #elif V_STOP_PIN == Y_MAX_PIN
        #warning "注意：自动将V无感应限位开关分配给Y_MAX_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
    #elif V_STOP_PIN == Z_MIN_PIN
        #warning "注意：自动将V无感应限位开关分配给Z_MIN_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
    #elif V_STOP_PIN == Z_MAX_PIN
        #warning "注意：自动将V无感应限位开关分配给Z_MAX_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
    #elif V_STOP_PIN == E0_DIAG_PIN
        #warning "注意：自动将V无感应限位开关分配给E0_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
    #elif V_STOP_PIN == E1_DIAG_PIN
        #warning "注意：自动将V无感应限位开关分配给E1_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
    #elif V_STOP_PIN == E2_DIAG_PIN
        #warning "注意：自动将V无感应限位开关分配给E2_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
    #elif V_STOP_PIN == E3_DIAG_PIN
        #warning "注意：自动将V无感应限位开关分配给E3_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
    #elif V_STOP_PIN == E4_DIAG_PIN
        #warning "注意：自动将V无感应限位开关分配给E4_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
    #elif V_STOP_PIN == E5_DIAG_PIN
        #warning "注意：自动将V无感应限位开关分配给E5_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
    #elif V_STOP_PIN == E6_DIAG_PIN
        #warning "注意：自动将V无感应限位开关分配给E6_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
    #elif V_STOP_PIN == E7_DIAG_PIN
        #warning "注意：自动将V无感应限位开关分配给E7_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
    #endif
  #endif
  #if AUTO_ASSIGNED_W_STEPPER
      #warning "注意：自动将W STEP/DIR/ENABLE_PIN分配给未使用的En_STEP/DIR/ENABLE_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
  #endif
  #if AUTO_ASSIGNED_W_CS
      #warning "注意：自动将W_CS_PIN分配给未使用的En_CS_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
  #endif
  #if AUTO_ASSIGNED_W_MS1
      #warning "注意：自动将W_MS1_PIN分配给未使用的En_MS1_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
  #endif
  #if AUTO_ASSIGNED_W_MS2
      #warning "注意：自动将W_MS2_PIN分配给未使用的En_MS2_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
  #endif
  #if AUTO_ASSIGNED_W_MS3
      #warning "注意：自动将W_MS3_PIN分配给未使用的En_MS3_PIN。（定义NO_AUTO_ASSIGN_WARNING以抑制此警告。）"
  #endif
#if AUTO_ASSIGNED_W_DIAG
    #if W_STOP_PIN == X_MIN_PIN
      #warning "注意：自动分配W无传感器终点到X_MIN_PIN。（定义NO_AUTO_ASSIGN_WARNING来忽略此警告。）"
    #elif W_STOP_PIN == X_MAX_PIN
      #warning "注意：自动分配W无传感器终点到X_MAX_PIN。（定义NO_AUTO_ASSIGN_WARNING来忽略此警告。）"
    #elif W_STOP_PIN == Y_MIN_PIN
      #warning "注意：自动分配W无传感器终点到Y_MIN_PIN。（定义NO_AUTO_ASSIGN_WARNING来忽略此警告。）"
    #elif W_STOP_PIN == Y_MAX_PIN
      #warning "注意：自动分配W无传感器终点到Y_MAX_PIN。（定义NO_AUTO_ASSIGN_WARNING来忽略此警告。）"
    #elif W_STOP_PIN == Z_MIN_PIN
      #warning "注意：自动分配W无传感器终点到Z_MIN_PIN。（定义NO_AUTO_ASSIGN_WARNING来忽略此警告。）"
    #elif W_STOP_PIN == Z_MAX_PIN
      #warning "注意：自动分配W无传感器终点到Z_MAX_PIN。（定义NO_AUTO_ASSIGN_WARNING来忽略此警告。）"
    #elif W_STOP_PIN == E0_DIAG_PIN
      #warning "注意：自动分配W无传感器终点到E0_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING来忽略此警告。）"
    #elif W_STOP_PIN == E1_DIAG_PIN
      #warning "注意：自动分配W无传感器终点到E1_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING来忽略此警告。）"
    #elif W_STOP_PIN == E2_DIAG_PIN
      #warning "注意：自动分配W无传感器终点到E2_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING来忽略此警告。）"
    #elif W_STOP_PIN == E3_DIAG_PIN
      #warning "注意：自动分配W无传感器终点到E3_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING来忽略此警告。）"
    #elif W_STOP_PIN == E4_DIAG_PIN
      #warning "注意：自动分配W无传感器终点到E4_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING来忽略此警告。）"
    #elif W_STOP_PIN == E5_DIAG_PIN
      #warning "注意：自动分配W无传感器终点到E5_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING来忽略此警告。）"
    #elif W_STOP_PIN == E6_DIAG_PIN
      #warning "注意：自动分配W无传感器终点到E6_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING来忽略此警告。）"
    #elif W_STOP_PIN == E7_DIAG_PIN
      #warning "注意：自动分配W无传感器终点到E7_DIAG_PIN。（定义NO_AUTO_ASSIGN_WARNING来忽略此警告。）"
    #endif
  #endif

  #if ENABLED(CHAMBER_FAN) && !defined(CHAMBER_FAN_INDEX)
    #warning "注意：自动分配CHAMBER_FAN_INDEX到第一个空闲的FAN引脚。（定义NO_AUTO_ASSIGN_WARNING来忽略此警告。）"
  #endif

#endif // !NO_AUTO_ASSIGN_WARNING

#if IS_LEGACY_TFT
  #warning "不要忘记在Configuration.h中更新TFT设置。"
#endif

#if ENABLED(EMIT_CREALITY_422_WARNING) && DISABLED(NO_CREALITY_422_DRIVER_WARNING)
  #warning "Creality 4.2.2主板配备了各种步进驱动器。请检查主板标签（通常在SD卡模块上）并设置正确的*_DRIVER_TYPE！（C=HR4988，E=A4988，A=TMC2208，B=TMC2209，H=TMC2225，H8=HR4988）。（定义NO_CREALITY_422_DRIVER_WARNING来忽略此警告。）"
#endif

#if ENABLED(PRINTCOUNTER_SYNC)
  #warning "为了防止丢步，动作将暂停以进行PRINTCOUNTER自动保存。"
#endif

#if HOMING_Z_WITH_PROBE && IS_CARTESIAN && DISABLED(Z_SAFE_HOMING)
  #error "当使用探针进行归位时，建议启用Z_SAFE_HOMING。启用Z_SAFE_HOMING或注释掉此行以继续。"
#endif

//
// 警告用户可能的终点/DIAG引脚冲突，以防止在不使用传感器归位时出现归位问题
//
#if !USE_SENSORLESS
  #if ENABLED(USES_DIAG_JUMPERS) && DISABLED(DIAG_JUMPERS_REMOVED)
    #warning "当SENSORLESS_HOMING被禁用时，必须移除主板上的DIAG跳线。（定义DIAG_JUMPERS_REMOVED以忽略此警告。）"
  #elif ENABLED(USES_DIAG_PINS) && DISABLED(DIAG_PINS_REMOVED)
    #warning "除非启用SENSORLESS_HOMING，否则必须物理上移除驱动器上的DIAG引脚。（请参阅https://bit.ly/2ZPRlt0）（定义DIAG_PINS_REMOVED以忽略此警告。）"
  #endif
#endif

#if ENABLED(QUICK_HOME) && (X_SPI_SENSORLESS || Y_SPI_SENSORLESS)
  #warning "使用QUICK_HOME可能导致SPI_ENDSTOPS不可靠。调整后退以获得更好的结果。"
#endif

#if CANNOT_EMBED_CONFIGURATION
  #warning "禁用CONFIGURATION_EMBEDDING，因为目标通常具有较少的闪存存储空间。定义FORCE_CONFIG_EMBED来覆盖。"
#endif

#if HAS_LCD_CONTRAST && LCD_CONTRAST_MIN >= LCD_CONTRAST_MAX
  #warning "当LCD_CONTRAST_MIN >= LCD_CONTRAST_MAX时无法更改对比度。"
#endif

#if PROGRESS_MSG_EXPIRE > 0 && HAS_STATUS_MESSAGE_TIMEOUT
  #warning "建议不要将PROGRESS_MSG_EXPIRE与STATUS_MESSAGE_TIMEOUT_SEC结合使用。"
#endif

/**
 * FYSETC/MKS/BTT Mini Panel 背光
 */
#if ANY(FYSETC_242_OLED_12864, FYSETC_MINI_12864_2_1) && !ALL(NEOPIXEL_LED, LED_CONTROL_MENU, LED_USER_PRESET_STARTUP, LED_COLOR_PRESETS)
  #warning "您的FYSETC/MKS/BTT Mini Panel最好与NEOPIXEL_LED、LED_CONTROL_MENU、LED_USER_PRESET_STARTUP和LED_COLOR_PRESETS一起使用。"
#endif

#if ANY(FYSETC_MINI_12864_1_2, FYSETC_MINI_12864_2_0) && DISABLED(RGB_LED)
  #warning "您的FYSETC Mini Panel最好与RGB_LED一起使用。"
#elif ANY(FYSETC_MINI_12864_2_0, FYSETC_MINI_12864_2_1) && DISABLED(LED_USER_PRESET_STARTUP)
  #warning "您的FYSETC Mini Panel最好与LED_USER_PRESET_STARTUP一起使用。"
#endif

#if ANY(FYSETC_242_OLED_12864, FYSETC_MINI_12864) && ALL(PSU_CONTROL, HAS_COLOR_LEDS) && !LED_POWEROFF_TIMEOUT
  #warning "您的FYSETC显示器与PSU_CONTROL一起使用时最好启用LED_POWEROFF_TIMEOUT。"
#endif

/**
 * Maple环境
 */
#ifdef __STM32F1__
  #warning "Maple构建环境已过时。请使用非Maple构建环境。将问题报告给Marlin Firmware项目。"
#endif

/**
 * Průša MK3/S/+风扇引脚重新分配
 */
#if MB(BTT_BTT002_V1_0, EINSY_RAMBO) && DISABLED(NO_MK3_FAN_PINS_WARNING)
  #warning "定义MK3_FAN_PINS来交换热端和零件冷却风扇引脚。（定义NO_MK3_FAN_PINS_WARNING来抑制此警告。）"
#endif

/**
 * GD32不完全与STM32相同
 */
#if MB(SOVOL_V131, TRIGORILLA_V006)
  #warning "基于GD32的控制器可能与STM32平台不完全兼容。请报告任何问题。"
#endif

/**
 * BD Sensor应始终包含BABYSTEPPING
 */
#if ENABLED(BD_SENSOR) && DISABLED(BABYSTEPPING)
  #warning "建议在BD_SENSOR中启用BABYSTEPPING。"
#endif

/**
 * EP Babystepping与EMERGENCY_PARSER最佳配合
 */
#if ENABLED(EP_BABYSTEPPING) && DISABLED(EMERGENCY_PARSER)
  #warning "建议在EP_BABYSTEPPING中启用EMERGENCY_PARSER。"
#endif

/**
 * POLAR警告
 */
#if ALL(POLAR, S_CURVE_ACCELERATION)
  #warning "POLAR运动学可能与S_CURVE_ACCELERATION不完全兼容。"
#endif

/**
 * 输入整形
 */
#if HAS_ZV_SHAPING && ANY(CORE_IS_XY, MARKFORGED_XY, MARKFORGED_YX)
  #warning "CORE / MARKFORGED运动学轴的输入整形仍处于实验阶段。"
#endif

/**
 * 自动多步限制
 */
#if MULTISTEPPING_LIMIT_WARNING
  #warning "MULTISTEPPING_LIMIT已自动设置为128。如果机器响应速度慢，请使用较低的值。"
#endif

/**
 * SD卡额外选项
 */
#if SDSORT_CACHE_VFATS_WARNING
  #warning "SDSORT_CACHE_VFATS已减少为VFAT_ENTRIES_LIMIT。"
#endif
#if SDSORT_CACHE_LPC1768_WARNING
  #warning "LPC1768上的SDCARD_SORT_ALPHA子选项被覆盖，因为与DOGM LCD SCK重叠。"
#endif

/**
 * Ender-5 S1引导程序
 */
#ifdef STM32F4_UPDATE_FOLDER
  #warning "将固件bin文件放在SD卡上名为“STM32F4_UPDATE”的文件夹中。使用“M936 V2”安装。"
#endif

/**
 * ProUI引导屏幕持续时间
 */
#if ENABLED(DWIN_LCD_PROUI) && BOOTSCREEN_TIMEOUT > 2000
  #warning "对于ProUI，建议使用原始的BOOTSCREEN_TIMEOUT 1100。"
#endif

/**
 * AD595最低电压
 */
#if HAL_ADC_VREF_MV < 5000 && ANY_THERMISTOR_IS(-1) && DISABLED(ALLOW_AD595_3V3_VREF)
  #warning "(-1) AD595热电偶放大器需要5V输入电源！使用AD8495进行3.3V ADC。"
#endif
