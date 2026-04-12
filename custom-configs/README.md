# 个人定制配置文件

## ⚠️ 重要提示

此目录包含我个人定制的CNC电路板配置文件，**不适用于通用硬件**。

## 📋 配置文件列表

### config_waveshare_esp32s3_pico_simple.yaml

**适用硬件：**
- 主控板：微雪 ESP32-S3-PICO
- 电机驱动：标准STEP/DIR/EN驱动器（非TMC）
- 轴配置：3轴（X, Y双电机并联, Z）

**主要特性：**
- ✅ 禁用PSRAM以释放GPIO33-37
- ✅ Y轴双电机并联驱动
- ✅ 激光PWM输出（GPIO12）
- ✅ I2C接口（SDA=42, SCL=41）
- ✅ 限位开关支持

**引脚映射：**

| 轴 | 功能 | GPIO | 说明 |
|----|------|------|------|
| X | STEP | 17 | 步进脉冲 |
| X | DIR | 13 | 方向控制 |
| X | EN | 35 | 使能控制 |
| X | Limit- | 1 | 负向限位 |
| Y主 | STEP | 18 | 主电机步进 |
| Y主 | DIR | 14 | 主电机方向 |
| Y主 | EN | 36 | 主电机使能 |
| Y主 | Limit- | 2 | 主电机限位 |
| Y副 | STEP | 34 | 副电机步进 |
| Y副 | DIR | 16 | 副电机方向 |
| Y副 | EN | 38 | 副电机使能 |
| Z | STEP | 33 | 步进脉冲 |
| Z | DIR | 15 | 方向控制 |
| Z | EN | 37 | 使能控制 |
| Z | Limit- | 4 | 负向限位 |
| Laser | PWM | 12 | 激光功率控制 |
| I2C | SDA | 42 | I2C数据 |
| I2C | SCL | 41 | I2C时钟 |

## 🔧 使用方法

1. **确认硬件匹配** - 确保您的硬件与上述配置完全一致
2. **上传配置** - 通过FluidNC Web界面的File Manager上传此文件
3. **重命名** - 将文件重命名为 `config.yaml`
4. **重启设备** - 重启ESP32使配置生效

## ⚙️ 源码修改要求

使用此配置需要修改FluidNC源码以启用GPIO33和GPIO34的输出功能：

```cpp
// FluidNC/esp32/esp32s3/GPIOCapabilities.cpp
if ((index <= 21) || (index == 33) || (index == 34) || (index >= 35 && index <= 48)) {
    return PinCapabilities::Native | PinCapabilities::Input | PinCapabilities::Output | ...
}
```

同时需要在 `sdkconfig.defaults` 中禁用PSRAM支持。

## 📝 作者信息

- **作者**: kxgx
- **硬件**: 微雪 ESP32-S3-PICO + 自定义CNC电路板
- **日期**: 2026-04-12
- **仓库**: https://github.com/kxgx/FluidNC

## ❗ 免责声明

此配置文件仅适用于作者个人的定制硬件。如果您使用的是其他硬件平台，请参考官方示例配置或根据实际硬件修改引脚定义。直接使用可能导致硬件损坏或功能异常。
