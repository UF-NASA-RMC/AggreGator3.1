// Generated by gencpp from file shared_files/IR.msg
// DO NOT EDIT!


#ifndef SHARED_FILES_MESSAGE_IR_H
#define SHARED_FILES_MESSAGE_IR_H


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
struct IR_
{
  typedef IR_<ContainerAllocator> Type;

  IR_()
    : data()  {
      data.assign(0);
  }
  IR_(const ContainerAllocator& _alloc)
    : data()  {
  (void)_alloc;
      data.assign(0);
  }



   typedef boost::array<uint8_t, 33>  _data_type;
  _data_type data;




  typedef boost::shared_ptr< ::shared_files::IR_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::shared_files::IR_<ContainerAllocator> const> ConstPtr;

}; // struct IR_

typedef ::shared_files::IR_<std::allocator<void> > IR;

typedef boost::shared_ptr< ::shared_files::IR > IRPtr;
typedef boost::shared_ptr< ::shared_files::IR const> IRConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::shared_files::IR_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::shared_files::IR_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::shared_files::IR_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::shared_files::IR_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::shared_files::IR_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::shared_files::IR_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::shared_files::IR_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::shared_files::IR_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::shared_files::IR_<ContainerAllocator> >
{
  static const char* value()
  {
    return "9070c081569179e08f21c88f64cf7bc9";
  }

  static const char* value(const ::shared_files::IR_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x9070c081569179e0ULL;
  static const uint64_t static_value2 = 0x8f21c88f64cf7bc9ULL;
};

template<class ContainerAllocator>
struct DataType< ::shared_files::IR_<ContainerAllocator> >
{
  static const char* value()
  {
    return "shared_files/IR";
  }

  static const char* value(const ::shared_files::IR_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::shared_files::IR_<ContainerAllocator> >
{
  static const char* value()
  {
    return "uint8[33] data\n\
";
  }

  static const char* value(const ::shared_files::IR_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::shared_files::IR_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.data);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct IR_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::shared_files::IR_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::shared_files::IR_<ContainerAllocator>& v)
  {
    s << indent << "data[]" << std::endl;
    for (size_t i = 0; i < v.data.size(); ++i)
    {
      s << indent << "  data[" << i << "]: ";
      Printer<uint8_t>::stream(s, indent + "  ", v.data[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // SHARED_FILES_MESSAGE_IR_H
