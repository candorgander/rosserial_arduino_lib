#ifndef _ROS_dynamic_reconfigure_DoubleParameter_h
#define _ROS_dynamic_reconfigure_DoubleParameter_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace dynamic_reconfigure
{

    static const char dynamic_reconfigure_DoubleParameter_type[] PROGMEM= "dynamic_reconfigure/DoubleParameter";
    static const char dynamic_reconfigure_DoubleParameter_md5[] PROGMEM= "d8512f27253c0f65f928a67c329cd658";
  class DoubleParameter : public ros::Msg
  {
    public:
      typedef const char* _name_type;
      _name_type name;
      typedef float _value_type;
      _value_type value;

    DoubleParameter():
      name(""),
      value(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      offset += serializeAvrFloat64(outbuffer + offset, this->value);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->value));
     return offset;
    }

    virtual const char * getType(const char * type_msg) override { strcpy_P((char *)type_msg, (char *)dynamic_reconfigure_DoubleParameter_type);return type_msg; };
    virtual const char * getMD5(const char * md5_msg) override { strcpy_P((char *)md5_msg, (char *)dynamic_reconfigure_DoubleParameter_md5);return md5_msg; };

  };

}
#endif
