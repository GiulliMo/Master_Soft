; Auto-generated. Do not edit!


(cl:in-package assistant_robin-srv)


;//! \htmlinclude Activate-request.msg.html

(cl:defclass <Activate-request> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass Activate-request (<Activate-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Activate-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Activate-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name assistant_robin-srv:<Activate-request> is deprecated: use assistant_robin-srv:Activate-request instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Activate-request>) ostream)
  "Serializes a message object of type '<Activate-request>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Activate-request>) istream)
  "Deserializes a message object of type '<Activate-request>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Activate-request>)))
  "Returns string type for a service object of type '<Activate-request>"
  "assistant_robin/ActivateRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Activate-request)))
  "Returns string type for a service object of type 'Activate-request"
  "assistant_robin/ActivateRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Activate-request>)))
  "Returns md5sum for a message object of type '<Activate-request>"
  "d41d8cd98f00b204e9800998ecf8427e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Activate-request)))
  "Returns md5sum for a message object of type 'Activate-request"
  "d41d8cd98f00b204e9800998ecf8427e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Activate-request>)))
  "Returns full string definition for message of type '<Activate-request>"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Activate-request)))
  "Returns full string definition for message of type 'Activate-request"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Activate-request>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Activate-request>))
  "Converts a ROS message object to a list"
  (cl:list 'Activate-request
))
;//! \htmlinclude Activate-response.msg.html

(cl:defclass <Activate-response> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass Activate-response (<Activate-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Activate-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Activate-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name assistant_robin-srv:<Activate-response> is deprecated: use assistant_robin-srv:Activate-response instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Activate-response>) ostream)
  "Serializes a message object of type '<Activate-response>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Activate-response>) istream)
  "Deserializes a message object of type '<Activate-response>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Activate-response>)))
  "Returns string type for a service object of type '<Activate-response>"
  "assistant_robin/ActivateResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Activate-response)))
  "Returns string type for a service object of type 'Activate-response"
  "assistant_robin/ActivateResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Activate-response>)))
  "Returns md5sum for a message object of type '<Activate-response>"
  "d41d8cd98f00b204e9800998ecf8427e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Activate-response)))
  "Returns md5sum for a message object of type 'Activate-response"
  "d41d8cd98f00b204e9800998ecf8427e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Activate-response>)))
  "Returns full string definition for message of type '<Activate-response>"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Activate-response)))
  "Returns full string definition for message of type 'Activate-response"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Activate-response>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Activate-response>))
  "Converts a ROS message object to a list"
  (cl:list 'Activate-response
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'Activate)))
  'Activate-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'Activate)))
  'Activate-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Activate)))
  "Returns string type for a service object of type '<Activate>"
  "assistant_robin/Activate")