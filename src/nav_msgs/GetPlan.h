#ifndef _ROS_SERVICE_GetPlan_h
#define _ROS_SERVICE_GetPlan_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseStamped.h"
#include "nav_msgs/Path.h"

namespace nav_msgs
{

static const char GETPLAN[] PROGMEM= "nav_msgs/GetPlan";

    static const char nav_msgs_GetPlanRequest_type[] PROGMEM= "nav_msgs/GetPlanRequest";
    static const char nav_msgs_GetPlanRequest_md5[] PROGMEM= "e25a43e0752bcca599a8c2eef8282df8";
  class GetPlanRequest : public ros::Msg
  {
    public:
      typedef geometry_msgs::PoseStamped _start_type;
      _start_type start;
      typedef geometry_msgs::PoseStamped _goal_type;
      _goal_type goal;
      typedef float _tolerance_type;
      _tolerance_type tolerance;

    GetPlanRequest():
      start(),
      goal(),
      tolerance(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->start.serialize(outbuffer + offset);
      offset += this->goal.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_tolerance;
      u_tolerance.real = this->tolerance;
      *(outbuffer + offset + 0) = (u_tolerance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_tolerance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_tolerance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_tolerance.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tolerance);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->start.deserialize(inbuffer + offset);
      offset += this->goal.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_tolerance;
      u_tolerance.base = 0;
      u_tolerance.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_tolerance.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_tolerance.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_tolerance.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->tolerance = u_tolerance.real;
      offset += sizeof(this->tolerance);
     return offset;
    }

    virtual const char * getType(const char * type_msg) override { strcpy_P((char *)type_msg, (char *)GETPLAN);return type_msg; };
    virtual const char * getMD5(const char * md5_msg) override { strcpy_P((char *)md5_msg, (char *)nav_msgs_GetPlanRequest_md5);return md5_msg; };

  };

    static const char nav_msgs_GetPlanResponse_type[] PROGMEM= "nav_msgs/GetPlanResponse";
    static const char nav_msgs_GetPlanResponse_md5[] PROGMEM= "0002bc113c0259d71f6cf8cbc9430e18";
  class GetPlanResponse : public ros::Msg
  {
    public:
      typedef nav_msgs::Path _plan_type;
      _plan_type plan;

    GetPlanResponse():
      plan()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->plan.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->plan.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType(const char * type_msg) override { strcpy_P((char *)type_msg, (char *)GETPLAN);return type_msg; };
    virtual const char * getMD5(const char * md5_msg) override { strcpy_P((char *)md5_msg, (char *)nav_msgs_GetPlanResponse_md5);return md5_msg; };

  };

  class GetPlan {
    public:
    typedef GetPlanRequest Request;
    typedef GetPlanResponse Response;
  };

}
#endif
