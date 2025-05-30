#ifndef _ROS_geometry_msgs_Vector3Stamped_h
#define _ROS_geometry_msgs_Vector3Stamped_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Vector3.h"

namespace geometry_msgs
{

    static const char geometry_msgs_Vector3Stamped_type[] PROGMEM= "geometry_msgs/Vector3Stamped";
    static const char geometry_msgs_Vector3Stamped_md5[] PROGMEM= "7b324c7325e683bf02a9b14b01090ec7";
  class Vector3Stamped : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef geometry_msgs::Vector3 _vector_type;
      _vector_type vector;

    Vector3Stamped():
      header(),
      vector()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->vector.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->vector.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType(const char * type_msg) override { strcpy_P((char *)type_msg, (char *)geometry_msgs_Vector3Stamped_type);return type_msg; };
    virtual const char * getMD5(const char * md5_msg) override { strcpy_P((char *)md5_msg, (char *)geometry_msgs_Vector3Stamped_md5);return md5_msg; };

  };

}
#endif
