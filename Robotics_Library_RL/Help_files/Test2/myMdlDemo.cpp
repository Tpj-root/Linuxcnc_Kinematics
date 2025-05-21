#include <iostream>
#include <QWidget>
#include <Inventor/SoDB.h>
#include <Inventor/Qt/SoQt.h>
#include <Inventor/Qt/viewers/SoQtExaminerViewer.h>
#include <rl/sg/so/Scene.h>

int
main(int argc, char** argv)
{
	SoDB::init();
	QWidget* widget = SoQt::init(argc, argv, argv[0]);
	widget->resize(800, 600);
	rl::sg::so::Scene scene;
	scene.load("/home/cnc/Desktop/BUILD3/rl/examples/rlsg/unimation-puma560_boxes.xml");
	SoQtExaminerViewer viewer(widget, NULL, true, SoQtFullViewer::BUILD_POPUP);
	viewer.setSceneGraph(scene.root);
	viewer.setTransparencyType(SoGLRenderAction::SORTED_OBJECT_BLEND);
	viewer.show();
	SoQt::show(widget);
	SoQt::mainLoop();
	return 0;
}
///home/cnc/Desktop/BUILD3/rl/examples/rlsg/unimation-puma560_boxes.xml