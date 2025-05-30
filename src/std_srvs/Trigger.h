#ifndef _ROS_SERVICE_Trigger_h
#define _ROS_SERVICE_Trigger_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace std_srvs
{

static const char TRIGGER[] PROGMEM= "std_srvs/Trigger";

    static const char std_srvs_TriggerRequest_type[] PROGMEM= "std_srvs/TriggerRequest";
    static const char std_srvs_TriggerRequest_md5[] PROGMEM= "d41d8cd98f00b204e9800998ecf8427e";
  class TriggerRequest : public ros::Msg
  {
    public:

    TriggerRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
     return offset;
    }

    virtual const char * getType(const char * type_msg) override { strcpy_P((char *)type_msg, (char *)TRIGGER);return type_msg; };
    virtual const char * getMD5(const char * md5_msg) override { strcpy_P((char *)md5_msg, (char *)std_srvs_TriggerRequest_md5);return md5_msg; };

  };

    static const char std_srvs_TriggerResponse_type[] PROGMEM= "std_srvs/TriggerResponse";
    static const char std_srvs_TriggerResponse_md5[] PROGMEM= "937c9679a518e3a18d831e57125ea522";
  class TriggerResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;
      typedef const char* _message_type;
      _message_type message;

    TriggerResponse():
      success(0),
      message("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      uint32_t length_message = strlen(this->message);
      varToArr(outbuffer + offset, length_message);
      offset += 4;
      memcpy(outbuffer + offset, this->message, length_message);
      offset += length_message;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
      uint32_t length_message;
      arrToVar(length_message, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_message; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_message-1]=0;
      this->message = (char *)(inbuffer + offset-1);
      offset += length_message;
     return offset;
    }

    virtual const char * getType(const char * type_msg) override { strcpy_P((char *)type_msg, (char *)TRIGGER);return type_msg; };
    virtual const char * getMD5(const char * md5_msg) override { strcpy_P((char *)md5_msg, (char *)std_srvs_TriggerResponse_md5);return md5_msg; };

  };

  class Trigger {
    public:
    typedef TriggerRequest Request;
    typedef TriggerResponse Response;
  };

}
#endif
