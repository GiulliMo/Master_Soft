;; Auto-generated. Do not edit!


(when (boundp 'assistant_robin::Activate)
  (if (not (find-package "ASSISTANT_ROBIN"))
    (make-package "ASSISTANT_ROBIN"))
  (shadow 'Activate (find-package "ASSISTANT_ROBIN")))
(unless (find-package "ASSISTANT_ROBIN::ACTIVATE")
  (make-package "ASSISTANT_ROBIN::ACTIVATE"))
(unless (find-package "ASSISTANT_ROBIN::ACTIVATEREQUEST")
  (make-package "ASSISTANT_ROBIN::ACTIVATEREQUEST"))
(unless (find-package "ASSISTANT_ROBIN::ACTIVATERESPONSE")
  (make-package "ASSISTANT_ROBIN::ACTIVATERESPONSE"))

(in-package "ROS")





(defclass assistant_robin::ActivateRequest
  :super ros::object
  :slots ())

(defmethod assistant_robin::ActivateRequest
  (:init
   (&key
    )
   (send-super :init)
   self)
  (:serialization-length
   ()
   (+
    0
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;;
   self)
  )

(defclass assistant_robin::ActivateResponse
  :super ros::object
  :slots ())

(defmethod assistant_robin::ActivateResponse
  (:init
   (&key
    )
   (send-super :init)
   self)
  (:serialization-length
   ()
   (+
    0
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;;
   self)
  )

(defclass assistant_robin::Activate
  :super ros::object
  :slots ())

(setf (get assistant_robin::Activate :md5sum-) "d41d8cd98f00b204e9800998ecf8427e")
(setf (get assistant_robin::Activate :datatype-) "assistant_robin/Activate")
(setf (get assistant_robin::Activate :request) assistant_robin::ActivateRequest)
(setf (get assistant_robin::Activate :response) assistant_robin::ActivateResponse)

(defmethod assistant_robin::ActivateRequest
  (:response () (instance assistant_robin::ActivateResponse :init)))

(setf (get assistant_robin::ActivateRequest :md5sum-) "d41d8cd98f00b204e9800998ecf8427e")
(setf (get assistant_robin::ActivateRequest :datatype-) "assistant_robin/ActivateRequest")
(setf (get assistant_robin::ActivateRequest :definition-)
      "---
")

(setf (get assistant_robin::ActivateResponse :md5sum-) "d41d8cd98f00b204e9800998ecf8427e")
(setf (get assistant_robin::ActivateResponse :datatype-) "assistant_robin/ActivateResponse")
(setf (get assistant_robin::ActivateResponse :definition-)
      "---
")



(provide :assistant_robin/Activate "d41d8cd98f00b204e9800998ecf8427e")


