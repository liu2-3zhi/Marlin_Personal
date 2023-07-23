/**
 * Marlin 3D打印机固件
 * 版权所有 (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * 基于Sprinter和grbl。
 * 版权所有 (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * 本程序是自由软件：您可以在自由软件基金会发布的GNU通用公共许可证的条款下重新发布和/或修改它
 * 的版本3，或者（根据您的选择）任何后续版本。
 *
 * 本程序希望能有所帮助，但不提供任何形式的保证；即使没有明示的保证，也没有适销性或适用于特定目的的默示保证。
 * 有关更多详细信息，请参阅GNU通用公共许可证。
 *
 * 如果没有，您应该随附此程序的GNU通用公共许可证。
 * 如果没有，请参见<https://www.gnu.org/licenses/>。
 *
 */
#pragma once

//引入被抽离的关键参数
#include "key_configuration_parameters.h"

/**
 * Configuration.h
 *
 * 基本设置，例如：
 *
 * - 电子设备的类型
 * - 温度传感器的类型
 * - 打印机的几何结构
 * - 终点停止开关的配置
 * - LCD控制器
 * - 额外功能
 *
 * 高级设置可以在Configuration_adv.h中找到
 */
#define CONFIGURATION_H_VERSION 02010300

//===========================================================================
//============================= 入门指南 =============================
//===========================================================================

/**
 * 这里有一些有用的链接，可以帮助您配置和校准您的机器：
 *
 * 示例配置：https://github.com/MarlinFirmware/Configurations/branches/all
 *
 * Průša计算器：https://blog.prusa3d.com/calculator_3416/
 *
 * 校准指南：https://reprap.org/wiki/Calibration
 *          https://reprap.org/wiki/Triffid_Hunter%27s_Calibration_Guide
 *          https://web.archive.org/web/20220907014303/https://sites.google.com/site/repraplogphase/calibration-of-your-reprap
 *          https://youtu.be/wAL9d7FgInk
 *          https://teachingtechyt.github.io/calibration.html
 *
 * 校准物件：https://www.thingiverse.com/thing:5573
 *          https://www.thingiverse.com/thing:1278865
 */

// @section info

// 此构建的作者信息，在启动和M115期间打印到主机
#define STRING_CONFIG_H_AUTHOR "Zelly, MkS Robin E3D" // 谁做出了这些更改。
#define CUSTOM_VERSION_FILE Version.h // 从根目录开始的路径（不带引号）

// @section machine

// 选择与您的设置匹配的boards.h中的名称
#ifndef MOTHERBOARD
  #define MOTHERBOARD BOARD_MKS_ROBIN_E3D
#endif

/**
 * 选择用于与主机通信的板上串口。
 * 这允许将无线适配器（例如）连接到非默认端口引脚。
 * -1表示USB模拟串口（如果可用）。
 * 注意：第一个串口（-1或0）始终由Arduino引导加载程序使用。
 *
 * :[-1, 0, 1, 2, 3, 4, 5, 6, 7]
 */
#define SERIAL_PORT 1

/**
 * 串口波特率
 * 这是所有串口的默认通信速度。
 * 在下面设置其他串口的波特率默认值。
 *
 * 大多数情况下，250000 是有效的，但如果您经常在主机打印过程中遇到中断，可以尝试较低的速度。
 * 如果要加快SD文件传输速度，可以尝试高达1000000。
 * 
 *
 * :[2400, 9600, 19200, 38400, 57600, 115200, 250000, 500000, 1000000]
 */
#define BAUDRATE 115200

#define BAUD_RATE_GCODE     // 启用G-code M575以设置波特率

/**
 * 选择用于与主机通信的板上的第二个串口。
 * 目前，仅支持Teensy 4.1板的以太网（-2）。
 * :[-2, -1, 0, 1, 2, 3, 4, 5, 6, 7]
 */
//#define SERIAL_PORT_2 -1
//#define BAUDRATE_2 250000   // :[2400, 9600, 19200, 38400, 57600, 115200, 250000, 500000, 1000000] 启用以覆盖BAUDRATE

/**
 * 选择用于与主机通信的板上的第三个串口。
 * 仅支持AVR、DUE、LPC1768/9和STM32/STM32F1。
 * :[-1, 0, 1, 2, 3, 4, 5, 6, 7]
 */
//#define SERIAL_PORT_3 1
//#define BAUDRATE_3 250000   // :[2400, 9600, 19200, 38400, 57600, 115200, 250000, 500000, 1000000] 启用以覆盖BAUDRATE

/**
 * 选择用于与RS485协议通信的串口
 * :[-1, 0, 1, 2, 3, 4, 5, 6, 7]
 */
//#define RS485_SERIAL_PORT 1
#ifdef RS485_SERIAL_PORT
  //#define RS485_BUS_BUFFER_SIZE 128
#endif

// 在AT90USB设备上启用蓝牙串口接口
//#define BLUETOOTH

// 在LCD“Ready”消息和Info菜单中显示的名称
#define CUSTOM_MACHINE_NAME "MKS Robin E3D"

// 打印机的唯一ID，用于区分不同的机器。
// 可以选择您自己的ID，或使用类似 https://www.uuidgenerator.net/version4 的服务。
#define MACHINE_UUID "56a91fea-7beb-40dd-aed9-50fd417f1c26"

// @section stepper drivers

/**
 * 步进驱动器
 *
 * 这些设置允许Marlin调整步进驱动器的定时和启用支持高级选项的步进驱动器。
 * 您还可以在Configuration_adv.h中覆盖定时选项。
 *
 * 对于TMC2225驱动器，请使用TMC2208/TMC2208_STANDALONE。
 * 对于TMC2226驱动器，请使用TMC2209/TMC2209_STANDALONE。
 *
 * 选项：A4988, A5984, DRV8825, LV8729, TB6560, TB6600, TMC2100,
 *          TMC2130, TMC2130_STANDALONE, TMC2160, TMC2160_STANDALONE,
 *          TMC2208, TMC2208_STANDALONE, TMC2209, TMC2209_STANDALONE,
 *          TMC26X,  TMC26X_STANDALONE,  TMC2660, TMC2660_STANDALONE,
 *          TMC5130, TMC5130_STANDALONE, TMC5160, TMC5160_STANDALONE
 * :['A4988', 'A5984', 'DRV8825', 'LV8729', 'TB6560', 'TB6600', 'TMC2100', 'TMC2130', 'TMC2130_STANDALONE', 'TMC2160', 'TMC2160_STANDALONE', 'TMC2208', 'TMC2208_STANDALONE', 'TMC2209', 'TMC2209_STANDALONE', 'TMC26X', 'TMC26X_STANDALONE', 'TMC2660', 'TMC2660_STANDALONE', 'TMC5130', 'TMC5130_STANDALONE', 'TMC5160', 'TMC5160_STANDALONE']
 */
#define X_DRIVER_TYPE  A4988
#define Y_DRIVER_TYPE  A4988
#define Z_DRIVER_TYPE  A4988
//#define X2_DRIVER_TYPE A4988
//#define Y2_DRIVER_TYPE A4988
//#define Z2_DRIVER_TYPE A4988
//#define Z3_DRIVER_TYPE A4988
//#define Z4_DRIVER_TYPE A4988
//#define I_DRIVER_TYPE  A4988
//#define J_DRIVER_TYPE  A4988
//#define K_DRIVER_TYPE  A4988
//#define U_DRIVER_TYPE  A4988
//#define V_DRIVER_TYPE  A4988
//#define W_DRIVER_TYPE  A4988
#define E0_DRIVER_TYPE A4988
//#define E1_DRIVER_TYPE A4988
//#define E2_DRIVER_TYPE A4988
//#define E3_DRIVER_TYPE A4988
//#define E4_DRIVER_TYPE A4988
//#define E5_DRIVER_TYPE A4988
//#define E6_DRIVER_TYPE A4988
//#define E7_DRIVER_TYPE A4988
//采用key_configuration_parameters.h的定义优先覆盖
#if defined(X_DRIVER_TYPE_KEY) && defined(Y_DRIVER_TYPE_KEY) && defined(Z_DRIVER_TYPE_KEY) && defined(E0_DRIVER_TYPE_KEY)
  #undef X_DRIVER_TYPE
  #define X_DRIVER_TYPE X_DRIVER_TYPE_KEY

  #undef Y_DRIVER_TYPE
  #define Y_DRIVER_TYPE Y_DRIVER_TYPE_KEY

  #undef Z_DRIVER_TYPE
  #define Z_DRIVER_TYPE Z_DRIVER_TYPE_KEY

  #undef E0_DRIVER_TYPE
  #define E0_DRIVER_TYPE E0_DRIVER_TYPE_KEY
#elif !defined(X_DRIVER_TYPE_KEY) && !defined(Y_DRIVER_TYPE_KEY) && !defined(Z_DRIVER_TYPE_KEY) && !defined(E0_DRIVER_TYPE_KEY)
  // 什么也不做
#else
  #error "请检查驱动类型是否全部定义。X_DRIVER_TYPE_KEY, Y_DRIVER_TYPE_KEY, Z_DRIVER_TYPE_KEY, E0_DRIVER_TYPE_KEY 都需要同时被定义或者同时不被定义。"
#endif


/**
 * 附加轴设置
 *
 * 为所有旋转或枢轴轴定义AXISn_ROTATES。
 * 旋转轴坐标以度为单位。
 *
 * AXISn_NAME定义在（大多数）G-code命令中用于引用轴的字母。
 * 按照惯例，名称和角色通常是：
 *   'A'：平行于X的旋转轴
 *   'B'：平行于Y的旋转轴
 *   'C'：平行于Z的旋转轴
 *   'U'：平行于X的辅助线性轴
 *   'V'：平行于Y的辅助线性轴
 *   'W'：平行于Z的辅助线性轴
 *
 * 无论这些设置如何，轴在内部都以I、J、K、U、V、W命名。
 */
#ifdef I_DRIVER_TYPE
  #define AXIS4_NAME 'A' // :['A', 'B', 'C', 'U', 'V', 'W']
  #define AXIS4_ROTATES
#endif
#ifdef J_DRIVER_TYPE
  #define AXIS5_NAME 'B' // :['B', 'C', 'U', 'V', 'W']
  #define AXIS5_ROTATES
#endif
#ifdef K_DRIVER_TYPE
  #define AXIS6_NAME 'C' // :['C', 'U', 'V', 'W']
  #define AXIS6_ROTATES
#endif
#ifdef U_DRIVER_TYPE
  #define AXIS7_NAME 'U' // :['U', 'V', 'W']
  //#define AXIS7_ROTATES
#endif
#ifdef V_DRIVER_TYPE
  #define AXIS8_NAME 'V' // :['V', 'W']
  //#define AXIS8_ROTATES
#endif
#ifdef W_DRIVER_TYPE
  #define AXIS9_NAME 'W' // :['W']
  //#define AXIS9_ROTATES
#endif

// @section extruder

// 这定义了挤出机的数量
// :[0, 1, 2, 3, 4, 5, 6, 7, 8]
#define EXTRUDERS 1

// 一般预期的丝材直径（1.75、2.85、3.0等）。用于体积计算、丝材宽度传感器等。
#define DEFAULT_NOMINAL_FILAMENT_DIA 1.75

// 用于Cyclops或任何共享单个喷嘴的“多挤出机”。
//#define SINGLENOZZLE

// 在工具更改时保存和恢复温度和风扇速度。
// 使用M104/106/109 T ...设置未选择的工具的待机温度。
#if ENABLED(SINGLENOZZLE)
  //#define SINGLENOZZLE_STANDBY_TEMP
  //#define SINGLENOZZLE_STANDBY_FAN
#endif

// 使用单个步进电机的双挤出机
//#define SWITCHING_EXTRUDER
#if ENABLED(SWITCHING_EXTRUDER)
  #define SWITCHING_EXTRUDER_SERVO_NR 0
  #define SWITCHING_EXTRUDER_SERVO_ANGLES { 0, 90 } // E0、E1的角度[, E2、E3]
  #if EXTRUDERS > 3
    #define SWITCHING_EXTRUDER_E23_SERVO_NR 1
  #endif
#endif

// 通过碰撞工具头切换挤出机。需要EVENT_GCODE_TOOLCHANGE_#。
//#define MECHANICAL_SWITCHING_EXTRUDER

/**
 * 使用伺服电机抬升/降低一个（或两个）喷嘴的双喷嘴。
 * 可与SWITCHING_EXTRUDER组合使用。
 */
//#define SWITCHING_NOZZLE
#if ENABLED(SWITCHING_NOZZLE)
  #define SWITCHING_NOZZLE_SERVO_NR 0
  //#define SWITCHING_NOZZLE_E1_SERVO_NR 1          // 如果使用两个舵机，则为第二个的索引
  #define SWITCHING_NOZZLE_SERVO_ANGLES { 0, 90 }   // E0、E1（单个舵机）或降下/抬起（双舵机）的角度
  #define SWITCHING_NOZZLE_SERVO_DWELL 2500         // 等待舵机进行物理移动的时间
#endif

// 通过碰撞工具头切换喷嘴。需要EVENT_GCODE_TOOLCHANGE_#。
//#define MECHANICAL_SWITCHING_NOZZLE

/**
 * 使用电磁阀停靠机制连接到移动部件的两个单独的X支架和挤出机。
 * 需要SOL1_PIN和SOL2_PIN。
 */
//#define PARKING_EXTRUDER

/**
 * 两个独立的带有挤出机的X型车床，通过使用运动和无线圈电磁铁连接到移动部件的磁性停车机制
 * 
 *
 * 项目链接   : https://www.thingiverse.com/thing:3080893
 * 运动视频链接 : https://youtu.be/0xCEiG9VS3k
 *              https://youtu.be/Bqbcs0CU2FE
 */
//#define MAGNETIC_PARKING_EXTRUDER

#if ANY(PARKING_EXTRUDER, MAGNETIC_PARKING_EXTRUDER)

  #define PARKING_EXTRUDER_PARKING_X { -78, 184 }     // 停放挤出机时的X位置
  #define PARKING_EXTRUDER_GRAB_DISTANCE 1            // （毫米）超出停放点移动的距离以抓取挤出机

  #if ENABLED(PARKING_EXTRUDER)

    #define PARKING_EXTRUDER_SOLENOIDS_INVERT           // 如果启用，则不会在施加电压时磁化电磁阀
    #define PARKING_EXTRUDER_SOLENOIDS_PINS_ACTIVE LOW  // 'LOW'或'HIGH'的引脚信号通电
    #define PARKING_EXTRUDER_SOLENOIDS_DELAY 250        // （毫秒）磁场的延迟时间，如果为0或未定义，则不延迟。
    //#define MANUAL_SOLENOID_CONTROL                   // 使用M380 S / M381手动控制对接电磁阀

  #elif ENABLED(MAGNETIC_PARKING_EXTRUDER)

    #define MPE_FAST_SPEED      9000      // （毫米/分钟）最后一个距离点之前的移动速度
    #define MPE_SLOW_SPEED      4500      // （毫米/分钟）最后一个距离移动到停放和耦合的速度
    #define MPE_TRAVEL_DISTANCE   10      // （毫米）最后一个距离点
    #define MPE_COMPENSATION       0      // 偏移补偿-1、0、1（倍数）仅用于耦合

  #endif

#endif

/**
 * 切换工具头
 *
 * 支持可互换和可对接的工具头，例如
 * E3D工具切换器。工具头使用舵机锁定。
 */
//#define SWITCHING_TOOLHEAD

/**
 * 磁性换接工具头
 *
 * 支持可更换和可连接的工具头，使用运动和无伺服机构的磁性连接机制。
 */
//#define MAGNETIC_SWITCHING_TOOLHEAD

/**
 * 电磁切换工具头
 *
 * 用于CoreXY/HBot运动学的停车。
 * 工具头在一侧停放并用电磁铁固定。
 * 支持多于2个工具头。请参阅https://youtu.be/JolbsAKTKf4
 */
//#define ELECTROMAGNETIC_SWITCHING_TOOLHEAD

#if ANY(SWITCHING_TOOLHEAD, MAGNETIC_SWITCHING_TOOLHEAD, ELECTROMAGNETIC_SWITCHING_TOOLHEAD)
  #define SWITCHING_TOOLHEAD_Y_POS          235         // （毫米）工具头对接的Y位置
  #define SWITCHING_TOOLHEAD_Y_SECURITY      10         // （毫米）Y轴的安全距离
  #define SWITCHING_TOOLHEAD_Y_CLEAR         60         // （毫米）与对接点的最小X轴无障碍距离
  #define SWITCHING_TOOLHEAD_X_POS          { 215, 0 }  // （毫米）停放挤出机时的X位置
  #if ENABLED(SWITCHING_TOOLHEAD)
    #define SWITCHING_TOOLHEAD_SERVO_NR       2         // 舵机连接器的索引
    #define SWITCHING_TOOLHEAD_SERVO_ANGLES { 0, 180 }  // （度）锁定、解锁的角度
  #elif ENABLED(MAGNETIC_SWITCHING_TOOLHEAD)
    #define SWITCHING_TOOLHEAD_Y_RELEASE      5         // （毫米）Y轴的安全距离
    #define SWITCHING_TOOLHEAD_X_SECURITY   { 90, 150 } // （毫米）X轴的安全距离（T0、T1）
    //#define PRIME_BEFORE_REMOVE                       // 在从对接台上释放之前进行挤出
    #if ENABLED(PRIME_BEFORE_REMOVE)
      #define SWITCHING_TOOLHEAD_PRIME_MM           20  // （毫米）挤出器挤出长度
      #define SWITCHING_TOOLHEAD_RETRACT_MM         10  // （毫米）挤出后回缩长度
      #define SWITCHING_TOOLHEAD_PRIME_FEEDRATE    300  // （毫米/分钟）挤出器挤出进给速度
      #define SWITCHING_TOOLHEAD_RETRACT_FEEDRATE 2400  // （毫米/分钟）挤出器回缩进给速度
    #endif
  #elif ENABLED(ELECTROMAGNETIC_SWITCHING_TOOLHEAD)
    #define SWITCHING_TOOLHEAD_Z_HOP          2         // （毫米）切换时的Z抬升
  #endif
#endif

/**
 * "混合挤出机"
 *   - 添加G-code M163和M164以设置和“提交”当前混合因子。
 *   - 扩展步进例程以按比例移动多个步进器。
 *   - Repetier Firmware的'M164 S<index>'支持虚拟工具。
 *   - 此实现支持最多两个混合挤出机。
 *   - 启用DIRECT_MIXING_IN_G1以支持M165和G1中的混合（来自Pia Taubert的参考实现）。
 */
//#define MIXING_EXTRUDER
#if ENABLED(MIXING_EXTRUDER)
  #define MIXING_STEPPERS 2        // 混合挤出机中的步进器数量
  #define MIXING_VIRTUAL_TOOLS 16  // 使用M163和M164的虚拟工具方法
  //#define DIRECT_MIXING_IN_G1    // 允许G1运动命令中的ABCDHI混合因子
  //#define GRADIENT_MIX           // 支持M166和LCD的渐变混合
  //#define MIXING_PRESETS         // 为2个或3个MIXING_STEPPERS分配8个默认V-tool预设值
  #if ENABLED(GRADIENT_MIX)
    //#define GRADIENT_VTOOL       // 添加M166 T以使用V-tool索引作为渐变别名
  #endif
#endif

// 挤出机的偏移量（如果使用多个并依赖于固件来在更换时定位），取消注释。
// 偏移量对于喷嘴0（默认挤出机）必须为X = 0、Y = 0。
// 对于其他喷嘴，它是它们到喷嘴0（默认挤出机）的距离。
//#define HOTEND_OFFSET_X { 0.0, 20.00 } // 每个喷嘴的相对X偏移（毫米）
//#define HOTEND_OFFSET_Y { 0.0, 5.00 }  // 每个喷嘴的相对Y偏移（毫米）
//#define HOTEND_OFFSET_Z { 0.0, 0.00 }  // 每个喷嘴的相对Z偏移（毫米）

// @section multi-material

/**
 * 多材料单元
 * 设置为以下预定义模型之一：
 *
 *   PRUSA_MMU1           : Průša MMU1（“复用器”版本）
 *   PRUSA_MMU2           : Průša MMU2
 *   PRUSA_MMU2S          : Průša MMU2S（需要带运动传感器的MK3S挤出机，EXTRUDERS = 5）
 *   EXTENDABLE_EMU_MMU2  : 具有可配置丝材数量的MMU（具有与Průša MMU2兼容的ERCF、SMuFF或类似固件）
 *   EXTENDABLE_EMU_MMU2S : 具有可配置丝材数量的MMUS（具有与Průša MMU2兼容的ERCF、SMuFF或类似固件）
 *
 * 需要NOZZLE_PARK_FEATURE在MMU单元故障时停放打印头。
 * 请参阅Configuration_adv.h中的其他选项。
 * :["PRUSA_MMU1", "PRUSA_MMU2", "PRUSA_MMU2S", "EXTENDABLE_EMU_MMU2", "EXTENDABLE_EMU_MMU2S"]
 */
//#define MMU_MODEL PRUSA_MMU2

// @section psu control

/**
 * 电源控制
 *
 * 启用并通过PS_ON_PIN连接电源。
 * 指定电源是否为高电平活动或低电平活动。
 */
#define PSU_CONTROL
#define PSU_NAME "CSPS电源"

#if ENABLED(PSU_CONTROL)
  //#define MKS_PWC                 // 使用MKS PWC附加组件
  //#define PS_OFF_CONFIRM          // 关闭电源时确认对话框
  #define PS_OFF_SOUND            // 关闭电源时蜂鸣1秒钟
  #define PSU_ACTIVE_STATE HIGH      // 设置ATX为'LOW'，X-Box为'HIGH'

  //#define PSU_DEFAULT_OFF               // 保持关闭状态，直到使用M80直接启用
  //#define PSU_POWERUP_DELAY      250    // （毫秒）电源升温到全功率的延迟
  //#define LED_POWEROFF_TIMEOUT 10000    // （毫秒）关电源后关闭LED，具有这个延迟的时间

  //#define POWER_OFF_TIMER               // 启用M81 D<seconds>以在延迟后关闭电源
  //#define POWER_OFF_WAIT_FOR_COOLDOWN   // 仅在冷却后才启用M81 S以关闭电源

  //#define PSU_POWERUP_GCODE  "M355 S1"  // 上电后运行的G-code（例如，打开箱灯）
  //#define PSU_POWEROFF_GCODE "M355 S0"  // 关电源前运行的G-code（例如，关闭箱灯）
  //设置消NEOPIXEL灯带PIN为电源PIN
  #define PS_ON_PIN NEOPIXEL_PIN
  //取消NEOPIXEL灯带PIN
  #undef NEOPIXEL_PIN

  //#define AUTO_POWER_CONTROL      // 启用PS_ON引脚的自动控制
  #if ENABLED(AUTO_POWER_CONTROL)
    #define AUTO_POWER_FANS         // 如果风扇需要电源，打开电源
    #define AUTO_POWER_E_FANS
    #define AUTO_POWER_CONTROLLERFAN
    #define AUTO_POWER_CHAMBER_FAN
    #define AUTO_POWER_COOLER_FAN
    #define POWER_TIMEOUT              30 // （秒）如果机器闲置此时间，关闭电源
    //#define POWER_OFF_DELAY          60 // （秒）M81命令后的关闭电源延迟。有用于让风扇运行更长的时间。
  #endif
  #if ANY(AUTO_POWER_CONTROL, POWER_OFF_WAIT_FOR_COOLDOWN)
    //#define AUTO_POWER_E_TEMP        50 // （°C）如果任何挤出器超过此温度，打开电源
    //#define AUTO_POWER_CHAMBER_TEMP  30 // （°C）如果腔体超过此温度，打开电源
    //#define AUTO_POWER_COOLER_TEMP   26 // （°C）如果冷却器超过此温度，打开电源
  #endif
#endif

//===========================================================================
//============================= 热力设置 ============================
//===========================================================================
// @section 温度

/**
 * 温度传感器:
 *
 * 正常情况下使用4.7kΩ上拉电阻！热端传感器可以使用1kΩ上拉电阻，并配合正确的电阻和表格。
 *
 * ================================================================
 *  模拟热敏电阻 - 4.7kΩ 上拉电阻 - 正常
 * ================================================================
 *     1 : 100kΩ EPCOS - EPCOS热敏电阻的最佳选择
 *   331 : 100kΩ 和#1相同，但为MEGA缩放到3.3V
 *   332 : 100kΩ 和#1相同，但为DUE缩放到3.3V
 *     2 : 200kΩ ATC Semitec 204GT-2
 *   202 : 200kΩ Copymaster 3D
 *     3 : ???Ω  Mendel-parts热敏电阻
 *     4 : 10kΩ  通用热敏电阻！！不要用于热端 - 在高温下精度较差！！
 *     5 : 100kΩ ATC Semitec 104GT-2/104NT-4-R025H42G - 用于ParCan、J-Head和E3D，SliceEngineering 300°C
 *   501 : 100kΩ Zonestar - Tronxy X3A
 *   502 : 100kΩ Zonestar - 用于Zonestar Průša P802M的加热床
 *   503 : 100kΩ Zonestar (Z8XM2) 加热床热敏电阻
 *   504 : 100kΩ Zonestar P802QR2 (Part# QWG-104F-B3950) 热端热敏电阻
 *   505 : 100kΩ Zonestar P802QR2 (Part# QWG-104F-3950) 加热床热敏电阻
 *   512 : 100kΩ RPW-Ultra 热端
 *     6 : 100kΩ EPCOS - 不如表格#1精确（使用fluke热电偶创建）
 *     7 : 100kΩ Honeywell 135-104LAG-J01
 *    71 : 100kΩ Honeywell 135-104LAF-J01
 *     8 : 100kΩ Vishay 0603 SMD NTCS0603E3104FXT
 *     9 : 100kΩ GE Sensing AL03006-58.2K-97-G1
 *    10 : 100kΩ RS PRO 198-961
 *    11 : 100kΩ Keenovo AC硅胶垫，大多数Wanhao i3机器 - beta 3950, 1%
 *    12 : 100kΩ Vishay 0603 SMD NTCS0603E3104FXT (#8) - 用于Makibox加热床校准
 *    13 : 100kΩ Hisens最高到300°C - 用于“Simple ONE”和“All In ONE”热端 - beta 3950, 1%
 *    14 : 100kΩ  (R25), 4092K (beta25), 4.7kΩ上拉, 加热床热敏电阻 - 用于Ender-5 S1
 *    15 : 100kΩ 校准用于JGAurora A5热端
 *    18 : 200kΩ ATC Semitec 204GT-2 Dagoma.Fr - MKS_Base_DKU001327
 *    22 : 100kΩ GTM32 Pro vB - 热端 - 4.7kΩ上拉到3.3V和220Ω到模拟输入
 *    23 : 100kΩ GTM32 Pro vB - 加热床 - 4.7kΩ上拉到3.3v和220Ω到模拟输入
 *    30 : 100kΩ Kis3d 硅胶加热垫 200W/300W，带有6mm精密铸造板（EN AW 5083）NTC100K - beta 3950
 *    60 : 100kΩ Maker's Tool Works Kapton加热床热敏电阻 - beta 3950
 *    61 : 100kΩ Formbot/Vivedino 350°C热敏电阻 - beta 3950
 *    66 : 4.7MΩ Dyze Design / Trianglelab T-D500 500°C高温热敏电阻
 *    67 : 500kΩ SliceEngineering 450°C热敏电阻
 *    68 : PT100 Dyze Design的放大板
 *    70 : 100kΩ bq Hephestos 2
 *    75 : 100kΩ 带有NTC100K MGB18-104F39050L32的通用硅胶加热垫
 *  2000 : 100kΩ Ultimachine Rambo TDK NTCG104LH104KT1 NTC100K主板热敏电阻
 *
 * ================================================================
 *  模拟热敏电阻 - 1kΩ 上拉电阻
 *   非典型情况，需要将4.7kΩ上拉电阻更换为1kΩ。
 *   （但可以提供更高的精度和更稳定的PID）
 * ================================================================
 *    51 : 100kΩ EPCOS (1kΩ上拉)
 *    52 : 200kΩ ATC Semitec 204GT-2 (1kΩ上拉)
 *    55 : 100kΩ ATC Semitec 104GT-2 - 用于ParCan和J-Head (1kΩ上拉)
 *
 * ================================================================
 *  模拟热敏电阻 - 10kΩ 上拉电阻 - 非典型
 * ================================================================
 *    99 : 100kΩ 某些Wanhao i3机器上使用的10kΩ上拉电阻
 *
 * ================================================================
 *  模拟 RTD（Pt100/Pt1000）
 * ================================================================
 *   110 : Pt100 与 1kΩ 上拉电阻（非典型）
 *   147 : Pt100 与 4.7kΩ 上拉电阻
 *  1010 : Pt1000 与 1kΩ 上拉电阻（非典型）
 *  1022 : Pt1000 与 2.2kΩ 上拉电阻
 *  1047 : Pt1000 与 4.7kΩ 上拉电阻（E3D）
 *    20 : Pt100 与 Ultimainboard V2.x 上的电路，主板 ADC 参考电压 = INA826 放大板供电电压。
 *                注意：（1）必须使用没有上拉的 ADC 输入。（2）某些 INA826 放大器在 3.3V 下不可靠，因此考虑使用传感器 147、110 或 21。
 *    21 : Pt100 与 Ultimainboard V2.x 上的电路，3.3V ADC 参考电压（STM32、LPC176x....）和 5V INA826 放大板供电。
 *                注意：ADC 引脚不耐受 5V。不建议使用，因为超过 500°C 可能会损坏 CPU。
 *   201 : Pt100 与 Overlord 上的电路，类似于 Ultimainboard V2.x
 *
 * ================================================================
 *  SPI RTD/热电偶板
 * ================================================================
 *    -5 : MAX31865，带有 Pt100/Pt1000，2、3 或 4 线  (仅适用于传感器 0-1)
 *                  注意：您必须取消注释/设置下面的 MAX31865_*_OHMS_n 定义。
 *    -3 : MAX31855，带有热电偶，-200°C 至 +700°C（仅适用于传感器 0-1）
 *    -2 : MAX6675，带有热电偶，0°C 至 +700°C    （仅适用于传感器 0-1）
 *
 *  注意：请在您的 pins 文件中为每个使用 SPI 热电偶的 TEMP_SENSOR_n 设置 TEMP_n_CS_PIN。
 *        默认情况下，使用默认串行总线上的硬件 SPI。如果您还设置了 TEMP_n_SCK_PIN 和 TEMP_n_MISO_PIN，
 *        则将在这些端口上使用软件 SPI。您可以在 Configuration_adv.h 文件中强制使用默认总线上的硬件 SPI。
 *        目前，不支持传感器的独立硬件 SPI 总线。
 *
 * ================================================================ 
 *  模拟热电偶模块
 * ================================================================
 *    -4 : AD8495与热电偶
 *    -1 : AD595与热电偶
 *
 * ================================================================
 *  SoC内部传感器
 * ================================================================
 *   100 : SoC内部传感器
 *
 * ================================================================
 *  自定义/虚拟/其他热敏传感器
 * ================================================================
 *     0 : 未使用
 *  1000 : 自定义 - 在Configuration_adv.h中指定参数
 *
 *   !!! 仅用于测试或开发目的。绝不用于生产机器。 !!!
 *   998 : 虚拟表格，始终读取25°C或下面定义的温度。
 *   999 : 虚拟表格，始终读取100°C或下面定义的温度。
 */
#define TEMP_SENSOR_0 1
#define TEMP_SENSOR_1 0
#define TEMP_SENSOR_2 0
#define TEMP_SENSOR_3 0
#define TEMP_SENSOR_4 0
#define TEMP_SENSOR_5 0
#define TEMP_SENSOR_6 0
#define TEMP_SENSOR_7 0
#define TEMP_SENSOR_BED 1
#define TEMP_SENSOR_PROBE 0
#define TEMP_SENSOR_CHAMBER 0
#define TEMP_SENSOR_COOLER 0
#define TEMP_SENSOR_BOARD 0
#define TEMP_SENSOR_SOC 0
#define TEMP_SENSOR_REDUNDANT 0

// 虚拟热敏电阻的恒定温度读数，用于998和999
#define DUMMY_THERMISTOR_998_VALUE  25
#define DUMMY_THERMISTOR_999_VALUE 100

// 使用MAX31865传感器（-5）时的电阻值（对于TEMP_SENSOR_0 / 1）
#if TEMP_SENSOR_IS_MAX_TC(0)
  #define MAX31865_SENSOR_OHMS_0      100 // (Ω) 通常为100或1000（PT100或PT1000）
  #define MAX31865_CALIBRATION_OHMS_0 430 // (Ω) 通常为Adafruit PT100的430; Adafruit PT1000的4300
#endif
#if TEMP_SENSOR_IS_MAX_TC(1)
  #define MAX31865_SENSOR_OHMS_1      100
  #define MAX31865_CALIBRATION_OHMS_1 430
#endif
#if TEMP_SENSOR_IS_MAX_TC(2)
  #define MAX31865_SENSOR_OHMS_2      100
  #define MAX31865_CALIBRATION_OHMS_2 430
#endif

#if HAS_E_TEMP_SENSOR
  #define TEMP_RESIDENCY_TIME         10  // (秒) M109中等待热端“稳定”的时间
  #define TEMP_WINDOW                  1  // (°C) “温度达到”计时器的温度接近度
  #define TEMP_HYSTERESIS              3  // (°C) 温度接近目标时被视为“足够接近”
#endif

#if TEMP_SENSOR_BED
  #define TEMP_BED_RESIDENCY_TIME     10  // (秒) M190中等待加热床“稳定”的时间
  #define TEMP_BED_WINDOW              1  // (°C) “温度达到”计时器的温度接近度
  #define TEMP_BED_HYSTERESIS          3  // (°C) 温度接近目标时被视为“足够接近”
#endif

#if TEMP_SENSOR_CHAMBER
  #define TEMP_CHAMBER_RESIDENCY_TIME 10  // (秒) M191中等待加热室“稳定”的时间
  #define TEMP_CHAMBER_WINDOW          1  // (°C) “温度达到”计时器的温度接近度
  #define TEMP_CHAMBER_HYSTERESIS      3  // (°C) 温度接近目标时被视为“足够接近”
#endif

/**
 * 冗余温度传感器（TEMP_SENSOR_REDUNDANT）
 *
 * 使用一个温度传感器作为另一个读数的冗余传感器。选择一个未使用的温度传感器，
 * 并选择您要为其提供冗余读数的另一个传感器。如果两个热敏电阻的温度差异大于TEMP_SENSOR_REDUNDANT_MAX_DIFF（°C），
 * 则打印作业将被中止。选择的传感器将禁用其正常功能；即选择加热床传感器（-1）将禁用加热床加热/监控功能。
 *
 * 
 * 用于选择源/目标的选项：COOLER, PROBE, BOARD, CHAMBER, BED, E0, E1, E2, E3, E4, E5, E6, E7
 */
#if TEMP_SENSOR_REDUNDANT
  #define TEMP_SENSOR_REDUNDANT_SOURCE    E1  // 提供冗余读数的传感器。
  #define TEMP_SENSOR_REDUNDANT_TARGET    E0  // 我们为其提供冗余读数的传感器。
  #define TEMP_SENSOR_REDUNDANT_MAX_DIFF  10  // (°C) 触发打印作业中止的温度差异。
#endif

// 低于此温度，加热器将关闭，
// 因为这可能表示热敏电阻线断开。
#define HEATER_0_MINTEMP   5
#define HEATER_1_MINTEMP   5
#define HEATER_2_MINTEMP   5
#define HEATER_3_MINTEMP   5
#define HEATER_4_MINTEMP   5
#define HEATER_5_MINTEMP   5
#define HEATER_6_MINTEMP   5
#define HEATER_7_MINTEMP   5
#define BED_MINTEMP        5
#define CHAMBER_MINTEMP    5

// 高于此温度，加热器将关闭。
// 这可以保护组件免受过热，但无法防止短路和故障。
// （使用MINTEMP进行热敏电阻短路/故障保护。）
#define HEATER_0_MAXTEMP 275
#define HEATER_1_MAXTEMP 275
#define HEATER_2_MAXTEMP 275
#define HEATER_3_MAXTEMP 275
#define HEATER_4_MAXTEMP 275
#define HEATER_5_MAXTEMP 275
#define HEATER_6_MAXTEMP 275
#define HEATER_7_MAXTEMP 275
#define BED_MAXTEMP      125
#define CHAMBER_MAXTEMP  60

/**
 * 热力超调
 * 在加热（和打印）过程中，温度通常会“超调”目标温度多度
 * （特别是在PID调整之前）。将目标温度设置得太接近
 * MAXTEMP会导致MAXTEMP关闭！使用这些值禁止设置温度
 * 太接近MAXTEMP。
 */
#define HOTEND_OVERSHOOT 15   // (°C) 禁止超过MAXTEMP - OVERSHOOT的温度
#define BED_OVERSHOOT    10   // (°C) 禁止超过MAXTEMP - OVERSHOOT的温度
#define COOLER_OVERSHOOT  2   // (°C) 禁止小于OVERSHOOT的温度

//===========================================================================
//============================= PID设置 ======================================
//===========================================================================

// @section hotend temp

/**
 * 温度控制
 *
 * (NONE) : 开关控制加热
 * PIDTEMP : PID温度控制（约4.1K）
 * MPCTEMP : 预测模型温度控制（约1.8K，未进行自动调节）
 */
#define PIDTEMP           // 详细请参阅PID调整指南 https://reprap.org/wiki/PID_Tuning
//#define MPCTEMP         // **实验性的** 请参阅 https://marlinfw.org/docs/features/model_predictive_control.html

#define PID_MAX  255      // 在PID活动时限制热端电流（参见下面的PID_FUNCTIONAL_RANGE）；255=全电流
#define PID_K1     0.95   // 任何PID循环内的平滑系数

#if ENABLED(PIDTEMP)
  //#define PID_DEBUG             // 将PID调试数据打印到串口。使用'M303 D'切换激活。
  //#define PID_PARAMS_PER_HOTEND // 为每个挤出机使用单独的PID参数（用于不匹配的挤出机）
                                  // 使用G-code设置/获取：M301 E[挤出机编号，0-2]

  // Creality Ender-3
  #if ENABLED(PID_PARAMS_PER_HOTEND)
    // 根据您的设置，此处指定每个热端的值。
    // 如果值较少，则最后一个值适用于剩余的热端。
    #define DEFAULT_Kp_LIST {  21.73,  21.73 }
    #define DEFAULT_Ki_LIST {   1.54,   1.54 }
    #define DEFAULT_Kd_LIST {  76.55,  76.55 }
  #else
    #define DEFAULT_Kp  16.25
    #define DEFAULT_Ki   1.06
    #define DEFAULT_Kd  62.42

    //采用key_configuration_parameters.h的定义优先覆盖
#if defined(DEFAULT_Kp_Key) && defined(DEFAULT_Ki_Key) && defined(DEFAULT_Kd_Key)
  #undef DEFAULT_Kp
  #define DEFAULT_Kp DEFAULT_Kp_Key
  #undef DEFAULT_Ki
  #define DEFAULT_Ki DEFAULT_Ki_Key
  #undef DEFAULT_Kd
  #define DEFAULT_Kd DEFAULT_Kd_Key
#elif !defined(DEFAULT_Kp_Key) && !defined(DEFAULT_Ki_Key) && !defined(DEFAULT_Kd_Key)
  // 什么也不做
#else
  #error "请检查 DEFAULT_Kp_Key, DEFAULT_Ki_Key, DEFAULT_Kd_Key 是否同时被定义或同时不被定义。"
#endif


  #endif
#else
  #define BANG_MAX 255    // 在bang-bang模式下限制热端电流；255=全电流
#endif

/**
 * 热端的模型预测控制
 *
 * 使用热端的物理模型来控制温度。正确配置后，这比PID具有更好的响应性和稳定性，
 * 并消除了PID_EXTRUSION_SCALING和PID_FAN_SCALING的需要。启用MPC_AUTOTUNE并使用M306 T进行自动调整。
 * 
 * @section mpctemp
 */
#if ENABLED(MPCTEMP)
  #define MPC_AUTOTUNE                                // 包含MPC自动调整的方法（约6.3K字节的闪存）
  //#define MPC_EDIT_MENU                             // 将MPC编辑添加到“高级设置”菜单中（约1.3K字节的闪存）
  //#define MPC_AUTOTUNE_MENU                         // 将MPC自动调整添加到“高级设置”菜单中（约350字节的闪存）

  #define MPC_MAX 255                                 // (0..255) MPC激活时的喷嘴电流。
  #define MPC_HEATER_POWER { 40.0f }                  // (W) 加热器功率。

  #define MPC_INCLUDE_FAN                             // 建模风扇速度？

  // 从M306获取的物理常数
  #define MPC_BLOCK_HEAT_CAPACITY { 16.7f }           // (J/K) 热块热容。
  #define MPC_SENSOR_RESPONSIVENESS { 0.22f }         // (K/s per ∆K) 传感器温度从热块的变化速率。
  #define MPC_AMBIENT_XFER_COEFF { 0.068f }           // (W/K) 热块到室内空气（风扇关闭时）的传热系数。
  #if ENABLED(MPC_INCLUDE_FAN)
    #define MPC_AMBIENT_XFER_COEFF_FAN255 { 0.097f }  // (W/K) 热块到室内空气（风扇全开时）的传热系数。
  #endif

  // 对于一个风扇和多个热端，MPC需要知道如何应用风扇冷却效果。
  #if ENABLED(MPC_INCLUDE_FAN)
    //#define MPC_FAN_0_ALL_HOTENDS
    //#define MPC_FAN_0_ACTIVE_HOTEND
  #endif

  // 满料加热容量（焦耳/开尔文/毫米）
  // 使用M306 H<value>在运行时设置
  #define FILAMENT_HEAT_CAPACITY_PERMM { 5.6e-3f }    // 对于1.75mm PLA为0.0056 J/K/mm（对于2.85mm PLA为0.0149 J/K/mm）。
                                                      // 对于1.75mm PETG为0.0036 J/K/mm（对于2.85mm PETG为0.0094 J/K/mm）。
                                                      // 对于1.75mm ABS为0.00515 J/K/mm（对于2.85mm ABS为0.0137 J/K/mm）。
                                                      // 对于1.75mm Nylon为0.00522 J/K/mm（对于2.85mm Nylon为0.0138 J/K/mm）。

  // 高级选项
  #define MPC_SMOOTHING_FACTOR 0.5f                   // (0.0...1.0) 噪音温度传感器可能需要较低的值以进行稳定。
  #define MPC_MIN_AMBIENT_CHANGE 1.0f                 // (K/s) 环境温度模型变化率，用于修正模型不准确性。
  #define MPC_STEADYSTATE 0.5f                        // (K/s) 稳态逻辑的温度变化速率。

  #define MPC_TUNING_POS { X_CENTER, Y_CENTER, 1.0f } // (mm) M306 自动调整位置，理想情况下为床中心在第一层高度。
  #define MPC_TUNING_END_Z 10.0f                      // (mm) M306 自动调整最终Z位置。
#endif

//===========================================================================
//====================== PID > 加热床温度控制 ================================
//===========================================================================

// @section bed temp

/**
 * 最大加热床功率
 * 适用于所有形式的加热床控制（PID、开关控制和带滞后的开关控制）。
 * 当设置为小于255的任何值时，将启用一种将加热床PWM作为除法器的形式，因此，除非您可以接受加热床上的PWM，否则不要使用它。（请参见关于启用PIDTEMPBED的注释）
 *
 */
#define MAX_BED_POWER 255 // 限制加热床的占空比；255 = 全电流

/**
 * PID加热床
 *
 * PID频率将与挤出机PWM相同。
 * 如果PID_dT是默认值，并且对硬件/配置正确，那么意味着7.689Hz，
 * 这对于驱动电阻性负载的方波没有太大影响。这也适用于Fotek SSR-10DA固态继电器驱动250W加热器。
 * 如果您的配置与此显着不同，并且您不了解相关问题，请在有其他人验证您的硬件正常工作之前不要使用加热床PID。
 *
 * 
 * 
 * 禁用此选项将使用开关控制。BED_LIMIT_SWITCHING启用滞后。
 */
#define PIDTEMPBED

#if ENABLED(PIDTEMPBED)
  //#define MIN_BED_POWER 0
  //#define PID_BED_DEBUG // 将加热床PID调试数据打印到串口。

  // 找到您自己的值：“M303 E-1 C8 S90”以在90°C下运行8个周期的自动调整床。
  #define DEFAULT_bedKp 34.0
  #define DEFAULT_bedKi 6.25
  #define DEFAULT_bedKd 140.2

//采用key_configuration_parameters.h的定义优先覆盖
	#if defined(DEFAULT_bedKp_Key) && defined(DEFAULT_bedKi_Key) && defined(DEFAULT_bedKd_Key)
	  #undef DEFAULT_bedKp
	  #define DEFAULT_bedKp DEFAULT_bedKp_Key
	  #undef DEFAULT_bedKi
	  #define DEFAULT_bedKi DEFAULT_bedKi_Key
	  #undef DEFAULT_bedKd
	  #define DEFAULT_bedKd DEFAULT_bedKd_Key
	#elif !defined(DEFAULT_bedKp_Key) && !defined(DEFAULT_bedKi_Key) && !defined(DEFAULT_bedKd_Key)
	  // do nothing
	#else
	  #error "请检查 DEFAULT_bedKp_Key, DEFAULT_bedKi_Key, DEFAULT_bedKd_Key 是否同时被定义或同时不被定义。"
	#endif

#else
  //#define BED_LIMIT_SWITCHING   // 将加热床温度保持在目标温度的BED_HYSTERESIS范围内
#endif

//===========================================================================
//==================== PID > 环境温度控制 ====================
//===========================================================================

/**
 * PID环境加热
 *
 * 如果启用此选项，请在下面设置PID常数。
 * 如果禁用此选项，将使用开关控制，CHAMBER_LIMIT_SWITCHING将启用滞后。
 * 
 *
 * PID频率将与挤出机PWM相同。
 * 如果PID_dT是默认值，并且对硬件/配置正确，那么意味着7.689Hz，
 * 这对于驱动电阻性负载的方波没有太大影响。这也适用于Fotek SSR-10DA固态继电器驱动200W加热器。
 * 如果您的配置与此显着不同，并且您不了解相关问题，请在有其他人验证您的硬件正常工作之前不要使用环境PID。
 * 
 * @section chamber temp
 */
//#define PIDTEMPCHAMBER
//#define CHAMBER_LIMIT_SWITCHING

/**
 * 最大环境加热功率
 * 适用于所有形式的环境加热控制（PID、开关控制和带滞后的开关控制）。
 * 当设置为小于255的任何值时，将启用一种将环境加热器PWM作为除法器的形式，因此，除非您可以接受加热器上的PWM，否则不要使用它。（请参见关于启用PIDTEMPCHAMBER的注释）
 *
 */
#define MAX_CHAMBER_POWER 255 // 限制环境加热器的占空比；255 = 全电流

#if ENABLED(PIDTEMPCHAMBER)
  #define MIN_CHAMBER_POWER 0
  //#define PID_CHAMBER_DEBUG // 将环境加热器PID调试数据打印到串口。

  // 使用Fotek SSR-10DA修改的Lasko“我的个人加热器”（200w）仅控制加热元件
  // 并放置在小型Creality打印机围护罩帐篷内。
  //
  #define DEFAULT_chamberKp 37.04
  #define DEFAULT_chamberKi 1.40
  #define DEFAULT_chamberKd 655.17
  // M309 P37.04 I1.04 D655.17

  // 找到您自己的值：“M303 E-2 C8 S50”以在50°C下运行8个周期的自动调整环境。
#endif // PIDTEMPCHAMBER

#if ANY(PIDTEMP, PIDTEMPBED, PIDTEMPCHAMBER)
  //#define PID_OPENLOOP          // 将PID放入开环中。M104/M140将输出功率从0设置为PID_MAX
  #define SLOW_PWM_HEATERS      // PWM的频率非常低（大约0.125Hz=8s）和状态时间最小约1s，适用于由继电器驱动的加热器
  #define PID_FUNCTIONAL_RANGE 10 // 如果目标温度与实际温度之间的温差大于PID_FUNCTIONAL_RANGE，则关闭PID，并将加热器设置为最小/最大。

  #define PID_EDIT_MENU         // 将PID编辑添加到“高级设置”菜单中（约700字节的闪存）
  #define PID_AUTOTUNE_MENU     // 将PID自动调整添加到“高级设置”菜单中（约250字节的闪存）
#endif

// @section safety

/**
 * 防止温度低于EXTRUDE_MINTEMP时进行挤出。
 * 添加M302来设置最低挤出温度和/或打开和关闭冷挤出防止。
 * 
 * 
 * *** 强烈建议保持此选项启用！ ***
 */
#define PREVENT_COLD_EXTRUSION
#define EXTRUDE_MINTEMP 170

/**
 * 防止单次挤出超过EXTRUDE_MAXLENGTH。
 * 注意：对于Bowden挤出机，使其足够大以允许装载/卸载。
 */
#define PREVENT_LENGTHY_EXTRUDE
#define EXTRUDE_MAXLENGTH 600

//===========================================================================
//======================== 过热保护 =======================
//===========================================================================

/**
 * 过热保护为打印机提供额外的保护，防止损坏和火灾。Marlin始终包括安全的最低和最高温度范围，
 * 可保护免受断开或断开的热敏电阻线的影响。
 *
 * 
 * 问题：如果热敏电阻掉出，它将报告房间中较低的温度，
 * 固件将保持加热器开启。
 *
 * 如果出现“过热保护”或“加热失败”错误，
 * 可在Configuration_adv.h中调整详细信息。
 */

#define THERMAL_PROTECTION_HOTENDS // 为所有挤出机启用过热保护
#define THERMAL_PROTECTION_BED     // 为加热床启用过热保护
#define THERMAL_PROTECTION_CHAMBER // 为加热腔启用过热保护
#define THERMAL_PROTECTION_COOLER  // 为激光冷却启用过热保护

//===========================================================================
//============================= 机械设置 ========================
//===========================================================================

// @section 机器

// 启用以下选项之一以进行CoreXY，CoreXZ或CoreYZ运动学，
// 以通常的顺序或相反的顺序
//#define COREXY
//#define COREXZ
//#define COREYZ
//#define COREYX
//#define COREZX
//#define COREZY
//#define MARKFORGED_XY  // MarkForged. 请参阅https://reprap.org/forum/read.php?152,504042
//#define MARKFORGED_YX

// 启用以获得具有无尽“Z”运动的带式打印机
//#define BELTPRINTER

// 启用Polargraph运动学
//#define POLARGRAPH
#if ENABLED(POLARGRAPH)
  #define POLARGRAPH_MAX_BELT_LEN  1035.0 // （mm）完全展开时的带长。使用M665 H进行覆盖。
  #define DEFAULT_SEGMENTS_PER_SECOND 5   // 基于持续时间的移动分段
  #define PEN_UP_DOWN_MENU                // 在MarlinUI菜单中添加“笔起”和“笔落”
#endif

// @section delta

// 启用DELTA运动学并进行以下配置
//#define DELTA
#if ENABLED(DELTA)

  // 通过许多直线制作delta曲线（线性插值）。
  // 这是可见角的权衡（线段不足）
  // 和处理器负载（太多的昂贵的sqrt调用）。
  #define DEFAULT_SEGMENTS_PER_SECOND 200

  // 在回零后向下移动到XY运动不受限制的高度
  //#define DELTA_HOME_TO_SAFE_ZONE

  // Delta校准菜单
  // 在MarlinUI菜单中添加三点校准。
  // 请参阅http://minow.blogspot.com/index.html#4918805519571907051
  //#define DELTA_CALIBRATION_MENU

  // G33 Delta自动校准。启用EEPROM_SETTINGS以存储结果。
  //#define DELTA_AUTO_CALIBRATION

  #if ENABLED(DELTA_AUTO_CALIBRATION)
    // 默认的探针点数：n*n（1 - > 7）
    #define DELTA_CALIBRATION_DEFAULT_POINTS 4
  #endif

  #if ANY(DELTA_AUTO_CALIBRATION, DELTA_CALIBRATION_MENU)
    // 纸张测试探测的步长
    #define PROBE_MANUALLY_STEP 0.05      // （mm）
  #endif

  // 打印表面直径/ 2减去无法到达的空间（避免与垂直塔碰撞）。
  #define PRINTABLE_RADIUS       140.0    // （mm）

  // 最大可到达区域
  #define DELTA_MAX_RADIUS       140.0    // （mm）

  // 对角推杆上孔的中心距离。
  #define DELTA_DIAGONAL_ROD 250.0        // （mm）

  // 床和喷嘴Z归位位置之间的距离
  #define DELTA_HEIGHT 250.00             // （mm）从G33自动校准获取此值

  #define DELTA_ENDSTOP_ADJ { 0.0, 0.0, 0.0 } // 从G33自动校准获取这些值

  // 当末端效应器居中时，对角推杆所跨越的水平距离。
  #define DELTA_RADIUS 124.0              // （mm）从G33自动校准获取此值

  // 用于单个塔的修剪调整
  // X和Y塔的塔角度校正/旋转XYZ，使Z塔角度= 0
  // 以逆时针角度为度数从上面看
  #define DELTA_TOWER_ANGLE_TRIM { 0.0, 0.0, 0.0 } // 从G33自动校准获取这些值

  // Delta半径和对角杆调整（mm）
  //#define DELTA_RADIUS_TRIM_TOWER { 0.0, 0.0, 0.0 }
  //#define DELTA_DIAGONAL_ROD_TRIM_TOWER { 0.0, 0.0, 0.0 }
#endif

// @section scara

/**
 * MORGAN_SCARA是由南非的QHARLEY在2012-2013年开发的。
 * 由JCERNY在2014年6月实施和略微改进。
 *
 * Mostly Printed SCARA是Tyler Williams的开源设计。参见：
 *   https://www.thingiverse.com/thing:2487048
 *   https://www.thingiverse.com/thing:1241491
 */
//#define MORGAN_SCARA
//#define MP_SCARA
#if ANY(MORGAN_SCARA, MP_SCARA)
  // 如果运动不平滑，请尝试降低此值
  #define DEFAULT_SEGMENTS_PER_SECOND 200

  // 内部和外部支撑臂的长度。精确测量臂长。
  #define SCARA_LINKAGE_1 150       // （mm）
  #define SCARA_LINKAGE_2 150       // （mm）

  // SCARA塔偏移（相对于床零位置的位置）
  // 这需要相当准确，因为它定义了SCARA空间中的打印床位置。
  #define SCARA_OFFSET_X  100       // （mm）
  #define SCARA_OFFSET_Y  -56       // （mm）

  #if ENABLED(MORGAN_SCARA)

    //#define DEBUG_SCARA_KINEMATICS
    #define FEEDRATE_SCALING        // 在行进过程中将XY进给速度从mm / s转换为度/ s

    // 中心周围在这个半径内的手臂无法到达
    #define MIDDLE_DEAD_ZONE_R   0  // （mm）

    #define THETA_HOMING_OFFSET  0  // 从校准指南和M360 / M114计算。参见https://www.morgan3dp.com/morgan-calibration-guide/
    #define PSI_HOMING_OFFSET    0  // 从校准指南和M364 / M114计算。参见https://www.morgan3dp.com/morgan-calibration-guide/

  #elif ENABLED(MP_SCARA)

    #define SCARA_OFFSET_THETA1  12 // 度
    #define SCARA_OFFSET_THETA2 131 // 度

  #endif

#endif

// @section tpara

// 启用TPARA运动学并进行以下配置
//#define AXEL_TPARA
#if ENABLED(AXEL_TPARA)
  #define DEBUG_TPARA_KINEMATICS
  #define DEFAULT_SEGMENTS_PER_SECOND 200

  // 内部和外部支撑臂的长度。精确测量臂长。
  #define TPARA_LINKAGE_1 120       // （mm）
  #define TPARA_LINKAGE_2 120       // （mm）

  // SCARA塔偏移（相对于床零位置的位置）
  // 这需要相当准确，因为它定义了SCARA空间中的打印床位置。
  #define TPARA_OFFSET_X    0       // （mm）
  #define TPARA_OFFSET_Y    0       // （mm）
  #define TPARA_OFFSET_Z    0       // （mm）

  #define FEEDRATE_SCALING        // 在行进过程中将XY进给速度从mm / s转换为度/ s

  // 中心周围在这个半径内的手臂无法到达
  #define MIDDLE_DEAD_ZONE_R   0  // （mm）

  // 从校准指南和M360 / M114计算。参见https://www.morgan3dp.com/morgan-calibration-guide/
  #define THETA_HOMING_OFFSET  0
  #define PSI_HOMING_OFFSET    0
#endif

// @section polar

/**
 * POLAR运动学
 * 由Kadir ilkimen为PolarBear CNC和babyBear开发
 * https://github.com/kadirilkimen/Polar-Bear-Cnc-Machine
 * https://github.com/kadirilkimen/babyBear-3D-printer
 *
 * 极坐标机器可以具有不同的配置。
 * 此运动学仅与以下配置兼容：
 *        X：独立线性
 *   Y或B：极坐标
 *        Z：独立线性
 *
 * 例如，PolarBear具有CoreXZ加上Polar Y或B。
 *
 * 极坐标轴靠近中心/原点的运动问题：
 *
 * 3D打印：
 * 靠近极坐标轴中心的运动比其他运动所需时间更长。
 * 这种简短的延迟导致了由于喷嘴内的压力而产生的更多物料沉积。
 *
 * 当前的运动学和进给速度缩放通过使运动尽可能快来解决这个问题。
 * 对于慢速运动有效，但在快速运动中效果不佳。必须实现更复杂的挤出补偿。
 *
 * 理想情况下，它应该估计一个长时间的靠近中心的旋转即将发生
 * 并且会导致不需要的沉积。因此，它可以预先补偿挤出。
 *
 * 激光切割：
 * 激光雕刻也会出现同样的问题。因为它在中心点旋转的时间更长，
 * 更有可能烧掉比应该烧的更多的材料。因此类似的
 * 补偿将用于激光切割操作。
 *
 * 铣削：
 * 这对切割/铣削操作不应该是一个问题。
 */
//#define POLAR
#if ENABLED(POLAR)
  #define DEFAULT_SEGMENTS_PER_SECOND 180   // 如果运动不平滑，请尝试降低此值
  #define PRINTABLE_RADIUS 82.0f            // （mm）X轴的最大行程

  // 落在POLAR_FAST_RADIUS内的运动被分配最高可能的进给速度
  // 以补偿与靠近原点的运动问题相关的不需要的沉积。
  #define POLAR_FAST_RADIUS 3.0f            // （mm）

  // 工具无法到达的半径。
  // 如果工具与极坐标轴的中心不完全对齐，则需要。
  #define POLAR_CENTER_OFFSET 0.0f          // （mm）

  #define FEEDRATE_SCALING                  // 在行进过程中将XY进给速度从mm / s转换为度/ s
#endif

// @section 机器

// 关节直接映射到没有运动学的轴的关节的机器人臂。
//#define ARTICULATED_ROBOT_ARM

// 对于具有平行水平轴（X，I）的热丝切割器，其中两个丝端的高度由平行轴（Y，J）控制。
// 关节直接映射到轴（无运动学）的关节（没有运动学）。
//#define FOAMCUTTER_XYUV

//===========================================================================
//============================== 终止开关设置 ===========================
//===========================================================================

// @section 终止开关

// 启用所有终止开关的上拉电阻，以防止浮动状态
#define ENDSTOPPULLUPS
#if DISABLED(ENDSTOPPULLUPS)
  // 禁用ENDSTOPPULLUPS以单独设置上拉电阻
  //#define ENDSTOPPULLUP_XMIN
  //#define ENDSTOPPULLUP_YMIN
  //#define ENDSTOPPULLUP_ZMIN
  //#define ENDSTOPPULLUP_IMIN
  //#define ENDSTOPPULLUP_JMIN
  //#define ENDSTOPPULLUP_KMIN
  //#define ENDSTOPPULLUP_UMIN
  //#define ENDSTOPPULLUP_VMIN
  //#define ENDSTOPPULLUP_WMIN
  //#define ENDSTOPPULLUP_XMAX
  //#define ENDSTOPPULLUP_YMAX
  //#define ENDSTOPPULLUP_ZMAX
  //#define ENDSTOPPULLUP_IMAX
  //#define ENDSTOPPULLUP_JMAX
  //#define ENDSTOPPULLUP_KMAX
  //#define ENDSTOPPULLUP_UMAX
  //#define ENDSTOPPULLUP_VMAX
  //#define ENDSTOPPULLUP_WMAX
  //#define ENDSTOPPULLUP_ZMIN_PROBE
#endif

// 启用所有终止开关的下拉电阻以防止浮动状态
//#define ENDSTOPPULLDOWNS
#if DISABLED(ENDSTOPPULLDOWNS)
  // 禁用ENDSTOPPULLDOWNS以单独设置下拉电阻
  //#define ENDSTOPPULLDOWN_XMIN
  //#define ENDSTOPPULLDOWN_YMIN
  //#define ENDSTOPPULLDOWN_ZMIN
  //#define ENDSTOPPULLDOWN_IMIN
  //#define ENDSTOPPULLDOWN_JMIN
  //#define ENDSTOPPULLDOWN_KMIN
  //#define ENDSTOPPULLDOWN_UMIN
  //#define ENDSTOPPULLDOWN_VMIN
  //#define ENDSTOPPULLDOWN_WMIN
  //#define ENDSTOPPULLDOWN_XMAX
  //#define ENDSTOPPULLDOWN_YMAX
  //#define ENDSTOPPULLDOWN_ZMAX
  //#define ENDSTOPPULLDOWN_IMAX
  //#define ENDSTOPPULLDOWN_JMAX
  //#define ENDSTOPPULLDOWN_KMAX
  //#define ENDSTOPPULLDOWN_UMAX
  //#define ENDSTOPPULLDOWN_VMAX
  //#define ENDSTOPPULLDOWN_WMAX
  //#define ENDSTOPPULLDOWN_ZMIN_PROBE
#endif

/**
 * 终止开关“触发”状态
 * 设置为适用于每个终止开关的状态（HIGH或LOW）。
 */
#define X_MIN_ENDSTOP_HIT_STATE LOW
// #define X_MAX_ENDSTOP_HIT_STATE HIGH
#define Y_MIN_ENDSTOP_HIT_STATE LOW
// #define Y_MAX_ENDSTOP_HIT_STATE HIGH
#define Z_MIN_ENDSTOP_HIT_STATE LOW
// #define Z_MAX_ENDSTOP_HIT_STATE HIGH
// #define I_MIN_ENDSTOP_HIT_STATE HIGH
// #define I_MAX_ENDSTOP_HIT_STATE HIGH
// #define J_MIN_ENDSTOP_HIT_STATE HIGH
// #define J_MAX_ENDSTOP_HIT_STATE HIGH
// #define K_MIN_ENDSTOP_HIT_STATE HIGH
// #define K_MAX_ENDSTOP_HIT_STATE HIGH
// #define U_MIN_ENDSTOP_HIT_STATE HIGH
// #define U_MAX_ENDSTOP_HIT_STATE HIGH
// #define V_MIN_ENDSTOP_HIT_STATE HIGH
// #define V_MAX_ENDSTOP_HIT_STATE HIGH
// #define W_MIN_ENDSTOP_HIT_STATE HIGH
// #define W_MAX_ENDSTOP_HIT_STATE HIGH
 #define Z_MIN_PROBE_ENDSTOP_HIT_STATE HIGH

// 如果所有启用的终止开关引脚都支持中断，请启用此功能。
// 这将消除了轮询中断引脚的必要性，从而节省了许多CPU周期。
//#define ENDSTOP_INTERRUPTS_FEATURE

/**
 * 终止开关噪声阈值
 *
 * 如果您的探针或终止开关由于噪声而误触发，请启用。
 *
 * - 较高的值可能会影响某些床探头的重复性或准确性。
 * - 要修复噪声，请在开关上并联安装100nF陶瓷电容器。
 * - 对于基于Makerbot设计的PCB上安装的常见微动开关，不需要此功能
 *   已经有了100nF电容器。
 *
 * ：[2,3,4,5,6,7]
 */
//#define ENDSTOP_NOISE_THRESHOLD 2

// 在回零运动过程中检测卡住或断开的终止开关。
#define DETECT_BROKEN_ENDSTOP

//=============================================================================
//============================== 运动设置 =======================================
//=============================================================================
// @section motion

/**
 * 默认设置
 *
 * 这些设置可以通过M502重置
 *
 * 需要注意的是，如果启用了EEPROM，保存的值将覆盖这些值。
 */

/**
 * 使用此选项，每个E电机可以有自己的因子来设置以下运动设置。
 * 如果给出的因子数少于总的挤出机数，最后一个值将适用于其余的挤出机。
 */
//#define DISTINCT_E_FACTORS

/**
 * 默认轴每单位步数（线性=步/毫米，旋转=步/°）
 * 使用M92进行覆盖
 *                                      X, Y, Z [, I [, J [, K...]]], E0 [, E1[, E2...]]
 */
#define DEFAULT_AXIS_STEPS_PER_UNIT   { 80, 80, 400, 382.161 }
//采用key_configuration_parameters.h的定义优先覆盖
#if defined(DEFAULT_AXIS_STEPS_PER_UNIT_X) && defined(DEFAULT_AXIS_STEPS_PER_UNIT_Y) && defined(DEFAULT_AXIS_STEPS_PER_UNIT_Z) && defined(DEFAULT_AXIS_STEPS_PER_UNIT_E)
  #undef DEFAULT_AXIS_STEPS_PER_UNIT
  #define DEFAULT_AXIS_STEPS_PER_UNIT { DEFAULT_AXIS_STEPS_PER_UNIT_X, DEFAULT_AXIS_STEPS_PER_UNIT_Y, DEFAULT_AXIS_STEPS_PER_UNIT_Z, DEFAULT_AXIS_STEPS_PER_UNIT_E }
#elif !defined(DEFAULT_AXIS_STEPS_PER_UNIT_X) && !defined(DEFAULT_AXIS_STEPS_PER_UNIT_Y) && !defined(DEFAULT_AXIS_STEPS_PER_UNIT_Z) && !defined(DEFAULT_AXIS_STEPS_PER_UNIT_E)
  // 什么也不做
#else
  #error "请检查 DEFAULT_AXIS_STEPS_PER_UNIT_X, DEFAULT_AXIS_STEPS_PER_UNIT_Y, DEFAULT_AXIS_STEPS_PER_UNIT_Z, DEFAULT_AXIS_STEPS_PER_UNIT_E 是否同时被定义或同时不被定义。"
#endif


/**
 * 默认最大进给速度（线性=毫米/秒，旋转=°/秒）
 * 使用M203进行覆盖
 *                                      X, Y, Z [, I [, J [, K...]]], E0 [, E1[, E2...]]
 */
#define DEFAULT_MAX_FEEDRATE          { 500, 500, 5, 25 }

//采用key_configuration_parameters.h的定义优先覆盖
#if defined(DEFAULT_MAX_FEEDRATE_X) && defined(DEFAULT_MAX_FEEDRATE_Y) && defined(DEFAULT_MAX_FEEDRATE_Z) && defined(DEFAULT_MAX_FEEDRATE_E)
  #undef DEFAULT_MAX_FEEDRATE
  #define DEFAULT_MAX_FEEDRATE { DEFAULT_MAX_FEEDRATE_X, DEFAULT_MAX_FEEDRATE_Y, DEFAULT_MAX_FEEDRATE_Z, DEFAULT_MAX_FEEDRATE_E }
#elif !defined(DEFAULT_MAX_FEEDRATE_X) && !defined(DEFAULT_MAX_FEEDRATE_Y) && !defined(DEFAULT_MAX_FEEDRATE_Z) && !defined(DEFAULT_MAX_FEEDRATE_E)
  // do nothing
#else
  #error "请检查 DEFAULT_MAX_FEEDRATE_X, DEFAULT_MAX_FEEDRATE_Y, DEFAULT_MAX_FEEDRATE_Z, DEFAULT_MAX_FEEDRATE_E 是否同时被定义或同时不被定义。"
#endif

#define LIMITED_MAX_FR_EDITING        // 通过M203或LCD将编辑限制为DEFAULT_MAX_FEEDRATE * 2
#if ENABLED(LIMITED_MAX_FR_EDITING)
  //#define MAX_FEEDRATE_EDIT_VALUES    { 600, 600, 10, 50 } // ...或者，设置自己的编辑限制
#endif

/**
 * 默认最大加速度（时间变化速度）（线性=毫米/（秒^2），旋转=°/（秒^2））
 * （加速运动的最大起始速度）
 * 使用M201进行覆盖
 *                                      X, Y, Z [, I [, J [, K...]]], E0 [, E1[, E2...]]
 */
#define DEFAULT_MAX_ACCELERATION      { 500, 500, 100, 5000 }
//采用key_configuration_parameters.h的定义优先覆盖
#if defined(DEFAULT_MAX_ACCELERATION_X) && defined(DEFAULT_MAX_ACCELERATION_Y) && defined(DEFAULT_MAX_ACCELERATION_Z) && defined(DEFAULT_MAX_ACCELERATION_E)
  #undef DEFAULT_MAX_ACCELERATION
  #define DEFAULT_MAX_ACCELERATION { DEFAULT_MAX_ACCELERATION_X, DEFAULT_MAX_ACCELERATION_Y, DEFAULT_MAX_ACCELERATION_Z, DEFAULT_MAX_ACCELERATION_E }
#elif !defined(DEFAULT_MAX_ACCELERATION_X) && !defined(DEFAULT_MAX_ACCELERATION_Y) && !defined(DEFAULT_MAX_ACCELERATION_Z) && !defined(DEFAULT_MAX_ACCELERATION_E)
  // do nothing
#else
  #error "请检查 DEFAULT_MAX_ACCELERATION_X, DEFAULT_MAX_ACCELERATION_Y, DEFAULT_MAX_ACCELERATION_Z, DEFAULT_MAX_ACCELERATION_E 是否同时被定义或同时不被定义。"
#endif



#define LIMITED_MAX_ACCEL_EDITING     // 通过M201或LCD将编辑限制为DEFAULT_MAX_ACCELERATION * 2
#if ENABLED(LIMITED_MAX_ACCEL_EDITING)
  //#define MAX_ACCEL_EDIT_VALUES       { 6000, 6000, 200, 20000 } // ...或者，设置自己的编辑限制
#endif

/**
 * 默认加速度（时间变化速度）（线性=毫米/（秒^2），旋转=°/（秒^2））
 * 使用M204进行覆盖
 *
 *   M204 P    加速度
 *   M204 R    回退加速度
 *   M204 T    移动加速度
 *   M204 I    角加速度
 *   M204 J    角移动加速度
 */
#define DEFAULT_ACCELERATION                   500  // X, Y, Z ... 和 E 打印移动的加速度
#define DEFAULT_RETRACT_ACCELERATION           500  // 回退的 E 加速度
#define DEFAULT_TRAVEL_ACCELERATION            500  // X, Y, Z ... 的移动（非打印）加速度

//采用key_configuration_parameters.h的定义优先覆盖
#if defined(DEFAULT_ACCELERATION_Key) && defined(DEFAULT_RETRACT_ACCELERATION_Key) && defined(DEFAULT_TRAVEL_ACCELERATION_Key)
  #undef DEFAULT_ACCELERATION
  #define DEFAULT_ACCELERATION DEFAULT_ACCELERATION_Key
  #undef DEFAULT_RETRACT_ACCELERATION
  #define DEFAULT_RETRACT_ACCELERATION DEFAULT_RETRACT_ACCELERATION_Key
  #undef DEFAULT_TRAVEL_ACCELERATION
  #define DEFAULT_TRAVEL_ACCELERATION DEFAULT_TRAVEL_ACCELERATION_Key
#elif !defined(DEFAULT_ACCELERATION_Key) && !defined(DEFAULT_RETRACT_ACCELERATION_Key) && !defined(DEFAULT_TRAVEL_ACCELERATION_Key)
  // 不执行任何操作
#else
  #error "DEFAULT_ACCELERATION_Key、DEFAULT_RETRACT_ACCELERATION_Key 和 DEFAULT_TRAVEL_ACCELERATION_Key 必须全部定义或全部不定义"
#endif

#if ENABLED(AXIS4_ROTATES)
  #define DEFAULT_ANGULAR_ACCELERATION        3000  // 旋转打印移动的 I, J, K 加速度
  #define DEFAULT_ANGULAR_TRAVEL_ACCELERATION 3000  // 旋转移动（非打印）的 I, J, K 加速度
#endif

/**
 * 默认Jerk限制（毫米/秒）
 * 使用M205进行覆盖 X Y Z . . . E
 *
 * “Jerk”指定了需要加速度的最小速度变化。
 * 当改变速度和方向时，如果差异小于此处设置的值，则可能立即发生。
 */
//#define CLASSIC_JERK
#if ENABLED(CLASSIC_JERK)
  #define DEFAULT_XJERK 10.0
  #define DEFAULT_YJERK 10.0
  #define DEFAULT_ZJERK  0.3
  //#define DEFAULT_IJERK  0.3
  //#define DEFAULT_JJERK  0.3
  //#define DEFAULT_KJERK  0.3
  //#define DEFAULT_UJERK  0.3
  //#define DEFAULT_VJERK  0.3
  //#define DEFAULT_WJERK  0.3

  //#define TRAVEL_EXTRA_XYJERK 0.0     // 所有移动的额外Jerk补贴

  //#define LIMITED_JERK_EDITING        // 通过M205或LCD将编辑限制为DEFAULT_aJERK * 2
  #if ENABLED(LIMITED_JERK_EDITING)
    #define MAX_JERK_EDIT_VALUES { 20, 20, 0.6, 10 } // ...或者，设置自己的编辑限制
  #endif
#endif

#define DEFAULT_EJERK    5.0  // 可能被线性提前使用

/**
 * 路口偏差因子
 *
 * 查看：
 *   https://reprap.org/forum/read.php?1,739819
 *   https://blog.kyneticcnc.com/2018/10/computing-junction-deviation-for-marlin.html
 */
#if DISABLED(CLASSIC_JERK)
  #define JUNCTION_DEVIATION_MM 0.08  // （毫米）距离实际交叉点边缘的距离
  #define JD_HANDLE_SMALL_SEGMENTS    // 对于小段（<1mm）和大的分歧角（> 135°），使用曲率估计而不仅仅是交叉点角度
#endif

/**
 * S-Curve加速度
 *
 * 此选项通过将Bézier曲线拟合到移动加速度来消除打印过程中的振动，从而产生更平滑的方向变化。
 *
 * 请参阅https://github.com/synthetos/TinyG/wiki/Jerk-Controlled-Motion-Explained
 */
#define S_CURVE_ACCELERATION

//===========================================================================
//============================= Z探针选项 =============================
//===========================================================================
// @section 探针

//
// 请参考 https://marlinfw.org/docs/configuration/probes.html
//

/**
 * 启用此选项以连接到Z-MIN引脚的探针。
 * 该探针替代了Z-MIN终点开关，并用于Z归位。
 * （自动启用USE_PROBE_FOR_Z_HOMING）
 */
//#define Z_MIN_PROBE_USES_Z_MIN_ENDSTOP_PIN

//采用key_configuration_parameters.h的定义优先覆盖
#ifdef Z_Axis_Probe
    #if (Z_Axis_Probe != Fixed && Z_Axis_Probe != Bltouch)
        #error "Z_Axis_Probe设置有误"
        #undef Z_Axis_Probe
    #endif
    #if Z_Axis_Probe == Fixed
        #ifndef Z_MIN_PROBE_USES_Z_MIN_ENDSTOP_PIN
            #define Z_MIN_PROBE_USES_Z_MIN_ENDSTOP_PIN
        #endif
    #elif Z_Axis_Probe == Bltouch
        #ifdef Z_MIN_PROBE_USES_Z_MIN_ENDSTOP_PIN
            #undef Z_MIN_PROBE_USES_Z_MIN_ENDSTOP_PIN
        #endif
    #endif
#endif

// 强制使用探针进行Z轴归位
//#define USE_PROBE_FOR_Z_HOMING

/**
 * Z_MIN_PROBE_PIN
 *
 * 仅在探针无法连接到所选MOTHERBOARD的默认Z_MIN_PROBE_PIN时覆盖此引脚。
 *
 * - 最简单的选项是使用一个空闲的终点连接器。
 * - 对于供电（通常是感应式）传感器，请使用5V。
 *
 * - 对于简单的开关...
 *   - 常闭（NC）也连接到GND。
 *   - 常开（NO）也连接到5V。
 */
//#define Z_MIN_PROBE_PIN -1

/**
 * 探针类型
 *
 * Allen Key探针，舵机探针，Z-Sled探针，FIX_MOUNTED_PROBE等。
 * 激活其中之一以使用下面的自动调平台功能。
 */

/**
 * "Manual Probe"提供了一种在没有探针的情况下进行"自动"调平台的方法。
 * 使用G29重复调用，在每个点上使用移动命令或（使用LCD_BED_LEVELING）LCD控制器调整Z高度。
 */
//#define PROBE_MANUALLY

/**
 * 固定安装的探针不会展开或需要手动展开。
 *   （例如感应探针或基于喷嘴的探针开关。）
 */
//#define FIX_MOUNTED_PROBE

/**
 * 使用喷嘴作为探针，例如具有导电喷嘴系统或压电智能效应器。
 */
//#define NOZZLE_AS_PROBE

/**
 * Z舵机探针，例如旋转臂上的终点开关。
 */
//#define Z_PROBE_SERVO_NR 0
#ifdef Z_PROBE_SERVO_NR
  //#define Z_SERVO_ANGLES { 70, 0 }      // Z舵机展开和收起角度
  //#define Z_SERVO_MEASURE_ANGLE 45      // 如果舵机在展开后必须移动到“自由”位置进行测量，请使用此选项
  //#define Z_SERVO_INTERMEDIATE_STOW     // 在点之间收起探针
  //#define Z_SERVO_DEACTIVATE_AFTER_STOW // 在探针收起时停用舵机
#endif

/**
 * BLTouch探针使用霍尔效应传感器并模拟舵机。
 */
#define BLTOUCH

/**
 * MagLev V4探针，由MDD提供
 *
 * 此探针通过给内置电磁铁供电来展开和激活。
 */
//#define MAGLEV4
#if ENABLED(MAGLEV4)
  //#define MAGLEV_TRIGGER_PIN 11     // 设置为连接的数字输出
  #define MAGLEV_TRIGGER_DELAY 15     // 更改此值可能导致线圈过热
#endif

/**
 * Touch-MI探针，由hotends.fr提供
 *
 * 此探针通过将X轴移动到床边缘上的磁铁上来展开和激活。
 * 默认情况下，磁铁假定在左侧，并通过home命令激活。如果磁铁在右侧，请启用并设置TOUCH_MI_DEPLOY_XPOS为展开位置。
 *
 * 还需要：BABYSTEPPING，BABYSTEP_ZPROBE_OFFSET，Z_SAFE_HOMING，
 *         以及最小的Z_CLEARANCE_FOR_HOMING为10。
 */
//#define TOUCH_MI_PROBE
#if ENABLED(TOUCH_MI_PROBE)
  #define TOUCH_MI_RETRACT_Z 0.5                  // 探针收起的高度
  //#define TOUCH_MI_DEPLOY_XPOS (X_MAX_BED + 2)  // 如果磁铁在床的右侧，请使用此选项
  //#define TOUCH_MI_MANUAL_DEPLOY                // 手动展开（LCD菜单）
#endif

// 通过电磁铁引脚（SOL1_PIN）展开和收起的探针
//#define SOLENOID_PROBE

// 类似于Charles Bell设计的底座安装探针。
//#define Z_PROBE_SLED
//#define SLED_DOCKING_OFFSET 5  // X轴必须移动的额外距离以拾取底座。0应该没有问题，但如果需要，您可以将其推得更远。

// 通过移动x轴展开的探针，例如Marty Rice设计的Wilson II的齿轮和齿条探针。
//#define RACK_AND_PINION_PROBE
#if ENABLED(RACK_AND_PINION_PROBE)
  #define Z_PROBE_DEPLOY_X  X_MIN_POS
  #define Z_PROBE_RETRACT_X X_MAX_POS
#endif

/**
 * 磁性安装的探针
 * 适用于Euclid、Klicky、Klackender等探针。
 */
//#define MAG_MOUNTED_PROBE
#if ENABLED(MAG_MOUNTED_PROBE)
  #define PROBE_DEPLOY_FEEDRATE (133*60)  // (mm/min) 探针展开速度
  #define PROBE_STOW_FEEDRATE   (133*60)  // (mm/min) 探针收起速度

  #define MAG_MOUNTED_DEPLOY_1 { PROBE_DEPLOY_FEEDRATE, { 245, 114, 30 } }  // 移动到侧面，停靠并连接探针
  #define MAG_MOUNTED_DEPLOY_2 { PROBE_DEPLOY_FEEDRATE, { 210, 114, 30 } }  // 将探针从底座上移开
  #define MAG_MOUNTED_DEPLOY_3 { PROBE_DEPLOY_FEEDRATE, {   0,   0,  0 } }  // 如有需要，额外移动
  #define MAG_MOUNTED_DEPLOY_4 { PROBE_DEPLOY_FEEDRATE, {   0,   0,  0 } }  // 如有需要，额外移动
  #define MAG_MOUNTED_DEPLOY_5 { PROBE_DEPLOY_FEEDRATE, {   0,   0,  0 } }  // 如有需要，额外移动
  #define MAG_MOUNTED_STOW_1   { PROBE_STOW_FEEDRATE,   { 245, 114, 20 } }  // 移动到底座
  #define MAG_MOUNTED_STOW_2   { PROBE_STOW_FEEDRATE,   { 245, 114,  0 } }  // 将探针放在移除器旁边
  #define MAG_MOUNTED_STOW_3   { PROBE_STOW_FEEDRATE,   { 230, 114,  0 } }  // 侧面移动以移除探针
  #define MAG_MOUNTED_STOW_4   { PROBE_STOW_FEEDRATE,   { 210, 114, 20 } }  // 侧面移动以移除探针
  #define MAG_MOUNTED_STOW_5   { PROBE_STOW_FEEDRATE,   {   0,   0,  0 } }  // 如有需要，额外移动
#endif

// Duet Smart Effector（用于Delta打印机）- https://docs.duet3d.com/en/Duet3D_hardware/Accessories/Smart_Effector
// 当定义了引脚时，可以使用M672来设置/重置探针的灵敏度。
//#define DUET_SMART_EFFECTOR
#if ENABLED(DUET_SMART_EFFECTOR)
  #define SMART_EFFECTOR_MOD_PIN  -1  // 将GPIO引脚连接到Smart Effector MOD引脚
#endif

/**
 * 使用StallGuard2用喷嘴探测床。
 * 需要具有StallGuard功能的Trinamic步进电机驱动器。
 * 注意：这可能会损坏具有Z导程螺杆的机器。
 *       在设置此功能时要非常小心。
 */
//#define SENSORLESS_PROBING

/**
 * Allen key可收起的z探针，许多Kossel Delta 3D打印机上可见 - https://reprap.org/wiki/Kossel#Autolevel_probe
 * 通过触碰Z轴皮带展开。通过按下探针收起。
 */
//#define Z_PROBE_ALLEN_KEY
#if ENABLED(Z_PROBE_ALLEN_KEY)
  // G29上展开和收起弹簧加载的触摸探针的2或3组坐标，
  // 如果定义了舵机驱动的触摸探针，请取消注释适用于您的打印机/探针的选项。

  #define Z_PROBE_ALLEN_KEY_DEPLOY_1 { 30.0, PRINTABLE_RADIUS, 100.0 }
  #define Z_PROBE_ALLEN_KEY_DEPLOY_1_FEEDRATE XY_PROBE_FEEDRATE

  #define Z_PROBE_ALLEN_KEY_DEPLOY_2 { 0.0, PRINTABLE_RADIUS, 100.0 }
  #define Z_PROBE_ALLEN_KEY_DEPLOY_2_FEEDRATE (XY_PROBE_FEEDRATE)/10

  #define Z_PROBE_ALLEN_KEY_DEPLOY_3 { 0.0, (PRINTABLE_RADIUS) * 0.75, 100.0 }
  #define Z_PROBE_ALLEN_KEY_DEPLOY_3_FEEDRATE XY_PROBE_FEEDRATE

  #define Z_PROBE_ALLEN_KEY_STOW_1 { -64.0, 56.0, 23.0 } // 将探针移动到位置
  #define Z_PROBE_ALLEN_KEY_STOW_1_FEEDRATE XY_PROBE_FEEDRATE

  #define Z_PROBE_ALLEN_KEY_STOW_2 { -64.0, 56.0, 3.0 } // 按下探针
  #define Z_PROBE_ALLEN_KEY_STOW_2_FEEDRATE (XY_PROBE_FEEDRATE)/10

  #define Z_PROBE_ALLEN_KEY_STOW_3 { -64.0, 56.0, 50.0 } // 将其抬起以清除
  #define Z_PROBE_ALLEN_KEY_STOW_3_FEEDRATE XY_PROBE_FEEDRATE

  #define Z_PROBE_ALLEN_KEY_STOW_4 { 0.0, 0.0, 50.0 }
  #define Z_PROBE_ALLEN_KEY_STOW_4_FEEDRATE XY_PROBE_FEEDRATE

#endif // Z_PROBE_ALLEN_KEY

//对Z探针进行覆盖
//采用key_configuration_parameters.h的定义优先覆盖
#ifdef Z_Axis_Probe
    #if (Z_Axis_Probe != Fixed && Z_Axis_Probe != Bltouch)
        #error "Z_Axis_Probe设置有误"
        #ifdef FIX_MOUNTED_PROBE
            #define Z_MIN_PROBE_USES_Z_MIN_ENDSTOP_PIN
        #endif
        #undef Z_Axis_Probe
    #endif
    #if Z_Axis_Probe == Fixed
        #ifndef Z_MIN_PROBE_USES_Z_MIN_ENDSTOP_PIN
            #define Z_MIN_PROBE_USES_Z_MIN_ENDSTOP_PIN
        #endif
        #ifdef BLTOUCH
            #undef BLTOUCH
        #endif
        #ifndef FIX_MOUNTED_PROBE
            #define FIX_MOUNTED_PROBE
        #endif
    #elif Z_Axis_Probe == Bltouch
        #ifdef Z_MIN_PROBE_USES_Z_MIN_ENDSTOP_PIN
            #undef Z_MIN_PROBE_USES_Z_MIN_ENDSTOP_PIN
        #endif
        #ifdef FIX_MOUNTED_PROBE
            #undef FIX_MOUNTED_PROBE
        #endif
        #ifndef BLTOUCH
            #define BLTOUCH
        #endif
    #endif
#endif




/**
 * 喷嘴到探针的偏移量 { X, Y, Z }
 *
 * X和Y偏移量
 *   使用卡尺或尺子测量从喷嘴尖到探针中心点的X和Y轴上的距离。
 *
 * Z偏移量
 * - 对于Z偏移，请使用您最了解的值，并在运行时进行调整。
 * - 通常的探针在喷嘴下面触发，并且Z偏移量为负值。
 * - 触发在喷嘴高度之上的探头不常见，但确实存在。使用此类探头时，
 *   请小心设置Z_CLEARANCE_DEPLOY_PROBE和Z_CLEARANCE_BETWEEN_PROBES
 *   以避免在探测期间发生碰撞。
 *
 * 调整和调整
 * - 可以使用“M851”、LCD菜单、微步调等在运行时调整探针偏移。
 * - PROBE_OFFSET_WIZARD（configuration_adv.h）可用于设置Z偏移。
 *
 * 假设典型的工作区方向：
 *  - 喷嘴在探针的右侧，具有正X偏移量
 *  - 喷嘴在探针的左侧，具有负X偏移量
 *  - 喷嘴在探针的后面，具有正Y偏移量
 *  - 喷嘴在探针的前面，具有负Y偏移量
 *
 * 一些示例：
 *   #define NOZZLE_TO_PROBE_OFFSET { 10, 10, -1 }   // 示例 "1"
 *   #define NOZZLE_TO_PROBE_OFFSET {-10,  5, -1 }   // 示例 "2"
 *   #define NOZZLE_TO_PROBE_OFFSET {  5, -5, -1 }   // 示例 "3"
 *   #define NOZZLE_TO_PROBE_OFFSET {-15,-10, -1 }   // 示例 "4"
 *
 *     +-- 后面 ---+
 *     |    [+]    |
 *   L |        1  | R <-- 示例 "1" (右+,  后+)
 *   E |  2        | I <-- 示例 "2" ( 左-,  后+)
 *   F |[-]  N  [+]| G <-- 喷嘴
 *   T |       3   | H <-- 示例 "3" (右+,  前-)
 *     | 4         | T <-- 示例 "4" ( 左-,  前-)
 *     |    [-]    |
 *     O-- 前面 --+
 */
#define NOZZLE_TO_PROBE_OFFSET { 10, 10, 0 }

//采用key_configuration_parameters.h的定义优先覆盖
#if defined(NOZZLE_TO_PROBE_OFFSET_X) && defined(NOZZLE_TO_PROBE_OFFSET_Y) && defined(NOZZLE_TO_PROBE_OFFSET_Z)
  #undef NOZZLE_TO_PROBE_OFFSET
  #define NOZZLE_TO_PROBE_OFFSET { NOZZLE_TO_PROBE_OFFSET_X, NOZZLE_TO_PROBE_OFFSET_Y, NOZZLE_TO_PROBE_OFFSET_Z }
#elif !defined(NOZZLE_TO_PROBE_OFFSET_X) && !defined(NOZZLE_TO_PROBE_OFFSET_Y) && !defined(NOZZLE_TO_PROBE_OFFSET_Z)
  // do nothing
#else
  #error "请检查 NOZZLE_TO_PROBE_OFFSET_X, NOZZLE_TO_PROBE_OFFSET_Y, NOZZLE_TO_PROBE_OFFSET_Z 是否同时被定义或同时不被定义。"
#endif


// 启用并设置为使用特定工具进行探测。禁用以允许任何工具。
#define PROBING_TOOL 0
#ifdef PROBING_TOOL
  //#define PROBE_TOOLCHANGE_NO_MOVE  // 在探针换工具时禁止移动
#endif

// 大多数探针应远离床的边缘，但
// 使用NOZZLE_AS_PROBE时，这可以是负值，以获得更宽的探测区域。
#define PROBING_MARGIN 35

// 探针之间的X和Y轴移动速度（mm/min）
#define XY_PROBE_FEEDRATE (133*60)

// “多次探测”（MULTIPLE_PROBING == 2）时第一次探测的进给速率（mm/min）
#define Z_PROBE_FEEDRATE_FAST (4*60)

// 每个点的“准确”探测的进给速率（mm/min）
#define Z_PROBE_FEEDRATE_SLOW (Z_PROBE_FEEDRATE_FAST / 2)

/**
 * 探针激活开关
 * 一个开关指示正确展开，或者一个光学
 * 开关在车厢靠近床时触发。
 */
//#define PROBE_ACTIVATION_SWITCH
#if ENABLED(PROBE_ACTIVATION_SWITCH)
  #define PROBE_ACTIVATION_SWITCH_STATE LOW // 指示探针处于活动状态的状态
  //#define PROBE_ACTIVATION_SWITCH_PIN PC6 // 在此处覆盖默认引脚
#endif

/**
 * 在每次探测之前设置Tare探针（确定零点）。
 * 对于需要排除诸如拉扯车厢上的电缆等元素的应变计或压电传感器很有用。
 */
//#define PROBE_TARE
#if ENABLED(PROBE_TARE)
  #define PROBE_TARE_TIME  200    // （ms）保持校准引脚的时间
  #define PROBE_TARE_DELAY 200    // （ms）校准之后的延迟
  #define PROBE_TARE_STATE HIGH   // 校准引脚的写入状态
  //#define PROBE_TARE_PIN PA5    // 在此处覆盖默认引脚
  #if ENABLED(PROBE_ACTIVATION_SWITCH)
    //#define PROBE_TARE_ONLY_WHILE_INACTIVE  // 如果PROBE_ACTIVATION_SWITCH处于活动状态，则无法进行校准/探针
  #endif
#endif

/**
 * 探针启用/禁用
 * 仅当启用时，探针才会提供触发信号。
 */
//#define PROBE_ENABLE_DISABLE
#if ENABLED(PROBE_ENABLE_DISABLE)
  //#define PROBE_ENABLE_PIN -1   // 在此处覆盖默认引脚
#endif

/**
 * 多次探测
 *
 * 通过多次探测2次或更多次，可以获得改进的结果。
 * 使用EXTRA_PROBING将忽略更具有代表性的读数。
 *
 * 2次快/慢探测，使用加权平均值。
 * 3次或更多次增加更多的慢速探测，取平均值。
 */
#define MULTIPLE_PROBING 2
#define EXTRA_PROBING    1

/**
 * Z探针在部署、收起和在探针点之间移动时，需要清除空间，以避免碰撞床和其他硬件。
 * 安装在舵机上的探针需要额外的空间来旋转臂。
 * 电感式探针需要空间来避免早期触发。
 *
 * 使用这些设置来指定升起探针（或降低床）的距离（毫米）。
 * 这里设置的值适用于任何（负值）与NOZZLE_TO_PROBE_OFFSET，M851或LCD设置的探针Z偏移。
 * 只有大于等于1的整数值才有效。
 *
 * 示例：“M851 Z-5”与CLEARANCE为4 => 床和喷嘴之间的距离为9mm。
 * 但是：“M851 Z+1”与CLEARANCE为2 => 床和喷嘴之间的距离为2mm。
 */
#define Z_CLEARANCE_DEPLOY_PROBE    20 // 部署/收起时的Z间隙
#define Z_CLEARANCE_BETWEEN_PROBES  20 // 探针点之间的Z间隙
#define Z_CLEARANCE_MULTI_PROBE     20 // 多次探针之间的Z间隙
//#define Z_AFTER_PROBING           5 // 探测完成后的Z位置

#define Z_PROBE_LOW_POINT          -2 // 在触发点下方的最远距离，停止前进

// 对于M851，给出Z探针偏移的范围
#define Z_PROBE_OFFSET_RANGE_MIN -20
#define Z_PROBE_OFFSET_RANGE_MAX 20

// 启用M48重复性测试以测试探针精度
//#define Z_MIN_PROBE_REPEATABILITY_TEST

// 在部署/收起之前暂停等待用户确认
//#define PAUSE_BEFORE_DEPLOY_STOW
#if ENABLED(PAUSE_BEFORE_DEPLOY_STOW)
  //#define PAUSE_PROBE_DEPLOY_WHEN_TRIGGERED // 用于手动部署Allenkey探针
#endif

/**
 * 如果探测不可靠，请启用以下一个或多个选项。
 * 在探测期间禁用加热器和/或风扇以最小化电气噪声。
 * 还可以添加延迟以使噪音和振动稳定下来。
 * 这些选项对BLTouch探针最有用，但也可能改善电感探针和压电传感器的读数。
 */
//#define PROBING_HEATERS_OFF       // 探针时关闭加热器
#if ENABLED(PROBING_HEATERS_OFF)
  //#define WAIT_FOR_BED_HEATER     // 等待床加热到达所需温度（提高准确性）
  //#define WAIT_FOR_HOTEND         // 等待热端加热到达所需温度（提高准确性，防止冷挤出）
#endif
//#define PROBING_FANS_OFF          // 探针时关闭风扇
//#define PROBING_ESTEPPERS_OFF     // 探针时关闭所有挤出机步进电机
//#define PROBING_STEPPERS_OFF      // 探针时关闭所有步进电机（除了需要保持位置的）
//#define DELAY_BEFORE_PROBING 200  // （毫秒）防止振动触发压电传感器

// 对于探针，要求最小喷嘴和/或床温度
//#define PREHEAT_BEFORE_PROBING
#if ENABLED(PREHEAT_BEFORE_PROBING)
  #define PROBING_NOZZLE_TEMP 120   // （摄氏度）目前仅适用于E0
  #define PROBING_BED_TEMP     50
#endif

// 对于反转步进使能引脚（低电平）使用0，对于非反转（高电平）使用1
//：{ 0:'低', 1:'高' }
#define X_ENABLE_ON 0
#define Y_ENABLE_ON 0
#define Z_ENABLE_ON 0
#define E_ENABLE_ON 0 // 对于所有挤出机
//#define I_ENABLE_ON 0
//#define J_ENABLE_ON 0
//#define K_ENABLE_ON 0
//#define U_ENABLE_ON 0
//#define V_ENABLE_ON 0
//#define W_ENABLE_ON 0

// 立即关闭轴步进电机，当它们不进行步进时。
// 警告：当电机关闭时，可能会导致失去位置准确性！
//#define DISABLE_X
//#define DISABLE_Y
//#define DISABLE_Z
//#define DISABLE_I
//#define DISABLE_J
//#define DISABLE_K
//#define DISABLE_U
//#define DISABLE_V
//#define DISABLE_W

// 关闭显示器闪烁，以警告可能的准确性降低
//#define DISABLE_REDUCED_ACCURACY_WARNING

// @section extruder

//#define DISABLE_E               // 不使用挤出机时禁用挤出机
#define DISABLE_OTHER_EXTRUDERS   // 仅保持活动挤出机启用

// @section motion

// 反向步进方向。如果某个轴向错误移动，请更改（或反转电机连接器）。
#define INVERT_X_DIR true
#define INVERT_Y_DIR false
#define INVERT_Z_DIR false
//#define INVERT_I_DIR false
//#define INVERT_J_DIR false
//#define INVERT_K_DIR false
//#define INVERT_U_DIR false
//#define INVERT_V_DIR false
//#define INVERT_W_DIR false

//采用key_configuration_parameters.h的定义优先覆盖
#if defined(INVERT_X_DIR_Key) && defined(INVERT_Y_DIR_Key) && defined(INVERT_Z_DIR_Key)
  #undef INVERT_X_DIR
  #define INVERT_X_DIR INVERT_X_DIR_Key
  #undef INVERT_Y_DIR
  #define INVERT_Y_DIR INVERT_Y_DIR_Key
  #undef INVERT_Z_DIR
  #define INVERT_Z_DIR INVERT_Z_DIR_Key
#elif !defined(INVERT_X_DIR_Key) && !defined(INVERT_Y_DIR_Key) && !defined(INVERT_Z_DIR_Key)
  // 不执行任何操作
#else
  #error "INVERT_X_DIR_Key、INVERT_Y_DIR_Key 和 INVERT_Z_DIR_Key 必须全部定义或全部不定义"
#endif


// @section extruder

// 对于直接驱动挤出机v9，设置为true；对于齿轮挤出机，设置为false。
#define INVERT_E0_DIR false
#define INVERT_E1_DIR false
#define INVERT_E2_DIR false
#define INVERT_E3_DIR false
#define INVERT_E4_DIR false
#define INVERT_E5_DIR false
#define INVERT_E6_DIR false
#define INVERT_E7_DIR false

// @section homing

//#define NO_MOTION_BEFORE_HOMING // 在所有轴进行回零之前禁止移动。还启用HOME_AFTER_DEACTIVATE以提高安全性。
#define HOME_AFTER_DEACTIVATE   // 打开步进器停用后需要重新回零。还启用NO_MOTION_BEFORE_HOMING以提高安全性。

/**
 * 如果在禁用步进器时Z轴自行移动，请设置Z_IDLE_HEIGHT。
 *  - 如果喷嘴掉落到床上，请使用较低的值（例如Z_MIN_POS）。
 *  - 如果床下降，远离喷嘴，请使用较大的值（例如Z_MAX_POS）。
 */
//#define Z_IDLE_HEIGHT Z_HOME_POS

//#define Z_CLEARANCE_FOR_HOMING  4 // （毫米）回零（G28）之前的最小Z高度，用于床上方的Z间隙，夹具等...
                                    // 请确保在Z_MAX_POS上方有足够的间隙，以防止磨损。

//#define Z_AFTER_HOMING         10 // （毫米）回零后要移动到的高度（如果已回零）

// 回零开关方向；1=MAX，-1=MIN
//：[-1,1]
#define X_HOME_DIR -1
#define Y_HOME_DIR -1
#define Z_HOME_DIR -1
//#define I_HOME_DIR -1
//#define J_HOME_DIR -1
//#define K_HOME_DIR -1
//#define U_HOME_DIR -1
//#define V_HOME_DIR -1
//#define W_HOME_DIR -1

// @section geometry

// 可打印区域的大小
#define X_BED_SIZE 170
#define Y_BED_SIZE 180

// 回零后的旅行限制（线性=mm，旋转=°），对应于端点位置。
#define X_MIN_POS 0
#define Y_MIN_POS 0
#define Z_MIN_POS 0
#define X_MAX_POS X_BED_SIZE
#define Y_MAX_POS Y_BED_SIZE
#define Z_MAX_POS 130
//#define I_MIN_POS 0
//#define I_MAX_POS 50
//#define J_MIN_POS 0
//#define J_MAX_POS 50
//#define K_MIN_POS 0
//#define K_MAX_POS 50
//#define U_MIN_POS 0
//#define U_MAX_POS 50
//#define V_MIN_POS 0
//#define V_MAX_POS 50
//#define W_MIN_POS 0
//#define W_MAX_POS 50

//采用key_configuration_parameters.h的定义优先覆盖
#if defined(Printable_Area_X) && defined(Printable_Area_Y) && defined(Printable_Area_Z)
  #undef X_BED_SIZE
  #define X_BED_SIZE Printable_Area_X
  #undef Y_BED_SIZE
  #define Y_BED_SIZE Printable_Area_Y
  #undef Z_MAX_POS
  #define Z_MAX_POS Printable_Area_Z
#elif !defined(Printable_Area_X) && !defined(Printable_Area_Y) && !defined(Printable_Area_Z)
  // 不执行任何操作
#else
  #error "Printable_Area_X、Printable_Area_Y 和 Printable_Area_Z 必须全部定义或全部不定义"
#endif


/**
 * 软件端点
 *
 * - 防止超出设置的机器边界。
 * - 如果需要，可以禁用单个轴。
 * - X和Y仅适用于直角坐标机器人。
 * - 使用“M211”打开/关闭软件端点或报告当前状态
 */

// 最小软件端点限制在最小坐标边界内的移动
#define MIN_SOFTWARE_ENDSTOPS
#if ENABLED(MIN_SOFTWARE_ENDSTOPS)
  #define MIN_SOFTWARE_ENDSTOP_X
  #define MIN_SOFTWARE_ENDSTOP_Y
  #define MIN_SOFTWARE_ENDSTOP_Z
  #define MIN_SOFTWARE_ENDSTOP_I
  #define MIN_SOFTWARE_ENDSTOP_J
  #define MIN_SOFTWARE_ENDSTOP_K
  #define MIN_SOFTWARE_ENDSTOP_U
  #define MIN_SOFTWARE_ENDSTOP_V
  #define MIN_SOFTWARE_ENDSTOP_W
#endif

// 最大软件端点限制在最大坐标边界内的移动
#define MAX_SOFTWARE_ENDSTOPS
#if ENABLED(MAX_SOFTWARE_ENDSTOPS)
  #define MAX_SOFTWARE_ENDSTOP_X
  #define MAX_SOFTWARE_ENDSTOP_Y
  #define MAX_SOFTWARE_ENDSTOP_Z
  #define MAX_SOFTWARE_ENDSTOP_I
  #define MAX_SOFTWARE_ENDSTOP_J
  #define MAX_SOFTWARE_ENDSTOP_K
  #define MAX_SOFTWARE_ENDSTOP_U
  #define MAX_SOFTWARE_ENDSTOP_V
  #define MAX_SOFTWARE_ENDSTOP_W
#endif

#if ANY(MIN_SOFTWARE_ENDSTOPS, MAX_SOFTWARE_ENDSTOPS)
  #define SOFT_ENDSTOPS_MENU_ITEM  // 从LCD启用/禁用软件端点
#endif

/**
 * 耗材剩余传感器
 * 机械或光电限位开关用于检测丝材是否存在。
 *
 * 重要：只有当Marlin知道正在运行打印作业时，才会触发运行。
 * 当：
 *  1. 从M24启动介质运行打印作业。
 *  2. 使用M75启动打印作业计时器。
 *  3. 打开加热器并启用PRINTJOB_TIMER_AUTOSTART。
 *
 * 基于RAMPS的板使用SERVO3_PIN作为第一个剩余传感器。
 * 对于其他板，您可能需要定义FIL_RUNOUT_PIN，FIL_RUNOUT2_PIN等。
 */
#define FILAMENT_RUNOUT_SENSOR

//采用key_configuration_parameters.h的定义优先覆盖
#ifdef FILAMENT_RUNOUT_SENSOR_Key
    #if FILAMENT_RUNOUT_SENSOR_Key
        #define FILAMENT_RUNOUT_SENSOR
    #else
        #undef FILAMENT_RUNOUT_SENSOR
    #endif
#endif

#if ENABLED(FILAMENT_RUNOUT_SENSOR)
  #define FIL_RUNOUT_ENABLED_DEFAULT true // 在启动时启用传感器。使用M412后跟M500覆盖。
  #define NUM_RUNOUT_SENSORS   1          // 传感器的数量，每个挤出机最多一个。为每个定义一个FIL_RUNOUT#_PIN。

  #define FIL_RUNOUT_STATE     HIGH        // 表示丝材不存在的引脚状态。
  #define FIL_RUNOUT_PULLUP               // 使用内部上拉电阻用于丝材剩余引脚。
  //#define FIL_RUNOUT_PULLDOWN           // 使用内部下拉电阻用于丝材剩余引脚。
  //#define WATCH_ALL_RUNOUT_SENSORS      // 在任何触发传感器上执行剩余脚本，而不仅适用于活动挤出机。
                                          // 对于混合挤出机，这是自动启用的。

  // 如果剩余传感器不同，请单独覆盖
  //#define FIL_RUNOUT1_STATE LOW
  //#define FIL_RUNOUT1_PULLUP
  //#define FIL_RUNOUT1_PULLDOWN

  //#define FIL_RUNOUT2_STATE LOW
  //#define FIL_RUNOUT2_PULLUP
  //#define FIL_RUNOUT2_PULLDOWN

  //#define FIL_RUNOUT3_STATE LOW
  //#define FIL_RUNOUT3_PULLUP
  //#define FIL_RUNOUT3_PULLDOWN

  //#define FIL_RUNOUT4_STATE LOW
  //#define FIL_RUNOUT4_PULLUP
  //#define FIL_RUNOUT4_PULLDOWN

  //#define FIL_RUNOUT5_STATE LOW
  //#define FIL_RUNOUT5_PULLUP
  //#define FIL_RUNOUT5_PULLDOWN

  //#define FIL_RUNOUT6_STATE LOW
  //#define FIL_RUNOUT6_PULLUP
  //#define FIL_RUNOUT6_PULLDOWN

  //#define FIL_RUNOUT7_STATE LOW
  //#define FIL_RUNOUT7_PULLUP
  //#define FIL_RUNOUT7_PULLDOWN

  //#define FIL_RUNOUT8_STATE LOW
  //#define FIL_RUNOUT8_PULLUP
  //#define FIL_RUNOUT8_PULLDOWN

  // 在剩余被检测到之后执行的命令。
  // 使用%c占位符来执行命令中的当前工具（例如，"M600 T%c"）。
  // 注意：“M412 H1”后，主机处理剩余，此脚本不适用。
  #define FILAMENT_RUNOUT_SCRIPT "M600"

  // 在检测到剩余后，继续打印此长度的丝材
  // 执行剩余脚本之前。对于位于馈送管末端的传感器很有用。
  // 每个传感器需要4个字节的SRAM，外加4个字节的开销。
  //#define FILAMENT_RUNOUT_DISTANCE_MM 25

  #ifdef FILAMENT_RUNOUT_DISTANCE_MM
    // 启用此选项以使用切换运动期间切换剩余引脚的编码盘
    // （请确保FILAMENT_RUNOUT_DISTANCE_MM足够大，以避免误报）。
    //#define FILAMENT_MOTION_SENSOR

    #if ENABLED(FILAMENT_MOTION_SENSOR)
      //#define FILAMENT_SWITCH_AND_MOTION
      #if ENABLED(FILAMENT_SWITCH_AND_MOTION)
        #define NUM_MOTION_SENSORS   1          // 传感器的数量，每个挤出机最多一个。为每个定义一个FIL_MOTION#_PIN。

        // 如果运动传感器不同，请单独覆盖
        //#define FIL_MOTION1_PIN    -1

        //#define FIL_MOTION1_STATE LOW
        //#define FIL_MOTION1_PULLUP
        //#define FIL_MOTION1_PULLDOWN

        //#define FIL_MOTION2_STATE LOW
        //#define FIL_MOTION2_PULLUP
        //#define FIL_MOTION2_PULLDOWN

        //#define FIL_MOTION3_STATE LOW
        //#define FIL_MOTION3_PULLUP
        //#define FIL_MOTION3_PULLDOWN

        //#define FIL_MOTION4_STATE LOW
        //#define FIL_MOTION4_PULLUP
        //#define FIL_MOTION4_PULLDOWN

        //#define FIL_MOTION5_STATE LOW
        //#define FIL_MOTION5_PULLUP
        //#define FIL_MOTION5_PULLDOWN

        //#define FIL_MOTION6_STATE LOW
        //#define FIL_MOTION6_PULLUP
        //#define FIL_MOTION6_PULLDOWN

        //#define FIL_MOTION7_STATE LOW
        //#define FIL_MOTION7_PULLUP
        //#define FIL_MOTION7_PULLDOWN

        //#define FIL_MOTION8_STATE LOW
        //#define FIL_MOTION8_PULLUP
        //#define FIL_MOTION8_PULLDOWN
      #endif
    #endif
  #endif
#endif

//===========================================================================
//=============================== 床平整校准 ==============================
//===========================================================================
// @section calibrate

/**
 * 选择下面的选项之一以启用 G29 床平整校准。根据选择，G29 的参数和行为将发生变化。
 *
 * 如果使用探针进行 Z 轴归位，请同时启用 Z_SAFE_HOMING！
 *
 * - AUTO_BED_LEVELING_3POINT
 *   探测床上的三个任意点（不共线）
 *   指定这三个点的 XY 坐标
 *   结果是一个倾斜的平面，适用于平整的床
 *
 * - AUTO_BED_LEVELING_LINEAR
 *   探测网格中的多个点
 *   指定矩形区域和采样点的密度
 *   结果是一个倾斜的平面，适用于平整的床
 *
 * - AUTO_BED_LEVELING_BILINEAR
 *   探测网格中的多个点
 *   指定矩形区域和采样点的密度
 *   结果是一个网格，适用于大型或不平整的床
 *
 * - AUTO_BED_LEVELING_UBL（统一床平整）
 *   综合其他系统的特点和优势的床平整系统。UBL 还包括集成网格生成、网格验证和网格编辑系统。
 *
 * - MESH_BED_LEVELING
 *   手动探测网格
 *   结果是一个网格，适用于大型或不平整的床（见 BILINEAR）
 *   对于没有探针的机器，网格床平整提供了一种按步骤进行平整的方法，因此您可以在每个网格点手动调整 Z 高度。
 *   使用 LCD 控制器时，该过程将逐步指导。
 */
//#define AUTO_BED_LEVELING_3POINT
//#define AUTO_BED_LEVELING_LINEAR
#define AUTO_BED_LEVELING_BILINEAR
//#define AUTO_BED_LEVELING_UBL
//#define MESH_BED_LEVELING

/**
 * 通常情况下，G28 完成后会禁用平整校准。启用下面的选项之一以恢复先前的平整状态或始终在 G28 后立即启用平整校准。
 */
#define RESTORE_LEVELING_AFTER_G28
//#define ENABLE_LEVELING_AFTER_G28

/**
 * 自动平整校准需要预热
 */
//#define PREHEAT_BEFORE_LEVELING
#if ENABLED(PREHEAT_BEFORE_LEVELING)
  #define LEVELING_NOZZLE_TEMP 120   // (°C) 目前仅适用于 E0
  #define LEVELING_BED_TEMP     50
#endif

/**
 * 床距离传感器
 *
 * 使用 0.01mm 的精度测量床到喷嘴的距离。
 * 有关此传感器的信息，请访问 https://github.com/markniu/Bed_Distance_sensor
 * 使用 I2C 端口，因此需要 I2C 库 markyue/Panda_SoftMasterI2C。
 */
//#define BD_SENSOR

/**
 * 启用对 G28、G29、M48 等的详细日志记录。
 * 使用 'M111 S32' 命令打开。
 * 注意：需要大量的 PROGMEM！
 */
//#define DEBUG_LEVELING_FEATURE

#if ANY(MESH_BED_LEVELING, AUTO_BED_LEVELING_UBL, PROBE_MANUALLY)
  // 设置手动调整开始时的高度
  #define MANUAL_PROBE_START_Z 0.2  // (mm) 注释掉以使用上次测量的高度
#endif

#if ANY(MESH_BED_LEVELING, AUTO_BED_LEVELING_BILINEAR, AUTO_BED_LEVELING_UBL)
  /**
   * 逐渐减小平整校准的修正，直到达到设定的高度，
   * 此时移动将与机器的 XY 平面平行。
   * 可以使用 M420 Z<height> 设置高度。
   */
  #define ENABLE_LEVELING_FADE_HEIGHT
  #if ENABLED(ENABLE_LEVELING_FADE_HEIGHT)
    #define DEFAULT_LEVELING_FADE_HEIGHT 10.0 // (mm) 默认的减小高度。
  #endif

  /**
   * 添加 Z 偏移量（M424 Z），适用于计划器级别的所有移动。
   * 此 Z 偏移量将在 G29 中自动设置为中值。
   */
  //#define GLOBAL_MESH_Z_OFFSET

  /**
   * 对于笛卡尔机器，不要将移动分割为网格边界，
   * 而是将移动分割为短线段，如 Delta 一样。
   * 这样可以更好地跟踪床的轮廓，而不是从边到边的直线移动。
   */
  #define SEGMENT_LEVELED_MOVES
  #define LEVELED_SEGMENT_LENGTH 5.0 // (mm) 所有线段的长度（最后一个除外）

  /**
   * 启用 G26 网格验证工具。
   */
  //G26 命令用于验证网格矫正的准确性。它通过在整个打印床上打印单层图案，清楚地显示每个网格点的定义准确性。这样，您就可以确定网格中哪些区域不够完美，以及需要调整每个网格点多少。您可以使用 G26 命令的多种选项来获得合理的结果。
  #define G26_MESH_VALIDATION
  #if ENABLED(G26_MESH_VALIDATION)
    #define MESH_TEST_NOZZLE_SIZE    0.4  // (mm) 主喷嘴直径。
    #define MESH_TEST_LAYER_HEIGHT   0.2  // (mm) G26 的默认层高。
    #define MESH_TEST_HOTEND_TEMP  205    // (°C) G26 的默认喷嘴温度。
    #define MESH_TEST_BED_TEMP      60    // (°C) G26 的默认床温度。
    #define G26_XY_FEEDRATE         20    // (mm/s) G26 XY 移动的进给速度。
    #define G26_XY_FEEDRATE_TRAVEL 100    // (mm/s) G26 XY 行程移动的进给速度。
    #define G26_RETRACT_MULTIPLIER   1.0  // 网格测试元素之间默认使用的 G26 Q（回抽）。
  #endif

#endif

#if ANY(AUTO_BED_LEVELING_LINEAR, AUTO_BED_LEVELING_BILINEAR)

  // 设置每个维度的网格点数。
  #define GRID_MAX_POINTS_X 5
  #define GRID_MAX_POINTS_Y GRID_MAX_POINTS_X

  // 沿 Y 轴探测，每列后进 X
  //#define PROBE_Y_FIRST

  #if ENABLED(AUTO_BED_LEVELING_BILINEAR)

    // 超出探测网格后，是否继续斜面？
    // 默认是保持最近边沿的高度。
    #define EXTRAPOLATE_BEYOND_GRID

    //
    // 通过 Catmull-Rom 方法对网格进行细分。
    // 合成中间点以生成更详细的网格。
    //
    #define ABL_BILINEAR_SUBDIVISION
    #if ENABLED(ABL_BILINEAR_SUBDIVISION)
      // 探测点之间的细分数
      #define BILINEAR_SUBDIVISIONS 3
    #endif

  #endif

#elif ENABLED(AUTO_BED_LEVELING_UBL)

  //===========================================================================
  //========================= 统一床平整 ============================
  //===========================================================================

  //#define MESH_EDIT_GFX_OVERLAY   // 编辑网格时显示图形叠加

  #define MESH_INSET 1              // 将网格边界设置为床的内部区域
  #define GRID_MAX_POINTS_X 10      // 每个轴上不要超过 15 个点，实现受限。
  #define GRID_MAX_POINTS_Y GRID_MAX_POINTS_X

  //#define UBL_HILBERT_CURVE       // 在探测多个点时使用 Hilbert 分布，以减少移动

  //#define UBL_TILT_ON_MESH_POINTS         // 使用 G29 J 中最近的网格点进行更好的 Z 参考
  //#define UBL_TILT_ON_MESH_POINTS_3POINT  // 使用 G29 J0（3点）中最近的网格点

  #define UBL_MESH_EDIT_MOVES_Z     // 有经验的用户更喜欢喷嘴不移动
  #define UBL_SAVE_ACTIVE_ON_M500   // 在 M500 上将当前活动网格保存在当前槽中

  //#define UBL_Z_RAISE_WHEN_OFF_MESH 2.5 // 当喷嘴离开网格时，使用该值作为 Z 高度校正值。

  //#define UBL_MESH_WIZARD         // 连续运行几个命令，以获得完整的网格

  /**
   * 探测不允许在障碍物的位置进行。
   */
  //#define AVOID_OBSTACLES
  #if ENABLED(AVOID_OBSTACLES)
    #define CLIP_W  23  // 夹床的宽度，应该比其物理尺寸多几毫米
    #define CLIP_H  14  // 夹床的高度，应该比其物理尺寸多几毫米

    // 障碍物矩形定义为 { X1, Y1, X2, Y2 }
    #define OBSTACLE1 { (X_BED_SIZE) / 4     - (CLIP_W) / 2,                       0, (X_BED_SIZE) / 4     + (CLIP_W) / 2, CLIP_H }
    #define OBSTACLE2 { (X_BED_SIZE) * 3 / 4 - (CLIP_W) / 2,                       0, (X_BED_SIZE) * 3 / 4 + (CLIP_W) / 2, CLIP_H }
    #define OBSTACLE3 { (X_BED_SIZE) / 4     - (CLIP_W) / 2, (Y_BED_SIZE) - (CLIP_H), (X_BED_SIZE) / 4     + (CLIP_W) / 2, Y_BED_SIZE }
    #define OBSTACLE4 { (X_BED_SIZE) * 3 / 4 - (CLIP_W) / 2, (Y_BED_SIZE) - (CLIP_H), (X_BED_SIZE) * 3 / 4 + (CLIP_W) / 2, Y_BED_SIZE }

    // 探测网格必须在 G29 J 中进行缩进。这是可以接受的，因为它仅用于计算网格本身的线性转换。
    #define G29J_MESH_TILT_MARGIN ((CLIP_H) + 1)
  #endif

#elif ENABLED(MESH_BED_LEVELING)

  //===========================================================================
  //=================================== 网格 ==================================
  //===========================================================================

  #define MESH_INSET 10          // 将网格边界设置为床的内部区域
  #define GRID_MAX_POINTS_X 3    // 每个轴上不要超过 7 个点，实现受限。
  #define GRID_MAX_POINTS_Y GRID_MAX_POINTS_X

  //#define MESH_G28_REST_ORIGIN // 在归位所有轴（'G28' 或 'G28 XYZ'）后，将 Z 重置为 Z_MIN_POS

#endif // BED_LEVELING

/**
 * 添加一个床平整子菜单，适用于 ABL 或 MBL。
 * 如果启用了手动探测，则包括一个引导过程。
 */
#define LCD_BED_LEVELING

#if ENABLED(LCD_BED_LEVELING)
  #define MESH_EDIT_Z_STEP  0.025 // (mm) 手动探测 Z 轴时的步长。
  #define LCD_PROBE_Z_RANGE 4     // (mm) 围绕 Z_MIN_POS 居中的 Z 范围，用于 LCD Z 调整
  #define MESH_EDIT_MENU        // 添加一个菜单来编辑网格点
#endif

// 添加一个菜单项，以在手动调整床时在床角之间移动
#define LCD_BED_TRAMMING

#if ENABLED(LCD_BED_TRAMMING)
  #define BED_TRAMMING_INSET_LFRB { 30, 30, 30, 30 } // (mm) 左、前、右、后的缩进
  #define BED_TRAMMING_HEIGHT      0.0        // (mm) 三点调平时喷嘴的 Z 高度
  #define BED_TRAMMING_Z_HOP       4.0        // (mm) 调平点之间喷嘴的 Z 高度
  #define BED_TRAMMING_INCLUDE_CENTER         // 在最后一个角之后移动到中心
  //#define BED_TRAMMING_USE_PROBE
  #if ENABLED(BED_TRAMMING_USE_PROBE)
    #define BED_TRAMMING_PROBE_TOLERANCE 0.1  // (mm)
    #define BED_TRAMMING_VERIFY_RAISED        // 调整后触发探针后，重新探针验证
    //#define BED_TRAMMING_AUDIO_FEEDBACK
  #endif

  /**
   * 底平调整顺序
   *
   * 设置 2 个或 4 个点。当给出 2 个点时，第 3 个点是相对边的中心。
   *
   *  LF  左前    RF  右前
   *  LB  左后    RB  右后
   *
   * 示例：
   *
   *      默认        {LF,RB,LB,RF}         {LF,RF}           {LB,LF}
   *  LB --------- RB   LB --------- RB    LB --------- RB   LB --------- RB
   *  |  4       3  |   | 3         2 |    |     <3>     |   | 1           |
   *  |             |   |             |    |             |   |          <3>|
   *  |  1       2  |   | 1         4 |    | 1         2 |   | 2           |
   *  LF --------- RF   LF --------- RF    LF --------- RF   LF --------- RF
   */
  #define BED_TRAMMING_LEVELING_ORDER { LF, RF, RB, LB }
#endif

/**
 * 在 G29 探测结束后执行的命令。
 * 有助于缩进或将 Z 探针移出路线。
 */
//#define Z_PROBE_END_SCRIPT "G1 Z10 F12000\nG1 X15 Y330\nG1 Z0.5\nG1 Z10"

// @section homing

// 床的中心在 (X=0, Y=0)
//#define BED_CENTER_AT_0_0

// 手动设置归位位置。对于自动设置，请将这些定义为空。
// 对于 DELTA，这是笛卡尔打印体积的顶部中心。
//#define MANUAL_X_HOME_POS 0
//#define MANUAL_Y_HOME_POS 0
//#define MANUAL_Z_HOME_POS 0
//#define MANUAL_I_HOME_POS 0
//#define MANUAL_J_HOME_POS 0
//#define MANUAL_K_HOME_POS 0
//#define MANUAL_U_HOME_POS 0
//#define MANUAL_V_HOME_POS 0
//#define MANUAL_W_HOME_POS 0

/**
 * 使用“Z 安全归位”避免在床区域之外的位置进行归位。
 *
 * - 在 Z 归位之前，将 Z 探针（或喷嘴）移动到定义的 XY 点。
 * - 仅在 XY 位置已知并可信任的情况下允许 Z 归位。
 * - 如果步进驱动器休眠，可能需要再次进行 XY 归位，然后才进行 Z 归位。
 */
#define Z_SAFE_HOMING

#if ENABLED(Z_SAFE_HOMING)
  #define Z_SAFE_HOMING_X_POINT X_CENTER  // Z 归位的 X 点
  #define Z_SAFE_HOMING_Y_POINT Y_CENTER  // Z 归位的 Y 点
  //#define Z_SAFE_HOMING_POINT_ABSOLUTE  // 在 Z 归位位置上忽略 HOME_OFFSET（M206）
#endif

// 归位速度（线性=mm/min，旋转=°/min）
#define HOMING_FEEDRATE_MM_M { (20*60), (20*60), (4*60) }

// 验证归位终止开关是否触发
#define VALIDATE_HOMING_ENDSTOPS

// @section calibrate

/**
 * 床倾斜补偿
 *
 * 此功能可以校正 XYZ 轴的错位。
 *
 * 执行以下步骤以获取 XY 平面上的床倾斜：
 *  1. 打印一个测试正方形（例如，https://www.thingiverse.com/thing:2563185）
 *  2. 对于 XY_DIAG_AC，测量对角线 A 到 C
 *  3. 对于 XY_DIAG_BD，测量对角线 B 到 D
 *  4. 对于 XY_SIDE_AD，测量边 A 到 D
 *
 * Marlin 将根据这些测量自动计算错位因子。
 * 也可以手动计算和设置错位因子：
 *
 *  - 计算 AB     : SQRT(2*AC*AC+2*BD*BD-4*AD*AD)/2
 *  - XY_SKEW_FACTOR : TAN(PI/2-ACOS((AC*AC-AB*AB-AD*AD)/(2*AB*AD)))
 *
 * 如果需要，按照相同的步骤计算 XZ 和 YZ 的错位。
 * 使用以下图表作为参考：
 *
 *    Y                     Z                     Z
 *    ^     B-------C       ^     B-------C       ^     B-------C
 *    |    /       /        |    /       /        |    /       /
 *    |   /       /         |   /       /         |   /       /
 *    |  A-------D          |  A-------D          |  A-------D
 *    +-------------->X     +-------------->X     +-------------->Y
 *     XY_SKEW_FACTOR        XZ_SKEW_FACTOR        YZ_SKEW_FACTOR
 */
//#define SKEW_CORRECTION

#if ENABLED(SKEW_CORRECTION)
  // 在此处输入所有长度测量：
  #define XY_DIAG_AC 282.8427124746
  #define XY_DIAG_BD 282.8427124746
  #define XY_SIDE_AD 200

  // 或者，直接设置 XY 倾斜因子：
  //#define XY_SKEW_FACTOR 0.0

  //#define SKEW_CORRECTION_FOR_Z
  #if ENABLED(SKEW_CORRECTION_FOR_Z)
    #define XZ_DIAG_AC 282.8427124746
    #define XZ_DIAG_BD 282.8427124746
    #define YZ_DIAG_AC 282.8427124746
    #define YZ_DIAG_BD 282.8427124746
    #define YZ_SIDE_AD 200

    // 或者，直接设置 Z 倾斜因子：
    //#define XZ_SKEW_FACTOR 0.0
    //#define YZ_SKEW_FACTOR 0.0
  #endif

  // 启用此选项以使用 M852 在运行时设置错位
  //#define SKEW_CORRECTION_GCODE
#endif

//=============================================================================
//============================= 附加功能 ===========================
//=============================================================================

// @section eeprom

/**
 * EEPROM
 *
 * 用于在重新启动时保留可配置设置的持久存储。
 *
 *   M500 - 将设置存储到 EEPROM。
 *   M501 - 从 EEPROM 读取设置。（即，放弃未保存的更改）
 *   M502 - 将设置还原为“工厂”默认值。（随后使用 M500 初始化 EEPROM。）
 */
#define EEPROM_SETTINGS       // 使用 M500 和 M501 进行持久存储
//#define DISABLE_M503        // 禁用以节省约2700字节的闪存。发布时请禁用！
#define EEPROM_CHITCHAT       // 在 EEPROM 命令上提供反馈。禁用以节省 PROGMEM。
#define EEPROM_BOOT_SILENT    // 仅在第一次加载期间保持 M503 安静，仅提供错误信息
#if ENABLED(EEPROM_SETTINGS)
  #define EEPROM_AUTO_INIT    // 在发生任何错误时自动初始化 EEPROM。
  //#define EEPROM_INIT_NOW   // 在新构建后的第一次启动时初始化 EEPROM。
#endif

// @section host

//
// 主机保活功能
//
// 当启用时，Marlin 将定期向主机发送繁忙状态消息，
// 表示无法接受命令。
//
#define HOST_KEEPALIVE_FEATURE        // 如果主机不喜欢保活消息，请禁用此选项
#define DEFAULT_KEEPALIVE_INTERVAL 2  // “繁忙”消息之间的秒数。使用 M113 设置。
#define BUSY_WHILE_HEATING            // 一些主机要求即使在加热过程中也发送“繁忙”消息

// @section units

//
// G20/G21 英寸模式支持
//
//#define INCH_MODE_SUPPORT

//
// M149 设置温度单位支持
//
//#define TEMPERATURE_UNITS_SUPPORT

// @section temperature

//
// 预热常数 - 最多支持 10 个而无需更改
//
#define PREHEAT_1_LABEL       "PLA"
#define PREHEAT_1_TEMP_HOTEND 185
#define PREHEAT_1_TEMP_BED     45
#define PREHEAT_1_TEMP_CHAMBER 35
#define PREHEAT_1_FAN_SPEED   255 // 0 到 255 的值

#define PREHEAT_2_LABEL       "ABS"
#define PREHEAT_2_TEMP_HOTEND 240
#define PREHEAT_2_TEMP_BED    110
#define PREHEAT_2_TEMP_CHAMBER 35
#define PREHEAT_2_FAN_SPEED   255 // 0 到 255 的值

// @section motion

/**
 * 喷嘴停车
 *
 * 在空闲或 G27 时，将喷嘴停在给定的 XYZ 位置上。
 *
 * “P”参数控制应用于 Z 轴的动作：
 *
 *    P0  (默认) 如果 Z 低于停车 Z，则提高喷嘴。
 *    P1  始终提高喷嘴到 Z 停车高度。
 *    P2  将喷嘴提高 Z 停车量，限制为 Z_MAX_POS。
 */
#define NOZZLE_PARK_FEATURE

#if ENABLED(NOZZLE_PARK_FEATURE)
  // 指定停车位置为 { X, Y, Z_raise }
  #define NOZZLE_PARK_POINT { (X_MIN_POS + 10), (Y_MAX_POS - 10), 20 }
  #define NOZZLE_PARK_MOVE          0   // 停车运动：0 = XY 移动，1 = 仅 X，2 = 仅 Y，3 = X 先于 Y，4 = Y 先于 X
  #define NOZZLE_PARK_Z_RAISE_MIN   2   // (mm) 始终将 Z 提高至少这个距离
  #define NOZZLE_PARK_XY_FEEDRATE 100   // (mm/s) X 和 Y 轴进给速度（也用于 delta Z 轴）
  #define NOZZLE_PARK_Z_FEEDRATE    5   // (mm/s) Z 轴进给速度（不适用于 delta 打印机）
#endif

/**
 * 清洁喷嘴功能
 *
 * 添加 G12 命令以执行喷嘴清洁过程。
 *
 * 参数：
 *   P  模式
 *   S  次数 / 重复
 *   T  三角形（仅 P1）
 *
 * 模式：
 *   P0  直线（默认）。此过程需要固定床位于固定位置的海绵状材料。
 *       “S” 指定在起始 / 结束点之间的往返运动（即，前后运动）的次数。
 *
 *   P1  在 (X0, Y0) 和 (X1, Y1) 之间的锯齿状模式，"T" 指定 zig-zag 三角形的数量，
 *       "S" 定义往返运动的次数。锯齿状模式将在较窄的尺寸中执行。
 *       例如，“G12 P1 S1 T3” 将执行以下操作：
 *
 *          --
 *         |  (X0, Y1) |     /\        /\        /\     | (X1, Y1)
 *         |           |    /  \      /  \      /  \    |
 *       A |           |   /    \    /    \    /    \   |
 *         |           |  /      \  /      \  /      \  |
 *         |  (X0, Y0) | /        \/        \/        \ | (X1, Y0)
 *          --         +--------------------------------+
 *                       |________|_________|_________|
 *                           T1        T2        T3
 *
 *   P2  圆形模式，中心为 NOZZLE_CLEAN_CIRCLE_MIDDLE。
 *       “R” 指定半径。“S” 指定运动次数。
 *       在开始之前，喷嘴移动到 NOZZLE_CLEAN_START_POINT。
 *
 *   注意事项：结束的 Z 应与开始的 Z 相同。
 */
//#define NOZZLE_CLEAN_FEATURE

#if ENABLED(NOZZLE_CLEAN_FEATURE)
  #define NOZZLE_CLEAN_PATTERN_LINE     // 提供 'G12 P0' - 简单的线性清洁模式
  #define NOZZLE_CLEAN_PATTERN_ZIGZAG   // 提供 'G12 P1' - 锯齿状清洁模式
  #define NOZZLE_CLEAN_PATTERN_CIRCLE   // 提供 'G12 P2' - 圆形清洁模式

  // 在未提供 'P' 的情况下使用的默认模式。上面启用的选项之一。
  #define NOZZLE_CLEAN_DEFAULT_PATTERN 0

  #define NOZZLE_CLEAN_STROKES     12   // 默认模式重复次数

  #if ENABLED(NOZZLE_CLEAN_PATTERN_ZIGZAG)
    #define NOZZLE_CLEAN_TRIANGLES  3   // 默认三角形数量
  #endif

  // 为每个工具指定位置为 { { X, Y, Z }, { X, Y, Z } }
  // 双喷头系统可以使用 { {  -20, (Y_BED_SIZE / 2), (Z_MIN_POS + 1) },  {  420, (Y_BED_SIZE / 2), (Z_MIN_POS + 1) }}
  #define NOZZLE_CLEAN_START_POINT { {  30, 30, (Z_MIN_POS + 1) } }
  #define NOZZLE_CLEAN_END_POINT   { { 100, 60, (Z_MIN_POS + 1) } }

  #if ENABLED(NOZZLE_CLEAN_PATTERN_CIRCLE)
    #define NOZZLE_CLEAN_CIRCLE_RADIUS 6.5                      // (mm) 圆形模式半径
    #define NOZZLE_CLEAN_CIRCLE_FN 10                           // 圆形模式圆的段数
    #define NOZZLE_CLEAN_CIRCLE_MIDDLE NOZZLE_CLEAN_START_POINT // 圆的中心点
  #endif

  // 在清洁后将喷嘴移动到初始位置
  #define NOZZLE_CLEAN_GOBACK

  // 对于总是在门架高度的放置区的冲洗/清洁站（因此没有 Z 移动）
  //#define NOZZLE_CLEAN_NO_Z

  // 对于安装在 X 轴上的冲洗/清洁站
  //#define NOZZLE_CLEAN_NO_Y

  // 清洁时要求最低喷嘴温度
  #define NOZZLE_CLEAN_MIN_TEMP 170
  //#define NOZZLE_CLEAN_HEATUP       // 加热喷嘴而不是跳过擦拭

  // 显式擦拭 G 代码脚本适用于没有参数的 G12。
  //#define WIPE_SEQUENCE_COMMANDS "G1 X-17 Y25 Z10 F4000\nG1 Z1\nM114\nG1 X-17 Y25\nG1 X-17 Y95\nG1 X-17 Y25\nG1 X-17 Y95\nG1 X-17 Y25\nG1 X-17 Y95\nG1 X-17 Y25\nG1 X-17 Y95\nG1 X-17 Y25\nG1 X-17 Y95\nG1 X-17 Y25\nG1 X-17 Y95\nG1 Z15\nM400\nG0 X-10.0 Y-9.0"

#endif

// @section host

/**
 * 打印作业计时器
 *
 * 在 M104/M109/M140/M190/M141/M191 上自动启动和停止打印作业计时器。
 * 只有当床/腔体目标温度低于 BED_MINTEMP/CHAMBER_MINTEMP 时，
 * 打印作业计时器才会停止。
 *
 *   M104（热端，无等待） - 高温 = 无，          低温 = 停止计时器
 *   M109（热端，等待）   - 高温 = 启动计时器，低温 = 停止计时器
 *   M140（床，无等待）   - 高温 = 无，          低温 = 停止计时器
 *   M190（床，等待）      - 高温 = 启动计时器，低温 = 无
 *   M141（腔体，无等待） - 高温 = 无，          低温 = 停止计时器
 *   M191（腔体，等待）    - 高温 = 启动计时器，低温 = 无
 *
 * 可以使用以下命令来控制计时器：
 *
 *   M75 - 启动打印作业计时器
 *   M76 - 暂停打印作业计时器
 *   M77 - 停止打印作业计时器
 */
#define PRINTJOB_TIMER_AUTOSTART

// @section stats

/**
 * 打印计数器
 *
 * 跟踪统计数据，例如：
 *
 *  - 总打印作业数
 *  - 总成功打印作业数
 *  - 总失败打印作业数
 *  - 总打印时间
 *
 * 使用 M78 查看当前统计信息。
 */
#define PRINTCOUNTER
#if ENABLED(PRINTCOUNTER)
  #define PRINTCOUNTER_SAVE_INTERVAL 60 // (分钟) 在打印期间的 EEPROM 保存间隔。值为 0 将在打印结束时保存统计信息。
#endif

// @section security

/**
 * 密码
 *
 * 为打印机设置一个数字密码，可以在以下情况下要求密码：
 *
 *  - 打印机启动时
 *  - 打开“从媒体打印”菜单时
 *  - SD 打印完成或中止时
 *
 * 可以使用以下 G 代码：
 *
 *  M510 - 锁定打印机。除 M511 外，阻止所有命令。
 *  M511 - 解锁打印机。
 *  M512 - 设置、更改和删除密码。
 *
 * 如果忘记密码并被锁定，您需要重新刷写禁用该功能的固件，重置 EEPROM，
 * 并（可选）再次刷写启用该功能的固件。
 */
//#define PASSWORD_FEATURE
#if ENABLED(PASSWORD_FEATURE)
  #define PASSWORD_LENGTH 4                 // (#) 数字的位数（1-9）。建议使用 3 或 4
  #define PASSWORD_ON_STARTUP
  #define PASSWORD_UNLOCK_GCODE             // 使用 M511 P<password> 命令解锁。禁用以防止暴力攻击。
  #define PASSWORD_CHANGE_GCODE             // 使用 M512 P<old> S<new> 更改密码。
  //#define PASSWORD_ON_SD_PRINT_MENU       // 这不会阻止 G 代码运行
  //#define PASSWORD_AFTER_SD_PRINT_END
  //#define PASSWORD_AFTER_SD_PRINT_ABORT
  //#include "Configuration_Secure.h"       // 包含 PASSWORD_DEFAULT_VALUE 的外部文件
#endif

//=============================================================================
//============================= LCD和SD卡支持 ============================
//=============================================================================

// @section interface

/**
 * LCD语言
 *
 * 选择在LCD上显示的语言。可用的语言有：
 *
 *   en, an, bg, ca, cz, da, de, el, el_CY, es, eu, fi, fr, gl, hr, hu, it,
 *   jp_kana, ko_KR, nl, pl, pt, pt_br, ro, ru, sk, sv, tr, uk, vi, zh_CN, zh_TW
 *
 * :{ 'en':'英语', 'an':'阿拉贡语', 'bg':'保加利亚语', 'ca':'加泰罗尼亚语', 'cz':'捷克语', 'da':'丹麦语', 'de':'德语', 'el':'希腊语（希腊）', 'el_CY':'希腊语（塞浦路斯）', 'es':'西班牙语', 'eu':'巴斯克语', 'fi':'芬兰语', 'fr':'法语', 'gl':'加利西亚语', 'hr':'克罗地亚语', 'hu':'匈牙利语', 'it':'意大利语', 'jp_kana':'日语', 'ko_KR':'韩语（南韩）', 'nl':'荷兰语', 'pl':'波兰语', 'pt':'葡萄牙语', 'pt_br':'葡萄牙语（巴西）', 'ro':'罗马尼亚语', 'ru':'俄语', 'sk':'斯洛伐克语', 'sv':'瑞典语', 'tr':'土耳其语', 'uk':'乌克兰语', 'vi':'越南语', 'zh_CN':'中文（简体）', 'zh_TW':'中文（繁体）' }
 */
#define LCD_LANGUAGE zh_CN

/**
 * LCD字符集
 *
 * 注意：此选项不适用于图形显示。
 *
 * 所有基于字符的LCD提供ASCII字符加上以下语言扩展之一：
 *
 *  - JAPANESE ... 最常见的
 *  - WESTERN  ... 带有更多重音字符
 *  - CYRILLIC ... 用于俄语
 *
 * 要确定控制器上安装的语言扩展：
 *
 *  - 使用设置为'test'的LCD_LANGUAGE进行编译和上传
 *  - 单击控制器以查看LCD菜单
 *  - LCD将显示日语、西方语言或西里尔文本
 *
 * 请参阅https://marlinfw.org/docs/development/lcd_language.html
 *
 * :['JAPANESE', 'WESTERN', 'CYRILLIC']
 */
#define DISPLAY_CHARSET_HD44780 JAPANESE

/**
 * 信息屏风格（0：经典，1：Průša）
 *
 * :[0:'经典', 1:'Průša']
 */
#define LCD_INFO_SCREEN_STYLE 0

/**
 * SD卡
 *
 * 默认情况下禁用SD卡支持。如果您的控制器有SD插槽，您必须取消注释以下选项，否则它将无法正常工作。
 */
#define SDSUPPORT

/**
 * SD卡：启用CRC
 *
 * 在SD通信上使用CRC检查和重试。
 */
#define SD_CHECK_AND_RETRY

/**
 * LCD菜单项目
 *
 * 禁用所有菜单，仅显示状态屏幕，或者只删除一些冗余的菜单项目以节省空间。
 */
//#define NO_LCD_MENUS
//#define SLIM_LCD_MENUS

//
// 编码器设置
//
// 此选项覆盖产生一个步骤所需的默认编码器脉冲数。
// 对于高分辨率编码器，应该增加此值。
//
//#define ENCODER_PULSES_PER_STEP 4

//
// 使用此选项覆盖在下一个/上一个菜单项之间移动所需的步骤信号数。
//
//#define ENCODER_STEPS_PER_MENU_ITEM 1

/**
 * 编码器方向选项
 *
 * 首先在两个选项都禁用的情况下测试编码器的行为。
 *
 *  反转值编辑和菜单导航？启用REVERSE_ENCODER_DIRECTION。
 *  仅反转菜单导航？启用REVERSE_MENU_DIRECTION。
 *  仅反转值编辑？启用两个选项。
 */

//
// 此选项在任何地方反转编码器方向。
//
//  如果顺时针使值减小，则设置此选项
//
//#define REVERSE_ENCODER_DIRECTION
//采用key_configuration_parameters.h的定义优先覆盖
#ifdef REVERSE_ENCODER_DIRECTION_key
    #if REVERSE_ENCODER_DIRECTION_key
        #define REVERSE_ENCODER_DIRECTION
    #else
        #undef REVERSE_ENCODER_DIRECTION
    #endif
#endif


//
// 此选项在导航LCD菜单时反转编码器方向。
//
//  如果顺时针通常向下移动，则使其向上移动。
//  如果顺时针通常向上移动，则使其向下移动。
//
//#define REVERSE_MENU_DIRECTION

//
// 此选项在选择屏幕上反转编码器方向。
//
//  如果顺时针通常向左移动，则使其向右移动。
//  如果顺时针通常向右移动，则使其向左移动。
//
//#define REVERSE_SELECT_DIRECTION

//
// 编码器EMI噪声滤波器
//
// 此选项增加编码器采样以过滤由EMI噪声引起的虚假编码器点击。
//
//#define ENCODER_NOISE_FILTER
#if ENABLED(ENCODER_NOISE_FILTER)
  #define ENCODER_SAMPLES 10
#endif

//
// 单独轴归位
//
// 将单独轴归位项（Home X，Home Y和Home Z）添加到LCD菜单中。
//
#define INDIVIDUAL_AXIS_HOMING_MENU
#define INDIVIDUAL_AXIS_HOMING_SUBMENU//将单轴归位作为子菜单

//
// 扬声器/蜂鸣器
//
// 如果您有一个能发出音调的扬声器，请在此处启用它。
// 默认情况下，Marlin假设您有一个固定频率的蜂鸣器。
//
//#define SPEAKER

//
// UI反馈声音的持续时间和频率。
// 将其设置为0以在LCD菜单中禁用音频反馈。
//
// 注意：使用G代码测试音频输出：
//  M300 S<frequency Hz> P<duration ms>
//
//#define LCD_FEEDBACK_FREQUENCY_DURATION_MS 2
//#define LCD_FEEDBACK_FREQUENCY_HZ 5000

//
// 音调队列大小，用于防止蜂鸣声阻塞执行。
// 默认为4，或在此处覆盖。每个条目占用4个字节的SRAM。
//
//#define TONE_QUEUE_LENGTH 4

//
// 启动时要播放的音调序列，以音调（Hz）和持续时间（ms）的对形式。
// 音调之间静音。
//
//#define STARTUP_TUNE { 698, 300, 0, 50, 523, 50, 0, 25, 494, 50, 0, 25, 523, 100, 0, 50, 554, 300, 0, 100, 523, 300 }

//=============================================================================
//======================== LCD / 控制器选择 =========================
//========================   （基于字符的LCD）   =========================
//=============================================================================
// @section lcd

//
// RepRapDiscount智能控制器。
// https://reprap.org/wiki/RepRapDiscount_Smart_Controller
//
// 注意：通常带有白色PCB出售。
//
//#define REPRAP_DISCOUNT_SMART_CONTROLLER

//
// GT2560（YHCB2004）LCD显示屏
//
// 需要Testato、Koepel软件线库和
// Andriy Golovnya的LiquidCrystal_AIP31068库。
//
//#define YHCB2004

//
// 原始RADDS LCD显示+编码器+SD卡读卡器
// https://web.archive.org/web/20200719145306/http://doku.radds.org/dokumentation/lcd-display/
//
//#define RADDS_DISPLAY

//
// ULTIMAKER控制器。
//
//#define ULTIMAKERCONTROLLER

//
// ULTIPANEL，在Thingiverse上看到的。
//
//#define ULTIPANEL

//
// T3P3的PanelOne（通过RAMPS 1.4 AUX2/AUX3）
// https://reprap.org/wiki/PanelOne
//
//#define PANEL_ONE

//
// GADGETS3D G3D LCD/SD控制器
// https://reprap.org/wiki/RAMPS_1.3/1.4_GADGETS3D_Shield_with_Panel
//
// 注意：通常带有蓝色PCB出售。
//
//#define G3D_PANEL

//
// RigidBot Panel V1.0
//
//#define RIGIDBOT_PANEL

//
// Makeboard 3D打印机配件3D打印机Mini Display 1602 Mini Controller
// https://www.aliexpress.com/item/32765887917.html
//
//#define MAKEBOARD_MINI_2_LINE_DISPLAY_1602

//
// ANET和Tronxy 20x4控制器
//
//#define ZONESTAR_LCD            // 需要将ADC_KEYPAD_PIN分配给模拟引脚。
                                  // 这个LCD已知容易受到电气干扰的影响
                                  // 这使显示器变得混乱。按下任意按钮即可清除它。
                                  // 这是一个带有5个模拟按钮的LCD2004显示器。

//
// 通用的16x2、16x4、20x2或20x4基于字符的LCD。
//
//#define ULTRA_LCD

//=============================================================================
//======================== LCD / 控制器选择 ===========================
//=====================   (I2C 和移位寄存器 LCD)   =====================
//=============================================================================

//
// 控制器类型: I2C
//
// 注意: 这些控制器需要安装Arduino的LiquidCrystal_I2C库。更多信息请查看: https://github.com/kiyoshigawa/LiquidCrystal_I2C
//

//
// Elefu RA板控制面板
// https://web.archive.org/web/20140823033947/http://www.elefu.com/index.php?route=product/product&product_id=53
//
//#define RA_CONTROL_PANEL

//
// Sainsmart (YwRobot) LCD显示屏
//
// 这些需要LiquidCrystal_I2C库:
//   https://github.com/MarlinFirmware/New-LiquidCrystal
//   https://github.com/fmalpartida/New-LiquidCrystal/wiki
//
//#define LCD_SAINSMART_I2C_1602
//#define LCD_SAINSMART_I2C_2004

//
// 通用LCM1602 LCD适配器
//
//#define LCM1602

//
// PANELOLU2 LCD，带有状态LED，
// 单独的旋转编码器和点击输入。
//
// 注意: 这个控制器需要Arduino的LiquidTWI2库v1.2.3或更高版本。
// 更多信息请查看: https://github.com/lincomatic/LiquidTWI2
//
// 注意: PANELOLU2编码器点击输入可以直接连接到一个引脚(如果BTN_ENC被定义为!= -1)，
// 或者通过I2C读取(当BTN_ENC == -1)。
//
//#define LCD_I2C_PANELOLU2

//
// Panucatt VIKI LCD，带有状态LED，
// 集成点击和 L/R/U/D 按钮，单独的编码器输入。
//
//#define LCD_I2C_VIKI

//
// 控制器类型: 移位寄存器面板
//

//
// 2线非锁存LCD SR，来自https://github.com/fmalpartida/New-LiquidCrystal/wiki/schematics#user-content-ShiftRegister_connection
// LCD配置: https://reprap.org/wiki/SAV_3D_LCD
//
//#define SAV_3DLCD

//
// 3线带 strobe 的SR LCD，使用74HC4094
// https://github.com/mikeshub/SailfishLCD
// 使用Sailfish的代码
//
//#define FF_INTERFACEBOARD

//
// TFT GLCD面板与Marlin UI
// 面板通过SPI或I2C接口连接到主板。
// 查看 https://github.com/Serhiy-K/TFTGLCDAdapter
//
//#define TFTGLCD_PANEL_SPI
//#define TFTGLCD_PANEL_I2C

//=============================================================================
//=======================   LCD / 控制器选择  =======================
//=========================      (图形LCD)      ========================
//=============================================================================

//
// 控制器类型: 图形128x64 (DOGM)
//
// 重要: 图形显示需要U8glib库!
//      https://github.com/olikraus/U8glib_Arduino
//
// 注意: 如果LCD无响应，可能需要交换插头。
//

//
// RepRapDiscount全图形智能控制器
// https://reprap.org/wiki/RepRapDiscount_Full_Graphic_Smart_Controller
//
#define REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER

//
// K.3D全图形智能控制器
//
//#define K3D_FULL_GRAPHIC_SMART_CONTROLLER

//
// ReprapWorld图形LCD
// https://reprapworld.com/electronics/3d-printer-modules/autonomous-printing/graphical-lcd-screen-v1-0/
//
//#define REPRAPWORLD_GRAPHICAL_LCD

//
// 如果你有Panucatt Devices，请启用以下选项之一
// Viki 2.0 或 mini Viki 带有图形LCD
// https://www.panucatt.com
//
//#define VIKI2
//#define miniVIKI

//
// Alfawise Ex8 打印机LCD，标记为 WYH L12864 COG
//
//#define WYH_L12864

//
// MakerLab Mini Panel 带有图形
// 控制器和SD卡支持 - https://reprap.org/wiki/Mini_panel
//
//#define MINIPANEL

//
// MaKr3d Makr-Panel 带有图形控制器和SD卡支持。
// https://reprap.org/wiki/MaKrPanel
//
//#define MAKRPANEL

//
// Adafruit ST7565 全图形控制器。
// https://github.com/eboston/Adafruit-ST7565-Full-Graphic-Controller/
//
//#define ELB_FULL_GRAPHIC_CONTROLLER

//
// BQ LCD智能控制器，BQ Hephestos 2 和 Witbox 2 默认配备。
//
//#define BQ_LCD_SMART_CONTROLLER

//
// Cartesio 用户界面
// https://web.archive.org/web/20180605050442/http://mauk.cc/webshop/cartesio-shop/electronics/user-interface
//
//#define CARTESIO_UI

//
// 用于带有图形LCD的Melzi卡的LCD
//
//#define LCD_FOR_MELZI

//
// Ultimaker 2打印机的原始Ulticontroller，带有SSD1309 I2C显示屏和编码器
// https://github.com/Ultimaker/Ultimaker2/tree/master/1249_Ulticontroller_Board_(x1)
//
//#define ULTI_CONTROLLER

//
// MKS MINI12864 带有图形控制器和SD卡支持
// https://reprap.org/wiki/MKS_MINI_12864
//
//#define MKS_MINI_12864

//
// MKS MINI12864 V3 是一个 FYSETC_MINI_12864_2_1 的别名。Type A/B. NeoPixel RGB 背光。
//
//#define MKS_MINI_12864_V3

//
// MKS LCD12864A/B 带有图形控制器和SD卡支持。遵循 MKS_MINI_12864 的引脚排列。
// https://www.aliexpress.com/item/33018110072.html
//
//#define MKS_LCD12864A
//#define MKS_LCD12864B

//
// FYSETC 的 MINI12864 图形控制器，带有SD卡支持
// https://wiki.fysetc.com/Mini12864_Panel/
//
//#define FYSETC_MINI_12864_X_X    // Type C/D/E/F. 默认没有可调节的RGB背光
//#define FYSETC_MINI_12864_1_2    // Type C/D/E/F. 简单的RGB背光(始终开启)
//#define FYSETC_MINI_12864_2_0    // Type A/B. 离散的RGB背光
//#define FYSETC_MINI_12864_2_1    // Type A/B. NeoPixel RGB背光
//#define FYSETC_GENERIC_12864_1_1 // 较大的显示屏，基本的开关背光。

//
// BigTreeTech Mini 12864 V1.0 是一个 FYSETC_MINI_12864_2_1 的别名。Type A/B. NeoPixel RGB 背光。
// https://github.com/bigtreetech/MINI-12864/tree/master/mini12864_v1.0
//
//#define BTT_MINI_12864_V1

//
// Creality CR-10 / CR-7 / Ender-3 的原厂显示屏
// https://www.aliexpress.com/item/32833148327.html
//
// 连接到RAMPS和兼容的主板上的EXP1。
//
//#define CR10_STOCKDISPLAY

//
// Ender-2 原厂显示屏，MKS_MINI_12864的一个变种
//
//#define ENDER2_STOCKDISPLAY

//
// ANET 和 Tronxy 图形控制器
//
// Anet 128x64 全图形LCD，带有旋转编码器，用于Anet A6
// 一个RepRapDiscount全图形显示的克隆品，但引脚/连接方式不同(参见pins_ANET_10.h)。启用其中之一。
//
//#define ANET_FULL_GRAPHICS_LCD
//#define ANET_FULL_GRAPHICS_LCD_ALT_WIRING

//
// AZSMZ 12864 LCD 带有SD卡
// https://www.aliexpress.com/item/32837222770.html
//
//#define AZSMZ_12864

//
// Silvergate GLCD 控制器
// https://github.com/android444/Silvergate
//
//#define SILVER_GATE_GLCD_CONTROLLER

//
// eMotion Tech 带有SD卡的LCD
// https://www.reprap-france.com/produit/1234568748-ecran-graphique-128-x-64-points-2-1
//
//#define EMOTION_TECH_LCD

//=============================================================================
//==============================  OLED显示屏  ==============================
//=============================================================================

//
// SSD1306 OLED全图形通用显示屏
//
//#define U8GLIB_SSD1306

//
// SAV OLEd LCD模块，支持SSD1306或SH1106 LCD模块
//
//#define SAV_3DGLCD
#if ENABLED(SAV_3DGLCD)
  #define U8GLIB_SSD1306
  //#define U8GLIB_SH1106
#endif

//
// TinyBoy2 128x64 OLED / 编码器面板
//
//#define OLED_PANEL_TINYBOY2

//
// MKS OLED 1.3" 128×64 全图形控制器
// https://reprap.org/wiki/MKS_12864OLED
//
// 小巧但非常清晰的OLED显示屏
//
//#define MKS_12864OLED          // 使用SH1106控制器 (默认)
//#define MKS_12864OLED_SSD1306  // 使用SSD1306控制器

//
// Zonestar OLED 128×64 全图形控制器
//
//#define ZONESTAR_12864LCD           // 带有ST7920控制器的图形(DOGM)显示屏
//#define ZONESTAR_12864OLED          // 带有SH1106控制器的1.3" OLED (默认)
//#define ZONESTAR_12864OLED_SSD1306  // 带有SSD1306控制器的0.96" OLED

//
// Einstart S OLED SSD1306
//
//#define U8GLIB_SH1106_EINSTART

//
// Overlord OLED显示屏/控制器，带有I2C蜂鸣器和LED灯
//
//#define OVERLORD_OLED

//
// FYSETC OLED 2.42" 128×64 全图形控制器，带有WS2812 RGB
// 您可以在以下地方找到: https://www.aliexpress.com/item/4000345255731.html
//#define FYSETC_242_OLED_12864   // 使用SSD1309控制器

//
// K.3D SSD1309 OLED 2.42" 128×64 全图形控制器
//
//#define K3D_242_OLED_CONTROLLER   // 软件SPI

//=============================================================================
//========================== 可扩展的UI显示屏 ===========================
//=============================================================================

/**
 * DGUS 触摸显示屏，带有DWIN OS。 (选择其中一个)
 *
 * ORIGIN (Marlin DWIN_SET)
 *  - 下载 https://github.com/coldtobi/Marlin_DGUS_Resources
 *  - 将下载的DWIN_SET文件夹复制到SD卡中。
 *  - 产品: https://www.aliexpress.com/item/32993409517.html
 *
 * FYSETC (供应商默认)
 *  - 下载 https://github.com/FYSETC/FYSTLCD-2.0
 *  - 将下载的SCREEN文件夹复制到SD卡中。
 *  - 产品: https://www.aliexpress.com/item/32961471929.html
 *
 * HIPRECY (供应商默认)
 *  - 下载 https://github.com/HiPrecy/Touch-Lcd-LEO
 *  - 将下载的DWIN_SET文件夹复制到SD卡中。
 *
 * MKS (MKS-H43) (供应商默认)
 *  - 下载 https://github.com/makerbase-mks/MKS-H43
 *  - 将下载的DWIN_SET文件夹复制到SD卡中。
 *  - 产品: https://www.aliexpress.com/item/1005002008179262.html
 *
 * RELOADED (T5UID1)
 *  - 下载 https://github.com/Neo2003/DGUS-reloaded/releases
 *  - 将下载的DWIN_SET文件夹复制到SD卡中。
 *
 * IA_CREALITY (T5UID1)
 *  - 下载 https://github.com/InsanityAutomation/Marlin/raw/CrealityDwin_2.0/TM3D_Combined480272_Landscape_V7.7z
 *  - 将下载的DWIN_SET文件夹复制到SD卡中。
 *
 * E3S1PRO (T5UID1)
 *  - 下载 https://github.com/CrealityOfficial/Ender-3S1/archive/3S1_Plus_Screen.zip
 *  - 将下载的DWIN_SET文件夹复制到SD卡中。
 *
 * CREALITY_TOUCH
 *  - CR-6 OEM 触摸屏。带有DWIN显示屏并支持触摸。
 *
 * 使用DGUS显示屏进行闪存操作:
 *  - 使用4KB分配大小将SD卡格式化为FAT32。
 *  - 下载所需的文件，具体取决于您的显示屏类型。
 *  - 将microSD卡插入显示屏的背面。
 *  - 启动显示屏并等待更新完成。
 *
 * :[ 'ORIGIN', 'FYSETC', 'HYPRECY', 'MKS', 'RELOADED', 'IA_CREALITY', 'E3S1PRO', 'CREALITY_TOUCH' ]
 */
//#define DGUS_LCD_UI ORIGIN
#if DGUS_UI_IS(MKS)
  #define USE_MKS_GREEN_UI
#elif DGUS_UI_IS(IA_CREALITY)
  //#define LCD_SCREEN_ROTATE 90          // 纵向模式或800x480显示屏
  //#define IA_CREALITY_BOOT_DELAY 1500   // (毫秒)
#endif

//
// Malyan M200/M300打印机的触摸屏LCD
//
//#define MALYAN_LCD

//
// 用于FTDI EVE (FT800/FT810)显示屏的触摸UI
// 查看Configuration_adv.h以获得所有配置选项。
//
//#define TOUCH_UI_FTDI_EVE

//
// Anycubic Chiron触摸屏
//
//#define ANYCUBIC_LCD_CHIRON

//
// Anycubic i3 Mega触摸屏
//
//#define ANYCUBIC_LCD_I3MEGA
#if ENABLED(ANYCUBIC_LCD_I3MEGA)
  //#define ANYCUBIC_LCD_GCODE_EXT  // 为了与DGUS克隆兼容性，在菜单项中添加 ".gcode"
#endif

//
// Anycubic Vyper触摸屏
//
//#define ANYCUBIC_LCD_VYPER

//
// 320x240 Nextion 2.8" 串行TFT电阻触摸屏 NX3224T028
//
//#define NEXTION_TFT

//
// Escher3D的PanelDue触摸控制器
// http://escher3d.com/pages/order/products/product2.php
//
//#define PANELDUE

//
// 第三方或供应商定制的控制器界面。
// 源码应安装在 'src/lcd/extui' 目录下。
//
//#define EXTENSIBLE_UI

#if ENABLED(EXTENSIBLE_UI)
  //#define EXTUI_LOCAL_BEEPER // 启用外部显示屏的本地蜂鸣器引脚
#endif

//=============================================================================
//=============================== 图形TFTs ====================================
//=============================================================================

/**
 * 具体的TFT模型预设。启用以下选项之一
 * 或启用TFT_GENERIC并设置子选项。
 */

//
// 480x320, 3.5英寸，带旋转编码器的SPI显示屏，来自MKS
// 通常与MKS Robin Nano V2和V3配对使用
// https://github.com/makerbase-mks/MKS-TFT-Hardware/tree/master/MKS%20TS35
//
//#define MKS_TS35_V2_0

//
// 320x240, 2.4英寸，来自MKS的FSMC显示屏
// 通常与MKS Robin Nano V1.2配对使用
//
//#define MKS_ROBIN_TFT24

//
// 320x240, 2.8英寸，来自MKS的FSMC显示屏
// 通常与MKS Robin Nano V1.2配对使用
//
//#define MKS_ROBIN_TFT28

//
// 320x240, 3.2英寸，来自MKS的FSMC显示屏
// 通常与MKS Robin Nano V1.2配对使用
//
//#define MKS_ROBIN_TFT32

//
// 480x320, 3.5英寸，来自MKS的FSMC显示屏
// 通常与MKS Robin Nano V1.2配对使用
//
//#define MKS_ROBIN_TFT35

//
// 480x272, 4.3英寸，来自MKS的FSMC显示屏
//
//#define MKS_ROBIN_TFT43

//
// 320x240, 3.2英寸，来自MKS的FSMC显示屏
// 通常与MKS Robin配对使用
//
//#define MKS_ROBIN_TFT_V1_1R

//
// 480x320, 3.5英寸，来自Tronxy的FSMC标准显示屏
//
//#define TFT_TRONXY_X5SA

//
// 480x320, 3.5英寸，来自AnyCubic的FSMC标准显示屏
//
//#define ANYCUBIC_TFT35

//
// 320x240, 2.8英寸，来自Longer/Alfawise的FSMC标准显示屏
//
//#define LONGER_LK_TFT28

//
// 320x240, 2.8英寸，来自ET4的FSMC标准显示屏
//
//#define ANET_ET4_TFT28

//
// 480x320, 3.5英寸，来自ET5的FSMC标准显示屏
//
//#define ANET_ET5_TFT35

//
// 1024x600, 7英寸，带旋转编码器的RGB标准显示屏，来自BIQU BX
// https://github.com/bigtreetech/BIQU-BX/tree/master/Hardware
//
//#define BIQU_BX_TFT70

//
// 480x320, 3.5英寸，带旋转编码器的SPI标准显示屏，来自BIQU B1 SE系列
// https://github.com/bigtreetech/TFT35-SPI/tree/master/v1
//
//#define BTT_TFT35_SPI_V1_0

//
// 通用TFT，具有详细的选项
//
//#define TFT_GENERIC
#if ENABLED(TFT_GENERIC)
  // :[ 'AUTO', 'ST7735', 'ST7789', 'ST7796', 'R61505', 'ILI9328', 'ILI9341', 'ILI9488' ]
  #define TFT_DRIVER AUTO

  // 接口。启用以下选项之一：
  //#define TFT_INTERFACE_FSMC
  //#define TFT_INTERFACE_SPI

  // TFT分辨率。启用以下选项之一：
  //#define TFT_RES_320x240
  //#define TFT_RES_480x272
  //#define TFT_RES_480x320
  //#define TFT_RES_1024x600
#endif

/**
 * TFT UI - 用户界面选择。启用以下选项之一：
 *
 *   TFT_CLASSIC_UI - 模拟DOGM - 128x64放大
 *   TFT_COLOR_UI   - Marlin默认菜单，触摸友好，使用完整的TFT功能
 *   TFT_LVGL_UI    - 使用LVGL的现代UI
 *
 *   对于LVGL_UI，还要将'assets'文件夹从构建目录复制到
 *   SD卡的根目录，以及已编译的固件一起。
 */
//#define TFT_CLASSIC_UI
//#define TFT_COLOR_UI
//#define TFT_LVGL_UI

#if ENABLED(TFT_COLOR_UI)
  /**
   * TFT Font for Color_UI. 选择以下之一：
   *
   * NOTOSANS  - 默认字体，带反锯齿。支持Latin Extended和非Latin字符。
   * UNIFONT   - 轻量级字体，无反锯齿。只支持Latin Extended和非Latin字符。
   * HELVETICA - 轻量级字体，无反锯齿。仅支持基本拉丁字符(0x0020-0x007F)和拉丁-1补充字符(0x0080-0x00FF)。
   */
  #define TFT_FONT  NOTOSANS

/**
   * TFT 主题用于 Color_UI。选择以下主题之一或将新主题添加到 'Marlin/src/lcd/tft/themes' 目录中。
   *
   * BLUE_MARLIN  - 默认主题，背景为 '午夜蓝'
   * BLACK_MARLIN - 背景为 '黑色' 的主题
   * ANET_BLACK   - 用于 Anet ET4/5 的主题
   */

  #define TFT_THEME BLACK_MARLIN

  //#define TFT_SHARED_IO   // I/O 在 TFT 显示器和其他设备之间共享。禁用异步数据传输。

  #define COMPACT_MARLIN_BOOT_LOGO  // 使用压缩数据节省Flash空间。
#endif

#if ENABLED(TFT_LVGL_UI)
  //#define MKS_WIFI_MODULE // MKS WiFi模块
#endif

/**
 * TFT旋转。设置为以下值之一：
 *
 *   TFT_ROTATE_90,  TFT_ROTATE_90_MIRROR_X,  TFT_ROTATE_90_MIRROR_Y,
 *   TFT_ROTATE_180, TFT_ROTATE_180_MIRROR_X, TFT_ROTATE_180_MIRROR_Y,
 *   TFT_ROTATE_270, TFT_ROTATE_270_MIRROR_X, TFT_ROTATE_270_MIRROR_Y,
 *   TFT_MIRROR_X, TFT_MIRROR_Y, TFT_NO_ROTATION
 */
//#define TFT_ROTATION TFT_NO_ROTATION

//=============================================================================
//============================  其他控制器  ============================
//=============================================================================

//
// Ender-3 v2 OEM显示屏。带旋转编码器的DWIN显示屏。
//
//#define DWIN_CREALITY_LCD           // Creality界面
//#define DWIN_LCD_PROUI              // MRiscoC的Pro界面
//#define DWIN_CREALITY_LCD_JYERSUI   // Jacob Myers的Jyers界面
//#define DWIN_MARLINUI_PORTRAIT      // MarlinUI（纵向）
//#define DWIN_MARLINUI_LANDSCAPE     // MarlinUI（横向）

//
// 触摸屏设置
//
//#define TOUCH_SCREEN
#if ENABLED(TOUCH_SCREEN)
  #define BUTTON_DELAY_EDIT      50 // (ms) 编辑界面的按钮重复延迟
  #define BUTTON_DELAY_MENU     250 // (ms) 菜单的按钮重复延迟

  //#define DISABLE_ENCODER         // 禁用点击编码器，如果有的话
  //#define TOUCH_IDLE_SLEEP_MINS 5 // (分钟) 显示屏在一段时间内无活动后休眠。使用M255 S设置。

  #define TOUCH_SCREEN_CALIBRATION

  //#define TOUCH_CALIBRATION_X 12316
  //#define TOUCH_CALIBRATION_Y -8981
  //#define TOUCH_OFFSET_X        -43
  //#define TOUCH_OFFSET_Y        257
  //#define TOUCH_ORIENTATION TOUCH_LANDSCAPE

  #if ALL(TOUCH_SCREEN_CALIBRATION, EEPROM_SETTINGS)
    #define TOUCH_CALIBRATION_AUTO_SAVE // 自动将成功的校准值保存到EEPROM中
  #endif

  #if ENABLED(TFT_COLOR_UI)
    //#define SINGLE_TOUCH_NAVIGATION
  #endif
#endif

//
// RepRapWorld REPRAPWORLD_KEYPAD v1.1
// https://reprapworld.com/products/electronics/ramps/keypad_v1_0_fully_assembled/
//
//#define REPRAPWORLD_KEYPAD
//#define REPRAPWORLD_KEYPAD_MOVE_STEP 10.0 // (mm) 每次按键移动的距离

//
// EasyThreeD ET-4000+，带按钮输入和状态LED
//
//#define EASYTHREED_UI

//采用key_configuration_parameters.h的定义优先覆盖
#ifdef REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER_Key
  #define REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER
  // 取消其他LCD控制器选项的定义
  #undef ANET_FULL_GRAPHICS_LCD
  #undef AZSMZ_12864
  #undef BQ_LCD_SMART_CONTROLLER
  #undef CARTESIO_UI
  #undef ELB_FULL_GRAPHIC_CONTROLLER
  #undef FF_INTERFACEBOARD
  #undef FYSETC_242_OLED_12864
  #undef G3D_PANEL
  #undef LCD_FOR_MELZI
  #undef LCD_I2C_PANELOLU2
  #undef LCD_I2C_VIKI
  #undef LCM1602
  #undef LONGER_LK_TFT28
  #undef MAKEBOARD_MINI_2_LINE_DISPLAY_1602
  #undef MAKRPANEL
  #undef MALYAN_LCD
  #undef NEXTION_TFT
  #undef MKS_LCD12864A
  #undef MKS_LCD12864B
  #undef OLED_PANEL_TINYBOY2
  #undef OVERLORD_OLED
  #undef PANEL_ONE
  #undef RA_CONTROL_PANEL
  #undef RADDS_DISPLAY
  #undef REPRAPWORLD_GRAPHICAL_LCD
  #undef RIGIDBOT_PANEL
  #undef SAV_3DGLCD
  #undef SAV_3DLCD
  #undef SILVER_GATE_GLCD_CONTROLLER
  #undef TFT_TRONXY_X5SA
  #undef TOUCH_UI_FTDI_EVE
  #undef U8GLIB_SH1106_EINSTART
  #undef ULTI_CONTROLLER 
#endif 

//=============================================================================
//=============================== 额外功能 ==============================
//=============================================================================

// @section fans

// 设置用户可控风扇的数量。禁用以使用所有板定义的风扇。
// :[1,2,3,4,5,6,7,8]
//#define NUM_M106_FANS 1

// 使用软件PWM驱动风扇，与加热器一样。这使用非常低的频率
// 不像硬件PWM那样令人讨厌。另一方面，如果这个频率
// 太低，您还应该增加SOFT_PWM_SCALE。
#define FAN_SOFT_PWM

// 将其增加1将使软件PWM频率加倍，
// 影响加热器和如果启用FAN_SOFT_PWM则影响风扇。
// 但是，每次递增控制分辨率减半；
// 在零值时，有128个有效的控制位置。
// :[0,1,2,3,4,5,6,7]
#define SOFT_PWM_SCALE 1

// 如果SOFT_PWM_SCALE设置为大于0的值，则可以使用抖动
// 来减轻相关的分辨率损失。如果启用，
// 某些PWM周期会被拉伸，以便平均达到所需的
// 占空比。
//#define SOFT_PWM_DITHER

// @section extras

// 支持BariCUDA粘合剂挤出机
//#define BARICUDA

// @section lights

// 显示热端和加热床温度的温度状态LED。
// 如果所有热端、加热床温度和目标温度都低于54°C，
// 则蓝色LED为开启状态。否则为红色LED为开启状态。（1°C的滞后）
//#define TEMP_STAT_LEDS

// 支持BlinkM/CyzRgb
//#define BLINKM

// 支持PCA9632 PWM LED驱动器
//#define PCA9632

// 支持PCA9533 PWM LED驱动器
//#define PCA9533

/**
 * RGB LED / LED灯带控制
 *
 * 启用对连接到5V数字引脚的RGB LED或
 * 由数字引脚控制的MOSFET控制的RGB灯带的支持。
 *
 * 添加M150命令来设置LED（或LED灯带）的颜色。
 * 如果引脚具有PWM功能（例如4、5、6、11），则可以设置
 * 从0到255的亮度范围。
 * 对于NeoPixel LED，还可以设置整体亮度参数。
 *
 *  === 警告 ===
 *  LED灯带需要PWM线和LED之间的MOSFET芯片，
 *  因为Arduino无法处理LED所需的电流。
 *  如果不遵循此预防措施，可能会损坏Arduino！
 *
 *  注意：需要单独的5V电源！NeoPixel LED
 *  需要的电流比Arduino的5V线性稳压器能产生的电流要大。
 *
 *  要求PWM频率介于50 <> 100Hz之间（检查HAL或variant）
 *  如果可能，使用FAST_PWM_FAN来减少风扇噪音。
 */

// LED类型。只启用以下两个选项之一：
//#define RGB_LED
//#define RGBW_LED

#if ANY(RGB_LED, RGBW_LED)
  //#define RGB_LED_R_PIN 34
  //#define RGB_LED_G_PIN 43
  //#define RGB_LED_B_PIN 35
  //#define RGB_LED_W_PIN -1
#endif

#if ANY(RGB_LED, RGBW_LED, PCA9632)
  //#define RGB_STARTUP_TEST              // 对于PWM引脚，渐变所有颜色之间
  #if ENABLED(RGB_STARTUP_TEST)
    #define RGB_STARTUP_TEST_INNER_MS 10  // (ms) 减少或增加渐变速度
  #endif
#endif

// 支持Adafruit NeoPixel LED驱动器
//#define NEOPIXEL_LED
#if ENABLED(NEOPIXEL_LED)
  #define NEOPIXEL_TYPE          NEO_GRBW // NEO_GRBW、NEO_RGBW、NEO_GRB、NEO_RBG等。
                                          // 请参阅 https://github.com/adafruit/Adafruit_NeoPixel/blob/master/Adafruit_NeoPixel.h
  //#define NEOPIXEL_PIN                4 // LED驱动引脚
  //#define NEOPIXEL2_TYPE  NEOPIXEL_TYPE
  //#define NEOPIXEL2_PIN               5
  #define NEOPIXEL_PIXELS              30 // 条中的LED数量（在禁用NEOPIXEL2_SEPARATE时最长的条）
  #define NEOPIXEL_IS_SEQUENTIAL          // 逐个显示温度变化 - 逐个LED。禁用以同时更改所有LED。
  #define NEOPIXEL_BRIGHTNESS         127 // 初始亮度（0-255）
  //#define NEOPIXEL_STARTUP_TEST         // 启动时循环显示颜色

  // 支持使用M150 S1 ... 控制的第二个Adafruit NeoPixel LED驱动器
  //#define NEOPIXEL2_SEPARATE
  #if ENABLED(NEOPIXEL2_SEPARATE)
    #define NEOPIXEL2_PIXELS           15 // 第二条中的LED数量
    #define NEOPIXEL2_BRIGHTNESS      127 // 初始亮度（0-255）
    #define NEOPIXEL2_STARTUP_TEST        // 启动时循环显示颜色
    #define NEOPIXEL_M150_DEFAULT      -1 // M150没有'S'时的默认条。使用-1默认设置所有条。
  #else
    //#define NEOPIXEL2_INSERIES          // 默认行为是两个NeoPixel并行
  #endif

  // 使用一些NeoPixel LED进行静态（背景）照明
  //#define NEOPIXEL_BKGD_INDEX_FIRST   0 // 第一个背景LED的索引
  //#define NEOPIXEL_BKGD_INDEX_LAST    5 // 最后一个背景LED的索引
  //#define NEOPIXEL_BKGD_COLOR         { 255, 255, 255, 0 }  // R、G、B、W
  //#define NEOPIXEL_BKGD_TIMEOUT_COLOR {  25,  25,  25, 0 }  // R、G、B、W
  //#define NEOPIXEL_BKGD_ALWAYS_ON       // 当其他NeoPixel关闭时保持背光打开
#endif

/**
 * 打印机事件LED
 *
 * 在打印过程中，LED将反映打印机状态：
 *
 *  - 当加热床达到目标温度时，逐渐从蓝色过渡到紫色
 *  - 当热端达到温度时，逐渐从紫色过渡到红色
 *  - 变为白色以照亮工作平台
 *  - 打印完成后变为绿色
 *  - 在打印完成后并且用户按下按钮后关闭
 */
#if ANY(BLINKM, RGB_LED, RGBW_LED, PCA9632, PCA9533, NEOPIXEL_LED)
  #define PRINTER_EVENT_LEDS
#endif

// @section servos

/**
 * 伺服机数量
 *
 * 对于某些与伺服机相关的选项，NUM_SERVOS将自动设置。
 * 如果有额外的伺服机需要手动控制，则手动设置。
 * 将其设置为0以关闭伺服机支持。
 */
//给BLTOUCH使用的
#define NUM_SERVOS 1 // 注意：M280-M282命令的伺服机索引从0开始

//检查是否为BLTOUCH，如果是，就判读是否开启伺服机，如果没有，就开启。
#if defined(Z_Axis_Probe) && Z_Axis_Probe == Bltouch
    #ifndef NUM_SERVOS
        #define NUM_SERVOS 1
    #endif
#endif

//检查是否为BLTOUCH，如果不是，就关闭，避免出错。
#if defined(NUM_SERVOS) && NUM_SERVOS == 1 && defined(Z_Axis_Probe) && Z_Axis_Probe == Fixed
    #undef NUM_SERVOS
#endif


// (ms) 在下一次移动开始之前的延迟，以便伺服机有时间达到目标角度。
// 300ms是一个很好的值，但您可以尝试更少的延迟。
// 如果伺服机无法达到所请求的位置，请增加它。
#define SERVO_DELAY { 300 }

// 仅在移动时给伺服机供电，否则关闭以防止抖动
//#define DEACTIVATE_SERVOS_AFTER_MOVE

// 使用M281编辑伺服机角度，并使用M500将其保存到EEPROM中
//#define EDITABLE_SERVO_ANGLES

// 使用M282禁用伺服机以减少功耗、噪音和热量
//#define SERVO_DETACH_GCODE
