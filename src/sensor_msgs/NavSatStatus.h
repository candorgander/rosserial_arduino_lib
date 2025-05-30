#ifndef _ROS_sensor_msgs_NavSatStatus_h
#define _ROS_sensor_msgs_NavSatStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace sensor_msgs
{

    static const char sensor_msgs_NavSatStatus_type[] PROGMEM= "sensor_msgs/NavSatStatus";
    static const char sensor_msgs_NavSatStatus_md5[] PROGMEM= "331cdbddfa4bc96ffc3b9ad98900a54c";
  class NavSatStatus : public ros::Msg
  {
    public:
      typedef int8_t _status_type;
      _status_type status;
      typedef uint16_t _service_type;
      _service_type service;
      enum { STATUS_NO_FIX =   -1         };
      enum { STATUS_FIX =       0         };
      enum { STATUS_SBAS_FIX =  1         };
      enum { STATUS_GBAS_FIX =  2         };
      enum { SERVICE_GPS =      1 };
      enum { SERVICE_GLONASS =  2 };
      enum { SERVICE_COMPASS =  4       };
      enum { SERVICE_GALILEO =  8 };

    NavSatStatus():
      status(0),
      service(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_status;
      u_status.real = this->status;
      *(outbuffer + offset + 0) = (u_status.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->status);
      *(outbuffer + offset + 0) = (this->service >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->service >> (8 * 1)) & 0xFF;
      offset += sizeof(this->service);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_status;
      u_status.base = 0;
      u_status.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->status = u_status.real;
      offset += sizeof(this->status);
      this->service =  ((uint16_t) (*(inbuffer + offset)));
      this->service |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->service);
     return offset;
    }

    virtual const char * getType(const char * type_msg) override { strcpy_P((char *)type_msg, (char *)sensor_msgs_NavSatStatus_type);return type_msg; };
    virtual const char * getMD5(const char * md5_msg) override { strcpy_P((char *)md5_msg, (char *)sensor_msgs_NavSatStatus_md5);return md5_msg; };

  };

}
#endif
