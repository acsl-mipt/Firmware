/****************************************************************************
 *
 *   Copyright (c) 2016 PX4 Development Team. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name PX4 nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/**
 * Dump GPS communication to a file.
 *
 * If this is set to 1, all GPS communication data will be published via uORB,
 * and written to the log file as gps_dump message.
 * @min 0
 * @max 1
 * @value 0 Disable
 * @value 1 Enable
 * @group GPS
 */
PARAM_DEFINE_INT32(GPS_DUMP_COMM, 0);

/**
 * GPS request frequency.
 *
 * Frequency of requesting position data from GNSS receiver (actual for supplied models).
 * @min 0.01
 * @max 20.0
 * @group GPS
 */
PARAM_DEFINE_FLOAT(GPS_REQUEST_FREQ, 20.0f);

/**
 * External COM port for NovAtel GPS receiver.
 *
 * Zero-value - turn off external port.
 * @min 0
 * @max 3
 * @group GPS
 */
PARAM_DEFINE_INT32(GPS_NVTL_EXTPORT, 1);

/**
 * External COM port baudrate for NovAtel GPS receiver.
 *
 * @min 300
 * @max 230400
 * @group GPS
 */
PARAM_DEFINE_INT32(GPS_NVTL_EXTBAUD, 115200);

/**
 * External COM port request frequency for NovAtel GPS receiver.
 *
 * @min 0.01
 * @max 20.0
 * @group GPS
 */
PARAM_DEFINE_FLOAT(GPS_NVTL_EXTFREQ, 20.0f);
