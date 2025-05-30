#ifndef _ROS_actionlib_TestRequestActionResult_h
#define _ROS_actionlib_TestRequestActionResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "actionlib/TestRequestResult.h"

namespace actionlib
{

    static const char actionlib_TestRequestActionResult_type[] PROGMEM= "actionlib/TestRequestActionResult";
    static const char actionlib_TestRequestActionResult_md5[] PROGMEM= "0476d1fdf437a3a6e7d6d0e9f5561298";
  class TestRequestActionResult : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalStatus _status_type;
      _status_type status;
      typedef actionlib::TestRequestResult _result_type;
      _result_type result;

    TestRequestActionResult():
      header(),
      status(),
      result()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->status.serialize(outbuffer + offset);
      offset += this->result.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->status.deserialize(inbuffer + offset);
      offset += this->result.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType(const char * type_msg) override { strcpy_P((char *)type_msg, (char *)actionlib_TestRequestActionResult_type);return type_msg; };
    virtual const char * getMD5(const char * md5_msg) override { strcpy_P((char *)md5_msg, (char *)actionlib_TestRequestActionResult_md5);return md5_msg; };

  };

}
#endif
