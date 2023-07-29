/**
 * Marlin 3D打印机固件
 * 版权所有 (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * 基于Sprinter和grbl。
 * 版权所有 (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * 本程序是自由软件：您可以重新分发和/或修改
 * 根据GNU通用公共许可证的条款发布
 * 版本3或（根据您的选择）任何更高版本。
 *
 * 本程序是基于无任何担保的情况下分发的，
 * 包括但不限于对适销性或特定用途的适用性的暗示担保。
 * 详细信息请参见GNU通用公共许可证。
 *
 * 您应该已经收到了GNU通用公共许可证的副本
 * 这个程序。如果没有，请参阅<https://www.gnu.org/licenses/>。
 *
 */
#pragma once

/**
 * Configuration_adv.h
 *
 * 高级设置。
 * 仅在您确切知道自己在做什么时才更改这些设置。
 * 如果设置不当，某些设置可能会损坏您的打印机！
 *
 * 基本设置可以在Configuration.h中找到
 */
#define CONFIGURATION_ADV_H_VERSION 02010300

// @section develop

/**
 * 配置导出
 *
 * 将配置作为构建的一部分导出。（请参见signature.py）
 * 输出文件保存在构建目录下（例如 .pio/build/mega2560）。
 *
 * 以`build_all_examples --ini`作为config.ini档案的例子。
 *
 *  1 = marlin_config.json - 包含配置的字典。
 *      此文件也会为CONFIGURATION_EMBEDDING生成。
 *  2 = config.ini - PlatformIO预处理的文件格式。
 *  3 = schema.json - 整个配置模式。（13 = 模式组）
 *  4 = schema.yml - 整个配置模式。
 */
//#define CONFIG_EXPORT 2 // :[1:'JSON', 2:'config.ini', 3:'schema.json', 4:'schema.yml']

//===========================================================================
//============================= 温度设置 ============================
//===========================================================================
// @section temperature

/**
 * 热电偶传感器对噪声非常敏感。传感器线上引入的任何噪声，
 * 例如与之并行的步进电机线，可能导致热电偶传感器报告虚假错误。
 * 该值是连续发生错误的次数，在报告错误之前。
 * 这样我们就可以忽略间歇性的错误条件，同时仍然检测到实际故障，
 * 这应该会导致传感器连续输出错误。
 *
 * 将此值设置为0可在发生第一个错误时失败。
 */
#define THERMOCOUPLE_MAX_ERRORS 15

//
// 自定义热敏电阻1000参数
//
#if TEMP_SENSOR_0 == 1000
  #define HOTEND0_PULLUP_RESISTOR_OHMS    4700 // 上拉电阻
  #define HOTEND0_RESISTANCE_25C_OHMS   100000 // 25°C电阻
  #define HOTEND0_BETA                    3950 // Beta值
  #define HOTEND0_SH_C_COEFF                 0 // Steinhart-Hart C系数
#endif

#if TEMP_SENSOR_1 == 1000
  #define HOTEND1_PULLUP_RESISTOR_OHMS    4700 // 上拉电阻
  #define HOTEND1_RESISTANCE_25C_OHMS   100000 // 25°C电阻
  #define HOTEND1_BETA                    3950 // Beta值
  #define HOTEND1_SH_C_COEFF                 0 // Steinhart-Hart C系数
#endif

#if TEMP_SENSOR_2 == 1000
  #define HOTEND2_PULLUP_RESISTOR_OHMS    4700 // 上拉电阻
  #define HOTEND2_RESISTANCE_25C_OHMS   100000 // 25°C电阻
  #define HOTEND2_BETA                    3950 // Beta值
  #define HOTEND2_SH_C_COEFF                 0 // Steinhart-Hart C系数
#endif

#if TEMP_SENSOR_3 == 1000
  #define HOTEND3_PULLUP_RESISTOR_OHMS    4700 // 上拉电阻
  #define HOTEND3_RESISTANCE_25C_OHMS   100000 // 25°C电阻
  #define HOTEND3_BETA                    3950 // Beta值
  #define HOTEND3_SH_C_COEFF                 0 // Steinhart-Hart C系数
#endif

#if TEMP_SENSOR_4 == 1000
  #define HOTEND4_PULLUP_RESISTOR_OHMS    4700 // 上拉电阻
  #define HOTEND4_RESISTANCE_25C_OHMS   100000 // 25°C电阻
  #define HOTEND4_BETA                    3950 // Beta值
  #define HOTEND4_SH_C_COEFF                 0 // Steinhart-Hart C系数
#endif

#if TEMP_SENSOR_5 == 1000
  #define HOTEND5_PULLUP_RESISTOR_OHMS    4700 // 上拉电阻
  #define HOTEND5_RESISTANCE_25C_OHMS   100000 // 25°C电阻
  #define HOTEND5_BETA                    3950 // Beta值
  #define HOTEND5_SH_C_COEFF                 0 // Steinhart-Hart C系数
#endif

#if TEMP_SENSOR_6 == 1000
  #define HOTEND6_PULLUP_RESISTOR_OHMS    4700 // 上拉电阻
  #define HOTEND6_RESISTANCE_25C_OHMS   100000 // 25°C电阻
  #define HOTEND6_BETA                    3950 // Beta值
  #define HOTEND6_SH_C_COEFF                 0 // Steinhart-Hart C系数
#endif

#if TEMP_SENSOR_7 == 1000
  #define HOTEND7_PULLUP_RESISTOR_OHMS    4700 // 上拉电阻
  #define HOTEND7_RESISTANCE_25C_OHMS   100000 // 25°C电阻
  #define HOTEND7_BETA                    3950 // Beta值
  #define HOTEND7_SH_C_COEFF                 0 // Steinhart-Hart C系数
#endif

#if TEMP_SENSOR_BED == 1000
  #define BED_PULLUP_RESISTOR_OHMS        4700 // 上拉电阻
  #define BED_RESISTANCE_25C_OHMS       100000 // 25°C电阻
  #define BED_BETA                        3950 // Beta值
  #define BED_SH_C_COEFF                     0 // Steinhart-Hart C系数
#endif

#if TEMP_SENSOR_CHAMBER == 1000
  #define CHAMBER_PULLUP_RESISTOR_OHMS    4700 // 上拉电阻
  #define CHAMBER_RESISTANCE_25C_OHMS   100000 // 25°C电阻
  #define CHAMBER_BETA                    3950 // Beta值
  #define CHAMBER_SH_C_COEFF                 0 // Steinhart-Hart C系数
#endif

#if TEMP_SENSOR_COOLER == 1000
  #define COOLER_PULLUP_RESISTOR_OHMS     4700 // 上拉电阻
  #define COOLER_RESISTANCE_25C_OHMS    100000 // 25°C电阻
  #define COOLER_BETA                     3950 // Beta值
  #define COOLER_SH_C_COEFF                  0 // Steinhart-Hart C系数
#endif

#if TEMP_SENSOR_PROBE == 1000
  #define PROBE_PULLUP_RESISTOR_OHMS      4700 // 上拉电阻
  #define PROBE_RESISTANCE_25C_OHMS     100000 // 25°C电阻
  #define PROBE_BETA                      3950 // Beta值
  #define PROBE_SH_C_COEFF                   0 // Steinhart-Hart C系数
#endif

#if TEMP_SENSOR_BOARD == 1000
  #define BOARD_PULLUP_RESISTOR_OHMS      4700 // 上拉电阻
  #define BOARD_RESISTANCE_25C_OHMS     100000 // 25°C电阻
  #define BOARD_BETA                      3950 // Beta值
  #define BOARD_SH_C_COEFF                   0 // Steinhart-Hart C系数
#endif

#if TEMP_SENSOR_REDUNDANT == 1000
  #define REDUNDANT_PULLUP_RESISTOR_OHMS  4700 // 上拉电阻
  #define REDUNDANT_RESISTANCE_25C_OHMS 100000 // 25°C电阻
  #define REDUNDANT_BETA                  3950 // Beta值
  #define REDUNDANT_SH_C_COEFF               0 // Steinhart-Hart C系数
#endif

/**
 * 热电偶选项 - 适用于MAX6675（-2），MAX31855（-3）和MAX31865（-5）。
 */
//#define TEMP_SENSOR_FORCE_HW_SPI                // 忽略SCK/MOSI/MISO引脚；使用CS和默认SPI总线。
//#define MAX31865_SENSOR_WIRES_0 2               // （2-4）连接到MAX31865板上的探头的导线数。
//#define MAX31865_SENSOR_WIRES_1 2
//#define MAX31865_SENSOR_WIRES_2 2

//#define MAX31865_50HZ_FILTER                    // 使用50Hz滤波器而不是默认的60Hz。
//#define MAX31865_USE_READ_ERROR_DETECTION       // 将值峰值（在1秒内20°C的差异）视为读取错误。

//#define MAX31865_USE_AUTO_MODE                  // 比1-shot更快地读取更多次数；偏置电压始终开启；对RTD温度有轻微影响。
//#define MAX31865_MIN_SAMPLING_TIME_MSEC     100 // （毫秒）1-shot：最小读取间隔。通过使传感器在较长时间内处于未供电状态，减少偏置电压效应。
//#define MAX31865_IGNORE_INITIAL_FAULTY_READS 10 // 忽略一些读取错误（保持温度读数）以解决可能的问题（＃23439）。

//#define MAX31865_WIRE_OHMS_0              0.95f // 对于2线制，设置导线电阻以获得更准确的读数。
//#define MAX31865_WIRE_OHMS_1              0.0f
//#define MAX31865_WIRE_OHMS_2              0.0f

/**
 * Hephestos 2 24V加热床升级套件。
 * https://www.en3dstudios.com/product/bq-hephestos-2-heated-bed-kit/
 */
//#define HEPHESTOS2_HEATED_BED_KIT
#if ENABLED(HEPHESTOS2_HEATED_BED_KIT)
  #define HEATER_BED_INVERTING true
#endif

//
// 加热床Bang-Bang选项
//
#if DISABLED(PIDTEMPBED)
  #define BED_CHECK_INTERVAL 5000   // （毫秒）Bang-Bang控制的检查间隔
  #if ENABLED(BED_LIMIT_SWITCHING)
    #define BED_HYSTERESIS 2        // （°C）仅在ABS（T-target）> BED_HYSTERESIS时设置相关的加热器状态
  #endif
#endif

//
// 加热室选项
//
#if DISABLED(PIDTEMPCHAMBER)
  #define CHAMBER_CHECK_INTERVAL 5000   // （毫秒）Bang-Bang控制的检查间隔
  #if ENABLED(CHAMBER_LIMIT_SWITCHING)
    #define CHAMBER_HYSTERESIS 2        // （°C）仅在ABS（T-target）> CHAMBER_HYSTERESIS时设置相关的加热器状态
  #endif
#endif

#if TEMP_SENSOR_CHAMBER
  //#define HEATER_CHAMBER_PIN      P2_04   // 必需的加热器开/关引脚（例如：SKR 1.4 Turbo HE1插头）
  //#define HEATER_CHAMBER_INVERTING false
  //#define FAN1_PIN                   -1   // 在P2_04引脚上去除风扇信号（例如：SKR 1.4 Turbo HE1插头）

  //#define CHAMBER_FAN               // 启用室内风扇
  #if ENABLED(CHAMBER_FAN)
    //#define CHAMBER_FAN_INDEX   2   // 重新用作室内风扇的风扇的索引。（默认：第一个未使用的风扇）
    #define CHAMBER_FAN_MODE      2   // 风扇控制模式：0=静态；1=温度高于目标时线性增加；2=V形曲线；3=类似于1但风扇始终开启。
    #if CHAMBER_FAN_MODE == 0
      #define CHAMBER_FAN_BASE  255   // 室内风扇PWM（0-255）
    #elif CHAMBER_FAN_MODE == 1
      #define CHAMBER_FAN_BASE  128   // 基础室内风扇PWM（0-255）；当室内温度高于目标温度时打开
      #define CHAMBER_FAN_FACTOR 25   // 每°C高于目标的PWM增加量
    #elif CHAMBER_FAN_MODE == 2
      #define CHAMBER_FAN_BASE  128   // 最小室内风扇PWM（0-255）
      #define CHAMBER_FAN_FACTOR 25   // 每°C与目标的差异的PWM增加量
    #elif CHAMBER_FAN_MODE == 3
      #define CHAMBER_FAN_BASE  128   // 基础室内风扇PWM（0-255）
      #define CHAMBER_FAN_FACTOR 25   // 每°C高于目标的PWM增加量
    #endif
  #endif

  //#define CHAMBER_VENT              // 启用室内风门
  #if ENABLED(CHAMBER_VENT)
    #define CHAMBER_VENT_SERVO_NR  1  // 风门舵机的索引
    #define HIGH_EXCESS_HEAT_LIMIT 5  // 考虑到室内有过多的热量时超过目标温度多少度
    #define LOW_EXCESS_HEAT_LIMIT  3
    #define MIN_COOLING_SLOPE_TIME_CHAMBER_VENT 20
    #define MIN_COOLING_SLOPE_DEG_CHAMBER_VENT 1.5
  #endif
#endif

//
// 激光冷却器选项
//
#if TEMP_SENSOR_COOLER
  #define COOLER_MINTEMP           8  // （°C）
  #define COOLER_MAXTEMP          26  // （°C）
  #define COOLER_DEFAULT_TEMP     16  // （°C）
  #define TEMP_COOLER_HYSTERESIS   1  // （°C）被认为是接近目标温度的温度接近度
  #define COOLER_PIN               8  // 激光冷却器开/关引脚，用于控制冷却元件的通电（例如TEC，通过继电器的外部冷却器）
  #define COOLER_INVERTING     false
  #define TEMP_COOLER_PIN         15  // 激光/冷却器温度传感器引脚。需要ADC。
  #define COOLER_FAN                  // 启用冷却器上的风扇，风扇# 0,1,2,3等。
  #define COOLER_FAN_INDEX         0  // FAN号0, 1, 2等。例如
  #if ENABLED(COOLER_FAN)
    #define COOLER_FAN_BASE      100  // 基础冷却器风扇PWM（0-255）；当冷却器温度高于目标温度时打开
    #define COOLER_FAN_FACTOR     25  // 每°C高于目标的PWM增加量
  #endif
#endif

//
// 主板传感器选项
//
#if TEMP_SENSOR_BOARD
  #define THERMAL_PROTECTION_BOARD   // 如果板载传感器离开低于温度范围，则停止打印机。
  #define BOARD_MINTEMP           8  // （°C）
  #define BOARD_MAXTEMP          70  // （°C）
  //#define TEMP_BOARD_PIN -1        // 覆盖板温度传感器引脚。
#endif

//
// SoC传感器选项
//
#if TEMP_SENSOR_SOC
  #define THERMAL_PROTECTION_SOC     // 如果SoC传感器离开低于温度范围，则停止打印机。
  #define SOC_MAXTEMP            85  // （°C）
#endif

/**
 * 热保护提供了对您的打印机的额外保护，
 * 防止损坏和火灾。Marlin始终包括安全的最低和最高温度范围，
 * 以保护断开或断开的热敏电阻线。
 *
 * 问题：如果热敏电阻掉出来，它将报告房间空气的较低
 * 温度，并且固件将保持加热器开启。
 *
 * 解决方案：一旦温度达到目标温度，开始观察。
 * 如果温度在目标温度下保持得太远（滞后）太久（周期），
 * 固件将停止机器作为安全预防措施。
 *
 * 如果“热失控”出现误报，请增加
 * THERMAL_PROTECTION_HYSTERESIS和/或THERMAL_PROTECTION_PERIOD
 */
#if ENABLED(THERMAL_PROTECTION_HOTENDS)
  #define THERMAL_PROTECTION_PERIOD 40        // 秒
  #define THERMAL_PROTECTION_HYSTERESIS 4     // 摄氏度

  //#define ADAPTIVE_FAN_SLOWING              // 如果温度下降，减慢部件冷却风扇的速度
  #if ENABLED(ADAPTIVE_FAN_SLOWING)
    //#define REPORT_ADAPTIVE_FAN_SLOWING     // 向控制台报告风扇减速活动
    #if ANY(MPCTEMP, PIDTEMP)
      //#define TEMP_TUNING_MAINTAIN_FAN      // 在M303或M306 T期间不要降低风扇速度
    #endif
  #endif

/**
 * 当M104、M109或M303增加目标温度时，固件将等待WATCH_TEMP_PERIOD到期。如果温度
 * 未增加WATCH_TEMP_INCREASE度，机器将停止工作并需要进行硬重置。此测试重新启动任何M104/M109/M303，但只有
 * 当前温度远低于目标温度以进行可靠测试时。
 *
 * 如果“加热失败”出现误报，请增加WATCH_TEMP_PERIOD
 * 和/或减小WATCH_TEMP_INCREASE。WATCH_TEMP_INCREASE不应设置
 * 低于2。
 */
#define WATCH_TEMP_PERIOD  40               // 秒
#define WATCH_TEMP_INCREASE 2               // 摄氏度
#endif

//采用key_configuration_parameters.h的定义优先覆盖
//确保挤出头热保护设置的正确性
#if defined(E_Heating_Waiting_Time) && defined(E_Temperature_Rise_During_Heating_Wait_Time)
// 两个宏都被定义
#elif !defined(E_Heating_Waiting_Time) && !defined(E_Temperature_Rise_During_Heating_Wait_Time)
// 两个宏都未被定义
#else
#error "\"E_Heating_Waiting_Time\" 和 \"E_Temperature_Rise_During_Heating_Wait_Time\" 都需要同时被定义或者同时不被定义"
#endif
#if defined(E_Heating_Waiting_Time) && defined(E_Temperature_Rise_During_Heating_Wait_Time)
#undef THERMAL_PROTECTION_PERIOD
#undef WATCH_TEMP_PERIOD
#define THERMAL_PROTECTION_PERIOD E_Heating_Waiting_Time
#define WATCH_TEMP_PERIOD E_Heating_Waiting_Time
#undef THERMAL_PROTECTION_HYSTERESIS
#undef WATCH_TEMP_INCREASE
#define THERMAL_PROTECTION_HYSTERESIS E_Temperature_Rise_During_Heating_Wait_Time
#define WATCH_TEMP_INCREASE E_Temperature_Rise_During_Heating_Wait_Time
#endif

/**
 * 热床的热保护参数与热端相同。
 */
#if ENABLED(THERMAL_PROTECTION_BED)
  #define THERMAL_PROTECTION_BED_PERIOD        20 // 秒
  #define THERMAL_PROTECTION_BED_HYSTERESIS     2 // 摄氏度

  /**
   * 与热床相同，除了（M140/M190/M303）。
   */
  #define WATCH_BED_TEMP_PERIOD                60 // 秒
  #define WATCH_BED_TEMP_INCREASE               2 // 摄氏度
#endif

//采用key_configuration_parameters.h的定义优先覆盖
//确保热床热保护设置的正确性
#if defined(BED_Heating_Waiting_Time) && defined(BED_Temperature_Rise_During_Heating_Wait_Time)
// 两个宏都被定义
#elif !defined(BED_Heating_Waiting_Time) && !defined(BED_Temperature_Rise_During_Heating_Wait_Time)
// 两个宏都未被定义
#else
#error "\"BED_Heating_Waiting_Time\" 和 \"BED_Temperature_Rise_During_Heating_Wait_Time\" 都需要同时被定义或者同时不被定义"
#endif
#if defined(BED_Heating_Waiting_Time) && defined(BED_Temperature_Rise_During_Heating_Wait_Time)
#undef THERMAL_PROTECTION_BED_PERIOD
#undef WATCH_BED_TEMP_PERIOD
#define THERMAL_PROTECTION_BED_PERIOD BED_Heating_Waiting_Time
#define WATCH_BED_TEMP_PERIOD BED_Heating_Waiting_Time
#undef THERMAL_PROTECTION_BED_HYSTERESIS
#undef WATCH_BED_TEMP_INCREASE
#define THERMAL_PROTECTION_BED_HYSTERESIS BED_Temperature_Rise_During_Heating_Wait_Time
#define WATCH_BED_TEMP_INCREASE BED_Temperature_Rise_During_Heating_Wait_Time
#endif

/**
 * 加热室的热保护参数。
 */
#if ENABLED(THERMAL_PROTECTION_CHAMBER)
  #define THERMAL_PROTECTION_CHAMBER_PERIOD    20 // 秒
  #define THERMAL_PROTECTION_CHAMBER_HYSTERESIS 2 // 摄氏度

  /**
   * 加热室的监视设置（M141/M191）。
   */
  #define WATCH_CHAMBER_TEMP_PERIOD            60 // 秒
  #define WATCH_CHAMBER_TEMP_INCREASE           2 // 摄氏度
#endif

/**
 * 激光冷却器的热保护参数。
 */
#if ENABLED(THERMAL_PROTECTION_COOLER)
  #define THERMAL_PROTECTION_COOLER_PERIOD     10 // 秒
  #define THERMAL_PROTECTION_COOLER_HYSTERESIS  3 // 摄氏度

  /**
   * 激光冷却监视设置（M143/M193）。
   */
  #define WATCH_COOLER_TEMP_PERIOD             60 // 秒
  #define WATCH_COOLER_TEMP_INCREASE            3 // 摄氏度
#endif

#if ANY(THERMAL_PROTECTION_HOTENDS, THERMAL_PROTECTION_BED, THERMAL_PROTECTION_CHAMBER, THERMAL_PROTECTION_COOLER)
  /**
   * 热保护差异监视器-实验性功能
   * 在温度传感器卡住时停止机器。
   *
   * 这个功能可能会导致一些热稳定系统停止工作。一定要在
   * 各种条件下进行全面测试。如果出现误报，请禁用。
   *
   * 此功能确保温度传感器定期更新。如果传感器死亡或“卡住”，
   * 或者如果Marlin停止读取它们，温度将保持不变，而加热器仍然可能通电！
   * 此功能仅监视温度变化，因此应该能够捕捉到任何问题，无论是硬件还是软件。
   *
   * 默认情况下，它使用THERMAL_PROTECTION_*_PERIOD常量（上面）作为时间窗口，
   * 在此窗口内必须发生至少一个温度变化，以指示传感器轮询正在工作。
   * 如果任何被监视的加热器的温度在此期间保持完全恒定（甚至没有微小的变化），
   * 将发生热故障错误，并停止打印机。
   *
   * 一个非常稳定的加热器可能会产生误报并停止打印机。在这种情况下，请尝试增加
   * 相应的THERMAL_PROTECTION_*_PERIOD常量一点。请记住，不受控制的加热
   * 不应持续超过一两分钟。
   *
   * 在禁用此功能之前，请注意区分误报与真实传感器问题。如果
   * 在重新启动后，加热器的温度似乎比预期高，可能存在真实的
   * 热故障。检查主机中的温度图形是否有异常的波动。
   */
  //#define THERMAL_PROTECTION_VARIANCE_MONITOR
  #if ENABLED(THERMAL_PROTECTION_VARIANCE_MONITOR)
    // 覆盖上面的THERMAL_PROTECTION...PERIOD设置的差异检测窗口。
    // 请记住，一些加热器比其他加热器加热更快。
    //#define THERMAL_PROTECTION_VARIANCE_MONITOR_PERIOD 30  // (s) 覆盖所有监控周期
  #endif
#endif

#if ENABLED(PIDTEMP)
  // 根据挤出速度向加热器功率添加一个附加项。
  // 一个选择得当的Kc值应该只添加足够的功率来熔化增加的材料体积。
  //#define PID_EXTRUSION_SCALING
  #if ENABLED(PID_EXTRUSION_SCALING)
    #define DEFAULT_Kc (100) // 加热功率 = Kc * e_speed
    #define LPQ_MAX_LEN 50
  #endif

  /**
   * 根据风扇速度向加热器功率添加一个附加项。
   * 一个选择得当的Kf值应该只添加足够的功率来补偿冷却风扇的功率损失。
   * 您可以只使用DEFAULT_Kf值添加一个恒定的补偿
   * 或按照下面的说明进行速度相关的补偿。
   *
   * 恒定补偿（仅在风扇速度为0%和100%时使用）
   * ---------------------------------------------------------------------
   * Kf值的一个很好的起点来自以下计算：
   *   kf = (power_fan * eff_fan) / power_heater * 255
   * 其中eff_fan在0.0和1.0之间，基于风扇效率和喷嘴/加热器的气流。
   *
   * 示例：
   *   加热器：40W，风扇：0.1A * 24V = 2.4W，eff_fan = 0.8
   *   Kf = (2.4W * 0.8) / 40W * 255 = 12.24
   *
   * 风扇速度相关的补偿
   * --------------------------------
   * 1. 要找到一个好的Kf值，设置挤出头温度，等待其稳定，然后启用风扇（100%）。
   *    确保PID_FAN_SCALING_LIN_FACTOR为0，并且未启用PID_FAN_SCALING_ALTERNATIVE_DEFINITION。
   *    如果看到温度下降，请重复测试，慢慢增加Kf值，直到温度下降消失。如果启用风扇后温度过高，则Kf值过大。
   * 2. 记下风扇速度为100%时的Kf值。
   * 3. 确定一个好的PID_FAN_SCALING_MIN_SPEED值，大约是风扇开始运动的速度。
   * 4. 为此风扇速度重复步骤1和2。
   * 5. 启用PID_FAN_SCALING_ALTERNATIVE_DEFINITION，并在PID_FAN_SCALING_AT_FULL_SPEED和PID_FAN_SCALING_AT_MIN_SPEED中输入
   *    两个已确定的Kf值。在PID_FAN_SCALING_MIN_SPEED中输入最小速度
   */
  //#define PID_FAN_SCALING
  #if ENABLED(PID_FAN_SCALING)
    //#define PID_FAN_SCALING_ALTERNATIVE_DEFINITION
    #if ENABLED(PID_FAN_SCALING_ALTERNATIVE_DEFINITION)
      // 使用替代定义的更简单配置。
      // 只需找到全速（255）和PID_FAN_SCALING_MIN_SPEED的Kf值。
      // DEFAULT_Kf和PID_FAN_SCALING_LIN_FACTOR会相应计算。

      #define PID_FAN_SCALING_AT_FULL_SPEED 13.0        //=PID_FAN_SCALING_LIN_FACTOR*255+DEFAULT_Kf
      #define PID_FAN_SCALING_AT_MIN_SPEED   6.0        //=PID_FAN_SCALING_LIN_FACTOR*PID_FAN_SCALING_MIN_SPEED+DEFAULT_Kf
      #define PID_FAN_SCALING_MIN_SPEED     10.0        // 启用PID_FAN_SCALING的最小风扇速度

      #define DEFAULT_Kf (255.0*PID_FAN_SCALING_AT_MIN_SPEED-PID_FAN_SCALING_AT_FULL_SPEED*PID_FAN_SCALING_MIN_SPEED)/(255.0-PID_FAN_SCALING_MIN_SPEED)
      #define PID_FAN_SCALING_LIN_FACTOR (PID_FAN_SCALING_AT_FULL_SPEED-DEFAULT_Kf)/255.0

    #else
      #define PID_FAN_SCALING_LIN_FACTOR (0)             // 由于冷却而导致的功率损失 = Kf *（风扇速度）
      #define DEFAULT_Kf 10                              // 添加到PID调谐器的常数值
      #define PID_FAN_SCALING_MIN_SPEED 10               // 启用PID_FAN_SCALING的最小风扇速度
    #endif
  #endif
#endif

/**
 * 自动温度模式
 *
 * 根据计划的E动作动态调整挤出头目标温度。
 *
 * （与PID_EXTRUSION_SCALING相比，它跟踪E运动并使用额外的kC值调整PID
 *  行为。）
 *
 * Autotemp的计算方式为（mintemp + factor * mm_per_sec），上限为maxtemp。
 *
 * 使用M104/M109 F<factor> S<mintemp> B<maxtemp>启用Autotemp模式。
 * 发送没有F参数的M104/M109来禁用（或使用AUTOTEMP_PROPORTIONAL和F0）。
 */
#define AUTOTEMP
#if ENABLED(AUTOTEMP)
  #define AUTOTEMP_OLDWEIGHT    0.98  // 用于加权先前读数的因子（0.0 < value < 1.0）
  #define AUTOTEMP_MIN          210
  #define AUTOTEMP_MAX          250
  #define AUTOTEMP_FACTOR       0.1f
  // 默认情况下使用M104/M109启用AUTOTEMP，使用此处设置的比例
  #define AUTOTEMP_PROPORTIONAL
  #if ENABLED(AUTOTEMP_PROPORTIONAL)
    #define AUTOTEMP_MIN_P      0 // （°C）添加到目标温度
    #define AUTOTEMP_MAX_P      5 // （°C）添加到目标温度
    #define AUTOTEMP_FACTOR_P   1 // 默认应用此F参数（M104/M109的F参数会覆盖）
  #endif
#endif

// 显示温度ADC值
// 启用M105以包括从温度传感器读取的ADC值。
//#define SHOW_TEMP_ADC_VALUES

/**
 * 高温热敏电阻器支持
 *
 * 能够支持高温的热敏电阻器在室温和低温下往往很难获得良好的读数。这意味着TEMP_SENSOR_X_RAW_LO_TEMP
 * 可能会在预热过程中加热元件首次打开时被捕获，这将触发MINTEMP错误作为安全措施
 * 并强制停止一切。
 * 为了规避此限制，我们允许一个预热时间（在此期间，
 * 不会触发MINTEMP错误）并添加一个min_temp缓冲区来处理
 * 异常读数。
 *
 * 如果要为热端热敏电阻器启用此功能，请取消注释并在下面的常量中设置大于0的值
 */

// 可以发生连续低温错误的次数
// 在触发MINTEMP错误之前。 （不应超过10个。）
//#define MAX_CONSECUTIVE_LOW_TEMPERATURE_ERROR_ALLOWED 0

/**
 * 在开始检查温度之前，挤出头将预热的毫秒数。
 * 此值不应设置为加热器达到目标温度的时间，而应该设置为您的热敏电阻器可以读取的最低温度的时间。越低越好/更安全。
 * 这不应该超过30秒（30000）
 */
//#define PREHEAT_TIME_HOTEND_MS 0
//#define PREHEAT_TIME_BED_MS 0

// @section extruder

/**
 * 挤出器断丝防护。
 * 如果机器处于空闲状态且温度高于MINTEMP
 * 那么每隔几秒钟挤出一些丝材。
 */
//#define EXTRUDER_RUNOUT_PREVENT
#if ENABLED(EXTRUDER_RUNOUT_PREVENT)
  #define EXTRUDER_RUNOUT_MINTEMP 190
  #define EXTRUDER_RUNOUT_SECONDS 30
  #define EXTRUDER_RUNOUT_SPEED 1500  // （mm/min）
  #define EXTRUDER_RUNOUT_EXTRUDE 5   // （mm）
#endif

/**
 * 挤出头空闲超时
 * 防止喷嘴中的丝材炭化并导致严重堵塞。
 */
#define HOTEND_IDLE_TIMEOUT
#if ENABLED(HOTEND_IDLE_TIMEOUT)
  #define HOTEND_IDLE_TIMEOUT_SEC (5*60)    // （秒）没有挤出器运动的时间触发保护
  #define HOTEND_IDLE_MIN_TRIGGER   180     // （°C）启用挤出头保护的最低温度
  #define HOTEND_IDLE_NOZZLE_TARGET   0     // （°C）超时后喷嘴的安全温度
  #define HOTEND_IDLE_BED_TARGET      0     // （°C）超时后热床的安全温度
#endif

// @section temperature

// AD595 / AD8495传感器的校准以调整温度测量。
// 最终温度计算公式为（measuredTemp * GAIN）+ OFFSET。
#define TEMP_SENSOR_AD595_OFFSET  0.0
#define TEMP_SENSOR_AD595_GAIN    1.0
#define TEMP_SENSOR_AD8495_OFFSET 0.0
#define TEMP_SENSOR_AD8495_GAIN   1.0

/**
 * 控制器风扇
 * 用于冷却步进驱动器和MOSFET。
 *
 * 当任何驱动器被启用时，风扇会自动开启，然后在驱动器关闭后不久关闭（或减速）。
 */
//#define USE_CONTROLLER_FAN
#if ENABLED(USE_CONTROLLER_FAN)
  //#define CONTROLLER_FAN_PIN -1           // 设置自定义引脚用于控制器风扇
  //#define CONTROLLER_FAN2_PIN -1          // 设置自定义引脚用于第二个控制器风扇
  //#define CONTROLLER_FAN_USE_Z_ONLY       // 仅考虑Z轴
  //#define CONTROLLER_FAN_IGNORE_Z         // 忽略Z轴步进驱动器。在步进驱动器超时禁用时有用。
  #define CONTROLLERFAN_SPEED_MIN         0 // （0-255）最小速度。 （如果低于此值，则关闭风扇。）
  #define CONTROLLERFAN_SPEED_ACTIVE    255 // （0-255）活动速度，当任何马达启用时使用
  #define CONTROLLERFAN_SPEED_IDLE        0 // （0-255）空闲速度，当马达禁用时使用
  #define CONTROLLERFAN_IDLE_TIME        60 // （秒）在禁用马达后继续运行风扇的额外时间

  // 使用TEMP_SENSOR_BOARD作为启用控制器风扇的触发器
  //#define CONTROLLER_FAN_MIN_BOARD_TEMP 40  // （°C）如果电路板达到此温度，则打开风扇

  // 使用TEMP_SENSOR_SOC作为启用控制器风扇的触发器
  //#define CONTROLLER_FAN_MIN_SOC_TEMP 40  // （°C）如果SOC达到此温度，则打开风扇

  //#define CONTROLLER_FAN_EDITABLE         // 启用M710可配置设置
  #if ENABLED(CONTROLLER_FAN_EDITABLE)
    #define CONTROLLER_FAN_MENU             // 启用控制器风扇子菜单
  #endif
#endif

/**
 * 风扇启动
 * 当部分冷却或控制器风扇首次启动时，以可靠启动的速度运行一小段时间，然后设置所需的速度。
 * （在具有FAN_SOFT_PWM的Sanguinololu上不起作用。）
 */
//#define FAN_KICKSTART_TIME  100  // （ms）
//#define FAN_KICKSTART_POWER 180  // 64-255

// 一些冷却器可能需要一个非零的“关闭”状态。
//#define FAN_OFF_PWM  1

/**
 * PWM风扇缩放
 *
 * 定义PWM风扇的最小/最大速度（使用M106设置）。
 *
 * 使用这些选项，M106的0-255值范围会缩放为子集，
 * 以确保风扇具有足够的功率旋转，或者使用更高电流的低电流风扇。 （例如，使用12V/24V的5V/12V风扇）
 * 值0始终关闭风扇。
 *
 * 定义以下其中一个或两个以覆盖默认的0-255范围。
 */
//#define FAN_MIN_PWM 50
//#define FAN_MAX_PWM 128

/**
 * 快速PWM风扇
 *
 * 内部使用PWM模式、预分频值和TOP分辨率的组合
 * 以尽可能接近所需频率。
 *
 * FAST_PWM_FAN_FREQUENCY
 *   设置所需的频率。
 *   对于AVR，如果未定义，则默认为F = F_CPU/（2*255*1）
 *         即，F = 16MHz微控制器上的31.4kHz或F = 20MHz微控制器上的39.2kHz。
 *   对于非AVR，如果未定义，则默认为F = 1Khz。
 *   此F值仅用于保护硬件免受配置的缺失
 *   并不是在用户没有意识到必须特定设置频率以支持目标板时完全完成它的配置。
 *
 *   注意：设置非常低的频率（< 10 Hz）可能导致意外的定时器行为。
 *         设置非常高的频率可能损坏硬件。
 *
 * USE_OCR2A_AS_TOP [默认未定义]
 *   使用TIMER2用于PWM的板有限制，导致TIMER2上只有几个可能的频率：
 *   16MHz MCU：[62.5kHz、31.4kHz（默认）、7.8kHz、3.92kHz、1.95kHz、977Hz、488Hz、244Hz、60Hz、122Hz、30Hz]
 *   20MHz MCU：[78.1kHz、39.2kHz（默认）、9.77kHz、4.9kHz、2.44kHz、1.22kHz、610Hz、305Hz、153Hz、76Hz、38Hz]
 *   通过启用USE_OCR2A_AS_TOP可以实现更大的频率范围。但请注意，此选项会阻止
 *   在OC2A引脚上使用PWM。只有在不需要OC2A上的PWM时才使用此选项。 （检查电路图。）
 *   USE_OCR2A_AS_TOP牺牲了占空比控制的分辨率，以实现更广泛的频率范围。
 */
//#define FAST_PWM_FAN    // 增加风扇PWM频率。消除PWM噪声，但增加FET/Arduino的发热
#if ENABLED(FAST_PWM_FAN)
  //#define FAST_PWM_FAN_FREQUENCY 31400  // 在此处定义以覆盖下面的默认值
  //#define USE_OCR2A_AS_TOP
  #ifndef FAST_PWM_FAN_FREQUENCY
    #ifdef __AVR__
      #define FAST_PWM_FAN_FREQUENCY ((F_CPU) / (2 * 255 * 1))
    #else
      #define FAST_PWM_FAN_FREQUENCY 1000U
    #endif
  #endif
#endif

/**
 * 分配更多的PWM风扇用于部分冷却，与风扇0同步
 */
//#define REDUNDANT_PART_COOLING_FAN 1  // 同步风扇0的第一个风扇的索引
#ifdef REDUNDANT_PART_COOLING_FAN
  //#define NUM_REDUNDANT_FANS 1        // 连续风扇的数量，用于与风扇0同步
#endif

// @section extruder

/**
 * 挤出头冷却风扇
 *
 * 当挤出头的温度超过EXTRUDER_AUTO_FAN_TEMPERATURE时，挤出头自动启动风扇。
 *
 * 您的板的引脚文件指定了推荐的引脚。在此处覆盖或将其设置为-1以完全禁用。
 *
 * 多个挤出头可以分配到相同的引脚，此时风扇将在任何选择的挤出头温度超过阈值时开启。
 */
#define E0_AUTO_FAN_PIN FAN0_PIN
#define E1_AUTO_FAN_PIN -1
#define E2_AUTO_FAN_PIN -1
#define E3_AUTO_FAN_PIN -1
#define E4_AUTO_FAN_PIN -1
#define E5_AUTO_FAN_PIN -1
#define E6_AUTO_FAN_PIN -1
#define E7_AUTO_FAN_PIN -1
#define CHAMBER_AUTO_FAN_PIN -1
#define COOLER_AUTO_FAN_PIN -1

#define EXTRUDER_AUTO_FAN_TEMPERATURE 50
#define EXTRUDER_AUTO_FAN_SPEED 255   // 255 == 全速
#define CHAMBER_AUTO_FAN_TEMPERATURE 30
#define CHAMBER_AUTO_FAN_SPEED 255
#define COOLER_AUTO_FAN_TEMPERATURE 18
#define COOLER_AUTO_FAN_SPEED 255

/**
 * 挤出头冷却风扇转速计
 *
 * 定义一个或多个转速计引脚，以启用风扇速度
 * 监控，并使用M123报告风扇速度。
 *
 * 注意：仅适用于高达7000 RPM的风扇。
 */
//#define FOURWIRES_FANS      // 当安装了4线PWM风扇时需要
//#define E0_FAN_TACHO_PIN -1
//#define E0_FAN_TACHO_PULLUP
//#define E0_FAN_TACHO_PULLDOWN
//#define E1_FAN_TACHO_PIN -1
//#define E1_FAN_TACHO_PULLUP
//#define E1_FAN_TACHO_PULLDOWN
//#define E2_FAN_TACHO_PIN -1
//#define E2_FAN_TACHO_PULLUP
//#define E2_FAN_TACHO_PULLDOWN
//#define E3_FAN_TACHO_PIN -1
//#define E3_FAN_TACHO_PULLUP
//#define E3_FAN_TACHO_PULLDOWN
//#define E4_FAN_TACHO_PIN -1
//#define E4_FAN_TACHO_PULLUP
//#define E4_FAN_TACHO_PULLDOWN
//#define E5_FAN_TACHO_PIN -1
//#define E5_FAN_TACHO_PULLUP
//#define E5_FAN_TACHO_PULLDOWN
//#define E6_FAN_TACHO_PIN -1
//#define E6_FAN_TACHO_PULLUP
//#define E6_FAN_TACHO_PULLDOWN
//#define E7_FAN_TACHO_PIN -1
//#define E7_FAN_TACHO_PULLUP
//#define E7_FAN_TACHO_PULLDOWN

/**
 * 部分冷却风扇复用器
 *
 * 此功能允许您进行数字复用风扇输出。
 * 复用器在工具更改时自动切换。
 * 为FANMUX[012]_PINs设置最多2、4或8个复用风扇。
 */
#define FANMUX0_PIN -1
#define FANMUX1_PIN -1
#define FANMUX2_PIN -1

/**
 * M355机箱灯开关/亮度
 */
//#define CASE_LIGHT_ENABLE
#if ENABLED(CASE_LIGHT_ENABLE)
  //#define CASE_LIGHT_PIN 4                  // 如果需要，覆盖默认引脚
  #define INVERT_CASE_LIGHT false             // 如果CASE LIGHT在引脚低电平时为ON，则设置为true
  #define CASE_LIGHT_DEFAULT_ON true          // 设置上电默认状态为开启
  #define CASE_LIGHT_DEFAULT_BRIGHTNESS 105   // 设置上电默认亮度（0-255，需要PWM引脚）
  //#define CASE_LIGHT_NO_BRIGHTNESS          // 禁用亮度控制。对于非PWM照明启用。
  //#define CASE_LIGHT_MAX_PWM 128            // 限制PWM占空比（0-255）
  //#define CASE_LIGHT_MENU                   // 向LCD菜单添加Case Light选项
  #if ENABLED(NEOPIXEL_LED)
    //#define CASE_LIGHT_USE_NEOPIXEL         // 使用NeoPixel LED作为机箱灯
  #endif
  #if ANY(RGB_LED, RGBW_LED)
    //#define CASE_LIGHT_USE_RGB_LED          // 使用RGB / RGBW LED作为机箱灯
  #endif
  #if ANY(CASE_LIGHT_USE_NEOPIXEL, CASE_LIGHT_USE_RGB_LED)
    #define CASE_LIGHT_DEFAULT_COLOR { 255, 255, 255, 255 } // { 红色, 绿色, 蓝色, 白色 }
  #endif
#endif

// @section homing

// 如果要使终点开关始终处于开启状态（默认情况下），即使没有归位
// 启用此选项。可以随时使用M120、M121覆盖。
//#define ENDSTOPS_ALWAYS_ON_DEFAULT

// @section extras

//#define Z_LATE_ENABLE // 在最后一刻启用Z轴。如果Z驱动器过热，请启用。

// 使用外部闭环控制器。如果需要，请在此处覆盖引脚。
//#define EXTERNAL_CLOSED_LOOP_CONTROLLER
#if ENABLED(EXTERNAL_CLOSED_LOOP_CONTROLLER)
  //#define CLOSED_LOOP_ENABLE_PIN        -1
  //#define CLOSED_LOOP_MOVE_COMPLETE_PIN -1
#endif

/**
 * 双X轴承架
 *
 * 此设置具有两个可以独立移动的X轴承架，每个都有自己的挤出头。
 * 这些承架可以用于打印具有两种颜色或材料的对象，或者在
 * “复制模式”中，可以同时打印两个相同或X镜像的对象。
 * 非活动的承架会自动停放，以防止渗漏。
 * X1是左边的承架，X2是右边的承架。它们在X轴的两端停放和归位。
 * 默认情况下，将第二个X轴步进驱动器分配给板上的第一个未使用的E插头。
 *
 * 可以使用M605 S<mode>选择以下Dual X Carriage模式：
 *
 *   0：（FULL_CONTROL）切片器对两个X承架具有完全控制权，并且可以实现最佳行程
 *       只要支持双X承架即可。 （M605 S0）
 *
 *   1：（AUTO_PARK）固件在工具更改时自动将X承架停放和解锁，因此
 *       不需要额外的切片器支持。 （M605 S1）
 *
 *   2：（DUPLICATION）固件与第一个X承架和挤出头同步地移动第二个X承架和挤出头，
 *       以同时打印两个相同的对象的副本。使用M605 S2 X[offs] R[deg]设置X偏移和温度差
 *       并用M605 S2跟随以启动复制运动。
 *
 *   3：（MIRRORED）受Formbot/Vivedino启发的镜像模式，其中第二个挤出头复制
 *       第一个的运动，但第二个挤出头在X轴上是反向的。
 *       使用M605 S2 X[offs] R[deg]设置初始X偏移和温度差
 *       并用M605 S3跟随以启动镜像运动。
 */
//#define DUAL_X_CARRIAGE
#if ENABLED(DUAL_X_CARRIAGE)
  #define X1_MIN_POS X_MIN_POS    // 设置为X_MIN_POS
  #define X1_MAX_POS X_BED_SIZE   // 最大坐标，以防X1承架碰到停放的X2承架
  #define X2_MIN_POS    80        // X2承架的最小坐标，以防碰到停放的X1承架
  #define X2_MAX_POS   353        // X2承架的最大位置，通常也是归位位置
  #define X2_HOME_POS X2_MAX_POS  // 默认的X2归位位置。设置为X2_MAX_POS。
                                  // 注意：对于Dual X Carriage使用M218 T1 Xn来覆盖X2_HOME_POS。
                                  // 这样可以在不重新构建的情况下重新校准终点开关的距离。
                                  // 请记住，将第二个挤出头的X偏移设置为0。
                                  // 在切片器中。
                                  
  // 这是默认的上电模式，可以使用M605 S<mode>稍后更改。
  #define DEFAULT_DUAL_X_CARRIAGE_MODE DXC_AUTO_PARK_MODE

  // 复制模式中的默认X偏移（通常设置为半个打印床宽度）
  #define DEFAULT_DUPLICATION_X_OFFSET 100

  // M605模式更改命令后执行的默认操作。通常是G28X以应用新的模式。
  //#define EVENT_GCODE_IDEX_AFTER_MODECHANGE "G28X"
#endif

/**
 * 多步进电机/多终点
 *
 * 当定义X2_DRIVER_TYPE时，表示X和X2电机协同工作。
 * 对X的以下解释也适用于Y和Z的多步进设置。
 * 终点开关偏移可以通过'M666 X<offset> Y<offset> Z<offset>'进行更改并存储到EEPROM中。
 *
 * - 如果X2电机需要与X相反的DIR信号，请启用INVERT_X2_VS_X_DIR。
 *
 * - 如果第二个电机有自己的终点开关，并且可调节偏移量，请启用X_DUAL_ENDSTOPS。
 *
 *   - 额外的终点开关包括在'M119'的输出中。
 *
 *   - 将X_DUAL_ENDSTOP_ADJUSTMENT设置为X2终点开关的已知误差。
 *     在'G28' / 'G28 X'上应用于X2电机。
 *     通过将X归位并测量误差来获得偏移量。
 *     也可以使用'M666 X<offset>'进行设置，并使用'M500'存储到EEPROM中。
 *
 *   - 在此处定义额外的终点开关引脚以覆盖默认值。不自动分配。
 */
#if HAS_X2_STEPPER && DISABLED(DUAL_X_CARRIAGE)
  //#define INVERT_X2_VS_X_DIR        // X2方向信号与X相反
  //#define X_DUAL_ENDSTOPS           // X2有自己的终点开关
  #if ENABLED(X_DUAL_ENDSTOPS)
    //#define X2_STOP_PIN X_MAX_PIN   // X2终点开关引脚覆盖
    #define X2_ENDSTOP_ADJUSTMENT  0  // X2相对于X终点开关的偏移量
  #endif
#endif

#if HAS_Y2_STEPPER
  //#define INVERT_Y2_VS_Y_DIR        // Y2方向信号与Y相反
  //#define Y_DUAL_ENDSTOPS           // Y2有自己的终点开关
  #if ENABLED(Y_DUAL_ENDSTOPS)
    //#define Y2_STOP_PIN Y_MAX_PIN   // Y2终点开关引脚覆盖
    #define Y2_ENDSTOP_ADJUSTMENT  0  // Y2相对于Y终点开关的偏移量
  #endif
#endif

//
// 多Z轴步进电机
//
#ifdef Z2_DRIVER_TYPE
  //#define INVERT_Z2_VS_Z_DIR        // Z2方向信号与Z相反

  //#define Z_MULTI_ENDSTOPS          // 其他Z轴具有自己的终点开关
  #if ENABLED(Z_MULTI_ENDSTOPS)
    //#define Z2_STOP_PIN X_MAX_PIN   // Z2终点开关引脚覆盖
    #define Z2_ENDSTOP_ADJUSTMENT 0   // Z2相对于Z终点开关的偏移量
  #endif
  #ifdef Z3_DRIVER_TYPE
    //#define INVERT_Z3_VS_Z_DIR      // Z3方向信号与Z相反
    #if ENABLED(Z_MULTI_ENDSTOPS)
      //#define Z3_STOP_PIN Y_MAX_PIN // Z3终点开关引脚覆盖
      #define Z3_ENDSTOP_ADJUSTMENT 0 // Z3相对于Z终点开关的偏移量
    #endif
  #endif
  #ifdef Z4_DRIVER_TYPE
    //#define INVERT_Z4_VS_Z_DIR      // Z4方向信号与Z相反
    #if ENABLED(Z_MULTI_ENDSTOPS)
      //#define Z4_STOP_PIN Z_MAX_PIN // Z4终点开关引脚覆盖
      #define Z4_ENDSTOP_ADJUSTMENT 0 // Z4相对于Z终点开关的偏移量
    #endif
  #endif
#endif

// 使用两个同步的步进电机驱动E轴
//#define E_DUAL_STEPPER_DRIVERS
#if ENABLED(E_DUAL_STEPPER_DRIVERS)
  //#define INVERT_E1_VS_E0_DIR       // E方向信号相反
#endif

// 使用M380在活动挤出头上启用一个电磁阀。使用M381禁用所有电磁阀。
// 为每个具有电磁阀的挤出头定义SOL0_PIN、SOL1_PIN等。
//#define EXT_SOLENOID

// @section homing

/**
 * 归位过程
 * 归位（G28）通过无限运动朝向终点开关，以确定工具头相对于工作空间的位置。
 */

//#define SENSORLESS_BACKOFF_MM  { 2, 2, 0 }  // （线性=毫米，旋转=°）在无感归位之前从终点开关后退

#define HOMING_BUMP_MM      { 5, 5, 2 }       // （线性=毫米，旋转=°）第一次碰撞终点开关后的后退
#define HOMING_BUMP_DIVISOR { 2, 2, 4 }       // 重复碰撞速度除数（除以归位进给速度）

//#define HOMING_BACKOFF_POST_MM { 2, 2, 2 }  // （线性=毫米，旋转=°）归位后从终点开关后退
//#define XY_COUNTERPART_BACKOFF_MM 0         // （毫米）在归位Y之后后退X，反之亦然

#define QUICK_HOME                            // 如果G28包含XY，则先进行对角线移动
//#define HOME_Y_BEFORE_X                     // 如果G28包含XY，则先归位Y再归位X
//#define HOME_Z_FIRST                        // 先归位Z。需要一个真正的终点开关（而不是一个探针）。
//#define CODEPENDENT_XY_HOMING               // 如果X/Y在先归位Y/X之前无法归位，请启用

// @section bltouch

#if ENABLED(BLTOUCH)
  /**
   * 要么：使用默认设置（推荐）或：为特殊用途使用以下定义
   * 不要激活探针可能不理解的设置。克隆可能会误解高级命令。
   *
   * 注意：如果探针未展开，请执行“复位”和“自检”，然后检查
   * 布朗色、红色和橙色线的布线情况。
   *
   * 注意：如果探针的触发信号未被识别，很可能是因为需要交换黑色和白色线。
   * 它们与真正的开关不同，不能“交换”。所以请先检查布线。
   *
   * 适用于所有BLTouch和克隆探针的设置：
   */

  // 安全：探针需要时间来识别命令。
  // 最小命令延迟（ms）。如果需要，请启用并增加。
  #define BLTOUCH_DELAY 500

  /**
   * 适用于BLTOUCH Classic 1.2、1.3或BLTouch Smart 1.0、2.0、2.2、3.0、3.1和大多数克隆探针：
   */

  // 特性：在展开后切换到SW模式。它使输出脉冲时间更长。在特殊情况下可能有用，例如噪声或滤波输入配置。
  //#define BLTOUCH_FORCE_SW_MODE

  /**
   * 适用于BLTouch Smart 3.0和3.1
   * 总结：
   *   - 电压模式：5V和OD（开漏 - “逻辑电压自由”）输出模式
   *   - 高速模式
   *   - 禁用液晶电压选项
   */

  /**
   * 危险：除非连接到5V容忍的控制器，否则不要激活5V模式！
   * V3.0或3.1：将默认模式设置为5V模式。如果禁用，则3.0上的OD模式是硬编码的默认值。
   * 在启动时，Marlin将其EEPROM与此值进行比较。如果所选模式不同，则会在初始化时完成模式设置EEPROM写入。
   * 使用以下选项强制V3.1探针进行EEPROM写入。
   */
  //#define BLTOUCH_SET_5V_MODE

  // 安全：在LCD菜单中启用电压模式设置。
  #define BLTOUCH_LCD_VOLTAGE_MENU

  /**
   * 安全：如果连接了具有未知电压模式的探针，请启用。
   * V3.0：在Marlin启动时将探针设置为上面选择的模式。在3.0上需要5V模式
   * V3.1：在Marlin启动时，将具有未知模式的探针强制进入所选择的模式（=探针EEPROM写入）
   * 为了延长探针的使用寿命，使用一次然后关闭并重新刷写。
   */
  #define BLTOUCH_FORCE_MODE_SET

  /**
   * 启用探针的“高速”选项。
   * 危险：如果探针有时失败，请禁用。仅适用于稳定的、良好调整的系统。
   * 此功能设计用于Z移动非常快的Delta机器；然而，速度更快的Cartesians也可能使用它。
   * 如果机器无法快速提升Z，则BLTouch可能会进入ALARM状态。
   *
   * 在此处设置默认状态，使用'M401 S'或UI更改，使用M500保存，使用M502重置。
   */
  //#define BLTOUCH_HS_MODE true

  #ifdef BLTOUCH_HS_MODE
    // 探针Z偏移（M851 Z）是触发探针的高度。
    // 这必须足够大，以使探针引脚离开床面并防止其被床夹紧。
    #define BLTOUCH_HS_EXTRA_CLEARANCE    7 // 额外的Z间隙
  #endif

#endif // BLTOUCH

// @section calibration

/**
 * Z轴步进电机自动校准
 * 使用床面探针添加G34命令以校准多个Z轴步进电机。
 */
//#define Z_STEPPER_AUTO_ALIGN
#if ENABLED(Z_STEPPER_AUTO_ALIGN)
  /**
   * 为Z1、Z2、Z3等定义探测器的X和Y位置，对应于床面车架上的螺钉位置，每个螺钉对应于一个Z轴步进电机。
   * 这些位置是相对于机器的，不随M206原点偏移而改变！
   * 如果未定义，将使用探测器极限。
   * 使用'M422 S<index> X<pos> Y<pos>'进行覆盖。
   */
  //#define Z_STEPPER_ALIGN_XY { {  10, 190 }, { 100,  10 }, { 190, 190 } }

  /**
   * 用于自动计算的探测器位置的方向。
   * 使用'M422 S<index> X<pos> Y<pos>'覆盖Z步进电机对齐点
   *
   * 2个步进电机：  (0)     (1)
   *                |       |   2   |
   *                | 1   2 |       |
   *                |       |   1   |
   *
   * 3个步进电机：  (0)     (1)     (2)     (3)
   *                |   3   | 1     | 2   1 |     2 |
   *                |       |     3 |       | 3     |
   *                | 1   2 | 2     |   3   |     1 |
   *
   * 4个步进电机：  (0)     (1)     (2)     (3)
   *                | 4   3 | 1   4 | 2   1 | 3   2 |
   *                |       |       |       |       |
   *                | 1   2 | 2   3 | 3   4 | 4   1 |
   */
  #ifndef Z_STEPPER_ALIGN_XY
    //#define Z_STEPPERS_ORIENTATION 0
  #endif

  /**
   * 更快地在床面校准中收敛的Z步进电机位置。
   * 需要3个或4个Z步进电机。
   *
   * 为Z1、Z2、Z3...定义步进电机XY位置，对应于床面车架上的螺钉位置，每个步进电机与步进电机驱动器顺序中的一个位置对应。
   */
  //#define Z_STEPPER_ALIGN_STEPPER_XY { { 210.7, 102.5 }, { 152.6, 220.0 }, { 94.5, 102.5 } }

  #ifndef Z_STEPPER_ALIGN_STEPPER_XY
    // 放大系数。用于调整步进电机（主轴）位置较远的情况下的校正步长。
    #define Z_STEPPER_ALIGN_AMP 1.0       // 使用值> 1.0 注意：这可能会导致不稳定！
  #endif

  // 在300mm床上，5%的等级会导致约1.5cm的偏差
  #define G34_MAX_GRADE              5    // （％）G34能够处理的最大斜坡
  #define Z_STEPPER_ALIGN_ITERATIONS 5    // 应用于校准的迭代次数
  #define Z_STEPPER_ALIGN_ACC        0.02 // 如果精度达到此值，则提前停止迭代
  #define RESTORE_LEVELING_AFTER_G34      // G34完成后恢复级调？
  // 在G34之后，重新归位Z（G28 Z）还是仅使用最后一个探针高度计算？
  // 重新归位可能在再现实际'G28 Z'归位高度方面更精确，尤其是在床面不平的情况下。
  #define HOME_AFTER_G34
#endif

//
// 添加G35命令以读取床角，以帮助调整螺丝。需要床面探针。
//
#define ASSISTED_TRAMMING
#if ENABLED(ASSISTED_TRAMMING)

  // 定义要探测的3到9个点。
  //#define TRAMMING_POINT_XY { {  20, 20 }, { 180,  20 }, { 180, 180 }, { 20, 180 } }
  //自动根据床大小和探头不可用范围调节探测点
  #define TRAMMING_POINT_XY { { PROBING_MARGIN, PROBING_MARGIN }, { X_BED_SIZE - PROBING_MARGIN, PROBING_MARGIN }, { X_BED_SIZE - PROBING_MARGIN, Y_BED_SIZE - PROBING_MARGIN }, { PROBING_MARGIN, Y_BED_SIZE - PROBING_MARGIN } }


  // 定义探测点的位置名称。
  #define TRAMMING_POINT_NAME_1 "前左"
  #define TRAMMING_POINT_NAME_2 "前右"
  #define TRAMMING_POINT_NAME_3 "后右"
  #define TRAMMING_POINT_NAME_4 "后左"

  #define RESTORE_LEVELING_AFTER_G35    // 启用以在操作后恢复级调设置
  #define REPORT_TRAMMING_MM          // 报告每个点相对于第一个点的Z偏差（mm）

  #define ASSISTED_TRAMMING_WIZARD    // 向LCD菜单添加Tramming向导

  //#define ASSISTED_TRAMMING_WAIT_POSITION { X_CENTER, Y_CENTER, 30 } // 移动喷嘴以便于调整

  /**
   * 螺丝线程：
   *   M3：30 = 顺时针，31 = 逆时针
   *   M4：40 = 顺时针，41 = 逆时针
   *   M5：50 = 顺时针，51 = 逆时针
   */
  #define TRAMMING_SCREW_THREAD 40

#endif

// @section motion control

/**
 * 固定时间基准运动控制--实验性功能
 * 使用G代码M493启用/禁用和设置参数。
 */
//#define FT_MOTION
#if ENABLED(FT_MOTION)
  #define FTM_DEFAULT_MODE ftMotionMode_DISABLED // 固定时间控制的默认模式。（ft_types.h中的枚举）
  #define FTM_DEFAULT_DYNFREQ_MODE dynFreqMode_DISABLED // 动态频率计算的默认模式。（ft_types.h中的枚举）
  #define FTM_SHAPING_DEFAULT_X_FREQ 37.0f // （Hz）输入整形器使用的默认峰值频率。
  #define FTM_SHAPING_DEFAULT_Y_FREQ 37.0f // （Hz）输入整形器使用的默认峰值频率。
  #define FTM_LINEAR_ADV_DEFAULT_ENA false // 默认线性提前启用（true）或禁用（false）。
  #define FTM_LINEAR_ADV_DEFAULT_K 0.0f // 默认线性提前增益。
  #define FTM_SHAPING_ZETA 0.1f // 输入整形器使用的Zeta值。
  #define FTM_SHAPING_V_TOL 0.05f // EI输入整形器使用的振动容限。

  /**
   * 高级配置
   */
  #define FTM_BATCH_SIZE 100 // 用于轨迹生成的批处理大小；
  #define FTM_WINDOW_SIZE 200 // 用于轨迹生成的窗口大小。
  #define FTM_FS 1000 // （Hz）用于轨迹生成的频率。（1 / FTM_TS）
  #define FTM_TS 0.001f // （秒）用于轨迹生成的时间步长。（1 / FTM_FS）
  #define FTM_STEPPER_FS 20000 // （Hz）用于步进器输入输出更新的频率。
  #define FTM_MIN_TICKS ((STEPPER_TIMER_RATE) / (FTM_STEPPER_FS)) // 步进器每步之间的最小步进数。
  #define FTM_MIN_SHAPE_FREQ 10 // 最小整形频率。
  #define FTM_ZMAX 100 // 整形函数的最大延迟（必须是偶数！）。
                      // 计算方式如下：
                      //    1/2 * (FTM_FS / FTM_MIN_SHAPE_FREQ) for ZV.
                      //    (FTM_FS / FTM_MIN_SHAPE_FREQ) for ZVD, MZV.
                      //    3/2 * (FTM_FS / FTM_MIN_SHAPE_FREQ) for 2HEI.
                      //    2 * (FTM_FS / FTM_MIN_SHAPE_FREQ) for 3HEI.
  #define FTM_STEPS_PER_UNIT_TIME 20 // 每单位时间的插值步进命令。
                                    // 计算方式为（FTM_STEPPER_FS / FTM_FS）。
  #define FTM_CTS_COMPARE_VAL 10 // 插值算法中使用的比较值。
                                // 计算方式为（FTM_STEPS_PER_UNIT_TIME / 2）。
  // 这些值可以配置以调整循环（loop()）的持续时间。
  #define FTM_STEPS_PER_LOOP 60 // 每次循环（loop()）生成的步进命令数量。
  #define FTM_POINTS_PER_LOOP 100 // 每次循环（loop()）生成的轨迹点数量。

  // 这个值可以配置以调整消耗命令缓冲区的时间。
  // 如果步进电机运动不平滑，请尝试增加此值。
  #define FTM_STEPPERCMD_BUFF_SIZE 1000 // 步进命令缓冲区的大小。

  //#define FT_MOTION_MENU // 提供MarlinUI菜单以设置M493参数。
#endif

/**
 * 输入整形 -- 实验性功能
 *
 * 零振动（ZV）输入整形的X和/或Y轴运动。
 *
 * 此选项在步进缓冲区中使用了大量的SRAM。缓冲区大小根据SHAPING_FREQ_[XY]、
 * DEFAULT_AXIS_STEPS_PER_UNIT、DEFAULT_MAX_FEEDRATE和ADAPTIVE_STEP_SMOOTHING自动计算。
 * 默认计算可以通过设置SHAPING_MIN_FREQ和/或SHAPING_MAX_FEEDRATE进行覆盖。
 * 频率越高，进给速度越低，缓冲区越小。
 * 如果在运行时缓冲区太小，高速运动时输入整形将具有降低的效果。
 *
 * 使用M593 D<factor> F<frequency>进行调整：
 *
 *  D<factor>    设置zeta/阻尼系数。如果未指定轴（X、Y等），则为所有轴设置。
 *  F<frequency> 设置频率。如果未指定轴（X、Y等），则为所有轴设置。
 *  T[map]       输入整形类型，0：ZV，1：EI，2：2H EI（尚未实现）
 *  X<1>         仅为X轴设置给定的参数。
 *  Y<1>         仅为Y轴设置给定的参数。
 */
//#define INPUT_SHAPING_X
//#define INPUT_SHAPING_Y
#if ANY(INPUT_SHAPING_X, INPUT_SHAPING_Y)
  #if ENABLED(INPUT_SHAPING_X)
    #define SHAPING_FREQ_X 40 // （Hz）X轴的默认主频。
    #define SHAPING_ZETA_X 0.15f // X轴的阻尼比（范围：0.0 = 无阻尼到1.0 = 临界阻尼）。
  #endif
  #if ENABLED(INPUT_SHAPING_Y)
    #define SHAPING_FREQ_Y 40 // （Hz）Y轴的默认主频。
    #define SHAPING_ZETA_Y 0.15f // Y轴的阻尼比（范围：0.0 = 无阻尼到1.0 = 临界阻尼）。
  #endif
  //#define SHAPING_MIN_FREQ 20 // 默认的整形频率的最小值。覆盖以影响SRAM使用情况。
  //#define SHAPING_MAX_STEPRATE 10000 // 默认的整形轴的最大总步进速率。覆盖以影响SRAM使用情况。
  //#define SHAPING_MENU // 在LCD上添加菜单以设置整形参数。
#endif

// @section motion

#define AXIS_RELATIVE_MODES { false, false, false, false }

// 为独立的喷嘴添加一个重复选项
//#define MULTI_NOZZLE_DUPLICATION

// 默认情况下，步进驱动器需要一个高电平信号，但某些高功率驱动器需要一个低电平信号来进行步进。
#define STEP_STATE_X HIGH
#define STEP_STATE_Y HIGH
#define STEP_STATE_Z HIGH
#define STEP_STATE_I HIGH
#define STEP_STATE_J HIGH
#define STEP_STATE_K HIGH
#define STEP_STATE_U HIGH
#define STEP_STATE_V HIGH
#define STEP_STATE_W HIGH
#define STEP_STATE_E HIGH

/**
 * 空闲步进电机关闭
 * 启用 DISABLE_IDLE_* 可在空闲时间后关闭轴步进电机。
 * 默认超时时间可以使用 M18 和 M84 进行覆盖。设置为 0 表示没有超时。
 */
#define DEFAULT_STEPPER_TIMEOUT_SEC 120
// #define DISABLE_IDLE_X
// #define DISABLE_IDLE_Y
// #define DISABLE_IDLE_Z    // 如果喷嘴可能会落到打印部件上，请禁用！
//#define DISABLE_IDLE_I
//#define DISABLE_IDLE_J
//#define DISABLE_IDLE_K
//#define DISABLE_IDLE_U
//#define DISABLE_IDLE_V
//#define DISABLE_IDLE_W
#define DISABLE_IDLE_E    // 关闭所有空闲挤出机

// 默认的打印和移动最小进给速度
#define DEFAULT_MINIMUMFEEDRATE             0.0     // (mm/s) 最小进给速度。使用 M205 S 进行设置。
#define DEFAULT_MINTRAVELFEEDRATE           0.0     // (mm/s) 最小移动进给速度。使用 M205 T 进行设置。
#if HAS_ROTATIONAL_AXES
  #define DEFAULT_ANGULAR_MINIMUMFEEDRATE   0.0     // (°/s) 旋转移动的最小进给速度。使用 M205 P 进行设置。
  #define DEFAULT_ANGULAR_MINTRAVELFEEDRATE 0.0     // (°/s) 旋转移动的最小旅行进给速度。使用 M205 Q 进行设置。
#endif

// 缓冲区清空时，段需要占用的最小时间
#define DEFAULT_MINSEGMENTTIME        20000   // (µs) 使用 M205 B 进行设置。

// 如果前瞻缓冲区（默认情况下）半满，则减慢机器速度。
// 增加减速因子以适应更大的缓冲区。
#define SLOWDOWN
#if ENABLED(SLOWDOWN)
  #define SLOWDOWN_DIVISOR 2
#endif

/**
 * XY 频率限制
 * 通过限制小的锯齿填充移动的频率来减少共振。
 * 参见 https://hydraraptor.blogspot.com/2010/12/frequency-limit.html
 * 使用 M201 F<freq> G<min%> 在运行时更改限制。
 */
//#define XY_FREQUENCY_LIMIT      10 // (Hz) 小的锯齿填充移动的最大频率。使用 M201 F<hertz> 进行设置。
#ifdef XY_FREQUENCY_LIMIT
  #define XY_FREQUENCY_MIN_PERCENT 5 // (percent) 应用的最小 FR 百分比。使用 M201 G<min%> 进行设置。
#endif

// 最小规划器接头速度。设置规划器在缓冲区的末尾和所有停止时的默认最小速度。
// 这个值不应该比零大太多，只有在用户的机器上以非常低的速度运行时观察到不希望的行为时才应该更改。
#define MINIMUM_PLANNER_SPEED 0.05 // (mm/s)

//
// 回程补偿
// 在方向改变时为轴添加额外的运动以补偿回程误差。
//
//#define BACKLASH_COMPENSATION
#if ENABLED(BACKLASH_COMPENSATION)
  // 定义间隙距离和校正值。
  // 如果启用了BACKLASH_GCODE，这些值是默认值。
  #define BACKLASH_DISTANCE_MM { 0, 0, 0 } // （线性=毫米，旋转=°）每个线性轴一个值
  #define BACKLASH_CORRECTION 0.0 // 0.0 = 无校正；1.0 = 完全校正

  // 在CORE运动学中添加电机方向更改的步骤
  //#define CORE_BACKLASH

  // 将BACKLASH_SMOOTHING_MM设置为在多个线段上分布间隙校正
  // 以减少打印效果上的伪像。（启用此功能会消耗大量的内存和计算！）
  //#define BACKLASH_SMOOTHING_MM 3 // （mm）

  // 运行时配置和校准间隙值的补偿（M425）
  //#define BACKLASH_GCODE

  #if ENABLED(BACKLASH_GCODE)
    // 在探测时测量Z间隙（G29）并使用“M425 Z”设置。
    #define MEASURE_BACKLASH_WHEN_PROBING

    #if ENABLED(MEASURE_BACKLASH_WHEN_PROBING)
      // 在测量时，探针将向远离接触点BACKLASH_MEASUREMENT_LIMIT
      // mm的位置移动，并在检测到断开接触时检查。
      #define BACKLASH_MEASUREMENT_LIMIT 0.5 // （mm）
      #define BACKLASH_MEASUREMENT_RESOLUTION 0.005 // （mm）
      #define BACKLASH_MEASUREMENT_FEEDRATE Z_PROBE_FEEDRATE_SLOW // （mm/min）
    #endif
  #endif
#endif

/**
 * 自动间隙、位置和挤出头偏移校准
 *
 * 启用G425以使用电导立方体、螺栓或垫圈在打印床上进行自动校准。
 *
 * G425使用探针接触床上的校准物体的顶部和侧面，并测量和/或校正位置偏移、轴向间隙
 * 和挤出头偏移。
 *
 * 注意：HOTEND_OFFSET和CALIBRATION_OBJECT_CENTER必须设置为真实值的±5mm以内，
 *       G425才能成功。
 */
//#define CALIBRATION_GCODE
#if ENABLED(CALIBRATION_GCODE)

  //#define CALIBRATION_SCRIPT_PRE  "M117 Starting Auto-Calibration\nT0\nG28\nG12\nM117 Calibrating..."
  //#define CALIBRATION_SCRIPT_POST "M500\nM117 Calibration data saved"

  #define CALIBRATION_MEASUREMENT_RESOLUTION 0.01 // mm

  #define CALIBRATION_FEEDRATE_SLOW 60 // mm/min
  #define CALIBRATION_FEEDRATE_FAST 1200 // mm/min
  #define CALIBRATION_FEEDRATE_TRAVEL 3000 // mm/min

  // 下面的参数是指喷嘴尖的锥形部分。
  #define CALIBRATION_NOZZLE_TIP_HEIGHT 1.0 // mm
  #define CALIBRATION_NOZZLE_OUTER_DIAMETER 2.0 // mm

  // 取消注释以启用报告（对于“G425 V”是必需的，但会消耗PROGMEM）。
  //#define CALIBRATION_REPORTING

  // 床上校准物体的真实位置和尺寸。
  #define CALIBRATION_OBJECT_CENTER { 264.0, -22.0,  -2.0 } // mm
  #define CALIBRATION_OBJECT_DIMENSIONS {  10.0,  10.0,  10.0 } // mm

  // 注释掉任何探测器无法接触到的边。为了获得最佳的
  // 自动校准结果，必须能够接触到所有的边。
  #define CALIBRATION_MEASURE_RIGHT
  #define CALIBRATION_MEASURE_FRONT
  #define CALIBRATION_MEASURE_LEFT
  #define CALIBRATION_MEASURE_BACK

  //#define CALIBRATION_MEASURE_IMIN
  //#define CALIBRATION_MEASURE_IMAX
  //#define CALIBRATION_MEASURE_JMIN
  //#define CALIBRATION_MEASURE_JMAX
  //#define CALIBRATION_MEASURE_KMIN
  //#define CALIBRATION_MEASURE_KMAX
  //#define CALIBRATION_MEASURE_UMIN
  //#define CALIBRATION_MEASURE_UMAX
  //#define CALIBRATION_MEASURE_VMIN
  //#define CALIBRATION_MEASURE_VMAX
  //#define CALIBRATION_MEASURE_WMIN
  //#define CALIBRATION_MEASURE_WMAX

  // 在顶部中心进行探测只有在中心是平的情况下才有效。如果
  // 在螺钉头或空心垫圈上进行探针，请在边缘附近进行探针。
  //#define CALIBRATION_MEASURE_AT_TOP_EDGES

  // 定义在校准过程中读取的引脚
  #ifndef CALIBRATION_PIN
    //#define CALIBRATION_PIN -1 // 在此处定义以覆盖默认引脚
    #define CALIBRATION_PIN_INVERTING false // 设置为true以反转自定义引脚
    //#define CALIBRATION_PIN_PULLDOWN
    #define CALIBRATION_PIN_PULLUP
  #endif
#endif

/**
 * 多步运行以突发方式发送步骤，以减少高步进率时MCU的使用率。
 * 这样可以实现比MCU本身支持的更高进给速度。
 */
#define MULTISTEPPING_LIMIT   16  //: [1, 2, 4, 8, 16, 32, 64, 128]

/**
 * 自适应步进平滑增加了多轴移动的分辨率，特别是在步进频率
 * 低于1kHz（对于AVR）或10kHz（对于ARM）时，多轴移动中的轴之间的混叠会引起可听的
 * 振动和表面伪影。该算法根据最低步进频率来自适应地提供最佳的步进平滑效果。
 */
//#define ADAPTIVE_STEP_SMOOTHING

/**
 * 自定义微步设置
 * 根据需要覆盖您的设置。支持最多3个MS引脚。
 */
//#define MICROSTEP1 LOW,LOW,LOW
//#define MICROSTEP2 HIGH,LOW,LOW
//#define MICROSTEP4 LOW,HIGH,LOW
//#define MICROSTEP8 HIGH,HIGH,LOW
//#define MICROSTEP16 LOW,LOW,HIGH
//#define MICROSTEP32 HIGH,LOW,HIGH

// 微步设置（需要具有名为X_MS1、X_MS2等的引脚的板子）。
#define MICROSTEP_MODES { 16, 16, 16, 16, 16, 16 } // [1,2,4,8,16]

/**
 *  @section  步进电机电流
 *
 * 一些板具有通过固件设置步进电机电流的方法。
 *
 * 打开后，上电时的电机电流由以下设置确定：
 *    PWM_MOTOR_CURRENT - 适用于MINIRAMBO和ULTIMAIN_2
 *                        已知兼容芯片：A4982
 *    DIGIPOT_MOTOR_CURRENT - 适用于BQ_ZUM_MEGA_3D、RAMBO和SCOOVO_X9H
 *                        已知兼容芯片：AD5206
 *    DAC_MOTOR_CURRENT_DEFAULT - 适用于PRINTRBOARD_REVF和RIGIDBOARD_V2
 *                        已知兼容芯片：MCP4728
 *    DIGIPOT_I2C_MOTOR_CURRENTS - 适用于5DPRINT、AZTEEG_X3_PRO、AZTEEG_X5_MINI_WIFI、MIGHTYBOARD_REVE
 *                        已知兼容芯片：MCP4451、MCP4018
 *
 * 电机电流也可以由M907-M910和LCD设置。
 *    M907 - 应用于所有。
 *    M908 - BQ_ZUM_MEGA_3D、RAMBO、PRINTRBOARD_REVF、RIGIDBOARD_V2和SCOOVO_X9H
 *    M909、M910和LCD - 仅适用于PRINTRBOARD_REVF和RIGIDBOARD_V2
 */
//#define PWM_MOTOR_CURRENT { 1300, 1300, 1250 }          // 毫安值
//#define DIGIPOT_MOTOR_CURRENT { 135,135,135,135,135 }   // 0-255之间的值（RAMBO 135 = ~0.75A，185 = ~1A）
//#define DAC_MOTOR_CURRENT_DEFAULT { 70, 80, 90, 80 }    // 默认驱动百分比 - X、Y、Z、E轴

/**
 * 基于I2C的数字电位器（例如，Azteeg X3 Pro）
 */
//#define DIGIPOT_MCP4018             // 需要https://github.com/felias-fogg/SlowSoftI2CMaster
//#define DIGIPOT_MCP4451
#if ANY(DIGIPOT_MCP4018, DIGIPOT_MCP4451)
  #define DIGIPOT_I2C_NUM_CHANNELS 8  // 5DPRINT：4   AZTEEG_X3_PRO：8   MKS_SBASE：5   MIGHTYBOARD_REVE：5

  // 实际电机电流（以安培为单位）。条目数量必须与DIGIPOT_I2C_NUM_CHANNELS相匹配。
  // 这些对应于物理驱动器，因此如果更改顺序，请注意。
  #define DIGIPOT_I2C_MOTOR_CURRENTS { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 } // AZTEEG_X3_PRO

  //#define DIGIPOT_USE_RAW_VALUES    // 使用DIGIPOT_MOTOR_CURRENT原始游标值（而不是A4988步进电机电流）

  /**
   * 常见的从器地址：
   *
   *                        A   (A shifted)   B   (B shifted)  IC
   * Smoothie              0x2C (0x58)       0x2D (0x5A)       MCP4451
   * AZTEEG_X3_PRO         0x2C (0x58)       0x2E (0x5C)       MCP4451
   * AZTEEG_X5_MINI        0x2C (0x58)       0x2E (0x5C)       MCP4451
   * AZTEEG_X5_MINI_WIFI         0x58              0x5C        MCP4451
   * MIGHTYBOARD_REVE      0x2F (0x5E)                         MCP4018
   */
  //#define DIGIPOT_I2C_ADDRESS_A 0x2C  // 第一个DIGIPOT的未移位从器地址
  //#define DIGIPOT_I2C_ADDRESS_B 0x2D  // 第二个DIGIPOT的未移位从器地址
#endif

//===========================================================================
//=============================附加功能===========================
//===========================================================================

// @section lcd

#if HAS_MANUAL_MOVE_MENU
  #define MANUAL_FEEDRATE { 50*60, 50*60, 4*60, 2*60 } // （mm/min）面板上手动移动的进给速度
  #define FINE_MANUAL_MOVE 0.025    // （mm）大多数机器上应用于Z轴的最小手动移动（< 0.1mm）
  #if IS_ULTIPANEL
    #define MANUAL_E_MOVES_RELATIVE // 显示挤出器移动距离而不是“位置”
    #define ULTIPANEL_FEEDMULTIPLY  // 编码器在状态屏幕上设置进给倍增器
  #endif
#endif

// 当旋转编码器速度更快时，更快地更改值
#define ENCODER_RATE_MULTIPLIER
#if ENABLED(ENCODER_RATE_MULTIPLIER)
  #define ENCODER_10X_STEPS_PER_SEC   30  // （步骤/秒）10倍速度的编码器速率
  #define ENCODER_100X_STEPS_PER_SEC  80  // （步骤/秒）100倍速度的编码器速率
#endif

// 在更改进给速度时播放提示音
//#define BEEP_ON_FEEDRATE_CHANGE
#if ENABLED(BEEP_ON_FEEDRATE_CHANGE)
  #define FEEDRATE_CHANGE_BEEP_DURATION   10
  #define FEEDRATE_CHANGE_BEEP_FREQUENCY 440
#endif

//
// LCD背光超时
//
//#define LCD_BACKLIGHT_TIMEOUT_MINS 1  // （分钟）背光关闭之前的超时时间

#if HAS_BED_PROBE && ANY(HAS_MARLINUI_MENU, HAS_TFT_LVGL_UI)
  #define PROBE_OFFSET_WIZARD       // 在LCD菜单中添加探针Z偏移校准选项
  #if ENABLED(PROBE_OFFSET_WIZARD)
    /**
     * 启用时，在启动向导时初始化探针Z偏移。
     * 使用略高于估计的喷嘴到探针Z偏移的高度。
     * 例如，偏移为-5，考虑一个起始高度为-4。
     */
    //#define PROBE_OFFSET_WIZARD_START_Z -4.0

    // 设置方便的位置进行校准（探头点和喷嘴/床距离）
    //#define PROBE_OFFSET_WIZARD_XY_POS { X_CENTER, Y_CENTER }
  #endif
#endif

#if HAS_MARLINUI_MENU

  #if HAS_BED_PROBE
    // 在探针偏移菜单中添加校正以补偿X轴扭曲。
    //#define X_AXIS_TWIST_COMPENSATION
    #if ENABLED(X_AXIS_TWIST_COMPENSATION)
      /**
       * 启用时，在启动向导时初始化探针Z偏移。
       * 使用略高于估计的喷嘴到探针Z偏移的高度。
       * 例如，偏移为-5，考虑一个起始高度为-4。
       */
      #define XATC_START_Z 0.0
      #define XATC_MAX_POINTS 3             // 向导中要探测的点数
      #define XATC_Y_POSITION Y_CENTER      // （mm）要探测的Y位置
      #define XATC_Z_OFFSETS { 0, 0, 0 }    // X轴样本点的Z偏移
    #endif

    // 在Motion菜单中显示部署/收起探针选项。
    #define PROBE_DEPLOY_STOW_MENU
  #endif

  // 在LCD菜单中包含一页打印机信息
  #define LCD_INFO_MENU
  #if ENABLED(LCD_INFO_MENU)
    //#define LCD_PRINTER_INFO_IS_BOOTSCREEN // 在打印机信息页上显示引导屏幕
  #endif

  // 添加50/100mm移动到MarlinUI，即使床较小
  #define LARGE_MOVE_ITEMS

  // BACK菜单项保持突出显示在顶部
  #define TURBO_BACK_MENU_ITEM

  // 在顶层插入一个预热菜单，以便快速访问
  //#define PREHEAT_SHORTCUT_MENU_ITEM

  // 在Configuration > Debug菜单中添加Endstop测试，用于端点/探针/退料测试
  #define LCD_ENDSTOP_TEST

#endif // HAS_MARLINUI_MENU

#if HAS_DISPLAY
  /**
   * ***供应商请注意***
   *
   * Marlin允许您为图形LCD添加自定义启动图像。
   * 使用此选项，Marlin首先显示您的自定义屏幕，然后显示带有版本号和Web URL的标准Marlin标志。
   *
   * 我们鼓励您利用此新功能，并恳请您保留未修改的Marlin启动屏幕。
   */
  #define SHOW_BOOTSCREEN                 // 启动时显示Marlin引导屏幕。**生产时启用**
  #if ENABLED(SHOW_BOOTSCREEN)
    #define BOOTSCREEN_TIMEOUT 500       // （ms）显示引导屏幕的总持续时间
    #if ANY(HAS_MARLINUI_U8GLIB, TFT_COLOR_UI)
      #define BOOT_MARLIN_LOGO_SMALL      // 在引导屏幕上显示较小的Marlin标志（节省大量闪存）
    #endif
    #if HAS_MARLINUI_U8GLIB
      //#define BOOT_MARLIN_LOGO_ANIMATED // 动画Marlin标志。闪存成本约为3260（或940）字节。
    #endif
    #if ANY(HAS_MARLINUI_U8GLIB, TOUCH_UI_FTDI_EVE)
      #define SHOW_CUSTOM_BOOTSCREEN      // 在启动时显示Marlin/_Bootscreen.h中的位图。
    #endif
  #endif

  #if HAS_MARLINUI_U8GLIB
      //#define CUSTOM_STATUS_SCREEN_IMAGE    // 在状态屏幕上显示Marlin/_Statusscreen.h中的位图。
  #endif

  #define SOUND_MENU_ITEM   // 在LCD菜单中添加静音选项
  #define SOUND_ON_DEFAULT    // 蜂鸣器/扬声器默认启用状态

  // 返回到状态屏幕的子菜单超时时间
  #define LCD_TIMEOUT_TO_STATUS 30000   // （ms）

  // 将较长的状态消息滚动到视图中
  #define STATUS_MESSAGE_SCROLLING

  // 对低优先级状态消息应用超时
  //#define STATUS_MESSAGE_TIMEOUT_SEC 30 // （秒）

  // 在信息屏幕上，当可能时，将XY显示为带有一位小数
  #define LCD_DECIMAL_SMALL_XY

  // 在打印过程中显示E位置（使用的挤出物量）
  #define LCD_SHOW_E_TOTAL

  // 显示负温度而不是“err”
  //#define SHOW_TEMPERATURE_BELOW_ZERO

  /**
   * LED控制菜单
   * 将LED控制添加到LCD菜单
   */
  //#define LED_CONTROL_MENU
  #if ENABLED(LED_CONTROL_MENU)
    #define LED_COLOR_PRESETS                 // 启用预设颜色菜单选项
    //#define NEO2_COLOR_PRESETS              // 启用第二个NeoPixel预设颜色菜单选项
    #if ENABLED(LED_COLOR_PRESETS)
      #define LED_USER_PRESET_RED        255  // 用户定义的红色值
      #define LED_USER_PRESET_GREEN      128  // 用户定义的绿色值
      #define LED_USER_PRESET_BLUE         0  // 用户定义的蓝色值
      #define LED_USER_PRESET_WHITE      255  // 用户定义的白色值
      #define LED_USER_PRESET_BRIGHTNESS 255  // 用户定义的亮度
      //#define LED_USER_PRESET_STARTUP       // 启动时让打印机显示用户定义的预设颜色
    #endif
    #if ENABLED(NEO2_COLOR_PRESETS)
      #define NEO2_USER_PRESET_RED        255 // 用户定义的红色值
      #define NEO2_USER_PRESET_GREEN      128 // 用户定义的绿色值
      #define NEO2_USER_PRESET_BLUE         0 // 用户定义的蓝色值
      #define NEO2_USER_PRESET_WHITE      255 // 用户定义的白色值
      #define NEO2_USER_PRESET_BRIGHTNESS 255 // 用户定义的亮度
      //#define NEO2_USER_PRESET_STARTUP      // 启动时让打印机显示用户定义的预设颜色（第二个灯带）
    #endif
  #endif

#endif // HAS_DISPLAY

// 添加'M73'以设置打印作业进度，覆盖Marlin的内置估计值
#define SET_PROGRESS_MANUALLY
#if ENABLED(SET_PROGRESS_MANUALLY)
  #define SET_PROGRESS_PERCENT            // 添加'P'参数以设置完成百分比
  //#define SET_REMAINING_TIME            // 添加'R'参数以设置剩余时间
  //#define SET_INTERACTION_TIME          // 添加'C'参数以设置直到下一次换丝或其他用户交互的时间
  //#define M73_REPORT                    // 向主机报告M73值
  #if ALL(M73_REPORT, HAS_MEDIA)
    #define M73_REPORT_SD_ONLY            // 仅在从SD卡打印时报告
  #endif
#endif

// LCD打印进度选项。可以轮流显示多个时间。
#if HAS_DISPLAY && ANY(HAS_MEDIA, SET_PROGRESS_MANUALLY)
  #define SHOW_PROGRESS_PERCENT           // 显示打印进度百分比（不影响进度条）
  #define SHOW_ELAPSED_TIME               // 显示已打印时间（前缀'E'）
  #define SHOW_REMAINING_TIME           // 显示估计完成时间（前缀'R'）
  #if ENABLED(SET_INTERACTION_TIME)
    #define SHOW_INTERACTION_TIME         // 显示直到下一次用户交互的时间（'C' = 换丝）
  #endif
  #define PRINT_PROGRESS_SHOW_DECIMALS  // 显示/报告带有小数位的进度，而不是所有UI都支持此功能

  #if ANY(HAS_MARLINUI_HD44780, IS_TFTGLCD_PANEL)
    //#define LCD_PROGRESS_BAR            // 在HD44780 LCD上显示进度条以进行SD打印
    #if ENABLED(LCD_PROGRESS_BAR)
      #define PROGRESS_BAR_BAR_TIME 2000  // （ms）显示进度条的时间
      #define PROGRESS_BAR_MSG_TIME 3000  // （ms）显示状态消息的时间
      #define PROGRESS_MSG_EXPIRE      0  // （ms）保留状态消息的时间（0=永久）
      //#define PROGRESS_MSG_ONCE         // 显示消息MSG_TIME然后清除它
      //#define LCD_PROGRESS_BAR_TEST     // 添加一个菜单项以测试进度条
    #endif
  #endif
#endif

#if HAS_MEDIA
  /**
   * SD卡SPI速度
   * 可能需要解决“卷初始化”错误。
   *
   * 启用并设置为SPI_HALF_SPEED、SPI_QUARTER_SPEED或SPI_EIGHTH_SPEED，
   * 否则将应用全速。
   *
   * :['SPI_HALF_SPEED'，'SPI_QUARTER_SPEED'，'SPI_EIGHTH_SPEED']
   */
  #define SD_SPI_SPEED SPI_HALF_SPEED

  // 标准SD检测电路在插入介质时读取为LOW，在空时读取为HIGH。
  // 如果您的SD卡检测不正确，请启用此选项并设置为HIGH。
  //#define SD_DETECT_STATE HIGH

  //#define SD_IGNORE_AT_STARTUP            // 启动时不加载SD卡
  //#define SDCARD_READONLY                 // 只读SD卡（以节省2K以上的闪存）

  //#define GCODE_REPEAT_MARKERS            // 启用G-code M808设置重复标记并进行循环

  #define SD_PROCEDURE_DEPTH 1              // 增加如果您需要更多嵌套的M32调用

  //#define SD_FINISHED_STEPPERRELEASE true   // SD打印完成后禁用步进电机
  #define SD_FINISHED_RELEASECOMMAND "M84"  // 使用“M84XYE”保持Z启用，以使床保持在原地

  // 反向SD排序以首先显示“最近的”文件，根据卡的FAT。
  // 由于FAT在使用中会失序，建议使用SDCARD_SORT_ALPHA。
  #define SDCARD_RATHERRECENTFIRST

  #define SD_MENU_CONFIRM_START             // 打印前确认所选的SD文件

  #define NO_SD_AUTOSTART                 // 完全删除auto#.g文件支持以节省一些闪存，SRAM
  //#define MENU_ADDAUTOSTART               // 添加一个菜单选项来运行auto#.g文件

  #define ONE_CLICK_PRINT                 // 在插入介质时提示打印最新的文件
  //#define BROWSE_MEDIA_ON_INSERT          // 插入介质时打开文件浏览器

  //#define MEDIA_MENU_AT_TOP               // 强制将媒体菜单列在主菜单顶部

  #define EVENT_GCODE_SD_ABORT "G28XY"      // SD中止打印时运行的G-code（例如“G28XY”或“G27”）

  #if ENABLED(PRINTER_EVENT_LEDS)
    #define PE_LEDS_COMPLETED_TIME  (30*60) // （秒）恢复正常照明之前保持LED“完成”颜色的时间
  #endif

  /**
   * 在断电后继续打印（Creality3D）
   *
   * 在SD打印期间，将当前状态存储到SD卡中的每个层的开始。
   * 如果在引导时找到恢复文件，则在LCD屏幕上提供一个选项，
   * 以从文件中的最后已知点继续打印。
   */
  #define POWER_LOSS_RECOVERY
  #if ENABLED(POWER_LOSS_RECOVERY)
    #define PLR_ENABLED_DEFAULT   true // 默认情况下启用断电恢复。（使用'M413 Sn'和'M500'设置）
    //#define BACKUP_POWER_SUPPLY       // 备用电源 / UPS在断电时移动步进电机
    //#define POWER_LOSS_ZRAISE       2 // （mm）恢复时Z轴提升（断电时使用UPS）
    //#define POWER_LOSS_PIN         44 // 检测断电的引脚。设置为-1以禁用没有模块的板上默认引脚。
    //#define POWER_LOSS_STATE     HIGH // 表示断电的引脚状态
    //#define POWER_LOSS_PULLUP         // 设置上拉/下拉以适应传感器
    //#define POWER_LOSS_PULLDOWN
    //#define POWER_LOSS_PURGE_LEN   20 // （mm）恢复时的抽丝长度
    //#define POWER_LOSS_RETRACT_LEN 10 // （mm）失败时的回抽长度。需要备用电源。

    // 没有POWER_LOSS_PIN的情况下，以下选项有助于减少对SD卡的磨损，
    // 特别是在“花瓶模式”打印时。设置过高将无法继续花瓶。
    #define POWER_LOSS_MIN_Z_CHANGE 0.05 // （mm）保存断电数据之前的最小Z变化

    // 如果需要正确恢复，则启用Z归位。99.9%的时间都应该禁用！
    //#define POWER_LOSS_RECOVER_ZHOME
    #if ENABLED(POWER_LOSS_RECOVER_ZHOME)
      //#define POWER_LOSS_ZHOME_POS { 0, 0 } // 安全的XY位置在避免平台上的对象的同时归位Z
    #endif
  #endif

  /**
   * 将SD文件列表按字母顺序排序。
   *
   * 启用此选项后，SD卡上的项目将按名称排序，以便更容易导航。
   *
   * 默认情况下...
   *
   *  - 使用最慢但最安全的方法进行排序。
   *  - 文件夹排序到顶部。
   *  - 排序键是静态分配的。
   *  - 无增加的G-code（M34）支持。
   *  - 40项排序限制。（第41项之后的项目未排序。）
   *
   * SD排序使用静态分配（由SDSORT_LIMIT设置），允许编译器计算最坏情况下的使用情况，
   * 如果SRAM限制超出，则引发错误。
   *
   *  - SDSORT_USES_RAM提供更快的预排序通过静态目录缓冲区。
   *  - SDSORT_USES_STACK也是如此，但使用本地基于堆栈的缓冲区。
   *  - SDSORT_CACHE_NAMES将在RAM中保留排序的文件列表以获得快速性能。最昂贵的选项。
   *  - SDSORT_DYNAMIC_RAM仅在SD菜单可见时使用RAM。（谨慎使用！）
   */
  #define SDCARD_SORT_ALPHA

  // SD卡排序选项
  #if ENABLED(SDCARD_SORT_ALPHA)
    #define SDSORT_LIMIT       40     // 最大排序项数（10-256）。每个项目花费27个字节。
    #define FOLDER_SORTING     -1     // -1=上面  0=无  1=下面
    #define SDSORT_GCODE       false  // 允许使用LCD和M34 G-code打开/关闭排序。
    #define SDSORT_USES_RAM    true  // 为更快的预排序预分配静态数组。
    #define SDSORT_USES_STACK  false  // 首选堆栈进行预排序以释放一些SRAM。（下面两个选项取反。）
    #define SDSORT_CACHE_NAMES true  // 在RAM中保持排序的项目更长时间以获得快速性能。最昂贵的选项。
    #define SDSORT_DYNAMIC_RAM false  // 仅在SD菜单可见时使用动态分配。（请谨慎使用！在使用之前设置SDSORT_LIMIT！）
    #define SDSORT_CACHE_VFATS 2      // 用于排序的最大13字节VFAT条目数。
                                    // 注意：仅影响具有SDSORT_CACHE_NAMES的SCROLL_LONG_FILENAMES，但不影响SDSORT_DYNAMIC_RAM。
  #endif

  // 允许在长文件名中使用国际符号。为了正确显示，LCD的字体必须包含这些字符。检查所选的LCD语言。
  #define UTF_FILENAME_SUPPORT

  #define LONG_FILENAME_HOST_SUPPORT      // 使用'M33 <dosname>'获取文件/文件夹的长文件名，并使用'M20 L'列出长文件名
  #define LONG_FILENAME_WRITE_SUPPORT   // 使用长文件名通过M28、M30和二进制传输协议创建/删除文件
  #define M20_TIMESTAMP_SUPPORT         // 通过将'T'标志添加到M20命令来包含时间戳

  #define SCROLL_LONG_FILENAMES           // 在SD卡菜单中滚动长文件名

  //#define SD_ABORT_NO_COOLDOWN          // 停止打印后保持加热器开启（不建议！）

  /**
   * 在任何端点触发时中止SD打印。
   * 使用“M540 S1”或LCD菜单启用此功能。
   * 必须激活端点才能使用此选项。
   */
  //#define SD_ABORT_ON_ENDSTOP_HIT
  #if ENABLED(SD_ABORT_ON_ENDSTOP_HIT)
    //#define SD_ABORT_ON_ENDSTOP_HIT_GCODE "G28XY" // 端点触发时运行的G-code（例如“G28XY”或“G27”）
  #endif

  //#define SD_REPRINT_LAST_SELECTED_FILE // 在打印完成后打开LCD菜单并选择相同的文件

  //#define AUTO_REPORT_SD_STATUS         // 自动报告媒体状态，间隔为'S<seconds>'

  /**
   * 支持使用Arduino USB Host Shield或等效的MAX3421E breakout板的USB闪存驱动器。
   * USB闪存驱动器将在Marlin中显示为SD卡。
   *
   * MAX3421E可以与SD卡读卡器分配相同的引脚，具体如下：
   *
   *    SCLK，MOSI，MISO --> SCLK，MOSI，MISO
   *    INT              --> SD_DETECT_PIN [1]
   *    SS               --> SDSS
   *
   * [1] 在AVR上，支持中断的引脚最适合UHS3兼容性。
   */
  //#define USB_FLASH_DRIVE_SUPPORT
  #if ENABLED(USB_FLASH_DRIVE_SUPPORT)
    /**
     * USB主机盾库
     *
     * - UHS2不使用中断并经过生产测试
     *   在带有32位Archim板的LulzBot TAZ Pro上。
     *
     * - UHS3是具有更好USB兼容性的新代码。但它
     *   测试较少，已知会干扰舵机。
     *   [1] 这需要USB_INTR_PIN具有中断功能。
     */
    //#define USE_UHS2_USB
    //#define USE_UHS3_USB

    #define DISABLE_DUE_SD_MMC // 禁用USB主机对USB驱动器的访问，以防止块访问时挂起的情况

    /**
     * 由某些板支持的本机USB主机（USB OTG）
     */
    //#define USE_OTG_USB_HOST

    #if DISABLED(USE_OTG_USB_HOST)
      #define USB_CS_PIN    SDSS
      #define USB_INTR_PIN  SD_DETECT_PIN
    #endif
  #endif

  /**
   * 使用支持SD-Firmware-Flashing的引导加载程序时，启用此选项，
   * 添加一个菜单项以在下次重启时激活SD-FW-Update。
   *
   * 需要ATMEGA2560（Arduino Mega）
   *
   * 使用过以下引导加载程序进行测试：
   *   https://github.com/FleetProbe/MicroBridge-Arduino-ATMega2560
   */
  //#define SD_FIRMWARE_UPDATE
  #if ENABLED(SD_FIRMWARE_UPDATE)
    #define SD_FIRMWARE_UPDATE_EEPROM_ADDR    0x1FF
    #define SD_FIRMWARE_UPDATE_ACTIVE_VALUE   0xF0
    #define SD_FIRMWARE_UPDATE_INACTIVE_VALUE 0xFF
  #endif

  /**
   * 如果您有超过~3K未使用的闪存空间，请启用此选项。
   * Marlin将所有设置作为压缩数据嵌入到固件二进制文件中。
   * 使用'M503 C'将设置写入SD卡作为'mc.zip'。
   * 有关如何使用'mc-apply.py'的详细信息，请参阅docs/ConfigEmbedding.md。
   */
  //#define CONFIGURATION_EMBEDDING

  // 添加一个优化的二进制文件传输模式，使用'M28 B1'启动
  #define BINARY_FILE_TRANSFER

  #if ENABLED(BINARY_FILE_TRANSFER)
    // 包括通过BINARY_FILE_TRANSFER支持固件上传的其他功能（例如，'M20 F'）
    #define CUSTOM_FIRMWARE_UPLOAD
  #endif

  /**
   * 将此选项设置为以下之一（否则适用于板的默认设置）：
   *
   *           LCD - 使用外部LCD控制器中的SD驱动器。
   *       ONBOARD - 使用控制板上的SD驱动器。
   *  CUSTOM_CABLE - 使用自定义电缆访问SD（如在引脚文件中定义）。
   *
   * :[ 'LCD'，'ONBOARD'，'CUSTOM_CABLE' ]
   */
  //#define SDCARD_CONNECTION ONBOARD

  // 如果SD检测变得无用（例如，通过使用SD扩展器）
  //#define NO_SD_DETECT

  /**
   * 多卷支持-实验性。
   * 添加'M21 Pm' / 'M21 S' / 'M21 U'以挂载SD卡/ USB驱动器。
   */
  //#define MULTI_VOLUME
  #if ENABLED(MULTI_VOLUME)
    #define VOLUME_SD_ONBOARD
    #define VOLUME_USB_FLASH_DRIVE
    #define DEFAULT_VOLUME SV_SD_ONBOARD
    #define DEFAULT_SHARED_VOLUME SV_USB_FLASH_DRIVE
  #endif

#endif // HAS_MEDIA

/**
 * 默认情况下，内置SD卡读卡器可能会作为USB大容量存储设备共享。
 * 此选项将SD卡从主机PC隐藏。
 */
//#define NO_SD_HOST_DRIVE   // 禁用通过USB访问SD卡（出于安全考虑）。

/**
 * 默认情况下，框架负责共享媒体I/O。
 * 如果需要，启用此选项以使Marlin负责共享媒体I/O。
 * 如果某些板上共享媒体无法正常工作，则使用此选项很有用。
 */
#if HAS_MEDIA && DISABLED(NO_SD_HOST_DRIVE)
  //#define DISKIO_HOST_DRIVE
#endif

/**
 * 图形显示附加选项
 *
 * 使用这里的优化功能以提高打印性能，
 * 这受到图形显示绘图的不利影响，
 * 特别是在进行多个短距离移动和在DELTA和SCARA机器上打印时。
 *
 * 在可靠的打印性能与快速显示更新之间存在权衡。
 * 一些选项可能导致显示落后于控制器事件，
 * 因为可靠的打印性能与快速显示更新之间存在权衡。
 */
#if HAS_MARLINUI_U8GLIB
  // 通过绘制空心框或无框在信息屏幕上节省许多周期
  //#define XYZ_NO_FRAME
  #define XYZ_HOLLOW_FRAME

  // 可在编辑项目中使用更大的字体。闪存成本3120字节。
  // 仅适用于西文。不适用于西里尔文、假名、土耳其文、希腊文或中文。
  //#define USE_BIG_EDIT_FONT

  // 信息屏幕上可以使用较小的字体。闪存成本2434字节。
  // 仅适用于西文。不适用于西里尔文、假名、土耳其文、希腊文或中文。
  //#define USE_SMALL_INFOFONT

  /**
   * 图形显示器休眠
   *
   * U8G库提供了SH1106、SSD1306、SSD1309和其他一些DOGM显示器的休眠/唤醒功能。
   * 启用此选项以节省能源并防止OLED像素烧结。
   * 添加菜单项“配置> LCD超时（m）”以设置等待时间
   * 从0（禁用）到99分钟。
   */
  //#define DISPLAY_SLEEP_MINUTES 2  // （分钟）屏幕关闭之前的超时时间。使用M255 S设置。

  /**
   * 基于ST7920的LCD可以使用ST7920字符生成器模拟16 x 4字符显示器，
   * 以实现非常快的屏幕更新。
   * 启用LIGHTWEIGHT_UI以使用此特殊显示模式。
   *
   * 由于LIGHTWEIGHT_UI的空间有限，位置和状态消息占用同一行。
   * 将STATUS_EXPIRE_SECONDS设置为显示状态消息之前的持续时间。
   *
   * 将STATUS_EXPIRE_SECONDS设置为零以永不清除状态。
   * 这将防止显示位置更新。
   */
  #if IS_U8GLIB_ST7920
    // 启用此选项并减小该值以优化屏幕更新。
    // 正常延迟为10µs。使用最低值以获得可靠的显示。
    //#define DOGM_SPI_DELAY_US 5

    //#define LIGHTWEIGHT_UI
    #if ENABLED(LIGHTWEIGHT_UI)
      #define STATUS_EXPIRE_SECONDS 20
    #endif
  #endif

  /**
   * 状态（信息）屏幕自定义
   * 这些选项可能会影响代码大小和屏幕渲染时间。
   * 自定义状态屏幕可以强制覆盖这些设置。
   */
  //#define STATUS_COMBINE_HEATERS    // 使用组合的加热器图像而不是分离的图像
  //#define STATUS_HOTEND_NUMBERLESS  // 使用普通的喷嘴图标而不是带编号的图标（有多个喷嘴时）
  #define STATUS_HOTEND_INVERTED      // 在加热时显示实心喷嘴位图（仅适用于带编号的喷嘴）
  #define STATUS_HOTEND_ANIM          // 使用第二个位图指示喷嘴加热
  #define STATUS_BED_ANIM             // 使用第二个位图指示床加热
  #define STATUS_CHAMBER_ANIM         // 使用第二个位图指示腔室加热
  //#define STATUS_CUTTER_ANIM        // 使用第二个位图指示主轴/激光激活
  //#define STATUS_COOLER_ANIM        // 使用第二个位图指示激光冷却
  //#define STATUS_FLOWMETER_ANIM     // 使用多个位图指示冷却液流量
  //#define STATUS_ALT_BED_BITMAP     // 使用备用床位图
  //#define STATUS_ALT_FAN_BITMAP     // 使用备用风扇位图
  //#define STATUS_FAN_FRAMES 3       // :[0,1,2,3,4] 风扇动画帧数
  #define STATUS_HEAT_PERCENT       // 显示加热进度条

  // 无关紧要的游戏选项
  #define MARLIN_BRICKOUT
  #define MARLIN_INVADERS
  #define MARLIN_SNAKE
  //#define GAMES_EASTER_EGG          // 在“Games”子菜单上方添加额外的空行

#endif // HAS_MARLINUI_U8GLIB

#if HAS_MARLINUI_U8GLIB || IS_DWIN_MARLINUI
  #define MENU_HOLLOW_FRAME           // 启用在菜单屏幕上绘制空心框以节省很多周期
  //#define OVERLAY_GFX_REVERSE       // 交换图形覆盖中的CW/CCW指示器
#endif

//
// DGUS / DWIN 显示的附加选项
//
#if HAS_DGUS_LCD
  #define LCD_BAUDRATE 115200

  #define DGUS_RX_BUFFER_SIZE 128
  #define DGUS_TX_BUFFER_SIZE 48
  //#define SERIAL_STATS_RX_BUFFER_OVERRUNS  // 修复 Rx 溢出情况（目前仅适用于 AVR）

  #define DGUS_UPDATE_INTERVAL_MS  500    // (ms) 自动屏幕更新之间的间隔

  #if DGUS_UI_IS(FYSETC, MKS, HIPRECY)
    #define DGUS_PRINT_FILENAME           // 打印时显示文件名
    #define DGUS_PREHEAT_UI               // 加热期间显示预热屏幕

    #if DGUS_UI_IS(FYSETC, MKS)
      //#define DGUS_UI_MOVE_DIS_OPTION   // FYSETC 和 MKS 默认禁用
    #else
      #define DGUS_UI_MOVE_DIS_OPTION     // UI_HIPRECY 默认启用
    #endif

    #define DGUS_FILAMENT_LOADUNLOAD
    #if ENABLED(DGUS_FILAMENT_LOADUNLOAD)
      #define DGUS_FILAMENT_PURGE_LENGTH 10
      #define DGUS_FILAMENT_LOAD_LENGTH_PER_TIME 0.5 // (mm) 根据 DGUS_UPDATE_INTERVAL_MS 比例调整
    #endif

    #define DGUS_UI_WAITING               // 在某些屏幕之间显示“等待”屏幕
    #if ENABLED(DGUS_UI_WAITING)
      #define DGUS_UI_WAITING_STATUS 10
      #define DGUS_UI_WAITING_STATUS_PERIOD 8 // 增加以减慢等待状态的循环
    #endif

  #elif DGUS_UI_IS(E3S1PRO)
    /**
     * 标准 Ender-3 S1 Pro/Plus 显示固件的 SD 文件处理能力较差。
     *
     * 自动滚动主要适用于状态消息、文件名和“关于”页面。
     *
     * 注意：高级 SD 卡选项受影响的是触摸屏固件，所以页面 5 及更高的显示为“4/4”。
     * 这个问题可能会在屏幕固件更新中得到修复。
     */
    #define DGUS_SOFTWARE_AUTOSCROLL        // 启用长文本软件自动滚动
    #define DGUS_AUTOSCROLL_START_CYCLES 1  // 无滚动的文本字符串开头的刷新周期数
    #define DGUS_AUTOSCROLL_END_CYCLES 1    // ... 文本字符串末尾的刷新周期数

    #define DGUS_ADVANCED_SDCARD            // 允许超过 20 个文件和导航目录
    #define DGUS_USERCONFIRM                // 重用 SD 卡页面显示各种消息
  #endif
#endif // HAS_DGUS_LCD

//
// AnyCubic Chiron TFT 显示的附加选项
//
#if ENABLED(ANYCUBIC_LCD_CHIRON)
  // 默认情况下会自动检测面板类型。
  // 如果您知道面板类型，请启用其中一个选项。
  //#define CHIRON_TFT_STANDARD
  //#define CHIRON_TFT_NEW

  // 启用更长的 Anycubic 启动声音
  //#define AC_DEFAULT_STARTUP_TUNE

  /**
   * 显示文件夹
   * 默认情况下，文件浏览器会以扁平列表显示所有 G-code 文件（包括子文件夹中的文件）。
   * 启用此选项以显示分层文件浏览器。
   *
   * 注意：
   * - 如果不启用此选项，则启用 SDCARD_SORT_ALPHA 可以使文件在文件夹之前/之后排序。
   * - 当与“new”面板一起使用时，文件夹名称也将在其名称后附加 '.gcode'。
   *   当前需要这个小技巧来强制面板显示文件夹。
   */
  #define AC_SD_FOLDER_VIEW
#endif

//
// 指定 UI 的其他语言。默认由 LCD_LANGUAGE 指定。
//
#if ANY(DOGLCD, TFT_COLOR_UI, TOUCH_UI_FTDI_EVE, IS_DWIN_MARLINUI, ANYCUBIC_LCD_VYPER)
  //#define LCD_LANGUAGE_2 fr
  //#define LCD_LANGUAGE_3 de
  //#define LCD_LANGUAGE_4 es
  //#define LCD_LANGUAGE_5 it
  #ifdef LCD_LANGUAGE_2
    //#define LCD_LANGUAGE_AUTO_SAVE // 在更改时自动保存语言到 EEPROM
  #endif
#endif

//
// 基于 FTDI 嵌入式视频引擎（EVE）的触摸 UI
//
#if ENABLED(TOUCH_UI_FTDI_EVE)
  // 使用的显示板
  //#define LCD_FTDI_VM800B35A        // FTDI 3.5 英寸，带 FT800（320x240）
  //#define LCD_4DSYSTEMS_4DLCD_FT843 // 4D Systems 4.3 英寸（480x272）
  //#define LCD_HAOYU_FT800CB         // Haoyu 4.3 英寸或 5 英寸（480x272）
  //#define LCD_HAOYU_FT810CB         // Haoyu 5 英寸（800x480）
  //#define LCD_LULZBOT_CLCD_UI       // LulzBot 彩色 LCD UI
  //#define LCD_FYSETC_TFT81050       // FYSETC 5 英寸（800x480）
  //#define LCD_EVE3_50G              // Matrix Orbital 5.0 英寸，800x480，BT815
  //#define LCD_EVE2_50G              // Matrix Orbital 5.0 英寸，800x480，FT813

  // 如果不使用原装 TFT 面板，请更正分辨率。
  //#define TOUCH_UI_320x240
  //#define TOUCH_UI_480x272
  //#define TOUCH_UI_800x480

  // 映射到标准 RepRapDiscount 显示器接口的板子
  //#define AO_EXP1_PINMAP      // LulzBot CLCD UI EXP1 映射
  //#define AO_EXP2_PINMAP      // LulzBot CLCD UI EXP2 映射
  //#define CR10_TFT_PINMAP     // Rudolph Riedel 的 CR10 映射
  //#define S6_TFT_PINMAP       // FYSETC S6 映射
  //#define F6_TFT_PINMAP       // FYSETC F6 映射

  //#define OTHER_PIN_LAYOUT  // 在下面手动定义引脚
  #if ENABLED(OTHER_PIN_LAYOUT)
    // 必须选择 CS 和 MOD_RESET（PD）的引脚
    #define CLCD_MOD_RESET  9
    #define CLCD_SPI_CS    10

    // 如果使用软件 SPI，则指定 SCLK、MOSI、MISO 的引脚
    //#define CLCD_USE_SOFT_SPI
    #if ENABLED(CLCD_USE_SOFT_SPI)
      #define CLCD_SOFT_SPI_MOSI 11
      #define CLCD_SOFT_SPI_MISO 12
      #define CLCD_SOFT_SPI_SCLK 13
    #endif
  #endif

  // 显示方向。FT800 支持倒置（即上下颠倒）显示。
  // FT810 及更高版本还支持纵向和镜像方向。
  //#define TOUCH_UI_INVERTED
  //#define TOUCH_UI_PORTRAIT
  //#define TOUCH_UI_MIRRORED

  // UTF8 处理和渲染。
  // 不支持的字符将显示为“？”。
  #define TOUCH_UI_USE_UTF8
  #if ENABLED(TOUCH_UI_USE_UTF8)
    // 西方重音符号支持。这些重音符号使用组合位图，存储空间相对较小。
    #define TOUCH_UI_UTF8_WESTERN_CHARSET
    #if ENABLED(TOUCH_UI_UTF8_WESTERN_CHARSET)
      // 其他字符组。这些字符需要完整的位图，并占用相当大的存储空间：
      #define TOUCH_UI_UTF8_SUPERSCRIPTS  // ¹ ² ³
      #define TOUCH_UI_UTF8_COPYRIGHT     // © ®
      #define TOUCH_UI_UTF8_GERMANIC      // ß
      #define TOUCH_UI_UTF8_SCANDINAVIAN  // Æ Ð Ø Þ æ ð ø þ
      #define TOUCH_UI_UTF8_PUNCTUATION   // « » ¿ ¡
      #define TOUCH_UI_UTF8_CURRENCY      // ¢ £ ¤ ¥
      #define TOUCH_UI_UTF8_ORDINALS      // º ª
      #define TOUCH_UI_UTF8_MATHEMATICS   // ± × ÷
      #define TOUCH_UI_UTF8_FRACTIONS     // ¼ ½ ¾
      #define TOUCH_UI_UTF8_SYMBOLS       // µ ¶ ¦ § ¬
    #endif

    // Cyrillic 字符集，大约需要 27KiB 的闪存
    //#define TOUCH_UI_UTF8_CYRILLIC_CHARSET
  #endif

  // 当标签不适合按钮时使用较小的字体
  #define TOUCH_UI_FIT_TEXT

  // 为“屏幕锁定”键盘使用数字密码。
  // （建议用于较小的显示屏）
  //#define TOUCH_UI_PASSCODE

  // 输出触摸 UI 事件的额外调试信息
  //#define TOUCH_UI_DEBUG

  // 开发者菜单（通过触摸“About Printer”版权文本访问）
  //#define TOUCH_UI_DEVELOPER_MENU
#endif

//
// 经典 UI 选项
//
#if TFT_SCALED_DOGLCD
  //#define TFT_MARLINUI_COLOR 0xFFFF // 白色
  //#define TFT_MARLINBG_COLOR 0x0000 // 黑色
  //#define TFT_DISABLED_COLOR 0x0003 // 几乎黑色
  //#define TFT_BTCANCEL_COLOR 0xF800 // 红色
  //#define TFT_BTARROWS_COLOR 0xDEE6 // 11011 110111 00110 黄色
  //#define TFT_BTOKMENU_COLOR 0x145F // 00010 100010 11111 青色
#endif

//
// ADC 按钮去抖动
//
#if HAS_ADC_BUTTONS
  #define ADC_BUTTON_DEBOUNCE_DELAY 16  // 如果按钮弹跳或重复太快，请增加此值
#endif

// @section safety

/**
 * 如果固件超载以至于无法读取温度传感器，看门狗硬件定时器将进行复位并禁用所有输出。
 *
 * 如果发现看门狗复位导致您的AVR板卡永远挂起，请启用WATCHDOG_RESET_MANUAL以使用自定义定时器。
 * 注意：此方法不太可靠，因为它只能在启用中断时捕获挂起。
 */
#define USE_WATCHDOG
#if ENABLED(USE_WATCHDOG)
  //#define WATCHDOG_RESET_MANUAL
#endif

// @section lcd

/**
 * 婴儿步进允许以微小增量移动轴，而不更改当前位置值。此功能主要用于实时调整打印的第一层的Z轴。
 *
 * 警告：不考虑限位开关！
 */
#define BABYSTEPPING
#if ENABLED(BABYSTEPPING)
  //#define EP_BABYSTEPPING                 // M293/M294支持EMERGENCY_PARSER的婴儿步进
  //#define BABYSTEP_WITHOUT_HOMING
  //#define BABYSTEP_ALWAYS_AVAILABLE       // 始终允许婴儿步进（不仅在运动时）
  //#define BABYSTEP_XY                     // 同时启用X/Y婴儿步进。DELTA不支持！
  //#define BABYSTEP_INVERT_Z               // 如果Z婴儿步进应该反向，请启用
  //#define BABYSTEP_MILLIMETER_UNITS       // 以毫米而不是微步为单位指定BABYSTEP_MULTIPLICATOR_(XY|Z)
  #define BABYSTEP_MULTIPLICATOR_Z  1       // （步进或毫米）每个Z婴儿步进的步进或毫米距离
  #define BABYSTEP_MULTIPLICATOR_XY 1       // （步进或毫米）每个XY婴儿步进的步进或毫米距离

  #define DOUBLECLICK_FOR_Z_BABYSTEPPING    // 在状态屏幕上双击进行Z轴婴儿步进。
  #if ENABLED(DOUBLECLICK_FOR_Z_BABYSTEPPING)
    #define DOUBLECLICK_MAX_INTERVAL 1250   // 点击之间的最大间隔，以毫秒为单位。
                                            // 注意：可能会添加额外的时间以减轻控制器延迟。
    #define MOVE_Z_WHEN_IDLE              // 当打印机空闲时，双击跳转到移动Z菜单。
    #if ENABLED(MOVE_Z_WHEN_IDLE)
      #define MOVE_Z_IDLE_MULTIPLICATOR 1   // 将1mm乘以此因子以获取移动步长。
    #endif
  #endif

  #define BABYSTEP_DISPLAY_TOTAL          // 显示自上次G28以来的总婴儿步进次数

  //#define BABYSTEP_ZPROBE_OFFSET          // 结合M851 Z和婴儿步进
  //#define BABYSTEP_GLOBAL_Z               // 结合M424 Z和婴儿步进

  #if ANY(BABYSTEP_ZPROBE_OFFSET, BABYSTEP_GLOBAL_Z)
    #if ENABLED(BABYSTEP_ZPROBE_OFFSET)
      //#define BABYSTEP_HOTEND_Z_OFFSET    // 对于多个热端，婴儿步进相对Z偏移
    #endif
    //#define BABYSTEP_GFX_OVERLAY          // 在Z偏移编辑器上启用图形叠加
  #endif
#endif

// @section extruder

/**
 * 线性压力控制 v1.5
 *
 * 假设：advance [steps] = k * (delta velocity [steps/s])
 * K=0 表示禁用 advance。
 *
 * 注意：LIN_ADVANCE 1.5 的 K 值与之前的版本不同！
 *
 * 对于直接驱动的 3mm PLA，推荐将 K 设置为约 0.22，驱动齿轮和热断点之间距离约为 6.5cm。
 * 对于弹性材料和较大距离，需要更大的 K 值。
 * 如果该算法产生的速度偏移比挤出机可以处理的速度偏移（与 E jerk 相比）大，
 * 则在受影响的移动期间，打印加速度将降低以保持在限制范围内。
 *
 * 详细说明请参见 https://marlinfw.org/docs/features/lin_advance.html。
 */
#define LIN_ADVANCE
#if ENABLED(LIN_ADVANCE)
  #if ENABLED(DISTINCT_E_FACTORS)
    #define ADVANCE_K { 0.0 }     // 每个挤出机的每1mm/s挤出速度的压缩长度，每个挤出机
  #else
    #define ADVANCE_K 0.0         // 应用于所有挤出机的压缩长度
  #endif
  //#define ADVANCE_K_EXTRA       // 添加第二个线性进给常数，可使用 M900 L 进行配置
  //#define LA_DEBUG              // 在操作过程中打印调试信息到串口。生产使用时禁用。
  //#define ALLOW_LOW_EJERK       // 允许 DEFAULT_EJERK 值 <10。建议用于直接驱动热端。
  //#define EXPERIMENTAL_I2S_LA   // 允许在 LA 中使用 I2S_STEPPER_STREAM。随着 LA 步进速率达到 ~20kHz，性能下降。
#endif

// @section leveling

/**
 * 在进行床探测之前，使用安全的床级配坐标将轴移动到有用的位置。
 * 例如，在归位旋转轴之后，Z探针可能不垂直于床面。
 * 选择值，使床水平，Z探针垂直。
 */
//#define SAFE_BED_LEVELING_START_X 0.0
//#define SAFE_BED_LEVELING_START_Y 0.0
//#define SAFE_BED_LEVELING_START_Z 0.0
//#define SAFE_BED_LEVELING_START_I 0.0
//#define SAFE_BED_LEVELING_START_J 0.0
//#define SAFE_BED_LEVELING_START_K 0.0
//#define SAFE_BED_LEVELING_START_U 0.0
//#define SAFE_BED_LEVELING_START_V 0.0
//#define SAFE_BED_LEVELING_START_W 0.0

/**
 * 所有3点级调平程序的探测点。
 * 如果自动选择的点不合适，请进行覆盖。
 */
#if NEEDS_THREE_PROBE_POINTS
  //#define PROBE_PT_1 {  15, 180 }   // (mm) { x, y }
  //#define PROBE_PT_2 {  15,  20 }
  //#define PROBE_PT_3 { 170,  20 }
#endif

/**
 * 探测边缘
 *
 * 为每个边缘覆盖 PROBING_MARGIN
 * 有助于将探测点定位于目标上或
 * 允许级调平避开床夹具的特定
 * 边缘。如果使用 NOZZLE_AS_PROBE，则允许负值
 * 以允许在床外进行探测。
 *
 * 如果替换了先前的 *_PROBE_BED_POSITION 选项，
 * 左和前的值在大多数情况下将直接映射到右和后，
 * 例如（X/Y_BED_SIZE - RIGHT/BACK_PROBE_BED_POSITION）
 *
 * 这样可以确保所有位置在编译时匹配，但是
 * 如果使用 M851 XY 修改了探针位置，则探针点将遵循。
 * 这样可以防止任何更改导致探针无法到达任何点。
 */
#if PROBE_SELECTED && !IS_KINEMATIC
  #define PROBING_MARGIN_LEFT PROBING_MARGIN
  #define PROBING_MARGIN_RIGHT PROBING_MARGIN
  #define PROBING_MARGIN_FRONT PROBING_MARGIN
  #define PROBING_MARGIN_BACK PROBING_MARGIN
#endif

#if ANY(MESH_BED_LEVELING, AUTO_BED_LEVELING_UBL)
  // 覆盖网格区域，如果自动（最大）区域太大
  //#define MESH_MIN_X MESH_INSET
  //#define MESH_MIN_Y MESH_INSET
  //#define MESH_MAX_X X_BED_SIZE - (MESH_INSET)
  //#define MESH_MAX_Y Y_BED_SIZE - (MESH_INSET)
#endif

#if ALL(AUTO_BED_LEVELING_UBL, EEPROM_SETTINGS)
  //#define OPTIMIZED_MESH_STORAGE  // 以较低的精度存储网格以节省 EEPROM 空间
#endif

/**
 * 重复尝试 G29 级调平，直到成功。
 * 在 G29_MAX_RETRIES 尝试后停止。
 */
//#define G29_RETRY_AND_RECOVER
#if ENABLED(G29_RETRY_AND_RECOVER)
  #define G29_MAX_RETRIES 3
  #define G29_HALT_ON_FAILURE
  /**
   * 指定在级调平成功后、尝试之间和达到最大重试次数后要执行的 GCODE 命令。
   */
  #define G29_SUCCESS_COMMANDS "M117 Bed leveling done."
  #define G29_RECOVER_COMMANDS "M117 Probe failed. Rewiping.\nG28\nG12 P0 S12 T0"
  #define G29_FAILURE_COMMANDS "M117 Bed leveling failed.\nG0 Z10\nM300 P25 S880\nM300 P50 S0\nM300 P25 S880\nM300 P50 S0\nM300 P25 S880\nM300 P50 S0\nG4 S1"

#endif

/**
 * 热探头补偿
 *
 * 调整探头测量值以补偿与探头、床和/或热端温度相关的形变。
 * 使用 G76 自动校准此功能以探测和床温度。
 * （挤出机温度/偏移值必须手动校准。）
 * 使用 M871 手动设置温度/偏移值。
 * 详细信息请参见 https://marlinfw.org/docs/features/probe_temp_compensation.html
 */
//#define PTC_PROBE    // 根据探头温度进行补偿
//#define PTC_BED      // 根据床温度进行补偿
//#define PTC_HOTEND   // 根据热端温度进行补偿

#if ANY(PTC_PROBE, PTC_BED, PTC_HOTEND)
  /**
   * 如果探头在定义的范围之外，则使用最接近的点和索引为 PTC_LINEAR_EXTRAPOLATION 的点之间的
   * 线性外推。例如，如果设置为 4，则将使用 data[0] 和 data[4] 之间的线性外推，用于 PTC_PROBE_START 以下的值。
   */
  //#define PTC_LINEAR_EXTRAPOLATION 4

  #if ENABLED(PTC_PROBE)
    // 探头温度校准生成从 PTC_PROBE_START
    //（例如 30）开始的值表，步长为 PTC_PROBE_RES（例如 5），采样次数为 PTC_PROBE_COUNT（例如 10）。
    #define PTC_PROBE_START   30    // （°C）
    #define PTC_PROBE_RES      5    // （°C）
    #define PTC_PROBE_COUNT   10
    #define PTC_PROBE_ZOFFS   { 0 } // （µm）每个样本的 Z 调整
  #endif

  #if ENABLED(PTC_BED)
    // 床温度校准构建类似的表。
    #define PTC_BED_START     60    // （°C）
    #define PTC_BED_RES        5    // （°C）
    #define PTC_BED_COUNT     10
    #define PTC_BED_ZOFFS     { 0 } // （µm）每个样本的 Z 调整
  #endif

  #if ENABLED(PTC_HOTEND)
    // 注意：热端没有自动校准。使用 M871 手动设置。
    #define PTC_HOTEND_START 180    // （°C）
    #define PTC_HOTEND_RES     5    // （°C）
    #define PTC_HOTEND_COUNT  20
    #define PTC_HOTEND_ZOFFS  { 0 } // （µm）每个样本的 Z 调整
  #endif

  // G76 选项
  #if ALL(PTC_PROBE, PTC_BED)
    // 等待探头冷却的停车位置
    #define PTC_PARK_POS   { 0, 0, 100 }

    // 探针位置，用于探测并等待探针达到目标温度
    //#define PTC_PROBE_POS  { 12.0f, 7.3f } // 示例：MK52 磁性热床
    #define PTC_PROBE_POS  { 90, 100 }

    // 在采集期间，探针应达到的温度
    #define PTC_PROBE_TEMP    30  // （°C）

    // 将喷嘴抬高的高度，高于 Z=0.0。降低此值可以帮助探针更快地加热。
    // 注意：Z=0.0 偏移由探针 Z 偏移（例如，使用 M851 Z 设置）确定。
    #define PTC_PROBE_HEATING_OFFSET 0.5
  #endif
#endif // PTC_PROBE || PTC_BED || PTC_HOTEND

// @section extras

//
// G60/G61 位置保存和返回
//
//#define SAVED_POSITIONS 1         // 每个保存的位置槽位占用 12 字节

//
// G2/G3 弧支持
//
//#define ARC_SUPPORT                 // 需要大约 3226 字节
#if ENABLED(ARC_SUPPORT)
  #define MIN_ARC_SEGMENT_MM      0.1 // （mm）每个弧段的最小长度
  #define MAX_ARC_SEGMENT_MM      1.0 // （mm）每个弧段的最大长度
  #define MIN_CIRCLE_SEGMENTS    72   // 完整圆中的最小段数
  //#define ARC_SEGMENTS_PER_SEC 50   // 使用进给速度选择段长度
  #define N_ARC_CORRECTION       25   // 在修正之间插入的插值段数
  //#define ARC_P_CIRCLES             // 启用“P”参数以指定完整圆
  //#define SF_ARC_FIX                // 仅在使用 “Arc Point” 倒角过程的 SkeinForge 时启用
#endif

// G5 Bézier 曲线支持，具有 XYZE 目标和 IJPQ 偏移
//#define BEZIER_CURVE_SUPPORT        // 需要大约 2666 字节

#if ANY(ARC_SUPPORT, BEZIER_CURVE_SUPPORT)
  //#define CNC_WORKSPACE_PLANES      // 允许在 XY、ZX 或 YZ 平面上运行 G2/G3/G5
#endif

/**
 * 直接步进
 *
 * 与 Klipper 使用的方法类似，G6 直接步进显著减少了运动计算，提高了顶部打印速度，并通过提前计算所有运动来减少步进别名效应。
 * 准备您的 G 代码：https://github.com/colinrgodsey/step-daemon
 */
//#define DIRECT_STEPPING

/**
 * G38 探测目标
 *
 * 此选项添加了 G38.2 和 G38.3（朝目标探测）
 * 以及可选的 G38.4 和 G38.5（远离目标探测）。
 * 对于 G38 进行多次探测，请设置 MULTIPLE_PROBING。
 */
//#define G38_PROBE_TARGET
#if ENABLED(G38_PROBE_TARGET)
  //#define G38_PROBE_AWAY        // 包括 G38.4 和 G38.5 以从目标远离探测
  #define G38_MINIMUM_MOVE 0.0275 // （mm）产生移动的最小距离。
#endif

// 移动（或段）的步数少于此值，将与下一个移动连接
#define MIN_STEPS_PER_SEGMENT 6

/**
 * 在设置步进 DIR 之前和之后的最小延迟（以 ns 为单位）
 *     0：无延迟（期望至少经过 10µS，因为一个 Stepper ISR 必须发生）
 *    20：TMC2xxx 驱动程序的最小延迟
 *   200：A4988 驱动程序的最小延迟
 *   400：A5984 驱动程序的最小延迟
 *   500：LV8729 驱动程序的最小延迟（推测，未在数据手册中找到信息）
 *   650：DRV8825 驱动程序的最小延迟
 *  1500：TB6600 驱动程序的最小延迟（推测，未在数据手册中找到信息）
 * 15000：TB6560 驱动程序的最小延迟（推测，未在数据手册中找到信息）
 *
 * 根据 Configuration.h 中设置的驱动程序类型覆盖默认值。
 */
//#define MINIMUM_STEPPER_POST_DIR_DELAY 650
//#define MINIMUM_STEPPER_PRE_DIR_DELAY 650

/**
 * 步进驱动器脉冲的最小宽度（以 µs 为单位）
 *     0：MCU 可能产生的最小宽度，与 TMC2xxx 驱动程序兼容
 *     0：LV8729 的最小宽度，由 stepper.h 中调整
 *     1：A4988 和 A5984 步进驱动器的最小值
 *     2：DRV8825 步进驱动器的最小值
 *     3：TB6600 步进驱动器的最小值
 *    30：TB6560 步进驱动器的最小值
 *
 * 根据 Configuration.h 中设置的驱动程序类型覆盖默认值。
 */
//#define MINIMUM_STEPPER_PULSE 2

/**
 * 步进驱动器允许的最大步进速率（以 Hz 为单位）
 * 如果未定义，则默认为 1MHz /（2 * MINIMUM_STEPPER_PULSE）
 * 5000000：TMC2xxx 步进驱动器的最大值
 * 1000000：LV8729 步进驱动器的最大值
 * 500000：A4988 步进驱动器的最大值
 * 250000：DRV8825 步进驱动器的最大值
 * 150000：TB6600 步进驱动器的最大值
 * 15000：TB6560 步进驱动器的最大值
 *
 * 根据 Configuration.h 中设置的驱动程序类型覆盖默认值。
 */
//#define MAXIMUM_STEPPER_RATE 250000

// @section 温度控制

// 并行控制加热器 0 和加热器 1。
//#define HEATERS_PARALLEL

//===========================================================================
//================================= 缓冲区 =================================
//===========================================================================
// @section motion

// 可以同时在规划器中的线性移动的数量。
// BLOCK_BUFFER_SIZE 的值必须是2的幂（例如8、16、32）
#if ALL(HAS_MEDIA, DIRECT_STEPPING)
  #define BLOCK_BUFFER_SIZE  8
#elif HAS_MEDIA
  #define BLOCK_BUFFER_SIZE 16
#else
  #define BLOCK_BUFFER_SIZE 16
#endif

// @section serial

// 用于串行输入的 ASCII 缓冲区
#define MAX_CMD_SIZE 96
#define BUFSIZE 4

// 传输到主机的缓冲区大小
// 为了节省 386 字节的闪存（和 TX_BUFFER_SIZE+3 字节的 RAM），设置为 0。
// 要缓冲一个简单的“ok”，您需要 4 字节。
// 对于 ADVANCED_OK（M105），您需要 32 字节。
// 对于调试回声：128 字节用于最佳速度。
// 其他输出不需要那么快。
// ：[0, 2, 4, 8, 16, 32, 64, 128, 256]
#define TX_BUFFER_SIZE 0

// 主机接收缓冲区大小
// 如果没有 XON/XOFF 流控制（参见下面的 SERIAL_XON_XOFF），32 字节应该足够。
// 要使用流控制，请将此缓冲区大小设置为至少 1024 字节。
// ：[0, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048]
//#define RX_BUFFER_SIZE 1024

#if RX_BUFFER_SIZE >= 1024
  // 启用以使控制器向主机发送 XON/XOFF 控制字符，
  // 以表示 RX 缓冲区正在变满。
  //#define SERIAL_XON_XOFF
#endif

#if HAS_MEDIA
  // 启用此选项以在将文件传输到 SD 后收集和显示最大 RX 队列使用情况。
  //#define SERIAL_STATS_MAX_RX_QUEUED

  // 启用此选项以在将文件传输到 SD 后收集和显示丢弃的字节数。
  //#define SERIAL_STATS_DROPPED_RX
#endif

// 监视 RX 缓冲区使用情况
// 如果串行接收缓冲区溢出，向串口输出错误。
// 如果看到这些错误，请增加 RX_BUFFER_SIZE 值。
// 不支持所有平台。
//#define RX_BUFFER_MONITOR

/**
 * 应急命令解析器
 *
 * 添加一个低级解析器，以截取特定命令，因此它们无法被阻塞。
 * 目前处理 M108、M112、M410、M876
 * 注意：并非所有平台都已实现。
 */
#define EMERGENCY_PARSER

/**
 * 实时报告（需要 EMERGENCY_PARSER）
 *
 * - 报告机器的位置和状态（类似于 Grbl）。
 * - 在长时间移动期间自动报告位置。
 * - 对于 CNC/LASER 很有用。
 *
 * 添加对以下命令的支持：
 *  S000：在移动时报告状态和位置。
 *  P000：即时暂停/保持移动。
 *  R000：从暂停/保持状态恢复。
 *
 * - 在保持状态下，所有应急解析器命令都可用，与平常一样。
 * - 启用 NANODLP_Z_SYNC 和 NANODLP_ALL_AXIS 以进行移动命令结束状态报告。
 */
//#define REALTIME_REPORTING_COMMANDS
#if ENABLED(REALTIME_REPORTING_COMMANDS)
  //#define FULL_REPORT_TO_HOST_FEATURE   // 自动报告类似于 Grbl CNC 的机器状态
#endif

// 坏的串行连接可能会错过接收到的命令，因为发送了“ok”
// 因此，一些客户端会在超时后的30秒内中止。
// 其他一些客户端在接收到“wait”时开始发送命令。
// 这个“wait”只在缓冲区为空时发送。这里的1秒是一个很好的值。
//#define NO_TIMEOUTS 1000 // 毫秒

// 一些客户端很快将拥有此功能。这可能使 NO_TIMEOUTS 不再必要。
//#define ADVANCED_OK

// Printrun 可能在一次性接收长字符串时遇到问题。
// 此选项在串行输出的行之间插入短暂的延迟。
#define SERIAL_OVERRUN_PROTECTION

// 用于串行回显，小数点后的位数
//#define SERIAL_FLOAT_PRECISION 4

/**
 * 设置填充典型字符空间所需的比例字体空间。
 * 这有助于更好地对齐诸如 `G29 O` 网格输出之类的命令的输出。
 *
 * 对于使用等宽字体的客户端（例如 OctoPrint），将其设置为 1.0。
 * 否则，根据您的客户端和字体进行调整。
 */
#define PROPORTIONAL_FONT_RATIO 1.0

// @section extras

/**
 * 额外的风扇速度
 * 为每个打印冷却风扇添加一个辅助风扇速度。
 *   'M106 P<fan> T3-255'：为 <fan> 设置辅助速度
 *   'M106 P<fan> T2'     ：使用设置的辅助速度
 *   'M106 P<fan> T1'     ：恢复以前的风扇速度
 */
//#define EXTRA_FAN_SPEED

/**
 * 固件基础的、由 LCD 控制的回缩
 *
 * 添加 G10 / G11 命令，用于自动固件回缩/恢复。
 * 使用 M207 和 M208 定义回缩/恢复的参数。
 *
 * 使用 M209 启用或禁用自动回缩。
 * 启用自动回缩后，所有在设置范围内的 G1 E 移动都将转换为基于固件的回缩/恢复移动。
 *
 * 在更换线材时务必关闭自动回缩。
 *
 * 请注意，M207 / M208 / M209 设置将保存到 EEPROM。
 */
//#define FWRETRACT
#if ENABLED(FWRETRACT)
#define FWRETRACT_AUTORETRACT // 覆盖切片器的回抽
#if ENABLED(FWRETRACT_AUTORETRACT)
#define MIN_AUTORETRACT 0.1 // (mm) 不要将E移动转换为此长度以下
#define MAX_AUTORETRACT 10.0 // (mm) 不要将E移动转换为此长度以上
#endif
#define RETRACT_LENGTH 3 // (mm) 默认回抽长度（正值）
#define RETRACT_LENGTH_SWAP 13 // (mm) 默认交换回抽长度（正值）
#define RETRACT_FEEDRATE 45 // (mm/s) 默认回抽速度
#define RETRACT_ZRAISE 0 // (mm) 默认回抽时提升的Z轴距离
#define RETRACT_RECOVER_LENGTH 0 // (mm) 默认额外的回复长度（在回复时添加到回抽长度上）
#define RETRACT_RECOVER_LENGTH_SWAP 0 // (mm) 默认额外的交换回复长度（在工具切换时添加到回抽长度上）
#define RETRACT_RECOVER_FEEDRATE 8 // (mm/s) 默认回复速度
#define RETRACT_RECOVER_FEEDRATE_SWAP 8 // (mm/s) 默认交换回复速度
#if ENABLED(MIXING_EXTRUDER)
//#define RETRACT_SYNC_MIXING // 同步回抽和恢复所有混合步进电机
#endif
#endif

/**
 * 通用换挤出机设置。
 * 适用于除 SWITCHING_TOOLHEAD、DUAL_X_CARRIAGE 或 PARKING_EXTRUDER 以外的所有挤出机类型。
 */
#if HAS_MULTI_EXTRUDER
  // 换挤出机时的 Z 抬高距离，某些挤出机需要
  #define TOOLCHANGE_ZRAISE                 2 // （mm）
  //#define TOOLCHANGE_ZRAISE_BEFORE_RETRACT  // 在换挤出机之前应用抬高（如果启用）
  //#define TOOLCHANGE_NO_RETURN              // 永远不返回到之前的位置
  #if ENABLED(TOOLCHANGE_NO_RETURN)
    //#define EVENT_GCODE_AFTER_TOOLCHANGE "G12X"   // 换挤出机后运行的额外 G 代码
  #endif

  /**
   * 换挤出机时执行换挤出机命令期间运行的额外 G 代码。可用于使用附加
   * 步进电机（例如 Configuration.h 中的 I 轴）驱动换挤出机。
   */
  //#define EVENT_GCODE_TOOLCHANGE_T0 "G28 A\nG1 A0"  // 在执行换挤出机命令 T0 期间运行的额外 G 代码
  //#define EVENT_GCODE_TOOLCHANGE_T1 "G1 A10"        // 在执行换挤出机命令 T1 期间运行的额外 G 代码
  //#define EVENT_GCODE_TOOLCHANGE_ALWAYS_RUN         // 始终执行上面的 G 代码序列。谨慎使用！

  /**
   * 将 EVENT_GCODE_TOOLCHANGE_Tx 的坐标视为相对于 T0，以便所有工具的移动
   * 轴保持一致。
   */
  //#define TC_GCODE_USE_GLOBAL_X   // 使用相对于挤出机 0 的 X 位置
  //#define TC_GCODE_USE_GLOBAL_Y   // 使用相对于挤出机 0 的 Y 位置
  //#define TC_GCODE_USE_GLOBAL_Z   // 使用相对于挤出机 0 的 Z 位置

  /**
   * 工具传感器用于检测挤出机是否已拿起或放下。
   * 需要 TOOL_SENSOR1_PIN、TOOL_SENSOR2_PIN 等引脚。
   */
  //#define TOOL_SENSOR

  /**
   * 在换挤出机时回缩和填充线材，以减少
   * 渗漏和串口，并获得更干净的过渡。
   */
  //#define TOOLCHANGE_FILAMENT_SWAP
  #if ENABLED(TOOLCHANGE_FILAMENT_SWAP)
    // 载入/卸载
    #define TOOLCHANGE_FS_LENGTH              12  // （mm）装载/卸载长度
    #define TOOLCHANGE_FS_EXTRA_RESUME_LENGTH  0  // （mm）用于更好的重启的额外长度。使用 LCD 或 M217 B 进行调整。
    #define TOOLCHANGE_FS_RETRACT_SPEED   (50*60) // （mm/min）（卸载）
    #define TOOLCHANGE_FS_UNRETRACT_SPEED (25*60) // （mm/min）（在 SINGLENOZZLE 或 Bowden 上必须减速装载）

    // 更长的填充以清除 SINGLENOZZLE
    #define TOOLCHANGE_FS_EXTRA_PRIME          0  // （mm）额外填充长度
    #define TOOLCHANGE_FS_PRIME_SPEED    (4.6*60) // （mm/min）额外填充速度
    #define TOOLCHANGE_FS_WIPE_RETRACT         0  // （mm）从停车位置切割回缩，减少线材过滤、更好的擦拭等。使用 LCD 或 M217 G 进行调整。

    // 填充后冷却以减少渗漏
    #define TOOLCHANGE_FS_FAN                 -1  // 风扇索引或 -1 表示跳过
    #define TOOLCHANGE_FS_FAN_SPEED          255  // 0-255
    #define TOOLCHANGE_FS_FAN_TIME            10  // （秒）

    // 第一次每个挤出机填充时使用 TOOLCHANGE_FS_PRIME_SPEED 进给速率
    //#define TOOLCHANGE_FS_SLOW_FIRST_PRIME

    /**
     * 在第一次将 T0 发送到打印机时，对 T0 进行首次填充：
     *  [ 通电 -> T0 { 激活并填充 T0 } -> T1 { 缩回 T0，激活并填充 T1 } ]
     * 如果禁用，则在从其他挤出机切换回 T0 之前，不要在 T0 上填充：
     *  [ 通电 -> T0 { T0 已激活 } -> T1 { 激活并填充 T1 } -> T0 { 缩回 T1，激活并填充 T0 } ]
     * 在打印之前使用 M217 V1 启用，以避免在主机连接时不必要的填充。
     */
    //#define TOOLCHANGE_FS_PRIME_FIRST_USED

    /**
     * 工具更改迁移
     * 此功能提供 G 代码和 LCD 选项，以在打印期间切换挤出机。
     * 所有适用的工具属性都会迁移，以便打印可以继续进行。
     * 工具必须非常匹配，并可能适用其他限制。
     * 有用于：
     *   - 在没有中断的情况下更改线材颜色
     *   - 在线材用尽后自动切换线轴
     *   - 在挤出机卡住时切换到不同的喷嘴
     */
    #define TOOLCHANGE_MIGRATION_FEATURE

  #endif

  /**
   * 换挤出机时的位置停泊头。
   * 不适用于 SWITCHING_TOOLHEAD、DUAL_X_CARRIAGE 或 PARKING_EXTRUDER
   */
  //#define TOOLCHANGE_PARK
  #if ENABLED(TOOLCHANGE_PARK)
    #define TOOLCHANGE_PARK_XY    { X_MIN_POS + 10, Y_MIN_POS + 10 }
    #define TOOLCHANGE_PARK_XY_FEEDRATE 6000  // （mm/min）
    //#define TOOLCHANGE_PARK_X_ONLY          // 仅 X 轴移动
    //#define TOOLCHANGE_PARK_Y_ONLY          // 仅 Y 轴移动
  #endif
#endif // HAS_MULTI_EXTRUDER

// @section advanced pause

/**
 * 高级暂停用于更换线材
 *  - 添加 G-code M600 线材更换以启动线材更换。
 *  - 此功能对于默认的 FILAMENT_RUNOUT_SCRIPT 是必需的。
 *
 * 要求：
 *  - 对于线材更换停车，启用并配置 NOZZLE_PARK_FEATURE。
 *  - 对于用户交互，启用 LCD 显示器、HOST_PROMPT_SUPPORT 或 EMERGENCY_PARSER。
 *
 * 启用 PARK_HEAD_ON_PAUSE 以添加 G-code M125 暂停和停车。
 */
#define ADVANCED_PAUSE_FEATURE
#if ENABLED(ADVANCED_PAUSE_FEATURE)
  #define PAUSE_PARK_RETRACT_FEEDRATE         60  // (mm/s) 初始回退速度。
  #define PAUSE_PARK_RETRACT_LENGTH            2  // (mm) 初始回退距离。
                                                  // 在停放喷嘴前立即执行这个短暂的回退。
  #define FILAMENT_CHANGE_UNLOAD_FEEDRATE     10  // (mm/s) 卸载丝料速度。可以相当快。
  #define FILAMENT_CHANGE_UNLOAD_ACCEL        25  // (mm/s^2) 较低的加速度可能允许更快的喂丝速度。
  #define FILAMENT_CHANGE_UNLOAD_LENGTH      400  // (mm) 完成卸载所需的丝料长度。
                                                  // 对于BOWDEN，长度为管道和喷嘴的总长度。
                                                  // 对于直驱，长度为喷嘴的总长度。
                                                  // 设置为0表示手动卸载。
  #define FILAMENT_CHANGE_SLOW_LOAD_FEEDRATE   6  // (mm/s) 开始加载时的慢移动速度。
  #define FILAMENT_CHANGE_SLOW_LOAD_LENGTH     0  // (mm) 慢移动长度，用于给予插入材料的时间。
                                                  // 设置为0以禁用开始加载并跳过快速加载。
  #define FILAMENT_CHANGE_FAST_LOAD_FEEDRATE   6  // (mm/s) 加载丝料速度。可以相当快。
  #define FILAMENT_CHANGE_FAST_LOAD_ACCEL     25  // (mm/s^2) 较低的加速度可能允许更快的喂丝速度。
  #define FILAMENT_CHANGE_FAST_LOAD_LENGTH   350  // (mm) 从挤出齿轮到喷嘴的丝料加载长度。
                                                  // 对于BOWDEN，长度为管道和喷嘴的总长度。
                                                  // 对于直驱，长度为喷嘴的总长度。
  //#define ADVANCED_PAUSE_CONTINUOUS_PURGE       // 连续清洁，直到达到清洁长度被中断。
  #define ADVANCED_PAUSE_PURGE_FEEDRATE        3  // (mm/s) 挤出速度（加载后）。应该比加载速度慢。
  #define ADVANCED_PAUSE_PURGE_LENGTH         50  // (mm) 加载后挤出的长度。
                                                  // 设置为0以手动挤出。
                                                  // 可以从“更换丝料”菜单中重复挤出丝料，
                                                  // 直到挤出一致丝料并清洁旧丝料。
  #define ADVANCED_PAUSE_RESUME_PRIME          0  // (mm) 返回停放位置后，喷嘴继续挤出的额外距离。
  //#define ADVANCED_PAUSE_FANS_PAUSE             // 在机器暂停时关闭打印冷却风扇。

                                                  // 卸载丝料先执行回退、延迟和清洁：
  #define FILAMENT_UNLOAD_PURGE_RETRACT       13  // (mm) 卸载的初始回退距离。
  #define FILAMENT_UNLOAD_PURGE_DELAY       5000  // (ms) 回退后等待丝料冷却的延迟时间。
  #define FILAMENT_UNLOAD_PURGE_LENGTH         8  // (mm) 执行一个撤回操作，然后清洁指定长度的丝料。
  #define FILAMENT_UNLOAD_PURGE_FEEDRATE      25  // (mm/s) 卸载前的清洁速度

  #define PAUSE_PARK_NOZZLE_TIMEOUT           45  // (秒) 喷嘴停留安全时间限制。
  #define FILAMENT_CHANGE_ALERT_BEEPS         10  // 要播放的警报音数目，需要用户响应。
  #define PAUSE_PARK_NO_STEPPER_TIMEOUT           // 启用XYZ步进电机在更换丝料时保持通电。
  //#define FILAMENT_CHANGE_RESUME_ON_INSERT      // 当再次触发断丝传感器时自动继续/加载丝料。
  //#define PAUSE_REHEAT_FAST_RESUME              // 在继续之前减少等待次数，无需在超时后再次提示。

  #define PARK_HEAD_ON_PAUSE                      // 暂停和更换丝料时，停放喷嘴。
  #define HOME_BEFORE_FILAMENT_CHANGE             // 如果需要，在更换丝料之前回零

  #define FILAMENT_LOAD_UNLOAD_GCODES             // 添加M701/M702加载/卸载G代码，以及LCD准备菜单中的加载/卸载。
  //#define FILAMENT_UNLOAD_ALL_EXTRUDERS         // 允许M702卸载所有温度高于最小目标温度（由M302设置）的挤出机。
#endif


// @section tmc_smart

/**
 * Trinamic 智能驱动器
 *
 * 要在 SPI 模式下使用 TMC2130、TMC2160、TMC2660、TMC5130、TMC5160 步进电机驱动器：
 *  - 将 SPI 引脚连接到板上的硬件 SPI 接口。
 *    一些板上有简单的跳线连接！请参阅板的文档。
 *  - 在您的 `pins_MYBOARD.h` 文件中定义所需的步进电机 CS 引脚。
 *    （请参阅 RAMPS 引脚，例如。）
 *  - 也可以使用 GPIO 引脚进行软件 SPI，而不是硬件 SPI。

 * 要使用带有串行 UART 的 TMC220x 步进电机驱动器：
 *  - 通过 1K 电阻将 PDN_UART 连接到 #_SERIAL_TX_PIN。
 *    要读取能力，还需要将 PDN_UART 通过无电阻连接到 #_SERIAL_RX_PIN。
 *    一些板上有简单的跳线连接！请参阅板的文档。
 *  - 这些驱动器也可以与硬件串行通信一起使用。

 * 需要 TMC26XStepper 库来使用 TMC26X 步进电机驱动器。
 *   https://github.com/MarlinFirmware/TMC26XStepper

 * 需要 TMCStepper 库来使用其他 TMC 步进电机驱动器。
 *   https://github.com/teemuatlut/TMCStepper

 * @section tmc/config
 */
#if HAS_TRINAMIC_CONFIG || HAS_TMC26X

  #define HOLD_MULTIPLIER    0.5  // 缩小保持电流从运行电流

  /**
   * 将微步插值为 256
   * 用下面的 <driver>_INTERPOLATE 设置覆盖每个驱动程序
   */
  #define INTERPOLATE      true

  #if AXIS_IS_TMC_CONFIG(X)
    #define X_CURRENT       580        // (mA) RMS 电流。峰值电流乘以 1.414。
    #define X_CURRENT_HOME  (X_CURRENT/2)  // (mA) 用于传感器寻迹的 RMS 电流
    #define X_MICROSTEPS     16        // 0..256
    #define X_RSENSE          0.11     // 乘以 1000 用于 TMC26X
    #define X_CHAIN_POS      -1        // -1..0: 未连接。1: MCU MOSI 连接。2: 链中的下一个，...
    //#define X_INTERPOLATE  true      // 启用以覆盖 X 轴的 'INTERPOLATE'
    //#define X_HOLD_MULTIPLIER 0.5    // 启用以覆盖 X 轴的 'HOLD_MULTIPLIER'
  #endif

  #if AXIS_IS_TMC_CONFIG(X2)
    #define X2_CURRENT      X_CURRENT
    #define X2_CURRENT_HOME X_CURRENT_HOME
    #define X2_MICROSTEPS   X_MICROSTEPS
    #define X2_RSENSE       X_RSENSE
    #define X2_CHAIN_POS     -1
    //#define X2_INTERPOLATE true
    //#define X2_HOLD_MULTIPLIER 0.5
  #endif

  #if AXIS_IS_TMC_CONFIG(Y)
    #define Y_CURRENT       580
    #define Y_CURRENT_HOME  (Y_CURRENT/2)
    #define Y_MICROSTEPS     16
    #define Y_RSENSE          0.11
    #define Y_CHAIN_POS      -1
    //#define Y_INTERPOLATE  true
    //#define Y_HOLD_MULTIPLIER 0.5
  #endif

  #if AXIS_IS_TMC_CONFIG(Y2)
    #define Y2_CURRENT      Y_CURRENT
    #define Y2_CURRENT_HOME Y_CURRENT_HOME
    #define Y2_MICROSTEPS   Y_MICROSTEPS
    #define Y2_RSENSE       Y_RSENSE
    #define Y2_CHAIN_POS     -1
    //#define Y2_INTERPOLATE true
    //#define Y2_HOLD_MULTIPLIER 0.5
  #endif

  #if AXIS_IS_TMC_CONFIG(Z)
    #define Z_CURRENT       580
    #define Z_CURRENT_HOME  Z_CURRENT
    #define Z_MICROSTEPS     16
    #define Z_RSENSE          0.11
    #define Z_CHAIN_POS      -1
    //#define Z_INTERPOLATE  true
    //#define Z_HOLD_MULTIPLIER 0.5
  #endif

  #if AXIS_IS_TMC_CONFIG(Z2)
    #define Z2_CURRENT      Z_CURRENT
    #define Z2_CURRENT_HOME Z_CURRENT_HOME
    #define Z2_MICROSTEPS   Z_MICROSTEPS
    #define Z2_RSENSE       Z_RSENSE
    #define Z2_CHAIN_POS     -1
    //#define Z2_INTERPOLATE true
    //#define Z2_HOLD_MULTIPLIER 0.5
  #endif

  #if AXIS_IS_TMC_CONFIG(Z3)
    #define Z3_CURRENT      Z_CURRENT
    #define Z3_CURRENT_HOME Z_CURRENT_HOME
    #define Z3_MICROSTEPS   Z_MICROSTEPS
    #define Z3_RSENSE       Z_RSENSE
    #define Z3_CHAIN_POS     -1
    //#define Z3_INTERPOLATE true
    //#define Z3_HOLD_MULTIPLIER 0.5
  #endif

  #if AXIS_IS_TMC_CONFIG(Z4)
    #define Z4_CURRENT      Z_CURRENT
    #define Z4_CURRENT_HOME Z_CURRENT_HOME
    #define Z4_MICROSTEPS   Z_MICROSTEPS
    #define Z4_RSENSE       Z_RSENSE
    #define Z4_CHAIN_POS     -1
    //#define Z4_INTERPOLATE true
    //#define Z4_HOLD_MULTIPLIER 0.5
  #endif

  #if AXIS_IS_TMC_CONFIG(I)
    #define I_CURRENT      800
    #define I_CURRENT_HOME I_CURRENT
    #define I_MICROSTEPS    16
    #define I_RSENSE         0.11
    #define I_CHAIN_POS     -1
    //#define I_INTERPOLATE  true
    //#define I_HOLD_MULTIPLIER 0.5
  #endif

  #if AXIS_IS_TMC_CONFIG(J)
    #define J_CURRENT      800
    #define J_CURRENT_HOME J_CURRENT
    #define J_MICROSTEPS    16
    #define J_RSENSE         0.11
    #define J_CHAIN_POS     -1
    //#define J_INTERPOLATE  true
    //#define J_HOLD_MULTIPLIER 0.5
  #endif

  #if AXIS_IS_TMC_CONFIG(K)
    #define K_CURRENT      800
    #define K_CURRENT_HOME K_CURRENT
    #define K_MICROSTEPS    16
    #define K_RSENSE         0.11
    #define K_CHAIN_POS     -1
    //#define K_INTERPOLATE  true
    //#define K_HOLD_MULTIPLIER 0.5
  #endif

  #if AXIS_IS_TMC_CONFIG(U)
    #define U_CURRENT      800
    #define U_CURRENT_HOME U_CURRENT
    #define U_MICROSTEPS     8
    #define U_RSENSE         0.11
    #define U_CHAIN_POS     -1
    //#define U_INTERPOLATE  true
    //#define U_HOLD_MULTIPLIER 0.5
  #endif

  #if AXIS_IS_TMC_CONFIG(V)
    #define V_CURRENT      800
    #define V_CURRENT_HOME V_CURRENT
    #define V_MICROSTEPS     8
    #define V_RSENSE         0.11
    #define V_CHAIN_POS     -1
    //#define V_INTERPOLATE  true
    //#define V_HOLD_MULTIPLIER 0.5
  #endif

  #if AXIS_IS_TMC_CONFIG(W)
    #define W_CURRENT      800
    #define W_CURRENT_HOME W_CURRENT
    #define W_MICROSTEPS     8
    #define W_RSENSE         0.11
    #define W_CHAIN_POS     -1
    //#define W_INTERPOLATE  true
    //#define W_HOLD_MULTIPLIER 0.5
  #endif

  #if AXIS_IS_TMC_CONFIG(E0)
    #define E0_CURRENT      650
    #define E0_MICROSTEPS    16
    #define E0_RSENSE         0.11
    #define E0_CHAIN_POS     -1
    //#define E0_INTERPOLATE true
    //#define E0_HOLD_MULTIPLIER 0.5
  #endif

  #if AXIS_IS_TMC_CONFIG(E1)
    #define E1_CURRENT      E0_CURRENT
    #define E1_MICROSTEPS   E0_MICROSTEPS
    #define E1_RSENSE       E0_RSENSE
    #define E1_CHAIN_POS     -1
    //#define E1_INTERPOLATE true
    //#define E1_HOLD_MULTIPLIER 0.5
  #endif

  #if AXIS_IS_TMC_CONFIG(E2)
    #define E2_CURRENT      E0_CURRENT
    #define E2_MICROSTEPS   E0_MICROSTEPS
    #define E2_RSENSE       E0_RSENSE
    #define E2_CHAIN_POS     -1
    //#define E2_INTERPOLATE true
    //#define E2_HOLD_MULTIPLIER 0.5
  #endif

  #if AXIS_IS_TMC_CONFIG(E3)
    #define E3_CURRENT      E0_CURRENT
    #define E3_MICROSTEPS   E0_MICROSTEPS
    #define E3_RSENSE       E0_RSENSE
    #define E3_CHAIN_POS     -1
    //#define E3_INTERPOLATE true
    //#define E3_HOLD_MULTIPLIER 0.5
  #endif

  #if AXIS_IS_TMC_CONFIG(E4)
    #define E4_CURRENT      E0_CURRENT
    #define E4_MICROSTEPS   E0_MICROSTEPS
    #define E4_RSENSE       E0_RSENSE
    #define E4_CHAIN_POS     -1
    //#define E4_INTERPOLATE true
    //#define E4_HOLD_MULTIPLIER 0.5
  #endif

  #if AXIS_IS_TMC_CONFIG(E5)
    #define E5_CURRENT      E0_CURRENT
    #define E5_MICROSTEPS   E0_MICROSTEPS
    #define E5_RSENSE       E0_RSENSE
    #define E5_CHAIN_POS     -1
    //#define E5_INTERPOLATE true
    //#define E5_HOLD_MULTIPLIER 0.5
  #endif

  #if AXIS_IS_TMC_CONFIG(E6)
    #define E6_CURRENT      E0_CURRENT
    #define E6_MICROSTEPS   E0_MICROSTEPS
    #define E6_RSENSE       E0_RSENSE
    #define E6_CHAIN_POS     -1
    //#define E6_INTERPOLATE true
    //#define E6_HOLD_MULTIPLIER 0.5
  #endif

  #if AXIS_IS_TMC_CONFIG(E7)
    #define E7_CURRENT      E0_CURRENT
    #define E7_MICROSTEPS   E0_MICROSTEPS
    #define E7_RSENSE       E0_RSENSE
    #define E7_CHAIN_POS     -1
    //#define E7_INTERPOLATE true
    //#define E7_HOLD_MULTIPLIER 0.5
  #endif

  // @section tmc/spi

/**
 * TMC2130、TMC2160、TMC2660、TMC5130 和 TMC5160 驱动器的默认 SPI 引脚被覆盖在这里。
 * 可以在板子的引脚文件中找到默认引脚。
 */
//#define X_CS_PIN      -1
//#define Y_CS_PIN      -1
//#define Z_CS_PIN      -1
//#define X2_CS_PIN     -1
//#define Y2_CS_PIN     -1
//#define Z2_CS_PIN     -1
//#define Z3_CS_PIN     -1
//#define Z4_CS_PIN     -1
//#define I_CS_PIN      -1
//#define J_CS_PIN      -1
//#define K_CS_PIN      -1
//#define U_CS_PIN      -1
//#define V_CS_PIN      -1
//#define W_CS_PIN      -1
//#define E0_CS_PIN     -1
//#define E1_CS_PIN     -1
//#define E2_CS_PIN     -1
//#define E3_CS_PIN     -1
//#define E4_CS_PIN     -1
//#define E5_CS_PIN     -1
//#define E6_CS_PIN     -1
//#define E7_CS_PIN     -1

/**
 * 用于 SPI 驱动的软件选项（TMC2130、TMC2160、TMC2660、TMC5130 和 TMC5160）。
 * 默认的软件 SPI 引脚在各自的引脚文件中定义，
 * 但是你可以在这里覆盖或定义它们。
 */
//#define TMC_USE_SW_SPI
//#define TMC_SPI_MOSI  -1
//#define TMC_SPI_MISO  -1
//#define TMC_SPI_SCK   -1

// @section tmc/serial

/**
   * 四个TMC2209驱动器可以使用相同的硬件/软件串口，硬件配置地址。
   * 使用MS1和MS2引脚上的跳线设置地址。
   * 地址 | MS1  | MS2
   *       0 | 低   | 低
   *       1 | 高   | 低
   *       2 | 低   | 高
   *       3 | 高   | 高
   *
   * 在同一个串口上，为了所有驱动器设置匹配的*_SERIAL_TX_PIN和*_SERIAL_RX_PIN，
   * 可以在这里设置，也可以在您的板子的引脚文件中设置。
   */
//#define  X_SLAVE_ADDRESS 0
//#define  Y_SLAVE_ADDRESS 0
//#define  Z_SLAVE_ADDRESS 0
//#define X2_SLAVE_ADDRESS 0
//#define Y2_SLAVE_ADDRESS 0
//#define Z2_SLAVE_ADDRESS 0
//#define Z3_SLAVE_ADDRESS 0
//#define Z4_SLAVE_ADDRESS 0
//#define  I_SLAVE_ADDRESS 0
//#define  J_SLAVE_ADDRESS 0
//#define  K_SLAVE_ADDRESS 0
//#define  U_SLAVE_ADDRESS 0
//#define  V_SLAVE_ADDRESS 0
//#define  W_SLAVE_ADDRESS 0
//#define E0_SLAVE_ADDRESS 0
//#define E1_SLAVE_ADDRESS 0
//#define E2_SLAVE_ADDRESS 0
//#define E3_SLAVE_ADDRESS 0
//#define E4_SLAVE_ADDRESS 0
//#define E5_SLAVE_ADDRESS 0
//#define E6_SLAVE_ADDRESS 0
//#define E7_SLAVE_ADDRESS 0

// @section tmc/smart

/**
 * 软件使能
 *
 * 用于不使用专用使能引脚的驱动器，而是通过 SPI 或 UART 等通信线路处理相同的功能。
 */
//#define SOFTWARE_DRIVER_ENABLE

// @section tmc/stealthchop

/**
 * 仅适用于 TMC2130、TMC2160、TMC2208、TMC2209、TMC5130 和 TMC5160
 * 使用 Trinamic 的超静音步进模式。
 * 当禁用时，Marlin 将使用 spreadCycle 步进模式。
 */
  #if HAS_STEALTHCHOP
    #define STEALTHCHOP_XY
    #define STEALTHCHOP_Z
    #define STEALTHCHOP_I
    #define STEALTHCHOP_J
    #define STEALTHCHOP_K
    #define STEALTHCHOP_U
    #define STEALTHCHOP_V
    #define STEALTHCHOP_W
    #define STEALTHCHOP_E
  #endif

/**
 * 通过使用预定义的参数集或库中包含的示例来优化 spreadCycle 步进模式的斩波参数。
 * 提供的参数集为
 * 
 * CHOPPER_DEFAULT_12V
 * CHOPPER_DEFAULT_19V
 * CHOPPER_DEFAULT_24V
 * CHOPPER_DEFAULT_36V
 * CHOPPER_09STEP_24V   // 0.9 度步进电机（24V）
 * CHOPPER_PRUSAMK3_24V // 从 MK3 官方固件导入的参数（24V）
 * CHOPPER_MARLIN_119   // Marlin v1.1.9 的旧默认值
 *
 * 使用以下方式定义自己的参数：
 * { <off_time[1..15]>, <hysteresis_end[-3..12]>, hysteresis_start[1..8] }
 */
#define CHOPPER_TIMING CHOPPER_DEFAULT_24V        // 所有轴（下面覆盖）
//#define CHOPPER_TIMING_X  CHOPPER_TIMING        // X 轴（下面覆盖）
//#define CHOPPER_TIMING_X2 CHOPPER_TIMING_X
//#define CHOPPER_TIMING_Y  CHOPPER_TIMING        // Y 轴（下面覆盖）
//#define CHOPPER_TIMING_Y2 CHOPPER_TIMING_Y
//#define CHOPPER_TIMING_Z  CHOPPER_TIMING        // Z 轴（下面覆盖）
//#define CHOPPER_TIMING_Z2 CHOPPER_TIMING_Z
//#define CHOPPER_TIMING_Z3 CHOPPER_TIMING_Z
//#define CHOPPER_TIMING_Z4 CHOPPER_TIMING_Z
//#define CHOPPER_TIMING_I  CHOPPER_TIMING        // I 轴
//#define CHOPPER_TIMING_J  CHOPPER_TIMING        // J 轴
//#define CHOPPER_TIMING_K  CHOPPER_TIMING        // K 轴
//#define CHOPPER_TIMING_U  CHOPPER_TIMING        // U 轴
//#define CHOPPER_TIMING_V  CHOPPER_TIMING        // V 轴
//#define CHOPPER_TIMING_W  CHOPPER_TIMING        // W 轴
//#define CHOPPER_TIMING_E  CHOPPER_TIMING        // 挤出机（下面覆盖）
//#define CHOPPER_TIMING_E1 CHOPPER_TIMING_E
//#define CHOPPER_TIMING_E2 CHOPPER_TIMING_E
//#define CHOPPER_TIMING_E3 CHOPPER_TIMING_E
//#define CHOPPER_TIMING_E4 CHOPPER_TIMING_E
//#define CHOPPER_TIMING_E5 CHOPPER_TIMING_E
//#define CHOPPER_TIMING_E6 CHOPPER_TIMING_E
//#define CHOPPER_TIMING_E7 CHOPPER_TIMING_E

// @section tmc/status

/**
 * 监控 Trinamic 驱动器
 * 用于监视过温和接地短路等错误条件。
 * 为了管理过温，Marlin 可以减小驱动器电流直到错误条件解除。
 * 其他检测到的条件可以用于停止当前打印。
 * 相关 G-code：
 * M906 - 设置或获取以毫安为单位的电机电流，使用轴代码 X、Y、Z、E。如果没有给出轴代码，则报告值。
 * M911 - 报告步进驱动器的过温预警条件。
 * M912 - 清除步进驱动器的过温预警条件标志。
 * M122 - 报告驱动器参数（需要 TMC_DEBUG）
 */
//#define MONITOR_DRIVER_STATUS

  #if ENABLED(MONITOR_DRIVER_STATUS)
    #define CURRENT_STEP_DOWN     50  // [mA]
    #define REPORT_CURRENT_CHANGE
    #define STOP_ON_ERROR
  #endif

// @section tmc/hybrid

/**
 * 仅适用于 TMC2130、TMC2160、TMC2208、TMC2209、TMC5130 和 TMC5160
 * 当步进速度超过 HYBRID_THRESHOLD 时，驱动器将切换到 spreadCycle。
 * 这种模式允许以牺牲更高噪音水平的方式进行更快的移动。
 * 必须启用 STEALTHCHOP_(XY|Z|E) 来使用 HYBRID_THRESHOLD。
 * 使用 M913 X/Y/Z 来动态调整设置。
 */
//#define HYBRID_THRESHOLD

#define X_HYBRID_THRESHOLD     100  // [mm/s] X轴混合阈值
#define X2_HYBRID_THRESHOLD    100  // [mm/s] X2轴混合阈值
#define Y_HYBRID_THRESHOLD     100  // [mm/s] Y轴混合阈值
#define Y2_HYBRID_THRESHOLD    100  // [mm/s] Y2轴混合阈值
#define Z_HYBRID_THRESHOLD       3  // [mm/s] Z轴混合阈值
#define Z2_HYBRID_THRESHOLD      3  // [mm/s] Z2轴混合阈值
#define Z3_HYBRID_THRESHOLD      3  // [mm/s] Z3轴混合阈值
#define Z4_HYBRID_THRESHOLD      3  // [mm/s] Z4轴混合阈值
#define I_HYBRID_THRESHOLD       3  // [线性=mm/s, 旋转=°/s] I轴混合阈值
#define J_HYBRID_THRESHOLD       3  // [线性=mm/s, 旋转=°/s] J轴混合阈值
#define K_HYBRID_THRESHOLD       3  // [线性=mm/s, 旋转=°/s] K轴混合阈值
#define U_HYBRID_THRESHOLD       3  // [mm/s] U轴混合阈值
#define V_HYBRID_THRESHOLD       3  // [mm/s] V轴混合阈值
#define W_HYBRID_THRESHOLD       3  // [mm/s] W轴混合阈值
#define E0_HYBRID_THRESHOLD     30  // [mm/s] E0轴混合阈值
#define E1_HYBRID_THRESHOLD     30  // [mm/s] E1轴混合阈值
#define E2_HYBRID_THRESHOLD     30  // [mm/s] E2轴混合阈值
#define E3_HYBRID_THRESHOLD     30  // [mm/s] E3轴混合阈值
#define E4_HYBRID_THRESHOLD     30  // [mm/s] E4轴混合阈值
#define E5_HYBRID_THRESHOLD     30  // [mm/s] E5轴混合阈值
#define E6_HYBRID_THRESHOLD     30  // [mm/s] E6轴混合阈值
#define E7_HYBRID_THRESHOLD     30  // [mm/s] E7轴混合阈值

/**
 * 使用StallGuard来归位/探测X、Y、Z轴。
 *
 * 仅适用于TMC2130、TMC2160、TMC2209、TMC2660、TMC5130和TMC5160驱动器。
 * 将步进驱动器的DIAG1引脚连接到X/Y终点开关引脚。
 * X、Y和Z轴的归位将始终在spreadCycle模式下进行。
 *
 * X/Y/Z_STALL_SENSITIVITY是默认的堵转阈值。
 * 使用M914 X Y Z命令在运行时设置堵转阈值：
 *
 *  灵敏度     TMC2209   其他驱动器
 *  HIGHEST     255      -64    （过于敏感 => 误判）
 *  LOWEST       0        63    （过于不敏感 => 无触发）
 *
 * 建议将HOMING_BUMP_MM设置为{0, 0, 0}。
 *
 * SPI_ENDSTOPS  *** 仅适用于TMC2130/TMC5160 ***
 * 通过SPI轮询驱动器来确定归位时的负载。
 * 不再需要从DIAG1引脚到终点开关引脚的连线。
 *
 * IMPROVE_HOMING_RELIABILITY调整归位时的加速度和冲击，并为终点开关触发增加了一个保护期。
 *
 * 将*_STALL_SENSITIVITY注释掉以禁用该轴的无感归位。
 * @section tmc/stallguard
 */
//#define SENSORLESS_HOMING // 仅支持StallGuard功能的驱动器

#if ANY(SENSORLESS_HOMING, SENSORLESS_PROBING)
  // TMC2209: 0...255. TMC2130: -64...63
  #define X_STALL_SENSITIVITY  100
  #define X2_STALL_SENSITIVITY X_STALL_SENSITIVITY
  #define Y_STALL_SENSITIVITY  100
  #define Y2_STALL_SENSITIVITY Y_STALL_SENSITIVITY
  //#define Z_STALL_SENSITIVITY  8
  //#define Z2_STALL_SENSITIVITY Z_STALL_SENSITIVITY
  //#define Z3_STALL_SENSITIVITY Z_STALL_SENSITIVITY
  //#define Z4_STALL_SENSITIVITY Z_STALL_SENSITIVITY
  //#define I_STALL_SENSITIVITY  8
  //#define J_STALL_SENSITIVITY  8
  //#define K_STALL_SENSITIVITY  8
  //#define U_STALL_SENSITIVITY  8
  //#define V_STALL_SENSITIVITY  8
  //#define W_STALL_SENSITIVITY  8
  //#define SPI_ENDSTOPS              // 仅适用于TMC2130/TMC5160
  #define IMPROVE_HOMING_RELIABILITY
#endif

// @section tmc/config

/**
 * TMC 归零步进相位。
 *
 * 通过归零到步进电机线圈的最近绝对相位位置，提高归零重现性。
 * Trinamic 驱动器使用包含 1024 个值的步进相位表，跨越 4 个全步骤，
 * 每个步骤有 256 个位置（因此总共 1024 个位置）。
 * 全步骤位置（128、384、640、896）具有最高的保持力矩。
 *
 * 值从 0..1023，-1 来禁用该轴的归零相位。
 */
//#define TMC_HOME_PHASE { 896, 896, 896 }

/**
 * 在上升和下降沿信号上进行步进（与方波相同）。
 */
  #define EDGE_STEPPING

/**
 * 启用 TMC 步进驱动器的 M122 调试命令。
 * M122 S0/1 将启用连续报告。
 */
//#define TMC_DEBUG

/**
 * 您可以通过填写预定义函数来设置自己的高级设置。
 * 可用函数列表可以在库的 GitHub 页面上找到
 * https://github.com/teemuatlut/TMCStepper
 *
 * 示例：
 * #define TMC_ADV() { \
 *   stepperX.diag0_otpw(1); \
 *   stepperY.intpol(0); \
 * }
 */
  #define TMC_ADV() {  }

#endif // HAS_TRINAMIC_CONFIG || HAS_TMC26X

// @section i2cbus

//
// LPC176x LCD 和数字电流控制器的 I2C 主 ID
// 不适用于基于 Wire 库的其他外设。
//
//#define I2C_MASTER_ID  1  // 设置一个从 0 到 2 的值

/**
 * TWI/I2C 总线
 *
 * 该功能是一个实验性功能，因此不应在生产机器上使用。
 * 启用此功能将允许您从总线上的从设备发送和接收 I2C 数据。
 *
 * ; 示例 #1
 * ; 此宏将字符串 "Marlin" 发送到地址为 0x63（99）的从设备
 * ; 它使用多个具有一个 B<base 10> 参数的 M260 命令
 * M260 A99  ; 目标从设备地址
 * M260 B77  ; M
 * M260 B97  ; a
 * M260 B114 ; r
 * M260 B108 ; l
 * M260 B105 ; i
 * M260 B110 ; n
 * M260 S1   ; 发送当前缓冲区
 *
 * ; 示例 #2
 * ; 从地址为 0x63（99）的从设备请求 6 个字节
 * M261 A99 B5
 *
 * ; 示例 #3
 * ; M261 请求的串行输出示例
 * echo:i2c-reply: from:99 bytes:5 data:hello
 */

//#define EXPERIMENTAL_I2CBUS
#if ENABLED(EXPERIMENTAL_I2CBUS)
  #define I2C_SLAVE_ADDRESS  0  // Set a value from 8 to 127 to act as a slave
#endif

// @section photo

/**
 * 光电 G-code
 * 添加 M240 G-code 来拍照。
 * 照片可以通过数字引脚或物理移动来触发。
 */
//#define PHOTO_GCODE
#if ENABLED(PHOTO_GCODE)
  // 在拍照前移动到的位置（并抬高 Z）
  //#define PHOTO_POSITION { X_MAX_POS - 5, Y_MAX_POS, 0 }  // { xpos, ypos, zraise } (M240 X Y Z)
  //#define PHOTO_DELAY_MS   100                            // （ms）移动回去前的暂停时间（M240 P）
  //#define PHOTO_RETRACT_MM   6.5                          // （mm）用于拍照移动的 E 退缩/恢复（M240 R S）

  // 佳能 RC-1 或自制数字相机触发器
  // 数据来源：https://www.doc-diy.net/photo/rc-1_hacked/
  //#define PHOTOGRAPH_PIN 23

  // 佳能 Hack Development Kit
  // https://web.archive.org/web/20200920094805/https://captain-slow.dk/2014/03/09/3d-printing-timelapses/
  //#define CHDK_PIN        4

  // 可选的第二次移动并延迟触发相机快门
  //#define PHOTO_SWITCH_POSITION { X_MAX_POS, Y_MAX_POS }  // { xpos, ypos } (M240 I J)

  // 持续按下开关或保持 CHDK_PIN 高电平的持续时间
  //#define PHOTO_SWITCH_MS   50 // （ms）（M240 D）

  /**
   * 根据板和相机型号可能需要调整 PHOTO_PULSES_US。
   * 引脚必须以 48.4kHz 运行。
   * 确保使用的 PHOTOGRAPH_PIN 可以快速上升和下降。
   * （例如，MKS SBase 临时传感器引脚太慢，因此使用 J8 上的 P1.23。）
   *
   * 尼康的示例脉冲数据：https://bit.ly/2FKD0Aq
   *                     红外线接线：https://git.io/JvJf7
   */
  //#define PHOTO_PULSES_US { 2000, 27850, 400, 1580, 400, 3580, 400 }  // （微秒）每个 48.4kHz 振荡的持续时间
  #ifdef PHOTO_PULSES_US
    #define PHOTO_PULSE_DELAY_US 13 // （微秒）高电平和低电平脉冲的大致持续时间
  #endif
#endif

// @section cnc
/**
 * 主轴和激光控制
 *
 * 添加 M3、M4 和 M5 命令来打开和关闭主轴/激光，
 * 设置主轴速度、主轴方向和激光功率。
 *
 * SuperPid 是 CNC 铣削社区中使用的一种路由器/主轴速度控制器。
 * Marlin 可以用来打开和关闭主轴。还可以用来设置主轴速度从 5000 到 30000 RPM。
 *
 * 您需要选择一个用于 ON/OFF 功能的引脚，还可以选择一个用于速度控制的 0-5V 硬件 PWM 引脚和一个用于旋转方向的引脚。
 *
 * 详细的配置信息请参阅 https://marlinfw.org/docs/configuration/2.0.9/laser_spindle.html。
 */
//#define SPINDLE_FEATURE
//#define LASER_FEATURE
#if ANY(SPINDLE_FEATURE, LASER_FEATURE)
  #define SPINDLE_LASER_ACTIVE_STATE    LOW    // 如果 SPINDLE_LASER_ENA_PIN 为高电平活动，请设置为 "HIGH"

  #define SPINDLE_LASER_USE_PWM                // 如果您的控制器支持设置速度/功率，请启用
  #if ENABLED(SPINDLE_LASER_USE_PWM)
    #define SPINDLE_LASER_PWM_INVERT    false  // 如果速度/功率在减小时速度/功率上升，请设置为 "true"
    #define SPINDLE_LASER_FREQUENCY     2500   //（Hz）主轴/激光频率（仅在支持的 HAL：AVR、ESP32 和 LPC 中使用）
                                               // ESP32：如果 SPINDLE_LASER_PWM_PIN 是板载的，则 <=78125Hz。对于 I2S 扩展器，
                                               // 频率决定 PWM 分辨率。2500Hz = 0-100，977Hz = 0-255，...
                                               // （250000 / SPINDLE_LASER_FREQUENCY）= 最大值。
  #endif

  //#define AIR_EVACUATION                     // 使用 G-Code M10-M11 控制切割真空/激光吹风机电机
  #if ENABLED(AIR_EVACUATION)
    #define AIR_EVACUATION_ACTIVE       LOW    // 如果开/关功能为高电平活动，请设置为 "HIGH"
    //#define AIR_EVACUATION_PIN        42     // 重写默认的切割真空或激光吹风机引脚
  #endif

  //#define AIR_ASSIST                         // 使用 G-Code M8-M9 控制气助力
  #if ENABLED(AIR_ASSIST)
    #define AIR_ASSIST_ACTIVE           LOW    // 气助力引脚的状态
    //#define AIR_ASSIST_PIN            44     // 重写默认的气助力引脚
  #endif

  //#define SPINDLE_SERVO                      // 一个将角度转换为主轴功率的伺服
  #ifdef SPINDLE_SERVO
    #define SPINDLE_SERVO_NR   0               // 用于主轴控制的伺服索引
    #define SPINDLE_SERVO_MIN 10               // 伺服主轴的最小角度
  #endif

  /**
   * 速度/功率可以设定（'M3 S'）并以以下方式显示：
   *  - PWM255  （S0 - S255）
   *  - PERCENT （S0 - S100）
   *  - RPM     （S0 - S50000）最适用于主轴
   *  - SERVO   （S0 - S180）
   */
  #define CUTTER_POWER_UNIT PWM255

  /**
   * 相对刀具功率
   * 通常，'M3 O<power>' 设置
   * OCR 功率相对于 SPEED_POWER_MIN...SPEED_POWER_MAX 范围。
   * 因此，输入功率为 0...255 对应于 SPEED_POWER_MIN...SPEED_POWER_MAX
   * 而不是正常范围（0 到 SPEED_POWER_MAX）。
   * 最好与（例如）SuperPID 路由器控制器一起使用：S0 = 5000 RPM 和 S255 = 30000 RPM
   */
  //#define CUTTER_POWER_RELATIVE              // 设置速度与 [SPEED_POWER_MIN...SPEED_POWER_MAX] 成比例

  #if ENABLED(SPINDLE_FEATURE)
    //#define SPINDLE_CHANGE_DIR               // 如果您的主轴控制器可以改变主轴方向，请启用
    #define SPINDLE_CHANGE_DIR_STOP            // 如果在改变旋转方向之前应停止主轴，请启用
    #define SPINDLE_INVERT_DIR          false  // 如果主轴方向相反，请设置为 "true"

    #define SPINDLE_LASER_POWERUP_DELAY   5000 // （ms）等待主轴/激光达到速度/功率的延迟时间
    #define SPINDLE_LASER_POWERDOWN_DELAY 5000 // （ms）等待主轴停下的延迟时间

    /**
     * M3/M4 功率方程
     *
     * 每个工具使用不同的速度/功率控制值范围。
     * 这些参数用于在工具功率单位和 PWM 之间进行转换。
     *
     * 速度/功率 = （PWMDC / 255 * 100 - SPEED_POWER_INTERCEPT）/ SPEED_POWER_SLOPE
     * PWMDC = （spdpwr - SPEED_POWER_MIN）/（SPEED_POWER_MAX - SPEED_POWER_MIN）/ SPEED_POWER_SLOPE
     */
    #if ENABLED(SPINDLE_LASER_USE_PWM)
      #define SPEED_POWER_INTERCEPT       0    // （％）0-100，即最小功率百分比
      #define SPEED_POWER_MIN          5000    // （RPM）
      #define SPEED_POWER_MAX         30000    // （RPM）SuperPID 路由器控制器 0 - 30,000 RPM
      #define SPEED_POWER_STARTUP     25000    // （RPM）M3/M4 速度/功率的默认值（无参数）
    #endif

  #else

#if ENABLED(SPINDLE_LASER_USE_PWM)
  #define SPEED_POWER_INTERCEPT       0    // (%) 0-100，即最小功率百分比
  #define SPEED_POWER_MIN             0    // (%) 0-100
  #define SPEED_POWER_MAX           100    // (%) 0-100
  #define SPEED_POWER_STARTUP        80    // (%) M3/M4的速度/功率默认值（无参数时）
#endif

// 定义激光测试点火功能的最小和最大测试脉冲时间值
#define LASER_TEST_PULSE_MIN           1   // (ms) 与激光控制菜单一起使用
#define LASER_TEST_PULSE_MAX         999   // (ms) 注意：菜单可能不显示超过3个字符

#define SPINDLE_LASER_POWERUP_DELAY   50   // (ms) 延迟使主轴/激光加速到速度/功率
#define SPINDLE_LASER_POWERDOWN_DELAY 50   // (ms) 延迟使主轴停止

/**
 * 激光器安全超时时间
 *
 * 当一段时间没有移动时，激光器应该关闭。
 * 在设置此值时，请考虑材料的易燃性、切割速率和G代码顺序。
 * 如果设置得太低，可能会在非常缓慢的移动过程中关闭；如果设置得太高，可能会引发材料燃烧。
 */
#define LASER_SAFETY_TIMEOUT_MS     1000   // (毫秒)

/**
 * 拉丝宽度传感器
 *
 * 实时测量拉丝宽度并根据任何不规则性调整流速。
 *
 * 还允许测量的拉丝直径设置挤出速率，以便切片器只需指定体积。
 *
 * 任何动态模式中的移动都将使用当前进给速度计算激光功率。
 * 进给速度由移动命令的 F 参数设置，例如 G1 X0 Y10 F6000
 * 激光功率将通过位移除掉8个LSB来计算。在二进制中，这相当于除以256。
 * 计算给出了0到255的ocr值，超过F65535的值将设置为255。
 * 更精细的功率控制，如加速度/减速的补偿，将在未来的版本中解决。
 *
 * M5 I 清除内联模式并将功率设置为0，M5 将功率输出设置为0，但保持内联模式开启。
 */
 
/**
 * 启用 M3 命令以实现激光模式内联功率规划器同步。
 * 此功能允许在 CUTTER_MODE_CONTINUOUS 模式下将任何 M3 S 值注入块缓冲区。
 * 此选项允许立即提交 M3 激光功率，而无需等待规划器同步。
 */
//#define LASER_POWER_SYNC

/**
 * 相对于移动速率，按比例缩放激光的功率。
 *
 * - 将入口功率设置为入口速度与标称速度的比例。
 * - 每 N 步将功率斜坡上升，以近似速度梯形。
 * - 由于有限的功率分辨率，这只是一个近似值。
 */
//#define LASER_SAFETY_TIMEOUT_MS     1000   // (ms)

//
// 激光 I2C 电流表（高精度 INA226 低/高边模块）
//
//#define I2C_AMMETER
#if ENABLED(I2C_AMMETER)
  #define I2C_AMMETER_IMAX            0.1    // (安培) 预期电流范围的校准值
  #define I2C_AMMETER_SHUNT_RESISTOR  0.1    // (欧姆) 校准电流电阻值
#endif

//
// 激光冷却液流量计
//
//#define LASER_COOLANT_FLOW_METER
#if ENABLED(LASER_COOLANT_FLOW_METER)
  #define FLOWMETER_PIN         20  // 需要外部中断使能引脚（例如，RAMPS 2,3,18,19,20,21）
  #define FLOWMETER_PPL       5880  // (脉冲/升) 输入引脚上的流量计每升脉冲数
  #define FLOWMETER_INTERVAL  1000  // (ms) 流速计算间隔，以毫秒为单位
  #define FLOWMETER_SAFETY          // 防止在未设置最小流速的情况下运行激光
  #if ENABLED(FLOWMETER_SAFETY)
    #define FLOWMETER_MIN_LITERS_PER_MINUTE 1.5 // (升/分钟) 启用时所需的最小流量
  #endif
#endif

#endif
#endif // SPINDLE_FEATURE || LASER_FEATURE

/**
 * 同步激光控制（使用 M106/M107）
 *
 * Marlin 通常在处理规划器块后的“不久之后”应用 M106/M107 风扇速度。
 * 这对于连接到风扇标头的 PWM/TTL 激光（如某些附加的激光套件）来说太不准确了。
 * 启用此选项可通过更准确的时间设置风扇/激光速度，以提高打印精度。
 *
 * 注意：此选项牺牲了一些冷却风扇速度选项。
 */
//#define LASER_SYNCHRONOUS_M106_M107

/**
 * 冷却液控制
 *
 * 添加 M7、M8 和 M9 命令来打开和关闭雾化或洪水冷却液。
 *
 * 注意：还必须定义 COOLANT_MIST_PIN 和/或 COOLANT_FLOOD_PIN。
 */
//#define COOLANT_CONTROL
#if ENABLED(COOLANT_CONTROL)
  #define COOLANT_MIST                // 如果有雾化冷却液，请启用
  #define COOLANT_FLOOD               // 如果有洪水冷却液，请启用
  #define COOLANT_MIST_INVERT  false  // 如果开/关功能相反，请设置为 "true"
  #define COOLANT_FLOOD_INVERT false  // 如果开/关功能相反，请设置为 "true"
#endif

// @section filament width

/**
 * 拉丝宽度传感器
 *
 * 实时测量拉丝宽度并根据任何不规则性调整流速。
 *
 * 还允许测量的拉丝直径设置挤出速率，以便切片器只需指定体积。
 *
 * 34 RAMPS_14    ：AUX2 连接器上的模拟输入 5
 * 81 PRINTRBOARD ：Exp1 连接器上的模拟输入 2（版本 B、C、D、E）
 * 301 RAMBO       ：模拟输入 3
 *
 * 注意：可能需要为其他板定义模拟引脚。
 */
//#define FILAMENT_WIDTH_SENSOR
#if ENABLED(FILAMENT_WIDTH_SENSOR)
  #define FILAMENT_SENSOR_EXTRUDER_NUM 0    // 拥有拉丝传感器的挤出器的索引：[0,1,2,3,4]
  #define MEASUREMENT_DELAY_CM        14    //（cm）从拉丝传感器到熔化腔的距离

  #define FILWIDTH_ERROR_MARGIN        1.0  //（mm）如果测量值与标称宽度相差太大，则忽略
  #define MAX_MEASUREMENT_DELAY       20    //（字节）存储测量值的缓冲区大小（每厘米 1 字节）。必须大于 MEASUREMENT_DELAY_CM。

  #define DEFAULT_MEASURED_FILAMENT_DIA DEFAULT_NOMINAL_FILAMENT_DIA // 将测量值设置为标称直径
  // 在 LCD 状态行上显示拉丝宽度。状态消息将在 5 秒后过期。
  //#define FILAMENT_LCD_DISPLAY
#endif

// @section power

/**
 * 电力监测器
 * 监测电压（V）和/或电流（A），并在可能的情况下监测功率（W）
 *
 * 使用M430读取和配置
 *
 * 电流传感器将直流电压（相对于测量电流）输入到模拟引脚
 * 电压传感器将直流电压（相对于测量电压）输入到模拟引脚
 */
//#define POWER_MONITOR_CURRENT   // 监测系统电流
//#define POWER_MONITOR_VOLTAGE   // 监测系统电压

#if ENABLED(POWER_MONITOR_CURRENT)
  #define POWER_MONITOR_VOLTS_PER_AMP    0.05000  // 每安培输入电压到 MCU 模拟引脚 - 不要超过 ADC_VREF！
  #define POWER_MONITOR_CURRENT_OFFSET   0        // 应用于计算电流的偏移量（安培）
  #define POWER_MONITOR_FIXED_VOLTAGE   13.6      // 没有电压传感器的电流传感器的电压（用于功率显示）
#endif

#if ENABLED(POWER_MONITOR_VOLTAGE)
  #define POWER_MONITOR_VOLTS_PER_VOLT  0.077933  // 每伏特输入电压到 MCU 模拟引脚 - 不要超过 ADC_VREF！
  #define POWER_MONITOR_VOLTAGE_OFFSET  0         // 应用于计算电压的偏移量（伏特）
#endif

// @section safety

/**
 * 步进驱动器防混乱保护
 *
 * 如果为您的板定义了SAFE_POWER_PIN，则Marlin将在上电之前检查步进驱动器是否正确插入。
 * 如果您的步进驱动器不支持该功能，请禁用保护。
 */
//#define DISABLE_DRIVER_SAFE_POWER_PROTECT

// @section cnc

/**
 * CNC 坐标系
 *
 * 启用 G53 和 G54-G59.3 命令以选择坐标系
 * 启用 G92.1 以将工作空间重置为本机机器空间。
 */
//#define CNC_COORDINATE_SYSTEMS

/**
 * CNC 钻孔循环 - 正在开发中
 *
 * 启用 G81 执行钻孔循环。
 * 目前仅支持单个循环，不支持 G-code 链接。
 */
//#define CNC_DRILLING_CYCLE

// @section reporting

/**
 * 使用 M123 S<seconds> 自动报告风扇速度
 * 需要带有转速计引脚的风扇
 */
//#define AUTO_REPORT_FANS

/**
 * 使用 M155 S<seconds> 自动报告温度
 */
#define AUTO_REPORT_TEMPERATURES
#if ENABLED(AUTO_REPORT_TEMPERATURES) && TEMP_SENSOR_REDUNDANT
  //#define AUTO_REPORT_REDUNDANT // 包括 "R" 传感器在自动报告中
#endif

/**
 * 使用 M154 S<seconds> 自动报告位置
 */
//#define AUTO_REPORT_POSITION
#if ENABLED(AUTO_REPORT_POSITION)
  //#define AUTO_REPORT_REAL_POSITION // 自动报告真实位置
#endif

/**
 * 在 M115 输出中包含功能
 */
#define EXTENDED_CAPABILITIES_REPORT
#if ENABLED(EXTENDED_CAPABILITIES_REPORT)
  //#define M115_GEOMETRY_REPORT
#endif

// @section security

/**
 * 预期打印机检查
 * 添加 M16 G-code 来将一个字符串与 MACHINE_NAME 进行比较。
 * 使用非匹配的字符串的 M16 会使打印机停止。
 */
#define EXPECTED_PRINTER_CHECK

// @section volumetrics

/**
 * 禁用所有容积挤出选项
 */
//#define NO_VOLUMETRICS

#if DISABLED(NO_VOLUMETRICS)
  /**
   * 容积挤出默认状态
   * 激活以使容积挤出成为默认方法，
   * 默认直径为 DEFAULT_NOMINAL_FILAMENT_DIA。
   *
   * 使用 'M200 D0' 禁用，使用 'M200 Dn' 设置新直径（并启用容积挤出）。
   * 使用 'M200 S0/S1' 禁用/启用容积挤出。
   */
  //#define VOLUMETRIC_DEFAULT_ON

  //#define VOLUMETRIC_EXTRUDER_LIMIT
  #if ENABLED(VOLUMETRIC_EXTRUDER_LIMIT)
    /**
     * 默认容积挤出限制，单位为每秒立方毫米（mm^3/sec）。
     * 此出厂设置适用于所有挤出器。
     * 使用 'M200 [T<extruder>] L<limit>' 覆盖和 'M502' 重置。
     * 非零值激活基于容积的挤出限制。
     */
    #define DEFAULT_VOLUMETRIC_EXTRUDER_LIMIT 0.00      //（mm^3/sec）
  #endif
#endif

// @section reporting

// M114 "Current Position" 报告的额外选项
//#define M114_DETAIL         // 使用 'M114' 获取详细信息以检查规划器计算
//#define M114_REALTIME       // 基于正向运动学的实时当前位置
//#define M114_LEGACY         // 在每个调用上同步使用 M114。如有需要，请启用。

//#define REPORT_FAN_CHANGE   // 在更改时报告新的风扇速度 M106 等

// @section gcode

/**
 * 使用 28 字节的 SRAM 优化 G-code 解析器
 */
#define FASTER_GCODE_PARSER

#if ENABLED(FASTER_GCODE_PARSER)
  #define GCODE_QUOTED_STRINGS  // 支持带引号的字符串参数
#endif

//  支持 MeatPack G-code 压缩（https://github.com/scottmudge/OctoPrint-MeatPack）
//#define MEATPACK_ON_SERIAL_PORT_1
//#define MEATPACK_ON_SERIAL_PORT_2

#define GCODE_CASE_INSENSITIVE  // 接受使用小写字母发送给固件的 G-code

//#define REPETIER_GCODE_M360     // 添加来自 Repetier FW 的命令

/**
 * 启用此选项以使 Marlin 构建更简洁，删除所有工作空间偏移量，
 * 简化坐标转换、平整等。
 *
 *  - 禁用 M206 和 M428。
 *  - G92 将恢复到 Marlin 1.0 的行为。
 */
//#define NO_WORKSPACE_OFFSETS

/**
 * CNC G-code 选项
 * 支持激光切割机、绘图机凸轮等使用的 CNC 风格 G-code 方言。
 * 请注意，对于 3D 打印，应谨慎使用 G0 进给速率（如果使用）。
 * 高进给速率可能会导致共振并损害打印质量。
 */
//#define PAREN_COMMENTS      // 支持圆括号括起的注释
//#define GCODE_MOTION_MODES  // 记住运动模式（G0 G1 G2 G3 G5 G38.X）并应用于 X Y Z E F 等

// 启用并设置所有 G0 移动的（默认）进给速率
//#define G0_FEEDRATE 3000 //（mm/min）
#ifdef G0_FEEDRATE
  //#define VARIABLE_G0_FEEDRATE // G0 运动模式下，通过 F 来设置 G0 进给速率
#endif
//#define G0_ANGULAR_FEEDRATE 2700 //（°/min）

// @section gcode

/**
 * 启动命令
 *
 * 打开电源后立即执行某些 G-code 命令。
 */
//#define STARTUP_COMMANDS "M17 Z"

/**
 * G-code 宏
 *
 * 添加 G-code 宏 M810-M819 来定义和运行 G-code 宏。
 * 宏不会保存到 EEPROM。
 */
//#define GCODE_MACROS
#if ENABLED(GCODE_MACROS)
  #define GCODE_MACROS_SLOTS       5  // 最多可使用 10 个
  #define GCODE_MACROS_SLOT_SIZE  50  // 单个宏的最大长度
#endif

/**
 * 用户自定义菜单项，用于运行自定义 G-code。
 * 最多可定义 25 个，但实际数量取决于 LCD。
 */

// @section custom main menu

// 自定义菜单：主菜单
#define CUSTOM_MENU_MAIN
#if ENABLED(CUSTOM_MENU_MAIN)
  //#define CUSTOM_MENU_MAIN_TITLE "Custom Commands"
  #define CUSTOM_MENU_MAIN_SCRIPT_DONE "M117 User Script Done"
  #define CUSTOM_MENU_MAIN_SCRIPT_AUDIBLE_FEEDBACK
  //#define CUSTOM_MENU_MAIN_SCRIPT_RETURN   // 执行脚本后返回状态屏幕
  #define CUSTOM_MENU_MAIN_ONLY_IDLE         // 仅在机器空闲时显示自定义菜单

  #define MAIN_MENU_ITEM_1_DESC "Home & UBL Info"
  #define MAIN_MENU_ITEM_1_GCODE "G28\nG29 W"
  //#define MAIN_MENU_ITEM_1_CONFIRM          // 执行此操作前显示确认对话框

  #define MAIN_MENU_ITEM_2_DESC "Preheat for " PREHEAT_1_LABEL
  #define MAIN_MENU_ITEM_2_GCODE "M140 S" STRINGIFY(PREHEAT_1_TEMP_BED) "\nM104 S" STRINGIFY(PREHEAT_1_TEMP_HOTEND)
  //#define MAIN_MENU_ITEM_2_CONFIRM

  //#define MAIN_MENU_ITEM_3_DESC "Preheat for " PREHEAT_2_LABEL
  //#define MAIN_MENU_ITEM_3_GCODE "M140 S" STRINGIFY(PREHEAT_2_TEMP_BED) "\nM104 S" STRINGIFY(PREHEAT_2_TEMP_HOTEND)
  //#define MAIN_MENU_ITEM_3_CONFIRM

  //#define MAIN_MENU_ITEM_4_DESC "Heat Bed/Home/Level"
  //#define MAIN_MENU_ITEM_4_GCODE "M140 S" STRINGIFY(PREHEAT_2_TEMP_BED) "\nG28\nG29"
  //#define MAIN_MENU_ITEM_4_CONFIRM

  //#define MAIN_MENU_ITEM_5_DESC "Home & Info"
  //#define MAIN_MENU_ITEM_5_GCODE "G28\nM503"
  //#define MAIN_MENU_ITEM_5_CONFIRM

  // 第23个菜单项 - 默认网格验证
#define MAIN_MENU_ITEM_23_DESC "网格验证"
#define MAIN_MENU_ITEM_23_GCODE "G28\n" // 先回原点
                                "G26\n" // 执行网格验证
                                "G4 P5" // 等待5秒
#define MAIN_MENU_ITEM_23_CONFIRM

// 第24个菜单项 - 自定义温度网格验证  
#define MAIN_MENU_ITEM_24_DESC "自定义温度网格验证"
#define MAIN_MENU_ITEM_24_GCODE "M140 S" STRINGIFY(PREHEAT_1_TEMP_BED) "\n"
                               "M104 S" STRINGIFY(PREHEAT_1_TEMP_HOTEND) "\n"
                               "G28\n" // 先回原点
                               "G26\n"  
                               "G4 P5" // 等待5秒
#define MAIN_MENU_ITEM_24_CONFIRM

// 第25个菜单项 - 自定义层高网格验证
#define MAIN_MENU_ITEM_25_DESC "自定义层高网格验证"  
#define MAIN_MENU_ITEM_25_GCODE "M140 S60\n"
                               "M104 S205\n"
                               "M220 S100\n"
                               "M221 S100\n"
                               "G28\n" // 先回原点
                               "G26 L0.1\n"
                               "G4 P5" // 等待5秒
#define MAIN_MENU_ITEM_25_CONFIRM
#endif

// @section custom config menu

// 自定义菜单：配置菜单
//#define CUSTOM_MENU_CONFIG
#if ENABLED(CUSTOM_MENU_CONFIG)
  //#define CUSTOM_MENU_CONFIG_TITLE "Custom Commands"
  #define CUSTOM_MENU_CONFIG_SCRIPT_DONE "M117 Wireless Script Done"
  #define CUSTOM_MENU_CONFIG_SCRIPT_AUDIBLE_FEEDBACK
  //#define CUSTOM_MENU_CONFIG_SCRIPT_RETURN  // 执行脚本后返回状态屏幕
  #define CUSTOM_MENU_CONFIG_ONLY_IDLE        // 仅在机器空闲时显示自定义菜单

  #define CONFIG_MENU_ITEM_1_DESC "Wifi ON"
  #define CONFIG_MENU_ITEM_1_GCODE "M118 [ESP110] WIFI-STA pwd=12345678"
  //#define CONFIG_MENU_ITEM_1_CONFIRM        // 执行此操作前显示确认对话框

  #define CONFIG_MENU_ITEM_2_DESC "Bluetooth ON"
  #define CONFIG_MENU_ITEM_2_GCODE "M118 [ESP110] BT pwd=12345678"
  //#define CONFIG_MENU_ITEM_2_CONFIRM

  //#define CONFIG_MENU_ITEM_3_DESC "Radio OFF"
  //#define CONFIG_MENU_ITEM_3_GCODE "M118 [ESP110] OFF pwd=12345678"
  //#define CONFIG_MENU_ITEM_3_CONFIRM

  //#define CONFIG_MENU_ITEM_4_DESC "Wifi ????"
  //#define CONFIG_MENU_ITEM_4_GCODE "M118 ????"
  //#define CONFIG_MENU_ITEM_4_CONFIRM

  //#define CONFIG_MENU_ITEM_5_DESC "Wifi ????"
  //#define CONFIG_MENU_ITEM_5_GCODE "M118 ????"
  //#define CONFIG_MENU_ITEM_5_CONFIRM
#endif

// @section custom buttons

/**
 * 用户自定义按钮，用于运行自定义 G-code。
 * 最多可定义 25 个。
 */
//#define CUSTOM_USER_BUTTONS
#if ENABLED(CUSTOM_USER_BUTTONS)
  //#define BUTTON1_PIN -1
  #if PIN_EXISTS(BUTTON1)
    #define BUTTON1_HIT_STATE     LOW       // 触发按钮的状态。NC=低电平，NO=高电平。
    #define BUTTON1_WHEN_PRINTING false     // 在打印过程中允许触发按钮？
    #define BUTTON1_GCODE         "G28"
    #define BUTTON1_DESC          "Homing"  // 设置 LCD 状态的可选字符串
  #endif

  //#define BUTTON2_PIN -1
  #if PIN_EXISTS(BUTTON2)
    #define BUTTON2_HIT_STATE     LOW
    #define BUTTON2_WHEN_PRINTING false
    #define BUTTON2_GCODE         "M140 S" STRINGIFY(PREHEAT_1_TEMP_BED) "\nM104 S" STRINGIFY(PREHEAT_1_TEMP_HOTEND)
    #define BUTTON2_DESC          "Preheat for " PREHEAT_1_LABEL
  #endif

  //#define BUTTON3_PIN -1
  #if PIN_EXISTS(BUTTON3)
    #define BUTTON3_HIT_STATE     LOW
    #define BUTTON3_WHEN_PRINTING false
    #define BUTTON3_GCODE         "M140 S" STRINGIFY(PREHEAT_2_TEMP_BED) "\nM104 S" STRINGIFY(PREHEAT_2_TEMP_HOTEND)
    #define BUTTON3_DESC          "Preheat for " PREHEAT_2_LABEL
  #endif
#endif

// @section host

/**
 * 宿主动作命令
 *
 * 根据标准定义宿主流控命令。
 *
 * 请参阅 https://reprap.org/wiki/G-code#Action_commands
 * 常用命令 ................. poweroff, pause, paused, resume, resumed, cancel
 * G29_RETRY_AND_RECOVER .. probe_rewipe, probe_failed
 *
 * 某些功能添加了原因代码以扩展这些命令。
 *
 * 宿主提示支持使 Marlin 能够使用宿主进行用户提示，
 * 以便可以从宿主端管理耗材耗尽等过程。
 */
//#define HOST_ACTION_COMMANDS
#if ENABLED(HOST_ACTION_COMMANDS)
  //#define HOST_PAUSE_M76                // 告诉宿主在 M76 中暂停
  //#define HOST_PROMPT_SUPPORT           // 启动宿主提示以获取用户反馈
  #if ENABLED(HOST_PROMPT_SUPPORT)
    //#define HOST_STATUS_NOTIFICATIONS   // 将某些状态消息作为通知发送给宿主
  #endif
  //#define HOST_START_MENU_ITEM          // 添加一个菜单项，告诉宿主启动
  //#define HOST_SHUTDOWN_MENU_ITEM       // 添加一个菜单项，告诉宿主关闭
#endif

// @section extras

/**
 * 取消对象
 *
 * 实现M486，允许Marlin跳过对象
 */
//#define CANCEL_OBJECTS
#if ENABLED(CANCEL_OBJECTS)
  #define CANCEL_OBJECTS_REPORTING // 将当前对象作为状态消息输出
#endif

/**
 * 闭环控制的I2C位置编码器。
 * 由Aus3D的Chris Barr开发。
 *
 * Wiki: https://wiki.aus3d.com.au/Magnetic_Encoder
 * Github: https://github.com/Aus3D/MagneticEncoder
 *
 * 供应商: https://aus3d.com.au/products/magnetic-encoder-module
 * 替代供应商: https://reliabuild3d.com/
 *
 * Reliabuild编码器已经进行了修改以提高可靠性。
 * @section i2c encoders
 */

//#define I2C_POSITION_ENCODERS
#if ENABLED(I2C_POSITION_ENCODERS)

  #define I2CPE_ENCODER_CNT         1                       // 安装的编码器数量；当前支持最多5个编码器。

  #define I2CPE_ENC_1_ADDR          I2CPE_PRESET_ADDR_X     // 编码器的I2C地址。30-200。
  #define I2CPE_ENC_1_AXIS          X_AXIS                  // 安装编码器模块的轴。 <X|Y|Z|E>_AXIS。
  #define I2CPE_ENC_1_TYPE          I2CPE_ENC_TYPE_LINEAR   // 编码器的类型：I2CPE_ENC_TYPE_LINEAR -或-
                                                            // I2CPE_ENC_TYPE_ROTARY。
  #define I2CPE_ENC_1_TICKS_UNIT    2048                    // 2mm极磁条为1024；1mm极磁条为2048。
                                                            // 对于线性编码器，这是每毫米的脉冲数，
                                                            // 对于旋转编码器，这是每个转一圈的脉冲数。
  //#define I2CPE_ENC_1_TICKS_REV     (16 * 200)            // 仅对于旋转编码器需要；每一整圈的步进数（电机步数/圈 * 微步）
  //#define I2CPE_ENC_1_INVERT                              // 反转轴行程方向。
  #define I2CPE_ENC_1_EC_METHOD     I2CPE_ECM_MICROSTEP     // 错误修正的类型。
  #define I2CPE_ENC_1_EC_THRESH     0.10                    // 误差的阈值（以毫米为单位），
                                                            // 超过此阈值打印机将尝试修正误差；
                                                            // 小于此阈值的误差将被忽略以最小化测量噪声/延迟（滤波）。

  #define I2CPE_ENC_2_ADDR          I2CPE_PRESET_ADDR_Y     // 同上，但是用于编码器2。
  #define I2CPE_ENC_2_AXIS          Y_AXIS
  #define I2CPE_ENC_2_TYPE          I2CPE_ENC_TYPE_LINEAR
  #define I2CPE_ENC_2_TICKS_UNIT    2048
  //#define I2CPE_ENC_2_TICKS_REV   (16 * 200)
  //#define I2CPE_ENC_2_INVERT
  #define I2CPE_ENC_2_EC_METHOD     I2CPE_ECM_MICROSTEP
  #define I2CPE_ENC_2_EC_THRESH     0.10

  #define I2CPE_ENC_3_ADDR          I2CPE_PRESET_ADDR_Z     // 编码器3。添加其他的配置选项
  #define I2CPE_ENC_3_AXIS          Z_AXIS                  // 或使用下面的默认值。

  #define I2CPE_ENC_4_ADDR          I2CPE_PRESET_ADDR_E     // 编码器4。
  #define I2CPE_ENC_4_AXIS          E_AXIS

  #define I2CPE_ENC_5_ADDR          34                      // 编码器5。
  #define I2CPE_ENC_5_AXIS          E_AXIS

  // 启用编码器但没有进行上述配置的默认设置。
  #define I2CPE_DEF_TYPE            I2CPE_ENC_TYPE_LINEAR
  #define I2CPE_DEF_ENC_TICKS_UNIT  2048
  #define I2CPE_DEF_TICKS_REV       (16 * 200)
  #define I2CPE_DEF_EC_METHOD       I2CPE_ECM_NONE
  #define I2CPE_DEF_EC_THRESH       0.1

  //#define I2CPE_ERR_THRESH_ABORT  100.0                   // 阈值大小（以毫米为单位），
                                                            // 任一轴上的错误超过此阈值将导致打印机中止。
                                                            // 注释掉以禁用中止行为。

  #define I2CPE_TIME_TRUSTED        10000                   // 在编码器故障后，在再次信任编码器之前，
                                                            // 必须经过的时间（以毫秒为单位）。

  /**
   * 每次从缓冲区执行新命令时，检查位置，但在长距离移动期间，
   * 此设置确定检查之间的最小更新时间。
   * 当仅针对跳跃而不是振动进行校正时，值为100效果很好。
   */
  #define I2CPE_MIN_UPD_TIME_MS     4                       // （毫秒）编码器检查之间的最小时间。

  // 使用滚动平均值识别表示跳跃而不是振动和噪声的持续性错误。
  #define I2CPE_ERR_ROLLING_AVERAGE

#endif // I2C_POSITION_ENCODERS

/**
 * 模拟摇杆
 * @section joystick
 */
//#define JOYSTICK
#if ENABLED(JOYSTICK)
  #define JOY_X_PIN    5  // RAMPS: AUX2上的建议引脚A5
  #define JOY_Y_PIN   10  // RAMPS: AUX2上的建议引脚A10
  #define JOY_Z_PIN   12  // RAMPS: AUX2上的建议引脚A12
  #define JOY_EN_PIN  44  // RAMPS: AUX2上的建议引脚D44

  //#define INVERT_JOY_X  // 如果X方向反向，请启用
  //#define INVERT_JOY_Y  // 如果Y方向反向，请启用
  //#define INVERT_JOY_Z  // 如果Z方向反向，请启用

  // 使用M119和JOYSTICK_DEBUG连接后，找到合理的值：
  #define JOY_X_LIMITS { 5600, 8190-100, 8190+100, 10800 } // 最小值，死区开始，死区结束，最大值
  #define JOY_Y_LIMITS { 5600, 8250-100, 8250+100, 11000 }
  #define JOY_Z_LIMITS { 4800, 8080-100, 8080+100, 11550 }
  //#define JOYSTICK_DEBUG
#endif

/**
 * 机械门架校准
 * Průša TMC_Z_CALIBRATION的现代替代品。
 * 添加了与任何可调电流驱动器一起工作的功能。
 * 作为G34实施，因为M915已被弃用。
 * @section calibrate
 */
//#define MECHANICAL_GANTRY_CALIBRATION
#if ENABLED(MECHANICAL_GANTRY_CALIBRATION)
  #define GANTRY_CALIBRATION_CURRENT          600     // 默认校准电流（毫安）
  #define GANTRY_CALIBRATION_EXTRA_HEIGHT      15     // 在Z_###_POS之外额外移动的距离（毫米）
  #define GANTRY_CALIBRATION_FEEDRATE         500     // 校正移动的进给速率
  //#define GANTRY_CALIBRATION_TO_MIN                 // 启用以在MIN方向上校准Z

  //#define GANTRY_CALIBRATION_SAFE_POSITION XY_CENTER // 喷嘴的安全位置
  //#define GANTRY_CALIBRATION_XY_PARK_FEEDRATE 3000  // XY停泊进给速率 - MMM
  //#define GANTRY_CALIBRATION_COMMANDS_PRE   ""
  #define GANTRY_CALIBRATION_COMMANDS_POST  "G28"     // 强烈建议使用G28以确保准确位置
#endif

/**
 * 瞬间冻结/解冻功能
 * 可能对允许恢复的紧急停止有用。
 * @section interface
 */
//#define FREEZE_FEATURE
#if ENABLED(FREEZE_FEATURE)
  //#define FREEZE_PIN 41   // 在此处覆盖默认（KILL）引脚
  #define FREEZE_STATE LOW  // 指示冻结的引脚状态
#endif

/**
 * MAX7219调试矩阵
 *
 * 添加对基于Max7219芯片的低成本8x8 LED矩阵的支持，
 * 作为实时状态显示。需要3个信号线。
 * 包含一些有用的调试选项来演示其使用。
 * @section debug matrix
 */
//#define MAX7219_DEBUG
#if ENABLED(MAX7219_DEBUG)
  #define MAX7219_CLK_PIN   64
  #define MAX7219_DIN_PIN   57
  #define MAX7219_LOAD_PIN  44

  //#define MAX7219_GCODE          // 添加M7219 G代码以控制LED矩阵
  #define MAX7219_INIT_TEST    2   // 启动时的测试模式：0=无，1=扫描，2=螺旋
  #define MAX7219_NUMBER_UNITS 1   // 链中的Max7219单元数。
  #define MAX7219_ROTATE       0   // 顺时针旋转显示（以 +/- 90°的倍数）
                                   // 连接器位置：右边=0，底部=-90，顶部=90，左边=180
  //#define MAX7219_REVERSE_ORDER  // 可能反转LED矩阵单元的顺序
  //#define MAX7219_REVERSE_EACH   // 可能反转每个矩阵单元行中的LED
  //#define MAX7219_SIDE_BY_SIDE   // 大型芯片+矩阵板可以侧面连接

  /**
   * 示例调试功能
   * 如果添加更多调试显示，请小心避免冲突！
   */
  #define MAX7219_DEBUG_PRINTER_ALIVE     // 闪烁8x8矩阵的角来显示固件是否正常工作
  #define MAX7219_DEBUG_PLANNER_HEAD  2   // 显示此和下一行上的计划队列头位置
  #define MAX7219_DEBUG_PLANNER_TAIL  4   // 显示此和下一行上的计划队列尾位置

  #define MAX7219_DEBUG_PLANNER_QUEUE 0   // 显示当前计划队列深度的当前行以及下一行的LED矩阵
                                          // 如果遇到卡顿、重启等问题，此选项可以实时显示
                                          // 对配置进行的调整如何影响打印机。
  #define MAX7219_DEBUG_PROFILE       6   // 在此LED矩阵上显示在受监视代码中花费的CPU时间的分数
                                          // 默认情况下对idle()进行了调整，因此此项显示处理器的“空闲”程度。
                                          // 参见CodeProfiler类。
  //#define MAX7219_DEBUG_MULTISTEPPING 6 // 在此LED矩阵上显示多步进 1 到 128。
#endif

/**
 * NanoDLP同步支持
 *
 * 支持与NanoDLP一起使用时的同步Z移动。
 * G0/G1轴移动将输出“Z_move_comp”字符串，
 * 以启用与DLP投影机曝光的同步。
 * 此功能允许您使用[[WaitForDoneMessage]]而不是M400命令。
 * @section nanodlp
 */
//#define NANODLP_Z_SYNC
#if ENABLED(NANODLP_Z_SYNC)
  //#define NANODLP_ALL_AXIS  // 发送“Z_move_comp”报告以供任何轴移动（不仅Z）。
#endif

/**
 * 以太网。使用M552启用并设置IP地址。
 * @section network
 */
#if HAS_ETHERNET
  #define MAC_ADDRESS { 0xDE, 0xAD, 0xBE, 0xEF, 0xF0, 0x0D }  // 与您的网络唯一的MAC地址
#endif

/**
 * WiFi支持（Espressif ESP32 WiFi）
 */
//#define WIFISUPPORT         // Marlin内置WiFi管理
//#define ESP3D_WIFISUPPORT   // ESP3D库WiFi管理（https://github.com/luc-github/ESP3DLib）

#if ANY(WIFISUPPORT, ESP3D_WIFISUPPORT)
  //#define WEBSUPPORT          // 启动一个Web服务器（可能包括自动发现）
  //#define OTASUPPORT          // 支持空中固件更新
  //#define WIFI_CUSTOM_COMMAND // 接受来自主机的功能配置命令（例如WiFi ESP3D）

  /**
   * 要设置默认的WiFi SSID / 密码，请创建一个名为Configuration_Secure.h的文件，
   * 其中包含针对您的网络定制的以下定义。
   * 通过.gitignore将此特定文件排除在外，以防止意外泄漏给公众。
   *
   *   #define WIFI_SSID "WiFi SSID"
   *   #define WIFI_PWD  "WiFi Password"
   */
  //#include "Configuration_Secure.h" // 带有WiFi SSID / 密码的外部文件
#endif

// @section multi-material

/**
 * Průša多材料单元（MMU）
 * 在Configuration.h中启用
 *
 * 这些设备允许板上的单个步进驱动器驱动具有任意数量步进电机的多材料进给器。
 */
#if HAS_PRUSA_MMU1
  /**
   * 此选项仅允许多路复用器在工具切换时进行切换。
   * 配置自定义E移动选项尚待开发。
   *
   * 如果需要，可以在此处覆盖默认的DIO选择器引脚。
   * 某些引脚文件可能为这些引脚提供了默认值。
   */
  //#define E_MUX0_PIN 40  // 始终需要
  //#define E_MUX1_PIN 42  // 对于3到8个输入需要
  //#define E_MUX2_PIN 44  // 对于5到8个输入需要
#elif HAS_PRUSA_MMU2
  // 用于与MMU2通信的串口。
  #define MMU2_SERIAL_PORT 2

  // 如果有定义用于MMU的引脚，则使用硬件复位
  //#define MMU2_RST_PIN 23

  // 启用如果MMU2具有12V步进电机（MMU2固件1.0.2及更高版本）
  //#define MMU2_MODE_12V

  // 当MMU2 F.I.N.D.A.探测到丝材耗尽时执行的G代码
  #define MMU2_FILAMENT_RUNOUT_SCRIPT "M600"

// 添加一个用于MMU2的LCD菜单
//#define MMU2_MENUS

// 用于从LCD菜单加载/卸载丝材的设置。
// 这是针对Průša MK3风格挤出机。根据您的硬件进行自定义。
#define MMU2_FILAMENTCHANGE_EJECT_FEED 80.0
#define MMU2_LOAD_TO_NOZZLE_SEQUENCE \
  {  7.2, 1145 }, \
  { 14.4,  871 }, \
  { 36.0, 1393 }, \
  { 14.4,  871 }, \
  { 50.0,  198 }

#define MMU2_RAMMING_SEQUENCE \
  {   1.0, 1000 }, \
  {   1.0, 1500 }, \
  {   2.0, 2000 }, \
  {   1.5, 3000 }, \
  {   2.5, 4000 }, \
  { -15.0, 5000 }, \
  { -14.0, 1200 }, \
  {  -6.0,  600 }, \
  {  10.0,  700 }, \
  { -10.0,  400 }, \
  { -50.0, 2000 }

/**
 * 使用类似MMU2S的传感器
 * 此模式需要带有传感器的MK3S挤出机，例如MMU2S。
 * 请参阅https://help.prusa3d.com/guide/3b-mk3s-mk2-5s-extruder-upgrade_41560#42048，第11步
 */
#if HAS_PRUSA_MMU2S
  #define MMU2_C0_RETRY   5             // 重试次数（总时间 = 超时*重试次数）

  #define MMU2_CAN_LOAD_FEEDRATE 800    // （mm/min）
  #define MMU2_CAN_LOAD_SEQUENCE \
    {  0.1, MMU2_CAN_LOAD_FEEDRATE }, \
    {  60.0, MMU2_CAN_LOAD_FEEDRATE }, \
    { -52.0, MMU2_CAN_LOAD_FEEDRATE }

  #define MMU2_CAN_LOAD_RETRACT   6.0   // （mm）保持在加载序列值之间的距离以下
  #define MMU2_CAN_LOAD_DEVIATION 0.8   // （mm）可接受的误差

  #define MMU2_CAN_LOAD_INCREMENT 0.2   // （mm）在MMU2模块内重复使用
  #define MMU2_CAN_LOAD_INCREMENT_SEQUENCE \
    { -MMU2_CAN_LOAD_INCREMENT, MMU2_CAN_LOAD_FEEDRATE }

  // 如果传感器在初始卸载移动后检测到丝材，则继续卸载
  //#define MMU_IR_UNLOAD_MOVE
#else

  /**
   * MMU1挤出机传感器
   *
   * 支持Průša（或其他）红外传感器，用于检测挤出机附近的丝材，
   * 从而使加载更可靠。适用于与齿轮之间距离小于38mm的挤出机配备的丝材传感器。
   *
   * 在加载过程中，当传感器被触发时，挤出机将停止，然后最后一次移动到齿轮位置。
   * 如果未检测到丝材，MMU2可以尝试更多次。如果所有尝试都失败，将触发丝材耗尽。
   */
  //#define MMU_EXTRUDER_SENSOR
  #if ENABLED(MMU_EXTRUDER_SENSOR)
    #define MMU_LOADING_ATTEMPTS_NR 5 // 如果首次加载失败，最大加载丝材尝试次数
  #endif

#endif

//#define MMU2_DEBUG  // 将调试信息写入串行输出

#endif // HAS_PRUSA_MMU2

/**
 * 高级打印计数器设置
 * @section stats
 */
#if ENABLED(PRINTCOUNTER)
  #define SERVICE_WARNING_BUZZES  3
  // 激活最多3个服务间隔看门狗
  //#define SERVICE_NAME_1      "Service S"
  //#define SERVICE_INTERVAL_1  100 // 打印时间（小时）
  //#define SERVICE_NAME_2      "Service L"
  //#define SERVICE_INTERVAL_2  200 // 打印时间（小时）
  //#define SERVICE_NAME_3      "Service 3"
  //#define SERVICE_INTERVAL_3    1 // 打印时间（小时）
#endif

// @section develop

//
// M100空闲内存监视器，用于调试内存使用情况
//
//#define M100_FREE_MEMORY_WATCHER

//
// M42 - 设置引脚状态
//
//#define DIRECT_PIN_CONTROL

//
// M43 - 显示引脚状态，切换引脚，监视引脚，监视限位开关和切换LED，测试伺服探针
//
//#define PINS_DEBUGGING

// 启用在启动时运行的测试，并生成报告
//#define MARLIN_TEST_BUILD

// 启用Marlin开发模式，添加一些特殊命令
//#define MARLIN_DEV_MODE

#if ENABLED(MARLIN_DEV_MODE)
  /**
   * D576 - 缓冲区监视
   * 为了帮助诊断与空命令缓冲区相关的打印质量问题。
   */
  //#define BUFFER_MONITORING
#endif

/**
 * 后期调试会捕获错误行为并将CPU状态和回溯输出到串行端口。
 * 在调试器中运行时，它将中断以进行调试。这有助于在远程位置理解崩溃情况。需要约400字节的SRAM和5Kb的闪存。
 */
//#define POSTMORTEM_DEBUGGING

/**
 * 软件复位选项
 */
//#define SOFT_RESET_VIA_SERIAL         // “KILL”和“^X”命令将软复位控制器
//#define SOFT_RESET_ON_KILL            // 使用数字按钮在KILL后软复位控制器

// 报告从寄存器r2而不是MCUSR清除的复位原因。由Optiboot在AVR上支持。
//#define OPTIBOOT_RESET_REASON
