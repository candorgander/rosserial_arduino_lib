#ifndef _ROS_geometry_msgs_Wrench_h
#define _ROS_geometry_msgs_Wrench_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Vector3.h"

namespace geometry_msgs
{

    static const char geometry_msgs_Wrench_type[] PROGMEM= "geometry_msgs/Wrench";
    static const char geometry_msgs_Wrench_md5[] PROGMEM= "4f539cf138b23283b520fd271b567936";
  class Wrench : public ros::Msg
  {
    public:
      typedef geometry_msgs::Vector3 _force_type;
      _force_type force;
      typedef geometry_msgs::Vector3 _torque_type;
      _torque_type torque;

    Wrench():
      force(),
      torque()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->force.serialize(outbuffer + offset);
      offset += this->torque.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->force.deserialize(inbuffer + offset);
      offset += this->torque.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType(const char * type_msg) override { strcpy_P((char *)type_msg, (char *)geometry_msgs_Wrench_type);return type_msg; };
    virtual const char * getMD5(const char * md5_msg) override { strcpy_P((char *)md5_msg, (char *)geometry_msgs_Wrench_md5);return md5_msg; };

  };

}
#endif
