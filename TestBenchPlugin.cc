#include "TestBenchPlugin.h"
#include <ignition/math/Vector3.hh>

namespace gazebo
{
    using namespace ignition::math;
    TestBenchPlugin::TestBenchPlugin()
        : updateConnection_()
    {
    }

    void TestBenchPlugin::Load(physics::ModelPtr _model, sdf::ElementPtr _sdf)
    {
        (void)_sdf;
        world_ = _model->GetWorld();
        model_ = _model;
        gazebo::physics::PhysicsEnginePtr physics = world_->Physics();
        printf("[Plugin] Using Physcis Engine: %s\n", physics->GetType().c_str());

        updateConnection_ = event::Events::ConnectWorldUpdateBegin(std::bind(&TestBenchPlugin::OnUpdate, this));
    }

    void TestBenchPlugin::OnUpdate()
    {
        gazebo::physics::LinkPtr baseLink = model_->GetLink("BaseLink");
        gazebo::physics::LinkPtr armLink = model_->GetLink("ArmLink");

        baseLink->SetWorldPose(Pose3d(0, 0, 0, 0, 0, 0), true, true);
        armLink->SetWorldPose(Pose3d(0, 0.1, 2.4, 0, 0.5, 0), true, true);

        Pose3d dirty = armLink->DirtyPose();

        // printf("%f, %f, %f, %f, %f, %f\n",
        //              dirty.Pos().X(),
        //              dirty.Pos().X(),
        //              dirty.Pos().X(),
        //              dirty.Rot().Roll(),
        //              dirty.Rot().Pitch(),
        //              dirty.Rot().Yaw());
    }

    // Register this plugin with the simulator
    GZ_REGISTER_MODEL_PLUGIN(TestBenchPlugin)
} // namespace gazebo
