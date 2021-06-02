#include "DetectImage.hpp"
#include "Classify.hpp"
#include "DetectVideo.hpp"

int main(int argc, char const *argv[])
{

         
   cv::String keys =
        "{i imgInC |<none>           | input image path}"        
        "{j imgOutC |../ressource/image/imgOutC.jpg   | output classified image}"         
        "{c classC |../ressource/txt/classification_classes_ILSVRC2012.txt   | classification classes}"       
        "{n nnPC |../ressource/txt/DenseNet_121.prototxt    | classification DensNet proto}"                  
        "{o nnMC |../ressource/txt/DenseNet_121.caffemodel         | classification DensNet model}"                 
        "{m modelC |caffe                | classification model}"                    
        "{help h usage ?    |      | show help message}";      
  
    cv::CommandLineParser parser(argc, argv, keys);
    parser.about("Image Classification and Image/Video  detection");
    if (parser.has("help")) 
    {
        parser.printMessage();
        return 0;
    }
    //bool hasImagePath = parser.has("imgInC");
    cv::String imageInputClassif = parser.get<cv::String>("imgInC"); 
    cv::String imageOutputClassif = parser.get<cv::String>("imgOutC");
    cv::String classesClassif = parser.get<cv::String>("classC"); 
    cv::String NNProtoClassif = parser.get<cv::String>("nnPC");
    cv::String NNModelClassif = parser.get<cv::String>("nnMC"); 
    cv::String modelOnlyClassif = parser.get<cv::String>("modelC"); 

    if (!parser.check()) 
    {
        parser.printErrors();
        return -1;
    }

    classify(imageInputClassif.c_str(), imageOutputClassif.c_str(), 
    classesClassif.c_str(), NNProtoClassif.c_str(), 
    NNModelClassif.c_str(), modelOnlyClassif.c_str()); 
  
    return 0;
    
}
