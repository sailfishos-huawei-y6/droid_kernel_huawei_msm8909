/* Copyright (c) 2013-2014, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef MSM_CAMERA_DT_UTIL_H__
#define MSM_CAMERA_DT_UTIL_H__

#include <soc/qcom/camera2.h>
#include <linux/gpio.h>
#include <linux/of.h>
#include "msm_camera_i2c.h"

int msm_sensor_get_sub_module_index(struct device_node *of_node,
	struct  msm_sensor_info_t **s_info);

int msm_sensor_get_dt_actuator_data(struct device_node *of_node,
	struct msm_actuator_info **act_info);

int msm_sensor_get_dt_csi_data(struct device_node *of_node,
	struct msm_camera_csi_lane_params **csi_lane_params);

int msm_camera_get_dt_power_setting_data(struct device_node *of_node,
	struct camera_vreg_t *cam_vreg, int num_vreg,
	struct msm_camera_power_ctrl_t *power_info);

int msm_camera_get_dt_gpio_req_tbl(struct device_node *of_node,
	struct msm_camera_gpio_conf *gconf, uint16_t *gpio_array,
	uint16_t gpio_array_size);

int msm_camera_get_dt_gpio_set_tbl(struct device_node *of_node,
	struct msm_camera_gpio_conf *gconf, uint16_t *gpio_array,
	uint16_t gpio_array_size);

int msm_camera_init_gpio_pin_tbl(struct device_node *of_node,
	struct msm_camera_gpio_conf *gconf, uint16_t *gpio_array,
	uint16_t gpio_array_size);

int msm_camera_get_dt_vreg_data(struct device_node *of_node,
	struct camera_vreg_t **cam_vreg, int *num_vreg);

//modified by yangze for camera cts test (qc805) 2014-01-18 begin
int msm_camera_enable_i2c_mux(struct msm_camera_i2c_conf *i2c_conf);
int msm_camera_disable_i2c_mux(struct msm_camera_i2c_conf *i2c_conf);
int msm_camera_pinctrl_init(struct msm_camera_power_ctrl_t *ctrl);
struct msm_sensor_power_setting*
msm_camera_get_power_settings(struct msm_camera_power_ctrl_t *ctrl,
	enum msm_sensor_power_seq_type_t seq_type,
	uint16_t seq_val);
//modified by yangze for camera cts test (qc805) 2014-01-18 end

int msm_camera_power_up(struct msm_camera_power_ctrl_t *ctrl,
	enum msm_camera_device_type_t device_type,
	struct msm_camera_i2c_client *sensor_i2c_client);

int msm_camera_power_down(struct msm_camera_power_ctrl_t *ctrl,
	enum msm_camera_device_type_t device_type,
	struct msm_camera_i2c_client *sensor_i2c_client);

int msm_camera_fill_vreg_params(struct camera_vreg_t *cam_vreg,
	int num_vreg, struct msm_sensor_power_setting *power_setting,
	uint16_t power_setting_size);

#endif
