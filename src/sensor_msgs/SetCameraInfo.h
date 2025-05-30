#ifndef _ROS_SERVICE_SetCameraInfo_h
#define _ROS_SERVICE_SetCameraInfo_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/CameraInfo.h"

namespace sensor_msgs
{

static const char SETCAMERAINFO[] PROGMEM= "sensor_msgs/SetCameraInfo";

    static const char sensor_msgs_SetCameraInfoRequest_type[] PROGMEM= "sensor_msgs/SetCameraInfoRequest";
    static const char sensor_msgs_SetCameraInfoRequest_md5[] PROGMEM= "ee34be01fdeee563d0d99cd594d5581d";
  class SetCameraInfoRequest : public ros::Msg
  {
    public:
      typedef sensor_msgs::CameraInfo _camera_info_type;
      _camera_info_type camera_info;

    SetCameraInfoRequest():
      camera_info()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->camera_info.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->camera_info.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType(const char * type_msg) override { strcpy_P((char *)type_msg, (char *)SETCAMERAINFO);return type_msg; };
    virtual const char * getMD5(const char * md5_msg) override { strcpy_P((char *)md5_msg, (char *)sensor_msgs_SetCameraInfoRequest_md5);return md5_msg; };

  };

    static const char sensor_msgs_SetCameraInfoResponse_type[] PROGMEM= "sensor_msgs/SetCameraInfoResponse";
    static const char sensor_msgs_SetCameraInfoResponse_md5[] PROGMEM= "2ec6f3eff0161f4257b808b12bc830c2";
  class SetCameraInfoResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;
      typedef const char* _status_message_type;
      _status_message_type status_message;

    SetCameraInfoResponse():
      success(0),
      status_message("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      uint32_t length_status_message = strlen(this->status_message);
      varToArr(outbuffer + offset, length_status_message);
      offset += 4;
      memcpy(outbuffer + offset, this->status_message, length_status_message);
      offset += length_status_message;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
      uint32_t length_status_message;
      arrToVar(length_status_message, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_status_message; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_status_message-1]=0;
      this->status_message = (char *)(inbuffer + offset-1);
      offset += length_status_message;
     return offset;
    }

    virtual const char * getType(const char * type_msg) override { strcpy_P((char *)type_msg, (char *)SETCAMERAINFO);return type_msg; };
    virtual const char * getMD5(const char * md5_msg) override { strcpy_P((char *)md5_msg, (char *)sensor_msgs_SetCameraInfoResponse_md5);return md5_msg; };

  };

  class SetCameraInfo {
    public:
    typedef SetCameraInfoRequest Request;
    typedef SetCameraInfoResponse Response;
  };

}
#endif
