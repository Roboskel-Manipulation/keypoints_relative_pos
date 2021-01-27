# keypoints_relative_pos

## Description
This package checks the relative position of the left wrist and the left shoulder keypoints and publishes a boolean value. The keypoints are expected to be the output of [openpose_3D_localization](https://github.com/Roboskel-manipulation/openpose_3D_localization).

## Functionality
For each pair of left wrist and shoulder keypoints their relative position along the z-axis is computed (difference of the z coordinates). A history of the last 10 relative positions is stored and if the number of negative relative positions is greater than 3 then the boolean value is set to `false`, otherwise `true`. If at least one of the keypoints is unavailable (wrist or shoulder is out of the camera field of view or for other unforeseen reasons), the boolean is set to `true`. 
