#pragma once

#include <stdint.h>

namespace lifx {

#pragma pack(push, 1)

struct Frame {
  uint16_t size;
  uint16_t protocol:12;
  bool addressable:1;
  bool tagged:1;
  uint8_t origin:2;
  uint32_t source;
};

struct FrameAddress {
  uint8_t target[8];
  uint8_t reserved[6];
  bool res_required:1;
  bool ack_required:1;
  uint8_t :6;
  uint8_t sequence;
};

struct ProtocolHeader {
  uint64_t :64;
  uint16_t type;
  uint16_t :16;
};

struct Header {
  Frame frame;
  FrameAddress frame_address;
  ProtocolHeader protocol_header;
};

#pragma pack(pop)

}  // namespace lifx
