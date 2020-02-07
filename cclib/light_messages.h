#pragma once

#include <stdint.h>

#include "cclib/message.h"

namespace lifx {

#pragma pack(push, 1)

struct Light {
  struct State;
  struct Get : public RequestPayload<101, State> {};

  struct SetColor : public RequestPayload<102, State> {
    uint8_t :8;
    HSBK color;
    uint32_t duration_ms;
  };

  struct SetWaveform : public RequestPayload<103, State> {
    uint8_t :8;
    bool transient;
    HSBK color;
    uint32_t period_ms;
    float cycles;
    int16_t skew_ratio;
    Waveform waveform;
  };

  struct SetWaveformOptional : public RequestPayload<119, State> {
    uint8_t :8;
    bool transient;
    HSBK color;
    uint32_t period_ms;
    float cycles;
    int16_t skew_ratio;
    Waveform waveform;
    bool set_hue;
    bool set_saturation;
    bool set_brightness;
    bool set_kelvin;
  };

  struct State : public ResponsePayload<107> {
    HSBK color;
    int64_t :16;
    uint16_t power;
    Label label;
    uint64_t :64;
  };

  struct StatePower;
  struct GetPower : public RequestPayload<116, StatePower> {};

  struct SetPower : public RequestPayload<117, StatePower> {
    PowerLevel level;
    uint32_t duration_ms;
  };

  struct StatePower : public ResponsePayload<118> {
    PowerLevel level;
  };

  struct StateInfrared;
  struct GetInfrared : public RequestPayload<120, StateInfrared> {};

  struct StateInfrared : public ResponsePayload<121> {};

  struct SetInfrared : public RequestPayload<122, StateInfrared> {
    uint16_t brightness;
  };
};

#pragma pack(push)

}  // namespace lifx
