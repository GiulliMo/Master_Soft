;; Auto-generated. Do not edit!


(when (boundp 'speech_recog_uc_basic::SpeechResult)
  (if (not (find-package "SPEECH_RECOG_UC_BASIC"))
    (make-package "SPEECH_RECOG_UC_BASIC"))
  (shadow 'SpeechResult (find-package "SPEECH_RECOG_UC_BASIC")))
(unless (find-package "SPEECH_RECOG_UC_BASIC::SPEECHRESULT")
  (make-package "SPEECH_RECOG_UC_BASIC::SPEECHRESULT"))

(in-package "ROS")
;;//! \htmlinclude SpeechResult.msg.html


(defclass speech_recog_uc_basic::SpeechResult
  :super ros::object
  :slots (_result _confidence ))

(defmethod speech_recog_uc_basic::SpeechResult
  (:init
   (&key
    ((:result __result) "")
    ((:confidence __confidence) 0.0)
    )
   (send-super :init)
   (setq _result (string __result))
   (setq _confidence (float __confidence))
   self)
  (:result
   (&optional __result)
   (if __result (setq _result __result)) _result)
  (:confidence
   (&optional __confidence)
   (if __confidence (setq _confidence __confidence)) _confidence)
  (:serialization-length
   ()
   (+
    ;; string _result
    4 (length _result)
    ;; float32 _confidence
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _result
       (write-long (length _result) s) (princ _result s)
     ;; float32 _confidence
       (sys::poke _confidence (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _result
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _result (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; float32 _confidence
     (setq _confidence (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get speech_recog_uc_basic::SpeechResult :md5sum-) "3b397b511fdfa28d89b546a70ca93d17")
(setf (get speech_recog_uc_basic::SpeechResult :datatype-) "speech_recog_uc_basic/SpeechResult")
(setf (get speech_recog_uc_basic::SpeechResult :definition-)
      "string result
float32 confidence
")



(provide :speech_recog_uc_basic/SpeechResult "3b397b511fdfa28d89b546a70ca93d17")


