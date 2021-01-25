//////////////////////////////////////////////////////////////////////////////////////
/// \brief TestBenchPlugin is a Gazebo Model Plugin that creates a pipeline
///        for Gazebo and accesses the necessary shms to get target values for control.
///
/// \copyright Wandercraft
//////////////////////////////////////////////////////////////////////////////////////

#ifndef TEST_BENCH_PLUGIN
#define TEST_BENCH_PLUGIN

#include <gazebo/common/common.hh>
#include <gazebo/gazebo.hh>
#include <gazebo/physics/physics.hh>

namespace gazebo
{
    class TestBenchPlugin : public ModelPlugin
    {
    public:
        TestBenchPlugin();
        virtual ~TestBenchPlugin() = default;

        void Load(physics::ModelPtr _model, sdf::ElementPtr _sdf);

    private:
        void OnUpdate();
        physics::WorldPtr world_{nullptr};
        physics::ModelPtr model_{nullptr};
        event::ConnectionPtr updateConnection_;
    };
}

#endif
