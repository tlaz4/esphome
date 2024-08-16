#include "esphome/core/log.h"
#include "rcwl1601.h"

namespace esphome {
namespace rcwl1601 {

static const char *TAG = "rcwl1601.sensor";

void RCWL1601::setup(){

}

void RCWL1601::update(){
  publish_state(42.0);

  float result = this->read_data_();
  ESP_LOGD(TAG, "%s - Got distance: %.2f mm", this->name_.c_str(), result);

  publish_state(result);

}

void RCWL1601::dump_config(){
   LOG_I2C_DEVICE(this);
   if (this->is_failed()) {
     ESP_LOGE(TAG, "Communication with rcwl1206 failed!");
   }
}

float RCWL1601::read_data_(){
  uint32_t data;
  uint8_t val = 0x01 ;
  this->write(&val, 1);

  delay_microseconds_safe(20000);
  uint8_t data_buffer[] = {0,0,0,0,0};

  this->read(data_buffer,3);

  data = data_buffer[0]<< 16 | data_buffer[1]<< 8 | data_buffer[2];
  float distance = float(data) / 1000;

  return float;
}

} // namespace RCWL1601
} // namespace esphome
