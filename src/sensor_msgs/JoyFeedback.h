#ifndef _ROS_sensor_msgs_JoyFeedback_h
#define _ROS_sensor_msgs_JoyFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace sensor_msgs
{

    static const char sensor_msgs_JoyFeedback_type[] PROGMEM= "sensor_msgs/JoyFeedback";
    static const char sensor_msgs_JoyFeedback_md5[] PROGMEM= "f4dcd73460360d98f36e55ee7f2e46f1";
  class JoyFeedback : public ros::Msg
  {
    public:
      typedef uint8_t _type_type;
      _type_type type;
      typedef uint8_t _id_type;
      _id_type id;
      typedef float _intensity_type;
      _intensity_type intensity;
      enum { TYPE_LED =  0 };
      enum { TYPE_RUMBLE =  1 };
      enum { TYPE_BUZZER =  2 };

    JoyFeedback():
      type(0),
      id(0),
      intensity(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->type);
      *(outbuffer + offset + 0) = (this->id >> (8 * 0)) & 0xFF;
      offset += sizeof(this->id);
      union {
        float real;
        uint32_t base;
      } u_intensity;
      u_intensity.real = this->intensity;
      *(outbuffer + offset + 0) = (u_intensity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_intensity.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_intensity.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_intensity.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->intensity);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->type);
      this->id =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->id);
      union {
        float real;
        uint32_t base;
      } u_intensity;
      u_intensity.base = 0;
      u_intensity.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_intensity.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_intensity.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_intensity.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->intensity = u_intensity.real;
      offset += sizeof(this->intensity);
     return offset;
    }

    virtual const char * getType(const char * type_msg) override { strcpy_P((char *)type_msg, (char *)sensor_msgs_JoyFeedback_type);return type_msg; };
    virtual const char * getMD5(const char * md5_msg) override { strcpy_P((char *)md5_msg, (char *)sensor_msgs_JoyFeedback_md5);return md5_msg; };

  };

}
#endif
