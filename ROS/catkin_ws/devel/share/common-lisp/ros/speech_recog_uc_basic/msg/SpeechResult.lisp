; Auto-generated. Do not edit!


(cl:in-package speech_recog_uc_basic-msg)


;//! \htmlinclude SpeechResult.msg.html

(cl:defclass <SpeechResult> (roslisp-msg-protocol:ros-message)
  ((result
    :reader result
    :initarg :result
    :type cl:string
    :initform "")
   (confidence
    :reader confidence
    :initarg :confidence
    :type cl:float
    :initform 0.0))
)

(cl:defclass SpeechResult (<SpeechResult>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SpeechResult>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SpeechResult)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name speech_recog_uc_basic-msg:<SpeechResult> is deprecated: use speech_recog_uc_basic-msg:SpeechResult instead.")))

(cl:ensure-generic-function 'result-val :lambda-list '(m))
(cl:defmethod result-val ((m <SpeechResult>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader speech_recog_uc_basic-msg:result-val is deprecated.  Use speech_recog_uc_basic-msg:result instead.")
  (result m))

(cl:ensure-generic-function 'confidence-val :lambda-list '(m))
(cl:defmethod confidence-val ((m <SpeechResult>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader speech_recog_uc_basic-msg:confidence-val is deprecated.  Use speech_recog_uc_basic-msg:confidence instead.")
  (confidence m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SpeechResult>) ostream)
  "Serializes a message object of type '<SpeechResult>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'result))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'result))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'confidence))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SpeechResult>) istream)
  "Deserializes a message object of type '<SpeechResult>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'result) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'result) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'confidence) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SpeechResult>)))
  "Returns string type for a message object of type '<SpeechResult>"
  "speech_recog_uc_basic/SpeechResult")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SpeechResult)))
  "Returns string type for a message object of type 'SpeechResult"
  "speech_recog_uc_basic/SpeechResult")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SpeechResult>)))
  "Returns md5sum for a message object of type '<SpeechResult>"
  "3b397b511fdfa28d89b546a70ca93d17")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SpeechResult)))
  "Returns md5sum for a message object of type 'SpeechResult"
  "3b397b511fdfa28d89b546a70ca93d17")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SpeechResult>)))
  "Returns full string definition for message of type '<SpeechResult>"
  (cl:format cl:nil "string result~%float32 confidence~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SpeechResult)))
  "Returns full string definition for message of type 'SpeechResult"
  (cl:format cl:nil "string result~%float32 confidence~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SpeechResult>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'result))
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SpeechResult>))
  "Converts a ROS message object to a list"
  (cl:list 'SpeechResult
    (cl:cons ':result (result msg))
    (cl:cons ':confidence (confidence msg))
))
