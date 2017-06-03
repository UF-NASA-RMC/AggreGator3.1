; Auto-generated. Do not edit!


(cl:in-package shared_files-msg)


;//! \htmlinclude Laser.msg.html

(cl:defclass <Laser> (roslisp-msg-protocol:ros-message)
  ((data
    :reader data
    :initarg :data
    :type (cl:vector cl:fixnum)
   :initform (cl:make-array 8 :element-type 'cl:fixnum :initial-element 0)))
)

(cl:defclass Laser (<Laser>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Laser>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Laser)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name shared_files-msg:<Laser> is deprecated: use shared_files-msg:Laser instead.")))

(cl:ensure-generic-function 'data-val :lambda-list '(m))
(cl:defmethod data-val ((m <Laser>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader shared_files-msg:data-val is deprecated.  Use shared_files-msg:data instead.")
  (data m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Laser>) ostream)
  "Serializes a message object of type '<Laser>"
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) ele) ostream))
   (cl:slot-value msg 'data))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Laser>) istream)
  "Deserializes a message object of type '<Laser>"
  (cl:setf (cl:slot-value msg 'data) (cl:make-array 8))
  (cl:let ((vals (cl:slot-value msg 'data)))
    (cl:dotimes (i 8)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:aref vals i)) (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Laser>)))
  "Returns string type for a message object of type '<Laser>"
  "shared_files/Laser")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Laser)))
  "Returns string type for a message object of type 'Laser"
  "shared_files/Laser")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Laser>)))
  "Returns md5sum for a message object of type '<Laser>"
  "3b76fca2912fc273d22c6054a1e79b1d")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Laser)))
  "Returns md5sum for a message object of type 'Laser"
  "3b76fca2912fc273d22c6054a1e79b1d")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Laser>)))
  "Returns full string definition for message of type '<Laser>"
  (cl:format cl:nil "#Bigger by at least two numbers than the requested data~%uint8[8]  data~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Laser)))
  "Returns full string definition for message of type 'Laser"
  (cl:format cl:nil "#Bigger by at least two numbers than the requested data~%uint8[8]  data~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Laser>))
  (cl:+ 0
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'data) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 1)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Laser>))
  "Converts a ROS message object to a list"
  (cl:list 'Laser
    (cl:cons ':data (data msg))
))
