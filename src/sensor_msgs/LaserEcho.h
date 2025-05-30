#ifndef _ROS_sensor_msgs_LaserEcho_h
#define _ROS_sensor_msgs_LaserEcho_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace sensor_msgs
{

    static const char sensor_msgs_LaserEcho_type[] PROGMEM= "sensor_msgs/LaserEcho";
    static const char sensor_msgs_LaserEcho_md5[] PROGMEM= "8bc5ae449b200fba4d552b4225586696";
  class LaserEcho : public ros::Msg
  {
    public:
      uint32_t echoes_length;
      typedef float _echoes_type;
      _echoes_type st_echoes;
      _echoes_type * echoes;

    LaserEcho():
      echoes_length(0), st_echoes(), echoes(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->echoes_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->echoes_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->echoes_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->echoes_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->echoes_length);
      for( uint32_t i = 0; i < echoes_length; i++){
      union {
        float real;
        uint32_t base;
      } u_echoesi;
      u_echoesi.real = this->echoes[i];
      *(outbuffer + offset + 0) = (u_echoesi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_echoesi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_echoesi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_echoesi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->echoes[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t echoes_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      echoes_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      echoes_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      echoes_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->echoes_length);
      if(echoes_lengthT > echoes_length)
        this->echoes = (float*)realloc(this->echoes, echoes_lengthT * sizeof(float));
      echoes_length = echoes_lengthT;
      for( uint32_t i = 0; i < echoes_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_echoes;
      u_st_echoes.base = 0;
      u_st_echoes.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_echoes.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_echoes.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_echoes.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_echoes = u_st_echoes.real;
      offset += sizeof(this->st_echoes);
        memcpy( &(this->echoes[i]), &(this->st_echoes), sizeof(float));
      }
     return offset;
    }

    virtual const char * getType(const char * type_msg) override { strcpy_P((char *)type_msg, (char *)sensor_msgs_LaserEcho_type);return type_msg; };
    virtual const char * getMD5(const char * md5_msg) override { strcpy_P((char *)md5_msg, (char *)sensor_msgs_LaserEcho_md5);return md5_msg; };

  };

}
#endif
