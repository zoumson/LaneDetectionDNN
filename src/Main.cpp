#include "ClassifyDetect.hpp"

int main(int argc, char const *argv[])
{

       //"{i imgInC |<none>           | input image path}"                 
   cv::String keys =
        "{o option |<none>           | 1 image classification, 2 image detection, 3 video detection}" 
        "{i imgInC |           | input image path}"        
        "{j imgOutC |../result/image/imgOutC.jpg   | output classified image}"         
        "{c classC |../ressource/txt/classification_classes_ILSVRC2012.txt   | classification classes}"       
        "{n nnPC |../ressource/txt/DenseNet_121.prototxt    | classification model}"                  
        "{e nnMC |../ressource/txt/DenseNet_121.caffemodel         | classification config}"                 
        "{m modelC |caffe                | classification framework}"        
        "{l classDI |../ressource/txt/object_detection_classes_coco.txt   | image detection classes}"       
        "{p nnPDI |../ressource/txt/frozen_inference_graph.pb    | image detection model}"                  
        "{q nnMDI |../ressource/txt/ssd_mobilenet_v2_coco_2018_03_29.pbtxt.txt        | image detection config}"                 
        "{r modelDI |TensorFlow               | image detection framework}"   
        "{v videoIn |          | input video path}"   
        "{t videoOut |../result/video/video_result.avi           | output detected video path}"                
        "{help h usage ?    |      | show help message}";      
  
    cv::CommandLineParser parser(argc, argv, keys);
    parser.about("Image Classification and Image/Video  detection");
    if (parser.has("help")) 
    {
        parser.printMessage();
        return 0;
    }
    //bool hasImagePath = parser.has("imgInC");
    int option = parser.get<int>("option"); 
    cv::String imageInputClassif = parser.get<cv::String>("imgInC"); 
    cv::String imageOutputClassif = parser.get<cv::String>("imgOutC");
    cv::String classesClassif = parser.get<cv::String>("classC"); 
    cv::String NNProtoClassif = parser.get<cv::String>("nnPC");
    cv::String NNModelClassif = parser.get<cv::String>("nnMC"); 
    cv::String modelOnlyClassif = parser.get<cv::String>("modelC"); 
    cv::String classesDI= parser.get<cv::String>("classDI"); 
    cv::String NNProtoDI = parser.get<cv::String>("nnPDI");
    cv::String NNModelDI = parser.get<cv::String>("nnMDI"); 
    cv::String modelOnlyDI = parser.get<cv::String>("modelDI"); 

    cv::String videoIn = parser.get<cv::String>("videoIn"); 
    cv::String videoOut = parser.get<cv::String>("videoOut"); 
    if (!parser.check()) 
    {
        parser.printErrors();
        return -1;
    }



switch (option)
{
case 1:
    if (!parser.has("imgInC")) 
    {
        std::cout<<"Please insert an image path\n";
        return 0;
    }
    classify(imageInputClassif.c_str(), imageOutputClassif.c_str(), 
    classesClassif.c_str(), NNProtoClassif.c_str(), 
    NNModelClassif.c_str(), modelOnlyClassif.c_str()); 
    break;
case 2:
    if (!parser.has("imgInC")) 
    {
        std::cout<<"Please insert an image path\n";
        return 0;
    }
    detectImage(imageInputClassif.c_str(), imageOutputClassif.c_str(), 
    classesDI.c_str(), NNProtoDI.c_str(), 
    NNModelDI.c_str(), modelOnlyDI.c_str());
    break;
case 3:
    if (!parser.has("videoIn")) 
    {
        std::cout<<"Please insert a video path\n";
        return 0;
    }
    detectVideo(videoIn.c_str(), videoOut.c_str(), 
    classesDI.c_str(), NNProtoDI.c_str(), 
    NNModelDI.c_str(), modelOnlyDI.c_str());
    break;
default:
std::cout <<"Please insert a choice again.\n";
    break;
}

  
    return 0;
    
}
