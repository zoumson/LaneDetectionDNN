## Detection of object in a image/video and image classification 
(on going)
![lane_detection](https://user-images.githubusercontent.com/38358621/120438139-91f13b00-c3b3-11eb-87e2-0381ff416563.png)

<!-- TABLE OF CONTENTS -->
<details open="open">
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#file-structure">Files Structure</a>
      <ul>
        <li><a href="#folders">Folders</a></li>
        <li><a href="#entire-files-structure">Entire Files Structure</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgements">Acknowledgements</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

<!-- [![Product Name Screen Shot][product-screenshot]](https://example.com) -->

Image Classification is a fundamental task that attempts to comprehend an entire image as a whole. The goal is to classify the image by assigning it to a specific label. Typically, Image Classification refers to images in which only one object appears and is analyzed. In contrast, object detection involves both classification and localization tasks, and is used to analyze more realistic cases in which multiple objects may exist in an image.

A list of commonly used resources that I find helpful are listed in the acknowledgements.

<!--Built with -->
### Built With

<br>

* [opencv](https://opencv.org/)
* [cmake](https://cmake.org/)
* [gnu](https://www.gnu.org/)

<br>

## File Structure

### Folders

* [build/](build/): Running `cmake ..` and `make`.
* [include/](include/): c++ header files.
* [lib/](lib/): c++ custom libraries.
* [resource/](resource/): input images and video, deep neural network configuration files.
* [result/](result/): output images and video.
* [src/](src/): c++ definitions.


### Entire Files Structure 


```
.
├── build
├── CMakeLists.txt
├── include
│   └── ClassifyDetect.hpp
├── lib
├── README.md
├── ressource
│   ├── image
│   │   ├── image_1.jpg
│   │   └── image_2.jpg
│   ├── txt
│   │   ├── classification_classes_ILSVRC2012.txt
│   │   ├── DenseNet_121.caffemodel
│   │   ├── DenseNet_121.prototxt
│   │   ├── frozen_inference_graph.pb
│   │   ├── object_detection_classes_coco.txt
│   │   └── ssd_mobilenet_v2_coco_2018_03_29.pbtxt.txt
│   └── video
│       └── video_1.mp4
├── result
│   ├── image
│   │   └── imgOutC.jpg
│   └── video
│       └── video_result.avi
└── src
    ├── ClassifyDetect.cpp
    └── Main.cpp

11 directories, 16 files


```


<!-- GETTING STARTED -->
## Getting Started

This is a sample code of how you may detect a lane on a road while driving autonomous vehicle.
To get a local copy up and running follow these simple steps.

### Prerequisites

This is an example of how to list things you need to use the software and how to install them.
* cmake
  ```sh
  sudo apt-get install cmake
  ```
 * CPP standard: `CMAKE_CXX_STANDARD 17`
 * [Install](https://askubuntu.com/questions/342202/failed-to-load-module-canberra-gtk-module-but-already-installed) `gtk` and `gtk3` module to access `canberra-gtk-module` used by `opencv imshow`
 
  ```sh
  sudo apt install libcanberra-gtk-module libcanberra-gtk3-module
  ```

### Installation

1. Install first `opencv4` cpp libraries at [https://opencv.org/](https://opencv.org/)
2. Clone the repo
   ```sh
   git clone https://github.com/zoumson/LaneDetectionDNN.git
   ```
3. Go to build
   ```sh
   cd ./build
4. Clear the folder `build`
   ```sh
   rm -r *
   ```
5. Then run the cmake file to generate the makefile
   ```sh
   cmake ..
   ```
6. Finally run the makefile to generate the executable `main`
   ```sh
   make
   ```


<!-- USAGE EXAMPLES -->
### Usage
1. Command line arguments
<br>

```
Image Classification and Image/Video  detection
Usage: main [params] 

	-?, -h, --help, --usage (value:true)
		show help message
	-c, --classC (value:../ressource/txt/classification_classes_ILSVRC2012.txt)
		classification classes
	--classDI, -l (value:../ressource/txt/object_detection_classes_coco.txt)
		image detection classes
	-e, --nnMC (value:../ressource/txt/DenseNet_121.caffemodel)
		classification config
	-i, --imgInC
		input image path
	--imgOutC, -j (value:../result/image/imgOutC.jpg)
		output classified image
	-m, --modelC (value:caffe)
		classification framework
	--modelDI, -r (value:TensorFlow)
		image detection framework
	-n, --nnPC (value:../ressource/txt/DenseNet_121.prototxt)
		classification model
	--nnMDI, -q (value:../ressource/txt/ssd_mobilenet_v2_coco_2018_03_29.pbtxt.txt)
		image detection config
	--nnPDI, -p (value:../ressource/txt/frozen_inference_graph.pb)
		image detection model
	-o, --option (value:<none>)
		1 image classification, 2 image detection, 3 video detection
	-t, --videoOut (value:../result/video/video_result.avi)
		output detected video path
	-v, --videoIn
		input video path

```

<br>

2. Run an image classification with an image in `ressource/image`
```
./main -o=1 -i=../ressource/image/image_1.jpg
```

3. Run an image detection with an image  in `ressource/image`
```
./main -o=2 -i=../ressource/image/image_2.jpg
```

3. Run a video detection with a video  in `ressource/video`
```
./main -o=3 -i=../ressource/video/video_1.mp4
```
<br>


<!-- ROADMAP -->
## Roadmap

All the headers files are well docummented, read through the comments

<!-- CONTRIBUTING -->
## Contributing

Contributions are what make the open source community such an amazing place to be learn, inspire, and create. Any contributions you make are **greatly appreciated**.

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request



<!-- LICENSE -->
## License

Distributed under the MIT License. See `LICENSE` for more information.



<!-- CONTACT -->
## Contact

Adama Zouma - <!-- [@your_twitter](https://twitter.com/your_username) -->- stargue49@gmail.com

Project Link: [https://github.com/zoumson/LaneDetectionDNN](https://github.com/zoumson/LaneDetectionDNN.git)



<!-- ACKNOWLEDGEMENTS -->
## Acknowledgements
* [Google](https://www.google.com/)
* [Stack Overflow](https://stackoverflow.com/)
* [Github](https://github.com/)




<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->

[contributors-shield]: https://img.shields.io/github/contributors/othneildrew/Best-README-Template.svg?style=for-the-badge
[contributors-url]: https://github.com/othneildrew/Best-README-Template/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/othneildrew/Best-README-Template.svg?style=for-the-badge
[forks-url]: https://github.com/othneildrew/Best-README-Template/network/members
[stars-shield]: https://img.shields.io/github/stars/othneildrew/Best-README-Template.svg?style=for-the-badge
[stars-url]: https://github.com/othneildrew/Best-README-Template/stargazers
[issues-shield]: https://img.shields.io/github/issues/othneildrew/Best-README-Template.svg?style=for-the-badge
[issues-url]: https://github.com/othneildrew/Best-README-Template/issues
[license-shield]: https://img.shields.io/github/license/othneildrew/Best-README-Template.svg?style=for-the-badge
[license-url]: https://github.com/othneildrew/Best-README-Template/blob/master/LICENSE.txt
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: linkedin.com/in/adama-zouma-553bba13a
[product-screenshot]: images/screenshot.png


