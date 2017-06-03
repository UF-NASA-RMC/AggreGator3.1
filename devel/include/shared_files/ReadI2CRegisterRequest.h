// Generated by gencpp from file shared_files/ReadI2CRegisterRequest.msg
// DO NOT EDIT!


#ifndef SHARED_FILES_MESSAGE_READI2CREGISTERREQUEST_H
#define SHARED_FILES_MESSAGE_READI2CREGISTERREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace shared_files
{
template <class ContainerAllocator>
struct ReadI2CRegisterRequest_
{
  typedef ReadI2CRegisterRequest_<ContainerAllocator> Type;

  ReadI2CRegisterRequest_()
    : addr(0)
    , reg(0)
    , size(0)  {
    }
  ReadI2CRegisterRequest_(const ContainerAllocator& _alloc)
    : addr(0)
    , reg(0)
    , size(0)  {
  (void)_alloc;
    }



   typedef int8_t _addr_type;
  _addr_type addr;

   typedef int8_t _reg_type;
  _reg_type reg;

   typedef int8_t _size_type;
  _size_type size;




  typedef boost::shared_ptr< ::shared_files::ReadI2CRegisterRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::shared_files::ReadI2CRegisterRequest_<ContainerAllocator> const> ConstPtr;

}; // struct ReadI2CRegisterRequest_

typedef ::shared_files::ReadI2CRegisterRequest_<std::allocator<void> > ReadI2CRegisterRequest;

typedef boost::shared_ptr< ::shared_files::ReadI2CRegisterRequest > ReadI2CRegisterRequestPtr;
typedef boost::shared_ptr< ::shared_files::ReadI2CRegisterRequest const> ReadI2CRegisterRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::shared_files::ReadI2CRegisterRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::shared_files::ReadI2CRegisterRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace shared_files

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'shared_files': ['/home/odroid/AggreGator3.1/src/shared_files/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::shared_files::ReadI2CRegisterRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::shared_files::ReadI2CRegisterRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::shared_files::ReadI2CRegisterRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::shared_files::ReadI2CRegisterRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::shared_files::ReadI2CRegisterRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::shared_files::ReadI2CRegisterRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::shared_files::ReadI2CRegisterRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "e495661742b70ca0f6f15452cef4bf47";
  }

  static const char* value(const ::shared_files::ReadI2CRegisterRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xe495661742b70ca0ULL;
  static const uint64_t static_value2 = 0xf6f15452cef4bf47ULL;
};

template<class ContainerAllocator>
struct DataType< ::shared_files::ReadI2CRegisterRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "shared_files/ReadI2CRegisterRequest";
  }

  static const char* value(const ::shared_files::ReadI2CRegisterRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::shared_files::ReadI2CRegisterRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int8 addr\n\
int8 reg\n\
int8 size\n\
";
  }

  static const char* value(const ::shared_files::ReadI2CRegisterRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::shared_files::ReadI2CRegisterRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.addr);
      stream.next(m.reg);
      stream.next(m.size);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ReadI2CRegisterRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::shared_files::ReadI2CRegisterRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::shared_files::ReadI2CRegisterRequest_<ContainerAllocator>& v)
  {
    s << indent << "addr: ";
    Printer<int8_t>::stream(s, indent + "  ", v.addr);
    s << indent << "reg: ";
    Printer<int8_t>::stream(s, indent + "  ", v.reg);
    s << indent << "size: ";
    Printer<int8_t>::stream(s, indent + "  ", v.size);
  }
};

} // namespace message_operations
} // namespace ros

#endif // SHARED_FILES_MESSAGE_READI2CREGISTERREQUEST_H
