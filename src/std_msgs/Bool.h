#ifndef _ROS_std_msgs_Bool_h
#define _ROS_std_msgs_Bool_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace std_msgs
{

    static const char std_msgs_Bool_type[] PROGMEM= "std_msgs/Bool";
    static const char std_msgs_Bool_md5[] PROGMEM= "8b94c1b53db61fb6aed406028ad6332a";
  class Bool : public ros::Msg
  {
    public:
      typedef bool _data_type;
      _data_type data;

    Bool():
      data(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_data;
      u_data.real = this->data;
      *(outbuffer + offset + 0) = (u_data.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->data);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_data;
      u_data.base = 0;
      u_data.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->data = u_data.real;
      offset += sizeof(this->data);
     return offset;
    }

    virtual const char * getType(const char * type_msg) override { strcpy_P((char *)type_msg, (char *)std_msgs_Bool_type);return type_msg; };
    virtual const char * getMD5(const char * md5_msg) override { strcpy_P((char *)md5_msg, (char *)std_msgs_Bool_md5);return md5_msg; };

  };

}
#endif
