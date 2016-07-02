#!/bin/bash

sitl_num=$1
model=$2

sim_port=15019
mav_port=15010
mav_port2=15011
mav_port3=15012

mav_oport=15015
mav_oport2=15016
mav_oport3=15017

port_step=10

src_path=`pwd`

rc_script="posix-configs/SITL/init/rcS_multiple"
build_path=${src_path}/build_posix_sitl_default

cd $build_path/src/firmware/posix

rc_file="rcS"
n=1
while [ $n -le $sitl_num ]; do
 wrk_dir=$model$n

 mkdir -p $wrk_dir
 cd $wrk_dir

 if [ ! -f $rc_file ]; then
  mkdir -p rootfs/fs/microsd
  mkdir -p rootfs/eeprom
  touch rootfs/eeprom/parameters

  cp ${src_path}/ROMFS/px4fmu_common/mixers/quad_w.main.mix ./

  cat ${src_path}/${rc_script}_gazebo_$model |
    sed s/_SYSID_/$n/ |
    sed s/_SIMPORT_/${sim_port}/ |
    sed s/_MAVPORT_/${mav_port}/g | sed s/_MAVOPORT_/${mav_oport}/ |
    sed s/_MAVPORT2_/${mav_port2}/ | sed s/_MAVOPORT2_/${mav_oport2}/ |
    sed s/_MAVPORT3_/${mav_port3}/g | sed s/_MAVOPORT3_/${mav_oport3}/ > $rc_file
 fi

 sudo -b -u $USER ../mainapp -d $rc_file >out.log 2>err.log

 cd ../

 n=$(($n + 1))
 sim_port=$(($sim_port + $port_step))
 mav_port=$(($mav_port + $port_step))
 mav_port2=$(($mav_port2 + $port_step))
 mav_port3=$(($mav_port3 + $port_step))
 mav_oport=$(($mav_oport + $port_step))
 mav_oport2=$(($mav_oport2 + $port_step))
 mav_oport3=$(($mav_oport3 + $port_step))
done
