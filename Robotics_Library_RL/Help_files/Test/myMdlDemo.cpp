#include <iostream>
#include <rl/math/Transform.h>
#include <rl/math/Unit.h>
#include <rl/mdl/Kinematic.h>
#include <rl/mdl/Model.h>
#include <rl/mdl/XmlFactory.h>

int
main(int argc, char** argv)
{
	rl::mdl::XmlFactory factory;
	std::shared_ptr<rl::mdl::Model> model(factory.create("/home/cnc/Desktop/BUILD3/rl/examples/rlmdl/unimation-puma560.xml"));
	rl::mdl::Kinematic* kinematics = dynamic_cast<rl::mdl::Kinematic*>(model.get());
	rl::math::Vector q(6);
	q << 10, 10, -20, 30, 50, -10;
	q *= rl::math::DEG2RAD;
	kinematics->setPosition(q);
	kinematics->forwardPosition();
	rl::math::Transform t = kinematics->getOperationalPosition(0);
	rl::math::Vector3 position = t.translation();
	rl::math::Vector3 orientation = t.rotation().eulerAngles(2, 1, 0).reverse();
	std::cout << "Joint configuration in degrees: " << q.transpose() * rl::math::RAD2DEG << std::endl;
	std::cout << "End-effector position: [m] " << position.transpose() << " orientation [deg] " << orientation.transpose() * rl::math::RAD2DEG << std::endl;
	return 0;
}
///home/cnc/Desktop/BUILD3/rl/examples/rlsg/unimation-puma560_boxes.xml