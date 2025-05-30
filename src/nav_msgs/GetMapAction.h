#ifndef _ROS_nav_msgs_GetMapAction_h
#define _ROS_nav_msgs_GetMapAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "nav_msgs/GetMapActionGoal.h"
#include "nav_msgs/GetMapActionResult.h"
#include "nav_msgs/GetMapActionFeedback.h"

namespace nav_msgs
{

    static const char nav_msgs_GetMapAction_type[] PROGMEM= "nav_msgs/GetMapAction";
    static const char nav_msgs_GetMapAction_md5[] PROGMEM= "e611ad23fbf237c031b7536416dc7cd7";
  class GetMapAction : public ros::Msg
  {
    public:
      typedef nav_msgs::GetMapActionGoal _action_goal_type;
      _action_goal_type action_goal;
      typedef nav_msgs::GetMapActionResult _action_result_type;
      _action_result_type action_result;
      typedef nav_msgs::GetMapActionFeedback _action_feedback_type;
      _action_feedback_type action_feedback;

    GetMapAction():
      action_goal(),
      action_result(),
      action_feedback()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->action_goal.serialize(outbuffer + offset);
      offset += this->action_result.serialize(outbuffer + offset);
      offset += this->action_feedback.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->action_goal.deserialize(inbuffer + offset);
      offset += this->action_result.deserialize(inbuffer + offset);
      offset += this->action_feedback.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType(const char * type_msg) override { strcpy_P((char *)type_msg, (char *)nav_msgs_GetMapAction_type);return type_msg; };
    virtual const char * getMD5(const char * md5_msg) override { strcpy_P((char *)md5_msg, (char *)nav_msgs_GetMapAction_md5);return md5_msg; };

  };

}
#endif
