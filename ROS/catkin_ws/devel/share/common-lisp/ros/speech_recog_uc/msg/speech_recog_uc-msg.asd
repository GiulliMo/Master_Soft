
(cl:in-package :asdf)

(defsystem "speech_recog_uc-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "DOAResult" :depends-on ("_package_DOAResult"))
    (:file "_package_DOAResult" :depends-on ("_package"))
    (:file "SpeechResult" :depends-on ("_package_SpeechResult"))
    (:file "_package_SpeechResult" :depends-on ("_package"))
  ))