// Generated by gencpp from file speech_recog_uc_basic/SpeechResult.msg
// DO NOT EDIT!


#ifndef SPEECH_RECOG_UC_BASIC_MESSAGE_SPEECHRESULT_H
#define SPEECH_RECOG_UC_BASIC_MESSAGE_SPEECHRESULT_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace speech_recog_uc_basic
{
template <class ContainerAllocator>
struct SpeechResult_
{
  typedef SpeechResult_<ContainerAllocator> Type;

  SpeechResult_()
    : result()
    , confidence(0.0)  {
    }
  SpeechResult_(const ContainerAllocator& _alloc)
    : result(_alloc)
    , confidence(0.0)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _result_type;
  _result_type result;

   typedef float _confidence_type;
  _confidence_type confidence;





  typedef boost::shared_ptr< ::speech_recog_uc_basic::SpeechResult_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::speech_recog_uc_basic::SpeechResult_<ContainerAllocator> const> ConstPtr;

}; // struct SpeechResult_

typedef ::speech_recog_uc_basic::SpeechResult_<std::allocator<void> > SpeechResult;

typedef boost::shared_ptr< ::speech_recog_uc_basic::SpeechResult > SpeechResultPtr;
typedef boost::shared_ptr< ::speech_recog_uc_basic::SpeechResult const> SpeechResultConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::speech_recog_uc_basic::SpeechResult_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::speech_recog_uc_basic::SpeechResult_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace speech_recog_uc_basic

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'speech_recog_uc_basic': ['/home/alf/catkin_ws/src/speech_recog_uc/speech_recog_uc_basic/msg'], 'actionlib_msgs': ['/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::speech_recog_uc_basic::SpeechResult_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::speech_recog_uc_basic::SpeechResult_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::speech_recog_uc_basic::SpeechResult_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::speech_recog_uc_basic::SpeechResult_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::speech_recog_uc_basic::SpeechResult_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::speech_recog_uc_basic::SpeechResult_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::speech_recog_uc_basic::SpeechResult_<ContainerAllocator> >
{
  static const char* value()
  {
    return "3b397b511fdfa28d89b546a70ca93d17";
  }

  static const char* value(const ::speech_recog_uc_basic::SpeechResult_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x3b397b511fdfa28dULL;
  static const uint64_t static_value2 = 0x89b546a70ca93d17ULL;
};

template<class ContainerAllocator>
struct DataType< ::speech_recog_uc_basic::SpeechResult_<ContainerAllocator> >
{
  static const char* value()
  {
    return "speech_recog_uc_basic/SpeechResult";
  }

  static const char* value(const ::speech_recog_uc_basic::SpeechResult_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::speech_recog_uc_basic::SpeechResult_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string result\n\
float32 confidence\n\
";
  }

  static const char* value(const ::speech_recog_uc_basic::SpeechResult_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::speech_recog_uc_basic::SpeechResult_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.result);
      stream.next(m.confidence);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SpeechResult_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::speech_recog_uc_basic::SpeechResult_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::speech_recog_uc_basic::SpeechResult_<ContainerAllocator>& v)
  {
    s << indent << "result: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.result);
    s << indent << "confidence: ";
    Printer<float>::stream(s, indent + "  ", v.confidence);
  }
};

} // namespace message_operations
} // namespace ros

#endif // SPEECH_RECOG_UC_BASIC_MESSAGE_SPEECHRESULT_H
