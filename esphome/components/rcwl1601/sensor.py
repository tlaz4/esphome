import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import i2c, sensor
from esphome.const import ICON_RULER, UNIT_MILLIMETER, DEVICE_CLASS_DISTANCE, STATE_CLASS_MEASUREMENT

DEPENDENCIES = ["i2c"]


rcwl1601_ns = cg.esphome_ns.namespace("rcwl1601")
RCWL1601 = rcwl1601_ns.class_(
    "RCWL1601", cg.PollingComponent, i2c.I2CDevice
)

CONFIG_SCHEMA = (
    sensor.sensor_schema(
        RCWL1601,
        unit_of_measurement=UNIT_MILLIMETER,
        icon=ICON_RULER,
        accuracy_decimals=1,
        device_class=DEVICE_CLASS_DISTANCE,
        state_class=STATE_CLASS_MEASUREMENT,
    )
    .extend(cv.polling_component_schema("60s"))
    .extend(i2c.i2c_device_schema(0x57))
    .extend({cv.GenerateID(): cv.declare_id(RCWL1601)})
)


async def to_code(config):
    var = await sensor.new_sensor(config)
    await cg.register_component(var, config)
    await i2c.register_i2c_device(var, config)

