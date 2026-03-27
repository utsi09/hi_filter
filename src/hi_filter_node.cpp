#include <memory>
#include "rclcpp/rclcpp.hpp"
#include <sensor_msgs/msg/point_cloud2.hpp>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/PCLPointCloud2.h>


using namespace std;
using std::placeholders::_1;

class HiFilter : public rclcpp::Node
{
public:
    HiFilter()
    : Node("hi_filter")
    {
        subscription_ = this->create_subscription<sensor_msgs::msg::PointCloud2>(
            "/lidar_points", rclcpp::SensorDataQoS(), bind(&HiFilter::lidar_callback, this, _1)
        );
        publisher_ = this->create_publisher<sensor_msgs::msg::PointCloud2>("hi_filtered_pt",rclcpp::SensorDataQoS());

    }
private:
    void lidar_callback(const sensor_msgs::msg::PointCloud2::SharedPtr msg) const
    {
        auto cloud = std::make_shared<pcl::PointCloud<pcl::PointXYZI>>();
        pcl::fromROSMsg(*msg, *cloud);
        
        RCLCPP_INFO(this->get_logger(), "포인트 사이즈: %zu", cloud->points.size());
        size_t p_size = cloud->points.size();
        auto high_cloud = std::make_shared<pcl::PointCloud<pcl::PointXYZI>>();
        for(int i=0; i < p_size; i++){
            if(cloud->points[i].intensity > 200.0){
                high_cloud->push_back(cloud->points[i]);
            }
        }
        RCLCPP_INFO(this->get_logger(), "[가공후] 포인트 사이즈: %zu", high_cloud->points.size());
        auto hi_pt_msg = std::make_shared<sensor_msgs::msg::PointCloud2>();
        pcl::toROSMsg(*high_cloud, *hi_pt_msg);
        hi_pt_msg->header = msg->header;
        publisher_->publish(*hi_pt_msg);
    }
    rclcpp::Subscription<sensor_msgs::msg::PointCloud2>::SharedPtr subscription_;
    rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr publisher_;
};

int main(int argc, char* argv[])
{
    rclcpp::init(argc,argv);
    rclcpp::spin(make_shared<HiFilter>());
    rclcpp::shutdown();
    return 0;
}