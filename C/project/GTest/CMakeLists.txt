cmake_minimum_required(VERSION 3.20.2)

project(testrbd_NFCVehIf)

set(MODULE_INCLUDE_PATHS
    "${WS_ROOT}/rbd/pk/fca/MasterMcu/AIM/ASW/rbd_VehIf/rbd_NFCVehIf/src"
    "./mock"
    "../stub"
    "${WS_ROOT}/rbd/pk/fca/MasterMcu/AIM/ASW/rbd_VehIf/rbd_RfhmIf/inc/"
    "${WS_ROOT}/rbd/pk/fca/MasterMcu/AIM/ASW/rbd_VehIf/rbd_VSM/inc/"
    "${WS_ROOT}/rbd/pk/pf/sw/MCAL/ST_Chorus/DeviceFiles/include/"
    "${WS_ROOT}/rbd/pk/pf/sw/CDD/AnchorCom/cfg/"
    "${WS_ROOT}/rbd/pk/fca/MasterMcu/AIM/ASW/rbd_VehIf/rbd_NFCVehIf/inc/"
    "${CDS_ROOT}/SwFctGrps/util/rbdBufReader/src"
    "${CDS_ROOT}/SwFctGrps/util/rbdBufWriter/src"
    "${CDS_ROOT}/SwFctGrps/Dkm/SwUnits/rbdDeviceMgr/src"
)

set(MODULE_SRC_FILES
    "./mock/mock_rbd_NFCVehIf.c"
)

set(MODULE_TEST_FILES
    "./test_rbd_NFCVehIf.cpp"
)

add_unit_test_target(
    MODULE_NAME "rbd_NFCVehIf"
    MODULE_INCLUDES ${MODULE_INCLUDE_PATHS}
    MODULE_SRC ${MODULE_SRC_FILES}
    TEST_SRC ${MODULE_TEST_FILES}
)