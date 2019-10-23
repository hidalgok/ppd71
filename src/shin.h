#ifndef shin_H
#define shin_H

#include "Stream.h"

class PPD71
{
public:

  struct DATA {
    // Standard Particles, CF=1
    uint16_t avg_10s;
    uint16_t avg_30s;
    uint16_t avg_60s;
    uint16_t avg_180s;
  };

  PPD71(Stream&);

  int read(DATA& data);

private:

  uint8_t _payload[12];
  Stream* _stream;
  DATA* _data;

  uint8_t _checksum;
  uint8_t _error;

  void loop();
};

#endif
