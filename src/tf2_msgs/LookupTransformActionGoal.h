#ifndef _ROS_tf2_msgs_LookupTransformActionGoal_h
#define _ROS_tf2_msgs_LookupTransformActionGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalID.h"
#include "tf2_msgs/LookupTransformGoal.h"

namespace tf2_msgs
{

    static const char tf2_msgs_LookupTransformActionGoal_type[] PROGMEM= "tf2_msgs/LookupTransformActionGoal";
    static const char tf2_msgs_LookupTransformActionGoal_md5[] PROGMEM= "f2e7bcdb75c847978d0351a13e699da5";
  class LookupTransformActionGoal : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalID _goal_id_type;
      _goal_id_type goal_id;
      typedef tf2_msgs::LookupTransformGoal _goal_type;
      _goal_type goal;

    LookupTransformActionGoal():
      header(),
      goal_id(),
      goal()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->goal_id.serialize(outbuffer + offset);
      offset += this->goal.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->goal_id.deserialize(inbuffer + offset);
      offset += this->goal.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType(const char * type_msg) override { strcpy_P((char *)type_msg, (char *)tf2_msgs_LookupTransformActionGoal_type);return type_msg; };
    virtual const char * getMD5(const char * md5_msg) override { strcpy_P((char *)md5_msg, (char *)tf2_msgs_LookupTransformActionGoal_md5);return md5_msg; };

  };

}
#endif
