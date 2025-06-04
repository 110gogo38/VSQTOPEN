#include "DlibEx.h"

bool DlibEx::init() 
{
    try
    {
        m_stDetector = get_frontal_face_detector();
        deserialize("shape_predictor_68_face_landmarks.dat") >> m_stPoseModel;
    }
    catch (serialization_error &e)
    {
        cout << "You need dlib's default face landmarking model file to run this example." << endl;
        cout << "You can get it from the following URL: " << endl;
        cout << "http://dlib.net/files/shape_predictor_68_face_landmarks.dat.bz2" << endl;
        cout << endl << e.what() << endl;
        return false;
    }
    catch (exception &e)
    {
        cout << "·¢ÉúÒì³£: " << e.what() << endl;
        system("pause");
        return false;
    }
    return true;
}

std::vector<rectangle> DlibEx::detectFaces(cv_image<bgr_pixel> &img)
{
    return m_stDetector(img);
}
