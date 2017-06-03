; Auto-generated. Do not edit!


(cl:in-package shared_files-msg)


;//! \htmlinclude IR.msg.html

(cl:defclass <IR> (roslisp-msg-protocol:ros-message)
  ((data
    :reader data
    :initarg :data
    :type (cl:vector cl:fixnum)
   :initform (cl:make-array 33 :element-type 'cl:fixnum :initial-element 0)))
)

(cl:defclass IR (<IR>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <IR>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'IR)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name shared_files-msg:<IR> is deprecated: use shared_files-msg:IR instead.")))

(cl:ensure-generic-function 'data-val :lambda-list '(m))
(cl:defmethod data-val ((m <IR>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader shared_files-msg:data-val is deprecated.  Use shared_files-msg:data instead.")
  (data m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <IR>) ostream)
  "Serializes a message object of type '<IR>"
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) ele) ostream))
   (cl:slot-value msg 'data))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <IR>) istream)
  "Deserializes a message object of type '<IR>"
  (cl:setf (cl:slot-value msg 'data) (cl:make-array 33))
  (cl:let ((vals (cl:slot-value msg 'data)))
    (cl:dotimes (i 33)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:aref vals i)) (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<IR>)))
  "Returns string type for a message object of type '<IR>"
  "shared_files/IR")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'IR)))
  "Returns string type for a message object of type 'IR"
  "shared_files/IR")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<IR>)))
  "Returns md5sum for a message object of type '<IR>"
  "9070c081569179e08f21c88f64cf7bc9")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'IR)))
  "Returns md5sum for a message object of type 'IR"
  "9070c081569179e08f21c88f64cf7bc9")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<IR>)))
  "Returns full string definition for message of type '<IR>"
  (cl:format cl:nil "uint8[33] data~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'IR)))
  "Returns full string definition for message of type 'IR"
  (cl:format cl:nil "uint8[33] data~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <IR>))
  (cl:+ 0
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'data) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 1)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <IR>))
  "Converts a ROS message object to a list"
  (cl:list 'IR
    (cl:cons ':data (data msg))
))
