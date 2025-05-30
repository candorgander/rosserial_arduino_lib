#ifndef _ROS_rosserial_msgs_Log_h
#define _ROS_rosserial_msgs_Log_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rosserial_msgs
{

    static const char rosserial_msgs_Log_type[] PROGMEM= "rosserial_msgs/Log";
    static const char rosserial_msgs_Log_md5[] PROGMEM= "11abd731c25933261cd6183bd12d6295";
  class Log : public ros::Msg
  {
    public:
      typedef uint8_t _level_type;
      _level_type level;
      typedef const char* _msg_type;
      _msg_type msg;
      enum { ROSDEBUG = 0 };
      enum { INFO = 1 };
      enum { WARN = 2 };
      enum { ERROR = 3 };
      enum { FATAL = 4 };

    Log():
      level(0),
      msg("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->level >> (8 * 0)) & 0xFF;
      offset += sizeof(this->level);
      uint32_t length_msg = strlen(this->msg);
      varToArr(outbuffer + offset, length_msg);
      offset += 4;
      memcpy(outbuffer + offset, this->msg, length_msg);
      offset += length_msg;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->level =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->level);
      uint32_t length_msg;
      arrToVar(length_msg, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_msg; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_msg-1]=0;
      this->msg = (char *)(inbuffer + offset-1);
      offset += length_msg;
     return offset;
    }

    virtual const char * getType(const char * type_msg) override { strcpy_P((char *)type_msg, (char *)rosserial_msgs_Log_type);return type_msg; };
    virtual const char * getMD5(const char * md5_msg) override { strcpy_P((char *)md5_msg, (char *)rosserial_msgs_Log_md5);return md5_msg; };

  };

}
#endif
