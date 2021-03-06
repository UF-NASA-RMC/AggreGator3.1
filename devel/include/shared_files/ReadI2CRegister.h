// Generated by gencpp from file shared_files/ReadI2CRegister.msg
// DO NOT EDIT!


#ifndef SHARED_FILES_MESSAGE_READI2CREGISTER_H
#define SHARED_FILES_MESSAGE_READI2CREGISTER_H

#include <ros/service_traits.h>


#include <shared_files/ReadI2CRegisterRequest.h>
#include <shared_files/ReadI2CRegisterResponse.h>


namespace shared_files
{

struct ReadI2CRegister
{

typedef ReadI2CRegisterRequest Request;
typedef ReadI2CRegisterResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct ReadI2CRegister
} // namespace shared_files


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::shared_files::ReadI2CRegister > {
  static const char* value()
  {
    return "e0f881584c1cdaf6c52e091fbeb83b32";
  }

  static const char* value(const ::shared_files::ReadI2CRegister&) { return value(); }
};

template<>
struct DataType< ::shared_files::ReadI2CRegister > {
  static const char* value()
  {
    return "shared_files/ReadI2CRegister";
  }

  static const char* value(const ::shared_files::ReadI2CRegister&) { return value(); }
};


// service_traits::MD5Sum< ::shared_files::ReadI2CRegisterRequest> should match 
// service_traits::MD5Sum< ::shared_files::ReadI2CRegister > 
template<>
struct MD5Sum< ::shared_files::ReadI2CRegisterRequest>
{
  static const char* value()
  {
    return MD5Sum< ::shared_files::ReadI2CRegister >::value();
  }
  static const char* value(const ::shared_files::ReadI2CRegisterRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::shared_files::ReadI2CRegisterRequest> should match 
// service_traits::DataType< ::shared_files::ReadI2CRegister > 
template<>
struct DataType< ::shared_files::ReadI2CRegisterRequest>
{
  static const char* value()
  {
    return DataType< ::shared_files::ReadI2CRegister >::value();
  }
  static const char* value(const ::shared_files::ReadI2CRegisterRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::shared_files::ReadI2CRegisterResponse> should match 
// service_traits::MD5Sum< ::shared_files::ReadI2CRegister > 
template<>
struct MD5Sum< ::shared_files::ReadI2CRegisterResponse>
{
  static const char* value()
  {
    return MD5Sum< ::shared_files::ReadI2CRegister >::value();
  }
  static const char* value(const ::shared_files::ReadI2CRegisterResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::shared_files::ReadI2CRegisterResponse> should match 
// service_traits::DataType< ::shared_files::ReadI2CRegister > 
template<>
struct DataType< ::shared_files::ReadI2CRegisterResponse>
{
  static const char* value()
  {
    return DataType< ::shared_files::ReadI2CRegister >::value();
  }
  static const char* value(const ::shared_files::ReadI2CRegisterResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // SHARED_FILES_MESSAGE_READI2CREGISTER_H
