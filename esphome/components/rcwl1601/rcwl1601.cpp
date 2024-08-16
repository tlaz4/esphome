#include "esphome/core/log.h"
#include "rcwl1601.h"

namespace esphome {
namespace rcwl1601 {

static const char *TAG = "rcwl1601.sensor";

void RCWL1601::setup(){

}

void RCWL1601::update(){
  publish_state(42.0);

  uint8_t data[3];
  ESP_LOGD(TAG, this->read_data_(data));
  ESP_LOGD(TAG, "Distance: ", &data);

}

void RCWL1601::dump_config(){
   LOG_I2C_DEVICE(this);
   if (this->is_failed()) {
     ESP_LOGE(TAG, "Communication with rcwl1206 failed!");
   }
}

bool RCWL1601::read_data_(uint8_t *data){
  uint8_t start_reading = 1;

  if(this->write(&start_reading, 1) != i2c::ERROR_OK){
    this->mark_failed();
    return false;
  }
  delay_microseconds_safe(20000);
  if(this->read(data, sizeof(data) != i2c::ERROR_OK){
    this->mark_failed();
    return false;
  }

  return true;

}

} // namespace RCWL1601
} // namespace esphome
