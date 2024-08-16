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
  this->read_data_(data);
  ESP_LOGD(TAG, "Distance: ", &data);

}

void RCWL1601::dump_config(){
   LOG_I2C_DEVICE(this);
   if (this->is_failed()) {
     ESP_LOGE(TAG, "Communication with rcwl1206 failed!");
   }
}

bool RCWL1601::read_data_(uint8_t *data){
  this->write((byte)1, 1);
  delay_microseconds_safe(20000);
  this->read(data, sizeof(data));

  return true;

}

} // namespace RCWL1601
} // namespace esphome
