#ifndef _ROS_std_msgs_Float64MultiArray_h
#define _ROS_std_msgs_Float64MultiArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/MultiArrayLayout.h"

namespace std_msgs
{

    static const char std_msgs_Float64MultiArray_type[] PROGMEM= "std_msgs/Float64MultiArray";
    static const char std_msgs_Float64MultiArray_md5[] PROGMEM= "4b7d974086d4060e7db4613a7e6c3ba4";
  class Float64MultiArray : public ros::Msg
  {
    public:
      typedef std_msgs::MultiArrayLayout _layout_type;
      _layout_type layout;
      uint32_t data_length;
      typedef float _data_type;
      _data_type st_data;
      _data_type * data;

    Float64MultiArray():
      layout(),
      data_length(0), st_data(), data(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->layout.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->data_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->data_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->data_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->data_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->data_length);
      for( uint32_t i = 0; i < data_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->data[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->layout.deserialize(inbuffer + offset);
      uint32_t data_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->data_length);
      if(data_lengthT > data_length)
        this->data = (float*)realloc(this->data, data_lengthT * sizeof(float));
      data_length = data_lengthT;
      for( uint32_t i = 0; i < data_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_data));
        memcpy( &(this->data[i]), &(this->st_data), sizeof(float));
      }
     return offset;
    }

    virtual const char * getType(const char * type_msg) override { strcpy_P((char *)type_msg, (char *)std_msgs_Float64MultiArray_type);return type_msg; };
    virtual const char * getMD5(const char * md5_msg) override { strcpy_P((char *)md5_msg, (char *)std_msgs_Float64MultiArray_md5);return md5_msg; };

  };

}
#endif
