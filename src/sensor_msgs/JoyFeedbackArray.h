#ifndef _ROS_sensor_msgs_JoyFeedbackArray_h
#define _ROS_sensor_msgs_JoyFeedbackArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/JoyFeedback.h"

namespace sensor_msgs
{

    static const char sensor_msgs_JoyFeedbackArray_type[] PROGMEM= "sensor_msgs/JoyFeedbackArray";
    static const char sensor_msgs_JoyFeedbackArray_md5[] PROGMEM= "cde5730a895b1fc4dee6f91b754b213d";
  class JoyFeedbackArray : public ros::Msg
  {
    public:
      uint32_t array_length;
      typedef sensor_msgs::JoyFeedback _array_type;
      _array_type st_array;
      _array_type * array;

    JoyFeedbackArray():
      array_length(0), st_array(), array(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->array_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->array_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->array_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->array_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->array_length);
      for( uint32_t i = 0; i < array_length; i++){
      offset += this->array[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t array_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      array_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      array_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      array_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->array_length);
      if(array_lengthT > array_length)
        this->array = (sensor_msgs::JoyFeedback*)realloc(this->array, array_lengthT * sizeof(sensor_msgs::JoyFeedback));
      array_length = array_lengthT;
      for( uint32_t i = 0; i < array_length; i++){
      offset += this->st_array.deserialize(inbuffer + offset);
        memcpy( &(this->array[i]), &(this->st_array), sizeof(sensor_msgs::JoyFeedback));
      }
     return offset;
    }

    virtual const char * getType(const char * type_msg) override { strcpy_P((char *)type_msg, (char *)sensor_msgs_JoyFeedbackArray_type);return type_msg; };
    virtual const char * getMD5(const char * md5_msg) override { strcpy_P((char *)md5_msg, (char *)sensor_msgs_JoyFeedbackArray_md5);return md5_msg; };

  };

}
#endif
