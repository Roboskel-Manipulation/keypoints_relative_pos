# keypoints_relative_pos

## Description
This package checks the relative position of the left wrist and the left shoulder keypoints and publishes a boolean value. The keypoints are expected to be the output of [openpose_3D_localization](https://github.com/Roboskel-manipulation/openpose_3D_localization).

## Functionality
The relative wrist and shoulder positions are observed within a window of 5 observations. If  the wrist position is higher than the shoulder position at least in 3 observations  the boolean value is set to false, otherwise true. If at least one of the keypoints is unavailable (wrist or shoulder out of the camera field of view, or other unforeseen reasons), the boolean is set to true.

<b> Note </b>: In the [config file](https://github.com/Roboskel-Manipulation/openpose_3D_localization/blob/main/keypoint_3d_matching/config/keypoint_3d_matching.yaml) of the [openpose_3D_localization](https://github.com/Roboskel-Manipulation/openpose_3D_localization) package, add the numbers 4, 7 in the `points_of_interest` in order for the 3D coordinates of the left wrist and shoulder to be available.
