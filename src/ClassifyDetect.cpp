#include "ClassifyDetect.hpp"

using namespace std;
using namespace cv;
using namespace dnn;

int classify(const char* imageInput, const char* imageOutput, 
const char *classes, const char *NNProto, const char *NNModel, const char *modelOnly)
{

    std::vector<std::string> class_names;
    //ifstream ifs(string("../../input/classification_classes_ILSVRC2012.txt").c_str());
    ifstream ifs(classes);
    string line;
    while (getline(ifs, line))
    {
        class_names.push_back(line);
    }  
    
    // load the neural network model
    
    auto model = readNet(NNProto, NNModel, modelOnly);
    //auto model = readNet("../../input/DenseNet_121.prototxt", 
    //                    "../../input/DenseNet_121.caffemodel", 
    //                    "Caffe");   
    // load the image from disk
    Mat image = imread(imageInput);
    //Mat image = imread("../../input/image_1.jpg");

    // create blob from image
    Mat blob = blobFromImage(image, 0.01, Size(224, 224), Scalar(104, 117, 123));

    // set the input blob for the neural network
    model.setInput(blob);
    // forward pass the image blob through the model
    Mat outputs = model.forward();

    Point classIdPoint;
    double final_prob;
    minMaxLoc(outputs.reshape(1, 1), 0, &final_prob, 0, &classIdPoint);
    int label_id = classIdPoint.x;

    // Print predicted class.
    string out_text = format("%s, %.3f", (class_names[label_id].c_str()), final_prob);
    // put the class name text on top of the image
    putText(image, out_text, Point(25, 50), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 255, 0),
                2);
        
    imshow("Image", image);
    waitKey(0);
    imwrite(imageOutput, image);
    //imwrite("../../outputs/result_image.jpg", image);   
    return 0;

}

int detectImage(const char* imageInput, const char* imageOutput, 
const char *classes, const char *NNInf ,
const char *NNCoco, const char *modelOnly)
{

    std::vector<std::string> class_names;
    ifstream ifs(classes);    

    string line;
    while (getline(ifs, line))
    {
        class_names.push_back(line);
    }  
    // load the neural network model
    auto model = readNet(NNInf, NNCoco, modelOnly);
    // read the image from disk
    Mat image = imread(imageInput);  
    int image_height = image.cols;
    int image_width = image.rows;
    //create blob from image
    Mat blob = blobFromImage(image, 1.0, Size(300, 300), Scalar(127.5, 127.5, 127.5), 
                            true, false);
    //create blob from image
    model.setInput(blob);
    //forward pass through the model to carry out the detection
    Mat output = model.forward();
    Mat detectionMat(output.size[2], output.size[3], CV_32F, output.ptr<float>());

    for (int i = 0; i < detectionMat.rows; i++){
        int class_id = detectionMat.at<float>(i, 1);
        float confidence = detectionMat.at<float>(i, 2);
        
        // Check if the detection is of good quality
        if (confidence > 0.4){
            int box_x = static_cast<int>(detectionMat.at<float>(i, 3) * image.cols);
            int box_y = static_cast<int>(detectionMat.at<float>(i, 4) * image.rows);
            int box_width = static_cast<int>(detectionMat.at<float>(i, 5) * image.cols - box_x);
            int box_height = static_cast<int>(detectionMat.at<float>(i, 6) * image.rows - box_y);
            rectangle(image, Point(box_x, box_y), Point(box_x+box_width, box_y+box_height), Scalar(255,255,255), 2);
            putText(image, class_names[class_id-1].c_str(), Point(box_x, box_y-5), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0,255,255), 1);
        }
    }    

    imshow("image", image);
    imwrite(imageOutput, image);
    waitKey(0);
    destroyAllWindows();
    return 0;

}

int detectVideo(const char* videoInput, const char* videoOutput, 
const char *classes, const char *NN, 
const char *modelNN, const char *modelOnly){
//int main(int, char**) {
    std::vector<std::string> class_names;
    //ifstream ifs(string("../../../input/object_detection_classes_coco.txt").c_str());
    ifstream ifs(videoInput);
    string line;
    while (getline(ifs, line))
    {
        class_names.push_back(line);
    }  
    
    // load the neural network model
    //auto model = readNet("../../../input/frozen_inference_graph.pb", 
    //                    "../../../input/ssd_mobilenet_v2_coco_2018_03_29.pbtxt.txt", 
    //                   "TensorFlow");
    auto model = readNet(NN, modelNN, modelOnly);

    // capture the video
    VideoCapture cap(videoInput);
    //VideoCapture cap("../../../input/video_1.mp4");
    // get the video frames' width and height for proper saving of videos
    int frame_width = static_cast<int>(cap.get(3));
    int frame_height = static_cast<int>(cap.get(4));
    // create the `VideoWriter()` object
 //   VideoWriter out("../../../outputs/video_result.avi", VideoWriter::fourcc('M', 'J', 'P', 'G'), 30, 
 //                   Size(frame_width, frame_height));
    VideoWriter out(videoOutput, VideoWriter::fourcc('M', 'J', 'P', 'G'), 30, 
                    Size(frame_width, frame_height));
    while (cap.isOpened()) 
    {
        Mat image;
        bool isSuccess = cap.read(image);

        if (!isSuccess) break;
        
        int image_height = image.cols;
        int image_width = image.rows;
        //create blob from image
        Mat blob = blobFromImage(image, 1.0, Size(300, 300), Scalar(127.5, 127.5, 127.5), 
                                true, false);
        //create blob from image
        model.setInput(blob);
        //forward pass through the model to carry out the detection
        Mat output = model.forward();
        
        Mat detectionMat(output.size[2], output.size[3], CV_32F, output.ptr<float>());
        
        for (int i = 0; i < detectionMat.rows; i++)
        {
            int class_id = detectionMat.at<float>(i, 1);
            float confidence = detectionMat.at<float>(i, 2);

            // Check if the detection is of good quality
            if (confidence > 0.4){
                int box_x = static_cast<int>(detectionMat.at<float>(i, 3) * image.cols);
                int box_y = static_cast<int>(detectionMat.at<float>(i, 4) * image.rows);
                int box_width = static_cast<int>(detectionMat.at<float>(i, 5) * image.cols - box_x);
                int box_height = static_cast<int>(detectionMat.at<float>(i, 6) * image.rows - box_y);
                rectangle(image, Point(box_x, box_y), Point(box_x+box_width, box_y+box_height), Scalar(255,255,255), 2);
                putText(image, class_names[class_id-1].c_str(), Point(box_x, box_y-5), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0,255,255), 1);
            }
        }
        
        imshow("image", image);
        out.write(image);
        int k = waitKey(10);
        if (k == 113)
        {
            break;
        }
    }

cap.release();
destroyAllWindows();
return 0;
}