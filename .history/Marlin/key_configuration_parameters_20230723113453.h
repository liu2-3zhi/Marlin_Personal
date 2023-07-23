#pragma once

//打印机主板类型
#define MOTHERBOARD BOARD_MKS_ROBIN_E3D

//设置设备编号
//777为保留配置
//001,002,003,004,005,006,007,010,011,012
//000表示读取"Configuration.h"的配置信息
#define Equipment_Number 003

//————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//确保Equipment_Number设置正确
#if (Equipment_Number != 777 && Equipment_Number != 000 && Equipment_Number != 001 && Equipment_Number != 002 && Equipment_Number != 003 && Equipment_Number != 004 && Equipment_Number != 005 && Equipment_Number != 006 && Equipment_Number != 007 && Equipment_Number != 010 && Equipment_Number != 011 && Equipment_Number != 012)
    #error "Equipment_Number设置不正确，只能为、000、001、002、003、004、005、006、007、010、011、012、777"
#endif

//————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
//000

#if Equipment_Number == 000
    #warning "当前Equipment_Number为000，将不再对Configuration.h的配置信息进行覆盖。"
#endif

//————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#if Equipment_Number == 001

// 001
// 挤出头PID参数
//参考数值：
//K5A CR8 12V 40W
// Kp  25.81
// Ki   2.71
// Kd  61.56
//K5B E3D 12V 40W
// Kp  26.23
// Ki   2.82
// kd  60.99
//K5 15V 12V30W  CR8  
// Kp 18.76
// Ki 2.23
// Kd 39.47
//
//原固件参数
// Kp 22.20
// Ki 1.08
// Kd 114.00
#define DEFAULT_Kp_Key  22.20
#define DEFAULT_Ki_Key   1.08
#define DEFAULT_Kd_Key  114.00

// 热床PID参数
//参考数值
//200热床实测
// Kp 17.04
// Ki 0.30
// Kd 641.99
//150热床实测
// Kp 44.84
// Ki 2.96
// Kd 452.87
//
//原固件参数

// Kp 17.04
// Ki 0.30
// Kd 641.99
#define DEFAULT_bedKp_Key 17.04
#define DEFAULT_bedKi_Key 0.30
#define DEFAULT_bedKd_Key 641.99

// 轴步数（步数/mm）
// 每mm的脉冲数
// X：80
// Y：80
// Z：400
// E：98
#define DEFAULT_AXIS_STEPS_PER_UNIT_X 80
#define DEFAULT_AXIS_STEPS_PER_UNIT_Y 80
#define DEFAULT_AXIS_STEPS_PER_UNIT_Z 400
#define DEFAULT_AXIS_STEPS_PER_UNIT_E 98


// 最大速度（mm/s）
// 每秒钟移动的最大毫米数
// X：300
// Y：300
// Z：5
// E：25
#define DEFAULT_MAX_FEEDRATE_X 300
#define DEFAULT_MAX_FEEDRATE_Y 300
#define DEFAULT_MAX_FEEDRATE_Z 5
#define DEFAULT_MAX_FEEDRATE_E 25

// 最大加速度（mm/s2）
// 每秒钟速度的变化量
// X：3000
// Y：3000
// Z：100
// E：1000
#define DEFAULT_MAX_ACCELERATION_X 3000
#define DEFAULT_MAX_ACCELERATION_Y 3000
#define DEFAULT_MAX_ACCELERATION_Z 100
#define DEFAULT_MAX_ACCELERATION_E 1000

//默认加速度
// X, Y, Z ... 和 E 打印移动的加速度 3000
// 回退的 E 的加速度 3000
// X, Y, Z ... 的移动（非打印）加速度 3000
#define DEFAULT_ACCELERATION_Key          3000
#define DEFAULT_RETRACT_ACCELERATION_Key  3000
#define DEFAULT_TRAVEL_ACCELERATION_Key   3000

// Z探针类型：(Fixed/Bltouch)
// 固定安装的探针
#define Z_Axis_Probe Fixed

// 探针偏移量
//       +-- 后面 ---+
//       |    [+]    |
//     L |        1  | R <-- 示例 "1" (右+,  后+)
//     E |  2        | I <-- 示例 "2" ( 左-,  后+)
//     F |[-]  N  [+]| G <-- 喷嘴
//     T |       3   | H <-- 示例 "3" (右+,  前-)
//       | 4         | T <-- 示例 "4" ( 左-,  前-)
//       |    [-]    |
//       O-- 前面 --+
// {15, -40,0 }
// 探针位于喷嘴右侧15毫米处，位于喷嘴前方40毫米处，在Z轴上没有偏移
#define NOZZLE_TO_PROBE_OFFSET_X 15
#define NOZZLE_TO_PROBE_OFFSET_Y -40
#define NOZZLE_TO_PROBE_OFFSET_Z 0

// 电机反向
// X：反向
// Y：反向
// Z：不反向
#define INVERT_X_DIR_Key false
#define INVERT_Y_DIR_Key false
#define INVERT_Z_DIR_Key false

// 打印区域
// X：200
// Y：200
// Z：160
#define Printable_Area_X 200
#define Printable_Area_Y 200
#define Printable_Area_Z 160

// 控制器类型
// REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER
// 说白了就是LCD12864
#define REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER_Key

// 步进电机驱动器类型
//  选项：A4988, A5984, DRV8825, LV8729, TB6560, TB6600, TMC2100,
//           TMC2130, TMC2130_STANDALONE, TMC2160, TMC2160_STANDALONE,
//           TMC2208, TMC2208_STANDALONE, TMC2209, TMC2209_STANDALONE,
//           TMC26X,  TMC26X_STANDALONE,  TMC2660, TMC2660_STANDALONE,
//           TMC5130, TMC5130_STANDALONE, TMC5160, TMC5160_STANDALONE
// X：TMC2209
// Y：TMC2209
// Z：TMC2209
// E：TMC2209
#define X_DRIVER_TYPE_KEY TMC2209
#define Y_DRIVER_TYPE_KEY TMC2209
#define Z_DRIVER_TYPE_KEY TMC2209
#define E_DRIVER_TYPE_KEY TMC2209

//反转LCD屏幕编码器方向（true/false）
#define REVERSE_ENCODER_DIRECTION_key true

//断料检测（true/false）
//关闭耗材传感器
#define FILAMENT_RUNOUT_SENSOR_Key false

//用Z Probe Stop替换ZMIN STOP（true/false）
#define Z_Probe_Stop_Replace_ZMIN_STOP false

//热床多次探测
//每个点的探测次数
//总共探测3次
#define Number_Of_Probes_Per_Point 3
//每个点的探测次数
//总共探测3次
#define Number_Of_Probes_Per_Point 3

//防止温度传感器失效
//如果挤出头在 E_Heating_Waiting_Time 秒内，温度没有上升 E_Temperature_Rise_During_Heating_Wait_Time 摄氏度，就意味着温度传感器失效。
//打印机将会停止工作，直到被重置。
#define E_Heating_Waiting_Time 40           //秒
#define E_Temperature_Rise_During_Heating_Wait_Time 1          //摄氏度
//如果热床在 BED_Heating_Waiting_Time 秒内，温度没有上升 BED_Temperature_Rise_During_Heating_Wait_Time 摄氏度，就意味着温度传感器失效。
//打印机将会停止工作，直到被重置。
#define BED_Heating_Waiting_Time 40           //秒
#define BED_Temperature_Rise_During_Heating_Wait_Time 1          //摄氏度

#endif
//————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#if Equipment_Number == 002

// 002
// 挤出头PID参数
//参考数值：
//K5A CR8 12V 40W
// Kp  25.81
// Ki   2.71
// Kd  61.56
//K5B E3D 12V 40W
// Kp  26.23
// Ki   2.82
// kd  60.99
//K5 15V 12V30W  CR8  
// Kp 18.76
// Ki 2.23
// Kd 39.47
//
//原固件参数
// Kp 22.20
// Ki 1.08
// Kd 114.00
#define DEFAULT_Kp_Key  22.20
#define DEFAULT_Ki_Key   1.08
#define DEFAULT_Kd_Key  114.00

// 热床PID参数
//参考数值
//200热床实测
// Kp 17.04
// Ki 0.30
// Kd 641.99
//150热床实测
// Kp 44.84
// Ki 2.96
// Kd 452.87
//
//原固件参数

// Kp 17.04
// Ki 0.30
// Kd 641.99
#define DEFAULT_bedKp_Key 17.04
#define DEFAULT_bedKi_Key 0.30
#define DEFAULT_bedKd_Key 641.99

// 轴步数（步数/mm）
// 每mm的脉冲数
// X：80
// Y：80
// Z：400
// E：398
#define DEFAULT_AXIS_STEPS_PER_UNIT_X 80
#define DEFAULT_AXIS_STEPS_PER_UNIT_Y 80
#define DEFAULT_AXIS_STEPS_PER_UNIT_Z 400
#define DEFAULT_AXIS_STEPS_PER_UNIT_E 390


// 最大速度（mm/s）
// 每秒钟移动的最大毫米数
// X：300
// Y：300
// Z：5
// E：25
#define DEFAULT_MAX_FEEDRATE_X 300
#define DEFAULT_MAX_FEEDRATE_Y 300
#define DEFAULT_MAX_FEEDRATE_Z 5
#define DEFAULT_MAX_FEEDRATE_E 25

// 最大加速度（mm/s2）
// 每秒钟速度的变化量
// X：3000
// Y：3000
// Z：100
// E：1000
#define DEFAULT_MAX_ACCELERATION_X 3000
#define DEFAULT_MAX_ACCELERATION_Y 3000
#define DEFAULT_MAX_ACCELERATION_Z 100
#define DEFAULT_MAX_ACCELERATION_E 1000

//默认加速度
// X, Y, Z ... 和 E 打印移动的加速度 3000
// 回退的 E 的加速度 3000
// X, Y, Z ... 的移动（非打印）加速度 3000
#define DEFAULT_ACCELERATION_Key          3000
#define DEFAULT_RETRACT_ACCELERATION_Key  3000
#define DEFAULT_TRAVEL_ACCELERATION_Key   3000

// Z探针类型：(Fixed/Bltouch)
// 固定安装的探针
#define Z_Axis_Probe Fixed

// 探针偏移量
//       +-- 后面 ---+
//       |    [+]    |
//     L |        1  | R <-- 示例 "1" (右+,  后+)
//     E |  2        | I <-- 示例 "2" ( 左-,  后+)
//     F |[-]  N  [+]| G <-- 喷嘴
//     T |       3   | H <-- 示例 "3" (右+,  前-)
//       | 4         | T <-- 示例 "4" ( 左-,  前-)
//       |    [-]    |
//       O-- 前面 --+
// { -35, -25,-1.1 }
// 探针位于喷嘴左侧15毫米处，位于喷嘴前方25毫米处，位于喷嘴下方1.1毫米处
#define NOZZLE_TO_PROBE_OFFSET_X -35
#define NOZZLE_TO_PROBE_OFFSET_Y -25
#define NOZZLE_TO_PROBE_OFFSET_Z -1.1

// 电机反向
// X：反向
// Y：反向
// Z：不反向
#define INVERT_X_DIR_Key false
#define INVERT_Y_DIR_Key false
#define INVERT_Z_DIR_Key false

// 打印区域
// X：200
// Y：200
// Z：260
#define Printable_Area_X 200
#define Printable_Area_Y 200
#define Printable_Area_Z 260

// 控制器类型
// REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER
// 说白了就是LCD12864
#define REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER_Key

// 步进电机驱动器类型
//  选项：A4988, A5984, DRV8825, LV8729, TB6560, TB6600, TMC2100,
//           TMC2130, TMC2130_STANDALONE, TMC2160, TMC2160_STANDALONE,
//           TMC2208, TMC2208_STANDALONE, TMC2209, TMC2209_STANDALONE,
//           TMC26X,  TMC26X_STANDALONE,  TMC2660, TMC2660_STANDALONE,
//           TMC5130, TMC5130_STANDALONE, TMC5160, TMC5160_STANDALONE
// X：TMC2209
// Y：TMC2209
// Z：TMC2209
// E：TMC2209
#define X_DRIVER_TYPE_KEY TMC2209
#define Y_DRIVER_TYPE_KEY TMC2209
#define Z_DRIVER_TYPE_KEY TMC2209
#define E_DRIVER_TYPE_KEY TMC2209

//反转LCD屏幕编码器方向（true/false）
#define REVERSE_ENCODER_DIRECTION_key true

//断料检测（true/false）
//关闭耗材传感器
#define FILAMENT_RUNOUT_SENSOR_Key false

//用Z Probe Stop替换ZMIN STOP（true/false）
#define Z_Probe_Stop_Replace_ZMIN_STOP false

//热床多次探测
//每个点的探测次数
//总共探测3次
#define Number_Of_Probes_Per_Point 3
//每个点的探测次数
//总共探测3次
#define Number_Of_Probes_Per_Point 3

//防止温度传感器失效
//如果挤出头在 E_Heating_Waiting_Time 秒内，温度没有上升 E_Temperature_Rise_During_Heating_Wait_Time 摄氏度，就意味着温度传感器失效。
//打印机将会停止工作，直到被重置。
#define E_Heating_Waiting_Time 40           //秒
#define E_Temperature_Rise_During_Heating_Wait_Time 1          //摄氏度
//如果热床在 BED_Heating_Waiting_Time 秒内，温度没有上升 BED_Temperature_Rise_During_Heating_Wait_Time 摄氏度，就意味着温度传感器失效。
//打印机将会停止工作，直到被重置。
#define BED_Heating_Waiting_Time 40           //秒
#define BED_Temperature_Rise_During_Heating_Wait_Time 1          //摄氏度

#endif

//————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#if Equipment_Number == 003

// 003
// 挤出头PID参数
//参考数值：
//K5A CR8 12V 40W
// Kp  25.81
// Ki   2.71
// Kd  61.56
//K5B E3D 12V 40W
// Kp  26.23
// Ki   2.82
// kd  60.99
//K5 15V 12V30W  CR8  
// Kp 18.76
// Ki 2.23
// Kd 39.47
//
//原固件参数
// Kp 22.20
// Ki 1.08
// Kd 114.00
#define DEFAULT_Kp_Key  22.20
#define DEFAULT_Ki_Key   1.08
#define DEFAULT_Kd_Key  114.00

// 热床PID参数
//参考数值
//200热床实测
// Kp 17.04
// Ki 0.30
// Kd 641.99
//150热床实测
// Kp 44.84
// Ki 2.96
// Kd 452.87
//
//原固件参数

// Kp 17.04
// Ki 0.30
// Kd 641.99
#define DEFAULT_bedKp_Key 17.04
#define DEFAULT_bedKi_Key 0.30
#define DEFAULT_bedKd_Key 641.99

// 轴步数（步数/mm）
// 每mm的脉冲数
// X：80
// Y：80
// Z：400
// E：398
#define DEFAULT_AXIS_STEPS_PER_UNIT_X 80
#define DEFAULT_AXIS_STEPS_PER_UNIT_Y 80
#define DEFAULT_AXIS_STEPS_PER_UNIT_Z 800
#define DEFAULT_AXIS_STEPS_PER_UNIT_E 380


// 最大速度（mm/s）
// 每秒钟移动的最大毫米数
// X：300
// Y：300
// Z：5
// E：25
#define DEFAULT_MAX_FEEDRATE_X 300
#define DEFAULT_MAX_FEEDRATE_Y 300
#define DEFAULT_MAX_FEEDRATE_Z 5
#define DEFAULT_MAX_FEEDRATE_E 25

// 最大加速度（mm/s2）
// 每秒钟速度的变化量
// X：3000
// Y：3000
// Z：100
// E：1000
#define DEFAULT_MAX_ACCELERATION_X 3000
#define DEFAULT_MAX_ACCELERATION_Y 3000
#define DEFAULT_MAX_ACCELERATION_Z 100
#define DEFAULT_MAX_ACCELERATION_E 1000

//默认加速度
// X, Y, Z ... 和 E 打印移动的加速度 3000
// 回退的 E 的加速度 3000
// X, Y, Z ... 的移动（非打印）加速度 3000
#define DEFAULT_ACCELERATION_Key          3000
#define DEFAULT_RETRACT_ACCELERATION_Key  3000
#define DEFAULT_TRAVEL_ACCELERATION_Key   3000

// Z探针类型：(Fixed/Bltouch)
// 固定安装的探针
#define Z_Axis_Probe Fixed

// 探针偏移量
//       +-- 后面 ---+
//       |    [+]    |
//     L |        1  | R <-- 示例 "1" (右+,  后+)
//     E |  2        | I <-- 示例 "2" ( 左-,  后+)
//     F |[-]  N  [+]| G <-- 喷嘴
//     T |       3   | H <-- 示例 "3" (右+,  前-)
//       | 4         | T <-- 示例 "4" ( 左-,  前-)
//       |    [-]    |
//       O-- 前面 --+
//{ -35, -30, -3.7 }
// 探针位于喷嘴左侧35毫米处，位于喷嘴前方30毫米处，位于喷嘴下方3.7毫米处
#define NOZZLE_TO_PROBE_OFFSET_X -35
#define NOZZLE_TO_PROBE_OFFSET_Y -30
#define NOZZLE_TO_PROBE_OFFSET_Z -3.7

// 电机反向
// X：反向
// Y：反向
// Z：不反向
#define INVERT_X_DIR_Key false
#define INVERT_Y_DIR_Key false
#define INVERT_Z_DIR_Key false

// 打印区域
// X：200
// Y：200
// Z：260
#define Printable_Area_X 150
#define Printable_Area_Y 150
#define Printable_Area_Z 160

// 控制器类型
// REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER
// 说白了就是LCD12864
#define REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER_Key

// 步进电机驱动器类型
//  选项：A4988, A5984, DRV8825, LV8729, TB6560, TB6600, TMC2100,
//           TMC2130, TMC2130_STANDALONE, TMC2160, TMC2160_STANDALONE,
//           TMC2208, TMC2208_STANDALONE, TMC2209, TMC2209_STANDALONE,
//           TMC26X,  TMC26X_STANDALONE,  TMC2660, TMC2660_STANDALONE,
//           TMC5130, TMC5130_STANDALONE, TMC5160, TMC5160_STANDALONE
// X：TMC2209
// Y：TMC2209
// Z：TMC2209
// E：TMC2209
#define X_DRIVER_TYPE_KEY A4988
#define Y_DRIVER_TYPE_KEY A4988
#define Z_DRIVER_TYPE_KEY A4988
#define E_DRIVER_TYPE_KEY A4988

//不反转LCD屏幕编码器方向（true/false）
#define REVERSE_ENCODER_DIRECTION_key false

//断料检测（true/false）
//关闭耗材传感器
#define FILAMENT_RUNOUT_SENSOR_Key false

//用Z Probe Stop替换ZMIN STOP（true/false）
#define Z_Probe_Stop_Replace_ZMIN_STOP false

//热床多次探测
//每个点的探测次数
//总共探测3次
#define Number_Of_Probes_Per_Point 3
//将抛弃最差的数据的个数，剩余的求平均值
//抛弃最差的1个数据
#define The_Number_Of_Data_That_Is_Allowed_To_Be_Discarded 1

//防止温度传感器失效
//如果挤出头在 E_Heating_Waiting_Time 秒内，温度没有上升 E_Temperature_Rise_During_Heating_Wait_Time 摄氏度，就意味着温度传感器失效。
//打印机将会停止工作，直到被重置。
#define E_Heating_Waiting_Time 40           //秒
#define E_Temperature_Rise_During_Heating_Wait_Time 1          //摄氏度
//如果热床在 BED_Heating_Waiting_Time 秒内，温度没有上升 BED_Temperature_Rise_During_Heating_Wait_Time 摄氏度，就意味着温度传感器失效。
//打印机将会停止工作，直到被重置。
#define BED_Heating_Waiting_Time 40           //秒
#define BED_Temperature_Rise_During_Heating_Wait_Time 1          //摄氏度

#endif

//————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#if Equipment_Number == 004

// 004
// 挤出头PID参数
//参考数值：
//K5A CR8 12V 40W
// Kp  25.81
// Ki   2.71
// Kd  61.56
//K5B E3D 12V 40W
// Kp  26.23
// Ki   2.82
// kd  60.99
//K5 15V 12V30W  CR8  
// Kp 18.76
// Ki 2.23
// Kd 39.47
//
//原固件参数
// Kp 22.20
// Ki 1.08
// Kd 114.00
#define DEFAULT_Kp_Key  22.20
#define DEFAULT_Ki_Key   1.08
#define DEFAULT_Kd_Key  114.00

// 热床PID参数
//参考数值
//200热床实测
// Kp 17.04
// Ki 0.30
// Kd 641.99
//150热床实测
// Kp 44.84
// Ki 2.96
// Kd 452.87
//
//原固件参数

// Kp 17.04
// Ki 0.30
// Kd 641.99
#define DEFAULT_bedKp_Key 17.04
#define DEFAULT_bedKi_Key 0.30
#define DEFAULT_bedKd_Key 641.99

// 轴步数（步数/mm）
// 每mm的脉冲数
// X：80
// Y：80
// Z：400
// E：398
#define DEFAULT_AXIS_STEPS_PER_UNIT_X 80
#define DEFAULT_AXIS_STEPS_PER_UNIT_Y 80
#define DEFAULT_AXIS_STEPS_PER_UNIT_Z 400
#define DEFAULT_AXIS_STEPS_PER_UNIT_E 415


// 最大速度（mm/s）
// 每秒钟移动的最大毫米数
// X：300
// Y：300
// Z：5
// E：25
#define DEFAULT_MAX_FEEDRATE_X 300
#define DEFAULT_MAX_FEEDRATE_Y 300
#define DEFAULT_MAX_FEEDRATE_Z 5
#define DEFAULT_MAX_FEEDRATE_E 25

// 最大加速度（mm/s2）
// 每秒钟速度的变化量
// X：3000
// Y：3000
// Z：100
// E：1000
#define DEFAULT_MAX_ACCELERATION_X 3000
#define DEFAULT_MAX_ACCELERATION_Y 3000
#define DEFAULT_MAX_ACCELERATION_Z 100
#define DEFAULT_MAX_ACCELERATION_E 1000

//默认加速度
// X, Y, Z ... 和 E 打印移动的加速度 3000
// 回退的 E 的加速度 3000
// X, Y, Z ... 的移动（非打印）加速度 3000
#define DEFAULT_ACCELERATION_Key          3000
#define DEFAULT_RETRACT_ACCELERATION_Key  3000
#define DEFAULT_TRAVEL_ACCELERATION_Key   3000

// Z探针类型：(Fixed/Bltouch)
// 固定安装的探针
#define Z_Axis_Probe Fixed

// 探针偏移量
//       +-- 后面 ---+
//       |    [+]    |
//     L |        1  | R <-- 示例 "1" (右+,  后+)
//     E |  2        | I <-- 示例 "2" ( 左-,  后+)
//     F |[-]  N  [+]| G <-- 喷嘴
//     T |       3   | H <-- 示例 "3" (右+,  前-)
//       | 4         | T <-- 示例 "4" ( 左-,  前-)
//       |    [-]    |
//       O-- 前面 --+
//{ -35, -30, -3.7 }
// 探针位于喷嘴左侧35毫米处，位于喷嘴前方30毫米处，位于喷嘴下方3.95毫米处
#define NOZZLE_TO_PROBE_OFFSET_X -35
#define NOZZLE_TO_PROBE_OFFSET_Y -30
#define NOZZLE_TO_PROBE_OFFSET_Z -3.95

// 电机反向
// X：反向
// Y：反向
// Z：不反向
#define INVERT_X_DIR_Key false
#define INVERT_Y_DIR_Key false
#define INVERT_Z_DIR_Key false

// 打印区域
// X：200
// Y：200
// Z：260
#define Printable_Area_X 130
#define Printable_Area_Y 130
#define Printable_Area_Z 160

// 控制器类型
// REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER
// 说白了就是LCD12864
#define REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER_Key

// 步进电机驱动器类型
//  选项：A4988, A5984, DRV8825, LV8729, TB6560, TB6600, TMC2100,
//           TMC2130, TMC2130_STANDALONE, TMC2160, TMC2160_STANDALONE,
//           TMC2208, TMC2208_STANDALONE, TMC2209, TMC2209_STANDALONE,
//           TMC26X,  TMC26X_STANDALONE,  TMC2660, TMC2660_STANDALONE,
//           TMC5130, TMC5130_STANDALONE, TMC5160, TMC5160_STANDALONE
// X：TMC2209
// Y：TMC2209
// Z：TMC2209
// E：TMC2209
#define X_DRIVER_TYPE_KEY A4988
#define Y_DRIVER_TYPE_KEY A4988
#define Z_DRIVER_TYPE_KEY A4988
#define E_DRIVER_TYPE_KEY A4988

//不反转LCD屏幕编码器方向（true/false）
#define REVERSE_ENCODER_DIRECTION_key false

//断料检测（true/false）
//关闭耗材传感器
#define FILAMENT_RUNOUT_SENSOR_Key false

//用Z Probe Stop替换ZMIN STOP（true/false）
#define Z_Probe_Stop_Replace_ZMIN_STOP false

//热床多次探测
//每个点的探测次数
//总共探测3次
#define Number_Of_Probes_Per_Point 3
//每个点的探测次数
//总共探测3次
#define Number_Of_Probes_Per_Point 3

//防止温度传感器失效
//如果挤出头在 E_Heating_Waiting_Time 秒内，温度没有上升 E_Temperature_Rise_During_Heating_Wait_Time 摄氏度，就意味着温度传感器失效。
//打印机将会停止工作，直到被重置。
#define E_Heating_Waiting_Time 40           //秒
#define E_Temperature_Rise_During_Heating_Wait_Time 1          //摄氏度
//如果热床在 BED_Heating_Waiting_Time 秒内，温度没有上升 BED_Temperature_Rise_During_Heating_Wait_Time 摄氏度，就意味着温度传感器失效。
//打印机将会停止工作，直到被重置。
#define BED_Heating_Waiting_Time 40           //秒
#define BED_Temperature_Rise_During_Heating_Wait_Time 1          //摄氏度

#endif

//————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#if Equipment_Number == 005

// 005
// 挤出头PID参数
//参考数值：
//K5A CR8 12V 40W
// Kp  25.81
// Ki   2.71
// Kd  61.56
//K5B E3D 12V 40W
// Kp  26.23
// Ki   2.82
// kd  60.99
//K5 15V 12V30W  CR8  
// Kp 18.76
// Ki 2.23
// Kd 39.47
//
//原固件参数
// Kp 22.20
// Ki 1.08
// Kd 114.00
#define DEFAULT_Kp_Key  22.20
#define DEFAULT_Ki_Key   1.08
#define DEFAULT_Kd_Key  114.00

// 热床PID参数
//参考数值
//200热床实测
// Kp 17.04
// Ki 0.30
// Kd 641.99
//150热床实测
// Kp 44.84
// Ki 2.96
// Kd 452.87
//
//原固件参数

// Kp 17.04
// Ki 0.30
// Kd 641.99
#define DEFAULT_bedKp_Key 17.04
#define DEFAULT_bedKi_Key 0.30
#define DEFAULT_bedKd_Key 641.99

// 轴步数（步数/mm）
// 每mm的脉冲数
// X：80
// Y：80
// Z：400
// E：398
#define DEFAULT_AXIS_STEPS_PER_UNIT_X 80
#define DEFAULT_AXIS_STEPS_PER_UNIT_Y 80
#define DEFAULT_AXIS_STEPS_PER_UNIT_Z 400
#define DEFAULT_AXIS_STEPS_PER_UNIT_E 764


// 最大速度（mm/s）
// 每秒钟移动的最大毫米数
// X：300
// Y：300
// Z：5
// E：25
#define DEFAULT_MAX_FEEDRATE_X 300
#define DEFAULT_MAX_FEEDRATE_Y 300
#define DEFAULT_MAX_FEEDRATE_Z 5
#define DEFAULT_MAX_FEEDRATE_E 25

// 最大加速度（mm/s2）
// 每秒钟速度的变化量
// X：3000
// Y：3000
// Z：100
// E：1000
#define DEFAULT_MAX_ACCELERATION_X 3000
#define DEFAULT_MAX_ACCELERATION_Y 3000
#define DEFAULT_MAX_ACCELERATION_Z 100
#define DEFAULT_MAX_ACCELERATION_E 1000

//默认加速度
// X, Y, Z ... 和 E 打印移动的加速度 3000
// 回退的 E 的加速度 3000
// X, Y, Z ... 的移动（非打印）加速度 3000
#define DEFAULT_ACCELERATION_Key          3000
#define DEFAULT_RETRACT_ACCELERATION_Key  3000
#define DEFAULT_TRAVEL_ACCELERATION_Key   3000

// Z探针类型：(Fixed/Bltouch)
// 固定安装的探针
#define Z_Axis_Probe Fixed

// 探针偏移量
//       +-- 后面 ---+
//       |    [+]    |
//     L |        1  | R <-- 示例 "1" (右+,  后+)
//     E |  2        | I <-- 示例 "2" ( 左-,  后+)
//     F |[-]  N  [+]| G <-- 喷嘴
//     T |       3   | H <-- 示例 "3" (右+,  前-)
//       | 4         | T <-- 示例 "4" ( 左-,  前-)
//       |    [-]    |
//       O-- 前面 --+
//{ -30, 0,-2 }
// 探针位于喷嘴左侧30毫米处，在Y轴没有偏移，位于喷嘴下方2毫米处
#define NOZZLE_TO_PROBE_OFFSET_X -30
#define NOZZLE_TO_PROBE_OFFSET_Y 0
#define NOZZLE_TO_PROBE_OFFSET_Z -2

// 电机反向
// X：反向
// Y：反向
// Z：不反向
#define INVERT_X_DIR_Key false
#define INVERT_Y_DIR_Key false
#define INVERT_Z_DIR_Key false

// 打印区域
// X：200
// Y：200
// Z：260
#define Printable_Area_X 145
#define Printable_Area_Y 135
#define Printable_Area_Z 160

// 控制器类型
// REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER
// 说白了就是LCD12864
#define REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER_Key

// 步进电机驱动器类型
//  选项：A4988, A5984, DRV8825, LV8729, TB6560, TB6600, TMC2100,
//           TMC2130, TMC2130_STANDALONE, TMC2160, TMC2160_STANDALONE,
//           TMC2208, TMC2208_STANDALONE, TMC2209, TMC2209_STANDALONE,
//           TMC26X,  TMC26X_STANDALONE,  TMC2660, TMC2660_STANDALONE,
//           TMC5130, TMC5130_STANDALONE, TMC5160, TMC5160_STANDALONE
// X：TMC2209
// Y：TMC2209
// Z：TMC2209
// E：TMC2209
#define X_DRIVER_TYPE_KEY A4988
#define Y_DRIVER_TYPE_KEY A4988
#define Z_DRIVER_TYPE_KEY A4988
#define E_DRIVER_TYPE_KEY A4988

//反转LCD屏幕编码器方向（true/false）
#define REVERSE_ENCODER_DIRECTION_key true

//断料检测（true/false）
//开启耗材断料传感器
#define FILAMENT_RUNOUT_SENSOR_Key true

//用Z Probe Stop替换ZMIN STOP（true/false）
#define Z_Probe_Stop_Replace_ZMIN_STOP false

//热床多次探测
//每个点的探测次数
//总共探测3次
#define Number_Of_Probes_Per_Point 3
//每个点的探测次数
//总共探测3次
#define Number_Of_Probes_Per_Point 3

//防止温度传感器失效
//如果挤出头在 E_Heating_Waiting_Time 秒内，温度没有上升 E_Temperature_Rise_During_Heating_Wait_Time 摄氏度，就意味着温度传感器失效。
//打印机将会停止工作，直到被重置。
#define E_Heating_Waiting_Time 40           //秒
#define E_Temperature_Rise_During_Heating_Wait_Time 1          //摄氏度
//如果热床在 BED_Heating_Waiting_Time 秒内，温度没有上升 BED_Temperature_Rise_During_Heating_Wait_Time 摄氏度，就意味着温度传感器失效。
//打印机将会停止工作，直到被重置。
#define BED_Heating_Waiting_Time 40           //秒
#define BED_Temperature_Rise_During_Heating_Wait_Time 1          //摄氏度

#endif

//————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#if Equipment_Number == 006

// 006
// 挤出头PID参数
//参考数值：
//K5A CR8 12V 40W
// Kp  25.81
// Ki   2.71
// Kd  61.56
//K5B E3D 12V 40W
// Kp  26.23
// Ki   2.82
// kd  60.99
//K5 15V 12V30W  CR8  
// Kp 18.76
// Ki 2.23
// Kd 39.47
//
//原固件参数
// Kp 22.20
// Ki 1.08
// Kd 114.00
#define DEFAULT_Kp_Key  22.20
#define DEFAULT_Ki_Key   1.08
#define DEFAULT_Kd_Key  114.00

// 热床PID参数
//参考数值
//200热床实测
// Kp 17.04
// Ki 0.30
// Kd 641.99
//150热床实测
// Kp 44.84
// Ki 2.96
// Kd 452.87
//
//原固件参数

// Kp 17.04
// Ki 0.30
// Kd 641.99
#define DEFAULT_bedKp_Key 17.04
#define DEFAULT_bedKi_Key 0.30
#define DEFAULT_bedKd_Key 641.99

// 轴步数（步数/mm）
// 每mm的脉冲数
// X：80
// Y：80
// Z：400
// E：398
#define DEFAULT_AXIS_STEPS_PER_UNIT_X 80
#define DEFAULT_AXIS_STEPS_PER_UNIT_Y 80
#define DEFAULT_AXIS_STEPS_PER_UNIT_Z 400
#define DEFAULT_AXIS_STEPS_PER_UNIT_E 764


// 最大速度（mm/s）
// 每秒钟移动的最大毫米数
// X：300
// Y：300
// Z：5
// E：25
#define DEFAULT_MAX_FEEDRATE_X 300
#define DEFAULT_MAX_FEEDRATE_Y 300
#define DEFAULT_MAX_FEEDRATE_Z 5
#define DEFAULT_MAX_FEEDRATE_E 25

// 最大加速度（mm/s2）
// 每秒钟速度的变化量
// X：3000
// Y：3000
// Z：100
// E：1000
#define DEFAULT_MAX_ACCELERATION_X 3000
#define DEFAULT_MAX_ACCELERATION_Y 3000
#define DEFAULT_MAX_ACCELERATION_Z 100
#define DEFAULT_MAX_ACCELERATION_E 1000

//默认加速度
// X, Y, Z ... 和 E 打印移动的加速度 3000
// 回退的 E 的加速度 3000
// X, Y, Z ... 的移动（非打印）加速度 3000
#define DEFAULT_ACCELERATION_Key          3000
#define DEFAULT_RETRACT_ACCELERATION_Key  3000
#define DEFAULT_TRAVEL_ACCELERATION_Key   3000

// Z探针类型：(Fixed/Bltouch)
// 固定安装的探针
#define Z_Axis_Probe Fixed

// 探针偏移量
//       +-- 后面 ---+
//       |    [+]    |
//     L |        1  | R <-- 示例 "1" (右+,  后+)
//     E |  2        | I <-- 示例 "2" ( 左-,  后+)
//     F |[-]  N  [+]| G <-- 喷嘴
//     T |       3   | H <-- 示例 "3" (右+,  前-)
//       | 4         | T <-- 示例 "4" ( 左-,  前-)
//       |    [-]    |
//       O-- 前面 --+
//{ -30, 0,-2 }
// 探针位于喷嘴左侧30毫米处，在Y轴没有偏移，位于喷嘴下方2毫米处
#define NOZZLE_TO_PROBE_OFFSET_X -30
#define NOZZLE_TO_PROBE_OFFSET_Y 0
#define NOZZLE_TO_PROBE_OFFSET_Z -2

// 电机反向
// X：反向
// Y：反向
// Z：不反向
#define INVERT_X_DIR_Key false
#define INVERT_Y_DIR_Key false
#define INVERT_Z_DIR_Key false

// 打印区域
// X：200
// Y：200
// Z：260
#define Printable_Area_X 145
#define Printable_Area_Y 135
#define Printable_Area_Z 160

// 控制器类型
// REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER
// 说白了就是LCD12864
#define REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER_Key

// 步进电机驱动器类型
//  选项：A4988, A5984, DRV8825, LV8729, TB6560, TB6600, TMC2100,
//           TMC2130, TMC2130_STANDALONE, TMC2160, TMC2160_STANDALONE,
//           TMC2208, TMC2208_STANDALONE, TMC2209, TMC2209_STANDALONE,
//           TMC26X,  TMC26X_STANDALONE,  TMC2660, TMC2660_STANDALONE,
//           TMC5130, TMC5130_STANDALONE, TMC5160, TMC5160_STANDALONE
// X：TMC2209
// Y：TMC2209
// Z：TMC2209
// E：TMC2209
#define X_DRIVER_TYPE_KEY A4988
#define Y_DRIVER_TYPE_KEY A4988
#define Z_DRIVER_TYPE_KEY A4988
#define E_DRIVER_TYPE_KEY A4988

//反转LCD屏幕编码器方向（true/false）
#define REVERSE_ENCODER_DIRECTION_key true

//断料检测（true/false）
//开启耗材断料传感器
#define FILAMENT_RUNOUT_SENSOR_Key true

//用Z Probe Stop替换ZMIN STOP（true/false）
#define Z_Probe_Stop_Replace_ZMIN_STOP false

//热床多次探测
//每个点的探测次数
//总共探测3次
#define Number_Of_Probes_Per_Point 3
//每个点的探测次数
//总共探测3次
#define Number_Of_Probes_Per_Point 3

//防止温度传感器失效
//如果挤出头在 E_Heating_Waiting_Time 秒内，温度没有上升 E_Temperature_Rise_During_Heating_Wait_Time 摄氏度，就意味着温度传感器失效。
//打印机将会停止工作，直到被重置。
#define E_Heating_Waiting_Time 40           //秒
#define E_Temperature_Rise_During_Heating_Wait_Time 1          //摄氏度
//如果热床在 BED_Heating_Waiting_Time 秒内，温度没有上升 BED_Temperature_Rise_During_Heating_Wait_Time 摄氏度，就意味着温度传感器失效。
//打印机将会停止工作，直到被重置。
#define BED_Heating_Waiting_Time 40           //秒
#define BED_Temperature_Rise_During_Heating_Wait_Time 1          //摄氏度

#endif

//————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#if Equipment_Number == 007

// 007
// 挤出头PID参数
//参考数值：
//K5A CR8 12V 40W
// Kp  25.81
// Ki   2.71
// Kd  61.56
//K5B E3D 12V 40W
// Kp  26.23
// Ki   2.82
// kd  60.99
//K5 15V 12V30W  CR8  
// Kp 18.76
// Ki 2.23
// Kd 39.47
//
//原固件参数
// Kp 22.20
// Ki 1.08
// Kd 114.00
#define DEFAULT_Kp_Key  22.20
#define DEFAULT_Ki_Key   1.08
#define DEFAULT_Kd_Key  114.00

// 热床PID参数
//参考数值
//200热床实测
// Kp 17.04
// Ki 0.30
// Kd 641.99
//150热床实测
// Kp 44.84
// Ki 2.96
// Kd 452.87
//
//原固件参数

// Kp 17.04
// Ki 0.30
// Kd 641.99
#define DEFAULT_bedKp_Key 17.04
#define DEFAULT_bedKi_Key 0.30
#define DEFAULT_bedKd_Key 641.99

// 轴步数（步数/mm）
// 每mm的脉冲数
// X：80
// Y：80
// Z：400
// E：398
#define DEFAULT_AXIS_STEPS_PER_UNIT_X 80
#define DEFAULT_AXIS_STEPS_PER_UNIT_Y 80
#define DEFAULT_AXIS_STEPS_PER_UNIT_Z 400
#define DEFAULT_AXIS_STEPS_PER_UNIT_E 764


// 最大速度（mm/s）
// 每秒钟移动的最大毫米数
// X：300
// Y：300
// Z：5
// E：25
#define DEFAULT_MAX_FEEDRATE_X 300
#define DEFAULT_MAX_FEEDRATE_Y 300
#define DEFAULT_MAX_FEEDRATE_Z 5
#define DEFAULT_MAX_FEEDRATE_E 25

// 最大加速度（mm/s2）
// 每秒钟速度的变化量
// X：3000
// Y：3000
// Z：100
// E：1000
#define DEFAULT_MAX_ACCELERATION_X 3000
#define DEFAULT_MAX_ACCELERATION_Y 3000
#define DEFAULT_MAX_ACCELERATION_Z 100
#define DEFAULT_MAX_ACCELERATION_E 1000

//默认加速度
// X, Y, Z ... 和 E 打印移动的加速度 3000
// 回退的 E 的加速度 3000
// X, Y, Z ... 的移动（非打印）加速度 3000
#define DEFAULT_ACCELERATION_Key          3000
#define DEFAULT_RETRACT_ACCELERATION_Key  3000
#define DEFAULT_TRAVEL_ACCELERATION_Key   3000

// Z探针类型：(Fixed/Bltouch)
// 固定安装的探针
#define Z_Axis_Probe Fixed

// 探针偏移量
//       +-- 后面 ---+
//       |    [+]    |
//     L |        1  | R <-- 示例 "1" (右+,  后+)
//     E |  2        | I <-- 示例 "2" ( 左-,  后+)
//     F |[-]  N  [+]| G <-- 喷嘴
//     T |       3   | H <-- 示例 "3" (右+,  前-)
//       | 4         | T <-- 示例 "4" ( 左-,  前-)
//       |    [-]    |
//       O-- 前面 --+
//{ -30, 0,-2 }
// 探针位于喷嘴左侧30毫米处，在Y轴没有偏移，位于喷嘴下方2毫米处
#define NOZZLE_TO_PROBE_OFFSET_X -30
#define NOZZLE_TO_PROBE_OFFSET_Y 0
#define NOZZLE_TO_PROBE_OFFSET_Z -2

// 电机反向
// X：反向
// Y：反向
// Z：不反向
#define INVERT_X_DIR_Key false
#define INVERT_Y_DIR_Key false
#define INVERT_Z_DIR_Key false

// 打印区域
// X：200
// Y：200
// Z：260
#define Printable_Area_X 145
#define Printable_Area_Y 135
#define Printable_Area_Z 160

// 控制器类型
// REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER
// 说白了就是LCD12864
#define REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER_Key

// 步进电机驱动器类型
//  选项：A4988, A5984, DRV8825, LV8729, TB6560, TB6600, TMC2100,
//           TMC2130, TMC2130_STANDALONE, TMC2160, TMC2160_STANDALONE,
//           TMC2208, TMC2208_STANDALONE, TMC2209, TMC2209_STANDALONE,
//           TMC26X,  TMC26X_STANDALONE,  TMC2660, TMC2660_STANDALONE,
//           TMC5130, TMC5130_STANDALONE, TMC5160, TMC5160_STANDALONE
// X：TMC2209
// Y：TMC2209
// Z：TMC2209
// E：TMC2209
#define X_DRIVER_TYPE_KEY A4988
#define Y_DRIVER_TYPE_KEY A4988
#define Z_DRIVER_TYPE_KEY A4988
#define E_DRIVER_TYPE_KEY A4988

//反转LCD屏幕编码器方向（true/false）
#define REVERSE_ENCODER_DIRECTION_key true

//断料检测（true/false）
//开启耗材断料传感器
#define FILAMENT_RUNOUT_SENSOR_Key true

//用Z Probe Stop替换ZMIN STOP（true/false）
#define Z_Probe_Stop_Replace_ZMIN_STOP false

//热床多次探测
//每个点的探测次数
//总共探测3次
#define Number_Of_Probes_Per_Point 3
//每个点的探测次数
//总共探测3次
#define Number_Of_Probes_Per_Point 3

//防止温度传感器失效
//如果挤出头在 E_Heating_Waiting_Time 秒内，温度没有上升 E_Temperature_Rise_During_Heating_Wait_Time 摄氏度，就意味着温度传感器失效。
//打印机将会停止工作，直到被重置。
#define E_Heating_Waiting_Time 40           //秒
#define E_Temperature_Rise_During_Heating_Wait_Time 1          //摄氏度
//如果热床在 BED_Heating_Waiting_Time 秒内，温度没有上升 BED_Temperature_Rise_During_Heating_Wait_Time 摄氏度，就意味着温度传感器失效。
//打印机将会停止工作，直到被重置。
#define BED_Heating_Waiting_Time 40           //秒
#define BED_Temperature_Rise_During_Heating_Wait_Time 1          //摄氏度

#endif

//————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#if Equipment_Number == 010

// 010
// 挤出头PID参数
//参考数值：
//K5A CR8 12V 40W
// Kp  25.81
// Ki   2.71
// Kd  61.56
//K5B E3D 12V 40W
// Kp  26.23
// Ki   2.82
// kd  60.99
//K5 15V 12V30W  CR8  
// Kp 18.76
// Ki 2.23
// Kd 39.47
//
//原固件参数
// Kp 22.20
// Ki 1.08
// Kd 114.00
#define DEFAULT_Kp_Key  22.20
#define DEFAULT_Ki_Key   1.08
#define DEFAULT_Kd_Key  114.00

// 热床PID参数
//参考数值
//200热床实测
// Kp 17.04
// Ki 0.30
// Kd 641.99
//150热床实测
// Kp 44.84
// Ki 2.96
// Kd 452.87
//
//原固件参数

// Kp 17.04
// Ki 0.30
// Kd 641.99
#define DEFAULT_bedKp_Key 17.04
#define DEFAULT_bedKi_Key 0.30
#define DEFAULT_bedKd_Key 641.99

// 轴步数（步数/mm）
// 每mm的脉冲数
// X：80
// Y：80
// Z：400
// E：398
#define DEFAULT_AXIS_STEPS_PER_UNIT_X 80
#define DEFAULT_AXIS_STEPS_PER_UNIT_Y 80
#define DEFAULT_AXIS_STEPS_PER_UNIT_Z 400
#define DEFAULT_AXIS_STEPS_PER_UNIT_E 764


// 最大速度（mm/s）
// 每秒钟移动的最大毫米数
// X：300
// Y：300
// Z：5
// E：25
#define DEFAULT_MAX_FEEDRATE_X 300
#define DEFAULT_MAX_FEEDRATE_Y 300
#define DEFAULT_MAX_FEEDRATE_Z 5
#define DEFAULT_MAX_FEEDRATE_E 25

// 最大加速度（mm/s2）
// 每秒钟速度的变化量
// X：3000
// Y：3000
// Z：100
// E：1000
#define DEFAULT_MAX_ACCELERATION_X 3000
#define DEFAULT_MAX_ACCELERATION_Y 3000
#define DEFAULT_MAX_ACCELERATION_Z 100
#define DEFAULT_MAX_ACCELERATION_E 1000

//默认加速度
// X, Y, Z ... 和 E 打印移动的加速度 3000
// 回退的 E 的加速度 3000
// X, Y, Z ... 的移动（非打印）加速度 3000
#define DEFAULT_ACCELERATION_Key          3000
#define DEFAULT_RETRACT_ACCELERATION_Key  3000
#define DEFAULT_TRAVEL_ACCELERATION_Key   3000

// Z探针类型：(Fixed/Bltouch)
// 固定安装的探针
#define Z_Axis_Probe Fixed

// 探针偏移量
//       +-- 后面 ---+
//       |    [+]    |
//     L |        1  | R <-- 示例 "1" (右+,  后+)
//     E |  2        | I <-- 示例 "2" ( 左-,  后+)
//     F |[-]  N  [+]| G <-- 喷嘴
//     T |       3   | H <-- 示例 "3" (右+,  前-)
//       | 4         | T <-- 示例 "4" ( 左-,  前-)
//       |    [-]    |
//       O-- 前面 --+
//{ -30, 0,-2 }
// 探针位于喷嘴左侧30毫米处，在Y轴没有偏移，位于喷嘴下方2毫米处
#define NOZZLE_TO_PROBE_OFFSET_X -30
#define NOZZLE_TO_PROBE_OFFSET_Y 0
#define NOZZLE_TO_PROBE_OFFSET_Z -2

// 电机反向
// X：反向
// Y：反向
// Z：不反向
#define INVERT_X_DIR_Key false
#define INVERT_Y_DIR_Key false
#define INVERT_Z_DIR_Key false

// 打印区域
// X：200
// Y：200
// Z：260
#define Printable_Area_X 145
#define Printable_Area_Y 135
#define Printable_Area_Z 160

// 控制器类型
// REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER
// 说白了就是LCD12864
#define REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER_Key

// 步进电机驱动器类型
//  选项：A4988, A5984, DRV8825, LV8729, TB6560, TB6600, TMC2100,
//           TMC2130, TMC2130_STANDALONE, TMC2160, TMC2160_STANDALONE,
//           TMC2208, TMC2208_STANDALONE, TMC2209, TMC2209_STANDALONE,
//           TMC26X,  TMC26X_STANDALONE,  TMC2660, TMC2660_STANDALONE,
//           TMC5130, TMC5130_STANDALONE, TMC5160, TMC5160_STANDALONE
// X：TMC2209
// Y：TMC2209
// Z：TMC2209
// E：TMC2209
#define X_DRIVER_TYPE_KEY A4988
#define Y_DRIVER_TYPE_KEY A4988
#define Z_DRIVER_TYPE_KEY A4988
#define E_DRIVER_TYPE_KEY A4988

//反转LCD屏幕编码器方向（true/false）
#define REVERSE_ENCODER_DIRECTION_key true

//断料检测（true/false）
//开启耗材断料传感器
#define FILAMENT_RUNOUT_SENSOR_Key true

//用Z Probe Stop替换ZMIN STOP（true/false）
#define Z_Probe_Stop_Replace_ZMIN_STOP false

//热床多次探测
//每个点的探测次数
//总共探测3次
#define Number_Of_Probes_Per_Point 3
//每个点的探测次数
//总共探测3次
#define Number_Of_Probes_Per_Point 3

//防止温度传感器失效
//如果挤出头在 E_Heating_Waiting_Time 秒内，温度没有上升 E_Temperature_Rise_During_Heating_Wait_Time 摄氏度，就意味着温度传感器失效。
//打印机将会停止工作，直到被重置。
#define E_Heating_Waiting_Time 40           //秒
#define E_Temperature_Rise_During_Heating_Wait_Time 1          //摄氏度
//如果热床在 BED_Heating_Waiting_Time 秒内，温度没有上升 BED_Temperature_Rise_During_Heating_Wait_Time 摄氏度，就意味着温度传感器失效。
//打印机将会停止工作，直到被重置。
#define BED_Heating_Waiting_Time 40           //秒
#define BED_Temperature_Rise_During_Heating_Wait_Time 1          //摄氏度

#endif

//————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#if Equipment_Number == 011

// 011
// 挤出头PID参数
//参考数值：
//K5A CR8 12V 40W
// Kp  25.81
// Ki   2.71
// Kd  61.56
//K5B E3D 12V 40W
// Kp  26.23
// Ki   2.82
// kd  60.99
//K5 15V 12V30W  CR8  
// Kp 18.76
// Ki 2.23
// Kd 39.47
//
//原固件参数
// Kp 22.20
// Ki 1.08
// Kd 114.00
#define DEFAULT_Kp_Key  22.20
#define DEFAULT_Ki_Key   1.08
#define DEFAULT_Kd_Key  114.00

// 热床PID参数
//参考数值
//200热床实测
// Kp 17.04
// Ki 0.30
// Kd 641.99
//150热床实测
// Kp 44.84
// Ki 2.96
// Kd 452.87
//
//原固件参数

// Kp 17.04
// Ki 0.30
// Kd 641.99
#define DEFAULT_bedKp_Key 17.04
#define DEFAULT_bedKi_Key 0.30
#define DEFAULT_bedKd_Key 641.99

// 轴步数（步数/mm）
// 每mm的脉冲数
// X：80
// Y：80
// Z：400
// E：398
#define DEFAULT_AXIS_STEPS_PER_UNIT_X 80
#define DEFAULT_AXIS_STEPS_PER_UNIT_Y 80
#define DEFAULT_AXIS_STEPS_PER_UNIT_Z 400
#define DEFAULT_AXIS_STEPS_PER_UNIT_E 764


// 最大速度（mm/s）
// 每秒钟移动的最大毫米数
// X：300
// Y：300
// Z：5
// E：25
#define DEFAULT_MAX_FEEDRATE_X 300
#define DEFAULT_MAX_FEEDRATE_Y 300
#define DEFAULT_MAX_FEEDRATE_Z 5
#define DEFAULT_MAX_FEEDRATE_E 25

// 最大加速度（mm/s2）
// 每秒钟速度的变化量
// X：3000
// Y：3000
// Z：100
// E：1000
#define DEFAULT_MAX_ACCELERATION_X 3000
#define DEFAULT_MAX_ACCELERATION_Y 3000
#define DEFAULT_MAX_ACCELERATION_Z 100
#define DEFAULT_MAX_ACCELERATION_E 1000

//默认加速度
// X, Y, Z ... 和 E 打印移动的加速度 3000
// 回退的 E 的加速度 3000
// X, Y, Z ... 的移动（非打印）加速度 3000
#define DEFAULT_ACCELERATION_Key          3000
#define DEFAULT_RETRACT_ACCELERATION_Key  3000
#define DEFAULT_TRAVEL_ACCELERATION_Key   3000

// Z探针类型：(Fixed/Bltouch)
// 固定安装的探针
#define Z_Axis_Probe Fixed

// 探针偏移量
//       +-- 后面 ---+
//       |    [+]    |
//     L |        1  | R <-- 示例 "1" (右+,  后+)
//     E |  2        | I <-- 示例 "2" ( 左-,  后+)
//     F |[-]  N  [+]| G <-- 喷嘴
//     T |       3   | H <-- 示例 "3" (右+,  前-)
//       | 4         | T <-- 示例 "4" ( 左-,  前-)
//       |    [-]    |
//       O-- 前面 --+
//{ -30, 0,-2 }
// 探针位于喷嘴左侧30毫米处，在Y轴没有偏移，位于喷嘴下方2毫米处
#define NOZZLE_TO_PROBE_OFFSET_X -30
#define NOZZLE_TO_PROBE_OFFSET_Y 0
#define NOZZLE_TO_PROBE_OFFSET_Z -2

// 电机反向
// X：反向
// Y：反向
// Z：不反向
#define INVERT_X_DIR_Key false
#define INVERT_Y_DIR_Key false
#define INVERT_Z_DIR_Key false

// 打印区域
// X：200
// Y：200
// Z：260
#define Printable_Area_X 145
#define Printable_Area_Y 135
#define Printable_Area_Z 160

// 控制器类型
// REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER
// 说白了就是LCD12864
#define REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER_Key

// 步进电机驱动器类型
//  选项：A4988, A5984, DRV8825, LV8729, TB6560, TB6600, TMC2100,
//           TMC2130, TMC2130_STANDALONE, TMC2160, TMC2160_STANDALONE,
//           TMC2208, TMC2208_STANDALONE, TMC2209, TMC2209_STANDALONE,
//           TMC26X,  TMC26X_STANDALONE,  TMC2660, TMC2660_STANDALONE,
//           TMC5130, TMC5130_STANDALONE, TMC5160, TMC5160_STANDALONE
// X：TMC2209
// Y：TMC2209
// Z：TMC2209
// E：TMC2209
#define X_DRIVER_TYPE_KEY A4988
#define Y_DRIVER_TYPE_KEY A4988
#define Z_DRIVER_TYPE_KEY A4988
#define E_DRIVER_TYPE_KEY A4988

//反转LCD屏幕编码器方向（true/false）
#define REVERSE_ENCODER_DIRECTION_key true

//断料检测（true/false）
//开启耗材断料传感器
#define FILAMENT_RUNOUT_SENSOR_Key true

//用Z Probe Stop替换ZMIN STOP（true/false）
#define Z_Probe_Stop_Replace_ZMIN_STOP false

//热床多次探测
//每个点的探测次数
//总共探测3次
#define Number_Of_Probes_Per_Point 3
//每个点的探测次数
//总共探测3次
#define Number_Of_Probes_Per_Point 3

//防止温度传感器失效
//如果挤出头在 E_Heating_Waiting_Time 秒内，温度没有上升 E_Temperature_Rise_During_Heating_Wait_Time 摄氏度，就意味着温度传感器失效。
//打印机将会停止工作，直到被重置。
#define E_Heating_Waiting_Time 40           //秒
#define E_Temperature_Rise_During_Heating_Wait_Time 1          //摄氏度
//如果热床在 BED_Heating_Waiting_Time 秒内，温度没有上升 BED_Temperature_Rise_During_Heating_Wait_Time 摄氏度，就意味着温度传感器失效。
//打印机将会停止工作，直到被重置。
#define BED_Heating_Waiting_Time 40           //秒
#define BED_Temperature_Rise_During_Heating_Wait_Time 1          //摄氏度

#endif

//————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#if Equipment_Number == 012

// 012
// 挤出头PID参数
//参考数值：
//K5A CR8 12V 40W
// Kp  25.81
// Ki   2.71
// Kd  61.56
//K5B E3D 12V 40W
// Kp  26.23
// Ki   2.82
// kd  60.99
//K5 15V 12V30W  CR8  
// Kp 18.76
// Ki 2.23
// Kd 39.47
//
//原固件参数
// Kp 22.20
// Ki 1.08
// Kd 114.00
#define DEFAULT_Kp_Key  22.20
#define DEFAULT_Ki_Key   1.08
#define DEFAULT_Kd_Key  114.00

// 热床PID参数
//参考数值
//200热床实测
// Kp 17.04
// Ki 0.30
// Kd 641.99
//150热床实测
// Kp 44.84
// Ki 2.96
// Kd 452.87
//
//原固件参数

// Kp 17.04
// Ki 0.30
// Kd 641.99
#define DEFAULT_bedKp_Key 17.04
#define DEFAULT_bedKi_Key 0.30
#define DEFAULT_bedKd_Key 641.99

// 轴步数（步数/mm）
// 每mm的脉冲数
// X：80
// Y：80
// Z：400
// E：398
#define DEFAULT_AXIS_STEPS_PER_UNIT_X 80
#define DEFAULT_AXIS_STEPS_PER_UNIT_Y 80
#define DEFAULT_AXIS_STEPS_PER_UNIT_Z 400
#define DEFAULT_AXIS_STEPS_PER_UNIT_E 764


// 最大速度（mm/s）
// 每秒钟移动的最大毫米数
// X：300
// Y：300
// Z：5
// E：25
#define DEFAULT_MAX_FEEDRATE_X 300
#define DEFAULT_MAX_FEEDRATE_Y 300
#define DEFAULT_MAX_FEEDRATE_Z 5
#define DEFAULT_MAX_FEEDRATE_E 25

// 最大加速度（mm/s2）
// 每秒钟速度的变化量
// X：3000
// Y：3000
// Z：100
// E：1000
#define DEFAULT_MAX_ACCELERATION_X 3000
#define DEFAULT_MAX_ACCELERATION_Y 3000
#define DEFAULT_MAX_ACCELERATION_Z 100
#define DEFAULT_MAX_ACCELERATION_E 1000

//默认加速度
// X, Y, Z ... 和 E 打印移动的加速度 3000
// 回退的 E 的加速度 3000
// X, Y, Z ... 的移动（非打印）加速度 3000
#define DEFAULT_ACCELERATION_Key          3000
#define DEFAULT_RETRACT_ACCELERATION_Key  3000
#define DEFAULT_TRAVEL_ACCELERATION_Key   3000

// Z探针类型：(Fixed/Bltouch)
// 固定安装的探针
#define Z_Axis_Probe Fixed

// 探针偏移量
//       +-- 后面 ---+
//       |    [+]    |
//     L |        1  | R <-- 示例 "1" (右+,  后+)
//     E |  2        | I <-- 示例 "2" ( 左-,  后+)
//     F |[-]  N  [+]| G <-- 喷嘴
//     T |       3   | H <-- 示例 "3" (右+,  前-)
//       | 4         | T <-- 示例 "4" ( 左-,  前-)
//       |    [-]    |
//       O-- 前面 --+
//{ -30, 0,-2 }
// 探针位于喷嘴左侧30毫米处，在Y轴没有偏移，位于喷嘴下方2毫米处
#define NOZZLE_TO_PROBE_OFFSET_X -30
#define NOZZLE_TO_PROBE_OFFSET_Y 0
#define NOZZLE_TO_PROBE_OFFSET_Z -2

// 电机反向
// X：反向
// Y：反向
// Z：不反向
#define INVERT_X_DIR_Key false
#define INVERT_Y_DIR_Key false
#define INVERT_Z_DIR_Key false

// 打印区域
// X：200
// Y：200
// Z：260
#define Printable_Area_X 145
#define Printable_Area_Y 135
#define Printable_Area_Z 160

// 控制器类型
// REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER
// 说白了就是LCD12864
#define REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER_Key

// 步进电机驱动器类型
//  选项：A4988, A5984, DRV8825, LV8729, TB6560, TB6600, TMC2100,
//           TMC2130, TMC2130_STANDALONE, TMC2160, TMC2160_STANDALONE,
//           TMC2208, TMC2208_STANDALONE, TMC2209, TMC2209_STANDALONE,
//           TMC26X,  TMC26X_STANDALONE,  TMC2660, TMC2660_STANDALONE,
//           TMC5130, TMC5130_STANDALONE, TMC5160, TMC5160_STANDALONE
// X：TMC2209
// Y：TMC2209
// Z：TMC2209
// E：TMC2209
#define X_DRIVER_TYPE_KEY A4988
#define Y_DRIVER_TYPE_KEY A4988
#define Z_DRIVER_TYPE_KEY A4988
#define E_DRIVER_TYPE_KEY A4988

//反转LCD屏幕编码器方向（true/false）
#define REVERSE_ENCODER_DIRECTION_key true

//断料检测（true/false）
//开启耗材断料传感器
#define FILAMENT_RUNOUT_SENSOR_Key true

//用Z Probe Stop替换ZMIN STOP（true/false）
#define Z_Probe_Stop_Replace_ZMIN_STOP false

//热床多次探测
//每个点的探测次数
//总共探测3次
#define Number_Of_Probes_Per_Point 3
//每个点的探测次数
//总共探测3次
#define Number_Of_Probes_Per_Point 3

//防止温度传感器失效
//如果挤出头在 E_Heating_Waiting_Time 秒内，温度没有上升 E_Temperature_Rise_During_Heating_Wait_Time 摄氏度，就意味着温度传感器失效。
//打印机将会停止工作，直到被重置。
#define E_Heating_Waiting_Time 40           //秒
#define E_Temperature_Rise_During_Heating_Wait_Time 1          //摄氏度
//如果热床在 BED_Heating_Waiting_Time 秒内，温度没有上升 BED_Temperature_Rise_During_Heating_Wait_Time 摄氏度，就意味着温度传感器失效。
//打印机将会停止工作，直到被重置。
#define BED_Heating_Waiting_Time 40           //秒
#define BED_Temperature_Rise_During_Heating_Wait_Time 1          //摄氏度

#endif

//————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#if Equipment_Number == 777

// -001
// 挤出头PID参数
//参考数值：
//K5A CR8 12V 40W
// Kp  25.81
// Ki   2.71
// Kd  61.56
//K5B E3D 12V 40W
// Kp  26.23
// Ki   2.82
// kd  60.99
//K5 15V 12V30W  CR8  
// Kp 18.76
// Ki 2.23
// Kd 39.47
//
//原固件参数
// Kp 16.25
// Ki 1.06
// Kd 62.42
#define DEFAULT_Kp_Key  16.25
#define DEFAULT_Ki_Key   1.06
#define DEFAULT_Kd_Key  62.42

// 热床PID参数
//参考数值
//200热床实测
// Kp 17.04
// Ki 0.30
// Kd 641.99
//150热床实测
// Kp 44.84
// Ki 2.96
// Kd 452.87
//
//原固件参数
// Kp 34.0
// Ki 6.25
// Kd 140.2
#define DEFAULT_bedKp_Key 34.0
#define DEFAULT_bedKi_Key 6.25
#define DEFAULT_bedKd_Key 140.2

// 轴步数（步数/mm）
// 每mm的脉冲数
// X：80
// Y：80
// Z：400
// E：382.161
#define DEFAULT_AXIS_STEPS_PER_UNIT_X 80
#define DEFAULT_AXIS_STEPS_PER_UNIT_Y 80
#define DEFAULT_AXIS_STEPS_PER_UNIT_Z 400
#define DEFAULT_AXIS_STEPS_PER_UNIT_E 382.161


// 最大速度（mm/s）
// 每秒钟移动的最大毫米数
// X：300
// Y：300
// Z：5
// E：25
#define DEFAULT_MAX_FEEDRATE_X 300
#define DEFAULT_MAX_FEEDRATE_Y 300
#define DEFAULT_MAX_FEEDRATE_Z 5
#define DEFAULT_MAX_FEEDRATE_E 25

// 最大加速度（mm/s2）
// 每秒钟速度的变化量
// X：3000
// Y：3000
// Z：100
// E：1000
#define DEFAULT_MAX_ACCELERATION_X 500
#define DEFAULT_MAX_ACCELERATION_Y 500
#define DEFAULT_MAX_ACCELERATION_Z 100
#define DEFAULT_MAX_ACCELERATION_E 1000

//默认加速度
// X, Y, Z ... 和 E 打印移动的加速度 3000
// 回退的 E 的加速度 3000
// X, Y, Z ... 的移动（非打印）加速度 3000
#define DEFAULT_ACCELERATION_Key          500
#define DEFAULT_RETRACT_ACCELERATION_Key  500
#define DEFAULT_TRAVEL_ACCELERATION_Key   500

// Z探针类型：(Fixed/Bltouch)
// 固定安装的探针
#define Z_Axis_Probe Bltouch

// 探针偏移量
//       +-- 后面 ---+
//       |    [+]    |
//     L |        1  | R <-- 示例 "1" (右+,  后+)
//     E |  2        | I <-- 示例 "2" ( 左-,  后+)
//     F |[-]  N  [+]| G <-- 喷嘴
//     T |       3   | H <-- 示例 "3" (右+,  前-)
//       | 4         | T <-- 示例 "4" ( 左-,  前-)
//       |    [-]    |
//       O-- 前面 --+
//{ -30, 0,-2 }
// 探针位于喷嘴左侧30毫米处，在Y轴没有偏移，位于喷嘴下方2毫米处
#define NOZZLE_TO_PROBE_OFFSET_X -30
#define NOZZLE_TO_PROBE_OFFSET_Y 0
#define NOZZLE_TO_PROBE_OFFSET_Z 0

// 电机反向
// X：反向
// Y：不反向
// Z：不反向
#define INVERT_X_DIR_Key true
#define INVERT_Y_DIR_Key false
#define INVERT_Z_DIR_Key false

// 打印区域
// X：170
// Y：180
// Z：130
#define Printable_Area_X 170
#define Printable_Area_Y 180
#define Printable_Area_Z 130

// 控制器类型
// REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER
// 说白了就是LCD12864
#define REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER_Key

// 步进电机驱动器类型
//  选项：A4988, A5984, DRV8825, LV8729, TB6560, TB6600, TMC2100,
//           TMC2130, TMC2130_STANDALONE, TMC2160, TMC2160_STANDALONE,
//           TMC2208, TMC2208_STANDALONE, TMC2209, TMC2209_STANDALONE,
//           TMC26X,  TMC26X_STANDALONE,  TMC2660, TMC2660_STANDALONE,
//           TMC5130, TMC5130_STANDALONE, TMC5160, TMC5160_STANDALONE
// X：TMC2209
// Y：TMC2209
// Z：TMC2209
// E：TMC2209
#define X_DRIVER_TYPE_KEY A4988
#define Y_DRIVER_TYPE_KEY A4988
#define Z_DRIVER_TYPE_KEY A4988
#define E_DRIVER_TYPE_KEY A4988

//反转LCD屏幕编码器方向（true/false）
#define REVERSE_ENCODER_DIRECTION_key false

//断料检测（true/false）
//开启耗材断料传感器
#define FILAMENT_RUNOUT_SENSOR_Key true

//用Z Probe Stop替换ZMIN STOP（true/false）
#define Z_Probe_Stop_Replace_ZMIN_STOP false

//热床多次探测
//每个点的探测次数
//总共探测3次
#define Number_Of_Probes_Per_Point 3
//每个点的探测次数
//总共探测3次
#define Number_Of_Probes_Per_Point 3

//防止温度传感器失效
//如果挤出头在 E_Heating_Waiting_Time 秒内，温度没有上升 E_Temperature_Rise_During_Heating_Wait_Time 摄氏度，就意味着温度传感器失效。
//打印机将会停止工作，直到被重置。
#define E_Heating_Waiting_Time 40           //秒
#define E_Temperature_Rise_During_Heating_Wait_Time 1          //摄氏度
//如果热床在 BED_Heating_Waiting_Time 秒内，温度没有上升 BED_Temperature_Rise_During_Heating_Wait_Time 摄氏度，就意味着温度传感器失效。
//打印机将会停止工作，直到被重置。
#define BED_Heating_Waiting_Time 40           //秒
#define BED_Temperature_Rise_During_Heating_Wait_Time 1          //摄氏度

#endif

//————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

//代码修正
//确保探针类型能被正常定义


//确保探针设置正确
#ifdef Z_Axis_Probe
    #if (Z_Axis_Probe != Fixed && Z_Axis_Probe != Bltouch)
        #error "Z_Axis_Probe设置有误"
        #undef Z_Axis_Probe
    #endif
#endif

//确定电机方向的正确性
#if defined(INVERT_X_DIR_Key)
   #if INVERT_X_DIR_Key != true && INVERT_X_DIR_Key != false
   #error "INVERT_X_DIR_Key 必须是布尔值。"
   #endif
#endif
#if defined(INVERT_Y_DIR_Key)
    #if INVERT_Y_DIR_Key != true && INVERT_Y_DIR_Key != false
    #error "INVERT_Y_DIR_Key 必须是布尔值。"
    #endif
#endif
#if defined(INVERT_Z_DIR_Key)
    #if INVERT_Z_DIR_Key != true && INVERT_Z_DIR_Key != false
    #error "INVERT_Z_DIR_Key 必须是布尔值。"
    #endif
#endif

//检查LCD反转的正确性
#if  defined(REVERSE_ENCODER_DIRECTION_key)
    #if REVERSE_ENCODER_DIRECTION_key != true && REVERSE_ENCODER_DIRECTION_key != false
    #error "REVERSE_ENCODER_DIRECTION_key 必须是布尔值。"
    #endif
#endif

//确定耗材传感器的正确性
#if defined(FILAMENT_RUNOUT_SENSOR_Key)
    #if FILAMENT_RUNOUT_SENSOR_Key != true && FILAMENT_RUNOUT_SENSOR_Key != false
    #error "FILAMENT_RUNOUT_SENSOR_Key 必须是布尔值。"
    #endif
#endif

//确定用Z_Probe_Stop替换ZMIN_STOP的正确性
#if defined(Z_Probe_Stop_Replace_ZMIN_STOP)
    #if Z_Probe_Stop_Replace_ZMIN_STOP !=true && Z_Probe_Stop_Replace_ZMIN_STOP != false
    #error "Z_Probe_Stop_Replace_ZMIN_STOP 必须是布尔值。"
    #endif
#endif

//确保多重探测
#if defined(The_Number_Of_Data_That_Is_Allowed_To_Be_Discarded) && defined(Number_Of_Probes_Per_Point)
// 两个宏都被定义
#elif !defined(The_Number_Of_Data_That_Is_Allowed_To_Be_Discarded) && !defined(Number_Of_Probes_Per_Point)
// 两个宏都未被定义
#else
#error "\"The_Number_Of_Data_That_Is_Allowed_To_Be_Discarded\" 和 \"Number_Of_Probes_Per_Point\" 都需要同时被定义或者同时不被定义"
#endif

//确保挤出头热保护设置的正确性
#if defined(E_Heating_Waiting_Time) && defined(E_Temperature_Rise_During_Heating_Wait_Time)
// 两个宏都被定义
#elif !defined(E_Heating_Waiting_Time) && !defined(E_Temperature_Rise_During_Heating_Wait_Time)
// 两个宏都未被定义
#else
#error "\"E_Heating_Waiting_Time\" 和 \"E_Temperature_Rise_During_Heating_Wait_Time\" 都需要同时被定义或者同时不被定义"
#endif

//确保热床热保护设置的正确性
#if defined(BED_Heating_Waiting_Time) && defined(BED_Temperature_Rise_During_Heating_Wait_Time)
// 两个宏都被定义
#elif !defined(BED_Heating_Waiting_Time) && !defined(BED_Temperature_Rise_During_Heating_Wait_Time)
// 两个宏都未被定义
#else
#error "\"BED_Heating_Waiting_Time\" 和 \"BED_Temperature_Rise_During_Heating_Wait_Time\" 都需要同时被定义或者同时不被定义"
#endif

// 检查默认PID参数是否大于0
#if DEFAULT_Kp_Key <= 0
#error "DEFAULT_Kp_Key 必须大于0"
#endif

#if DEFAULT_Ki_Key <= 0
#error "DEFAULT_Ki_Key 必须大于0"
#endif

#if DEFAULT_Kd_Key <= 0
#error "DEFAULT_Kd_Key 必须大于0"
#endif

// 检查热床PID参数是否大于0
#if DEFAULT_bedKp_Key <= 0
#error "DEFAULT_bedKp_Key 必须大于0"
#endif

#if DEFAULT_bedKi_Key <= 0
#error "DEFAULT_bedKi_Key 必须大于0"

#endif

#if DEFAULT_bedKd_Key <= 0
#error "DEFAULT_bedKd_Key 必须大于0"
#endif

// 检查步进电机驱动器类型是否在可选范围内

#if X_DRIVER_TYPE_KEY != A4988 && X_DRIVER_TYPE_KEY != A5984 && X_DRIVER_TYPE_KEY != DRV8825 && X_DRIVER_TYPE_KEY != LV8729 && X_DRIVER_TYPE_KEY != TB6560 && X_DRIVER_TYPE_KEY != TB6600 && X_DRIVER_TYPE_KEY != TMC2100 && X_DRIVER_TYPE_KEY != TMC2130 && X_DRIVER_TYPE_KEY != TMC2130_STANDALONE && X_DRIVER_TYPE_KEY != TMC2160 && X_DRIVER_TYPE_KEY != TMC2160_STANDALONE && X_DRIVER_TYPE_KEY != TMC2208 && X_DRIVER_TYPE_KEY != TMC2208_STANDALONE && X_DRIVER_TYPE_KEY != TMC2209 && X_DRIVER_TYPE_KEY != TMC2209_STANDALONE && X_DRIVER_TYPE_KEY != TMC26X && X_DRIVER_TYPE_KEY != TMC26X_STANDALONE && X_DRIVER_TYPE_KEY != TMC2660 && X_DRIVER_TYPE_KEY != TMC2660_STANDALONE && X_DRIVER_TYPE_KEY != TMC5130 && X_DRIVER_TYPE_KEY != TMC5130_STANDALONE && X_DRIVER_TYPE_KEY != TMC5160 && X_DRIVER_TYPE_KEY != TMC5160_STANDALONE  
    #error "X_DRIVER_TYPE_KEY 必须为以下类型之一:A4988、A5984、DRV8825、LV8729、TB6560、TB6600、TMC2100、TMC2130、TMC2130_STANDALONE、TMC2160、TMC2160_STANDALONE、TMC2208、TMC2208_STANDALONE、TMC2209、TMC2209_STANDALONE、TMC26X、TMC26X_STANDALONE、TMC2660、TMC2660_STANDALONE、TMC5130、TMC5130_STANDALONE、TMC5160、TMC5160_STANDALONE"
#endif

#if Y_DRIVER_TYPE_KEY != A4988 && Y_DRIVER_TYPE_KEY != A5984 && Y_DRIVER_TYPE_KEY != DRV8825 && Y_DRIVER_TYPE_KEY != LV8729 && Y_DRIVER_TYPE_KEY != TB6560 && Y_DRIVER_TYPE_KEY != TB6600 && Y_DRIVER_TYPE_KEY != TMC2100 && Y_DRIVER_TYPE_KEY != TMC2130 && Y_DRIVER_TYPE_KEY != TMC2130_STANDALONE && Y_DRIVER_TYPE_KEY != TMC2160 && Y_DRIVER_TYPE_KEY != TMC2160_STANDALONE && Y_DRIVER_TYPE_KEY != TMC2208 && Y_DRIVER_TYPE_KEY != TMC2208_STANDALONE && Y_DRIVER_TYPE_KEY != TMC2209 && Y_DRIVER_TYPE_KEY != TMC2209_STANDALONE && Y_DRIVER_TYPE_KEY != TMC26X && Y_DRIVER_TYPE_KEY != TMC26X_STANDALONE && Y_DRIVER_TYPE_KEY != TMC2660 && Y_DRIVER_TYPE_KEY != TMC2660_STANDALONE && Y_DRIVER_TYPE_KEY != TMC5130 && Y_DRIVER_TYPE_KEY != TMC5130_STANDALONE && Y_DRIVER_TYPE_KEY != TMC5160 && Y_DRIVER_TYPE_KEY != TMC5160_STANDALONE
    #error "Y_DRIVER_TYPE_KEY 必须为以下类型之一:A4988、A5984、DRV8825、LV8729、TB6560、TB6600、TMC2100、TMC2130、TMC2130_STANDALONE、TMC2160、TMC2160_STANDALONE、TMC2208、TMC2208_STANDALONE、TMC2209、TMC2209_STANDALONE、TMC26X、TMC26X_STANDALONE、TMC2660、TMC2660_STANDALONE、TMC5130、TMC5130_STANDALONE、TMC5160、TMC5160_STANDALONE"  
#endif

#if Z_DRIVER_TYPE_KEY != A4988 && Z_DRIVER_TYPE_KEY != A5984 && Z_DRIVER_TYPE_KEY != DRV8825 && Z_DRIVER_TYPE_KEY != LV8729 && Z_DRIVER_TYPE_KEY != TB6560 && Z_DRIVER_TYPE_KEY != TB6600 && Z_DRIVER_TYPE_KEY != TMC2100 && Z_DRIVER_TYPE_KEY != TMC2130 && Z_DRIVER_TYPE_KEY != TMC2130_STANDALONE && Z_DRIVER_TYPE_KEY != TMC2160 && Z_DRIVER_TYPE_KEY != TMC2160_STANDALONE && Z_DRIVER_TYPE_KEY != TMC2208 && Z_DRIVER_TYPE_KEY != TMC2208_STANDALONE && Z_DRIVER_TYPE_KEY != TMC2209 && Z_DRIVER_TYPE_KEY != TMC2209_STANDALONE && Z_DRIVER_TYPE_KEY != TMC26X && Z_DRIVER_TYPE_KEY != TMC26X_STANDALONE && Z_DRIVER_TYPE_KEY != TMC2660 && Z_DRIVER_TYPE_KEY != TMC2660_STANDALONE && Z_DRIVER_TYPE_KEY != TMC5130 && Z_DRIVER_TYPE_KEY != TMC5130_STANDALONE && Z_DRIVER_TYPE_KEY != TMC5160 && Z_DRIVER_TYPE_KEY != TMC5160_STANDALONE
    #error "Z_DRIVER_TYPE_KEY 必须为以下类型之一:A4988、A5984、DRV8825、LV8729、TB6560、TB6600、TMC2100、TMC2130、TMC2130_STANDALONE、TMC2160、TMC2160_STANDALONE、TMC2208、TMC2208_STANDALONE、TMC2209、TMC2209_STANDALONE、TMC26X、TMC26X_STANDALONE、TMC2660、TMC2660_STANDALONE、TMC5130、TMC5130_STANDALONE、TMC5160、TMC5160_STANDALONE" 
#endif

#if E_DRIVER_TYPE_KEY != A4988 && E_DRIVER_TYPE_KEY != A5984 && E_DRIVER_TYPE_KEY != DRV8825 && E_DRIVER_TYPE_KEY != LV8729 && E_DRIVER_TYPE_KEY != TB6560 && E_DRIVER_TYPE_KEY != TB6600 && E_DRIVER_TYPE_KEY != TMC2100 && E_DRIVER_TYPE_KEY != TMC2130 && E_DRIVER_TYPE_KEY != TMC2130_STANDALONE && E_DRIVER_TYPE_KEY != TMC2160 && E_DRIVER_TYPE_KEY != TMC2160_STANDALONE && E_DRIVER_TYPE_KEY != TMC2208 && E_DRIVER_TYPE_KEY != TMC2208_STANDALONE && E_DRIVER_TYPE_KEY != TMC2209 && E_DRIVER_TYPE_KEY != TMC2209_STANDALONE && E_DRIVER_TYPE_KEY != TMC26X && E_DRIVER_TYPE_KEY != TMC26X_STANDALONE && E_DRIVER_TYPE_KEY != TMC2660 && E_DRIVER_TYPE_KEY != TMC2660_STANDALONE && E_DRIVER_TYPE_KEY != TMC5130 && E_DRIVER_TYPE_KEY != TMC5130_STANDALONE && E_DRIVER_TYPE_KEY != TMC5160 && E_DRIVER_TYPE_KEY != TMC5160_STANDALONE
    #error "E_DRIVER_TYPE_KEY 必须为以下类型之一:A4988、A5984、DRV8825、LV8729、TB6560、TB6600、TMC2100、TMC2130、TMC2130_STANDALONE、TMC2160、TMC2160_STANDALONE、TMC2208、TMC2208_STANDALONE、TMC2209、TMC2209_STANDALONE、TMC26X、TMC26X_STANDALONE、TMC2660、TMC2660_STANDALONE、TMC5130、TMC5130_STANDALONE、TMC5160、TMC5160_STANDALONE"
#endif

// 检查打印区域值是否为正数
#if Printable_Area_X <= 0
    #error "Printable_Area_X 必须是正数"  
#endif

#if Printable_Area_Y <= 0
    #error "Printable_Area_Y 必须是正数"
#endif

#if Printable_Area_Z <= 0
    #error "Printable_Area_Z 必须是正数"
#endif

// 检查热保护时间和温度是否为正数
#if E_Heating_Waiting_Time <= 0
    #error "E_Heating_Waiting_Time 必须是正数"
#endif

#if E_Temperature_Rise_During_Heating_Wait_Time <= 0
    #error "E_Temperature_Rise_During_Heating_Wait_Time 必须是正数"  
#endif

#if BED_Heating_Waiting_Time <= 0
    #error "BED_Heating_Waiting_Time 必须是正数" 
#endif

#if BED_Temperature_Rise_During_Heating_Wait_Time <= 0
    #error "BED_Temperature_Rise_During_Heating_Wait_Time 必须是正数"
#endif

// 检查热保护时间和温度是否大于等于1
#if E_Heating_Waiting_Time < 1
    #error "E_Heating_Waiting_Time 必须大于等于1"
#endif

#if E_Temperature_Rise_During_Heating_Wait_Time < 1
    #error "E_Temperature_Rise_During_Heating_Wait_Time 必须大于等于1"
#endif

#if BED_Heating_Waiting_Time < 1
    #error "BED_Heating_Waiting_Time 必须大于等于1"
#endif

#if BED_Temperature_Rise_During_Heating_Wait_Time < 1 
    #error "BED_Temperature_Rise_During_Heating_Wait_Time 必须大于等于1"
#endif

// 检查多点探测次数相关逻辑
#if Number_Of_Probes_Per_Point < 1
    #error "Number_Of_Probes_Per_Point 必须大于等于1"
#endif

#if defined(Number_Of_Probes_Per_Point) && defined(The_Number_Of_Data_That_Is_Allowed_To_Be_Discarded)
    #if Number_Of_Probes_Per_Point <= The_Number_Of_Data_That_Is_Allowed_To_Be_Discarded
        #error "Number_Of_Probes_Per_Point 必须大于 The_Number_Of_Data_That_Is_Allowed_To_Be_Discarded" 
    #endif
#endif  

#if defined(Number_Of_Probes_Per_Point)
    #if Number_Of_Probes_Per_Point != int(Number_Of_Probes_Per_Point)
        #error "Number_Of_Probes_Per_Point 必须是整数"
    #endif
#endif

#if defined(The_Number_Of_Data_That_Is_Allowed_To_Be_Discarded) 
    #if The_Number_Of_Data_That_Is_Allowed_To_Be_Discarded != int(The_Number_Of_Data_That_Is_Allowed_To_Be_Discarded)
        #error "The_Number_Of_Data_That_Is_Allowed_To_Be_Discarded 必须是整数"
    #endif
#endif

//————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————