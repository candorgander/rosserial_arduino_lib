#ifndef _ROS_SERVICE_AddDiagnostics_h
#define _ROS_SERVICE_AddDiagnostics_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace diagnostic_msgs
{

static const char ADDDIAGNOSTICS[] PROGMEM= "diagnostic_msgs/AddDiagnostics";

    static const char diagnostic_msgs_AddDiagnosticsRequest_type[] PROGMEM= "diagnostic_msgs/AddDiagnosticsRequest";
    static const char diagnostic_msgs_AddDiagnosticsRequest_md5[] PROGMEM= "c26cf6e164288fbc6050d74f838bcdf0";
  class AddDiagnosticsRequest : public ros::Msg
  {
    public:
      typedef const char* _load_namespace_type;
      _load_namespace_type load_namespace;

    AddDiagnosticsRequest():
      load_namespace("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_load_namespace = strlen(this->load_namespace);
      varToArr(outbuffer + offset, length_load_namespace);
      offset += 4;
      memcpy(outbuffer + offset, this->load_namespace, length_load_namespace);
      offset += length_load_namespace;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_load_namespace;
      arrToVar(length_load_namespace, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_load_namespace; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_load_namespace-1]=0;
      this->load_namespace = (char *)(inbuffer + offset-1);
      offset += length_load_namespace;
     return offset;
    }

    virtual const char * getType(const char * type_msg) override { strcpy_P((char *)type_msg, (char *)ADDDIAGNOSTICS);return type_msg; };
    virtual const char * getMD5(const char * md5_msg) override { strcpy_P((char *)md5_msg, (char *)diagnostic_msgs_AddDiagnosticsRequest_md5);return md5_msg; };

  };

    static const char diagnostic_msgs_AddDiagnosticsResponse_type[] PROGMEM= "diagnostic_msgs/AddDiagnosticsResponse";
    static const char diagnostic_msgs_AddDiagnosticsResponse_md5[] PROGMEM= "937c9679a518e3a18d831e57125ea522";
  class AddDiagnosticsResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;
      typedef const char* _message_type;
      _message_type message;

    AddDiagnosticsResponse():
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

    virtual const char * getType(const char * type_msg) override { strcpy_P((char *)type_msg, (char *)ADDDIAGNOSTICS);return type_msg; };
    virtual const char * getMD5(const char * md5_msg) override { strcpy_P((char *)md5_msg, (char *)diagnostic_msgs_AddDiagnosticsResponse_md5);return md5_msg; };

  };

  class AddDiagnostics {
    public:
    typedef AddDiagnosticsRequest Request;
    typedef AddDiagnosticsResponse Response;
  };

}
#endif
