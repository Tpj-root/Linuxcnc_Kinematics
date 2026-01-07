#include <iostream>
#include <rl/mdl/Model.h>
#include <rl/mdl/Kinematic.h>
#include <rl/mdl/UrdfFactory.h>
#include <rl/math/Transform.h>
#include <rl/math/Vector.h>
#include <rl/mdl/IcIk.h>

int main()
{
    try
    {
        // ----- Load Robot Model -----
        std::string urdfPath = "robot.urdf";   // put urdf in same folder

        rl::mdl::UrdfFactory factory;
        std::shared_ptr<rl::mdl::Model> model(factory.create(urdfPath));

        auto* kinematic = dynamic_cast<rl::mdl::Kinematic*>(model.get());
        if (!kinematic)
        {
            std::cerr << "Model is not kinematic!" << std::endl;
            return 1;
        }

        // Set initial joint position
        rl::math::Vector q(kinematic->getDof());
        q.setZero();

        // Apply to model
        kinematic->setPosition(q);
        kinematic->update();

        // ----- Forward Kinematics -----
        rl::math::Transform t = kinematic->getOperationalPosition(0);

        std::cout << "FK End-effector transform:\n" << t.matrix() << "\n";

        // ----- IK Target -----
        rl::math::Transform target = t;            // start from current end-effector
        target.translation().x() += 0.05;          // move 5 cm in X

        // ----- IK Solver -----
        rl::mdl::IcIk ik;
        ik.setModel(kinematic);
        ik.addGoal(0, target);

        rl::math::Vector qSolved(kinematic->getDof());

        bool success = ik.solve(qSolved);

        if (success)
        {
            std::cout << "\nIK Success! New joint angles:\n" << qSolved.transpose() << "\n";
        }
        else
        {
            std::cout << "\nIK Failed.\n";
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
