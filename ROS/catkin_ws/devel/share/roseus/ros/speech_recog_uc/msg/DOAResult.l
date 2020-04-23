;; Auto-generated. Do not edit!


(when (boundp 'speech_recog_uc::DOAResult)
  (if (not (find-package "SPEECH_RECOG_UC"))
    (make-package "SPEECH_RECOG_UC"))
  (shadow 'DOAResult (find-package "SPEECH_RECOG_UC")))
(unless (find-package "SPEECH_RECOG_UC::DOARESULT")
  (make-package "SPEECH_RECOG_UC::DOARESULT"))

(in-package "ROS")
;;//! \htmlinclude DOAResult.msg.html


(defclass speech_recog_uc::DOAResult
  :super ros::object
  :slots (_angle ))

(defmethod speech_recog_uc::DOAResult
  (:init
   (&key
    ((:angle __angle) 0.0)
    )
   (send-super :init)
   (setq _angle (float __angle))
   self)
  (:angle
   (&optional __angle)
   (if __angle (setq _angle __angle)) _angle)
  (:serialization-length
   ()
   (+
    ;; float32 _angle
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _angle
       (sys::poke _angle (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _angle
     (setq _angle (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get speech_recog_uc::DOAResult :md5sum-) "2d11dcdbe5a6f73dd324353dc52315ab")
(setf (get speech_recog_uc::DOAResult :datatype-) "speech_recog_uc/DOAResult")
(setf (get speech_recog_uc::DOAResult :definition-)
      "float32 angle
")



(provide :speech_recog_uc/DOAResult "2d11dcdbe5a6f73dd324353dc52315ab")


