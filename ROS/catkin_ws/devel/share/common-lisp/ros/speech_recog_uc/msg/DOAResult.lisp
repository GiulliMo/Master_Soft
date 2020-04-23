; Auto-generated. Do not edit!


(cl:in-package speech_recog_uc-msg)


;//! \htmlinclude DOAResult.msg.html

(cl:defclass <DOAResult> (roslisp-msg-protocol:ros-message)
  ((angle
    :reader angle
    :initarg :angle
    :type cl:float
    :initform 0.0))
)

(cl:defclass DOAResult (<DOAResult>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <DOAResult>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'DOAResult)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name speech_recog_uc-msg:<DOAResult> is deprecated: use speech_recog_uc-msg:DOAResult instead.")))

(cl:ensure-generic-function 'angle-val :lambda-list '(m))
(cl:defmethod angle-val ((m <DOAResult>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader speech_recog_uc-msg:angle-val is deprecated.  Use speech_recog_uc-msg:angle instead.")
  (angle m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <DOAResult>) ostream)
  "Serializes a message object of type '<DOAResult>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'angle))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <DOAResult>) istream)
  "Deserializes a message object of type '<DOAResult>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'angle) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<DOAResult>)))
  "Returns string type for a message object of type '<DOAResult>"
  "speech_recog_uc/DOAResult")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'DOAResult)))
  "Returns string type for a message object of type 'DOAResult"
  "speech_recog_uc/DOAResult")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<DOAResult>)))
  "Returns md5sum for a message object of type '<DOAResult>"
  "2d11dcdbe5a6f73dd324353dc52315ab")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'DOAResult)))
  "Returns md5sum for a message object of type 'DOAResult"
  "2d11dcdbe5a6f73dd324353dc52315ab")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<DOAResult>)))
  "Returns full string definition for message of type '<DOAResult>"
  (cl:format cl:nil "float32 angle~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'DOAResult)))
  "Returns full string definition for message of type 'DOAResult"
  (cl:format cl:nil "float32 angle~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <DOAResult>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <DOAResult>))
  "Converts a ROS message object to a list"
  (cl:list 'DOAResult
    (cl:cons ':angle (angle msg))
))
