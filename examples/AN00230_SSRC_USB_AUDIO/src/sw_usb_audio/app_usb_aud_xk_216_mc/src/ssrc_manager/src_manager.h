/*
 * src_manager.h
 *
 *  Created on: Oct 28, 2015
 *      Author: Ed
 */

#include "customdefines.h"

#ifndef SRC_MANAGER_H_
#define SRC_MANAGER_H_

#define     SSRC_N_CHANNELS                  2  //Total number of audio channels to be processed by SRC (minimum 1)

#define     SSRC_N_INSTANCES                 2  //Number of instances (each usuall run a logical core) used to process audio (minimum 1)
#define     SSRC_CHANNELS_PER_INSTANCE       (SSRC_N_CHANNELS/SSRC_N_INSTANCES)
                                                //Calcualted number of audio channels processed by each core
#define     SSRC_N_IN_SAMPLES                4  //Number of samples per channel in each block passed into SRC each call
                                                //Must be a power of 2 and minimum value is 4 (due to two /2 decimation stages)
#define     SSRC_N_OUT_IN_RATIO_MAX          5  //Max ratio between samples out:in per processing step (44.1->192 is worst case)
#define     SSRC_DITHER_SETTING              0  //Enables or disables quantisation of output with dithering to 24b
#define     SSRC_MAX_NUM_SAMPS_OUT           (SSRC_N_OUT_IN_RATIO_MAX * SSRC_N_IN_SAMPLES)
#define     SSRC_OUT_BUFF_SIZE               (SSRC_MAX_NUM_SAMPS_OUT * 8) //Size of FIFO on output of SSRC


void src_manager(chanend c_host, chanend c_i2s, chanend c_i2s_sampfreq);

#endif /* SRC_MANAGER_H_ */
