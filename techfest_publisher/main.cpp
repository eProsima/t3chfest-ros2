#include <iostream>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"


int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    auto node = rclcpp::node::Node::make_shared("talker_node");
    auto publisher = node->create_publisher<std_msgs::msg::String>("topic");
    auto message = std::make_shared<std_msgs::msg::String>();
    auto publish_count = 0;
    while (rclcpp::ok()) {
        message->data = "Hello, world! " + std::to_string(publish_count++);
        printf("> Publishing: [%s]\n", message->data.c_str());
        publisher->publish(message);
        rclcpp::spin_some(node);
        rclcpp::utilities::sleep_for(std::chrono::milliseconds(500));
    }
    return 0;
}
