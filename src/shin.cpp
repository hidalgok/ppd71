#include "Arduino.h"
#include "shin.h"

PPD71::PPD71(Stream& stream)
{
  this->_stream = &stream;
}

// Non-blocking function for parse response.
int PPD71::read(DATA& data)
{
  _data = &data;
  loop();
  
  return _error;
}

void PPD71::loop(){
	char Buffer[31];
  _error=1;
  if (_stream->available()>=29){
    _stream->readBytesUntil(0x04, Buffer, 29); //last byte is always 0x04
    if (Buffer[0]!=0x02){ //first byte is always 0x02
      //_error = 1;
      return;
    }else {
      _checksum = 0;
      for(int i=0;i<27;i++){
        _checksum+=Buffer[i];
      }
      if (_checksum!=Buffer[27]){
        //_error = 1;
        return;
      }else{
        _error = 0;
        _data->avg_10s=makeWord(Buffer[3],Buffer[4]);
        _data->avg_30s=makeWord(Buffer[5],Buffer[6]);
        _data->avg_60s=makeWord(Buffer[7],Buffer[8]);
        _data->avg_180s=makeWord(Buffer[9],Buffer[10]);
        return;
      }
    }
  }
}
