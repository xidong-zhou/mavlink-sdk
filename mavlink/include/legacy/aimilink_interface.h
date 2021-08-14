#include "rclcpp/rclcpp.hpp" 
#include "mymsgs/msg/core.hpp"
#include "mymsgs/msg/gpio.hpp"
#include "mymsgs/msg/imu.hpp"
#include "mymsgs/msg/twis.hpp"
#include "mymsgs/msg/version.hpp"

Mavlink_Interface interface;

	
mymsgs::msg::Core core_pubdata;
//~ mymsgs::msg::CoreSensors coresense_pubdata;
//~ mymsgs::msg::Hardware hardware_pubdata;
//~ mymsgs::msg::ControllerInfo controlinfo_pubdata;
//~ mymsgs::msg::DockInfraRed dockin_pubdata;

//~ CoreSensors_data coresensors_data;
//~ ControllerInfo_data controlinfo_data;
//~ UniqueDeviceID_data uniqid_data;
//~ GpInput_data gpin_data;
//~ ThreeAxisGyro_data threeAG_data;

rclcpp::Node::SharedPtr nh = rclcpp::Node::make_shared("aimibot") ;    
//~ private: 
//~ Aimi::Odom odome_try;
//~ Aimi::DiffDriver diff_drive;
//~ void subscribeVelocityCommand(const geometry_msgs::msg::Twist::SharedPtr msg);

//~ rclcpp::Publisher<mymsgs::msg::Hardware>::SharedPtr version_info_publisher;
rclcpp::Publisher<mymsgs::msg::Core>::SharedPtr core_publisher;
//~ rclcpp::Publisher<mymsgs::msg::DockInfraRed>::SharedPtr dock_ir_publisher;
//~ rclcpp::Publisher<mymsgs::msg::Inertia>::SharedPtr inertia_publisher;
//~ rclcpp::Publisher<mymsgs::msg::ThreeAxisGyro>::SharedPtr raw_imu_data_publisher;


//~ rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr velocity_command_subscriber;




