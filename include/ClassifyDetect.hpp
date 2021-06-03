
/*
* License plate detection
* See COPYRIGHT file at the top of the source tree.
*
* This product includes software developed by the
* STARGUE Project (http://www.stargue.org/).
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the STARGUE License Statement and
* the GNU General Public License along with this program. If not,
* see <http://www.lsstcorp.org/LegalNotices/>.
*/

/**
 * @file ClassifyDetect.hpp
 *
 * @brief Return all possible plates in a image. 
 *
 * @author Adama Zouma
 * 
 * @Contact: stargue49@gmail.com
 *
 */

#ifndef CLASSIFY_DETECT_H
#define CLASSIFY_DETECT_H

#include <iostream>
#include <fstream>
#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>
#include <opencv2/dnn/all_layers.hpp>
/* ============================================================================
 * Function Declaration
 * ============================================================================
 */

/**
 * \brief Show a detected plate on an image.
 *
 * \details The input image is processed, then if a plate is detected a rectangle is drawn around it. 
 *
 * \param showLicensePlateArgs [in] argument of the function, type is ShowLicensePlateArgs
 *
 * \return #error code, type is int
 * 
 * \see ShowLicensePlateArgs
 * 
 */
int classify(const char* imageInput, const char* imageOutput, 
const char *classes, const char *NNProto, 
const char *NNModel, const char *modelOnly);

/**
 * \brief Show a detected plate on an image.
 *
 * \details The input image is processed, then if a plate is detected a rectangle is drawn around it. 
 *
 * \param showLicensePlateArgs [in] argument of the function, type is ShowLicensePlateArgs
 *
 * \return #error code, type is int
 * 
 * \see ShowLicensePlateArgs
 * 
 */

int detectImage(const char* imageInput, const char* imageOutput, 
const char *classes, const char *NNInf ,
const char *NNCoco, const char *modelOnly); 

/**
 * \brief Show a detected plate on an image.
 *
 * \details The input image is processed, then if a plate is detected a rectangle is drawn around it. 
 *
 * \param showLicensePlateArgs [in] argument of the function, type is ShowLicensePlateArgs
 *
 * \return #error code, type is int
 * 
 * \see ShowLicensePlateArgs
 * 
 */
int detectVideo(const char* videoInput, const char* videoOutput, 
const char *classes, const char *NN, const char *modelNN, const char * modelOnly); 
#endif // CLASSIFY_DETECT_H
