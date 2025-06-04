#pragma once

#include <dlib/opencv.h>
#include <opencv2/highgui/highgui.hpp>
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/image_processing/render_face_detections.h>
#include <dlib/image_processing.h>
#include <dlib/gui_widgets.h>

using namespace dlib;
using namespace std;

class DlibEx
{
public:
		DlibEx() {};
		~DlibEx() {};

		bool init();
		std::vector<rectangle>detectFaces(cv_image<bgr_pixel> &img);

private:
	frontal_face_detector m_stDetector;
	shape_predictor m_stPoseModel;
};

