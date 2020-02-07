#pragma once

#include <stdint.h>

#include "cclib/message.h"

namespace lifx {

#pragma pack(push, 1)

struct Device {
  struct StateService;
  struct GetService : public RequestPayload<2, StateService> {
    static const bool broadcast = true;
  };

  struct StateService : public ResponsePayload<3> {
    Service service;
    Port port;
  };

  struct StateHostInfo;
  struct GetHostInfo : public RequestPayload<12, StateHostInfo> {};

  struct StateHostInfo : public ResponsePayload<13> {
    float signal;
    uint32_t tx;
    uint32_t rx;
    int16_t :16;
  };

  struct StateHostFirmware;
  struct GetHostFirmware : public RequestPayload<14, StateHostFirmware> {};

  struct StateHostFirmware : public ResponsePayload<15> {
    TimestampNanos build;
    uint64_t :64;
    uint16_t version_minor;
    uint16_t version_major;
  };

  struct StateWifiInfo;
  struct GetWifiInfo : public RequestPayload<16, StateWifiInfo> {};

  struct StateWifiInfo : public ResponsePayload<17> {
    float signal;
    uint32_t tx;
    uint32_t rx;
    int16_t :16;
  };

  struct StateWifiFirmware;
  struct GetWifiFirmware : public RequestPayload<18, StateWifiFirmware> {};

  struct StateWifiFirmware : public ResponsePayload<19> {
    TimestampNanos build;
    uint64_t :64;
    uint16_t version_minor;
    uint16_t version_major;
  };

  struct StatePower;
  struct GetPower : public RequestPayload<20, StatePower> {};

  struct SetPower : public RequestPayload<21, StatePower> {
    PowerLevel level;
  };

  struct StatePower : public ResponsePayload<22> {
    PowerLevel power;
  };

  struct StateLabel;
  struct GetLabel : public RequestPayload<23, StateLabel> {};

#ifdef ENABLE_SETTING_DEVICE_METADATA
  struct SetLabel : public RequestPayload<24, StateLabel> {
    Label label;
  };
#endif

  struct StateLabel : public ResponsePayload<25> {
    Label label;
  };

  struct StateVersion;
  struct GetVersion : public RequestPayload<32, StateVersion> {};

  struct StateVersion : public ResponsePayload<33> {
    uint32_t vendor;
    uint32_t product;
    uint32_t version;
  };

  struct StateInfo;
  struct GetInfo : public RequestPayload<34, StateInfo> {};

  struct StateInfo : public ResponsePayload<35> {
    uint32_t vendor;
    uint32_t product;
    uint32_t version;
  };

  struct StateLocation;
  struct GetLocation : public RequestPayload<48, StateLocation> {};

#ifdef ENABLE_SETTING_DEVICE_METADATA
  struct SetLocation : public RequestPayload<49, StateLocation> {
    uint8_t location[16];
    Label label;
    TimestampNanos updated_at;
  };
#endif

  struct StateLocation : public ResponsePayload<50> {
    uint8_t location[16];
    Label label;
    TimestampNanos updated_at;
  };

  struct StateGroup;
  struct GetGroup : public RequestPayload<51, StateGroup> {};

#ifdef ENABLE_SETTING_DEVICE_METADATA
  struct SetGroup : public RequestPayload<52, StateGroup> {
    uint8_t group[16];
    Label label;
    TimestampNanos updated_at;
  };
#endif

  struct StateGroup : public ResponsePayload<53> {
    uint8_t group[16];
    Label label;
    TimestampNanos updated_at;
  };

  struct EchoResponse;
  struct EchoRequest : public RequestPayload<58, EchoResponse> {
    uint8_t payload[8];
  };

  struct EchoResponse : public ResponsePayload<59> {
    uint8_t payload[8];
  };
};

#pragma pack(push)

}  // namespace lifx
