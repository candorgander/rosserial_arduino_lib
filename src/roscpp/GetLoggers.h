#ifndef _ROS_SERVICE_GetLoggers_h
#define _ROS_SERVICE_GetLoggers_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "roscpp/Logger.h"

namespace roscpp
{

static const char GETLOGGERS[] PROGMEM= "roscpp/GetLoggers";

    static const char roscpp_GetLoggersRequest_type[] PROGMEM= "roscpp/GetLoggersRequest";
    static const char roscpp_GetLoggersRequest_md5[] PROGMEM= "d41d8cd98f00b204e9800998ecf8427e";
  class GetLoggersRequest : public ros::Msg
  {
    public:

    GetLoggersRequest()
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

    virtual const char * getType(const char * type_msg) override { strcpy_P((char *)type_msg, (char *)GETLOGGERS);return type_msg; };
    virtual const char * getMD5(const char * md5_msg) override { strcpy_P((char *)md5_msg, (char *)roscpp_GetLoggersRequest_md5);return md5_msg; };

  };

    static const char roscpp_GetLoggersResponse_type[] PROGMEM= "roscpp/GetLoggersResponse";
    static const char roscpp_GetLoggersResponse_md5[] PROGMEM= "32e97e85527d4678a8f9279894bb64b0";
  class GetLoggersResponse : public ros::Msg
  {
    public:
      uint32_t loggers_length;
      typedef roscpp::Logger _loggers_type;
      _loggers_type st_loggers;
      _loggers_type * loggers;

    GetLoggersResponse():
      loggers_length(0), st_loggers(), loggers(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->loggers_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->loggers_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->loggers_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->loggers_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->loggers_length);
      for( uint32_t i = 0; i < loggers_length; i++){
      offset += this->loggers[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t loggers_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      loggers_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      loggers_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      loggers_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->loggers_length);
      if(loggers_lengthT > loggers_length)
        this->loggers = (roscpp::Logger*)realloc(this->loggers, loggers_lengthT * sizeof(roscpp::Logger));
      loggers_length = loggers_lengthT;
      for( uint32_t i = 0; i < loggers_length; i++){
      offset += this->st_loggers.deserialize(inbuffer + offset);
        memcpy( &(this->loggers[i]), &(this->st_loggers), sizeof(roscpp::Logger));
      }
     return offset;
    }

    virtual const char * getType(const char * type_msg) override { strcpy_P((char *)type_msg, (char *)GETLOGGERS);return type_msg; };
    virtual const char * getMD5(const char * md5_msg) override { strcpy_P((char *)md5_msg, (char *)roscpp_GetLoggersResponse_md5);return md5_msg; };

  };

  class GetLoggers {
    public:
    typedef GetLoggersRequest Request;
    typedef GetLoggersResponse Response;
  };

}
#endif
