#pragma once

#include "Motor.h"

namespace Motors {
    class StandardStepper : public Motor {
    public:
        StandardStepper(uint8_t axis_index, Pin step_pin, Pin dir_pin, Pin disable_pin);

        // Overrides for inherited methods
        void init() override;

        // No special action, but return true to say homing is possible
        bool set_homing_mode(bool isHoming) override { return true; }
        void set_disable(bool) override;
        void set_direction(bool) override;
        void step() override;
        void unstep() override;
        void read_settings() override;

        void init_step_dir_pins();

    protected:
        void config_message() override;

        rmt_channel_t _rmt_chan_num;
        Pin  _step_pin;
        Pin  _dir_pin;
        Pin  _disable_pin;

        bool _use_RMT;

    private:
        static rmt_channel_t get_next_RMT_chan_num();
        static rmt_item32_t  rmtItem[2];
        static rmt_config_t  rmtConfig;
    };
}
