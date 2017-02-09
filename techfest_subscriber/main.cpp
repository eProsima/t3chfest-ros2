#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

void chatter_callback(const std_msgs::msg::String::SharedPtr msg)
{
  printf("> I heard: [%s]\n", msg->data.c_str());
}

int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);
  auto node = rclcpp::node::Node::make_shared("listener_node");
  auto subscription = node->create_subscription<std_msgs::msg::String>
      ("topic", chatter_callback);
  rclcpp::spin(node);
  return 0;
}
