// Generated by gencpp from file shared_files/Laser.msg
// DO NOT EDIT!


#ifndef SHARED_FILES_MESSAGE_LASER_H
#define SHARED_FILES_MESSAGE_LASER_H


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
struct Laser_
{
  typedef Laser_<ContainerAllocator> Type;

  Laser_()
    : data()  {
      data.assign(0);
  }
  Laser_(const ContainerAllocator& _alloc)
    : data()  {
  (void)_alloc;
      data.assign(0);
  }



   typedef boost::array<uint8_t, 8>  _data_type;
  _data_type data;




  typedef boost::shared_ptr< ::shared_files::Laser_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::shared_files::Laser_<ContainerAllocator> const> ConstPtr;

}; // struct Laser_

typedef ::shared_files::Laser_<std::allocator<void> > Laser;

typedef boost::shared_ptr< ::shared_files::Laser > LaserPtr;
typedef boost::shared_ptr< ::shared_files::Laser const> LaserConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::shared_files::Laser_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::shared_files::Laser_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::shared_files::Laser_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::shared_files::Laser_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::shared_files::Laser_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::shared_files::Laser_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::shared_files::Laser_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::shared_files::Laser_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::shared_files::Laser_<ContainerAllocator> >
{
  static const char* value()
  {
    return "3b76fca2912fc273d22c6054a1e79b1d";
  }

  static const char* value(const ::shared_files::Laser_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x3b76fca2912fc273ULL;
  static const uint64_t static_value2 = 0xd22c6054a1e79b1dULL;
};

template<class ContainerAllocator>
struct DataType< ::shared_files::Laser_<ContainerAllocator> >
{
  static const char* value()
  {
    return "shared_files/Laser";
  }

  static const char* value(const ::shared_files::Laser_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::shared_files::Laser_<ContainerAllocator> >
{
  static const char* value()
  {
    return "#Bigger by at least two numbers than the requested data\n\
uint8[8]  data\n\
";
  }

  static const char* value(const ::shared_files::Laser_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::shared_files::Laser_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.data);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Laser_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::shared_files::Laser_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::shared_files::Laser_<ContainerAllocator>& v)
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

#endif // SHARED_FILES_MESSAGE_LASER_H
