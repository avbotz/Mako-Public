/** @file config.hpp
 *  @brief Vision configuration that is used in other packages as well.
 *
 *  @author David Zhang
 */
#ifndef VISION_CONFIG_HPP
#define VISION_CONFIG_HPP 

/*
 * TODO Rewrite config using parameters.
 */
enum class CameraMode { MOCK, LIVE };
enum Task { 
	NONE,
	GATE,
	GATE_ML,
	OCTAGON
};
const CameraMode CAMERA_MODE = CameraMode::LIVE;
const bool LOG = false;
const bool SIM = true;
const float HFOV = 83;
const float VFOV = 90;
const int FRONT = 0;
const int DOWN = 1;
const float FIMG_DIM[2] = { 3648, 5472 };
const float DIMG_DIM[2] = { 480, 640 };

#endif 
