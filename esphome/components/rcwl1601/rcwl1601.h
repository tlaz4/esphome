#pragma once

#include "esphome/core/component.h"
#include "esphome/components/sensor/sensor.h"
#include "esphome/components/i2c/i2c.h"

namespace esphome {
namespace rcwl1601 {


class RCWL1601 : public sensor::Sensor, public PollingComponent, public i2c::I2CDevice {
  public:
    void setup() override;
    void update() override;
    void dump_config() override;

  protected:
    float read_data_();
};
} // namespace RCWL1601
} // namespace esphome
