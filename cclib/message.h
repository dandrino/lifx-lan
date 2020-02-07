#pragma once

#include <stdint.h>

#include "cclib/header.h"

namespace lifx {

#pragma pack(push, 1)

/////////////////////////////////////////////////////////////////////////////////////////
// Message Field Types
/////////////////////////////////////////////////////////////////////////////////////////

enum class Waveform : uint8_t {
  SAW = 0,
  SINE = 1,
  HALF_SINE = 2,
  TRIANGLE = 3,
  PULSE = 4,
};

struct HSBK {
  uint16_t hue;
  uint16_t saturation;
  uint16_t brightness;
  uint16_t kelvin;
};

enum class PowerLevel : uint16_t {
 STANDBY = 0,
 ENABLED = 65535,
};

enum class Service : uint8_t {
  UDP = 1,
};

using Label = char[32];

using Port = uint32_t;
extern const Port kDefaultPort = 56700;

using TimestampNanos = uint64_t;

/////////////////////////////////////////////////////////////////////////////////////////
// Payload base types
/////////////////////////////////////////////////////////////////////////////////////////

template <uint16_t Type, typename ResponseType>
struct PayloadBase {
  using response_type = ResponseType;
  static const uint16_t type = Type;
  static const bool broadcast = false;
};

template <uint16_t Type, typename ResponseType>
using RequestPayload = PayloadBase<Type, ResponseType>;

template <uint16_t Type>
using ResponsePayload = PayloadBase<Type, void>;

struct Acknowledgement : public ResponsePayload<45> {};


/////////////////////////////////////////////////////////////////////////////////////////
// Base messages
/////////////////////////////////////////////////////////////////////////////////////////

template <typename Payload>
struct Message {
  static const int kBufferSizeBytes = 1024;
  static_assert(sizeof(Message<Payload>) <= kBufferSizeBytes,
                "Uh oh, the raw message buffer size is too small");
  union {
    uint8_t buffer[kBufferSizeBytes];
    struct {
      Header header;
      Payload payload;
    };
  };
};

using RawMessage = Message<uint8_t[0]>;

#pragma pack(pop)

}  // namespace lifx
