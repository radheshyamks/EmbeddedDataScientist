//----------------------------------------------------------------------------
// COPYRIGHT RESERVED, 2022 Robert Bosch (Australia) Pty Ltd.
// All rights reserved.  The reproduction, distribution and utilisation of
// this document as well as the communication of its contents to others
// without explicit authorisation is prohibited.  Offenders will be held liable
// for the payment of damages.  All rights reserved in the event of the grant
// of a patent, utility model or design.
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
//! \file
//! \brief  Unit Test file for the rbd_NFCVehIf module.
//!
//----------------------------------------------------------------------------

#include "gtest/gtest.h"
#include "gmock/gmock.h"

// Unit under test
extern "C"
{
#include "mock_rbd_NFCVehIf.h"
}
nfcTagTableType dummy_rbd_NFCVehIf_Table_as[10];
rbdSessionMgr_Status_et rbdSessionMgr_GetKeyRefByNfcReaderId_custom_fake(const rbdPk_NfcReaderId_t nfcReaderId, uint8* const keyRef)
{
    *(nfcTagTableType*)keyRef = dummy_rbd_NFCVehIf_Table_as[0];
    return rbdSessionMgr_GetKeyRefByNfcReaderId_fake.return_val;
}
uint8 dummy_FLDHM_NFCResponse_au8[NFC_MAX_MESSAGE_LEN];
Std_ReturnType dummy_return;
uint16 dummy_responseLength_u16;
FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_rbd_NFCVehIf_NFC_READER_FLDHM_RES_Sig_NFC_READER_FLDHM_DEVICE_Sig_custom_fake(P2VAR(uint8, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR) data, P2VAR(uint16, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR) length)
{
    for(uint16 i = 0; i <= 6; i++){
    data[i] = dummy_FLDHM_NFCResponse_au8[i];}
    *length = dummy_responseLength_u16;

    return dummy_return;
}
Std_ReturnType dummy_data1;
uint16 dummy_length;
uint16 dummy_FRDHM_NFCResponse_au8[300];
FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_rbd_NFCVehIf_NFC_READER_FRDHM_RES_Sig_NFC_READER_FRDHM_DEVICE_Sig_custom_fake(P2VAR(uint8, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR) data, P2VAR(uint16, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR) length)
{
    *(uint16*)data = dummy_FRDHM_NFCResponse_au8[0];
    *length = dummy_length;
    return dummy_data1;
}
Std_ReturnType dummy_data2;
uint16 dummy_length1;
uint16 dummy1_FRDHM_NFCResponse_au8[300];
FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_rbd_NFCVehIf_NFC_READER_WCPM2_RES_Sig_NFC_READER_WCPM2_DEVICE_Sig_custom_fake(P2VAR(uint8, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR) data, P2VAR(uint16, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR) length)
{

    *(uint16*)data = dummy1_FRDHM_NFCResponse_au8[0];
    *length = dummy_length1;
    return dummy_data2;
}
uint16 dummy_devMgr_OpStatus_u16;
FUNC(Std_ReturnType, RTE_RBDDKMRTEWRAPPER_APPL_CODE) Dkm_DeviceMgr_GetStatus_Operation_custom_fake(P2VAR(uint16, AUTOMATIC, RTE_RBDDKMRTEWRAPPER_APPL_VAR) ptrSeErrCode)
{
    *ptrSeErrCode=dummy_devMgr_OpStatus_u16;
    return Dkm_DeviceMgr_GetStatus_Operation_fake.return_val;
}
uint8 dummy_RefreshedDevKeyListCount_u8;
FUNC(Std_ReturnType, RTE_RBDDKMRTEWRAPPER_APPL_CODE) Dkm_GetNumberOfKeyEntries_Operation_custom_fake(rbdCdsTypes_DeviceType_en DeviceType, P2VAR(uint8, AUTOMATIC, RTE_RBDDKMRTEWRAPPER_APPL_VAR) ptrResultTable, uint32 ResultTableLength, P2VAR(uint8, AUTOMATIC, RTE_RBDDKMRTEWRAPPER_APPL_VAR) ptrkeycount)
{
    *ptrkeycount = dummy_RefreshedDevKeyListCount_u8;
    return Dkm_GetNumberOfKeyEntries_Operation_fake.return_val;
}
drmServices_Type dummy_dataType;
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_rbd_NFCVehIf_RP_drmServices_drmServices_custom_fake(P2VAR(drmServices_Type, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR) data)
{
	*data=dummy_dataType;
    return Rte_Read_rbd_NFCVehIf_RP_drmServices_drmServices_fake.return_val;
}
VAR(uint8, RTE_VAR_INIT) Rte_rbd_NFCVehIf_PP_Nfc_Count_Devices;
VAR(boolean, RTE_VAR_INIT) Rte_rbd_NFCVehIf_PP_CanRequest_DkmNfc_ComRequest;
VAR(DoorLockLastElSts, RTE_VAR_INIT) Rte_rbd_VSM_PP_DoorStatus_DoorLockLastElSts;
VAR(uint64, RTE_VAR_INIT) Rte_rbd_VSM_PP_InternalUtcTimestamp_De_rbd_VSM_PP_InternalUtcTimestamp;
VAR(boolean, RTE_VAR_INIT) Rte_rbd_VSM_PP_InternalUtcTimestampValid_De_rbd_VSM_PP_InternalUtcTimestampValid;
VAR(uint8, RTE_VAR_DEFAULT_RTE_App_CoreA_PIM_GROUP) Rte_rbd_NFCVehIf_FailedAttemptsCounter_MirrorBlock;
VAR(uint64, RTE_VAR_INIT) Rte_rbd_VSM_PP_AuthenticTimeManagementStatus_UtcTime;
VAR(boolean, RTE_VAR_INIT) Rte_rbd_VSM_PP_AuthenticTimeManagementStatus_UtcTimeValid;
VAR(uint8, RTE_VAR_DEFAULT_RTE_App_CoreA_PIM_GROUP) Rte_rbd_NFCVehIf_rbd_NFCVehIf_WCMP_FailedAttempts_Counter_MirrorBlock;
Rte_Calprm_rbd_NFCVehIf_DEFAULT_RTE_CDATA_GROUP_Type dummy_RteParameterRefTab;
VAR(Rte_ParameterRefTabType, RTE_VAR_INIT_NOCACHE) RteParameterRefTab = {0};
mock_nfcReaderResponseHeader_t nfcReaderHdr;
uint8 proxiPhoneAsAKey_u8  =TRUE;
class Testrbd_NFCVehIf : public testing::Test
{
public:
    void SetUp() override
    {
        RESET_FAKE(rbdSessionMgr_NfcDisconnected);
        RESET_FAKE(rbdSessionMgr_GetCardPairingReqResult);
        RESET_FAKE(rbdSessionMgr_initCardPairingTest);
        RESET_FAKE(Rte_Receive_rbd_NFCVehIf_NFC_READER_FLDHM_RES_Sig_NFC_READER_FLDHM_DEVICE_Sig);
        RESET_FAKE(rbdSessionMgr_ProcessNfcMsg);
        RESET_FAKE(rbd_RfhmIf_SendNfcToggleReq);
        RESET_FAKE(rbdSessionMgr_NfcReady);
        RESET_FAKE(rbdSessionMgr_GetDkAccessProfile);
        RESET_FAKE(rbdSessionMgr_GetKeyRefByNfcReaderId);
        RESET_FAKE(rbdSessionMgr_NfcConnected);
        RESET_FAKE(Rte_Send_rbd_NFCVehIf_NFC_READER_REQ_FLDHM_Sig_NFC_READER_DEVICE_2_Sig);
        RESET_FAKE(Rte_Send_rbd_NFCVehIf_NFC_READER_REQ_FRDHM_Sig_NFC_READER_DEVICE_3_Sig);
        RESET_FAKE(Rte_Send_rbd_NFCVehIf_NFC_READER_REQ_WCPM2_Sig_NFC_READER_DEVICE_1_Sig);
        RESET_FAKE(rbdSessionMgr_startNFCCardPairing);
        RESET_FAKE(rbdSessionMgr_ProvisionCert_Async);
        RESET_FAKE(Rte_Receive_rbd_NFCVehIf_NFC_READER_FRDHM_RES_Sig_NFC_READER_FRDHM_DEVICE_Sig);
        RESET_FAKE(Rte_Receive_rbd_NFCVehIf_NFC_READER_WCPM2_RES_Sig_NFC_READER_WCPM2_DEVICE_Sig);
        RESET_FAKE(Rte_Write_rbd_NFCVehIf_rbd_NFCVehIf_NFC_PhoneKeyPariring_Result_NFCPhoneKeyPariring_Result);
        RESET_FAKE(Com_ReceiveSignal);
        RESET_FAKE(rbd_RfhmIf_ControlFd9Bus);
        RESET_FAKE(Dkm_NfcFlow_Start);
        RESET_FAKE(Dkm_GetKeyInfoDevice_Operation);
        RESET_FAKE(NvM_WriteBlock);
        RESET_FAKE(rbd_RfhmIf_ControlFd1Bus);
        RESET_FAKE(Dkm_GetNumberOfKeyEntries_Operation);
        RESET_FAKE(Dkm_GetKeyInfoCard_Operation);
        RESET_FAKE(rbdDeviceMgr_GetStatus);
        RESET_FAKE(rbd_VSM_WcpKeyAuthResult_Cbk);
        RESET_FAKE(Rte_Read_rbd_NFCVehIf_RP_AuthenticTimeManagementStatus_UtcTime);
        RESET_FAKE(rbd_BackendIf_BackendKeyStatusUpdate_Cbk);
        RESET_FAKE(Dem_SetEventStatus);
        RESET_FAKE(Rte_Read_rbd_NFCVehIf_RP_drmServices_drmServices);

        FFF_RESET_HISTORY();
        RteParameterRefTab[Rte_CalprmElementGroup_rbd_NFCVehIf_DEFAULT_RTE_CDATA_GROUP]=&dummy_RteParameterRefTab;

    }

    void TearDown() override
    {
    }
};

//----------------------------------------------------------------------------
// Test Cases// FUNC(void, rbd_NFCVehIf_CODE) rbd_NFCVehIf_Cyclic(void)
//----------------------------------------------------------------------------
/*
@rst
    Brief description of test case.
    :BASELINE: c5ee5bdfdbb0fe2f0597fe83c7b18d4bd9be4777 [c5ee5bd]
    :Description: rbd_NFCVehIf_NfcCardTimer_u16 =(rbd_NFCVehIf_NfcCardTimer_u16 >= (uint16)NFC_CYCLE_TIME ) ? ( rbd_NFCVehIf_NfcCardTimer_u16 - NFC_CYCLE_TIME ) : 0u ==> FALSE
        rbd_NFCVehIf_PollingTimeoutTimer_u16 = (rbd_NFCVehIf_PollingTimeoutTimer_u16 >= (uint16)NFC_CYCLE_TIME ) ? ( rbd_NFCVehIf_PollingTimeoutTimer_u16 - NFC_CYCLE_TIME ) : 0u ==> FALSE
        if(TRUE == rbd_NFCVehIf_IsDeselectRetryTmr_Expired()) ==> FALSE
        if(rbd_NFCVehIf_DTCWCMP2Timer_active_b == TRUE) ==> FALSE
    :Arch ID: 0b18d96b-042f-478f-ba56-cd3caf41e637
    :REQ ID: NA
    :ALM Task ID: 288528
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_Deselect_TxManager_Cyclic()
    :Description: if((0x00U == rbd_NFCVehIf_DeselectInfo_S.retryTimer_u32) && (rbd_NFCVehIf_DeselectInfo_S.reqRetryCount_u8 > 0x00u)) ==> FALSE MCDC(TF)
        if(rbd_NFCVehIf_DeselectInfo_S.retryTimer_u32 > 0x00u) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 286698
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NfcIf_NfcTapThread()
    :Description: if(((uint8)NFC_READER_TAP_ENTRY_CARD_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
        else if(((uint8)NFC_READER_TAP_ENTRY_DEVICE_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8))  ==> FALSE MCDC (FX)
        else if(((uint8)NFC_READER_TAP_ENTRY_DEVICE_INFO_WAIT_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
        else if(((uint8)NFC_READER_TAP_ENTRY_TOGGLE_RSP_WAIT_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
        else if((((uint8)NFC_READER_TAP_ENTRY_CARD_AUTH_FAILED_STATE_E == session_state_u8) || ((uint8)NFC_READER_TAP_ENTRY_DEVICE_AUTH_FAILED_STATE_E == session_state_u8)) ==> FALSE MCDC (FF)
        if(((uint8)NFC_READER_TAP_START_CARD_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
        else if(((uint8)NFC_READER_TAP_START_DEVICE_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
        else if(((uint8)NFC_READER_TAP_START_DEVICE_INFO_WAIT_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
        else if((((uint8)NFC_READER_TAP_START_CARD_AUTH_FAILED_STATE_E == session_state_u8) || ((uint8)NFC_READER_TAP_START_DEVICE_AUTH_FAILED_STATE_E == session_state_u8)) ==> FALSE MCDC (FF)
        else if (((uint8)NFC_READER_PHONE_ENABLE_DISABLE_WCP_AUTH_FINISH_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC(FX)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 309599
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_NFCReaderSessionTimeOutManager()
    :Description: for ( NfcReaderId_u8 = 0u; NfcReaderId_u8 < NFC_NUM_READERS; NfcReaderId_u8++ ) ==> TRUE,FALSE
        if ( READER_IN_SESSION == rbd_NFCVehIf_Table_as[NfcReaderId_u8].connectionStatus_u8 ) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    rbd_NFCVehIf_CardPairingRoutine_Cyclic:
    :Description: switch ( rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_PLANT_PAIRING_E].DiagRoutine_State_en )
        case NFC_DIAG_ROUTINE_INIT_STATE_E:
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 309599
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    rbd_NFCVehIf_TestCardPairingRoutine_Cyclic:
    :Description: switch ( rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_TEST_CARD_PAIRING_E].DiagRoutine_State_en )
        case NFC_DIAG_ROUTINE_INIT_STATE_E:
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 309599
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    rbd_NFCVehIf_GetUIDRoutine_Cyclic:
    :Description: switch ( rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_GET_UID_E].DiagRoutine_State_en )
        case NFC_DIAG_ROUTINE_INIT_STATE_E:
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 309599
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_IsDeselectRetryTmr_Expired()
    :Description: Verifying for the function rbd_NFCVehIf_IsDeselectRetryTmr_Expired()
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 309599
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NfcIf_TapStartTriggerCyclic()
    :Description: if ( ((uint8)NFC_READER_TAP_START_RFHM_TRIGGER_RX_STATE_E) == session_state_u8 ) ==> FALSE
    rbd_NFCVehIf_TapStartPollingTimeoutTimer_u16 = ( rbd_NFCVehIf_TapStartPollingTimeoutTimer_u16 >= (uint16)NFC_CYCLE_TIME ) ? ( rbd_NFCVehIf_TapStartPollingTimeoutTimer_u16 - NFC_CYCLE_TIME ) : 0u ==> FALSE
        if ( rbd_NFCVehIf_TapStartPollingTimeoutTimer_u16 > 0x00u ) ==> FALSE
        if ( ( READER_IN_SESSION == readerConnection_state_u8 ) && ( ((uint8)NFC_READER_TAP_START_FLOW_INIT_STATE_E) == session_state_u8 ) ) ==> FALSE MCDC(FX)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 288528
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
@endrst
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_Cyclic_01)
{
    get_rbd_NFCVehIf_DeselectInfo_S()->mock_uRetryFinish_u8 = FALSE;
    *get_rbd_NFCVehIf_NfcCardTimer_u16() = 0;
    *get_rbd_NFCVehIf_PollingTimeoutTimer_u16() = 0;
    get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8  = 255;
    get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b  = 255;
    get_rbd_NFCVehIf_Table_as()[2].activeState_u8  = NFC_TEARDOWN_PAYLOAD_LEN;
    get_rbd_NFCVehIf_Table_as()[2].session_timeout_u16=255;
    *get_rbd_NFCVehIf_DTCWCMP2Timer_active_b() = FALSE;
    *get_rbd_NFCVehIf_TapStartPollingTimeoutTimer_u16() = 0;

    call_rbd_NFCVehIf_Cyclic();
    // Do Nothing
}
/*
@rst
    Brief description of test case.
    :Description: rbd_NFCVehIf_NfcCardTimer_u16 = ( rbd_NFCVehIf_NfcCardTimer_u16 >= (uint16)NFC_CYCLE_TIME ) ? ( rbd_NFCVehIf_NfcCardTimer_u16 - NFC_CYCLE_TIME ) : 0u ==> TRUE
        rbd_NFCVehIf_PollingTimeoutTimer_u16 = (rbd_NFCVehIf_PollingTimeoutTimer_u16 >= (uint16)NFC_CYCLE_TIME ) ? ( rbd_NFCVehIf_PollingTimeoutTimer_u16 - NFC_CYCLE_TIME ) : 0u ==> FALSE
        if(TRUE == rbd_NFCVehIf_IsDeselectRetryTmr_Expired()) ==> TRUE
        if(READER_IN_SESSION == wcpmReaderConnection_state_u8) ==> TRUE
        if(READER_IN_SESSION == fldhmReaderConnection_state_u8) ==> TRUE
        if(rbd_NFCVehIf_DTCWCMP2Timer_active_b == TRUE) ==> TRUE
        if((uint8)0 >= rbd_NFCVehIf_DTCWCPMTimer_u16) ==> FALSE
    :Arch ID: 0b18d96b-042f-478f-ba56-cd3caf41e637
    :REQ ID: NA
    :ALM Task ID: 309599
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NfcIf_NfcTapThread()
    :Description: if(((uint8)NFC_READER_TAP_ENTRY_CARD_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
        else if(((uint8)NFC_READER_TAP_ENTRY_DEVICE_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8))  ==> FALSE MCDC (FX)
        else if(((uint8)NFC_READER_TAP_ENTRY_DEVICE_INFO_WAIT_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
        else if(((uint8)NFC_READER_TAP_ENTRY_TOGGLE_RSP_WAIT_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
        else if((((uint8)NFC_READER_TAP_ENTRY_CARD_AUTH_FAILED_STATE_E == session_state_u8) || ((uint8)NFC_READER_TAP_ENTRY_DEVICE_AUTH_FAILED_STATE_E == session_state_u8)) ==> FALSE MCDC (FF)
        if(((uint8)NFC_READER_TAP_START_CARD_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
        else if(((uint8)NFC_READER_TAP_START_DEVICE_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
        else if(((uint8)NFC_READER_TAP_START_DEVICE_INFO_WAIT_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
        else if((((uint8)NFC_READER_TAP_START_CARD_AUTH_FAILED_STATE_E == session_state_u8) || ((uint8)NFC_READER_TAP_START_DEVICE_AUTH_FAILED_STATE_E == session_state_u8)) ==> FALSE MCDC (FF)
        else if (((uint8)NFC_READER_PHONE_ENABLE_DISABLE_WCP_AUTH_FINISH_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC(FX)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 309599
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_Deselect_TxManager_Cyclic()
    :Description: if((0x00U == rbd_NFCVehIf_DeselectInfo_S.retryTimer_u32) && (rbd_NFCVehIf_DeselectInfo_S.reqRetryCount_u8 > 0x00u)) ==> TRUE MCDC(TT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 309599
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_NFCReaderSessionTimeOutManager()
    :Description: for ( NfcReaderId_u8 = 0u; NfcReaderId_u8 < NFC_NUM_READERS; NfcReaderId_u8++ ) ==> TRUE,FALSE
        if ( READER_IN_SESSION == rbd_NFCVehIf_Table_as[NfcReaderId_u8].connectionStatus_u8 ) ==> TRUE
        rbd_NFCVehIf_Table_as[NfcReaderId_u8].session_timeout_u16 = (rbd_NFCVehIf_Table_as[NfcReaderId_u8].session_timeout_u16 != 0u ) ? ( rbd_NFCVehIf_Table_as[NfcReaderId_u8].session_timeout_u16 - (uint16)1u ) : (uint16)0u; ==> TRUE
        if(0u == rbd_NFCVehIf_Table_as[NfcReaderId_u8].session_timeout_u16) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 309599
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    rbd_NFCVehIf_CardPairingRoutine_Cyclic:
    :Description: switch ( rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_PLANT_PAIRING_E].DiagRoutine_State_en )
        case NFC_DIAG_ROUTINE_INIT_STATE_E:
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 309599
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    rbd_NFCVehIf_TestCardPairingRoutine_Cyclic:
    :Description: switch ( rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_TEST_CARD_PAIRING_E].DiagRoutine_State_en )
        case NFC_DIAG_ROUTINE_INIT_STATE_E:
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 309599
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    rbd_NFCVehIf_GetUIDRoutine_Cyclic:
    :Description: switch ( rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_GET_UID_E].DiagRoutine_State_en )
        case NFC_DIAG_ROUTINE_INIT_STATE_E:
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 309599
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_IsDeselectRetryTmr_Expired()
    :Description: Verifying for the function rbd_NFCVehIf_IsDeselectRetryTmr_Expired()
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 309599
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    calling function rbd_NFCVehIf_DESELECT_TimerRetry_Reload
    :Description: Verifying for the function rbd_NFCVehIf_DESELECT_TimerRetry_Reload()
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 309599
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ResetNFCReaderSessionTag()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 309599
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NfcIf_TapStartTriggerCyclic()
    :Description: if ( ((uint8)NFC_READER_TAP_START_RFHM_TRIGGER_RX_STATE_E) == session_state_u8 ) ==> FALSE
    rbd_NFCVehIf_TapStartPollingTimeoutTimer_u16 = ( rbd_NFCVehIf_TapStartPollingTimeoutTimer_u16 >= (uint16)NFC_CYCLE_TIME ) ? ( rbd_NFCVehIf_TapStartPollingTimeoutTimer_u16 - NFC_CYCLE_TIME ) : 0u ==> TRUE
        if ( rbd_NFCVehIf_TapStartPollingTimeoutTimer_u16 > 0x00u ) ==> FALSE
        if ( ( READER_IN_SESSION == readerConnection_state_u8 ) && ( ((uint8)NFC_READER_TAP_START_FLOW_INIT_STATE_E) == session_state_u8 ) ) ==> FALSE MCDC(TF)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 288528
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
@endrst
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_Cyclic_02)
{
    get_rbd_NFCVehIf_DeselectInfo_S()->mock_retryTimer_u32 = 0;
    get_rbd_NFCVehIf_DeselectInfo_S()->mock_reqRetryCount_u8 = 1;
	get_rbd_NFCVehIf_DeselectInfo_S()->mock_uRetryFinish_u8 = 1;
    *get_rbd_NFCVehIf_NfcCardTimer_u16() = 11;
    *get_rbd_NFCVehIf_DTCWCMP2Timer_active_b() = TRUE;
    *get_rbd_NFCVehIf_PollingTimeoutTimer_u16() = 1;
    *get_rbd_NFCVehIf_DTCWCPMTimer_u16() = 11;
    // rbd_NFCVehIf_NFCReaderSessionTimeOutManager()
    for ( uint8 NfcReaderId_u8 = 0u; NfcReaderId_u8 < NFC_NUM_READERS; NfcReaderId_u8++ ){
    get_rbd_NFCVehIf_Table_as()[NfcReaderId_u8].connectionStatus_u8 = 1;
    get_rbd_NFCVehIf_Table_as()[NfcReaderId_u8].activeState_u8 = 1;
    get_rbd_NFCVehIf_Table_as()[NfcReaderId_u8].session_timeout_u16  = 2;}
    *get_rbd_NFCVehIf_TapStartPollingTimeoutTimer_u16() = NFC_CYCLE_TIME;

    call_rbd_NFCVehIf_Cyclic();

    //assertion for rbd_NFCVehIf_ResetNFCReaderSessionTag
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8,READER_DISCONNECTED);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b ,255);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].activeState_u8 ,0x0);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].session_timeout_u16, NFC_SESSION_TIMEOUT);
    //assertion for rbd_NFCVehIf_Cyclic
    //EXPECT_EQ(rbd_RfhmIf_ControlFd9Bus_fake.call_count, 1);
    //EXPECT_EQ(Rte_rbd_NFCVehIf_PP_CanRequest_DkmNfc_ComRequest, FALSE);
    EXPECT_EQ(rbdSessionMgr_NfcDisconnected_fake.call_count, 2);
    EXPECT_EQ(rbdSessionMgr_NfcDisconnected_fake.arg0_val, 0);
    //assertion for rbd_NFCVehIf_DESELECT_TimerRetry_Reload
    EXPECT_EQ(get_rbd_NFCVehIf_DeselectInfo_S()->mock_nfcReaderId_en, 2);
    EXPECT_EQ(get_rbd_NFCVehIf_DeselectInfo_S()->mock_reqRetryCount_u8, 0);
    EXPECT_EQ(get_rbd_NFCVehIf_DeselectInfo_S()->mock_typeDeselect_u8, 0x01u);
    EXPECT_EQ(get_rbd_NFCVehIf_DeselectInfo_S()->mock_retryTimer_u32, 0x00u);
    EXPECT_EQ(get_rbd_NFCVehIf_DeselectInfo_S()->mock_uRetryFinish_u8, FALSE);
}

/*
@rst
    Brief description of test case.
    :Description: rbd_NFCVehIf_NfcCardTimer_u16 = ( rbd_NFCVehIf_NfcCardTimer_u16 >= (uint16)NFC_CYCLE_TIME ) ? ( rbd_NFCVehIf_NfcCardTimer_u16 - NFC_CYCLE_TIME ) : 0u ==> TRUE
        rbd_NFCVehIf_PollingTimeoutTimer_u16 = (rbd_NFCVehIf_PollingTimeoutTimer_u16 >= (uint16)NFC_CYCLE_TIME ) ? ( rbd_NFCVehIf_PollingTimeoutTimer_u16 - NFC_CYCLE_TIME ) : 0u ==> TRUE
        if(TRUE == rbd_NFCVehIf_IsDeselectRetryTmr_Expired()) ==> TRUE
        if(READER_IN_SESSION == wcpmReaderConnection_state_u8) ==> FALSE
        if(READER_IN_SESSION == fldhmReaderConnection_state_u8) ==> FALSE
        if(rbd_NFCVehIf_DTCWCMP2Timer_active_b == TRUE) ==> TRUE
        if((uint8)0 >= rbd_NFCVehIf_DTCWCPMTimer_u16) ==> TRUE
    :Arch ID: 0b18d96b-042f-478f-ba56-cd3caf41e637
    :REQ ID: NA
    :ALM Task ID: 309599
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NfcIf_NfcTapThread()
    :Description: if(((uint8)NFC_READER_TAP_ENTRY_CARD_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
        else if(((uint8)NFC_READER_TAP_ENTRY_DEVICE_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8))  ==> FALSE MCDC (FX)
        else if(((uint8)NFC_READER_TAP_ENTRY_DEVICE_INFO_WAIT_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
        else if(((uint8)NFC_READER_TAP_ENTRY_TOGGLE_RSP_WAIT_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
        else if((((uint8)NFC_READER_TAP_ENTRY_CARD_AUTH_FAILED_STATE_E == session_state_u8) || ((uint8)NFC_READER_TAP_ENTRY_DEVICE_AUTH_FAILED_STATE_E == session_state_u8)) ==> FALSE MCDC (FF)
        if(((uint8)NFC_READER_TAP_START_CARD_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
        else if(((uint8)NFC_READER_TAP_START_DEVICE_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
        else if(((uint8)NFC_READER_TAP_START_DEVICE_INFO_WAIT_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
        else if((((uint8)NFC_READER_TAP_START_CARD_AUTH_FAILED_STATE_E == session_state_u8) || ((uint8)NFC_READER_TAP_START_DEVICE_AUTH_FAILED_STATE_E == session_state_u8)) ==> FALSE MCDC (FF)
        else if (((uint8)NFC_READER_PHONE_ENABLE_DISABLE_WCP_AUTH_FINISH_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC(FX)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 309599
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_Deselect_TxManager_Cyclic()
    :Description: if((0x00U == rbd_NFCVehIf_DeselectInfo_S.retryTimer_u32) && (rbd_NFCVehIf_DeselectInfo_S.reqRetryCount_u8 > 0x00u)) ==> FALSE MCDC(TF)
        if(rbd_NFCVehIf_DeselectInfo_S.retryTimer_u32 > 0x00u) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 309599
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_NFCReaderSessionTimeOutManager()
    :Description: for ( NfcReaderId_u8 = 0u; NfcReaderId_u8 < NFC_NUM_READERS; NfcReaderId_u8++ ) ==> TRUE,FALSE
        if ( READER_IN_SESSION == rbd_NFCVehIf_Table_as[NfcReaderId_u8].connectionStatus_u8 ) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 309599
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    rbd_NFCVehIf_CardPairingRoutine_Cyclic:
    :Description: switch ( rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_PLANT_PAIRING_E].DiagRoutine_State_en )
        case NFC_DIAG_ROUTINE_INIT_STATE_E:
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 309599
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    rbd_NFCVehIf_TestCardPairingRoutine_Cyclic:
    :Description: switch ( rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_TEST_CARD_PAIRING_E].DiagRoutine_State_en )
        case NFC_DIAG_ROUTINE_INIT_STATE_E:
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 309599
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    rbd_NFCVehIf_GetUIDRoutine_Cyclic:
    :Description: switch ( rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_GET_UID_E].DiagRoutine_State_en )
        case NFC_DIAG_ROUTINE_INIT_STATE_E:
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 309599
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_IsDeselectRetryTmr_Expired()
    :Description: Verifying for the function rbd_NFCVehIf_IsDeselectRetryTmr_Expired()
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 309599
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    calling function rbd_NFCVehIf_DESELECT_TimerRetry_Reload
    :Description: Verifying for the function rbd_NFCVehIf_DESELECT_TimerRetry_Reload()
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 309599
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NfcIf_TapStartTriggerCyclic()
    :Description: if ( ((uint8)NFC_READER_TAP_START_RFHM_TRIGGER_RX_STATE_E) == session_state_u8 ) ==> FALSE
    rbd_NFCVehIf_TapStartPollingTimeoutTimer_u16 = ( rbd_NFCVehIf_TapStartPollingTimeoutTimer_u16 >= (uint16)NFC_CYCLE_TIME ) ? ( rbd_NFCVehIf_TapStartPollingTimeoutTimer_u16 - NFC_CYCLE_TIME ) : 0u ==> FALSE
        if ( rbd_NFCVehIf_TapStartPollingTimeoutTimer_u16 > 0x00u ) ==> FALSE
        if ( ( READER_IN_SESSION == readerConnection_state_u8 ) && ( ((uint8)NFC_READER_TAP_START_FLOW_INIT_STATE_E) == session_state_u8 ) ) ==> FALSE MCDC(FX)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 288528
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_DTC()
    :Description: if(max_auth_failure_counter_u8 <= wcpm2_auth_failure_counter_u8) ==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 288528
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
@endrst
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_Cyclic_03)
{
    get_rbd_NFCVehIf_DeselectInfo_S()->mock_uRetryFinish_u8 = 1;
    *get_rbd_NFCVehIf_NfcCardTimer_u16() = 11;
    *get_rbd_NFCVehIf_DTCWCMP2Timer_active_b() = TRUE;
    *get_rbd_NFCVehIf_DTCWCPMTimer_u16() = 10;
    // rbd_NFCVehIf_NFCReaderSessionTimeOutManager()
    for ( uint8 NfcReaderId_u8 = 0u; NfcReaderId_u8 < NFC_NUM_READERS; NfcReaderId_u8++ ){
    get_rbd_NFCVehIf_Table_as()[NfcReaderId_u8].connectionStatus_u8 = 2;
    get_rbd_NFCVehIf_Table_as()[NfcReaderId_u8].activeState_u8 = 1;
    get_rbd_NFCVehIf_Table_as()[NfcReaderId_u8].session_timeout_u16  = 0;}
    *get_rbd_NFCVehIf_PollingTimeoutTimer_u16() = NFC_CYCLE_TIME;

    call_rbd_NFCVehIf_Cyclic();
    //assertion for rbd_NFCVehIf_Cyclic
    //EXPECT_EQ(rbd_RfhmIf_ControlFd9Bus_fake.call_count, 2);
    //EXPECT_EQ(Rte_rbd_NFCVehIf_PP_CanRequest_DkmNfc_ComRequest, TRUE);
    //assertion for rbd_NFCVehIf_DESELECT_TimerRetry_Reload
    EXPECT_EQ(get_rbd_NFCVehIf_DeselectInfo_S()->mock_nfcReaderId_en, 2);
    EXPECT_EQ(get_rbd_NFCVehIf_DeselectInfo_S()->mock_reqRetryCount_u8, 0);
    EXPECT_EQ(get_rbd_NFCVehIf_DeselectInfo_S()->mock_typeDeselect_u8, 0x01u);
    EXPECT_EQ(get_rbd_NFCVehIf_DeselectInfo_S()->mock_retryTimer_u32, 0x00u);
    EXPECT_EQ(get_rbd_NFCVehIf_DeselectInfo_S()->mock_uRetryFinish_u8, FALSE);
}

//----------------------------------------------------------------------------
// Test Cases// FUNC(Std_ReturnType, rbd_NFCVehIf_CODE) rbd_NFCVehIf_GetNfcUID_Start_Start(P2VAR(uint8, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR) ErrorCode)
//----------------------------------------------------------------------------
/*
@rstd
    Brief description of test case.
    :Description: if(((uint8)NFC_ROUTINE_STATUS_IN_PROGRESS_E == rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_PLANT_PAIRING_E].nfcRoutineStatus) || ((uint8)NFC_ROUTINE_STATUS_IN_PROGRESS_E == rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_TEST_CARD_PAIRING_E].nfcRoutineStatus)) ==> TRUE MCDC(TX)
    :Arch ID: d0d0dcbd-dbf7-42ce-8806-ca4ac95f255a
    :REQ ID: NA
    :ALM Task ID: 288528
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_GetNfcUID_Start_Start_01)
{
    uint8 Out_ResData[2];
    Dcm_NegativeResponseCodeType ErrorCode;
    get_rbd_NFCVehIf_RoutineData_S()[0].mock_nfcRoutineStatus = 0x02u;
    Std_ReturnType ret_val = call_rbd_NFCVehIf_GetNfcUID_Start_Start(Out_ResData, &ErrorCode);
    EXPECT_EQ(ret_val, E_NOT_OK);
    EXPECT_EQ(ErrorCode, DCM_E_GENERALREJECT);
}
/*
@rstd
    Brief description of test case.
    :Description: if(((uint8)NFC_ROUTINE_STATUS_IN_PROGRESS_E == rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_PLANT_PAIRING_E].nfcRoutineStatus) || ((uint8)NFC_ROUTINE_STATUS_IN_PROGRESS_E == rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_TEST_CARD_PAIRING_E].nfcRoutineStatus)) ==> TRUE MCDC(FT)
    :Arch ID: d0d0dcbd-dbf7-42ce-8806-ca4ac95f255a
    :REQ ID: NA
    :ALM Task ID: 288528
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_GetNfcUID_Start_Start_02)
{
    uint8 Out_ResData[2];
    Dcm_NegativeResponseCodeType ErrorCode;
    get_rbd_NFCVehIf_RoutineData_S()[0].mock_nfcRoutineStatus = 0x01u;
    get_rbd_NFCVehIf_RoutineData_S()[1].mock_nfcRoutineStatus = 0x02u;
    Std_ReturnType ret_val = call_rbd_NFCVehIf_GetNfcUID_Start_Start(Out_ResData, &ErrorCode);
    EXPECT_EQ(ret_val, E_NOT_OK);
    EXPECT_EQ(ErrorCode, DCM_E_GENERALREJECT);
}
/*
@rstd
    Brief description of test case.
    :Description: if(((uint8)NFC_ROUTINE_STATUS_IN_PROGRESS_E == rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_PLANT_PAIRING_E].nfcRoutineStatus) || ((uint8)NFC_ROUTINE_STATUS_IN_PROGRESS_E == rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_TEST_CARD_PAIRING_E].nfcRoutineStatus)) ==> TRUE MCDC(FT)
        if (((uint8)NFC_ROUTINE_STATUS_IN_PROGRESS_E != rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_GET_UID_E].nfcRoutineStatus) && (FALSE == RoutineTriggered)) ==> FALSE MCDC(FX)
        else if ((uint8)NFC_ROUTINE_STATUS_IN_PROGRESS_E == rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_GET_UID_E].nfcRoutineStatus) ==> TRUE
    :Arch ID: d0d0dcbd-dbf7-42ce-8806-ca4ac95f255a
    :REQ ID: NA
    :ALM Task ID: 288528
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_GetNfcUID_Start_Start_03)
{
    uint8 Out_ResData[2];
    Dcm_NegativeResponseCodeType ErrorCode;
    get_rbd_NFCVehIf_RoutineData_S()[0].mock_nfcRoutineStatus = 0x01u;
    get_rbd_NFCVehIf_RoutineData_S()[1].mock_nfcRoutineStatus = 0x01u;
    get_rbd_NFCVehIf_RoutineData_S()[2].mock_nfcRoutineStatus = 0x02u;
    Std_ReturnType ret_val = call_rbd_NFCVehIf_GetNfcUID_Start_Start(Out_ResData, &ErrorCode);
    EXPECT_EQ(ret_val, PENDING);
}
/*
@rstd
    Brief description of test case.
    :Description: if(((uint8)NFC_ROUTINE_STATUS_IN_PROGRESS_E == rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_PLANT_PAIRING_E].nfcRoutineStatus) || ((uint8)NFC_ROUTINE_STATUS_IN_PROGRESS_E == rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_TEST_CARD_PAIRING_E].nfcRoutineStatus)) ==> TRUE MCDC(FT)
        if (((uint8)NFC_ROUTINE_STATUS_IN_PROGRESS_E != rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_GET_UID_E].nfcRoutineStatus) && (FALSE == RoutineTriggered)) ==> TRUE MCDC(TT)
    :Arch ID: d0d0dcbd-dbf7-42ce-8806-ca4ac95f255a
    :REQ ID: NA
    :ALM Task ID: 288528
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_GetNfcUID_Start_Start_04)
{
    uint8 Out_ResData[2];
    Dcm_NegativeResponseCodeType ErrorCode;
    get_rbd_NFCVehIf_RoutineData_S()[0].mock_nfcRoutineStatus = 0x01u;
    get_rbd_NFCVehIf_RoutineData_S()[1].mock_nfcRoutineStatus = 0x01u;
    get_rbd_NFCVehIf_RoutineData_S()[2].mock_nfcRoutineStatus = 0x03u;
    Std_ReturnType ret_val = call_rbd_NFCVehIf_GetNfcUID_Start_Start(Out_ResData, &ErrorCode);
    EXPECT_EQ(ret_val, PENDING);
    EXPECT_EQ(get_rbd_NFCVehIf_RoutineData_S()[2].mock_DiagRoutine_State_en, mock_NFC_DIAG_ROUTINE_REQUEST_RX_STATE_E);
    EXPECT_EQ(get_rbd_NFCVehIf_RoutineData_S()[2].mock_nfcRoutineStatus, 0X2u);
    EXPECT_EQ(get_rbd_NFCVehIf_RoutineData_S()[2].mock_nfcRoutineErrorCode, 0x0);
}
/*
@rstd
    Brief description of test case.
    :Description: if(((uint8)NFC_ROUTINE_STATUS_IN_PROGRESS_E == rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_PLANT_PAIRING_E].nfcRoutineStatus) || ((uint8)NFC_ROUTINE_STATUS_IN_PROGRESS_E == rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_TEST_CARD_PAIRING_E].nfcRoutineStatus)) ==> TRUE MCDC(FT)
        if (((uint8)NFC_ROUTINE_STATUS_IN_PROGRESS_E != rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_GET_UID_E].nfcRoutineStatus) && (FALSE == RoutineTriggered)) ==> FALSE MCDC(TF)
        else if ((uint8)NFC_ROUTINE_STATUS_IN_PROGRESS_E == rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_GET_UID_E].nfcRoutineStatus) ==> FALSE
    :Arch ID: d0d0dcbd-dbf7-42ce-8806-ca4ac95f255a
    :REQ ID: NA
    :ALM Task ID: 288528
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_GetNfcUID_Start_Start_05)
{
    uint8 Out_ResData[2];
    Dcm_NegativeResponseCodeType ErrorCode;
    get_rbd_NFCVehIf_RoutineData_S()[0].mock_nfcRoutineStatus = 0x01u;
    get_rbd_NFCVehIf_RoutineData_S()[1].mock_nfcRoutineStatus = 0x01u;
    get_rbd_NFCVehIf_RoutineData_S()[2].mock_nfcRoutineStatus = 0x03u;
    get_rbd_NFCVehIf_RoutineData_S()[2].mock_nfcRoutineErrorCode = 0x10u;
    Std_ReturnType ret_val = call_rbd_NFCVehIf_GetNfcUID_Start_Start(Out_ResData, &ErrorCode);
    EXPECT_EQ(ret_val, E_OK);
    EXPECT_EQ(ErrorCode, DCM_E_POSITIVERESPONSE);
}

//----------------------------------------------------------------------------
// Test Cases// FUNC(void, rbd_NFCVehIf_CODE) rbd_NFCVehIf_Init(void)
//----------------------------------------------------------------------------
/*
@rst
    Brief description of test case.
    :Description: for (uint8 i_u8 = 0; i_u8 < NFC_NUM_READERS; ++i_u8) ==> TRUE, FALSE
    :Arch ID: a1e27036-c340-4eed-b9c0-9b559cc6716e
    :REQ ID: NA
    :ALM Task ID: 183001
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_UpdateNfcCardData()
    :Description: for (uint8 i_u8 = 0; i_u8 < NFC_CARD_UID_LEN; ++i_u8) ==> TRUE, FALSE
    :Arch ID: 66b6e4c0-51ea-4aa7-b0ce-2dd0aa0bc066
    :REQ ID: NA
    :ALM Task ID: 183001
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_Init_01)
{
    call_rbd_NFCVehIf_Init();
    for (uint8 i_u8 = 0; i_u8 < NFC_NUM_READERS; ++i_u8)
    {
        EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[i_u8].connectionStatus_u8,READER_DISCONNECTED);
        // EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[i_u8].activeUseCase_u8,(uint8)NOT_ACTIVE);
        // EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[i_u8].rbdKeyRef_u8,RBDPK_KEYREF_INVALID);
        // EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[i_u8].pollKeyRef_b,FALSE);
        // EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[i_u8].teardown_b,FALSE);
    }
    // EXPECT_EQ(get_rbd_NFCVehIf_CardData_st()->routineStatus_u8 ,0);
    // EXPECT_EQ(get_rbd_NFCVehIf_CardData_st()->errorCode_u8, 0);
    // for (uint8 i_u8 = 0; i_u8 < NFC_CARD_UID_LEN; ++i_u8)
    // {
    //    EXPECT_EQ(get_rbd_NFCVehIf_CardData_st()->cardUID_au8[i_u8] ,get_rbd_NFCVehIf_NfcCardDefaultUid_au8()[i_u8]);
    // }Code removed
    // EXPECT_EQ(*get_rbd_NFCVehIf_NfcCardTimerIsActive_b(),FALSE);Code removed
}

//----------------------------------------------------------------------------
// Test Cases// FUNC(Std_ReturnType, rbd_NFCVehIf_CODE) rbd_NFCVehIf_NFC_Card_Pairing_Start_RequestResults(P2VAR(uint8, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR) ErrorCode)
//----------------------------------------------------------------------------
/*
@rst
    Brief description of test case.
    :Description: if((uint8)NFC_ROUTINE_STATUS_SUCCESS_E == rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_PLANT_PAIRING_E].nfcRoutineStatus) ==> FALSE
    :Arch ID: eb9e664d-03dd-480f-b5bf-be62b5ea2086
    :REQ ID: NA
    :ALM Task ID: 288528
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NFC_Card_Pairing_Start_RequestResults_01)
{
    uint8 Out_ResData[100];
    Dcm_NegativeResponseCodeType ErrorCode;
    get_rbd_NFCVehIf_RoutineData_S()[0].mock_nfcRoutineStatus = 0x02u;
    get_rbd_NFCVehIf_RoutineData_S()[0].mock_nfcRoutineErrorCode = 0x03u;
    Std_ReturnType ret_val = call_rbd_NFCVehIf_NFC_Card_Pairing_Start_RequestResults(Out_ResData,&ErrorCode);
    EXPECT_EQ(ret_val, RTE_E_OK);
    EXPECT_EQ(ErrorCode, DCM_E_POSITIVERESPONSE);
    EXPECT_EQ(Out_ResData[0], 0x02u);
    EXPECT_EQ(Out_ResData[1], 0x03u);
}
/*
@rst
    Brief description of test case.
    :Description: if((uint8)NFC_ROUTINE_STATUS_SUCCESS_E == rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_PLANT_PAIRING_E].nfcRoutineStatus) ==> TRUE
        if(FALSE == isKeyInfoReadInProgress) ==> TRUE
        if(RTE_E_OK == dkmRet_u8 ) ==> FALSE
    :Arch ID: eb9e664d-03dd-480f-b5bf-be62b5ea2086
    :REQ ID: NA
    :ALM Task ID: 288528
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NFC_Card_Pairing_Start_RequestResults_02)
{
    uint8 Out_ResData[100];
    Dcm_NegativeResponseCodeType ErrorCode;
    get_rbd_NFCVehIf_RoutineData_S()[0].mock_nfcRoutineStatus = 0x01u;
    get_rbd_NFCVehIf_RoutineData_S()[0].mock_nfcRoutineErrorCode = 0x02u;
    Dkm_GetKeyInfoCard_Operation_fake.return_val = RTE_E_INVALID;
    Std_ReturnType ret_val = call_rbd_NFCVehIf_NFC_Card_Pairing_Start_RequestResults(Out_ResData,&ErrorCode);
    EXPECT_EQ(ret_val, RTE_E_NFC_Card_Serial_Number_Read_DCM_E_PENDING);
    EXPECT_EQ(Out_ResData[0], 0x01u);
    EXPECT_EQ(Out_ResData[1], 0x02u);
}
/*
@rst
    Brief description of test case.
    :Description: if((uint8)NFC_ROUTINE_STATUS_SUCCESS_E == rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_PLANT_PAIRING_E].nfcRoutineStatus) ==> TRUE
        if(FALSE == isKeyInfoReadInProgress) ==> TRUE
        if(RTE_E_OK == dkmRet_u8 ) ==> TRUE
    :Arch ID: eb9e664d-03dd-480f-b5bf-be62b5ea2086
    :REQ ID: NA
    :ALM Task ID: 288528
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NFC_Card_Pairing_Start_RequestResults_03)
{
    uint8 Out_ResData[100];
    Dcm_NegativeResponseCodeType ErrorCode;
    get_rbd_NFCVehIf_RoutineData_S()[0].mock_nfcRoutineStatus = 0x01u;
    get_rbd_NFCVehIf_RoutineData_S()[0].mock_nfcRoutineErrorCode = 0x02u;
    Dkm_GetKeyInfoCard_Operation_fake.return_val = RTE_E_OK;
    Std_ReturnType ret_val = call_rbd_NFCVehIf_NFC_Card_Pairing_Start_RequestResults(Out_ResData,&ErrorCode);
    EXPECT_EQ(ret_val, RTE_E_NFC_Card_Serial_Number_Read_DCM_E_PENDING);
    EXPECT_EQ(Out_ResData[0], 0x01u);
    EXPECT_EQ(Out_ResData[1], 0x02u);
}
/*
@rst
    Brief description of test case.
    :Description: if((uint8)NFC_ROUTINE_STATUS_SUCCESS_E == rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_PLANT_PAIRING_E].nfcRoutineStatus) ==> TRUE
        if(FALSE == isKeyInfoReadInProgress) ==> FALSE
        if(RTE_E_OK == dkmRet_u8) ==> TRUE
    :Arch ID: eb9e664d-03dd-480f-b5bf-be62b5ea2086
    :REQ ID: NA
    :ALM Task ID: 288528
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NFC_Card_Pairing_Start_RequestResults_04)
{
    uint8 Out_ResData[100];
    Dcm_NegativeResponseCodeType ErrorCode;
    get_rbd_NFCVehIf_RoutineData_S()[0].mock_nfcRoutineStatus = 0x01u;
    get_rbd_NFCVehIf_RoutineData_S()[0].mock_nfcRoutineErrorCode = 0x02u;
    Dkm_DeviceMgr_GetStatus_Operation_fake.return_val = RTE_E_OK;
    Std_ReturnType ret_val = call_rbd_NFCVehIf_NFC_Card_Pairing_Start_RequestResults(Out_ResData,&ErrorCode);
    EXPECT_EQ(ret_val, RTE_E_NFC_Card_Pairing_Start_E_OK);
    EXPECT_EQ(ErrorCode, DCM_E_POSITIVERESPONSE);
    EXPECT_EQ(Out_ResData[0], 0x01u);
    EXPECT_EQ(Out_ResData[1], 0x02u);
}
/*
@rst
    Brief description of test case.
    :Description: if((uint8)NFC_ROUTINE_STATUS_SUCCESS_E == rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_PLANT_PAIRING_E].nfcRoutineStatus) ==> TRUE
        if(FALSE == isKeyInfoReadInProgress) ==> TRUE, FALSE
        if(RTE_E_OK == dkmRet_u8) ==> FALSE
        else if(RTE_E_IF_NfcFlow_E_BUSY == dkmRet_u8) ==> TRUE
    :Arch ID: eb9e664d-03dd-480f-b5bf-be62b5ea2086
    :REQ ID: NA
    :ALM Task ID: 288528
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NFC_Card_Pairing_Start_RequestResults_05)
{
    uint8 Out_ResData[100];
    Dcm_NegativeResponseCodeType ErrorCode;
    get_rbd_NFCVehIf_RoutineData_S()[0].mock_nfcRoutineStatus = 0x01u;
    get_rbd_NFCVehIf_RoutineData_S()[0].mock_nfcRoutineErrorCode = 0x02u;
    Dkm_DeviceMgr_GetStatus_Operation_fake.return_val = RTE_E_IF_NfcFlow_E_BUSY;
    Dkm_GetKeyInfoCard_Operation_fake.return_val = RTE_E_OK;
    Std_ReturnType ret_val = call_rbd_NFCVehIf_NFC_Card_Pairing_Start_RequestResults(Out_ResData,&ErrorCode);
    ret_val = call_rbd_NFCVehIf_NFC_Card_Pairing_Start_RequestResults(Out_ResData,&ErrorCode);
    EXPECT_EQ(ret_val, RTE_E_NFC_Card_Serial_Number_Read_DCM_E_PENDING);
    EXPECT_EQ(ErrorCode, DCM_E_POSITIVERESPONSE);
    EXPECT_EQ(Out_ResData[0], 0x01u);
    EXPECT_EQ(Out_ResData[1], 0x02u);
}
/*
@rst
    Brief description of test case.
    :Description: if((uint8)NFC_ROUTINE_STATUS_SUCCESS_E == rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_PLANT_PAIRING_E].nfcRoutineStatus) ==> TRUE
        if(FALSE == isKeyInfoReadInProgress) ==> FALSE
        if(RTE_E_OK == dkmRet_u8) ==> FALSE
        else if(RTE_E_IF_NfcFlow_E_BUSY == dkmRet_u8) ==> FALSE
    :Arch ID: eb9e664d-03dd-480f-b5bf-be62b5ea2086
    :REQ ID: NA
    :ALM Task ID: 288528
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NFC_Card_Pairing_Start_RequestResults_06)
{
    uint8 Out_ResData[100];
    Dcm_NegativeResponseCodeType ErrorCode;
    get_rbd_NFCVehIf_RoutineData_S()[0].mock_nfcRoutineStatus = 0x01u;
    get_rbd_NFCVehIf_RoutineData_S()[0].mock_nfcRoutineErrorCode = 0x02u;
    Dkm_DeviceMgr_GetStatus_Operation_fake.return_val = RTE_E_IF_NfcFlow_E_NOT_OK;
    Std_ReturnType ret_val = call_rbd_NFCVehIf_NFC_Card_Pairing_Start_RequestResults(Out_ResData,&ErrorCode);
    EXPECT_EQ(ret_val, RTE_E_NFC_Card_Pairing_Start_E_NOT_OK);
    EXPECT_EQ(ErrorCode, DCM_E_GENERALREJECT);
    EXPECT_EQ(Out_ResData[0], 0x01u);
    EXPECT_EQ(Out_ResData[1], 0x02u);
}

//----------------------------------------------------------------------------
// Test Cases// FUNC(Std_ReturnType, rbd_NFCVehIf_CODE) rbd_NFCVehIf_NFC_Card_Pairing_Start_Start(P2CONST(uint8, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_DATA) In_ReqData, uint8 serialNumLen_u8, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR) ErrorCode)
//----------------------------------------------------------------------------
/*
@rst
    Brief description of test case.
    :Description: if (FALSE == rbd_NFCVehIf_IsRoutineInProgress() && (dataType.SPKPHSCLKEY == TRUE)) ==> FALSE MCDC(TF)
    :Arch ID: 492f46cb-71ef-48f8-9a4f-3e74dd688a36
    :REQ ID: NA
    :ALM Task ID: 288528
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    rbd_NFCVehIf_IsRoutineInProgress:
    :Description: if ( ( rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_PLANT_PAIRING_E].nfcRoutineStatus == (uint8)NFC_ROUTINE_STATUS_IN_PROGRESS_E ) || ( rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_TEST_CARD_PAIRING_E].nfcRoutineStatus == (uint8)NFC_ROUTINE_STATUS_IN_PROGRESS_E ) || ( rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_GET_UID_E].nfcRoutineStatus == (uint8)NFC_ROUTINE_STATUS_IN_PROGRESS_E ) ) ==> FALSE MCDC(FFF)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 288528
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NFC_Card_Pairing_Start_Start_01)
{
    uint8 In_ReqData[20];
    Dcm_NegativeResponseCodeType ErrorCode;
    for(uint8 i =0; i<3; i++){
        get_rbd_NFCVehIf_RoutineData_S()[i].mock_nfcRoutineStatus = 0x01u;
        }
    dummy_dataType.SPKPHSCLKEY = FALSE;
    Rte_Read_rbd_NFCVehIf_RP_drmServices_drmServices_fake.custom_fake=Rte_Read_rbd_NFCVehIf_RP_drmServices_drmServices_custom_fake;
    Std_ReturnType ret_val = call_rbd_NFCVehIf_NFC_Card_Pairing_Start_Start(In_ReqData,1, &ErrorCode);
    EXPECT_EQ(ret_val, E_NOT_OK);
    EXPECT_EQ(ErrorCode, DCM_E_GENERALREJECT);
    EXPECT_EQ(Rte_Read_rbd_NFCVehIf_RP_drmServices_drmServices_fake.call_count, 1);
}
/*
@rst
    Brief description of test case.
    :Description: if (FALSE == rbd_NFCVehIf_IsRoutineInProgress() && (dataType.SPKPHSCLKEY == TRUE)) ==> FALSE MCDC(FX)
    :Arch ID: 492f46cb-71ef-48f8-9a4f-3e74dd688a36
    :REQ ID: NA
    :ALM Task ID: 288528
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    rbd_NFCVehIf_IsRoutineInProgress:
    :Description: if ( ( rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_PLANT_PAIRING_E].nfcRoutineStatus == (uint8)NFC_ROUTINE_STATUS_IN_PROGRESS_E ) || ( rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_TEST_CARD_PAIRING_E].nfcRoutineStatus == (uint8)NFC_ROUTINE_STATUS_IN_PROGRESS_E ) || ( rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_GET_UID_E].nfcRoutineStatus == (uint8)NFC_ROUTINE_STATUS_IN_PROGRESS_E ) ) ==> TRUE MCDC(TXX)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 288528
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NFC_Card_Pairing_Start_Start_02)
{
    uint8 In_ReqData[20];
    Dcm_NegativeResponseCodeType ErrorCode;
    get_rbd_NFCVehIf_RoutineData_S()[0].mock_nfcRoutineStatus = 0x02u;
    // dummy_dataType.SPKPHSCLKEY = FALSE;
    // Rte_Read_rbd_NFCVehIf_RP_drmServices_drmServices_fake.custom_fake=Rte_Read_rbd_NFCVehIf_RP_drmServices_drmServices_custom_fake;
    Std_ReturnType ret_val = call_rbd_NFCVehIf_NFC_Card_Pairing_Start_Start(In_ReqData,1, &ErrorCode);
    EXPECT_EQ(ret_val, E_NOT_OK);
    EXPECT_EQ(ErrorCode, DCM_E_GENERALREJECT);
    EXPECT_EQ(Rte_Read_rbd_NFCVehIf_RP_drmServices_drmServices_fake.call_count, 1);
}
/*
@rst
    Brief description of test case.
    :Description: if (FALSE == rbd_NFCVehIf_IsRoutineInProgress() && (dataType.SPKPHSCLKEY == TRUE)) ==> TRUE MCDC(TT)
    :Arch ID: 492f46cb-71ef-48f8-9a4f-3e74dd688a36
    :REQ ID: NA
    :ALM Task ID: 288528
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    rbd_NFCVehIf_IsRoutineInProgress:
    :Description: if ( ( rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_PLANT_PAIRING_E].nfcRoutineStatus == (uint8)NFC_ROUTINE_STATUS_IN_PROGRESS_E ) || ( rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_TEST_CARD_PAIRING_E].nfcRoutineStatus == (uint8)NFC_ROUTINE_STATUS_IN_PROGRESS_E ) || ( rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_GET_UID_E].nfcRoutineStatus == (uint8)NFC_ROUTINE_STATUS_IN_PROGRESS_E ) ) ==> FALSE MCDC(FFF)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 288528
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NFC_Card_Pairing_Start_Start_03)
{
    uint8 In_ReqData[20];
    Dcm_NegativeResponseCodeType ErrorCode;
    for(uint8 i =0; i<3; i++){
        get_rbd_NFCVehIf_RoutineData_S()[i].mock_nfcRoutineStatus = 0x01u;
        }
    dummy_dataType.SPKPHSCLKEY = TRUE;
    Rte_Read_rbd_NFCVehIf_RP_drmServices_drmServices_fake.custom_fake=Rte_Read_rbd_NFCVehIf_RP_drmServices_drmServices_custom_fake;
    Std_ReturnType ret_val = call_rbd_NFCVehIf_NFC_Card_Pairing_Start_Start(In_ReqData,1, &ErrorCode);
    EXPECT_EQ(ret_val, E_OK);
    EXPECT_EQ(ErrorCode, DCM_E_POSITIVERESPONSE);
    EXPECT_EQ(Rte_Read_rbd_NFCVehIf_RP_drmServices_drmServices_fake.call_count, 1);
    EXPECT_EQ(get_rbd_NFCVehIf_RoutineData_S()[0].mock_DiagRoutine_State_en, mock_NFC_DIAG_ROUTINE_REQUEST_RX_STATE_E);
}

//----------------------------------------------------------------------------
// Test Cases// FUNC(Std_ReturnType, rbd_NFCVehIf_CODE) rbd_NFCVehIf_NFC_Card_Serial_Number_Read_Operation(P2VAR(uint8, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR) Data)
//----------------------------------------------------------------------------
/*
@rst
    Brief description of test case.
    :Description: for ( uint8 index_u8 = 0; index_u8 < keyCardRef_paried_u8; ++index_u8 ) ==> TRUE,FALSE
        for ( uint8 i_u8 = 0; i_u8 < NFC_SERIAL_LEN; ++i_u8 ) ==> TRUE,FALSE
        for ( uint8 i_u8 = 0; i_u8 < NFC_CARD_UID_LEN; ++i_u8 ) ==> TRUE,FALSE
        for ( uint8 i_u8 = 0; i_u8 < KEY_IDENTIFIER_LENGTH; ++i_u8 ) ==> TRUE,FALSE
        for ( uint8 i_u8 = 0; i_u8 < KEY_FRIENDLY_NAME_LENGTH; ++i_u8 ) ==> TRUE,FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NFC_Card_Serial_Number_Read_Operation_01)
{
    uint8 Data[65535];
    *get_keyCardRef_paried_u8() = 1;
    Std_ReturnType ret_val = call_rbd_NFCVehIf_NFC_Card_Serial_Number_Read_Operation(Data);
    for ( uint8 index_u8 = 0; index_u8 < *get_keyCardRef_paried_u8(); ++index_u8 )
    {
        for ( uint8 i_u8 = 0; i_u8 < NFC_SERIAL_LEN; ++i_u8 )
		{
			EXPECT_EQ(Data[(uint8)1 + ( (uint8)index_u8 * NFC_PAIRED_CARD_LENGTH ) + (uint8)i_u8],
				get_rbd_NFCVehIf_Did5608Info()[index_u8].nfcCardSerNum[i_u8]);
		}
        for ( uint8 i_u8 = 0; i_u8 < NFC_CARD_UID_LEN; ++i_u8 )
		{
			EXPECT_EQ(Data[(uint8)16 + ( (uint8)index_u8 * NFC_PAIRED_CARD_LENGTH ) + (uint8)i_u8],
				get_rbd_NFCVehIf_Did5608Info()[index_u8].nfcCardUid[i_u8]);
		}

		EXPECT_EQ(Data[(uint8)23 + ( (uint8)index_u8 * NFC_PAIRED_CARD_LENGTH )], index_u8);

		for ( uint8 i_u8 = 0; i_u8 < KEY_IDENTIFIER_LENGTH; ++i_u8 )
		{
			EXPECT_EQ(Data[(uint8)24 + ( (uint8)index_u8 * NFC_PAIRED_CARD_LENGTH ) + (uint8)i_u8],
				get_rbd_NFCVehIf_Did5608Info()[index_u8].keyIdentifier[i_u8]);
		}

		for ( uint8 i_u8 = 0; i_u8 < KEY_FRIENDLY_NAME_LENGTH; ++i_u8 )
		{
			EXPECT_EQ(Data[(uint8)44 + ( (uint8)index_u8 * NFC_PAIRED_CARD_LENGTH ) + (uint8)i_u8],
				get_rbd_NFCVehIf_Did5608Info()[index_u8].keyFriendlyName[i_u8]);
		}
    }
    EXPECT_EQ(ret_val,E_OK);
}

//----------------------------------------------------------------------------
// Test Cases// FUNC(Std_ReturnType, rbd_NFCVehIf_CODE) rbd_NFCVehIf_NFC_Card_Termination_Start_RequestResults(P2VAR(uint8, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR) ErrorCode)
//----------------------------------------------------------------------------
/*
@rst
    Brief description of test case.
    :Description: Verify for the function rbd_NFCVehIf_NFC_Card_Termination_Start_RequestResults
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 183001
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
// TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NFC_Card_Termination_Start_RequestResults_01)
// {
//     Std_ReturnType ret_val = call_rbd_NFCVehIf_NFC_Card_Termination_Start_RequestResults(NULL,NULL);
//     EXPECT_EQ(ret_val,RTE_E_OK);
// }//Deleted..

//----------------------------------------------------------------------------
// Test Cases// FUNC(Std_ReturnType, rbd_NFCVehIf_CODE) rbd_NFCVehIf_NFC_Card_Termination_Start_Start(P2CONST(uint8, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_DATA) In_ReqData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR) ErrorCode)
//----------------------------------------------------------------------------
/*
@rst
    Brief description of test case.
    :Description: Verify for the function rbd_NFCVehIf_NFC_Card_Termination_Start_Start
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 183001
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
// TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NFC_Card_Termination_Start_Start_01)
// {
//     Std_ReturnType ret_val = call_rbd_NFCVehIf_NFC_Card_Termination_Start_Start(NULL,NULL);
//     EXPECT_EQ(ret_val,RTE_E_OK);
// }//Deleted..

//----------------------------------------------------------------------------
// Test Cases// FUNC(void, rbd_NFCVehIf_CODE) rbd_NFCVehIf_NFC_READER_FLDHM_DEVICE_Sig_Callback(void)
//----------------------------------------------------------------------------
/*
@rst
    Brief description of test case.
    :Description: if(READER_DISCONNECTED == readerConnection_state_u8) ==> TRUE
        if (RTE_E_OK == Rte_Receive_rbd_NFCVehIf_NFC_READER_FLDHM_RES_Sig_NFC_READER_FLDHM_DEVICE_Sig(FLDHM_NFCResponse_au8, &responseLength_u16)) ==> TRUE
        if ( ((uint8)NFC_SELECT == nfcReaderFLDHMHdr.cmdId_u8 ) && ((uint8)FLDHM == nfcReaderFLDHMHdr.txEcu_u8 ) ) ==> TRUE MCDC (TT)
        if(0u == nfcEntryFailedAttemptCtr_u8) ==> TRUE
        if(doorStatusLastCanBus_en < DOOR_STAT_SNA_EN) ==> FALSE
        else if(doorStatusLastNvm_en < DOOR_STAT_SNA_EN) ==> FALSE
        if(TRUE == data_validity_u8) ==> FALSE
        if(RTE_E_OK == ret) ==> TRUE
        if((responseLength_u16 <= NFC_MAX_MESSAGE_LEN) && (responseLength_u16 != 0U)) ==> FALSE MCDC (FX)
    :Arch ID: 890c7d89-e010-4a8c-a683-1d334703fa1b
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NfcIf_NfcReaderCanTPPacketHeaderRead()
    :Description: if((NULL != packetDataIn) && (NULL != nfcReaderDataHeader_ps)) ==> TRUE MCDC (TT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReceiveNFCResponse()
    :Description: if (nfcResponseLength_u16 >= (uint16)NFC_PAYLOAD_INIT_BYTE) ==> TRUE
       if (nfcReaderHdr.cmdId_u8 == (uint8)NFC_STATUS) ==> FALSE
       else if (nfcReaderHdr.cmdId_u8 == NFC_FAILUREMODE) ==> FALSE
       else if (nfcReaderHdr.cmdId_u8 == NFC_DETECTEDUIDS) ==> FALSE
    :Arch ID: 7276a26e-0947-4cfe-a535-ac5f1280e46f
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

     Calling function rbd_NFCVehIf_ProcessCCCResponse()
    :Description: iif (((uint8)NFC_SELECT == nfcReaderHdr.cmdId_u8) && (nfcReaderHdr.txEcu_u8 == (uint8)WCPM2)) ==> FALSE MCDC (TF)
        if (RBDSESSIONMGR_E_OK != rbdSessionMgr_ProcessNfcMsg(nfcReaderHdr.txEcu_u8, nfcReaderHdr.payloadLength_u16, &nfcResponse_pt[NFC_PAYLOAD_INIT_BYTE])) ==> FALSE
    :Arch ID: 49f43eea-398d-4c8a-9e33-32f47cb85c79
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NFC_READER_FLDHM_DEVICE_Sig_Callback_01)
{
    dummy_return = RTE_E_OK;
    dummy_responseLength_u16 = 264;
    dummy_FLDHM_NFCResponse_au8[NFC_COM_ID_BYTE] = (uint8)NFC_SELECT;
    dummy_FLDHM_NFCResponse_au8[NFC_ECU_ID_BYTE] = (uint8)FLDHM;
    Rte_Receive_rbd_NFCVehIf_NFC_READER_FLDHM_RES_Sig_NFC_READER_FLDHM_DEVICE_Sig_fake.custom_fake = Rte_Receive_rbd_NFCVehIf_NFC_READER_FLDHM_RES_Sig_NFC_READER_FLDHM_DEVICE_Sig_custom_fake;
     Rte_rbd_NFCVehIf_FailedAttemptsCounter_MirrorBlock=0;
    Rte_rbd_VSM_PP_InternalUtcTimestamp_De_rbd_VSM_PP_InternalUtcTimestamp=0;
    Rte_rbd_VSM_PP_InternalUtcTimestampValid_De_rbd_VSM_PP_InternalUtcTimestampValid=0;
    Rte_rbd_VSM_PP_DoorStatus_DoorLockLastElSts=100;
    get_rbd_NFCVehIf_Table_as()[FLDHM].connectionStatus_u8  = 255;
    get_rbd_NFCVehIf_Table_as()[FLDHM].Key_Card_Ref_b  = 255;
    get_rbd_NFCVehIf_Table_as()[FLDHM].activeState_u8  = 14;
    rbdSessionMgr_ProcessNfcMsg_fake.return_val=RBDSESSIONMGR_E_OK;
    call_rbd_NFCVehIf_NFC_READER_FLDHM_DEVICE_Sig_Callback();
    //EXPECT_EQ(rbd_RfhmIf_ControlFd9Bus_fake.call_count,1);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[FLDHM].connectionStatus_u8,0);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[FLDHM].Key_Card_Ref_b ,255);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[FLDHM].activeState_u8 ,0);
    EXPECT_EQ(rbdSessionMgr_ProcessNfcMsg_fake.call_count,1);
}
/*
@rst
    Brief description of test case.
    :Description: if(READER_DISCONNECTED == readerConnection_state_u8) ==> TRUE
        if (RTE_E_OK == Rte_Receive_rbd_NFCVehIf_NFC_READER_FLDHM_RES_Sig_NFC_READER_FLDHM_DEVICE_Sig(FLDHM_NFCResponse_au8, &responseLength_u16)) ==> TRUE
        if ( ((uint8)NFC_SELECT == nfcReaderFLDHMHdr.cmdId_u8 ) && ((uint8)FLDHM == nfcReaderFLDHMHdr.txEcu_u8 ) ) ==> TRUE MCDC (TT)
        if(0u == nfcEntryFailedAttemptCtr_u8) ==> FALSE
        if(doorStatusLastCanBus_en < DOOR_STAT_SNA_EN) ==> FALSE
        else if(doorStatusLastNvm_en < DOOR_STAT_SNA_EN) ==> TRUE
        if(TRUE == data_validity_u8) ==> TRUE
        if(READER_IN_SESSION == readerConnection_state_u8) ==> FALSE
        if(TRUE == rbd_NFCVehIf_RegisterNFCReaderSession(nfcReaderFLDHMHdr.txEcu_u8)) ==> FALSE
        if(RTE_E_OK == ret) ==> TRUE
        if((responseLength_u16 <= NFC_MAX_MESSAGE_LEN) && (responseLength_u16 != 0U)) ==> TRUE MCDC (TT)
    :Arch ID: 890c7d89-e010-4a8c-a683-1d334703fa1b
    :REQ ID: NA
    :ALM Task ID: 92308
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NfcIf_NfcReaderCanTPPacketHeaderRead()
    :Description: if((NULL != packetDataIn) && (NULL != nfcReaderDataHeader_ps)) ==> TRUE MCDC (TT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_RegisterNFCReaderSession()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
        if ( READER_DISCONNECTED == rbd_NFCVehIf_Table_as[NfcReaderId_u8].connectionStatus_u8 ) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReceiveNFCResponse()
    :Description: if (nfcResponseLength_u16 >= (uint16)NFC_PAYLOAD_INIT_BYTE) ==> TRUE
       if (nfcReaderHdr.cmdId_u8 == (uint8)NFC_STATUS) ==> FALSE
       else if (nfcReaderHdr.cmdId_u8 == NFC_FAILUREMODE) ==> FALSE
       else if (nfcReaderHdr.cmdId_u8 == NFC_DETECTEDUIDS) ==> FALSE
    :Arch ID: 7276a26e-0947-4cfe-a535-ac5f1280e46f
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ProcessCCCResponse()
     :Description: iif (((uint8)NFC_SELECT == nfcReaderHdr.cmdId_u8) && (nfcReaderHdr.txEcu_u8 == (uint8)WCPM2)) ==> FALSE MCDC (TF)
        if (RBDSESSIONMGR_E_OK != rbdSessionMgr_ProcessNfcMsg(nfcReaderHdr.txEcu_u8, nfcReaderHdr.payloadLength_u16, &nfcResponse_pt[NFC_PAYLOAD_INIT_BYTE]))  ==> FALSE
    :Arch ID: 49f43eea-398d-4c8a-9e33-32f47cb85c79
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NFC_READER_FLDHM_DEVICE_Sig_Callback_02)
{
    dummy_return = RTE_E_OK;
    dummy_responseLength_u16 = 263;
    dummy_FLDHM_NFCResponse_au8[NFC_COM_ID_BYTE] = (uint8)NFC_SELECT;
    dummy_FLDHM_NFCResponse_au8[NFC_ECU_ID_BYTE] = (uint8)FLDHM;
    Rte_Receive_rbd_NFCVehIf_NFC_READER_FLDHM_RES_Sig_NFC_READER_FLDHM_DEVICE_Sig_fake.custom_fake = Rte_Receive_rbd_NFCVehIf_NFC_READER_FLDHM_RES_Sig_NFC_READER_FLDHM_DEVICE_Sig_custom_fake;
     Rte_rbd_NFCVehIf_FailedAttemptsCounter_MirrorBlock=10;
    Rte_rbd_VSM_PP_DoorStatus_DoorLockLastElSts=5;
    get_rbd_NFCVehIf_Table_as()[FLDHM].connectionStatus_u8  = 5;
    get_rbd_NFCVehIf_Table_as()[FLDHM].Key_Card_Ref_b  = 255;
    get_rbd_NFCVehIf_Table_as()[FLDHM].activeState_u8  = 14;
    rbdSessionMgr_ProcessNfcMsg_fake.return_val=RBDSESSIONMGR_E_OK;
    Dkm_NfcFlow_Start_fake.return_val=RTE_E_OK;
    call_rbd_NFCVehIf_NFC_READER_FLDHM_DEVICE_Sig_Callback();
    //EXPECT_EQ(rbd_RfhmIf_ControlFd9Bus_fake.call_count,2);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[FLDHM].connectionStatus_u8,0);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[FLDHM].Key_Card_Ref_b ,RBDPK_KEYREF_INVALID);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[FLDHM].activeState_u8 ,0);
    EXPECT_EQ(rbdSessionMgr_ProcessNfcMsg_fake.call_count,1);
    EXPECT_EQ(Dkm_NfcFlow_Start_fake.call_count,0);
}
/*
@rst
    Brief description of test case.
    :Description: if(READER_DISCONNECTED == readerConnection_state_u8) ==> TRUE
        if (RTE_E_OK == Rte_Receive_rbd_NFCVehIf_NFC_READER_FLDHM_RES_Sig_NFC_READER_FLDHM_DEVICE_Sig(FLDHM_NFCResponse_au8, &responseLength_u16)) ==> TRUE
        if ( ((uint8)NFC_SELECT == nfcReaderFLDHMHdr.cmdId_u8 ) && ((uint8)FLDHM == nfcReaderFLDHMHdr.txEcu_u8 ) ) ==> TRUE MCDC (TT)
        if(0u == nfcEntryFailedAttemptCtr_u8) ==> FALSE
        if(doorStatusLastCanBus_en < DOOR_STAT_SNA_EN) ==> TRUE
        if(TRUE == data_validity_u8) ==> TRUE
        if(READER_IN_SESSION == readerConnection_state_u8) ==> FALSE
        if(TRUE == rbd_NFCVehIf_RegisterNFCReaderSession(nfcReaderFLDHMHdr.txEcu_u8)) ==> TRUE
        if(RTE_E_OK == ret) ==> TRUE
        if((responseLength_u16 <= NFC_MAX_MESSAGE_LEN) && (responseLength_u16 != 0U)) ==> FALSE MCDC (TF)
    :Arch ID: 890c7d89-e010-4a8c-a683-1d334703fa1b
    :REQ ID: NA
    :ALM Task ID: 92308
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NfcIf_NfcReaderCanTPPacketHeaderRead()
    :Description: if((NULL != packetDataIn) && (NULL != nfcReaderDataHeader_ps)) ==> TRUE MCDC (TT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_RegisterNFCReaderSession()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
        if ( READER_DISCONNECTED == rbd_NFCVehIf_Table_as[NfcReaderId_u8].connectionStatus_u8 ) ==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_UpdateNFCReaderState()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
        if(NULL != newDevRef_pu8) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReceiveNFCResponse()
    :Description: if (nfcResponseLength_u16 >= (uint16)NFC_PAYLOAD_INIT_BYTE) ==> FALSE
    :Arch ID: 7276a26e-0947-4cfe-a535-ac5f1280e46f
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NFC_READER_FLDHM_DEVICE_Sig_Callback_03)
{
    dummy_return = RTE_E_OK;
    dummy_responseLength_u16 = 0;
    dummy_FLDHM_NFCResponse_au8[NFC_COM_ID_BYTE] = (uint8)NFC_SELECT;
    dummy_FLDHM_NFCResponse_au8[NFC_ECU_ID_BYTE] = (uint8)FLDHM;
    Rte_Receive_rbd_NFCVehIf_NFC_READER_FLDHM_RES_Sig_NFC_READER_FLDHM_DEVICE_Sig_fake.custom_fake = Rte_Receive_rbd_NFCVehIf_NFC_READER_FLDHM_RES_Sig_NFC_READER_FLDHM_DEVICE_Sig_custom_fake;
     Rte_rbd_NFCVehIf_FailedAttemptsCounter_MirrorBlock=10;
    Rte_rbd_VSM_PP_DoorStatus_DoorLockLastElSts=50;
    get_rbd_NFCVehIf_Table_as()[FLDHM].connectionStatus_u8  = READER_DISCONNECTED;
    get_rbd_NFCVehIf_Table_as()[FLDHM].Key_Card_Ref_b  = 255;
    get_rbd_NFCVehIf_Table_as()[FLDHM].activeState_u8  = 14;
    rbdSessionMgr_ProcessNfcMsg_fake.return_val=RBDSESSIONMGR_E_OK;
    Dkm_NfcFlow_Start_fake.return_val=RTE_E_OK;
    call_rbd_NFCVehIf_NFC_READER_FLDHM_DEVICE_Sig_Callback();
    //EXPECT_EQ(rbd_RfhmIf_ControlFd9Bus_fake.call_count,1);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[FLDHM].connectionStatus_u8,READER_DISCONNECTED);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[FLDHM].Key_Card_Ref_b ,RBDPK_KEYREF_INVALID);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[FLDHM].activeState_u8 ,0X00);//NFC_READER_TAP_ENTRY_FLOW_INIT_STATE_E
    EXPECT_EQ(Dkm_NfcFlow_Start_fake.call_count,0);
}
/*
@rst
    Brief description of test case.
    :Description: if(READER_DISCONNECTED == readerConnection_state_u8) ==> TRUE
        if (RTE_E_OK == Rte_Receive_rbd_NFCVehIf_NFC_READER_FLDHM_RES_Sig_NFC_READER_FLDHM_DEVICE_Sig(FLDHM_NFCResponse_au8, &responseLength_u16)) ==> TRUE
        if ( ((uint8)NFC_SELECT == nfcReaderFLDHMHdr.cmdId_u8 ) && ((uint8)FLDHM == nfcReaderFLDHMHdr.txEcu_u8 ) ) ==> TRUE MCDC (TT)
        if(0u == nfcEntryFailedAttemptCtr_u8) ==> FALSE
        if(doorStatusLastCanBus_en < DOOR_STAT_SNA_EN) ==> TRUE
        if(TRUE == data_validity_u8) ==> TRUE
        if(READER_IN_SESSION == readerConnection_state_u8) ==> FALSE
        if(TRUE == rbd_NFCVehIf_RegisterNFCReaderSession(nfcReaderFLDHMHdr.txEcu_u8)) ==> TRUE
        if(RTE_E_OK == ret) ==> FALSE
    :Arch ID: 890c7d89-e010-4a8c-a683-1d334703fa1b
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NfcIf_NfcReaderCanTPPacketHeaderRead()
    :Description: if((NULL != packetDataIn) && (NULL != nfcReaderDataHeader_ps)) ==> TRUE MCDC (TT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_RegisterNFCReaderSession()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
        if ( READER_DISCONNECTED == rbd_NFCVehIf_Table_as[NfcReaderId_u8].connectionStatus_u8 ) ==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_UpdateNFCReaderState()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
        if(NULL != newDevRef_pu8) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NFC_READER_FLDHM_DEVICE_Sig_Callback_04)
{
    dummy_return = RTE_E_OK;
    dummy_responseLength_u16 = 0;
    dummy_FLDHM_NFCResponse_au8[NFC_COM_ID_BYTE] = (uint8)NFC_SELECT;
    dummy_FLDHM_NFCResponse_au8[NFC_ECU_ID_BYTE] = (uint8)FLDHM;
    Rte_Receive_rbd_NFCVehIf_NFC_READER_FLDHM_RES_Sig_NFC_READER_FLDHM_DEVICE_Sig_fake.custom_fake = Rte_Receive_rbd_NFCVehIf_NFC_READER_FLDHM_RES_Sig_NFC_READER_FLDHM_DEVICE_Sig_custom_fake;
     Rte_rbd_NFCVehIf_FailedAttemptsCounter_MirrorBlock=10;
    Rte_rbd_VSM_PP_DoorStatus_DoorLockLastElSts=50;
    get_rbd_NFCVehIf_Table_as()[FLDHM].connectionStatus_u8  = READER_DISCONNECTED;
    get_rbd_NFCVehIf_Table_as()[FLDHM].Key_Card_Ref_b  = 255;
    get_rbd_NFCVehIf_Table_as()[FLDHM].activeState_u8  = 14;
    rbdSessionMgr_ProcessNfcMsg_fake.return_val=RBDSESSIONMGR_E_OK;
    Dkm_NfcFlow_Start_fake.return_val=RTE_E_INVALID;
    call_rbd_NFCVehIf_NFC_READER_FLDHM_DEVICE_Sig_Callback();
    //EXPECT_EQ(rbd_RfhmIf_ControlFd9Bus_fake.call_count,1);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[FLDHM].connectionStatus_u8,READER_DISCONNECTED);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[FLDHM].Key_Card_Ref_b ,RBDPK_KEYREF_INVALID);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[FLDHM].activeState_u8 ,0X00);//NFC_READER_TAP_ENTRY_FLOW_INIT_STATE_E
    EXPECT_EQ(Dkm_NfcFlow_Start_fake.call_count,0);
}
/*
@rst
    Brief description of test case.
    :Description: if(READER_DISCONNECTED == readerConnection_state_u8) ==> TRUE
        if (RTE_E_OK == Rte_Receive_rbd_NFCVehIf_NFC_READER_FLDHM_RES_Sig_NFC_READER_FLDHM_DEVICE_Sig(FLDHM_NFCResponse_au8, &responseLength_u16)) ==> TRUE
        if ( ((uint8)NFC_SELECT == nfcReaderFLDHMHdr.cmdId_u8 ) && ((uint8)FLDHM == nfcReaderFLDHMHdr.txEcu_u8 ) ) ==> FALSE MCDC (TF)
        if(RTE_E_OK == ret) ==> TRUE
        if ( ( responseLength_u16 <= NFC_MAX_MESSAGE_LEN ) && ( responseLength_u16 != 0U ) ) ==> FALSE MCDC (TF)
    :Arch ID: 890c7d89-e010-4a8c-a683-1d334703fa1b
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

     Calling function rbd_NfcIf_NfcReaderCanTPPacketHeaderRead()
    :Description: if((NULL != packetDataIn) && (NULL != nfcReaderDataHeader_ps)) ==> TRUE MCDC (TT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

     Calling function rbd_NFCVehIf_ReceiveNFCResponse()
    :Description: if (nfcResponseLength_u16 >= (uint16)NFC_PAYLOAD_INIT_BYTE) ==> FALSE
    :Arch ID: 7276a26e-0947-4cfe-a535-ac5f1280e46f
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NFC_READER_FLDHM_DEVICE_Sig_Callback_05)
{
    dummy_return = RTE_E_OK;
    dummy_responseLength_u16 =0;
    dummy_FLDHM_NFCResponse_au8[NFC_COM_ID_BYTE] = (uint8)NFC_SELECT;
    dummy_FLDHM_NFCResponse_au8[NFC_ECU_ID_BYTE] = (uint8)DEFAULT_ECU;
    Rte_Receive_rbd_NFCVehIf_NFC_READER_FLDHM_RES_Sig_NFC_READER_FLDHM_DEVICE_Sig_fake.custom_fake = Rte_Receive_rbd_NFCVehIf_NFC_READER_FLDHM_RES_Sig_NFC_READER_FLDHM_DEVICE_Sig_custom_fake;
    call_rbd_NFCVehIf_NFC_READER_FLDHM_DEVICE_Sig_Callback();
        //Do Nothing
}
/*
@rst
    Brief description of test case.
    :Description: if(READER_DISCONNECTED == readerConnection_state_u8) ==> TRUE
        if (RTE_E_OK == Rte_Receive_rbd_NFCVehIf_NFC_READER_FLDHM_RES_Sig_NFC_READER_FLDHM_DEVICE_Sig(FLDHM_NFCResponse_au8, &responseLength_u16)) ==> TRUE
        if ( ((uint8)NFC_SELECT == nfcReaderFLDHMHdr.cmdId_u8 ) && ((uint8)FLDHM == nfcReaderFLDHMHdr.txEcu_u8 ) ) ==> FALSE MCDC (FX)
        if(RTE_E_OK == ret) ==> TRUE
        if ( ( responseLength_u16 <= NFC_MAX_MESSAGE_LEN ) && ( responseLength_u16 != 0U ) ) ==> FALSE MCDC (TF)
    :Arch ID: 890c7d89-e010-4a8c-a683-1d334703fa1b
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NfcIf_NfcReaderCanTPPacketHeaderRead()
    :Description: if((NULL != packetDataIn) && (NULL != nfcReaderDataHeader_ps)) ==> TRUE MCDC (TT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReceiveNFCResponse()
    :Description: if (nfcResponseLength_u16 >= (uint16)NFC_PAYLOAD_INIT_BYTE) ==> FALSE
    :Arch ID: 7276a26e-0947-4cfe-a535-ac5f1280e46f
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NFC_READER_FLDHM_DEVICE_Sig_Callback_06)
{
    dummy_return = RTE_E_OK;
    dummy_responseLength_u16 =0;
    dummy_FLDHM_NFCResponse_au8[NFC_COM_ID_BYTE] = (uint8)NFC_WRITEBUFFER;
    dummy_FLDHM_NFCResponse_au8[NFC_ECU_ID_BYTE] = (uint8)DEFAULT_ECU;
    Rte_Receive_rbd_NFCVehIf_NFC_READER_FLDHM_RES_Sig_NFC_READER_FLDHM_DEVICE_Sig_fake.custom_fake = Rte_Receive_rbd_NFCVehIf_NFC_READER_FLDHM_RES_Sig_NFC_READER_FLDHM_DEVICE_Sig_custom_fake;
    call_rbd_NFCVehIf_NFC_READER_FLDHM_DEVICE_Sig_Callback();
    //Do Nothing
}
/*
@rst
    Brief description of test case.
    :Description: if(READER_DISCONNECTED == readerConnection_state_u8) ==> TRUE
        if (RTE_E_OK == Rte_Receive_rbd_NFCVehIf_NFC_READER_FLDHM_RES_Sig_NFC_READER_FLDHM_DEVICE_Sig(FLDHM_NFCResponse_au8, &responseLength_u16)) ==> FALSE
    :Arch ID: 890c7d89-e010-4a8c-a683-1d334703fa1b
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NFC_READER_FLDHM_DEVICE_Sig_Callback_07)
{
    dummy_return = RTE_E_INVALID;
    dummy_responseLength_u16 =0;
    Rte_Receive_rbd_NFCVehIf_NFC_READER_FLDHM_RES_Sig_NFC_READER_FLDHM_DEVICE_Sig_fake.custom_fake = Rte_Receive_rbd_NFCVehIf_NFC_READER_FLDHM_RES_Sig_NFC_READER_FLDHM_DEVICE_Sig_custom_fake;
    call_rbd_NFCVehIf_NFC_READER_FLDHM_DEVICE_Sig_Callback();
    //Do Nothing
}
/*
@rst
    Brief description of test case.
    :Description: if(READER_DISCONNECTED == readerConnection_state_u8) ==> TRUE
        if (RTE_E_OK == Rte_Receive_rbd_NFCVehIf_NFC_READER_FLDHM_RES_Sig_NFC_READER_FLDHM_DEVICE_Sig(FLDHM_NFCResponse_au8, &responseLength_u16)) ==> TRUE
        if ( ((uint8)NFC_SELECT == nfcReaderFLDHMHdr.cmdId_u8 ) && ((uint8)FLDHM == nfcReaderFLDHMHdr.txEcu_u8 ) ) ==> TRUE MCDC (TT)
        if(0u == nfcEntryFailedAttemptCtr_u8) ==> FALSE
        if(doorStatusLastCanBus_en < DOOR_STAT_SNA_EN) ==> FALSE
        else if(doorStatusLastNvm_en < DOOR_STAT_SNA_EN) ==> TRUE
        if(TRUE == data_validity_u8) ==> TRUE
        if(READER_IN_SESSION == readerConnection_state_u8) ==> TRUE
        if(TRUE == rbd_NFCVehIf_RegisterNFCReaderSession(nfcReaderFLDHMHdr.txEcu_u8)) ==> FALSE
        if(RTE_E_OK == ret) ==> TRUE
        if((responseLength_u16 <= NFC_MAX_MESSAGE_LEN) && (responseLength_u16 != 0U)) ==> TRUE MCDC (TT)
    :Arch ID: 890c7d89-e010-4a8c-a683-1d334703fa1b
    :REQ ID: NA
    :ALM Task ID: 92308
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NfcIf_NfcReaderCanTPPacketHeaderRead()
    :Description: if((NULL != packetDataIn) && (NULL != nfcReaderDataHeader_ps)) ==> TRUE MCDC (TT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_RegisterNFCReaderSession()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
        if ( READER_DISCONNECTED == rbd_NFCVehIf_Table_as[NfcReaderId_u8].connectionStatus_u8 ) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReceiveNFCResponse()
    :Description: if (nfcResponseLength_u16 >= (uint16)NFC_PAYLOAD_INIT_BYTE) ==> TRUE
       if (nfcReaderHdr.cmdId_u8 == (uint8)NFC_STATUS) ==> FALSE
       else if (nfcReaderHdr.cmdId_u8 == NFC_FAILUREMODE) ==> FALSE
       else if (nfcReaderHdr.cmdId_u8 == NFC_DETECTEDUIDS) ==> FALSE
    :Arch ID: 7276a26e-0947-4cfe-a535-ac5f1280e46f
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ProcessCCCResponse()
     :Description: iif (((uint8)NFC_SELECT == nfcReaderHdr.cmdId_u8) && (nfcReaderHdr.txEcu_u8 == (uint8)WCPM2)) ==> FALSE MCDC (TF)
        if (RBDSESSIONMGR_E_OK != rbdSessionMgr_ProcessNfcMsg(nfcReaderHdr.txEcu_u8, nfcReaderHdr.payloadLength_u16, &nfcResponse_pt[NFC_PAYLOAD_INIT_BYTE]))  ==> FALSE
    :Arch ID: 49f43eea-398d-4c8a-9e33-32f47cb85c79
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NFC_READER_FLDHM_DEVICE_Sig_Callback_08)
{
    dummy_return = RTE_E_OK;
    dummy_responseLength_u16 = 263;
    dummy_FLDHM_NFCResponse_au8[NFC_COM_ID_BYTE] = (uint8)NFC_SELECT;
    dummy_FLDHM_NFCResponse_au8[NFC_ECU_ID_BYTE] = (uint8)FLDHM;
    Rte_Receive_rbd_NFCVehIf_NFC_READER_FLDHM_RES_Sig_NFC_READER_FLDHM_DEVICE_Sig_fake.custom_fake = Rte_Receive_rbd_NFCVehIf_NFC_READER_FLDHM_RES_Sig_NFC_READER_FLDHM_DEVICE_Sig_custom_fake;
     Rte_rbd_NFCVehIf_FailedAttemptsCounter_MirrorBlock=10;
    Rte_rbd_VSM_PP_DoorStatus_DoorLockLastElSts=5;
    get_rbd_NFCVehIf_Table_as()[FLDHM].connectionStatus_u8  = READER_IN_SESSION ;
    get_rbd_NFCVehIf_Table_as()[FLDHM].Key_Card_Ref_b  = 255;
    get_rbd_NFCVehIf_Table_as()[FLDHM].activeState_u8  = 14;
    rbdSessionMgr_ProcessNfcMsg_fake.return_val=RBDSESSIONMGR_E_OK;
    Dkm_NfcFlow_Start_fake.return_val=RTE_E_OK;
    dummy_dataType.SPKVEHUSG=FALSE;
    Rte_Read_rbd_NFCVehIf_RP_drmServices_drmServices_fake.custom_fake=Rte_Read_rbd_NFCVehIf_RP_drmServices_drmServices_custom_fake;
    call_rbd_NFCVehIf_NFC_READER_FLDHM_DEVICE_Sig_Callback();
    //EXPECT_EQ(rbd_RfhmIf_ControlFd9Bus_fake.call_count,1);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[FLDHM].connectionStatus_u8,READER_DISCONNECTED);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[FLDHM].Key_Card_Ref_b ,RBDPK_KEYREF_INVALID);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[FLDHM].activeState_u8 ,0X00);
    //EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[FLDHM].session_timeout_u16 ,6000u);//NFC_SESSION_TIMEOUT
    EXPECT_EQ(rbdSessionMgr_ProcessNfcMsg_fake.call_count,1);
    EXPECT_EQ(Dkm_NfcFlow_Start_fake.call_count,0);
    EXPECT_EQ(rbdSessionMgr_NfcDisconnected_fake.call_count,0);
}
/*
@rst
    Brief description of test case.
    :Description: if(READER_DISCONNECTED == readerConnection_state_u8) ==> FALSE
    :Arch ID: 890c7d89-e010-4a8c-a683-1d334703fa1b
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 ) && ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC(TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 270909
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NFC_READER_FLDHM_DEVICE_Sig_Callback_09)
{
    get_rbd_NFCVehIf_Table_as()[(uint8)WCPM2].activeState_u8=0X00;//NFC_READER_NOT_ACTIVE_STATE_E
    get_rbd_NFCVehIf_Table_as()[(uint8)WCPM2].connectionStatus_u8=READER_IN_SESSION;
    get_rbd_NFCVehIf_Table_as()[(uint8)WCPM2].Key_Card_Ref_b=TRUE;
    call_rbd_NFCVehIf_NFC_READER_FLDHM_DEVICE_Sig_Callback();
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[(uint8)WCPM2].connectionStatus_u8 ,READER_IN_SESSION);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[(uint8)WCPM2].Key_Card_Ref_b,TRUE);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[(uint8)WCPM2].activeState_u8,0X00);//(uint8)NFC_READER_NOT_ACTIVE_STATE_E
    //Do Nothing
}
//----------------------------------------------------------------------------
// Test Cases// FUNC(void, rbd_NFCVehIf_CODE) rbd_NFCVehIf_NFC_READER_FRDHM_DEVICE_Sig_Callback(void)
//----------------------------------------------------------------------------
/*
@rst
    Brief description of test case.
    :Description: if (RTE_E_OK == Rte_Receive_rbd_NFCVehIf_NFC_READER_FRDHM_RES_Sig_NFC_READER_FRDHM_DEVICE_Sig(FRDHM_NFCResponse_au8, &responseLength_u16)) ==> FALSE
    :Arch ID: fb28bead-fb8f-4b7b-8d87-d4d92d201a1b
    :REQ ID: NA
    :ALM Task ID: 183001
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NFC_READER_FRDHM_DEVICE_Sig_Callback_01)
{
    dummy_data1 = RTE_E_INVALID;
    Rte_Receive_rbd_NFCVehIf_NFC_READER_FRDHM_RES_Sig_NFC_READER_FRDHM_DEVICE_Sig_fake.custom_fake = Rte_Receive_rbd_NFCVehIf_NFC_READER_FRDHM_RES_Sig_NFC_READER_FRDHM_DEVICE_Sig_custom_fake;
    call_rbd_NFCVehIf_NFC_READER_FRDHM_DEVICE_Sig_Callback();
}

/*
@rst
    Brief description of test case.
    :Description: if (RTE_E_OK == Rte_Receive_rbd_NFCVehIf_NFC_READER_FRDHM_RES_Sig_NFC_READER_FRDHM_DEVICE_Sig(FRDHM_NFCResponse_au8, &responseLength_u16)) ==> TRUE
        if((responseLength_u16 <= NFC_MAX_MESSAGE_LEN) && (responseLength_u16 != 0U)) ==> TRUE, MCDC(TT)
    :Arch ID: fb28bead-fb8f-4b7b-8d87-d4d92d201a1b
    :REQ ID: NA
    :ALM Task ID: 183001
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReceiveNFCResponse()
    :Description: if (nfcResponseLength_u16 >= (uint16)NFC_PAYLOAD_INIT_BYTE) ==> FALSE
    :Arch ID: 7276a26e-0947-4cfe-a535-ac5f1280e46f
    :REQ ID: NA
    :ALM Task ID: 183001
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NFC_READER_FRDHM_DEVICE_Sig_Callback_02)
{
    dummy_data1 = RTE_E_OK;
    dummy_length = 3;
    Rte_Receive_rbd_NFCVehIf_NFC_READER_FRDHM_RES_Sig_NFC_READER_FRDHM_DEVICE_Sig_fake.custom_fake = Rte_Receive_rbd_NFCVehIf_NFC_READER_FRDHM_RES_Sig_NFC_READER_FRDHM_DEVICE_Sig_custom_fake;
    call_rbd_NFCVehIf_NFC_READER_FRDHM_DEVICE_Sig_Callback();
}

/*
@rst
    Brief description of test case.
    :Description: if (RTE_E_OK == Rte_Receive_rbd_NFCVehIf_NFC_READER_FRDHM_RES_Sig_NFC_READER_FRDHM_DEVICE_Sig(FRDHM_NFCResponse_au8, &responseLength_u16)) ==> TRUE
        if((responseLength_u16 <= NFC_MAX_MESSAGE_LEN) && (responseLength_u16 != 0U)) ==> TRUE, MCDC(TF)
    :Arch ID: fb28bead-fb8f-4b7b-8d87-d4d92d201a1b
    :REQ ID: NA
    :ALM Task ID: 183001
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReceiveNFCResponse()
    :Description: if (nfcResponseLength_u16 >= (uint16)NFC_PAYLOAD_INIT_BYTE) ==> FALSE
    :Arch ID: 7276a26e-0947-4cfe-a535-ac5f1280e46f
    :REQ ID: NA
    :ALM Task ID: 183001
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NFC_READER_FRDHM_DEVICE_Sig_Callback_03)
{
    dummy_data1 = RTE_E_OK;
    dummy_length = 0;
    Rte_Receive_rbd_NFCVehIf_NFC_READER_FRDHM_RES_Sig_NFC_READER_FRDHM_DEVICE_Sig_fake.custom_fake = Rte_Receive_rbd_NFCVehIf_NFC_READER_FRDHM_RES_Sig_NFC_READER_FRDHM_DEVICE_Sig_custom_fake;
    call_rbd_NFCVehIf_NFC_READER_FRDHM_DEVICE_Sig_Callback();
}

/*
@rst
    Brief description of test case.
    :Description: if (RTE_E_OK == Rte_Receive_rbd_NFCVehIf_NFC_READER_FRDHM_RES_Sig_NFC_READER_FRDHM_DEVICE_Sig(FRDHM_NFCResponse_au8, &responseLength_u16)) ==> TRUE
        if((responseLength_u16 <= NFC_MAX_MESSAGE_LEN) && (responseLength_u16 != 0U)) ==> TRUE, MCDC(FX)
    :Arch ID: fb28bead-fb8f-4b7b-8d87-d4d92d201a1b
    :REQ ID: NA
    :ALM Task ID: 183001
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReceiveNFCResponse()
    :Description: if (nfcResponseLength_u16 >= (uint16)NFC_PAYLOAD_INIT_BYTE) ==> TRUE
        if (nfcResponse_pt[NFC_COM_ID_BYTE] == NFC_STATUS) ==> FALSE
        else if (nfcResponse_pt[NFC_COM_ID_BYTE] == NFC_FAILUREMODE) ==> FALSE
        else if (nfcResponse_pt[NFC_COM_ID_BYTE] == NFC_DETECTEDUIDS) ==> TRUE
    :Arch ID: 7276a26e-0947-4cfe-a535-ac5f1280e46f
    :REQ ID: NA
    :ALM Task ID: 183001
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NFC_READER_FRDHM_DEVICE_Sig_Callback_04)
{
    dummy_data1 = RTE_E_OK;
    dummy_length = 264;
    dummy_FRDHM_NFCResponse_au8[NFC_COM_ID_BYTE] = NFC_DETECTEDUIDS;
    Rte_Receive_rbd_NFCVehIf_NFC_READER_FRDHM_RES_Sig_NFC_READER_FRDHM_DEVICE_Sig_fake.custom_fake = Rte_Receive_rbd_NFCVehIf_NFC_READER_FRDHM_RES_Sig_NFC_READER_FRDHM_DEVICE_Sig_custom_fake;
    call_rbd_NFCVehIf_NFC_READER_FRDHM_DEVICE_Sig_Callback();
}

//----------------------------------------------------------------------------
// Test Cases// FUNC(void, rbd_NFCVehIf_CODE) rbd_NFCVehIf_NFC_READER_WCPM2_DEVICE_Sig_Callback(void)
//----------------------------------------------------------------------------
/*
@rst
    Brief description of test case.
    :Description: if (RTE_E_OK == Rte_Receive_rbd_NFCVehIf_NFC_READER_WCPM2_RES_Sig_NFC_READER_WCPM2_DEVICE_Sig(WCPM2_NFCResponse_au8, &responseLength_u16)) ==> FALSE
    :Arch ID: 577f2e7f-1b9a-4f71-ad45-9eea8e4b9ba2
    :REQ ID: NA
    :ALM Task ID: 183001
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NFC_READER_WCPM2_DEVICE_Sig_Callback_01)
{
    dummy_data2 = RTE_E_INVALID;
    Rte_Receive_rbd_NFCVehIf_NFC_READER_WCPM2_RES_Sig_NFC_READER_WCPM2_DEVICE_Sig_fake.custom_fake = Rte_Receive_rbd_NFCVehIf_NFC_READER_WCPM2_RES_Sig_NFC_READER_WCPM2_DEVICE_Sig_custom_fake;
    call_rbd_NFCVehIf_NFC_READER_WCPM2_DEVICE_Sig_Callback();
}
/*
@rst
    Brief description of test case.
    :Description: if (RTE_E_OK == Rte_Receive_rbd_NFCVehIf_NFC_READER_WCPM2_RES_Sig_NFC_READER_WCPM2_DEVICE_Sig(WCPM2_NFCResponse_au8, &responseLength_u16)) ==> TRUE
        if((uint8)WCPM2 == nfcReaderWCPM2MHdr.txEcu_u8 ) ==> TRUE
        if((responseLength_u16 <= NFC_MAX_MESSAGE_LEN) && (responseLength_u16 != 0U)) ==> FALSE, MCDC(TF)
    :Arch ID: 577f2e7f-1b9a-4f71-ad45-9eea8e4b9ba2
    :REQ ID: NA
    :ALM Task ID: 183001
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReceiveNFCResponse()
    :Description: if (nfcResponseLength_u16 >= (uint16)NFC_PAYLOAD_INIT_BYTE) ==> FALSE
    :Arch ID: 7276a26e-0947-4cfe-a535-ac5f1280e46f
    :REQ ID: NA
    :ALM Task ID: 183001
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NFC_READER_WCPM2_DEVICE_Sig_Callback_02)
{
    dummy_data2 = RTE_E_OK;
    dummy_length1 = 0;
    dummy1_FRDHM_NFCResponse_au8[NFC_ECU_ID_BYTE] = 2;
    Rte_Receive_rbd_NFCVehIf_NFC_READER_WCPM2_RES_Sig_NFC_READER_WCPM2_DEVICE_Sig_fake.custom_fake = Rte_Receive_rbd_NFCVehIf_NFC_READER_WCPM2_RES_Sig_NFC_READER_WCPM2_DEVICE_Sig_custom_fake;
    call_rbd_NFCVehIf_NFC_READER_WCPM2_DEVICE_Sig_Callback();
}
/*
@rst
    Brief description of test case.
    :Description: if (RTE_E_OK == Rte_Receive_rbd_NFCVehIf_NFC_READER_WCPM2_RES_Sig_NFC_READER_WCPM2_DEVICE_Sig(WCPM2_NFCResponse_au8, &responseLength_u16)) ==> TRUE
        if((responseLength_u16 <= NFC_MAX_MESSAGE_LEN) && (responseLength_u16 != 0U)) ==> FALSE, MCDC(FX)
    :Arch ID: 577f2e7f-1b9a-4f71-ad45-9eea8e4b9ba2
    :REQ ID: NA
    :ALM Task ID: 183001
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReceiveNFCResponse()
    :Description: if (nfcResponseLength_u16 >= (uint16)NFC_PAYLOAD_INIT_BYTE) ==> FALSE
        if (nfcResponse_pt[NFC_COM_ID_BYTE] == NFC_STATUS) ==> FALSE
        else if (nfcResponse_pt[NFC_COM_ID_BYTE] == NFC_FAILUREMODE) ==> TRUE
    :Arch ID: 7276a26e-0947-4cfe-a535-ac5f1280e46f
    :REQ ID: NA
    :ALM Task ID: 183001
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NFC_READER_WCPM2_DEVICE_Sig_Callback_03)
{
    dummy_data2 = RTE_E_OK;
    dummy_length1 = 300;
    dummy1_FRDHM_NFCResponse_au8[NFC_COM_ID_BYTE] = NFC_FAILUREMODE;
    Rte_Receive_rbd_NFCVehIf_NFC_READER_WCPM2_RES_Sig_NFC_READER_WCPM2_DEVICE_Sig_fake.custom_fake = Rte_Receive_rbd_NFCVehIf_NFC_READER_WCPM2_RES_Sig_NFC_READER_WCPM2_DEVICE_Sig_custom_fake;
    call_rbd_NFCVehIf_NFC_READER_WCPM2_DEVICE_Sig_Callback();
}

/*
@rst
    Brief description of test case.
    :Description: if (RTE_E_OK == Rte_Receive_rbd_NFCVehIf_NFC_READER_WCPM2_RES_Sig_NFC_READER_WCPM2_DEVICE_Sig(WCPM2_NFCResponse_au8, &responseLength_u16)) ==> TRUE
        if((responseLength_u16 <= NFC_MAX_MESSAGE_LEN) && (responseLength_u16 != 0U)) ==> TRUE, MCDC(TT)
    :Arch ID: 577f2e7f-1b9a-4f71-ad45-9eea8e4b9ba2
    :REQ ID: NA
    :ALM Task ID: 183001
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReceiveNFCResponse()
    :Description: if (nfcResponseLength_u16 >= (uint16)NFC_PAYLOAD_INIT_BYTE) ==> TRUE
        if (nfcResponse_pt[NFC_COM_ID_BYTE] == NFC_STATUS) ==> TRUE
        switch (nfcResponse_pt[NFC_PAYLOAD_INIT_BYTE])
        default:
        if (rbd_NFCVehIf_Table_as[ecuRxId_u8].connectionStatus_u8 == READER_IN_SESSION) ==> FALSE
        if (rbd_NFCVehIf_Table_as[ecuRxId_u8].activeUseCase_u8 == CARD_PLANT_PAIR) ==> FALSE
        else if (rbd_NFCVehIf_Table_as[ecuRxId_u8].activeUseCase_u8 == CARD_PLANT_TEST) ==> FALSE
    :Arch ID: 7276a26e-0947-4cfe-a535-ac5f1280e46f
    :REQ ID: NA
    :ALM Task ID: 183001
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NFC_READER_WCPM2_DEVICE_Sig_Callback_04)
{
    dummy_data2 = RTE_E_OK;
    dummy_length1 = 30;
    dummy1_FRDHM_NFCResponse_au8[NFC_COM_ID_BYTE] = NFC_STATUS;
    dummy1_FRDHM_NFCResponse_au8[NFC_PAYLOAD_INIT_BYTE] = 11;
    dummy1_FRDHM_NFCResponse_au8[NFC_ECU_ID_BYTE] = 0;
    get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8 = READER_DISCONNECTED;
    // get_rbd_NFCVehIf_Table_as()[0].activeUseCase_u8 = READER_DISCONNECTED;
    Rte_Receive_rbd_NFCVehIf_NFC_READER_WCPM2_RES_Sig_NFC_READER_WCPM2_DEVICE_Sig_fake.custom_fake = Rte_Receive_rbd_NFCVehIf_NFC_READER_WCPM2_RES_Sig_NFC_READER_WCPM2_DEVICE_Sig_custom_fake;
    call_rbd_NFCVehIf_NFC_READER_WCPM2_DEVICE_Sig_Callback();
}

//----------------------------------------------------------------------------
// Test Cases// FUNC(Std_ReturnType, rbd_NFCVehIf_CODE) rbd_NFCVehIf_Test_SmartCard_Pairing_Start_RequestResults(P2VAR(uint8, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR) ErrorCode)
//----------------------------------------------------------------------------
/*
@rst
    Brief description of test case.
    :Description: for (uint8 i_u8 = 0; i_u8 < NFC_CARD_UID_LEN; ++i_u8) ==> TRUE, FALSE
    :Arch ID: 03ad2c10-cec0-4224-afd6-adffc6fba2d3
    :REQ ID: NA
    :ALM Task ID: 183001
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_Test_SmartCard_Pairing_Start_RequestResults_01)
{
    uint8 Out_ResData[20];
    Dcm_NegativeResponseCodeType ErrorCode;
    Std_ReturnType ret_val = call_rbd_NFCVehIf_Test_SmartCard_Pairing_Start_RequestResults(Out_ResData,&ErrorCode);
    EXPECT_EQ(RTE_E_OK,ret_val);
    // for (uint8 i_u8 = 0; i_u8 < NFC_CARD_UID_LEN; ++i_u8)
    // {
    //     EXPECT_EQ(Out_ResData[2+i_u8],get_rbd_NFCVehIf_CardData_st()->cardUID_au8[i_u8]);
    // }Code removed
    EXPECT_EQ(ErrorCode,DCM_E_POSITIVERESPONSE);
}

//----------------------------------------------------------------------------
// Test Cases// FUNC(Std_ReturnType, rbd_NFCVehIf_CODE) rbd_NFCVehIf_Test_SmartCard_Pairing_Start_Start(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR) ErrorCode)
//----------------------------------------------------------------------------
/*
@rst
    Brief description of test case.
    :Description: if (FALSE == rbd_NFCVehIf_IsRoutineInProgress()) ==> FALSE
    :Arch ID: 9bebccd0-f689-4a32-bd6d-49ec77d76d4b
    :REQ ID: NA
    :ALM Task ID: 288528
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    rbd_NFCVehIf_IsRoutineInProgress:
    :Description: if ( ( rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_PLANT_PAIRING_E].nfcRoutineStatus == (uint8)NFC_ROUTINE_STATUS_IN_PROGRESS_E ) || ( rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_TEST_CARD_PAIRING_E].nfcRoutineStatus == (uint8)NFC_ROUTINE_STATUS_IN_PROGRESS_E ) || ( rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_GET_UID_E].nfcRoutineStatus == (uint8)NFC_ROUTINE_STATUS_IN_PROGRESS_E ) ) ==> TRUE MCDC(FTX)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 288528
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_Test_SmartCard_Pairing_Start_Start_01)
{
    Dcm_NegativeResponseCodeType ErrorCode;
    get_rbd_NFCVehIf_RoutineData_S()[0].mock_nfcRoutineStatus = 0x01u;
    get_rbd_NFCVehIf_RoutineData_S()[1].mock_nfcRoutineStatus = 0x02u;
    Std_ReturnType ret_val = call_rbd_NFCVehIf_Test_SmartCard_Pairing_Start_Start(&ErrorCode);
    EXPECT_EQ(E_NOT_OK,ret_val);
    EXPECT_EQ(ErrorCode,DCM_E_GENERALREJECT);
}
/*
@rst
    Brief description of test case.
    :Description: if (FALSE == rbd_NFCVehIf_IsRoutineInProgress()) ==> TRUE
    :Arch ID: 9bebccd0-f689-4a32-bd6d-49ec77d76d4b
    :REQ ID: NA
    :ALM Task ID: 288528
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    rbd_NFCVehIf_IsRoutineInProgress:
    :Description: if ( ( rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_PLANT_PAIRING_E].nfcRoutineStatus == (uint8)NFC_ROUTINE_STATUS_IN_PROGRESS_E ) || ( rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_TEST_CARD_PAIRING_E].nfcRoutineStatus == (uint8)NFC_ROUTINE_STATUS_IN_PROGRESS_E ) || ( rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_GET_UID_E].nfcRoutineStatus == (uint8)NFC_ROUTINE_STATUS_IN_PROGRESS_E ) ) ==> FALSE MCDC(FFF)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 288528
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_Test_SmartCard_Pairing_Start_Start_02)
{
    Dcm_NegativeResponseCodeType ErrorCode;
    for(uint8 i =0; i<3; i++){
        get_rbd_NFCVehIf_RoutineData_S()[i].mock_nfcRoutineStatus = 0x03u;
        }
    Std_ReturnType ret_val = call_rbd_NFCVehIf_Test_SmartCard_Pairing_Start_Start(&ErrorCode);
    EXPECT_EQ(E_OK, ret_val);
    EXPECT_EQ(ErrorCode, DCM_E_POSITIVERESPONSE);
    EXPECT_EQ(get_rbd_NFCVehIf_RoutineData_S()[1].mock_DiagRoutine_State_en, mock_NFC_DIAG_ROUTINE_REQUEST_RX_STATE_E);
}

//----------------------------------------------------------------------------
// Test Cases// uint8 rbd_NFCVehIf_MapCCCToNFC(const uint16 cccCommandId_u16)
//----------------------------------------------------------------------------
/*
@rst
    Brief description of test case.
    :Description: for (uint8 i_u8 = 0; i_u8 < CCC_COMMAND_COUNT; ++i_u8) ==> TRUE
        if(cccCommandId_u16 == commandIdMapTable[CCC_ID_ROW][i_u8]) ==> TRUE
    :Arch ID: 3705cb92-efea-4c09-b80e-6dab1d21753e
    :REQ ID: NA
    :ALM Task ID: 183001
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_MapCCCToNFC_01)
{
    uint8 ret_val = call_rbd_NFCVehIf_MapCCCToNFC(CCC_SELECT);
    EXPECT_EQ(ret_val, 3);
}


//----------------------------------------------------------------------------
// Test Cases// void rbd_NFCVehIf_SetOwnerPairingMode(boolean const Enable)
//----------------------------------------------------------------------------
/*
@rst
    Brief description of test case.
    :Description: if (Enable == TRUE) ==> FALSE
    :Arch ID: 871b9a76-3d6a-4b71-a4bb-944d21644ef5
    :REQ ID: NA
    :ALM Task ID: 183001
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_SetOwnerPairingMode_01)
{
    call_rbd_NFCVehIf_SetOwnerPairingMode(FALSE);
}

/*
@rst
    Brief description of test case.
    :Description: if (Enable == TRUE) ==> TRUE
    :Arch ID: 871b9a76-3d6a-4b71-a4bb-944d21644ef5
    :REQ ID: NA
    :ALM Task ID: 183001
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_SetOwnerPairingMode_02)
{
    call_rbd_NFCVehIf_SetOwnerPairingMode(TRUE);
    // EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[WCPM2].activeUseCase_u8,(uint8)OWNER_PAIRING);
    EXPECT_EQ(rbdSessionMgr_NfcConnected_fake.call_count,1);
}
//----------------------------------------------------------------------------
// Test Cases// boolean rbd_NFCVehIf_SendNfcMsg(const rbdPk_NfcReaderId_t nfcReaderId, const uint16 Length, const uint8* const Data)
//----------------------------------------------------------------------------
/*
@rst
    Brief description of test case.
    :Description: if ((Length > CCC_ID_LENGTH) && (Length < MAX_LENGTH_CAPDU) ==> FALSE, MCDC(FX)
    :Arch ID: d9c3a5f0-42f9-4ab1-ac2a-b4998733c735
    :REQ ID: NA
    :ALM Task ID: 183001
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_SendNfcMsg_01)
{
   boolean ret_val = call_rbd_NFCVehIf_SendNfcMsg(1,1,NULL);
   EXPECT_EQ(FALSE,ret_val);
}
/*
@rst
    Brief description of test case.
    :Description: if ((Length > CCC_ID_LENGTH) && (Length < MAX_LENGTH_CAPDU) ==> FALSE, MCDC(TF)
    :Arch ID: d9c3a5f0-42f9-4ab1-ac2a-b4998733c735
    :REQ ID: NA
    :ALM Task ID: 183001
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_SendNfcMsg_02)
{
   boolean ret_val = call_rbd_NFCVehIf_SendNfcMsg(1,MAX_LENGTH_CAPDU,NULL);
   EXPECT_EQ(FALSE,ret_val);
}

/*
@rst
    Brief description of test case.
    :Description: if ((Length > CCC_ID_LENGTH) && (Length < MAX_LENGTH_CAPDU) ==> TRUE, MCDC(TT)
        if(RTE_E_OK == rbd_NFCVehIf_WritePort(nfcReaderId, rbd_NFCVehIf_Request_au8, requestLength_u16)) ==> FALSE
        if (requestLength_u16 <= MAX_LENGTH_CAPDU) ==> FALSE
    :Arch ID: d9c3a5f0-42f9-4ab1-ac2a-b4998733c735
    :REQ ID: NA
    :ALM Task ID: 183001
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_MapCCCToNFC()
    :Description: for (uint8 i_u8 = 0; i_u8 < CCC_COMMAND_COUNT; ++i_u8) ==> TRUE, FALSE
        if(cccCommandId_u16 == commandIdMapTable[CCC_ID_ROW][i_u8]) ==> FALSE
    :Arch ID: 3705cb92-efea-4c09-b80e-6dab1d21753e
    :REQ ID: NA
    :ALM Task ID: 183001
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_PrepNFCBuffer()
    :Description: if( (payLen_u16 <= (MAX_LENGTH_CAPDU - NFC_PAYLOAD_INIT_BYTE - 1U)) && (payLen_u16 != 0U) ) ==> FALSE, MCDC(FX)
    :Arch ID: 65a7df42-776e-4509-bbc2-606f3e4b772d
    :REQ ID: NA
    :ALM Task ID: 183001
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_WritePort()
    :Description: if (dest_u8 == (uint8)FLDHM) ==> TRUE
    :Arch ID: 768d42bb-df4d-4b75-bd0c-10cdf4ab93ae
    :REQ ID: NA
    :ALM Task ID: 183001
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_SendNfcMsg_03)
{
     uint8 Data[20] ={0};
    Rte_Send_rbd_NFCVehIf_NFC_READER_REQ_FLDHM_Sig_NFC_READER_DEVICE_2_Sig_fake.return_val = RTE_E_INVALID; //RTE_E_OK
    boolean ret_val = call_rbd_NFCVehIf_SendNfcMsg(FLDHM,260,Data);
    EXPECT_EQ(FALSE,ret_val);
    EXPECT_EQ(Rte_Send_rbd_NFCVehIf_NFC_READER_REQ_FLDHM_Sig_NFC_READER_DEVICE_2_Sig_fake.call_count,1);
}
/*
@rst
    Brief description of test case.
    :Description: if ((Length > CCC_ID_LENGTH) && (Length < MAX_LENGTH_CAPDU) ==> TRUE, MCDC(TT)
        if(RTE_E_OK == rbd_NFCVehIf_WritePort(nfcReaderId, rbd_NFCVehIf_Request_au8, requestLength_u16)) ==> TRUE
        if (requestLength_u16 <= MAX_LENGTH_CAPDU) ==> TRUE
    :Arch ID: d9c3a5f0-42f9-4ab1-ac2a-b4998733c735
    :REQ ID: NA
    :ALM Task ID: 183001
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_MapCCCToNFC()
    :Description: for (uint8 i_u8 = 0; i_u8 < CCC_COMMAND_COUNT; ++i_u8) ==> TRUE, FALSE
        if(cccCommandId_u16 == commandIdMapTable[CCC_ID_ROW][i_u8]) ==> TRUE
    :Arch ID: 3705cb92-efea-4c09-b80e-6dab1d21753e
    :REQ ID: NA
    :ALM Task ID: 183001
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_PrepNFCBuffer()
    :Description: if( (payLen_u16 <= (MAX_LENGTH_CAPDU - NFC_PAYLOAD_INIT_BYTE - 1U)) && (payLen_u16 != 0U) ) ==> FALSE, MCDC(FX)
    :Arch ID: 65a7df42-776e-4509-bbc2-606f3e4b772d
    :REQ ID: NA
    :ALM Task ID: 183001
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_WritePort()
    :Description: if (dest_u8 == (uint8)FLDHM) ==> FALSE
        else if (dest_u8 == (uint8)FRDHM) ==> TRUE
    :Arch ID: 768d42bb-df4d-4b75-bd0c-10cdf4ab93ae
    :REQ ID: NA
    :ALM Task ID: 183001
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_SendNfcMsg_04)
{
    uint8 Data[20] ={0};
    //cccComId_u16 = (((uint16)Data[CCC_CLA_BYTE]) << 8) | ((uint16)Data[CCC_INS_BYTE]);
    Data[CCC_CLA_BYTE] = 1;
    Data[CCC_INS_BYTE] = 0;
    Rte_Send_rbd_NFCVehIf_NFC_READER_REQ_FRDHM_Sig_NFC_READER_DEVICE_3_Sig_fake.return_val = RTE_E_OK;
    boolean ret_val = call_rbd_NFCVehIf_SendNfcMsg(FRDHM,258,Data);
    EXPECT_EQ(TRUE,ret_val);
    EXPECT_EQ(Rte_Send_rbd_NFCVehIf_NFC_READER_REQ_FRDHM_Sig_NFC_READER_DEVICE_3_Sig_fake.call_count,1);
}

//----------------------------------------------------------------------------
// Test Cases// void rbd_NFCVehIf_ReceiveNFCResponse(const uint8 *nfcResponse_pt, const uint16 nfcResponseLength_u16)
//----------------------------------------------------------------------------
/*
@rst
    Brief description of test case.
    :Description: if (nfcResponseLength_u16 >= (uint16)NFC_PAYLOAD_INIT_BYTE) ==> TRUE
        if (nfcReaderHdr.cmdId_u8 == (uint8)NFC_STATUS) ==> TRUE
        switch (nfcResponse_pt[NFC_PAYLOAD_INIT_BYTE])
        case READY:
        if((FALSE == rbd_NFCVehIf_IsDeselectRetryTmr_Expired()) && (session_state_u8 != (uint8)NFC_READER_CARD_PLANT_PAIR_STATE_E)) ==> FALSE MCDC (FX)
        if ((uint8)nfcReaderHdr.txEcu_u8 == (uint8)FLDHM) ==> FALSE
        if (((uint8)NFC_READER_TAP_START_STOP_TRIGGER_STATE_E == session_state_u8) ||
            ((uint8)NFC_READER_OWNER_PAIRING_TEAR_DOWN_STATE_E == session_state_u8) ||
            ((uint8)NFC_READER_CARD_PLANT_PAIR_TEAR_DOWN_STATE_E == session_state_u8) ||
            ((uint8)NFC_READER_CARD_PLANT_TEST_TEAR_DOWN_STATE_E == session_state_u8) ||
            ((uint8)NFC_READER_PHONE_ENABLE_DISABLE_WCP_AUTH_FINISH_STATE_E == session_state_u8)) ==> FALSE MCDC(FFFFF)
    :Arch ID: 7276a26e-0947-4cfe-a535-ac5f1280e46f
    :REQ ID: NA
    :ALM Task ID: 286698
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NfcIf_NfcReaderCanTPPacketHeaderRead()
    :Description: if((NULL != packetDataIn) && (NULL != nfcReaderDataHeader_ps)) ==> TRUE MCDC (TT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_ReceiveNFCResponse_01)
{
    uint8 nfcResponse_pt[20] = {0};
    nfcResponse_pt[NFC_COM_ID_BYTE] = (uint8)NFC_STATUS;
    nfcResponse_pt[NFC_PAYLOAD_INIT_BYTE] = READY;
    nfcResponse_pt[NFC_ECU_ID_BYTE] = 02;
    get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8  = 255;
    get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b  = 255;
    get_rbd_NFCVehIf_Table_as()[2].activeState_u8  = 0x62u;//NFC_READER_CARD_PLANT_PAIR_STATE_E
    get_rbd_NFCVehIf_DeselectInfo_S()->mock_uRetryFinish_u8 = 1;
    call_rbd_NFCVehIf_ReceiveNFCResponse(nfcResponse_pt,NFC_PAYLOAD_INIT_BYTE);
    EXPECT_EQ(rbdSessionMgr_NfcReady_fake.call_count,1);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8,255);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b ,255);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].activeState_u8 ,0x62u);//NFC_READER_CARD_PLANT_PAIR_STATE_E
}
/*
@rst
    Brief description of test case.
    :Description: if (nfcResponseLength_u16 >= (uint16)NFC_PAYLOAD_INIT_BYTE) ==> TRUE
        if (nfcReaderHdr.cmdId_u8 == (uint8)NFC_STATUS) ==> TRUE
        switch (nfcResponse_pt[NFC_PAYLOAD_INIT_BYTE])
        case READY:
        if((FALSE == rbd_NFCVehIf_IsDeselectRetryTmr_Expired()) && (session_state_u8 != (uint8)NFC_READER_CARD_PLANT_PAIR_STATE_E)) ==> TRUE MCDC (TT)
        if ((uint8)nfcReaderHdr.txEcu_u8 == (uint8)FLDHM) ==> TRUE
        if (((uint8)NFC_READER_TAP_START_STOP_TRIGGER_STATE_E == session_state_u8) ||
            ((uint8)NFC_READER_OWNER_PAIRING_TEAR_DOWN_STATE_E == session_state_u8) ||
            ((uint8)NFC_READER_CARD_PLANT_PAIR_TEAR_DOWN_STATE_E == session_state_u8) ||
            ((uint8)NFC_READER_CARD_PLANT_TEST_TEAR_DOWN_STATE_E == session_state_u8) ||
            ((uint8)NFC_READER_PHONE_ENABLE_DISABLE_WCP_AUTH_FINISH_STATE_E == session_state_u8)) ==> TRUE MCDC(FFFFT)
    :Arch ID: 7276a26e-0947-4cfe-a535-ac5f1280e46f
    :REQ ID: NA
    :ALM Task ID: 286698
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NfcIf_NfcReaderCanTPPacketHeaderRead()
    :Description: if((NULL != packetDataIn) && (NULL != nfcReaderDataHeader_ps)) ==> TRUE MCDC (TT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_UpdateNfcCardData
    :Description: for (uint8 i_u8 = 0; i_u8 < NFC_CARD_UID_LEN; ++i_u8) ==> TRUE,FALSE
    :Arch ID: 66b6e4c0-51ea-4aa7-b0ce-2dd0aa0bc066
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ResetNFCReaderSessionTag
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    rbd_NFCVehIf_DESELECT_TimerRetry_Reload:
    :Description: Verifying for the function rbd_NFCVehIf_DESELECT_TimerRetry_Reload()
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 286698
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_ReceiveNFCResponse_02)
{
    uint8 nfcResponse_pt[20] = {0};
    nfcResponse_pt[NFC_COM_ID_BYTE] = (uint8)NFC_STATUS;
    nfcResponse_pt[NFC_PAYLOAD_INIT_BYTE] = READY;
    nfcResponse_pt[NFC_ECU_ID_BYTE] = 0;
    get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8  = 255;
    get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b  = 255;
    get_rbd_NFCVehIf_Table_as()[0].activeState_u8  = 0x61;//NFC_READER_TEAR_DOWN_TRIGGER_STATE_E
    get_rbd_NFCVehIf_DeselectInfo_S()->mock_uRetryFinish_u8 = 0;
    call_rbd_NFCVehIf_ReceiveNFCResponse(nfcResponse_pt,NFC_PAYLOAD_INIT_BYTE);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8,READER_DISCONNECTED);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b ,RBDPK_KEYREF_INVALID);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].activeState_u8 ,0X00);//NFC_READER_NOT_ACTIVE_STATE_E
    // EXPECT_EQ(get_rbd_NFCVehIf_CardData_st()->routineStatus_u8,(uint8)ROUTINE_SUCCESS);
    // EXPECT_EQ(get_rbd_NFCVehIf_CardData_st()->errorCode_u8,(uint8)NO_FAILURE);Code removed
    // for (uint8 i_u8 = 0; i_u8 < 7; ++i_u8)
    // {
    //     EXPECT_EQ(get_rbd_NFCVehIf_CardData_st()->cardUID_au8[i_u8],get_rbd_NFCVehIf_NfcCardDefaultUid_au8()[i_u8]);
    // }Code removed
    EXPECT_EQ(rbdSessionMgr_NfcDisconnected_fake.call_count,2);
    EXPECT_EQ(rbdSessionMgr_NfcDisconnected_fake.arg0_val, nfcReaderHdr.mock_txEcu_u8);
    EXPECT_EQ(rbd_RfhmIf_SendNfcToggleReq_fake.call_count,1);
    EXPECT_EQ(rbd_RfhmIf_SendNfcToggleReq_fake.arg0_val, NO_TOGGLE);
    EXPECT_EQ(rbd_RfhmIf_SendNfcToggleReq_fake.arg1_val, 0);
}
/*
@rst
    Brief description of test case.
    :Description: if (nfcResponseLength_u16 >= (uint16)NFC_PAYLOAD_INIT_BYTE) ==> TRUE
        if (nfcReaderHdr.cmdId_u8 == (uint8)NFC_STATUS) ==> TRUE
        switch (nfcResponse_pt[NFC_PAYLOAD_INIT_BYTE])
        case DEVICEREMOVED:
        if ((uint8)nfcReaderHdr.txEcu_u8 == (uint8)FLDHM) ==> FALSE
        else if (session_state_u8 == (uint8)NFC_READER_CARD_PLANT_PAIR_STATE_E) ==> FALSE
        else if (session_state_u8 == (uint8)NFC_READER_CARD_PLANT_TEST_STATE_E) ==> FALSE
        else if (session_state_u8 == (uint8)NFC_READER_GET_UID_STATE_E) ==> FALSE
    :Arch ID: 7276a26e-0947-4cfe-a535-ac5f1280e46f
    :REQ ID: NA
    :ALM Task ID: 286698
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NfcIf_NfcReaderCanTPPacketHeaderRead()
    :Description: if((NULL != packetDataIn) && (NULL != nfcReaderDataHeader_ps)) ==> TRUE MCDC (TT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ResetNFCReaderSessionTag()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) )==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_ReceiveNFCResponse_03)
{
    uint8 nfcResponse_pt[20] = {0};
    nfcResponse_pt[NFC_COM_ID_BYTE] = (uint8)NFC_STATUS;
    nfcResponse_pt[NFC_PAYLOAD_INIT_BYTE] = DEVICEREMOVED;
    nfcResponse_pt[NFC_ECU_ID_BYTE] = 01;
    get_rbd_NFCVehIf_Table_as()[1].connectionStatus_u8  = 255;
    get_rbd_NFCVehIf_Table_as()[1].Key_Card_Ref_b  = 255;
    get_rbd_NFCVehIf_Table_as()[1].activeState_u8  = 14;
    call_rbd_NFCVehIf_ReceiveNFCResponse(nfcResponse_pt,NFC_PAYLOAD_INIT_BYTE);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[1].connectionStatus_u8,READER_DISCONNECTED);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[1].Key_Card_Ref_b ,RBDPK_KEYREF_INVALID);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[1].activeState_u8 ,0X00);//NFC_READER_NOT_ACTIVE_STATE_E
    EXPECT_EQ(rbdSessionMgr_NfcDisconnected_fake.call_count,1);
    EXPECT_EQ(rbdSessionMgr_NfcDisconnected_fake.arg0_val, nfcReaderHdr.mock_txEcu_u8);
}
/*
@rst
    Brief description of test case.
    :Description: if (nfcResponseLength_u16 >= (uint16)NFC_PAYLOAD_INIT_BYTE) ==> TRUE
        if (nfcReaderHdr.cmdId_u8 == (uint8)NFC_STATUS) ==> TRUE
        switch (nfcResponse_pt[NFC_PAYLOAD_INIT_BYTE])
        case DEVICEREMOVED:
        if ((uint8)nfcReaderHdr.txEcu_u8 == (uint8)FLDHM) ==> FALSE
        else if (session_state_u8 == (uint8)NFC_READER_CARD_PLANT_PAIR_STATE_E) ==> TRUE
    :Arch ID: 7276a26e-0947-4cfe-a535-ac5f1280e46f
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NfcIf_NfcReaderCanTPPacketHeaderRead()
    :Description: if((NULL != packetDataIn) && (NULL != nfcReaderDataHeader_ps)) ==> TRUE MCDC (TT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_UpdateNfcCardData()
    :Description: for (uint8 i_u8 = 0; i_u8 < NFC_CARD_UID_LEN; ++i_u8) ==> TRUE, FALSE
    :Arch ID: 66b6e4c0-51ea-4aa7-b0ce-2dd0aa0bc066
    :REQ ID: NA
    :ALM Task ID: 183001
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ResetNFCReaderSessionTag()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_ReceiveNFCResponse_04)
{
    uint8 nfcResponse_pt[20] = {0};
    nfcResponse_pt[NFC_COM_ID_BYTE] = (uint8)NFC_STATUS;
    nfcResponse_pt[NFC_PAYLOAD_INIT_BYTE] = DEVICEREMOVED;
    nfcResponse_pt[NFC_ECU_ID_BYTE] = 01;
    get_rbd_NFCVehIf_Table_as()[1].connectionStatus_u8  = 255;
    get_rbd_NFCVehIf_Table_as()[1].Key_Card_Ref_b  = 255;
    get_rbd_NFCVehIf_Table_as()[1].activeState_u8  = 0x30u;//NFC_READER_CARD_PLANT_PAIR_STATE_E
    call_rbd_NFCVehIf_ReceiveNFCResponse(nfcResponse_pt,NFC_PAYLOAD_INIT_BYTE);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[1].connectionStatus_u8,READER_DISCONNECTED);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[1].Key_Card_Ref_b ,RBDPK_KEYREF_INVALID);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[1].activeState_u8 ,0X00);//NFC_READER_NOT_ACTIVE_STATE_E
    EXPECT_EQ(rbdSessionMgr_NfcDisconnected_fake.call_count,1);
    EXPECT_EQ(rbdSessionMgr_NfcDisconnected_fake.arg0_val, nfcReaderHdr.mock_txEcu_u8);
    // EXPECT_EQ(get_rbd_NFCVehIf_CardData_st()->routineStatus_u8, ROUTINE_FAILED);
    // EXPECT_EQ(get_rbd_NFCVehIf_CardData_st()->errorCode_u8,(uint8)READER_NOT_READY_P);
    // for (uint8 i_u8 = 0; i_u8 < NFC_CARD_UID_LEN; ++i_u8)
    // {
    //    EXPECT_EQ(get_rbd_NFCVehIf_CardData_st()->cardUID_au8[i_u8] ,get_rbd_NFCVehIf_NfcCardDefaultUid_au8()[i_u8]);
    // }Code removed
    // EXPECT_EQ(*get_rbd_NFCVehIf_NfcCardTimerIsActive_b(),FALSE);Code removed
}

/*
@rst
    Brief description of test case.
    :Description: if (nfcResponseLength_u16 >= (uint16)NFC_PAYLOAD_INIT_BYTE) ==> TRUE
        if (nfcReaderHdr.cmdId_u8 == (uint8)NFC_STATUS) ==> TRUE
        switch (nfcResponse_pt[NFC_PAYLOAD_INIT_BYTE])
        case DEVICEREMOVED:
        if ((uint8)nfcReaderHdr.txEcu_u8 == (uint8)FLDHM) ==> FALSE
        else if (session_state_u8 == (uint8)NFC_READER_CARD_PLANT_PAIR_STATE_E) ==> FALSE
        else if (session_state_u8 == (uint8)NFC_READER_CARD_PLANT_TEST_STATE_E) ==> TRUE
    :Arch ID: 7276a26e-0947-4cfe-a535-ac5f1280e46f
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NfcIf_NfcReaderCanTPPacketHeaderRead()
    :Description: if((NULL != packetDataIn) && (NULL != nfcReaderDataHeader_ps)) ==> TRUE MCDC (TT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_UpdateNfcCardData()
    :Description: for (uint8 i_u8 = 0; i_u8 < NFC_CARD_UID_LEN; ++i_u8) ==> TRUE, FALSE
    :Arch ID: 66b6e4c0-51ea-4aa7-b0ce-2dd0aa0bc066
    :REQ ID: NA
    :ALM Task ID: 183001
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ResetNFCReaderSessionTag()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_ReceiveNFCResponse_05)
{
    uint8 nfcResponse_pt[20] = {0};
    nfcResponse_pt[NFC_COM_ID_BYTE] = (uint8)NFC_STATUS;
    nfcResponse_pt[NFC_PAYLOAD_INIT_BYTE] = DEVICEREMOVED;
    nfcResponse_pt[NFC_ECU_ID_BYTE] = 01;
    get_rbd_NFCVehIf_Table_as()[1].connectionStatus_u8  = 255;
    get_rbd_NFCVehIf_Table_as()[1].Key_Card_Ref_b  = 255;
    get_rbd_NFCVehIf_Table_as()[1].activeState_u8  = 0x40U;//NFC_READER_CARD_PLANT_TEST_STATE_E
    call_rbd_NFCVehIf_ReceiveNFCResponse(nfcResponse_pt,NFC_PAYLOAD_INIT_BYTE);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[1].connectionStatus_u8,READER_DISCONNECTED);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[1].Key_Card_Ref_b ,RBDPK_KEYREF_INVALID);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[1].activeState_u8 ,0X00);//NFC_READER_NOT_ACTIVE_STATE_E
    EXPECT_EQ(rbdSessionMgr_NfcDisconnected_fake.call_count,1);
    EXPECT_EQ(rbdSessionMgr_NfcDisconnected_fake.arg0_val, nfcReaderHdr.mock_txEcu_u8);
    // EXPECT_EQ(get_rbd_NFCVehIf_CardData_st()->routineStatus_u8, ROUTINE_FAILED);
    // EXPECT_EQ(get_rbd_NFCVehIf_CardData_st()->errorCode_u8, READER_NOT_READY_T);
    // for (uint8 i_u8 = 0; i_u8 < NFC_CARD_UID_LEN; ++i_u8)
    // {
    //    EXPECT_EQ(get_rbd_NFCVehIf_CardData_st()->cardUID_au8[i_u8] ,get_rbd_NFCVehIf_NfcCardDefaultUid_au8()[i_u8]);
    // }Code removed
    // EXPECT_EQ(*get_rbd_NFCVehIf_NfcCardTimerIsActive_b(),FALSE);Code removed
}
/*
@rst
    Brief description of test case.
    :Description: if (nfcResponseLength_u16 >= (uint16)NFC_PAYLOAD_INIT_BYTE) ==> TRUE
        if (nfcReaderHdr.cmdId_u8 == (uint8)NFC_STATUS) ==> TRUE
        switch (nfcResponse_pt[NFC_PAYLOAD_INIT_BYTE])
        case DEVICEREMOVED:
        if ((uint8)nfcReaderHdr.txEcu_u8 == (uint8)FLDHM) ==> TRUE
    :Arch ID: 7276a26e-0947-4cfe-a535-ac5f1280e46f
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NfcIf_NfcReaderCanTPPacketHeaderRead()
    :Description: if((NULL != packetDataIn) && (NULL != nfcReaderDataHeader_ps)) ==> TRUE MCDC (TT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ResetNFCReaderSessionTag()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/

TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_ReceiveNFCResponse_06)
{
    uint8 nfcResponse_pt[20] = {0};
    nfcResponse_pt[NFC_COM_ID_BYTE] = (uint8)NFC_STATUS;
    nfcResponse_pt[NFC_PAYLOAD_INIT_BYTE] = DEVICEREMOVED;
    nfcResponse_pt[NFC_ECU_ID_BYTE] = 0;
    get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8  = 255;
    get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b  = 255;
    get_rbd_NFCVehIf_Table_as()[0].activeState_u8  = 14;
    call_rbd_NFCVehIf_ReceiveNFCResponse(nfcResponse_pt,NFC_PAYLOAD_INIT_BYTE);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8,READER_DISCONNECTED);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b ,RBDPK_KEYREF_INVALID);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].activeState_u8 ,0X00);//NFC_READER_NOT_ACTIVE_STATE_E
    EXPECT_EQ(rbdSessionMgr_NfcDisconnected_fake.call_count,1);
    EXPECT_EQ(rbdSessionMgr_NfcDisconnected_fake.arg0_val, nfcReaderHdr.mock_txEcu_u8);
    EXPECT_EQ(rbd_RfhmIf_SendNfcToggleReq_fake.call_count,1);
    EXPECT_EQ(rbd_RfhmIf_SendNfcToggleReq_fake.arg0_val, NO_TOGGLE);
    EXPECT_EQ(rbd_RfhmIf_SendNfcToggleReq_fake.arg1_val, 0);
}
/*
@rst
    Brief description of test case.
    :Description: if (nfcResponseLength_u16 >= (uint16)NFC_PAYLOAD_INIT_BYTE) ==> TRUE
        if (nfcReaderHdr.cmdId_u8 == (uint8)NFC_STATUS) ==> TRUE
        switch (nfcResponse_pt[NFC_PAYLOAD_INIT_BYTE])
        case MULTNFCDEVPRESENT:
        if (session_state_u8 == (uint8)NFC_READER_GET_UID_STATE_E) ==> FALSE
    :Arch ID: 7276a26e-0947-4cfe-a535-ac5f1280e46f
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NfcIf_NfcReaderCanTPPacketHeaderRead()
    :Description: if((NULL != packetDataIn) && (NULL != nfcReaderDataHeader_ps)) ==> TRUE MCDC (TT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ResetNFCReaderSessionTag()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_ReceiveNFCResponse_07)
{
    uint8 nfcResponse_pt[20] = {0};
    nfcResponse_pt[NFC_COM_ID_BYTE] = (uint8)NFC_STATUS;
    nfcResponse_pt[NFC_PAYLOAD_INIT_BYTE] = MULTNFCDEVPRESENT;
    nfcResponse_pt[NFC_ECU_ID_BYTE] = 0;
    get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8  = 255;
    get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b  = 255;
    get_rbd_NFCVehIf_Table_as()[0].activeState_u8  = 14;
    call_rbd_NFCVehIf_ReceiveNFCResponse(nfcResponse_pt,NFC_PAYLOAD_INIT_BYTE);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8,READER_DISCONNECTED);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b ,RBDPK_KEYREF_INVALID);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].activeState_u8 ,0X00);//NFC_READER_NOT_ACTIVE_STATE_E
    EXPECT_EQ(rbdSessionMgr_NfcDisconnected_fake.call_count,1);
    EXPECT_EQ(rbdSessionMgr_NfcDisconnected_fake.arg0_val, nfcReaderHdr.mock_txEcu_u8);
}
/*
@rst
    Brief description of test case.
    :Description: if (nfcResponseLength_u16 >= (uint16)NFC_PAYLOAD_INIT_BYTE) ==> TRUE
        if (nfcReaderHdr.cmdId_u8 == (uint8)NFC_STATUS) ==> TRUE
        switch (nfcResponse_pt[NFC_PAYLOAD_INIT_BYTE])
        case MULTNFCDEVPRESENT:
        if (session_state_u8 == (uint8)NFC_READER_GET_UID_STATE_E) ==> TRUE
    :Arch ID: 7276a26e-0947-4cfe-a535-ac5f1280e46f
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NfcIf_NfcReaderCanTPPacketHeaderRead()
    :Description: if((NULL != packetDataIn) && (NULL != nfcReaderDataHeader_ps)) ==> TRUE MCDC (TT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_UpdateNfcCardData()
    :Description: for (uint8 i_u8 = 0; i_u8 < NFC_CARD_UID_LEN; ++i_u8) ==> TRUE, FALSE
    :Arch ID: 66b6e4c0-51ea-4aa7-b0ce-2dd0aa0bc066
    :REQ ID: NA
    :ALM Task ID: 183001
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ResetNFCReaderSessionTag()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/

TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_ReceiveNFCResponse_08)
{
    uint8 nfcResponse_pt[20] = {0};
    nfcResponse_pt[NFC_COM_ID_BYTE] = (uint8)NFC_STATUS;
    nfcResponse_pt[NFC_PAYLOAD_INIT_BYTE] = MULTNFCDEVPRESENT;
    nfcResponse_pt[NFC_ECU_ID_BYTE] = 0;
    get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8  = 255;
    get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b  = 255;
    get_rbd_NFCVehIf_Table_as()[0].activeState_u8  = 0x50u;//NFC_READER_GET_UID_STATE_E
    call_rbd_NFCVehIf_ReceiveNFCResponse(nfcResponse_pt,NFC_PAYLOAD_INIT_BYTE);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8,READER_DISCONNECTED);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b ,RBDPK_KEYREF_INVALID);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].activeState_u8 ,0X00);//NFC_READER_NOT_ACTIVE_STATE_E
    EXPECT_EQ(rbdSessionMgr_NfcDisconnected_fake.call_count,1);
    EXPECT_EQ(rbdSessionMgr_NfcDisconnected_fake.arg0_val, nfcReaderHdr.mock_txEcu_u8);
    // EXPECT_EQ(get_rbd_NFCVehIf_CardData_st()->routineStatus_u8, ROUTINE_FAILED);
    // EXPECT_EQ(get_rbd_NFCVehIf_CardData_st()->errorCode_u8,(uint8)MULT_CARDS);
    // for (uint8 i_u8 = 0; i_u8 < NFC_CARD_UID_LEN; ++i_u8)
    // {
    //    EXPECT_EQ(get_rbd_NFCVehIf_CardData_st()->cardUID_au8[i_u8] ,get_rbd_NFCVehIf_NfcCardDefaultUid_au8()[i_u8]);
    // }Code removed
    // EXPECT_EQ(*get_rbd_NFCVehIf_NfcCardTimerIsActive_b(),FALSE);Code removed
}

/*
@rst
    Brief description of test case.
    :Description: if (nfcResponseLength_u16 >= (uint16)NFC_PAYLOAD_INIT_BYTE) ==> TRUE
        if (nfcReaderHdr.cmdId_u8 == (uint8)NFC_STATUS) ==> TRUE
        switch (nfcResponse_pt[NFC_PAYLOAD_INIT_BYTE])
        default:
        if (READER_IN_SESSION == readerConnection_state_u8) ==> TRUE
        if (session_state_u8 == (uint8)NFC_READER_CARD_PLANT_PAIR_STATE_E) ==> FALSE
        else if (session_state_u8 == (uint8)NFC_READER_CARD_PLANT_TEST_STATE_E) ==> FALSE
    :Arch ID: 7276a26e-0947-4cfe-a535-ac5f1280e46f
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NfcIf_NfcReaderCanTPPacketHeaderRead()
    :Description: if((NULL != packetDataIn) && (NULL != nfcReaderDataHeader_ps)) ==> TRUE MCDC (TT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_UpdateNfcCardData()
    :Description: for (uint8 i_u8 = 0; i_u8 < NFC_CARD_UID_LEN; ++i_u8) ==> TRUE, FALSE
    :Arch ID: 66b6e4c0-51ea-4aa7-b0ce-2dd0aa0bc066
    :REQ ID: NA
    :ALM Task ID: 183001
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ResetNFCReaderSessionTag()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/

TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_ReceiveNFCResponse_09)
{
    uint8 nfcResponse_pt[200] = {0};
    nfcResponse_pt[NFC_COM_ID_BYTE] = (uint8)NFC_STATUS;
    nfcResponse_pt[NFC_PAYLOAD_INIT_BYTE] = PENDING;
    nfcResponse_pt[NFC_ECU_ID_BYTE] = 0;
    get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8  = READER_IN_SESSION;
    get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b  = 255;
    get_rbd_NFCVehIf_Table_as()[0].activeState_u8  = 14;
    call_rbd_NFCVehIf_ReceiveNFCResponse(nfcResponse_pt,NFC_PAYLOAD_INIT_BYTE);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8,READER_DISCONNECTED);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b ,RBDPK_KEYREF_INVALID);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].activeState_u8 ,0X00);//NFC_READER_NOT_ACTIVE_STATE_E
    EXPECT_EQ(rbdSessionMgr_NfcDisconnected_fake.call_count,1);
    EXPECT_EQ(rbdSessionMgr_NfcDisconnected_fake.arg0_val, nfcReaderHdr.mock_txEcu_u8);
}
/*
@rst
    Brief description of test case.
    :Description: if (nfcResponseLength_u16 >= (uint16)NFC_PAYLOAD_INIT_BYTE) ==> TRUE
        if (nfcReaderHdr.cmdId_u8 == (uint8)NFC_STATUS) ==> TRUE
        switch (nfcResponse_pt[NFC_PAYLOAD_INIT_BYTE])
        default:
        if (READER_IN_SESSION == readerConnection_state_u8) ==> FALSE
        if (session_state_u8 == (uint8)NFC_READER_CARD_PLANT_PAIR_STATE_E) ==> FALSE
        else if (session_state_u8 == (uint8)NFC_READER_CARD_PLANT_TEST_STATE_E) ==> TRUE
    :Arch ID: 7276a26e-0947-4cfe-a535-ac5f1280e46f
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NfcIf_NfcReaderCanTPPacketHeaderRead()
    :Description: if((NULL != packetDataIn) && (NULL != nfcReaderDataHeader_ps)) ==> TRUE MCDC (TT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_UpdateNfcCardData()
    :Description: for (uint8 i_u8 = 0; i_u8 < NFC_CARD_UID_LEN; ++i_u8) ==> TRUE, FALSE
    :Arch ID: 66b6e4c0-51ea-4aa7-b0ce-2dd0aa0bc066
    :REQ ID: NA
    :ALM Task ID: 183001
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/

TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_ReceiveNFCResponse_10)
{
    uint8 nfcResponse_pt[200] = {0};
    nfcResponse_pt[NFC_COM_ID_BYTE] = (uint8)NFC_STATUS;
    nfcResponse_pt[NFC_PAYLOAD_INIT_BYTE] = PENDING;
    nfcResponse_pt[NFC_ECU_ID_BYTE] = 0;
    get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8  = READER_DISCONNECTED;
    get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b  = 255;
    get_rbd_NFCVehIf_Table_as()[0].activeState_u8  = 0x40;//NFC_READER_CARD_PLANT_TEST_STATE_E
    call_rbd_NFCVehIf_ReceiveNFCResponse(nfcResponse_pt,NFC_PAYLOAD_INIT_BYTE);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8,READER_DISCONNECTED);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b ,RBDPK_KEYREF_INVALID);
    // EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].activeState_u8 ,0x40);
    // EXPECT_EQ(get_rbd_NFCVehIf_CardData_st()->routineStatus_u8, ROUTINE_FAILED);
    // EXPECT_EQ(get_rbd_NFCVehIf_CardData_st()->errorCode_u8, READER_NOT_READY_T);
    // for (uint8 i_u8 = 0; i_u8 < NFC_CARD_UID_LEN; ++i_u8)
    // {
    //    EXPECT_EQ(get_rbd_NFCVehIf_CardData_st()->cardUID_au8[i_u8] ,get_rbd_NFCVehIf_NfcCardDefaultUid_au8()[i_u8]);
    // }Code removed
    // EXPECT_EQ(*get_rbd_NFCVehIf_NfcCardTimerIsActive_b(),FALSE);Code removed
 }
/*
@rst
    Brief description of test case.
    :Description: if (nfcResponseLength_u16 >= (uint16)NFC_PAYLOAD_INIT_BYTE) ==> TRUE
       if (nfcReaderHdr.cmdId_u8 == (uint8)NFC_STATUS) ==> TRUE
        switch (nfcResponse_pt[NFC_PAYLOAD_INIT_BYTE])
        default:
        if (READER_IN_SESSION == readerConnection_state_u8) ==> FALSE
        if (session_state_u8 == (uint8)NFC_READER_CARD_PLANT_PAIR_STATE_E) ==> TRUE
    :Arch ID: 7276a26e-0947-4cfe-a535-ac5f1280e46f
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NfcIf_NfcReaderCanTPPacketHeaderRead()
    :Description: if((NULL != packetDataIn) && (NULL != nfcReaderDataHeader_ps)) ==> TRUE MCDC (TT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_UpdateNfcCardData()
    :Description: for (uint8 i_u8 = 0; i_u8 < NFC_CARD_UID_LEN; ++i_u8) ==> TRUE, FALSE
    :Arch ID: 66b6e4c0-51ea-4aa7-b0ce-2dd0aa0bc066
    :REQ ID: NA
    :ALM Task ID: 183001
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/

TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_ReceiveNFCResponse_11)
{
    uint8 nfcResponse_pt[200] = {0};
    nfcResponse_pt[NFC_COM_ID_BYTE] = (uint8)NFC_STATUS;
    nfcResponse_pt[NFC_PAYLOAD_INIT_BYTE] = PENDING;
    nfcResponse_pt[NFC_ECU_ID_BYTE] = 0;
    get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8  = READER_DISCONNECTED;
    get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b  = 255;
    get_rbd_NFCVehIf_Table_as()[0].activeState_u8  = 0x30u;//NFC_READER_CARD_PLANT_PAIR_STATE_E
    call_rbd_NFCVehIf_ReceiveNFCResponse(nfcResponse_pt,NFC_PAYLOAD_INIT_BYTE);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8,READER_DISCONNECTED);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b ,RBDPK_KEYREF_INVALID);
    // EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].activeState_u8 ,0x30u);
    // EXPECT_EQ(get_rbd_NFCVehIf_CardData_st()->routineStatus_u8, ROUTINE_FAILED);
    // EXPECT_EQ(get_rbd_NFCVehIf_CardData_st()->errorCode_u8, READER_NOT_READY_P);
    // for (uint8 i_u8 = 0; i_u8 < NFC_CARD_UID_LEN; ++i_u8)
    // {
    //    EXPECT_EQ(get_rbd_NFCVehIf_CardData_st()->cardUID_au8[i_u8] ,get_rbd_NFCVehIf_NfcCardDefaultUid_au8()[i_u8]);
    // }Code removed
    // EXPECT_EQ(*get_rbd_NFCVehIf_NfcCardTimerIsActive_b(),FALSE);Code removed
 }
 /*
@rst
    Brief description of test case.
    :Description: if (nfcResponseLength_u16 >= (uint16)NFC_PAYLOAD_INIT_BYTE) ==> TRUE
       if (nfcReaderHdr.cmdId_u8 == (uint8)NFC_STATUS) ==> FALSE
       else if (nfcReaderHdr.cmdId_u8 == NFC_FAILUREMODE) ==> FALSE
       else if (nfcReaderHdr.cmdId_u8 == NFC_DETECTEDUIDS) ==> FALSE
    :Arch ID: 7276a26e-0947-4cfe-a535-ac5f1280e46f
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NfcIf_NfcReaderCanTPPacketHeaderRead()
    :Description: if((NULL != packetDataIn) && (NULL != nfcReaderDataHeader_ps)) ==> TRUE MCDC (TT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ProcessCCCResponse()
    :Description: if (((uint8)NFC_SELECT == nfcReaderHdr.cmdId_u8) && (nfcReaderHdr.txEcu_u8 == (uint8)WCPM2)) ==> FALSE MCDC (FX)
        if (RBDSESSIONMGR_E_OK != rbdSessionMgr_ProcessNfcMsg(sourceEcuID_u8, payLength_u16, &nfcResponse_pt[NFC_PAYLOAD_INIT_BYTE])) ==> FALSE
    :Arch ID: 49f43eea-398d-4c8a-9e33-32f47cb85c79
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/

TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_ReceiveNFCResponse_12)
{
    uint8 nfcResponse_pt[200] = {0};
    nfcResponse_pt[NFC_COM_ID_BYTE] = (uint8)NFC_WRITEBUFFER;
     nfcResponse_pt[NFC_ECU_ID_BYTE] = 0;
  rbdSessionMgr_ProcessNfcMsg_fake.return_val = RBDSESSIONMGR_E_OK;
    call_rbd_NFCVehIf_ReceiveNFCResponse(nfcResponse_pt,NFC_PAYLOAD_INIT_BYTE);
    EXPECT_EQ(rbdSessionMgr_ProcessNfcMsg_fake.call_count,1);
 }
/*
@rst
    Brief description of test case.
    :Description: if (nfcResponseLength_u16 >= (uint16)NFC_PAYLOAD_INIT_BYTE) ==> TRUE
       if (nfcReaderHdr.cmdId_u8 == (uint8)NFC_STATUS) ==> FALSE
       else if (nfcReaderHdr.cmdId_u8 == NFC_FAILUREMODE) ==> FALSE
       else if (nfcReaderHdr.cmdId_u8 == NFC_DETECTEDUIDS) ==> TRUE
    :Arch ID: 7276a26e-0947-4cfe-a535-ac5f1280e46f
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NfcIf_NfcReaderCanTPPacketHeaderRead()
    :Description: if((NULL != packetDataIn) && (NULL != nfcReaderDataHeader_ps)) ==> TRUE MCDC (TT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/

TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_ReceiveNFCResponse_13)
{
    uint8 nfcResponse_pt[200] = {0};
    nfcResponse_pt[NFC_COM_ID_BYTE] = (uint8)NFC_DETECTEDUIDS;
     nfcResponse_pt[NFC_ECU_ID_BYTE] = 0;
  rbdSessionMgr_ProcessNfcMsg_fake.return_val = RBDSESSIONMGR_E_OK;
    call_rbd_NFCVehIf_ReceiveNFCResponse(nfcResponse_pt,NFC_PAYLOAD_INIT_BYTE);
 }

/*
@rst
    Brief description of test case.
    :Description: if (nfcResponseLength_u16 >= (uint16)NFC_PAYLOAD_INIT_BYTE) ==> TRUE
       if (nfcReaderHdr.cmdId_u8 == (uint8)NFC_STATUS) ==> FALSE
       else if (nfcReaderHdr.cmdId_u8 == NFC_FAILUREMODE) ==> TRUE
    :Arch ID: 7276a26e-0947-4cfe-a535-ac5f1280e46f
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NfcIf_NfcReaderCanTPPacketHeaderRead()
    :Description: if((NULL != packetDataIn) && (NULL != nfcReaderDataHeader_ps)) ==> TRUE MCDC (TT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/

TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_ReceiveNFCResponse_14)
{
    uint8 nfcResponse_pt[200] = {0};
    nfcResponse_pt[NFC_COM_ID_BYTE] = (uint8)NFC_FAILUREMODE;
     nfcResponse_pt[NFC_ECU_ID_BYTE] = 0;
    call_rbd_NFCVehIf_ReceiveNFCResponse(nfcResponse_pt,NFC_PAYLOAD_INIT_BYTE);
 }
 /*
@rst
    Brief description of test case.
    :Description: if (nfcResponseLength_u16 >= (uint16)NFC_PAYLOAD_INIT_BYTE) ==> FALSE
    :Arch ID: 7276a26e-0947-4cfe-a535-ac5f1280e46f
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/

TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_ReceiveNFCResponse_15)
{
    uint8 nfcResponse_pt[200] = {0};
    nfcResponse_pt[NFC_COM_ID_BYTE] = (uint8)NFC_FAILUREMODE;
     nfcResponse_pt[NFC_ECU_ID_BYTE] = 0;
    call_rbd_NFCVehIf_ReceiveNFCResponse(nfcResponse_pt,NFC_COM_ID_BYTE);
 }
 /*
@rst
    Brief description of test case.
    :Description: if (nfcResponseLength_u16 >= (uint16)NFC_PAYLOAD_INIT_BYTE) ==> TRUE
        if (nfcReaderHdr.cmdId_u8 == (uint8)NFC_STATUS) ==> TRUE
        switch (nfcResponse_pt[NFC_PAYLOAD_INIT_BYTE])
        case DEVICEREMOVED:
        if ((uint8)nfcReaderHdr.txEcu_u8 == (uint8)FLDHM) ==> FALSE
        else if (session_state_u8 == (uint8)NFC_READER_CARD_PLANT_PAIR_STATE_E) ==> FALSE
        else if (session_state_u8 == (uint8)NFC_READER_CARD_PLANT_TEST_STATE_E) ==> FALSE
        else if (session_state_u8 == (uint8)NFC_READER_GET_UID_STATE_E) ==> TRUE
    :Arch ID: 7276a26e-0947-4cfe-a535-ac5f1280e46f
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NfcIf_NfcReaderCanTPPacketHeaderRead()
    :Description: if((NULL != packetDataIn) && (NULL != nfcReaderDataHeader_ps)) ==> TRUE MCDC (TT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ResetNFCReaderSessionTag()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) )==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_ReceiveNFCResponse_16)
{
    uint8 nfcResponse_pt[20] = {0};
    nfcResponse_pt[NFC_COM_ID_BYTE] = (uint8)NFC_STATUS;
    nfcResponse_pt[NFC_PAYLOAD_INIT_BYTE] = DEVICEREMOVED;
    nfcResponse_pt[NFC_ECU_ID_BYTE] = 01;
    get_rbd_NFCVehIf_Table_as()[1].connectionStatus_u8  = 255;
    get_rbd_NFCVehIf_Table_as()[1].Key_Card_Ref_b  = 255;
    get_rbd_NFCVehIf_Table_as()[1].activeState_u8  = 0x50u;
    call_rbd_NFCVehIf_ReceiveNFCResponse(nfcResponse_pt,NFC_PAYLOAD_INIT_BYTE);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[1].connectionStatus_u8,READER_DISCONNECTED);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[1].Key_Card_Ref_b ,RBDPK_KEYREF_INVALID);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[1].activeState_u8 ,0X00);
    EXPECT_EQ(rbdSessionMgr_NfcDisconnected_fake.call_count,1);
    EXPECT_EQ(rbdSessionMgr_NfcDisconnected_fake.arg0_val, nfcReaderHdr.mock_txEcu_u8);
    // EXPECT_EQ(get_rbd_NFCVehIf_CardData_st()->routineStatus_u8,ROUTINE_FAILED);
    // // EXPECT_EQ(get_rbd_NFCVehIf_CardData_st()->errorCode_u8, TIMEOUT);
    // for (uint8 i_u8 = 0; i_u8 < NFC_CARD_UID_LEN; ++i_u8)
    // {
    //    EXPECT_EQ(get_rbd_NFCVehIf_CardData_st()->cardUID_au8[i_u8] ,get_rbd_NFCVehIf_NfcCardDefaultUid_au8()[i_u8]);
    // }Code removed
    // EXPECT_EQ(*get_rbd_NFCVehIf_NfcCardTimerIsActive_b(),FALSE);Code removed
}
/*
@rst
    Brief description of test case.
    :Description: if (nfcResponseLength_u16 >= (uint16)NFC_PAYLOAD_INIT_BYTE) ==> TRUE
        if (nfcReaderHdr.cmdId_u8 == (uint8)NFC_STATUS) ==> TRUE
        switch (nfcResponse_pt[NFC_PAYLOAD_INIT_BYTE])
        case READY:
        if((FALSE == rbd_NFCVehIf_IsDeselectRetryTmr_Expired()) && (session_state_u8 != (uint8)NFC_READER_CARD_PLANT_PAIR_STATE_E)) ==> TRUE MCDC (FX)
        if ((uint8)nfcReaderHdr.txEcu_u8 == (uint8)FLDHM) ==> TRUE
        if (((uint8)NFC_READER_TAP_START_STOP_TRIGGER_STATE_E == session_state_u8) ||
            ((uint8)NFC_READER_OWNER_PAIRING_TEAR_DOWN_STATE_E == session_state_u8) ||
            ((uint8)NFC_READER_CARD_PLANT_PAIR_TEAR_DOWN_STATE_E == session_state_u8) ||
            ((uint8)NFC_READER_CARD_PLANT_TEST_TEAR_DOWN_STATE_E == session_state_u8) ||
            ((uint8)NFC_READER_PHONE_ENABLE_DISABLE_WCP_AUTH_FINISH_STATE_E == session_state_u8)) ==> TRUE MCDC(FFFTX)
    :Arch ID: 7276a26e-0947-4cfe-a535-ac5f1280e46f
    :REQ ID: NA
    :ALM Task ID: 286698
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NfcIf_NfcReaderCanTPPacketHeaderRead()
    :Description: if((NULL != packetDataIn) && (NULL != nfcReaderDataHeader_ps)) ==> TRUE MCDC (TT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_UpdateNfcCardData
    :Description: for (uint8 i_u8 = 0; i_u8 < NFC_CARD_UID_LEN; ++i_u8) ==> TRUE,FALSE
    :Arch ID: 66b6e4c0-51ea-4aa7-b0ce-2dd0aa0bc066
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ResetNFCReaderSessionTag
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    rbd_NFCVehIf_DESELECT_TimerRetry_Reload:
    :Description: Verifying for the function rbd_NFCVehIf_DESELECT_TimerRetry_Reload()
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 286698
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_ReceiveNFCResponse_17)
{
    uint8 nfcResponse_pt[20] = {0};
    nfcResponse_pt[NFC_COM_ID_BYTE] = (uint8)NFC_STATUS;
    nfcResponse_pt[NFC_PAYLOAD_INIT_BYTE] = READY;
    nfcResponse_pt[NFC_ECU_ID_BYTE] = 0;
    get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8  = 255;
    get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b  = 255;
    get_rbd_NFCVehIf_Table_as()[0].activeState_u8  = 0x41;//NFC_READER_TEAR_DOWN_TRIGGER_STATE_E
    get_rbd_NFCVehIf_DeselectInfo_S()->mock_uRetryFinish_u8 = 0;
    call_rbd_NFCVehIf_ReceiveNFCResponse(nfcResponse_pt,NFC_PAYLOAD_INIT_BYTE);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8,READER_DISCONNECTED);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b ,RBDPK_KEYREF_INVALID);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].activeState_u8 ,0X00);//NFC_READER_NOT_ACTIVE_STATE_E
    // EXPECT_EQ(get_rbd_NFCVehIf_CardData_st()->routineStatus_u8,(uint8)ROUTINE_SUCCESS);
    // EXPECT_EQ(get_rbd_NFCVehIf_CardData_st()->errorCode_u8,(uint8)NO_FAILURE);
    // for (uint8 i_u8 = 0; i_u8 < 7; ++i_u8)
    // {
    //     EXPECT_EQ(get_rbd_NFCVehIf_CardData_st()->cardUID_au8[i_u8],get_rbd_NFCVehIf_NfcCardDefaultUid_au8()[i_u8]);
    // }Code removed
    EXPECT_EQ(rbdSessionMgr_NfcDisconnected_fake.call_count,2);
    EXPECT_EQ(rbdSessionMgr_NfcDisconnected_fake.arg0_val, nfcReaderHdr.mock_txEcu_u8);
    EXPECT_EQ(rbd_RfhmIf_SendNfcToggleReq_fake.call_count,1);
    EXPECT_EQ(rbd_RfhmIf_SendNfcToggleReq_fake.arg0_val, NO_TOGGLE);
    EXPECT_EQ(rbd_RfhmIf_SendNfcToggleReq_fake.arg1_val, 0);
}
/*
@rst
    Brief description of test case.
    :Description: if (nfcResponseLength_u16 >= (uint16)NFC_PAYLOAD_INIT_BYTE) ==> TRUE
        if (nfcReaderHdr.cmdId_u8 == (uint8)NFC_STATUS) ==> TRUE
        switch (nfcResponse_pt[NFC_PAYLOAD_INIT_BYTE])
        case READY:
        if((FALSE == rbd_NFCVehIf_IsDeselectRetryTmr_Expired()) && (session_state_u8 != (uint8)NFC_READER_CARD_PLANT_PAIR_STATE_E)) ==> TRUE MCDC(TT)
        if ((uint8)nfcReaderHdr.txEcu_u8 == (uint8)FLDHM) ==> TRUE
        if (((uint8)NFC_READER_TAP_START_STOP_TRIGGER_STATE_E == session_state_u8) ||
            ((uint8)NFC_READER_OWNER_PAIRING_TEAR_DOWN_STATE_E == session_state_u8) ||
            ((uint8)NFC_READER_CARD_PLANT_PAIR_TEAR_DOWN_STATE_E == session_state_u8) ||
            ((uint8)NFC_READER_CARD_PLANT_TEST_TEAR_DOWN_STATE_E == session_state_u8) ||
            ((uint8)NFC_READER_PHONE_ENABLE_DISABLE_WCP_AUTH_FINISH_STATE_E == session_state_u8)) ==> TRUE MCDC(FFTXX)
    :Arch ID: 7276a26e-0947-4cfe-a535-ac5f1280e46f
    :REQ ID: NA
    :ALM Task ID: 286698
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NfcIf_NfcReaderCanTPPacketHeaderRead()
    :Description: if((NULL != packetDataIn) && (NULL != nfcReaderDataHeader_ps)) ==> TRUE MCDC (TT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_UpdateNfcCardData
    :Description: for (uint8 i_u8 = 0; i_u8 < NFC_CARD_UID_LEN; ++i_u8) ==> TRUE,FALSE
    :Arch ID: 66b6e4c0-51ea-4aa7-b0ce-2dd0aa0bc066
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ResetNFCReaderSessionTag
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    rbd_NFCVehIf_DESELECT_TimerRetry_Reload:
    :Description: Verifying for the function rbd_NFCVehIf_DESELECT_TimerRetry_Reload()
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 286698
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_ReceiveNFCResponse_18)
{
    uint8 nfcResponse_pt[20] = {0};
    nfcResponse_pt[NFC_COM_ID_BYTE] = (uint8)NFC_STATUS;
    nfcResponse_pt[NFC_PAYLOAD_INIT_BYTE] = READY;
    nfcResponse_pt[NFC_ECU_ID_BYTE] = 0;
    get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8  = 255;
    get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b  = 255;
    get_rbd_NFCVehIf_Table_as()[0].activeState_u8  = 0x31;//NFC_READER_TEAR_DOWN_TRIGGER_STATE_E
    get_rbd_NFCVehIf_DeselectInfo_S()->mock_uRetryFinish_u8 = 0;
    call_rbd_NFCVehIf_ReceiveNFCResponse(nfcResponse_pt,NFC_PAYLOAD_INIT_BYTE);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8,READER_DISCONNECTED);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b ,RBDPK_KEYREF_INVALID);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].activeState_u8 ,0X00);//NFC_READER_NOT_ACTIVE_STATE_E
    // EXPECT_EQ(get_rbd_NFCVehIf_CardData_st()->routineStatus_u8,(uint8)ROUTINE_SUCCESS);
    // EXPECT_EQ(get_rbd_NFCVehIf_CardData_st()->errorCode_u8,(uint8)NO_FAILURE);
    // for (uint8 i_u8 = 0; i_u8 < 7; ++i_u8)
    // {
    //     EXPECT_EQ(get_rbd_NFCVehIf_CardData_st()->cardUID_au8[i_u8],get_rbd_NFCVehIf_NfcCardDefaultUid_au8()[i_u8]);
    // }Code removed
    EXPECT_EQ(rbdSessionMgr_NfcDisconnected_fake.call_count,2);
    EXPECT_EQ(rbdSessionMgr_NfcDisconnected_fake.arg0_val, nfcReaderHdr.mock_txEcu_u8);
    EXPECT_EQ(rbd_RfhmIf_SendNfcToggleReq_fake.call_count,1);
    EXPECT_EQ(rbd_RfhmIf_SendNfcToggleReq_fake.arg0_val, NO_TOGGLE);
    EXPECT_EQ(rbd_RfhmIf_SendNfcToggleReq_fake.arg1_val, 0);
}
/*
@rst
    Brief description of test case.
    :Description: if (nfcResponseLength_u16 >= (uint16)NFC_PAYLOAD_INIT_BYTE) ==> TRUE
        if (nfcReaderHdr.cmdId_u8 == (uint8)NFC_STATUS) ==> TRUE
        switch (nfcResponse_pt[NFC_PAYLOAD_INIT_BYTE])
        case READY:
        if((FALSE == rbd_NFCVehIf_IsDeselectRetryTmr_Expired()) && (session_state_u8 != (uint8)NFC_READER_CARD_PLANT_PAIR_STATE_E)) ==> TRUE MCDC (TT)
        if ((uint8)nfcReaderHdr.txEcu_u8 == (uint8)FLDHM) ==> TRUE
        if (((uint8)NFC_READER_TAP_START_STOP_TRIGGER_STATE_E == session_state_u8) ||
            ((uint8)NFC_READER_OWNER_PAIRING_TEAR_DOWN_STATE_E == session_state_u8) ||
            ((uint8)NFC_READER_CARD_PLANT_PAIR_TEAR_DOWN_STATE_E == session_state_u8) ||
            ((uint8)NFC_READER_CARD_PLANT_TEST_TEAR_DOWN_STATE_E == session_state_u8) ||
            ((uint8)NFC_READER_PHONE_ENABLE_DISABLE_WCP_AUTH_FINISH_STATE_E == session_state_u8)) ==> TRUE MCDC(TXXXX)
    :Arch ID: 7276a26e-0947-4cfe-a535-ac5f1280e46f
    :REQ ID: NA
    :ALM Task ID: 286698
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NfcIf_NfcReaderCanTPPacketHeaderRead()
    :Description: if((NULL != packetDataIn) && (NULL != nfcReaderDataHeader_ps)) ==> TRUE MCDC (TT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_UpdateNfcCardData
    :Description: for (uint8 i_u8 = 0; i_u8 < NFC_CARD_UID_LEN; ++i_u8) ==> TRUE,FALSE
    :Arch ID: 66b6e4c0-51ea-4aa7-b0ce-2dd0aa0bc066
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ResetNFCReaderSessionTag
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    rbd_NFCVehIf_DESELECT_TimerRetry_Reload:
    :Description: Verifying for the function rbd_NFCVehIf_DESELECT_TimerRetry_Reload()
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 286698
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_ReceiveNFCResponse_19)
{
    uint8 nfcResponse_pt[20] = {0};
    nfcResponse_pt[NFC_COM_ID_BYTE] = (uint8)NFC_STATUS;
    nfcResponse_pt[NFC_PAYLOAD_INIT_BYTE] = READY;
    nfcResponse_pt[NFC_ECU_ID_BYTE] = 0;
    get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8  = 255;
    get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b  = 255;
    get_rbd_NFCVehIf_Table_as()[0].activeState_u8  = 0x17;//NFC_READER_TEAR_DOWN_TRIGGER_STATE_E
    get_rbd_NFCVehIf_DeselectInfo_S()->mock_uRetryFinish_u8 = 0;
    call_rbd_NFCVehIf_ReceiveNFCResponse(nfcResponse_pt,NFC_PAYLOAD_INIT_BYTE);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8,READER_DISCONNECTED);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b ,RBDPK_KEYREF_INVALID);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].activeState_u8 ,0X00);//NFC_READER_NOT_ACTIVE_STATE_E
    // EXPECT_EQ(get_rbd_NFCVehIf_CardData_st()->routineStatus_u8,(uint8)ROUTINE_SUCCESS);
    // EXPECT_EQ(get_rbd_NFCVehIf_CardData_st()->errorCode_u8,(uint8)NO_FAILURE);
    // for (uint8 i_u8 = 0; i_u8 < 7; ++i_u8)
    // {
    //     EXPECT_EQ(get_rbd_NFCVehIf_CardData_st()->cardUID_au8[i_u8],get_rbd_NFCVehIf_NfcCardDefaultUid_au8()[i_u8]);
    // }Code removed
    EXPECT_EQ(rbdSessionMgr_NfcDisconnected_fake.call_count,2);
    EXPECT_EQ(rbdSessionMgr_NfcDisconnected_fake.arg0_val, nfcReaderHdr.mock_txEcu_u8);
    EXPECT_EQ(rbd_RfhmIf_SendNfcToggleReq_fake.call_count,1);
    EXPECT_EQ(rbd_RfhmIf_SendNfcToggleReq_fake.arg0_val, NO_TOGGLE);
    EXPECT_EQ(rbd_RfhmIf_SendNfcToggleReq_fake.arg1_val, 0);
}
/*
@rst
    Brief description of test case.
    :Description: if (nfcResponseLength_u16 >= (uint16)NFC_PAYLOAD_INIT_BYTE) ==> TRUE
        if (nfcReaderHdr.cmdId_u8 == (uint8)NFC_STATUS) ==> TRUE
        switch (nfcResponse_pt[NFC_PAYLOAD_INIT_BYTE])
        case READY:
        if((FALSE == rbd_NFCVehIf_IsDeselectRetryTmr_Expired()) && (session_state_u8 != (uint8)NFC_READER_CARD_PLANT_PAIR_STATE_E)) ==> TRUE MCDC (TT)
        if ((uint8)nfcReaderHdr.txEcu_u8 == (uint8)FLDHM) ==> TRUE
        if (((uint8)NFC_READER_TAP_START_STOP_TRIGGER_STATE_E == session_state_u8) ||
            ((uint8)NFC_READER_OWNER_PAIRING_TEAR_DOWN_STATE_E == session_state_u8) ||
            ((uint8)NFC_READER_CARD_PLANT_PAIR_TEAR_DOWN_STATE_E == session_state_u8) ||
            ((uint8)NFC_READER_CARD_PLANT_TEST_TEAR_DOWN_STATE_E == session_state_u8) ||
            ((uint8)NFC_READER_PHONE_ENABLE_DISABLE_WCP_AUTH_FINISH_STATE_E == session_state_u8)) ==> TRUE MCDC(FTXXX)
    :Arch ID: 7276a26e-0947-4cfe-a535-ac5f1280e46f
    :REQ ID: NA
    :ALM Task ID: 286698
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NfcIf_NfcReaderCanTPPacketHeaderRead()
    :Description: if((NULL != packetDataIn) && (NULL != nfcReaderDataHeader_ps)) ==> TRUE MCDC (TT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_UpdateNfcCardData
    :Description: for (uint8 i_u8 = 0; i_u8 < NFC_CARD_UID_LEN; ++i_u8) ==> TRUE,FALSE
    :Arch ID: 66b6e4c0-51ea-4aa7-b0ce-2dd0aa0bc066
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ResetNFCReaderSessionTag
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    rbd_NFCVehIf_DESELECT_TimerRetry_Reload:
    :Description: Verifying for the function rbd_NFCVehIf_DESELECT_TimerRetry_Reload()
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 286698
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_ReceiveNFCResponse_20)
{
    uint8 nfcResponse_pt[20] = {0};
    nfcResponse_pt[NFC_COM_ID_BYTE] = (uint8)NFC_STATUS;
    nfcResponse_pt[NFC_PAYLOAD_INIT_BYTE] = READY;
    nfcResponse_pt[NFC_ECU_ID_BYTE] = 0;
    get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8  = 255;
    get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b  = 255;
    get_rbd_NFCVehIf_Table_as()[0].activeState_u8  = 0x21;//NFC_READER_OWNER_PAIRING_TEAR_DOWN_STATE_E
    get_rbd_NFCVehIf_DeselectInfo_S()->mock_uRetryFinish_u8 = 0;
    call_rbd_NFCVehIf_ReceiveNFCResponse(nfcResponse_pt,NFC_PAYLOAD_INIT_BYTE);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8,READER_DISCONNECTED);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b ,RBDPK_KEYREF_INVALID);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].activeState_u8 ,0X00);//NFC_READER_NOT_ACTIVE_STATE_E
    // EXPECT_EQ(get_rbd_NFCVehIf_CardData_st()->routineStatus_u8,(uint8)ROUTINE_SUCCESS);
    // EXPECT_EQ(get_rbd_NFCVehIf_CardData_st()->errorCode_u8,(uint8)NO_FAILURE);
    // for (uint8 i_u8 = 0; i_u8 < 7; ++i_u8)
    // {
    //     EXPECT_EQ(get_rbd_NFCVehIf_CardData_st()->cardUID_au8[i_u8],get_rbd_NFCVehIf_NfcCardDefaultUid_au8()[i_u8]);
    // }Code removed
    EXPECT_EQ(rbdSessionMgr_NfcDisconnected_fake.call_count,2);
    EXPECT_EQ(rbdSessionMgr_NfcDisconnected_fake.arg0_val, nfcReaderHdr.mock_txEcu_u8);
    EXPECT_EQ(rbd_RfhmIf_SendNfcToggleReq_fake.call_count,1);
    EXPECT_EQ(rbd_RfhmIf_SendNfcToggleReq_fake.arg0_val, NO_TOGGLE);
    EXPECT_EQ(rbd_RfhmIf_SendNfcToggleReq_fake.arg1_val, 0);
}
/*
@rst
    Brief description of test case.
    :Description: if (nfcResponseLength_u16 >= (uint16)NFC_PAYLOAD_INIT_BYTE) ==> TRUE
        if (nfcReaderHdr.cmdId_u8 == (uint8)NFC_STATUS) ==> TRUE
        switch (nfcResponse_pt[NFC_PAYLOAD_INIT_BYTE])
        case READY:
        if((FALSE == rbd_NFCVehIf_IsDeselectRetryTmr_Expired()) && (session_state_u8 != (uint8)NFC_READER_CARD_PLANT_PAIR_STATE_E)) ==> FALSE MCDC (TF)
        if ((uint8)nfcReaderHdr.txEcu_u8 == (uint8)FLDHM) ==> TRUE
        if (((uint8)NFC_READER_TAP_START_STOP_TRIGGER_STATE_E == session_state_u8) ||
            ((uint8)NFC_READER_OWNER_PAIRING_TEAR_DOWN_STATE_E == session_state_u8) ||
            ((uint8)NFC_READER_CARD_PLANT_PAIR_TEAR_DOWN_STATE_E == session_state_u8) ||
            ((uint8)NFC_READER_CARD_PLANT_TEST_TEAR_DOWN_STATE_E == session_state_u8) ||
            ((uint8)NFC_READER_PHONE_ENABLE_DISABLE_WCP_AUTH_FINISH_STATE_E == session_state_u8)) ==> TRUE MCDC(FFFFT)
    :Arch ID: 7276a26e-0947-4cfe-a535-ac5f1280e46f
    :REQ ID: NA
    :ALM Task ID: 306772
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NfcIf_NfcReaderCanTPPacketHeaderRead()
    :Description: if((NULL != packetDataIn) && (NULL != nfcReaderDataHeader_ps)) ==> TRUE MCDC (TT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_UpdateNfcCardData
    :Description: for (uint8 i_u8 = 0; i_u8 < NFC_CARD_UID_LEN; ++i_u8) ==> TRUE,FALSE
    :Arch ID: 66b6e4c0-51ea-4aa7-b0ce-2dd0aa0bc066
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ResetNFCReaderSessionTag
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    rbd_NFCVehIf_DESELECT_TimerRetry_Reload:
    :Description: Verifying for the function rbd_NFCVehIf_DESELECT_TimerRetry_Reload()
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 286698
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_ReceiveNFCResponse_21)
{
    uint8 nfcResponse_pt[20] = {0};
    nfcResponse_pt[NFC_COM_ID_BYTE] = (uint8)NFC_STATUS;
    nfcResponse_pt[NFC_PAYLOAD_INIT_BYTE] = READY;
    nfcResponse_pt[NFC_ECU_ID_BYTE] = 0;
    get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8  = 255;
    get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b  = 255;
    get_rbd_NFCVehIf_Table_as()[0].activeState_u8  = 0X30;//NFC_READER_CARD_PLANT_PAIR_STATE_E
    get_rbd_NFCVehIf_DeselectInfo_S()->mock_uRetryFinish_u8 = 0;
    call_rbd_NFCVehIf_ReceiveNFCResponse(nfcResponse_pt,NFC_PAYLOAD_INIT_BYTE);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8,255);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b ,RBDPK_KEYREF_INVALID);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].activeState_u8 ,0X30);
    // EXPECT_EQ(get_rbd_NFCVehIf_CardData_st()->routineStatus_u8,(uint8)ROUTINE_SUCCESS);
    // EXPECT_EQ(get_rbd_NFCVehIf_CardData_st()->errorCode_u8,(uint8)NO_FAILURE);
    // for (uint8 i_u8 = 0; i_u8 < 7; ++i_u8)
    // {
    //     EXPECT_EQ(get_rbd_NFCVehIf_CardData_st()->cardUID_au8[i_u8],get_rbd_NFCVehIf_NfcCardDefaultUid_au8()[i_u8]);
    // }Code removed
    EXPECT_EQ(rbdSessionMgr_NfcDisconnected_fake.call_count,1);
    EXPECT_EQ(rbdSessionMgr_NfcDisconnected_fake.arg0_val, nfcReaderHdr.mock_txEcu_u8);
    EXPECT_EQ(rbd_RfhmIf_SendNfcToggleReq_fake.call_count,1);
    EXPECT_EQ(rbd_RfhmIf_SendNfcToggleReq_fake.arg0_val, NO_TOGGLE);
    EXPECT_EQ(rbd_RfhmIf_SendNfcToggleReq_fake.arg1_val, 0);
}
//----------------------------------------------------------------------------
// Test Cases// void rbd_NFCVehIf_ProcessCCCResponse(const uint8 *nfcResponse_pt)
//----------------------------------------------------------------------------
/*
@rst
    Brief description of test case.
    :Description: if (((uint8)NFC_SELECT == nfcReaderHdr.cmdId_u8) && (nfcReaderHdr.txEcu_u8 == (uint8)WCPM2)) ==> FALSE MCDC (FX)
        if(session_state_u8 != (uint8)NFC_READER_GET_UID_STATE_E) ==> TRUE
        if (RBDSESSIONMGR_E_OK != rbdSessionMgr_ProcessNfcMsg(sourceEcuID_u8, payLength_u16, &nfcResponse_pt[NFC_PAYLOAD_INIT_BYTE])) ==> FALSE
    :Arch ID: 49f43eea-398d-4c8a-9e33-32f47cb85c79
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NfcIf_NfcReaderCanTPPacketHeaderRead()
    :Description: if((NULL != packetDataIn) && (NULL != nfcReaderDataHeader_ps)) ==> TRUE MCDC (TT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_ProcessCCCResponse_01)
{
    uint8 nfcResponse_pt[20] = {0};
    nfcResponse_pt[NFC_COM_ID_BYTE] = (uint8)NFC_WRITEBUFFER;
    nfcResponse_pt[NFC_ECU_ID_BYTE] = (uint8)DEFAULT_ECU;
    rbdSessionMgr_ProcessNfcMsg_fake.return_val = RBDSESSIONMGR_E_OK;
    call_rbd_NFCVehIf_ProcessCCCResponse(nfcResponse_pt);
    EXPECT_EQ(rbdSessionMgr_ProcessNfcMsg_fake.call_count,1);
}
/*
@rst
    Brief description of test case.
    :Description: if (((uint8)NFC_SELECT == nfcReaderHdr.cmdId_u8) && (nfcReaderHdr.txEcu_u8 == (uint8)WCPM2)) ==> TRUE MCDC (TT)
        if(rbd_NFCVehIf_Table_as[WCPM2].activeState_u8 == (uint8)NFC_READER_TAP_START_FLOW_INIT_STATE_E) ==> FALSE
        for(uint8 i = 0; i < nfcReaderHdr.payloadLength_u16; ++i) ==> FALSE
        if(session_state_u8 != (uint8)NFC_READER_GET_UID_STATE_E) ==> FALSE
    :Arch ID: 49f43eea-398d-4c8a-9e33-32f47cb85c79
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NfcIf_NfcReaderCanTPPacketHeaderRead()
    :Description: if((NULL != packetDataIn) && (NULL != nfcReaderDataHeader_ps)) ==> TRUE MCDC (TT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_NfcTeardown()
    :Description: switch((NfcEcuIds)nfcReaderId)
        case WCPM2
        (rbd_NFCVehIf_NFC_Count > 0U) ? 1U : 0U ==> FALSE
        if(((uint8)NFC_READER_CARD_PLANT_PAIR_STATE_E == session_state_u8) ||
				   ((uint8)NFC_READER_CARD_PLANT_PAIR_TEAR_DOWN_STATE_E == session_state_u8) ||
				   ((uint8)NFC_READER_OWNER_PAIRING_STATE_E == session_state_u8) ||
				   ((uint8)NFC_READER_OWNER_PAIRING_TEAR_DOWN_STATE_E == session_state_u8) ||
				   ((uint8)NFC_READER_GET_UID_STATE_E == session_state_u8) ||
				   ((uint8)NFC_READER_GET_UID_TEAR_DOWN_STATE_E == session_state_u8)) ==> TRUE MCDC (FFFFTX)
        if(((uint8)NFC_READER_TAP_START_STOP_TRIGGER_STATE_E == session_state_u8) ||
				   ((uint8)NFC_READER_GET_UID_STATE_E == session_state_u8) ||
				   ((uint8)NFC_READER_GET_UID_TEAR_DOWN_STATE_E == session_state_u8)) ==> TRUE MCDC(FTX)
    :Arch ID: 307a4b14-a9de-4687-ba2e-5c65b174ce4a
    :REQ ID: NA
    :ALM Task ID: 286698
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_ProcessCCCResponse_02)
{
    uint8 nfcResponse_pt[20] = {0};
    nfcResponse_pt[NFC_COM_ID_BYTE] = (uint8)NFC_SELECT ;
    nfcResponse_pt[NFC_ECU_ID_BYTE] = (uint8)WCPM2;
    get_rbd_NFCVehIf_Table_as()[2].activeState_u8  = 0x50u;
    nfcReaderHdr.mock_txEcu_u8 = 1;
    rbdSessionMgr_ProcessNfcMsg_fake.return_val = RBDSESSIONMGR_E_OK;
    call_rbd_NFCVehIf_ProcessCCCResponse(nfcResponse_pt);
    // EXPECT_EQ(*get_rbd_NFCVehIf_NfcCardTimerIsActive_b(),FALSE);Code removed
}
/*
@rst
    Brief description of test case.
    :Description: if (((uint8)NFC_SELECT == nfcReaderHdr.cmdId_u8) && (nfcReaderHdr.txEcu_u8 == (uint8)WCPM2)) ==> TRUE MCDC (TT)
        if(rbd_NFCVehIf_Table_as[WCPM2].activeState_u8 == NFC_READER_TAP_START_FLOW_INIT_STATE_E) ==> TRUE
        for(uint8 i = 0; i < nfcReaderHdr.payloadLength_u16; ++i) ==> TRUE
        if(nfcResponse_pt[i] == (uint8)0x80) ==> TRUE,FALSE
        for(uint8 i_u8 = 0; i_u8 < nfcResponse_pt[i+(uint8)1]; ++i_u8) ==> TRUE,FALSE
        if(session_state_u8 != (uint8)NFC_READER_GET_UID_STATE_E) ==> TRUE
        if (RBDSESSIONMGR_E_OK != rbdSessionMgr_ProcessNfcMsg(sourceEcuID_u8, payLength_u16, &nfcResponse_pt[NFC_PAYLOAD_INIT_BYTE])) ==> FALSE
    :Arch ID: 49f43eea-398d-4c8a-9e33-32f47cb85c79
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NfcIf_NfcReaderCanTPPacketHeaderRead()
    :Description: if((NULL != packetDataIn) && (NULL != nfcReaderDataHeader_ps)) ==> TRUE MCDC (TT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_ProcessCCCResponse_03)
{
    uint8 nfcResponse_pt[20] = {0};
    nfcResponse_pt[NFC_COM_ID_BYTE] = (uint8)NFC_SELECT;
    nfcResponse_pt[NFC_ECU_ID_BYTE] = (uint8)WCPM2;
    nfcResponse_pt[NFC_PAY_LEN_LS_BYTE] = 0;
    nfcResponse_pt[NFC_PAY_LEN_MS_BYTE] = 5;
    get_rbd_NFCVehIf_Table_as()[WCPM2].activeState_u8=0x10u;//NFC_READER_TAP_START_FLOW_INIT_STATE_E
    nfcResponse_pt[4]=0x80;
    nfcResponse_pt[5]=2;
    //  *get_rbd_NFCVehIf_getUID_active_b() = FALSE;Code removed
     Rte_rbd_NFCVehIf_PP_Nfc_Count_Devices=0;
    rbdSessionMgr_ProcessNfcMsg_fake.return_val = RBDSESSIONMGR_E_OK;
    call_rbd_NFCVehIf_ProcessCCCResponse(nfcResponse_pt);
    EXPECT_EQ(rbdSessionMgr_ProcessNfcMsg_fake.call_count,1);
    // EXPECT_EQ(Rte_rbd_NFCVehIf_PP_Nfc_Count_Devices,1);
}
/*
@rst
    Brief description of test case.
    :Description: if (((uint8)NFC_SELECT == nfcReaderHdr.cmdId_u8) && (nfcReaderHdr.txEcu_u8 == (uint8)WCPM2)) ==> TRUE MCDC (TT)
        if(rbd_NFCVehIf_Table_as[WCPM2].activeState_u8 == NFC_READER_TAP_START_FLOW_INIT_STATE_E) ==> TRUE
        for(uint8 i = 0; i < nfcReaderHdr.payloadLength_u16; ++i) ==> TRUE,FALSE
        if(nfcResponse_pt[i] == (uint8)0x80) ==> TRUE,FALSE
        for(uint8 i_u8 = 0; i_u8 < nfcResponse_pt[i+(uint8)1]; ++i_u8) ==> TRUE,FALSE
        if(session_state_u8 != (uint8)NFC_READER_GET_UID_STATE_E) ==> TRUE
        if (RBDSESSIONMGR_E_OK != rbdSessionMgr_ProcessNfcMsg(sourceEcuID_u8, payLength_u16, &nfcResponse_pt[NFC_PAYLOAD_INIT_BYTE])) ==> FALSE
    :Arch ID: 49f43eea-398d-4c8a-9e33-32f47cb85c79
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NfcIf_NfcReaderCanTPPacketHeaderRead()
    :Description: if((NULL != packetDataIn) && (NULL != nfcReaderDataHeader_ps)) ==> TRUE MCDC (TT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_PrepNFCBuffer()
    :Description: if(payLen_u16 <= ((uint16)MAX_LENGTH_CAPDU - (uint16)NFC_PAYLOAD_INIT_BYTE - (uint16)1U)) ==> TRUE
    :Arch ID: 65a7df42-776e-4509-bbc2-606f3e4b772d
    :REQ ID: NA
    :ALM Task ID: 183001
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NfcIf_NfcReaderCanTPPacketHeaderWrite()
    :Description: if((NULL != packetDataOut) && (NULL != nfcReaderDataHeader_ps)) ==> TRUE MCDC(TT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 183001
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_WritePort()
    :Description: if (dest_u8 == (uint8)FLDHM) ==> FALSE
        else if (dest_u8 == (uint8)FRDHM) ==> FALSE
        else if (dest_u8 == (uint8)WCPM2) ==> TRUE
    :Arch ID: 768d42bb-df4d-4b75-bd0c-10cdf4ab93ae
    :REQ ID: NA
    :ALM Task ID: 183001
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_ProcessCCCResponse_04)
{
    uint8 nfcResponse_pt[20] = {0};
    nfcResponse_pt[NFC_COM_ID_BYTE] = (uint8)NFC_SELECT;
    nfcResponse_pt[NFC_ECU_ID_BYTE] = (uint8)WCPM2;
    nfcResponse_pt[NFC_PAY_LEN_LS_BYTE] = 0;
    nfcResponse_pt[NFC_PAY_LEN_MS_BYTE] = 5;
    get_rbd_NFCVehIf_Table_as()[WCPM2].activeState_u8=0x06u;//NFC_READER_TAP_START_FLOW_INIT_STATE_E
    nfcResponse_pt[4]=0x80;
    nfcResponse_pt[5]=2;
    //  *get_rbd_NFCVehIf_getUID_active_b() = TRUE;Code removed
    //  *get_rbd_NFCVehIf_NfcCardTimerIsActive_b()=TRUE;Code removed
    rbdSessionMgr_ProcessNfcMsg_fake.return_val = RBDSESSIONMGR_E_OK;
    call_rbd_NFCVehIf_ProcessCCCResponse(nfcResponse_pt);
    EXPECT_EQ(rbdSessionMgr_ProcessNfcMsg_fake.call_count,1);
    // EXPECT_EQ(*get_rbd_NFCVehIf_NfcCardTimerIsActive_b(),TRUE);Code removed
}
/*
@rst
    Brief description of test case.
    :Description: if (((uint8)NFC_SELECT == nfcReaderHdr.cmdId_u8) && (nfcReaderHdr.txEcu_u8 == (uint8)WCPM2)) ==> FALSE MCDC (FX)
        if(session_state_u8 != (uint8)NFC_READER_GET_UID_STATE_E) ==> TRUE
        if (RBDSESSIONMGR_E_OK != rbdSessionMgr_ProcessNfcMsg(sourceEcuID_u8, payLength_u16, &nfcResponse_pt[NFC_PAYLOAD_INIT_BYTE])) ==> FALSE
    :Arch ID: 49f43eea-398d-4c8a-9e33-32f47cb85c79
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NfcIf_NfcReaderCanTPPacketHeaderRead()
    :Description: if((NULL != packetDataIn) && (NULL != nfcReaderDataHeader_ps)) ==> FALSE MCDC (FX)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_ProcessCCCResponse_05)
{
    rbdSessionMgr_ProcessNfcMsg_fake.return_val = RBDSESSIONMGR_E_OK;
    call_rbd_NFCVehIf_ProcessCCCResponse(NULL);
}

//----------------------------------------------------------------------------
// Test Cases// void rbd_NFCVehIf_NfcTeardown(const rbdPk_NfcReaderId_t nfcReaderId)
//----------------------------------------------------------------------------
/*
@rst
    Brief description of test case.
    :Description: switch((NfcEcuIds)nfcReaderId)
        case default:
    :Arch ID: 307a4b14-a9de-4687-ba2e-5c65b174ce4a
    :REQ ID: NA
    :ALM Task ID: 286698
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> FALSE MCDC (FXX)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    rbd_NFCVehIf_DESELECT_TimerRetry_Reload:
    :Description: Verifying for the function rbd_NFCVehIf_DESELECT_TimerRetry_Reload()
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 286698
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NfcTeardown_01)
{
    get_rbd_NFCVehIf_Table_as()[2].activeState_u8=0X0D;//NFC_READER_TEAR_DOWN_TRIGGER_STATE_E
    Rte_rbd_NFCVehIf_PP_Nfc_Count_Devices=255;
    // *get_rbd_NFCVehIf_getUID_active_b() = TRUE;Code removed
    call_rbd_NFCVehIf_NfcTeardown(5);
}
/*
@rst
    Brief description of test case.
    :Description: switch((NfcEcuIds)nfcReaderId)
        case FRDHM:
    :Arch ID: 307a4b14-a9de-4687-ba2e-5c65b174ce4a
    :REQ ID: NA
    :ALM Task ID: 286698
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    rbd_NFCVehIf_DESELECT_TimerRetry_Reload:
    :Description: Verifying for the function rbd_NFCVehIf_DESELECT_TimerRetry_Reload()
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 286698
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NfcTeardown_02)
{
    get_rbd_NFCVehIf_Table_as()[1].activeState_u8=0X0D;//NFC_READER_TEAR_DOWN_TRIGGER_STATE_E
    Rte_rbd_NFCVehIf_PP_Nfc_Count_Devices=255;
    // *get_rbd_NFCVehIf_getUID_active_b() = FALSE;Code removed
    //*get_rbd_NFCVehIf_TapStart_active_b()=TRUE;
    call_rbd_NFCVehIf_NfcTeardown(1);
}
/*
@rst
    Brief description of test case.
    :Description: switch((NfcEcuIds)nfcReaderId)
        case WCPM2
        (rbd_NFCVehIf_NFC_Count > 0U) ? 1U : 0U ==> FALSE
        if(((uint8)NFC_READER_CARD_PLANT_PAIR_STATE_E == session_state_u8) ||
				   ((uint8)NFC_READER_CARD_PLANT_PAIR_TEAR_DOWN_STATE_E == session_state_u8) ||
				   ((uint8)NFC_READER_OWNER_PAIRING_STATE_E == session_state_u8) ||
				   ((uint8)NFC_READER_OWNER_PAIRING_TEAR_DOWN_STATE_E == session_state_u8) ||
				   ((uint8)NFC_READER_GET_UID_STATE_E == session_state_u8) ||
				   ((uint8)NFC_READER_GET_UID_TEAR_DOWN_STATE_E == session_state_u8)) ==> FALSE MCDC (FFFFFF)
        else if(((uint8)NFC_READER_TAP_START_TEAR_DOWN_STATE_E == session_state_u8) ||
				    ((uint8)NFC_READER_TAP_START_DEVICE_INFO_WAIT_STATE_E == session_state_u8)) ==> TRUE MCDC(FT)
        if(((uint8)NFC_READER_TAP_START_STOP_TRIGGER_STATE_E == session_state_u8) ||
				   ((uint8)NFC_READER_GET_UID_STATE_E == session_state_u8) ||
				   ((uint8)NFC_READER_GET_UID_TEAR_DOWN_STATE_E == session_state_u8)) ==> TRUE MCDC(TXX)
    :Arch ID: 307a4b14-a9de-4687-ba2e-5c65b174ce4a
    :REQ ID: NA
    :ALM Task ID: 286698
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    rbd_NFCVehIf_DESELECT_TimerRetry_Reload:
    :Description: Verifying for the function rbd_NFCVehIf_DESELECT_TimerRetry_Reload()
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 286698
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NfcTeardown_03)
{
    get_rbd_NFCVehIf_Table_as()[2].activeState_u8=0x15u;//NFC_READER_TAP_START_DEVICE_INFO_WAIT_STATE_E
    get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8=255;
    get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b=255;
    Rte_rbd_NFCVehIf_PP_Nfc_Count_Devices=255;
    // *get_rbd_NFCVehIf_getUID_active_b() = TRUE;Code removed
    //*get_rbd_NFCVehIf_TapStart_active_b()=TRUE;
    call_rbd_NFCVehIf_NfcTeardown(2);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].activeState_u8,0x15u);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8,255);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b,255);
}
/*
@rst
    Brief description of test case.
    :Description: switch((NfcEcuIds)nfcReaderId)
        case WCPM2
        (rbd_NFCVehIf_NFC_Count > 0U) ? 1U : 0U ==> FALSE
        if(((uint8)NFC_READER_CARD_PLANT_PAIR_STATE_E == session_state_u8) ||
				   ((uint8)NFC_READER_CARD_PLANT_PAIR_TEAR_DOWN_STATE_E == session_state_u8) ||
				   ((uint8)NFC_READER_OWNER_PAIRING_STATE_E == session_state_u8) ||
				   ((uint8)NFC_READER_OWNER_PAIRING_TEAR_DOWN_STATE_E == session_state_u8) ||
				   ((uint8)NFC_READER_GET_UID_STATE_E == session_state_u8) ||
				   ((uint8)NFC_READER_GET_UID_TEAR_DOWN_STATE_E == session_state_u8)) ==> TRUE MCDC (FFFFFT)
        if(((uint8)NFC_READER_TAP_START_STOP_TRIGGER_STATE_E == session_state_u8) ||
				   ((uint8)NFC_READER_GET_UID_STATE_E == session_state_u8) ||
				   ((uint8)NFC_READER_GET_UID_TEAR_DOWN_STATE_E == session_state_u8)) ==> TRUE MCDC(FFT)
    :Arch ID: 307a4b14-a9de-4687-ba2e-5c65b174ce4a
    :REQ ID: NA
    :ALM Task ID: 286698
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    rbd_NFCVehIf_DESELECT_TimerRetry_Reload:
    :Description: Verifying for the function rbd_NFCVehIf_DESELECT_TimerRetry_Reload()
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 286698
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NfcTeardown_04)
{
    get_rbd_NFCVehIf_Table_as()[2].activeState_u8=0x51u;//NFC_READER_GET_UID_TEAR_DOWN_STATE_E
    get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8=255;
    get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b=255;
    Rte_rbd_NFCVehIf_PP_Nfc_Count_Devices=255;
    // *get_rbd_NFCVehIf_getUID_active_b() = FALSE;Code removed
    //*get_rbd_NFCVehIf_TapStart_active_b()=TRUE;
    call_rbd_NFCVehIf_NfcTeardown(2);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].activeState_u8,0x51u);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8,255);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b,255);
}
/*
@rst
    Brief description of test case.
    :Description: switch((NfcEcuIds)nfcReaderId)
        case FLDHM:
        if((uint8)NFC_READER_TEAR_DOWN_TRIGGER_STATE_E == session_state_u8) ==> FALSE
    :Arch ID: 307a4b14-a9de-4687-ba2e-5c65b174ce4a
    :REQ ID: NA
    :ALM Task ID: 286698
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    rbd_NFCVehIf_DESELECT_TimerRetry_Reload:
    :Description: Verifying for the function rbd_NFCVehIf_DESELECT_TimerRetry_Reload()
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 286698
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NfcTeardown_05)
{
    get_rbd_NFCVehIf_Table_as()[0].activeState_u8=0x03u;//NFC_READER_TAP_ENTRY_CARD_AUTH_FAILED_STATE_E
    get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8=255;
    get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b=255;
    call_rbd_NFCVehIf_NfcTeardown(0);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].activeState_u8,0x03u);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8,255);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b,255);
}
/*
@rst
    Brief description of test case.
    :Description: switch((NfcEcuIds)nfcReaderId)
        case WCPM2
        (rbd_NFCVehIf_NFC_Count > 0U) ? 1U : 0U ==> FALSE
        if(((uint8)NFC_READER_CARD_PLANT_PAIR_STATE_E == session_state_u8) ||
				   ((uint8)NFC_READER_CARD_PLANT_PAIR_TEAR_DOWN_STATE_E == session_state_u8) ||
				   ((uint8)NFC_READER_OWNER_PAIRING_STATE_E == session_state_u8) ||
				   ((uint8)NFC_READER_OWNER_PAIRING_TEAR_DOWN_STATE_E == session_state_u8) ||
				   ((uint8)NFC_READER_GET_UID_STATE_E == session_state_u8) ||
				   ((uint8)NFC_READER_GET_UID_TEAR_DOWN_STATE_E == session_state_u8)) ==> TRUE MCDC (FFTXXX)
        if(((uint8)NFC_READER_TAP_START_STOP_TRIGGER_STATE_E == session_state_u8) ||
				   ((uint8)NFC_READER_GET_UID_STATE_E == session_state_u8) ||
				   ((uint8)NFC_READER_GET_UID_TEAR_DOWN_STATE_E == session_state_u8)) ==> FALSE MCDC(FFF)
    :Arch ID: 307a4b14-a9de-4687-ba2e-5c65b174ce4a
    :REQ ID: NA
    :ALM Task ID: 286698
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    rbd_NFCVehIf_DESELECT_TimerRetry_Reload:
    :Description: Verifying for the function rbd_NFCVehIf_DESELECT_TimerRetry_Reload()
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 286698
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NfcTeardown_06)
{
    get_rbd_NFCVehIf_Table_as()[2].activeState_u8=0x20u;//NFC_READER_OWNER_PAIRING_STATE_E
    get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8=255;
    get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b=255;
    Rte_rbd_NFCVehIf_PP_Nfc_Count_Devices=255;
    // *get_rbd_NFCVehIf_getUID_active_b() = FALSE;Code removed
    //*get_rbd_NFCVehIf_TapStart_active_b()=TRUE;
    call_rbd_NFCVehIf_NfcTeardown(2);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].activeState_u8,0x20u);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8,255);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b,255);
}
/*
@rst
    Brief description of test case.
    :Description: switch((NfcEcuIds)nfcReaderId)
        case WCPM2
        (rbd_NFCVehIf_NFC_Count > 0U) ? 1U : 0U ==> FALSE
        if(((uint8)NFC_READER_CARD_PLANT_PAIR_STATE_E == session_state_u8) ||
				   ((uint8)NFC_READER_CARD_PLANT_PAIR_TEAR_DOWN_STATE_E == session_state_u8) ||
				   ((uint8)NFC_READER_OWNER_PAIRING_STATE_E == session_state_u8) ||
				   ((uint8)NFC_READER_OWNER_PAIRING_TEAR_DOWN_STATE_E == session_state_u8) ||
				   ((uint8)NFC_READER_GET_UID_STATE_E == session_state_u8) ||
				   ((uint8)NFC_READER_GET_UID_TEAR_DOWN_STATE_E == session_state_u8)) ==> TRUE MCDC (TXXXXX)
        if(((uint8)NFC_READER_TAP_START_STOP_TRIGGER_STATE_E == session_state_u8) ||
				   ((uint8)NFC_READER_GET_UID_STATE_E == session_state_u8) ||
				   ((uint8)NFC_READER_GET_UID_TEAR_DOWN_STATE_E == session_state_u8)) ==> FALSE MCDC(FFF)
    :Arch ID: 307a4b14-a9de-4687-ba2e-5c65b174ce4a
    :REQ ID: NA
    :ALM Task ID: 286698
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    rbd_NFCVehIf_DESELECT_TimerRetry_Reload:
    :Description: Verifying for the function rbd_NFCVehIf_DESELECT_TimerRetry_Reload()
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 286698
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NfcTeardown_07)
{
    get_rbd_NFCVehIf_Table_as()[2].activeState_u8=0x30u;//NFC_READER_CARD_PLANT_PAIR_STATE_E
    get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8=255;
    get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b=255;
    Rte_rbd_NFCVehIf_PP_Nfc_Count_Devices=255;
    // *get_rbd_NFCVehIf_getUID_active_b() = FALSE;Code removed
    //*get_rbd_NFCVehIf_TapStart_active_b()=TRUE;
    call_rbd_NFCVehIf_NfcTeardown(2);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].activeState_u8,0x30u);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8,255);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b,255);
}
/*
@rst
    Brief description of test case.
    :Description: switch((NfcEcuIds)nfcReaderId)
        case WCPM2
        (rbd_NFCVehIf_NFC_Count > 0U) ? 1U : 0U ==> FALSE
        if(((uint8)NFC_READER_CARD_PLANT_PAIR_STATE_E == session_state_u8) ||
				   ((uint8)NFC_READER_CARD_PLANT_PAIR_TEAR_DOWN_STATE_E == session_state_u8) ||
				   ((uint8)NFC_READER_OWNER_PAIRING_STATE_E == session_state_u8) ||
				   ((uint8)NFC_READER_OWNER_PAIRING_TEAR_DOWN_STATE_E == session_state_u8) ||
				   ((uint8)NFC_READER_GET_UID_STATE_E == session_state_u8) ||
				   ((uint8)NFC_READER_GET_UID_TEAR_DOWN_STATE_E == session_state_u8)) ==> FALSE MCDC (FFFFFF)
            else if(((uint8)NFC_READER_TAP_START_TEAR_DOWN_STATE_E == session_state_u8) ||
                ((uint8)NFC_READER_TAP_START_DEVICE_INFO_WAIT_STATE_E == session_state_u8)) ==> TRUE MCDC (TX)
        if(((uint8)NFC_READER_TAP_START_STOP_TRIGGER_STATE_E == session_state_u8) ||
				   ((uint8)NFC_READER_GET_UID_STATE_E == session_state_u8) ||
				   ((uint8)NFC_READER_GET_UID_TEAR_DOWN_STATE_E == session_state_u8)) ==> FALSE MCDC(FFF)
    :Arch ID: 307a4b14-a9de-4687-ba2e-5c65b174ce4a
    :REQ ID: NA
    :ALM Task ID: 306772
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    rbd_NFCVehIf_DESELECT_TimerRetry_Reload:
    :Description: Verifying for the function rbd_NFCVehIf_DESELECT_TimerRetry_Reload()
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 286698
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NfcTeardown_08)
{
    get_rbd_NFCVehIf_Table_as()[2].activeState_u8=0x16u;//NFC_READER_TAP_START_TEAR_DOWN_STATE_E
    get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8=255;
    get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b=255;
    Rte_rbd_NFCVehIf_PP_Nfc_Count_Devices=255;
    // *get_rbd_NFCVehIf_getUID_active_b() = FALSE;Code removed
    call_rbd_NFCVehIf_NfcTeardown(2);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].activeState_u8,0x16u);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8,255);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b,255);
    EXPECT_EQ(get_rbd_NFCVehIf_DeselectInfo_S()->mock_nfcReaderId_en ,2);
    EXPECT_EQ(get_rbd_NFCVehIf_DeselectInfo_S()->mock_reqRetryCount_u8,0);
    EXPECT_EQ(get_rbd_NFCVehIf_DeselectInfo_S()->mock_typeDeselect_u8,0x00u);//NFC_READER_DESELECT_NORMAL_TYPE_E
    EXPECT_EQ(get_rbd_NFCVehIf_DeselectInfo_S()->mock_retryTimer_u32,0);
    EXPECT_EQ(get_rbd_NFCVehIf_DeselectInfo_S()->mock_uRetryFinish_u8,FALSE);
}
/*
@rst
    Brief description of test case.
    :Description: switch((NfcEcuIds)nfcReaderId)
        case WCPM2
        (rbd_NFCVehIf_NFC_Count > 0U) ? 1U : 0U ==> FALSE
        if(((uint8)NFC_READER_CARD_PLANT_PAIR_STATE_E == session_state_u8) ||
				   ((uint8)NFC_READER_CARD_PLANT_PAIR_TEAR_DOWN_STATE_E == session_state_u8) ||
				   ((uint8)NFC_READER_OWNER_PAIRING_STATE_E == session_state_u8) ||
				   ((uint8)NFC_READER_OWNER_PAIRING_TEAR_DOWN_STATE_E == session_state_u8) ||
				   ((uint8)NFC_READER_GET_UID_STATE_E == session_state_u8) ||
				   ((uint8)NFC_READER_GET_UID_TEAR_DOWN_STATE_E == session_state_u8)) ==> FALSE MCDC (FFTXXX)
        else if(((uint8)NFC_READER_TAP_START_TEAR_DOWN_STATE_E == session_state_u8) ||
                ((uint8)NFC_READER_TAP_START_DEVICE_INFO_WAIT_STATE_E == session_state_u8)) ==> FALSE MCDC (FF)
        if(((uint8)NFC_READER_TAP_START_STOP_TRIGGER_STATE_E == session_state_u8) ||
				   ((uint8)NFC_READER_GET_UID_STATE_E == session_state_u8) ||
				   ((uint8)NFC_READER_GET_UID_TEAR_DOWN_STATE_E == session_state_u8)) ==> FALSE MCDC(FFF)
    :Arch ID: 307a4b14-a9de-4687-ba2e-5c65b174ce4a
    :REQ ID: NA
    :ALM Task ID: 306772
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    rbd_NFCVehIf_DESELECT_TimerRetry_Reload:
    :Description: Verifying for the function rbd_NFCVehIf_DESELECT_TimerRetry_Reload()
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 286698
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NfcTeardown_09)
{
    get_rbd_NFCVehIf_Table_as()[2].activeState_u8=0X40u;//NFC_READER_CARD_PLANT_TEST_STATE_E
    get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8=255;
    get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b=255;
    Rte_rbd_NFCVehIf_PP_Nfc_Count_Devices=255;
    // *get_rbd_NFCVehIf_getUID_active_b() = FALSE;Code removed
    call_rbd_NFCVehIf_NfcTeardown(2);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].activeState_u8,0X40u);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8,255);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b,255);
    EXPECT_EQ(get_rbd_NFCVehIf_DeselectInfo_S()->mock_nfcReaderId_en ,2);
    EXPECT_EQ(get_rbd_NFCVehIf_DeselectInfo_S()->mock_reqRetryCount_u8,2);
    EXPECT_EQ(get_rbd_NFCVehIf_DeselectInfo_S()->mock_typeDeselect_u8,0x00u);//NFC_READER_DESELECT_NORMAL_TYPE_E
    EXPECT_EQ(get_rbd_NFCVehIf_DeselectInfo_S()->mock_retryTimer_u32,0);
    EXPECT_EQ(get_rbd_NFCVehIf_DeselectInfo_S()->mock_uRetryFinish_u8,FALSE);
}
//----------------------------------------------------------------------------
// Test Cases// void rbd_NFCVehIf_DkmStartPolling(const rbdPk_NfcReaderId_t nfcReaderId, const uint8* const DigitalKeyFrameworkId)
//----------------------------------------------------------------------------
/*
@rst
    Brief description of test case.
    :Description: Verify for the function rbd_NFCVehIf_DkmStartPolling()
    :Arch ID: 85fd62ce-ebb2-479a-ba5e-febb28da8756
    :REQ ID: NA
    :ALM Task ID: 183001
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_NfcStartPolling
    :Description: Verify for the function rbd_NFCVehIf_NfcStartPolling()
    :Arch ID: 8bc39f9d-cc06-4406-bdb9-b337e61f9bce
    :REQ ID: NA
    :ALM Task ID: 183001
    :Testing Method: Positve
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_DkmStartPolling_01)
{
    uint8 DigitalKeyFrameworkId;
    call_rbd_NFCVehIf_DkmStartPolling(1,&DigitalKeyFrameworkId);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[1].connectionStatus_u8, (uint8)READER_IN_SESSION);
}

//----------------------------------------------------------------------------
// Test Cases// Std_ReturnType rbd_NFCVehIf_NfcFlow_NotifyAuthStatus(rbdPk_NfcReaderId_t ReaderId, Dkm_CccAuthStatus_en* CccAuthStatus, uint8 * DeviceRef)
//----------------------------------------------------------------------------
/*
@rst
    Brief description of test case.
    :Description: if((NULL != DeviceRef) && (NULL !=CccAuthStatus)) ==> FALSE MCDC (FX)
    :Arch ID: a520f81f-ad7b-4395-ab0e-9793013e35a8
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NfcFlow_NotifyAuthStatus_01)
{
   Std_ReturnType ret_val = call_rbd_NFCVehIf_NfcFlow_NotifyAuthStatus(1,NULL,NULL);
    EXPECT_EQ(ret_val,RTE_E_OK);
}
/*
@rst
    Brief description of test case.
    :Description: if((NULL != DeviceRef) && (NULL !=CccAuthStatus)) ==> FALSE MCDC (TF)
    :Arch ID: a520f81f-ad7b-4395-ab0e-9793013e35a8
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NfcFlow_NotifyAuthStatus_02)
{
    uint8 DeviceRef=255;
   Std_ReturnType ret_val = call_rbd_NFCVehIf_NfcFlow_NotifyAuthStatus(1,NULL,&DeviceRef);
    EXPECT_EQ(ret_val,RTE_E_OK);
}
/*
@rst
    Brief description of test case.
    :Description: if((NULL != DeviceRef) && (NULL !=CccAuthStatus)) ==> TRUE MCDC (TT)
        if(ReaderId <= NFC_NUM_READERS) ==> FALSE
    :Arch ID: a520f81f-ad7b-4395-ab0e-9793013e35a8
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NfcFlow_NotifyAuthStatus_03)
{
     uint8 DeviceRef=255;
     Dkm_CccAuthStatus_en CccAuthStatus=255;
   Std_ReturnType ret_val = call_rbd_NFCVehIf_NfcFlow_NotifyAuthStatus(4,&CccAuthStatus,&DeviceRef);
    EXPECT_EQ(ret_val,RTE_E_OK);
}
/*
@rst
    Brief description of test case.
    :Description: if((NULL != DeviceRef) && (NULL !=CccAuthStatus)) ==> TRUE MCDC (TT)
        if(ReaderId <= NFC_NUM_READERS) ==> TRUE
        if(NULL != rbd_NFCVehIf_NfcReaderAuthNotification_FuncTable[ReaderId]) ==> FALSE
    :Arch ID: a520f81f-ad7b-4395-ab0e-9793013e35a8
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NfcFlow_NotifyAuthStatus_04)
{
     uint8 DeviceRef=255;
     Dkm_CccAuthStatus_en CccAuthStatus=255;
   Std_ReturnType ret_val = call_rbd_NFCVehIf_NfcFlow_NotifyAuthStatus(1,&CccAuthStatus,&DeviceRef);
    EXPECT_EQ(ret_val,RTE_E_OK);
}
/*
@rst
    Brief description of test case.
    :Description: if((NULL != DeviceRef) && (NULL !=CccAuthStatus)) ==> TRUE MCDC (TT)
        if(ReaderId <= NFC_NUM_READERS) ==> TRUE
        if(NULL != rbd_NFCVehIf_NfcReaderAuthNotification_FuncTable[ReaderId]) ==> TRUE
    :Arch ID: a520f81f-ad7b-4395-ab0e-9793013e35a8
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_NfcFlow_FLDHM_AuthNotification
    :Description: if((DevRef_u8 <= 32u) && (Dkm_AuthStatus_en == RBD_CCC_DEV_AUTHENTICATED)) ==> TRUE MCDC (TT)
        if(RTE_E_OK == dkmRet_u8 ) ==> FALSE
    :Arch ID: a33aa220-b1d6-46ac-a9aa-497709f360ab
    :REQ ID: NA
    :ALM Task ID: 92308
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_UpdateNFCReaderState
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
        if(NULL != newDevRef_pu8) ==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NfcFlow_NotifyAuthStatus_05)
{
     uint8 DeviceRef=0;
     Dkm_CccAuthStatus_en CccAuthStatus=0;
     Rte_rbd_NFCVehIf_FailedAttemptsCounter_MirrorBlock=0;
     Dkm_GetKeyInfoDevice_Operation_fake.return_val=0;
     get_rbd_NFCVehIf_Table_as()[FLDHM].activeState_u8  = 1;
   Std_ReturnType ret_val = call_rbd_NFCVehIf_NfcFlow_NotifyAuthStatus(0,&CccAuthStatus,&DeviceRef);
    EXPECT_EQ(ret_val,RTE_E_OK);
    EXPECT_EQ(Dkm_GetKeyInfoDevice_Operation_fake.call_count,1);
    // EXPECT_EQ(Dkm_GetKeyInfoDevice_Operation_fake.arg0_val,0x20);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].activeState_u8,0X07);//NFC_READER_TAP_ENTRY_DEVICE_INFO_WAIT_STATE_E
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b,0);
}
//----------------------------------------------------------------------------
// Test Cases// static void rbd_NFCVehIf_NfcFlow_FLDHM_AuthNotification(Dkm_CccAuthStatus_en Dkm_AuthStatus_en, uint8 DevRef_u8)
//----------------------------------------------------------------------------
/*
@rst
    Brief description of test case.
    :Description: if((DevRef_u8 <= 32u) && (Dkm_AuthStatus_en == RBD_CCC_DEV_AUTHENTICATED)) ==> FALSE MCDC (FX)
        else if(((DevRef_u8 >=100u) && (DevRef_u8 <= 109u)) && (Dkm_AuthStatus_en == RBD_CCC_DEV_AUTHENTICATED)) ==> TRUE MCDC (TTT)
        if (*(Rte_Pim_FailedAttemptsCounter_MirrorBlock()) != auth_fail_counter_u8) ==> TRUE
    :Arch ID: a33aa220-b1d6-46ac-a9aa-497709f360ab
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_UpdateNFCReaderState
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
        if(NULL != newDevRef_pu8) ==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NfcFlow_FLDHM_AuthNotification_01)
{
    Rte_rbd_NFCVehIf_FailedAttemptsCounter_MirrorBlock=10;
     call_rbd_NFCVehIf_NfcFlow_FLDHM_AuthNotification(RBD_CCC_DEV_AUTHENTICATED,100);
    // EXPECT_EQ(Rte_rbd_NFCVehIf_FailedAttemptsCounter_MirrorBlock,0);
    // EXPECT_EQ(NvM_WriteBlock_fake.call_count,1);
    // // EXPECT_EQ(NvM_WriteBlock_fake.arg0_val,0);
    // EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].activeState_u8,2);
    // EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b,100);
}
/*
@rst
    Brief description of test case.
    :Description: if((DevRef_u8 <= 32u) && (Dkm_AuthStatus_en == RBD_CCC_DEV_AUTHENTICATED)) ==> FALSE MCDC (FX)
        else if(((DevRef_u8 >=100u) && (DevRef_u8 <= 109u)) && (Dkm_AuthStatus_en == RBD_CCC_DEV_AUTHENTICATED)) ==> FALSE MCDC (TTF)
        else if(RBD_CCC_DEV_AUTHENTICATION_FAILED == Dkm_AuthStatus_en) ==> TRUE
        if (*(Rte_Pim_FailedAttemptsCounter_MirrorBlock()) != auth_fail_counter_u8) ==> TRUE
    :Arch ID: a33aa220-b1d6-46ac-a9aa-497709f360ab
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_UpdateNFCReaderState
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
        if(NULL != newDevRef_pu8) ==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NfcFlow_FLDHM_AuthNotification_02)
{
    Rte_rbd_NFCVehIf_FailedAttemptsCounter_MirrorBlock=10;
     call_rbd_NFCVehIf_NfcFlow_FLDHM_AuthNotification(RBD_CCC_DEV_AUTHENTICATION_FAILED,100);
    // EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].activeState_u8,3);
    // EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b,100);
    // EXPECT_EQ(Rte_rbd_NFCVehIf_FailedAttemptsCounter_MirrorBlock,11);
    // EXPECT_EQ(NvM_WriteBlock_fake.call_count,1);
}
/*
@rst
    Brief description of test case.
    :Description: if((DevRef_u8 <= 32u) && (Dkm_AuthStatus_en == RBD_CCC_DEV_AUTHENTICATED)) ==> FALSE MCDC (FX)
        else if(((DevRef_u8 >=100u) && (DevRef_u8 <= 109u)) && (Dkm_AuthStatus_en == RBD_CCC_DEV_AUTHENTICATED)) ==> FALSE MCDC (TTF)
        else if(RBD_CCC_DEV_AUTHENTICATION_FAILED == Dkm_AuthStatus_en) ==> TRUE
        if (*(Rte_Pim_FailedAttemptsCounter_MirrorBlock()) != auth_fail_counter_u8) ==> FALSE
    :Arch ID: a33aa220-b1d6-46ac-a9aa-497709f360ab
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_UpdateNFCReaderState
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
        if(NULL != newDevRef_pu8) ==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NfcFlow_FLDHM_AuthNotification_03)
{
    Rte_rbd_NFCVehIf_FailedAttemptsCounter_MirrorBlock=0XFF;
     call_rbd_NFCVehIf_NfcFlow_FLDHM_AuthNotification(RBD_CCC_DEV_AUTHENTICATION_FAILED,100);
    // EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].activeState_u8,3);
    // EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b,100);
    // EXPECT_EQ(Rte_rbd_NFCVehIf_FailedAttemptsCounter_MirrorBlock,255);
}
/*
@rst
    Brief description of test case.
    :Description: if((DevRef_u8 <= 32u) && (Dkm_AuthStatus_en == RBD_CCC_DEV_AUTHENTICATED)) ==> FALSE MCDC (FX)
        else if(((DevRef_u8 >=100u) && (DevRef_u8 <= 109u)) && (Dkm_AuthStatus_en == RBD_CCC_DEV_AUTHENTICATED)) ==> FALSE MCDC (TTF)
        else if(RBD_CCC_DEV_AUTHENTICATION_FAILED == Dkm_AuthStatus_en) ==> FALSE
        if (*(Rte_Pim_FailedAttemptsCounter_MirrorBlock()) != auth_fail_counter_u8) ==> FALSE
    :Arch ID: a33aa220-b1d6-46ac-a9aa-497709f360ab
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NfcFlow_FLDHM_AuthNotification_04)
{
    Rte_rbd_NFCVehIf_FailedAttemptsCounter_MirrorBlock=0XFF;
     call_rbd_NFCVehIf_NfcFlow_FLDHM_AuthNotification(DCM_E_VMSCNC_E,100);
    EXPECT_EQ(Rte_rbd_NFCVehIf_FailedAttemptsCounter_MirrorBlock,255);
}
/*
@rst
    Brief description of test case.
    :Description: if((DevRef_u8 <= 32u) && (Dkm_AuthStatus_en == RBD_CCC_DEV_AUTHENTICATED)) ==> FALSE MCDC (FX)
        else if(((DevRef_u8 >=100u) && (DevRef_u8 <= 109u)) && (Dkm_AuthStatus_en == RBD_CCC_DEV_AUTHENTICATED)) ==> FALSE MCDC (TFX)
        else if(RBD_CCC_DEV_AUTHENTICATION_FAILED == Dkm_AuthStatus_en) ==> FALSE
        if (*(Rte_Pim_FailedAttemptsCounter_MirrorBlock()) != auth_fail_counter_u8) ==> FALSE
    :Arch ID: a33aa220-b1d6-46ac-a9aa-497709f360ab
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NfcFlow_FLDHM_AuthNotification_05)
{
    Rte_rbd_NFCVehIf_FailedAttemptsCounter_MirrorBlock=0XFF;
     call_rbd_NFCVehIf_NfcFlow_FLDHM_AuthNotification(DCM_E_VMSCNC_E,110);
    EXPECT_EQ(Rte_rbd_NFCVehIf_FailedAttemptsCounter_MirrorBlock,255);
}
/*
@rst
    Brief description of test case.
    :Description: if((DevRef_u8 <= 32u) && (Dkm_AuthStatus_en == RBD_CCC_DEV_AUTHENTICATED)) ==> FALSE MCDC (TF)
        else if(((DevRef_u8 >=100u) && (DevRef_u8 <= 109u)) && (Dkm_AuthStatus_en == RBD_CCC_DEV_AUTHENTICATED)) ==> FALSE MCDC (FXX)
        else if(RBD_CCC_DEV_AUTHENTICATION_FAILED == Dkm_AuthStatus_en) ==> FALSE
        if (*(Rte_Pim_FailedAttemptsCounter_MirrorBlock()) != auth_fail_counter_u8) ==> FALSE
    :Arch ID: a33aa220-b1d6-46ac-a9aa-497709f360ab
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NfcFlow_FLDHM_AuthNotification_06)
{
    Rte_rbd_NFCVehIf_FailedAttemptsCounter_MirrorBlock=0XFF;
     call_rbd_NFCVehIf_NfcFlow_FLDHM_AuthNotification(DCM_E_VMSCNC_E,32);
    EXPECT_EQ(Rte_rbd_NFCVehIf_FailedAttemptsCounter_MirrorBlock,255);
}
/*
@rst
    Brief description of test case.
    :Description: if((DevRef_u8 <= 32u) && (Dkm_AuthStatus_en == RBD_CCC_DEV_AUTHENTICATED)) ==> TRUE MCDC (TT)
        if(RTE_E_OK == dkmRet_u8 ) ==> FALSE
    :Arch ID: a33aa220-b1d6-46ac-a9aa-497709f360ab
    :REQ ID: NA
    :ALM Task ID: 92308
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NfcFlow_FLDHM_AuthNotification_07)
{
    Rte_rbd_NFCVehIf_FailedAttemptsCounter_MirrorBlock=0XFF;
    Dkm_GetKeyInfoDevice_Operation_fake.return_val=1;
    get_rbd_NFCVehIf_Table_as()[FLDHM].activeState_u8  = 1;
     call_rbd_NFCVehIf_NfcFlow_FLDHM_AuthNotification(RBD_CCC_DEV_AUTHENTICATED,32);
    EXPECT_EQ(Rte_rbd_NFCVehIf_FailedAttemptsCounter_MirrorBlock,0);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].activeState_u8,0X04);//NFC_READER_TAP_ENTRY_DEVICE_AUTH_SUCCESS_STATE_E
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b,32);
}
//----------------------------------------------------------------------------
// Test Cases//static void rbd_NFCVehIf_NfcFlow_WCPM2_AuthNotification(Dkm_CccAuthStatus_en Dkm_AuthStatus_en, uint8 DevRef_u8)
//----------------------------------------------------------------------------
/*
@rst
    Brief description of test case.
    :Description: if (Dkm_AuthStatus_en == RBD_CCC_DEV_AUTHENTICATED) ==> TRUE
        if (wcpmSession_state_u8 == (uint8)NFC_READER_OWNER_PAIRING_STATE_E) ==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 286698
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_UpdateNFCReaderState
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
        if(NULL != newDevRef_pu8) ==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NfcFlow_WCPM2_AuthNotification_01)
{
    get_rbd_NFCVehIf_Table_as()[2].activeState_u8=0x20u;//(uint8)NFC_READER_OWNER_PAIRING_STATE_E(0X0B)
    get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8=255;
    get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b=TRUE;
    call_rbd_NFCVehIf_NfcFlow_WCPM2_AuthNotification(RBD_CCC_DEV_AUTHENTICATED,100);
    EXPECT_EQ(Rte_Write_rbd_NFCVehIf_rbd_NFCVehIf_NFC_PhoneKeyPariring_Result_NFCPhoneKeyPariring_Result_fake.call_count,1);
    EXPECT_EQ(Rte_Write_rbd_NFCVehIf_rbd_NFCVehIf_NFC_PhoneKeyPariring_Result_NFCPhoneKeyPariring_Result_fake.arg0_val,RBD_CCC_DEV_AUTHENTICATED);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].activeState_u8,0x21u);//NFC_READER_OWNER_PAIRING_TEAR_DOWN_STATE_E
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b, 100);
}
/*
@rst
    Brief description of test case.
    :Description: if (Dkm_AuthStatus_en == RBD_CCC_DEV_AUTHENTICATED) ==> TRUE
        if (wcpmSession_state_u8 == (uint8)NFC_READER_OWNER_PAIRING_STATE_E) ==> FALSE
        else if (wcpmSession_state_u8 == (uint8)NFC_READER_TAP_START_FLOW_INIT_STATE_E) ==> TRUE
        if((DevRef_u8 >=100u) && (DevRef_u8 <= 109u)) ==> FALSE MCDC (TF)
        else if(DevRef_u8 < 32u) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 286698
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_UpdateNFCReaderState
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
        if(NULL != newDevRef_pu8) ==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NfcFlow_WCPM2_AuthNotification_02)
{
    get_rbd_NFCVehIf_Table_as()[2].activeState_u8=0x10u;//(uint8)NFC_READER_TAP_START_FLOW_INIT_STATE_E
    get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8=255;
    get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b=TRUE;
    Dkm_GetKeyInfoDevice_Operation_fake.return_val=RTE_E_OK;
    call_rbd_NFCVehIf_NfcFlow_WCPM2_AuthNotification(RBD_CCC_DEV_AUTHENTICATED,110);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].activeState_u8,0x14u);//NFC_READER_TAP_START_DEVICE_AUTH_FAILED_STATE_E
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b,110);
}
/*
@rst
    Brief description of test case.
    :Description: if (Dkm_AuthStatus_en == RBD_CCC_DEV_AUTHENTICATED) ==> TRUE
        if (wcpmSession_state_u8 == (uint8)NFC_READER_OWNER_PAIRING_STATE_E) ==> FALSE
        else if (wcpmSession_state_u8 == (uint8)NFC_READER_TAP_START_FLOW_INIT_STATE_E) ==> TRUE
        if((DevRef_u8 >=100u) && (DevRef_u8 <= 109u)) ==> FALSE MCDC (FX)
        else if(DevRef_u8 < 32u) ==> TRUE
        if(RTE_E_OK == dkmRet_u8 ) ==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 286698
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_UpdateNFCReaderState
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
        if(NULL != newDevRef_pu8) ==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NfcFlow_WCPM2_AuthNotification_03)
{
    get_rbd_NFCVehIf_Table_as()[2].activeState_u8=0x10u;//(uint8)NFC_READER_TAP_START_FLOW_INIT_STATE_E
    get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8=255;
    get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b=TRUE;
    Dkm_GetKeyInfoDevice_Operation_fake.return_val=RTE_E_OK;
     call_rbd_NFCVehIf_NfcFlow_WCPM2_AuthNotification(RBD_CCC_DEV_AUTHENTICATED,31);
    EXPECT_EQ(Dkm_GetKeyInfoDevice_Operation_fake.call_count,1);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].activeState_u8,0x15u);//NFC_READER_TAP_START_DEVICE_INFO_WAIT_STATE_E
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b,31);
}
/*
@rst
    Brief description of test case.
    :Description: if (Dkm_AuthStatus_en == RBD_CCC_DEV_AUTHENTICATED) ==> TRUE
        if (wcpmSession_state_u8 == (uint8)NFC_READER_OWNER_PAIRING_STATE_E) ==> FALSE
        else if (wcpmSession_state_u8 == (uint8)NFC_READER_TAP_START_FLOW_INIT_STATE_E) ==> TRUE
        if((DevRef_u8 >=100u) && (DevRef_u8 <= 109u)) ==> FALSE MCDC (FX)
        else if(DevRef_u8 < 32u) ==> TRUE
        if(RTE_E_OK == dkmRet_u8 ) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 286698
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_UpdateNFCReaderState
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
        if(NULL != newDevRef_pu8) ==> TRUE
    :Arch ID:
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NfcFlow_WCPM2_AuthNotification_04)
{
    get_rbd_NFCVehIf_Table_as()[2].activeState_u8=0x10u;//(uint8)NFC_READER_TAP_START_FLOW_INIT_STATE_E
    get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8=255;
    get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b=TRUE;
    Dkm_GetKeyInfoDevice_Operation_fake.return_val=RTE_E_INVALID;
    call_rbd_NFCVehIf_NfcFlow_WCPM2_AuthNotification(RBD_CCC_DEV_AUTHENTICATED,31);
    EXPECT_EQ(Dkm_GetKeyInfoDevice_Operation_fake.call_count,1);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].activeState_u8,0x13u);//NFC_READER_TAP_START_DEVICE_AUTH_SUCCESS_STATE_E
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b, 31);
}
/*
@rst
    Brief description of test case.
    :Description: if (Dkm_AuthStatus_en == RBD_CCC_DEV_AUTHENTICATED) ==> TRUE
        if (wcpmSession_state_u8 == (uint8)NFC_READER_OWNER_PAIRING_STATE_E) ==> FALSE
        else if (wcpmSession_state_u8 == (uint8)NFC_READER_TAP_START_FLOW_INIT_STATE_E) ==> TRUE
        if((DevRef_u8 >=100u) && (DevRef_u8 <= 109u)) ==> TRUE MCDC (TT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 286698
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_UpdateNFCReaderState
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
        if(NULL != newDevRef_pu8) ==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NfcFlow_WCPM2_AuthNotification_05)
{
    get_rbd_NFCVehIf_Table_as()[2].activeState_u8=0x10u;//(uint8)NFC_READER_TAP_START_FLOW_INIT_STATE_E
    get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8=255;
    get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b=TRUE;
    call_rbd_NFCVehIf_NfcFlow_WCPM2_AuthNotification(RBD_CCC_DEV_AUTHENTICATED,100);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].activeState_u8,0x11u);//(uint8)NFC_READER_TAP_START_CARD_AUTH_SUCCESS_STATE_E
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b,100);;
}
/*
@rst
    Brief description of test case.
    :Description: if (Dkm_AuthStatus_en == RBD_CCC_DEV_AUTHENTICATED) ==> TRUE
        if (wcpmSession_state_u8 == (uint8)NFC_READER_OWNER_PAIRING_STATE_E) ==> FALSE
        else if (wcpmSession_state_u8 == (uint8)NFC_READER_TAP_START_FLOW_INIT_STATE_E) ==> FALSE
        else if (wcpmSession_state_u8 == (uint8)NFC_READER_PHONE_ENABLE_DISABLE_WCP_AUTH_INIT_STATE_E) ==> FALSE
        else if (wcpmSession_state_u8 == (uint8)NFC_READER_CARD_PLANT_PAIR_STATE_E) ==> FALSE
        else if(wcpmSession_state_u8 == (uint8)NFC_READER_CARD_PLANT_TEST_STATE_E) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 286698
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_UpdateNFCReaderState
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
        if(NULL != newDevRef_pu8) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NfcFlow_WCPM2_AuthNotification_06)
{
    get_rbd_NFCVehIf_Table_as()[2].activeState_u8=0x0Au;
    get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8=255;
    get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b=TRUE;
    // *get_rbd_NFCVehIf_NfcCardTimerIsActive_b() =TRUE;Code removed
    call_rbd_NFCVehIf_NfcFlow_WCPM2_AuthNotification(RBD_CCC_DEV_AUTHENTICATED,100);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].activeState_u8,0x0A);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b,TRUE);
    // EXPECT_EQ(get_rbd_NFCVehIf_CardData_st()->routineStatus_u8 , 1);
    // EXPECT_EQ(get_rbd_NFCVehIf_CardData_st()->errorCode_u8  ,0);
    // for (uint8 i_u8 = 0; i_u8 < NFC_CARD_UID_LEN; ++i_u8)
	// {
    //   EXPECT_EQ(get_rbd_NFCVehIf_CardData_st()->cardUID_au8[i_u8],get_rbd_NFCVehIf_NfcCardDefaultUid_au8()[i_u8]);
	// }Code removed
}
/*
@rst
    Brief description of test case.
    :Description: if (Dkm_AuthStatus_en == RBD_CCC_DEV_AUTHENTICATED) ==> FALSE
        else if (Dkm_AuthStatus_en == RBD_CCC_DEV_AUTHENTICATION_FAILED) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 286698
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NfcFlow_WCPM2_AuthNotification_07)
{
    get_rbd_NFCVehIf_Table_as()[2].activeState_u8=0x0Au;
    get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8=255;
    get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b=TRUE;
     call_rbd_NFCVehIf_NfcFlow_WCPM2_AuthNotification(RBD_CCC_DEV_PENDING,100);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].activeState_u8,0x0Au);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b,TRUE);
}
/*
@rst
    Brief description of test case.
    :Description: if (Dkm_AuthStatus_en == RBD_CCC_DEV_AUTHENTICATED) ==> FALSE
        else if (Dkm_AuthStatus_en == RBD_CCC_DEV_AUTHENTICATION_FAILED) ==> TRUE
        if (wcpmSession_state_u8 == (uint8)NFC_READER_CARD_PLANT_PAIR_STATE_E) ==> FALSE
        else if (wcpmSession_state_u8 == (uint8)NFC_READER_CARD_PLANT_TEST_STATE_E) ==> FALSE
        else if(wcpmSession_state_u8 == (uint8)NFC_READER_TAP_START_FLOW_INIT_STATE_E) ==> FALSE
        else if (wcpmSession_state_u8 == (uint8)NFC_READER_PHONE_ENABLE_DISABLE_WCP_AUTH_INIT_STATE_E) ==> FALSE
        else if (wcpmSession_state_u8 == (uint8)NFC_READER_OWNER_PAIRING_STATE_E) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 286698
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_UpdateNFCReaderState
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
        if(NULL != newDevRef_pu8) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NfcFlow_WCPM2_AuthNotification_08)
{
    get_rbd_NFCVehIf_Table_as()[2].activeState_u8=0x21u;//NFC_READER_OWNER_PAIRING_TEAR_DOWN_STATE_E
    get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8=255;
    get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b=TRUE;
    // get_rbd_NFCVehIf_CardData_st()->pollCardPairError_b=FALSE;Code removed
     call_rbd_NFCVehIf_NfcFlow_WCPM2_AuthNotification(RBD_CCC_DEV_AUTHENTICATION_FAILED,100);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].activeState_u8,0x21);//NFC_READER_OWNER_PAIRING_TEAR_DOWN_STATE_E
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b,TRUE);
    // EXPECT_EQ(get_rbd_NFCVehIf_CardData_st()->pollCardPairError_b, FALSE);Code removed
}
/*
@rst
    Brief description of test case.
    :Description: if (Dkm_AuthStatus_en == RBD_CCC_DEV_AUTHENTICATED) ==> FALSE
        else if (Dkm_AuthStatus_en == RBD_CCC_DEV_AUTHENTICATION_FAILED) ==> TRUE
        if (wcpmSession_state_u8 == (uint8)NFC_READER_CARD_PLANT_PAIR_STATE_E) ==> FALSE
        else if (wcpmSession_state_u8 == (uint8)NFC_READER_CARD_PLANT_TEST_STATE_E) ==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 286698
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_UpdateNfcCardData
    :Description: for (uint8 i_u8 = 0; i_u8 < NFC_CARD_UID_LEN; ++i_u8) ==> TRUE,FALSE
    :Arch ID: 66b6e4c0-51ea-4aa7-b0ce-2dd0aa0bc066
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_UpdateNFCReaderState
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
        if(NULL != newDevRef_pu8) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NfcFlow_WCPM2_AuthNotification_09)
{
    get_rbd_NFCVehIf_Table_as()[2].activeState_u8=0x40U;//NFC_READER_CARD_PLANT_TEST_STATE_E
    get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8=255;
    get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b=TRUE;
    // *get_rbd_NFCVehIf_NfcCardTimerIsActive_b() =TRUE;Code removed
     call_rbd_NFCVehIf_NfcFlow_WCPM2_AuthNotification(RBD_CCC_DEV_AUTHENTICATION_FAILED,100);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].activeState_u8,0x41);//(uint8)NFC_READER_CARD_PLANT_TEST_TEAR_DOWN_STATE_E
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b, 0x64);
    // EXPECT_EQ(get_rbd_NFCVehIf_CardData_st()->routineStatus_u8 ,3);
    // EXPECT_EQ(get_rbd_NFCVehIf_CardData_st()->errorCode_u8  ,1);
    // for (uint8 i_u8 = 0; i_u8 < NFC_CARD_UID_LEN; ++i_u8)
	// {
    //   EXPECT_EQ(get_rbd_NFCVehIf_CardData_st()->cardUID_au8[i_u8],get_rbd_NFCVehIf_NfcCardDefaultUid_au8()[i_u8]);
	// }Code removed
    // EXPECT_EQ(FALSE,*get_rbd_NFCVehIf_NfcCardTimerIsActive_b());Code removed
}
/*
@rst
    Brief description of test case.
    :Description: if (Dkm_AuthStatus_en == RBD_CCC_DEV_AUTHENTICATED) ==> FALSE
        else if (Dkm_AuthStatus_en == RBD_CCC_DEV_AUTHENTICATION_FAILED) ==> TRUE
        if (wcpmSession_state_u8 == (uint8)NFC_READER_CARD_PLANT_PAIR_STATE_E) ==> FALSE
        else if (wcpmSession_state_u8 == (uint8)NFC_READER_CARD_PLANT_TEST_STATE_E) ==> FALSE
        else if(wcpmSession_state_u8 == (uint8)NFC_READER_TAP_START_FLOW_INIT_STATE_E)=> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 286698
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_UpdateNFCReaderState
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
        if(NULL != newDevRef_pu8) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NfcFlow_WCPM2_AuthNotification_10)
{
    get_rbd_NFCVehIf_Table_as()[2].activeState_u8=0x10u;//NFC_READER_TAP_START_FLOW_INIT_STATE_E
    get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8=255;
    get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b=TRUE;
    // get_rbd_NFCVehIf_CardData_st()->pollCardPairError_b=FALSE;Code removed
    call_rbd_NFCVehIf_NfcFlow_WCPM2_AuthNotification(RBD_CCC_DEV_AUTHENTICATION_FAILED,100);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].activeState_u8,0x14);//NFC_READER_TAP_START_DEVICE_AUTH_FAILED_STATE_E
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b, 100);
}
/*
@rst
    Brief description of test case.
    :Description: if (Dkm_AuthStatus_en == RBD_CCC_DEV_AUTHENTICATED) ==> FALSE
        else if (Dkm_AuthStatus_en == RBD_CCC_DEV_AUTHENTICATION_FAILED) ==> TRUE
        if (wcpmSession_state_u8 == (uint8)NFC_READER_CARD_PLANT_PAIR_STATE_E) ==> FALSE
        else if (wcpmSession_state_u8 == (uint8)NFC_READER_CARD_PLANT_TEST_STATE_E) ==> FALSE
        else if(wcpmSession_state_u8 == (uint8)NFC_READER_TAP_START_FLOW_INIT_STATE_E)=> FALSE
        else if (wcpmSession_state_u8 == (uint8)NFC_READER_PHONE_ENABLE_DISABLE_WCP_AUTH_INIT_STATE_E) ==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 286698
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_UpdateNFCReaderState
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
        if(NULL != newDevRef_pu8) ==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NfcFlow_WCPM2_AuthNotification_11)
{
    get_rbd_NFCVehIf_Table_as()[2].activeState_u8=0x60u;//NFC_READER_PHONE_ENABLE_DISABLE_WCP_AUTH_INIT_STATE_E
    get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8=255;
    get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b=TRUE;
    // get_rbd_NFCVehIf_CardData_st()->pollCardPairError_b=FALSE;Code removed
    call_rbd_NFCVehIf_NfcFlow_WCPM2_AuthNotification(RBD_CCC_DEV_AUTHENTICATION_FAILED,100);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].activeState_u8,0x61);//NFC_READER_PHONE_ENABLE_DISABLE_WCP_AUTH_FINISH_STATE_E
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b,100);
    EXPECT_EQ(rbd_VSM_WcpKeyAuthResult_Cbk_fake.call_count, 1);
    EXPECT_EQ(rbd_VSM_WcpKeyAuthResult_Cbk_fake.arg0_val, FALSE);
}
/*
@rst
    Brief description of test case.
    :Description: if (Dkm_AuthStatus_en == RBD_CCC_DEV_AUTHENTICATED) ==> TRUE
        if (wcpmSession_state_u8 == (uint8)NFC_READER_OWNER_PAIRING_STATE_E) ==> FALSE
        else if (wcpmSession_state_u8 == (uint8)NFC_READER_TAP_START_FLOW_INIT_STATE_E) ==> FALSE
        else if (wcpmSession_state_u8 == (uint8)NFC_READER_PHONE_ENABLE_DISABLE_WCP_AUTH_INIT_STATE_E) ==> FALSE
        else if (wcpmSession_state_u8 == (uint8)NFC_READER_CARD_PLANT_PAIR_STATE_E) ==> FALSE
        else if(wcpmSession_state_u8 == (uint8)NFC_READER_CARD_PLANT_TEST_STATE_E) ==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 286698
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_UpdateNfcCardData
    :Description: for (uint8 i_u8 = 0; i_u8 < NFC_CARD_UID_LEN; ++i_u8) ==> TRUE,FALSE
    :Arch ID: 66b6e4c0-51ea-4aa7-b0ce-2dd0aa0bc066
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_UpdateNFCReaderState
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
        if(NULL != newDevRef_pu8) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NfcFlow_WCPM2_AuthNotification_12)
{
    get_rbd_NFCVehIf_Table_as()[2].activeState_u8=0x40;//NFC_READER_CARD_PLANT_TEST_STATE_E
    get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8=255;
    get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b=0x1;
    // *get_rbd_NFCVehIf_NfcCardTimerIsActive_b() =TRUE;Code removed
    call_rbd_NFCVehIf_NfcFlow_WCPM2_AuthNotification(RBD_CCC_DEV_AUTHENTICATED,100);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].activeState_u8,0x41);//(uint8)NFC_READER_CARD_PLANT_TEST_TEAR_DOWN_STATE_E
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b,0x64);
    // for (uint8 i_u8 = 0; i_u8 < NFC_CARD_UID_LEN; ++i_u8)
	// {
    //   EXPECT_EQ(get_rbd_NFCVehIf_CardData_st()->cardUID_au8[i_u8],get_rbd_NFCVehIf_NfcCardDefaultUid_au8()[i_u8]);
	// }Code removed
}
/*
@rst
    Brief description of test case.
    :Description: if (Dkm_AuthStatus_en == RBD_CCC_DEV_AUTHENTICATED) ==> TRUE
        if (wcpmSession_state_u8 == (uint8)NFC_READER_OWNER_PAIRING_STATE_E) ==> FALSE
        else if (wcpmSession_state_u8 == (uint8)NFC_READER_TAP_START_FLOW_INIT_STATE_E) ==> FALSE
        else if (wcpmSession_state_u8 == (uint8)NFC_READER_PHONE_ENABLE_DISABLE_WCP_AUTH_INIT_STATE_E) ==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 286698
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_UpdateNFCReaderState
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
        if(NULL != newDevRef_pu8) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NfcFlow_WCPM2_AuthNotification_13)
{
    get_rbd_NFCVehIf_Table_as()[2].activeState_u8=0x60;//NFC_READER_PHONE_ENABLE_DISABLE_WCP_AUTH_INIT_STATE_E
    get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8=255;
    get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b=0x1;
    // *get_rbd_NFCVehIf_NfcCardTimerIsActive_b() =TRUE;Code removed
    call_rbd_NFCVehIf_NfcFlow_WCPM2_AuthNotification(RBD_CCC_DEV_AUTHENTICATED,100);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].activeState_u8,0x61);//(uint8)NFC_READER_PHONE_ENABLE_DISABLE_WCP_AUTH_FINISH_STATE_E
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b, 100);
    // for (uint8 i_u8 = 0; i_u8 < NFC_CARD_UID_LEN; ++i_u8)
	// {
    //   EXPECT_EQ(get_rbd_NFCVehIf_CardData_st()->cardUID_au8[i_u8],get_rbd_NFCVehIf_NfcCardDefaultUid_au8()[i_u8]);
	// }Code removed
    EXPECT_EQ(rbd_VSM_WcpKeyAuthResult_Cbk_fake.call_count, 1);
}
/*
@rst
    Brief description of test case.
    :Description: if (Dkm_AuthStatus_en == RBD_CCC_DEV_AUTHENTICATED) ==> TRUE
        if (wcpmSession_state_u8 == (uint8)NFC_READER_OWNER_PAIRING_STATE_E) ==> FALSE
        else if (wcpmSession_state_u8 == (uint8)NFC_READER_TAP_START_FLOW_INIT_STATE_E) ==> FALSE
        else if (wcpmSession_state_u8 == (uint8)NFC_READER_PHONE_ENABLE_DISABLE_WCP_AUTH_INIT_STATE_E) ==> FALSE
        else if (wcpmSession_state_u8 == (uint8)NFC_READER_CARD_PLANT_PAIR_STATE_E) ==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 286698
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_UpdateNfcCardData
    :Description: for (uint8 i_u8 = 0; i_u8 < NFC_CARD_UID_LEN; ++i_u8) ==> TRUE,FALSE
    :Arch ID: 66b6e4c0-51ea-4aa7-b0ce-2dd0aa0bc066
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_UpdateNFCReaderState
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
        if(NULL != newDevRef_pu8) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NfcFlow_WCPM2_AuthNotification_14)
{
    get_rbd_NFCVehIf_Table_as()[2].activeState_u8=0x30;//NFC_READER_CARD_PLANT_PAIR_STATE_E
    get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8=255;
    get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b=0x1;
    // *get_rbd_NFCVehIf_NfcCardTimerIsActive_b() =TRUE;Code removed
    call_rbd_NFCVehIf_NfcFlow_WCPM2_AuthNotification(RBD_CCC_DEV_AUTHENTICATED,100);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].activeState_u8,0x31);//(uint8)NFC_READER_CARD_PLANT_PAIR_TEAR_DOWN_STATE_E
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b, 100);
    // for (uint8 i_u8 = 0; i_u8 < NFC_CARD_UID_LEN; ++i_u8)
	// {
    //   EXPECT_EQ(get_rbd_NFCVehIf_CardData_st()->cardUID_au8[i_u8],get_rbd_NFCVehIf_NfcCardDefaultUid_au8()[i_u8]);
	// }Code removed
    // EXPECT_EQ(FALSE,*get_rbd_NFCVehIf_NfcCardTimerIsActive_b());Code removed
}
/*
@rst
    Brief description of test case.
    :Description: if (Dkm_AuthStatus_en == RBD_CCC_DEV_AUTHENTICATED) ==> FALSE
        else if (Dkm_AuthStatus_en == RBD_CCC_DEV_AUTHENTICATION_FAILED) ==> TRUE
        if (wcpmSession_state_u8 == (uint8)NFC_READER_CARD_PLANT_PAIR_STATE_E) ==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 286698
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_UpdateNFCReaderState
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
        if(NULL != newDevRef_pu8) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NfcFlow_WCPM2_AuthNotification_15)
{
    get_rbd_NFCVehIf_Table_as()[2].activeState_u8=0x30;//NFC_READER_CARD_PLANT_PAIR_STATE_E
    get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8=255;
    get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b=0x1;
    // get_rbd_NFCVehIf_CardData_st()->pollCardPairError_b=FALSE;Code removed
    call_rbd_NFCVehIf_NfcFlow_WCPM2_AuthNotification(RBD_CCC_DEV_AUTHENTICATION_FAILED,100);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].activeState_u8,0x31);//NFC_READER_CARD_PLANT_PAIR_TEAR_DOWN_STATE_E
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b, 100);
}
/*
@rst
    Brief description of test case.
    :Description: if (Dkm_AuthStatus_en == RBD_CCC_DEV_AUTHENTICATED) ==> FALSE
        else if (Dkm_AuthStatus_en == RBD_CCC_DEV_AUTHENTICATION_FAILED) ==> TRUE
        if (wcpmSession_state_u8 == (uint8)NFC_READER_CARD_PLANT_PAIR_STATE_E) ==> FALSE
        else if (wcpmSession_state_u8 == (uint8)NFC_READER_CARD_PLANT_TEST_STATE_E) ==> FALSE
        else if(wcpmSession_state_u8 == (uint8)NFC_READER_TAP_START_FLOW_INIT_STATE_E) ==> FALSE
        else if (wcpmSession_state_u8 == (uint8)NFC_READER_PHONE_ENABLE_DISABLE_WCP_AUTH_INIT_STATE_E) ==> FALSE
        else if (wcpmSession_state_u8 == (uint8)NFC_READER_OWNER_PAIRING_STATE_E) ==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 286698
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_UpdateNFCReaderState
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
        if(NULL != newDevRef_pu8) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NfcFlow_WCPM2_AuthNotification_16)
{
    get_rbd_NFCVehIf_Table_as()[2].activeState_u8=0x20;//NFC_READER_OWNER_PAIRING_STATE_E
    get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8=255;
    get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b=0x1;
    // get_rbd_NFCVehIf_CardData_st()->pollCardPairError_b=FALSE;Code removed
    call_rbd_NFCVehIf_NfcFlow_WCPM2_AuthNotification(RBD_CCC_DEV_AUTHENTICATION_FAILED,100);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].activeState_u8,0x21);//NFC_READER_OWNER_PAIRING_TEAR_DOWN_STATE_E
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b, 100);
}
//----------------------------------------------------------------------------
// Test Cases// void rbd_NFCVehIf_SendStopTrigger(void)
//----------------------------------------------------------------------------
/*
@rst
    Brief description of test case.
    :Description: if(READER_IN_SESSION == wcpmReaderConnection_state_u8) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 286698
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

     Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_SendStopTrigger_01)
{
    get_rbd_NFCVehIf_Table_as()[2].activeState_u8=0X00;//NFC_READER_NOT_ACTIVE_STATE_E
    get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8=255;
    get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b=TRUE;
    call_rbd_NFCVehIf_SendStopTrigger();
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].activeState_u8,0X00);//NFC_READER_NOT_ACTIVE_STATE_E
    EXPECT_EQ(rbdSessionMgr_NfcDisconnected_fake.call_count, 1);
}
/*
@rst
    Brief description of test case.
    :Description: if(READER_IN_SESSION == wcpmReaderConnection_state_u8) ==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 286698
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

     Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_NfcTeardown()
    :Description: switch((NfcEcuIds)nfcReaderId)
        case WCPM2
        (rbd_NFCVehIf_NFC_Count > 0U) ? 1U : 0U ==> FALSE
        if(((uint8)NFC_READER_CARD_PLANT_PAIR_STATE_E == session_state_u8) ||
				   ((uint8)NFC_READER_CARD_PLANT_PAIR_TEAR_DOWN_STATE_E == session_state_u8) ||
				   ((uint8)NFC_READER_OWNER_PAIRING_STATE_E == session_state_u8) ||
				   ((uint8)NFC_READER_OWNER_PAIRING_TEAR_DOWN_STATE_E == session_state_u8) ||
				   ((uint8)NFC_READER_GET_UID_STATE_E == session_state_u8) ||
				   ((uint8)NFC_READER_GET_UID_TEAR_DOWN_STATE_E == session_state_u8)) ==> FALSE MCDC (FFFFFF)
        else if(((uint8)NFC_READER_TAP_START_TEAR_DOWN_STATE_E == session_state_u8) ||
				    ((uint8)NFC_READER_TAP_START_DEVICE_INFO_WAIT_STATE_E == session_state_u8)) ==> FALSE MCDC(FF)
        if(((uint8)NFC_READER_TAP_START_STOP_TRIGGER_STATE_E == session_state_u8) ||
				   ((uint8)NFC_READER_GET_UID_STATE_E == session_state_u8) ||
				   ((uint8)NFC_READER_GET_UID_TEAR_DOWN_STATE_E == session_state_u8)) ==> TRUE MCDC(TXX)
    :Arch ID: 307a4b14-a9de-4687-ba2e-5c65b174ce4a
    :REQ ID: NA
    :ALM Task ID: 286698
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_SendStopTrigger_02)
{
    get_rbd_NFCVehIf_Table_as()[2].activeState_u8=0X00;//NFC_READER_NOT_ACTIVE_STATE_E
    get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8= 1;
    get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b=TRUE;
    call_rbd_NFCVehIf_SendStopTrigger();
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].activeState_u8,0X00);//NFC_READER_NOT_ACTIVE_STATE_E
    EXPECT_EQ(rbdSessionMgr_NfcDisconnected_fake.call_count, 1);
}
//----------------------------------------------------------------------------
// Test Cases// void rbd_NFCVehIf_SendStartTrigger(void)
//----------------------------------------------------------------------------
/*
@rst
    Brief description of test case.
    :Description: if(readerConnection_state_u8 == READER_DISCONNECTED) ==> TRUE
        if ( READER_IN_SESSION == readerConnection_state_u8 ) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 306772
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 ) && ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC(TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 270909
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_RegisterNFCReaderSession
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
        if ( READER_DISCONNECTED == rbd_NFCVehIf_Table_as[NfcReaderId_u8].connectionStatus_u8 ) ==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

     Calling function rbd_NFCVehIf_UpdateNFCReaderState
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
        if(NULL != newDevRef_pu8) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_SendStartTrigger_01)
{
    get_rbd_NFCVehIf_Table_as()[(uint8)FLDHM].activeState_u8=0X00;//NFC_READER_NOT_ACTIVE_STATE_E
    get_rbd_NFCVehIf_Table_as()[(uint8)FLDHM].connectionStatus_u8=READER_DISCONNECTED;
    get_rbd_NFCVehIf_Table_as()[(uint8)FLDHM].Key_Card_Ref_b=TRUE;

    get_rbd_NFCVehIf_Table_as()[(uint8)WCPM2].activeState_u8=0X00;//NFC_READER_NOT_ACTIVE_STATE_E
    get_rbd_NFCVehIf_Table_as()[(uint8)WCPM2].connectionStatus_u8=READER_DISCONNECTED;
    get_rbd_NFCVehIf_Table_as()[(uint8)WCPM2].Key_Card_Ref_b=TRUE;

    call_rbd_NFCVehIf_SendStartTrigger();
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[(uint8)WCPM2].connectionStatus_u8 ,READER_IN_SESSION);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[(uint8)WCPM2].Key_Card_Ref_b,RBDPK_KEYREF_INVALID);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[(uint8)WCPM2].activeState_u8,0x18);//(uint8)NFC_READER_TAP_START_RFHM_TRIGGER_RX_STATE_E
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[(uint8)WCPM2].session_timeout_u16,NFC_SESSION_TIMEOUT);
//    EXPECT_EQ(Dkm_NfcFlow_Start_fake.call_count,0x01);
//    EXPECT_EQ(Dkm_NfcFlow_Start_fake.arg2_val,0);
//    EXPECT_EQ(Dkm_NfcFlow_Start_fake.arg3_val,0);
//    EXPECT_EQ(Dkm_NfcFlow_Start_fake.arg4_val,0);
    EXPECT_EQ(Dkm_GetNumberOfKeyEntries_Operation_fake.call_count,1);
}

/*
@rst
    Brief description of test case.
    :Description: if(readerConnection_state_u8 == READER_DISCONNECTED) ==> TRUE
        if ( READER_IN_SESSION == readerConnection_state_u8 ) ==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 306772
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 ) && ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC(TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 270909
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ResetNFCReaderSessionTag
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 270909
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_RegisterNFCReaderSession
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
        if ( READER_DISCONNECTED == rbd_NFCVehIf_Table_as[NfcReaderId_u8].connectionStatus_u8 ) ==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_UpdateNFCReaderState
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
        if(NULL != newDevRef_pu8) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_SendStartTrigger_02)
{
    get_rbd_NFCVehIf_Table_as()[(uint8)FLDHM].activeState_u8=0X00;//NFC_READER_NOT_ACTIVE_STATE_E
    get_rbd_NFCVehIf_Table_as()[(uint8)FLDHM].connectionStatus_u8=READER_DISCONNECTED;
    get_rbd_NFCVehIf_Table_as()[(uint8)FLDHM].Key_Card_Ref_b=TRUE;

    get_rbd_NFCVehIf_Table_as()[(uint8)WCPM2].activeState_u8=0X00;//NFC_READER_NOT_ACTIVE_STATE_E
    get_rbd_NFCVehIf_Table_as()[(uint8)WCPM2].connectionStatus_u8=READER_IN_SESSION;
    get_rbd_NFCVehIf_Table_as()[(uint8)WCPM2].Key_Card_Ref_b=TRUE;

    call_rbd_NFCVehIf_SendStartTrigger();
    EXPECT_EQ(rbdSessionMgr_NfcDisconnected_fake.call_count,0x01);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[(uint8)WCPM2].connectionStatus_u8 ,READER_IN_SESSION);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[(uint8)WCPM2].Key_Card_Ref_b,RBDPK_KEYREF_INVALID);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[(uint8)WCPM2].activeState_u8,0x18);//(uint8)NFC_READER_TAP_START_RFHM_TRIGGER_RX_STATE_E
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[(uint8)WCPM2].session_timeout_u16,NFC_SESSION_TIMEOUT);
//    EXPECT_EQ(Dkm_NfcFlow_Start_fake.call_count,0x01);
//    EXPECT_EQ(Dkm_NfcFlow_Start_fake.arg2_val,0);
//    EXPECT_EQ(Dkm_NfcFlow_Start_fake.arg3_val,0);
//    EXPECT_EQ(Dkm_NfcFlow_Start_fake.arg4_val,0);
    EXPECT_EQ(Dkm_GetNumberOfKeyEntries_Operation_fake.call_count,1);
}
/*
@rst
    Brief description of test case.
    :Description: if(readerConnection_state_u8 == READER_DISCONNECTED) ==> TRUE
        if ( READER_IN_SESSION == readerConnection_state_u8 ) ==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 306772
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 ) && ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC(TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 270909
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ResetNFCReaderSessionTag
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 270909
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_RegisterNFCReaderSession
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
        if ( READER_DISCONNECTED == rbd_NFCVehIf_Table_as[NfcReaderId_u8].connectionStatus_u8 ) ==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_UpdateNFCReaderState
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
        if(NULL != newDevRef_pu8) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_SendStartTrigger_03)
{
    get_rbd_NFCVehIf_Table_as()[(uint8)FLDHM].activeState_u8=0X00;//NFC_READER_NOT_ACTIVE_STATE_E
    get_rbd_NFCVehIf_Table_as()[(uint8)FLDHM].connectionStatus_u8=READER_IN_SESSION;
    get_rbd_NFCVehIf_Table_as()[(uint8)FLDHM].Key_Card_Ref_b=TRUE;

    call_rbd_NFCVehIf_SendStartTrigger();
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[(uint8)FLDHM].connectionStatus_u8 ,READER_IN_SESSION);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[(uint8)FLDHM].Key_Card_Ref_b,TRUE);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[(uint8)FLDHM].activeState_u8,0X00);//(uint8)NFC_READER_NOT_ACTIVE_STATE_E
}
//----------------------------------------------------------------------------
// Test Cases// static void rbd_NfcIf_NfcTapThread(void)
//----------------------------------------------------------------------------
/*
@rst
    Brief description of test case.
    :Description: if(((uint8)NFC_READER_TAP_ENTRY_CARD_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (TF)
        else if(((uint8)NFC_READER_TAP_ENTRY_DEVICE_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8))  ==> FALSE MCDC (FX)
        else if(((uint8)NFC_READER_TAP_ENTRY_DEVICE_INFO_WAIT_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
        else if(((uint8)NFC_READER_TAP_ENTRY_TOGGLE_RSP_WAIT_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (TF)
        else if((((uint8)NFC_READER_TAP_ENTRY_CARD_AUTH_FAILED_STATE_E == session_state_u8) || ((uint8)NFC_READER_TAP_ENTRY_DEVICE_AUTH_FAILED_STATE_E == session_state_u8))&& (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FFX)
        if(((uint8)NFC_READER_TAP_START_CARD_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (TF)
        else if(((uint8)NFC_READER_TAP_START_DEVICE_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
        else if(((uint8)NFC_READER_TAP_START_DEVICE_INFO_WAIT_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
        else if((((uint8)NFC_READER_TAP_START_CARD_AUTH_FAILED_STATE_E == session_state_u8) || ((uint8)NFC_READER_TAP_START_DEVICE_AUTH_FAILED_STATE_E == session_state_u8))&& (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FFX)
        else if (((uint8)NFC_READER_PHONE_ENABLE_DISABLE_WCP_AUTH_FINISH_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NfcIf_NfcTapThread_01)
{
    //FLDHM 0
    get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8  = NFC_SERIAL_LEN;//(15)
    get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b  = NFC_SERIAL_LEN;
    get_rbd_NFCVehIf_Table_as()[0].activeState_u8  = 0x02u;//NFC_READER_TAP_ENTRY_CARD_AUTH_SUCCESS_STATE_E
    //WCPM2 2
     get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8  = NFC_SERIAL_LEN;//(15)
    get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b  = NFC_SERIAL_LEN;
    get_rbd_NFCVehIf_Table_as()[2].activeState_u8  = 0x11;//NFC_READER_TAP_START_CARD_AUTH_SUCCESS_STATE_E
    call_rbd_NfcIf_NfcTapThread();
    // FLDHM 0
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8,NFC_SERIAL_LEN);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b ,NFC_SERIAL_LEN);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].activeState_u8 ,0x02u);
    //WCPM2 2
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8,NFC_SERIAL_LEN);//(15)
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b,NFC_SERIAL_LEN);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].activeState_u8 ,0x11);
}
/*
@rst
    Brief description of test case.
    :Description: if(((uint8)NFC_READER_TAP_ENTRY_CARD_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (TF)
        else if(((uint8)NFC_READER_TAP_ENTRY_DEVICE_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8))  ==> FALSE MCDC (TF)
        else if(((uint8)NFC_READER_TAP_ENTRY_DEVICE_INFO_WAIT_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
        else if(((uint8)NFC_READER_TAP_ENTRY_TOGGLE_RSP_WAIT_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
        else if((((uint8)NFC_READER_TAP_ENTRY_CARD_AUTH_FAILED_STATE_E == session_state_u8) || ((uint8)NFC_READER_TAP_ENTRY_DEVICE_AUTH_FAILED_STATE_E == session_state_u8))&& (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FFX)
        if(((uint8)NFC_READER_TAP_START_CARD_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
        else if(((uint8)NFC_READER_TAP_START_DEVICE_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (TF)
        else if(((uint8)NFC_READER_TAP_START_DEVICE_INFO_WAIT_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
        else if((((uint8)NFC_READER_TAP_START_CARD_AUTH_FAILED_STATE_E == session_state_u8) || ((uint8)NFC_READER_TAP_START_DEVICE_AUTH_FAILED_STATE_E == session_state_u8))&& (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FFX)
        else if (((uint8)NFC_READER_PHONE_ENABLE_DISABLE_WCP_AUTH_FINISH_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (TF)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NfcIf_NfcTapThread_02)
{
    //FLDHM 0
    get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8  = NFC_SERIAL_LEN;//(15)
    get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b  = NFC_SERIAL_LEN;
    get_rbd_NFCVehIf_Table_as()[0].activeState_u8  = 0x04u;//NFC_READER_TAP_ENTRY_DEVICE_AUTH_SUCCESS_STATE_E
    //WCPM2 2
    get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8  = NFC_SERIAL_LEN;//(15)
    get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b  = NFC_SERIAL_LEN;
    get_rbd_NFCVehIf_Table_as()[2].activeState_u8  = 0x13u;//NFC_READER_TAP_START_DEVICE_AUTH_SUCCESS_STATE_E
    call_rbd_NfcIf_NfcTapThread();
    // FLDHM 0
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8,NFC_SERIAL_LEN);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b ,NFC_SERIAL_LEN);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].activeState_u8 ,0x04u);
    //WCPM2 2
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8,NFC_SERIAL_LEN);//(15)
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b,NFC_SERIAL_LEN);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].activeState_u8 ,0x13u);
}
/*
@rst
    Brief description of test case.
    :Description: if(((uint8)NFC_READER_TAP_ENTRY_CARD_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (TF)
        else if(((uint8)NFC_READER_TAP_ENTRY_DEVICE_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8))  ==> FALSE MCDC (TF)
        else if(((uint8)NFC_READER_TAP_ENTRY_DEVICE_INFO_WAIT_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
        else if(((uint8)NFC_READER_TAP_ENTRY_TOGGLE_RSP_WAIT_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
        else if((((uint8)NFC_READER_TAP_ENTRY_CARD_AUTH_FAILED_STATE_E == session_state_u8) || ((uint8)NFC_READER_TAP_ENTRY_DEVICE_AUTH_FAILED_STATE_E == session_state_u8))&& (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (TFF)
        if(((uint8)NFC_READER_TAP_START_CARD_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (TF)
        else if(((uint8)NFC_READER_TAP_START_DEVICE_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (TF)
        else if(((uint8)NFC_READER_TAP_START_DEVICE_INFO_WAIT_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
        else if((((uint8)NFC_READER_TAP_START_CARD_AUTH_FAILED_STATE_E == session_state_u8) || ((uint8)NFC_READER_TAP_START_DEVICE_AUTH_FAILED_STATE_E == session_state_u8))&& (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (TFF)
        else if (((uint8)NFC_READER_PHONE_ENABLE_DISABLE_WCP_AUTH_FINISH_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NfcIf_NfcTapThread_03)
{
    //FLDHM 0
    get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8  = NFC_SERIAL_LEN;//(15)
    get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b  = NFC_SERIAL_LEN;
    get_rbd_NFCVehIf_Table_as()[0].activeState_u8  = 0x03u;//NFC_READER_TAP_ENTRY_CARD_AUTH_FAILED_STATE_E
    //WCPM2 2
     get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8  = NFC_SERIAL_LEN;//(15)
    get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b  = NFC_SERIAL_LEN;
    get_rbd_NFCVehIf_Table_as()[2].activeState_u8  = 0x12u;//NFC_READER_TAP_START_CARD_AUTH_FAILED_STATE_E
    call_rbd_NfcIf_NfcTapThread();
    // FLDHM 0
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8,NFC_SERIAL_LEN);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b ,NFC_SERIAL_LEN);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].activeState_u8 ,0x03u);
    //WCPM2 2
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8,NFC_SERIAL_LEN);//(15)
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b,NFC_SERIAL_LEN);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].activeState_u8 ,0x12u);
}
/*
@rst
    Brief description of test case.
    //FLDHM 0
    :Description: if(((uint8)NFC_READER_TAP_ENTRY_CARD_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> TRUE MCDC (TT)
        //WCPM2 2
        if(((uint8)NFC_READER_TAP_START_CARD_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> TRUE MCDC (TT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    //  Calling function rbd_NFCVehIf_ResetNFCReaderSessionTag()
    // :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) )==> TRUE
    // :Arch ID: NA
    // :REQ ID: NA
    // :ALM Task ID: 153320
    // :Testing Method: Positive
    // :Justifications: Coverage / Bug (NA)//Deleted

    Calling function rbd_NFCVehIf_UpdateNFCReaderState()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
        if(NULL != newDevRef_pu8) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NfcIf_NfcTapThread_04)
{
    //FLDHM 0
    get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8  = READER_IN_SESSION;
    get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b  = NFC_SERIAL_LEN;//(15)
    get_rbd_NFCVehIf_Table_as()[0].activeState_u8  = 0x02u;//NFC_READER_TAP_ENTRY_CARD_AUTH_SUCCESS_STATE_E
    //WCPM2 2
    get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8  = READER_IN_SESSION;
    get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b  = NFC_SERIAL_LEN;
    get_rbd_NFCVehIf_Table_as()[2].activeState_u8  = 0X11;//NFC_READER_TAP_START_CARD_AUTH_SUCCESS_STATE_E
    call_rbd_NfcIf_NfcTapThread();
    // FLDHM 0
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8,READER_IN_SESSION);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b ,NFC_SERIAL_LEN);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].activeState_u8 ,0x06u);//NFC_READER_TAP_ENTRY_TOGGLE_RSP_WAIT_STATE_E
    EXPECT_EQ(rbd_RfhmIf_ControlFd1Bus_fake.call_count,1);
    EXPECT_EQ(rbd_RfhmIf_SendNfcToggleReq_fake.call_count,1);
    // EXPECT_EQ(rbd_RfhmIf_SendNfcToggleReq_fake.arg1_val,0x00u);//RBD_DK_ACCESS_PROFILE_FULL_ACCESS
    //WCPM2 2
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8,READER_IN_SESSION);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b,NFC_SERIAL_LEN);
    //EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].activeState_u8 ,0X30);//NFC_READER_TAP_ENTRY_TOGGLE_RSP_WAIT_STATE_E
    EXPECT_EQ(rbd_RfhmIf_SendAuthStatus_fake.call_count,2);
}
/*
@rst
    Brief description of test case.
    :Description: if(((uint8)NFC_READER_TAP_ENTRY_CARD_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (TF)
        else if(((uint8)NFC_READER_TAP_ENTRY_DEVICE_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8))  ==> FALSE MCDC (TF)
        else if(((uint8)NFC_READER_TAP_ENTRY_DEVICE_INFO_WAIT_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
        else if(((uint8)NFC_READER_TAP_ENTRY_TOGGLE_RSP_WAIT_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
        else if((((uint8)NFC_READER_TAP_ENTRY_CARD_AUTH_FAILED_STATE_E == session_state_u8) || ((uint8)NFC_READER_TAP_ENTRY_DEVICE_AUTH_FAILED_STATE_E == session_state_u8))&& (READER_IN_SESSION == readerConnection_state_u8)) ==> TRUE MCDC (FTT)
        if(((uint8)NFC_READER_TAP_START_CARD_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (TF)
        else if(((uint8)NFC_READER_TAP_START_DEVICE_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (TF)
        else if(((uint8)NFC_READER_TAP_START_DEVICE_INFO_WAIT_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
        else if((((uint8)NFC_READER_TAP_START_CARD_AUTH_FAILED_STATE_E == session_state_u8) || ((uint8)NFC_READER_TAP_START_DEVICE_AUTH_FAILED_STATE_E == session_state_u8))&& (READER_IN_SESSION == readerConnection_state_u8)) ==> TRUE MCDC (FTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ResetNFCReaderSessionTag()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) )==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_UpdateNFCReaderState()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
        if(NULL != newDevRef_pu8) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NfcIf_NfcTapThread_05)
{
    //FLDHM 0
    get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8  = READER_IN_SESSION ;
    get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b  = NFC_SERIAL_LEN;//15
    get_rbd_NFCVehIf_Table_as()[0].activeState_u8  = 0x05u;//NFC_READER_TAP_ENTRY_DEVICE_AUTH_FAILED_STATE_E
    //WCPM2 2
    get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8  = READER_IN_SESSION ;
    get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b  = NFC_SERIAL_LEN;//15
    get_rbd_NFCVehIf_Table_as()[2].activeState_u8  = 0x14u;//NFC_READER_TAP_START_DEVICE_AUTH_FAILED_STATE_E
    call_rbd_NfcIf_NfcTapThread();
    // FLDHM 0
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8,READER_DISCONNECTED);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b ,RBDPK_KEYREF_INVALID);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].activeState_u8 ,0x00u);
    //WCPM2
    // EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8,READER_IN_SESSION);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b,0x0F);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].activeState_u8 ,0X16);//NFC_READER_TEAR_DOWN_TRIGGER_STATE_E
    // EXPECT_EQ(rbd_RfhmIf_ControlFd9Bus_fake.call_count,1);
    // EXPECT_EQ(rbd_RfhmIf_SendAuthStatus_fake.call_count,1);
}
/*
@rst
    Brief description of test case.
     //FLDHM 0
    :Description: if(((uint8)NFC_READER_TAP_ENTRY_CARD_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (TF)
        else if(((uint8)NFC_READER_TAP_ENTRY_DEVICE_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8))  ==> TRUE MCDC (TT)
        if(RTE_E_OK == dkmRet_u8 ) ==> TRUE
         //WCPM2 2
        if(((uint8)NFC_READER_TAP_START_CARD_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (TF)
        else if(((uint8)NFC_READER_TAP_START_DEVICE_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> TRUE MCDC (TT)
        if(RTE_E_OK == dkmRet_u8 ) ==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 270909
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

        Calling function rbd_NFCVehIf_ResetNFCReaderSessionTag()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) )==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_UpdateNFCReaderState()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
        if(NULL != newDevRef_pu8) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NfcIf_NfcTapThread_06)
{
    //FLDHM 0
    get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8  = READER_IN_SESSION;
    get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b  = NFC_SERIAL_LEN;//15
    get_rbd_NFCVehIf_Table_as()[0].activeState_u8  = 0x04u;//NFC_READER_TAP_ENTRY_DEVICE_AUTH_SUCCESS_STATE_E
    Dkm_GetKeyInfoDevice_Operation_fake.return_val=RTE_E_OK;
    //WCPM2 2
     get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8  = READER_IN_SESSION;
    get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b  = NFC_SERIAL_LEN;//15
    get_rbd_NFCVehIf_Table_as()[2].activeState_u8  = 0x13u;//NFC_READER_TAP_START_DEVICE_AUTH_SUCCESS_STATE_E
    dummy_devMgr_OpStatus_u16=RBDPK_CCC_DEV_AUTHENTICATION_FAILED;
    Dkm_DeviceMgr_GetStatus_Operation_fake.return_val=255;
    Dkm_DeviceMgr_GetStatus_Operation_fake.custom_fake=Dkm_DeviceMgr_GetStatus_Operation_custom_fake;

    call_rbd_NfcIf_NfcTapThread();
    // FLDHM 0
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8,READER_IN_SESSION);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b ,NFC_SERIAL_LEN);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].activeState_u8 ,0x07u);//(uint8)NFC_READER_TAP_ENTRY_DEVICE_INFO_WAIT_STATE_E
    //WCPM2 2
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8,READER_IN_SESSION);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b,NFC_SERIAL_LEN);//15
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].activeState_u8 ,0X15);//NFC_READER_TAP_START_DEVICE_INFO_WAIT_STATE_E
}
/*
@rst
    Brief description of test case.
     //FLDHM 0
    :Description: if(((uint8)NFC_READER_TAP_ENTRY_CARD_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (TF)
        else if(((uint8)NFC_READER_TAP_ENTRY_DEVICE_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8))  ==> TRUE MCDC (TT)
        if(RTE_E_OK == dkmRet_u8 ) ==> FALSE
         //WCPM2 2
        if(((uint8)NFC_READER_TAP_START_CARD_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (TF)
        else if(((uint8)NFC_READER_TAP_START_DEVICE_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> TRUE MCDC (TT)
        if(RTE_E_OK == dkmRet_u8 ) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 270909
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

     Calling function rbd_NFCVehIf_ResetNFCReaderSessionTag()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) )==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_UpdateNFCReaderState()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
        if(NULL != newDevRef_pu8) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NfcIf_NfcTapThread_07)
{
    //FLDHM 0
    get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8  = READER_IN_SESSION;
    get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b  = NFC_SERIAL_LEN;//15
    get_rbd_NFCVehIf_Table_as()[0].activeState_u8  = 0x04u;//NFC_READER_TAP_ENTRY_DEVICE_AUTH_SUCCESS_STATE_E
    Dkm_GetKeyInfoDevice_Operation_fake.return_val=RTE_E_INVALID;
    //WCPM2 2
     get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8  = READER_IN_SESSION;
    get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b  = NFC_SERIAL_LEN;//15
    get_rbd_NFCVehIf_Table_as()[2].activeState_u8  = 0x13u;//NFC_READER_TAP_START_DEVICE_AUTH_SUCCESS_STATE_E
    dummy_devMgr_OpStatus_u16=RBDPK_CCC_DEV_AUTHENTICATION_FAILED;
    Dkm_DeviceMgr_GetStatus_Operation_fake.return_val=RTE_E_INVALID;
    Dkm_DeviceMgr_GetStatus_Operation_fake.custom_fake=Dkm_DeviceMgr_GetStatus_Operation_custom_fake;
    call_rbd_NfcIf_NfcTapThread();
    // FLDHM 0
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8,READER_IN_SESSION);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b ,NFC_SERIAL_LEN);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].activeState_u8 ,0x04u);
    //WCPM2 2
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8,READER_IN_SESSION);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b,NFC_SERIAL_LEN);//15
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].activeState_u8 ,0X13);
}
/*
@rst
    Brief description of test case.
     //FLDHM 0
    :Description: if(((uint8)NFC_READER_TAP_ENTRY_CARD_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (TF)
        else if(((uint8)NFC_READER_TAP_ENTRY_DEVICE_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8))  ==> TRUE MCDC (TT)
        if((RTE_E_OK == ret) && ((uint16)RBDPK_CCC_DEV_AUTHENTICATED == devMgr_OpStatus_u16)) ==> FALSE MCDC (TF)
        else if((RTE_E_INVALID == ret) || (((uint16)RBDPK_CCC_DEV_AUTHENTICATION_FAILED == devMgr_OpStatus_u16))) ==> FALSE MCDC (FF)
         //WCPM2 2
        if(((uint8)NFC_READER_TAP_START_CARD_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (TF)
        else if(((uint8)NFC_READER_TAP_START_DEVICE_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> TRUE MCDC (TT)
        if((RTE_E_OK == ret) && ((uint16)RBDPK_CCC_DEV_AUTHENTICATED == devMgr_OpStatus_u16)) ==> FALSE MCDC (TF)
        else if((RTE_E_INVALID == ret) || (((uint16)RBDPK_CCC_DEV_AUTHENTICATION_FAILED == devMgr_OpStatus_u16))) ==> FALSE MCDC (FF)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

     Calling function rbd_NFCVehIf_ResetNFCReaderSessionTag()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) )==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_UpdateNFCReaderState()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
        if(NULL != newDevRef_pu8) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NfcIf_NfcTapThread_08)
{
    //FLDHM 0
    get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8  = READER_IN_SESSION;
    get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b  = NFC_SERIAL_LEN;//15
    get_rbd_NFCVehIf_Table_as()[0].activeState_u8  = 0x04u;//NFC_READER_TAP_ENTRY_DEVICE_AUTH_SUCCESS_STATE_E
    //WCPM2 2
     get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8  = READER_IN_SESSION;
    get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b  = NFC_SERIAL_LEN;//15
    get_rbd_NFCVehIf_Table_as()[2].activeState_u8  = 0x13u;//NFC_READER_TAP_START_DEVICE_AUTH_SUCCESS_STATE_E
    dummy_devMgr_OpStatus_u16=NUMBER_OF_AUTH_STATES;
    Dkm_DeviceMgr_GetStatus_Operation_fake.return_val=RTE_E_OK;
    Dkm_DeviceMgr_GetStatus_Operation_fake.custom_fake=Dkm_DeviceMgr_GetStatus_Operation_custom_fake;
    call_rbd_NfcIf_NfcTapThread();
    // FLDHM 0
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8,READER_IN_SESSION);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b ,NFC_SERIAL_LEN);
    // EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].activeState_u8 ,0x04u);
    //WCPM2 2
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8,READER_IN_SESSION);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b,NFC_SERIAL_LEN);//15
    // EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].activeState_u8 ,0x13u);
}
/*
@rst
    Brief description of test case.
     //FLDHM 0
    :Description: if(((uint8)NFC_READER_TAP_ENTRY_CARD_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (TF)
        else if(((uint8)NFC_READER_TAP_ENTRY_DEVICE_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8))  ==> FALSE MCDC (FX)
        else if(((uint8)NFC_READER_TAP_ENTRY_DEVICE_INFO_WAIT_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> TRUE MCDC (TT)
        if(RTE_E_OK == ret) ==> TRUE
        if(TRUE == keyInfo_S.isFriendDev) ==> TRUE
        if(RefreshedDevKeyListCount_u8 > DevKeyListCount_u8) ==> TRUE
         //WCPM2 2
        if(((uint8)NFC_READER_TAP_START_CARD_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (TF)
        else if(((uint8)NFC_READER_TAP_START_DEVICE_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
        else if(((uint8)NFC_READER_TAP_START_DEVICE_INFO_WAIT_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> TRUE MCDC (TT)
        if((RTE_E_OK == ret) ==> TRUE
        if(TRUE == keyInfo_S.isFriendDev) ==> TRUE
        if(RefreshedDevKeyListCount_u8 > DevKeyListCount_u8) ==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 286698
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

     Calling function rbd_NFCVehIf_ResetNFCReaderSessionTag()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) )==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_UpdateNFCReaderState()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
        if(NULL != newDevRef_pu8) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

*/
TEST_F(Testrbd_NFCVehIf, testrbd_NfcIf_NfcTapThread_09)
{
    // rbdCdsTypes_KeyInfo_st keyInfo_S;
    //FLDHM 0
    get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8  = READER_IN_SESSION;
    get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b  = NFC_SERIAL_LEN;//15
    get_rbd_NFCVehIf_Table_as()[0].activeState_u8  = 0x07u;//NFC_READER_TAP_ENTRY_DEVICE_INFO_WAIT_STATE_E
    //WCPM2 2
    get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8  = READER_IN_SESSION;
    get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b  = NFC_SERIAL_LEN;//15
    get_rbd_NFCVehIf_Table_as()[2].activeState_u8  = 0x15u;//NFC_READER_TAP_START_DEVICE_INFO_WAIT_STATE_E
    get_keyInfo_S()->isFriendDev=TRUE;
    dummy_devMgr_OpStatus_u16=RBDPK_CCC_DEV_AUTHENTICATED;
    Dkm_DeviceMgr_GetStatus_Operation_fake.return_val=RTE_E_OK;
    Dkm_DeviceMgr_GetStatus_Operation_fake.custom_fake=Dkm_DeviceMgr_GetStatus_Operation_custom_fake;

    dummy_RefreshedDevKeyListCount_u8 = 255;
    Dkm_GetNumberOfKeyEntries_Operation_fake.custom_fake=Dkm_GetNumberOfKeyEntries_Operation_custom_fake;
    call_rbd_NfcIf_NfcTapThread();
    // FLDHM 0
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8,READER_IN_SESSION);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b ,NFC_SERIAL_LEN);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].activeState_u8 ,0x06u);//(uint8)NFC_READER_TAP_ENTRY_TOGGLE_RSP_WAIT_STATE_E
    //WCPM2 2
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8,READER_IN_SESSION);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b,NFC_SERIAL_LEN);//15
    //EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].activeState_u8 ,0X30);//NFC_READER_TEAR_DOWN_TRIGGER_STATE_E
    EXPECT_EQ(rbd_RfhmIf_SendAuthStatus_fake.call_count,4);
    EXPECT_EQ(rbd_RfhmIf_SendNfcToggleReq_fake.call_count,1);
    EXPECT_EQ(rbd_BackendIf_BackendKeyStatusUpdate_Cbk_fake.call_count,2);
}
/*
@rst
    Brief description of test case.
     //FLDHM 0
    :Description: if(((uint8)NFC_READER_TAP_ENTRY_CARD_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (TF)
        else if(((uint8)NFC_READER_TAP_ENTRY_DEVICE_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8))  ==> FALSE MCDC (FX)
        else if(((uint8)NFC_READER_TAP_ENTRY_DEVICE_INFO_WAIT_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> TRUE MCDC (TT)
        if(RTE_E_OK == ret) ==> TRUE
        if(TRUE == keyInfo_S.isFriendDev) ==> FALSE
         //WCPM2 2
        if(((uint8)NFC_READER_TAP_START_CARD_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (TF)
        else if(((uint8)NFC_READER_TAP_START_DEVICE_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
        else if(((uint8)NFC_READER_TAP_START_DEVICE_INFO_WAIT_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> TRUE MCDC (TT)
        if((RTE_E_OK == ret) ==> TRUE
        if(TRUE == keyInfo_S.isFriendDev) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 92308
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

     Calling function rbd_NFCVehIf_ResetNFCReaderSessionTag()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) )==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_UpdateNFCReaderState()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
        if(NULL != newDevRef_pu8) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ResetNFCReaderSessionTag()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) )==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NfcIf_NfcTapThread_10)
{
    // rbdCdsTypes_KeyInfo_st keyInfo_S;
    //FLDHM 0
    get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8  = READER_IN_SESSION;
    get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b  = NFC_SERIAL_LEN;//15
    get_rbd_NFCVehIf_Table_as()[0].activeState_u8  = 0x07u;//NFC_READER_TAP_ENTRY_DEVICE_INFO_WAIT_STATE_E
    //WCPM2 2
     get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8  = READER_IN_SESSION;
    get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b  = NFC_SERIAL_LEN;//15
    get_rbd_NFCVehIf_Table_as()[2].activeState_u8  = 0x15u;//NFC_READER_TAP_START_DEVICE_INFO_WAIT_STATE_E
    get_keyInfo_S()->isFriendDev=FALSE;
    dummy_devMgr_OpStatus_u16=RBDPK_CCC_DEV_AUTHENTICATED;
    Dkm_DeviceMgr_GetStatus_Operation_fake.return_val=RTE_E_OK;
    Dkm_DeviceMgr_GetStatus_Operation_fake.custom_fake=Dkm_DeviceMgr_GetStatus_Operation_custom_fake;
    call_rbd_NfcIf_NfcTapThread();
    // FLDHM 0
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8,READER_IN_SESSION);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b ,NFC_SERIAL_LEN);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].activeState_u8 ,0x06u);
    //WCPM2 2
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8,READER_IN_SESSION);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b,NFC_SERIAL_LEN);//15
    //EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].activeState_u8 ,0X30);//NFC_READER_TEAR_DOWN_TRIGGER_STATE_E
    EXPECT_EQ(rbd_RfhmIf_SendAuthStatus_fake.call_count,5);
    EXPECT_EQ(rbd_RfhmIf_SendNfcToggleReq_fake.call_count,1);
}
/*
@rst
    Brief description of test case.
    :Description: if(((uint8)NFC_READER_TAP_ENTRY_CARD_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
        else if(((uint8)NFC_READER_TAP_ENTRY_DEVICE_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8))  ==> FALSE MCDC (FX)
        else if(((uint8)NFC_READER_TAP_ENTRY_DEVICE_INFO_WAIT_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
        else if(((uint8)NFC_READER_TAP_ENTRY_TOGGLE_RSP_WAIT_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
        else if((((uint8)NFC_READER_TAP_ENTRY_CARD_AUTH_FAILED_STATE_E == session_state_u8) || ((uint8)NFC_READER_TAP_ENTRY_DEVICE_AUTH_FAILED_STATE_E == session_state_u8))&& (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FXF)
        if(((uint8)NFC_READER_TAP_START_CARD_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (TF)
        else if(((uint8)NFC_READER_TAP_START_DEVICE_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (TF)
        else if(((uint8)NFC_READER_TAP_START_DEVICE_INFO_WAIT_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
        else if((((uint8)NFC_READER_TAP_START_CARD_AUTH_FAILED_STATE_E == session_state_u8) || ((uint8)NFC_READER_TAP_START_DEVICE_AUTH_FAILED_STATE_E == session_state_u8))&& (READER_IN_SESSION == readerConnection_state_u8)) ==> TRUE MCDC (FTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ResetNFCReaderSessionTag()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) )==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_UpdateNFCReaderState()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
        if(NULL != newDevRef_pu8) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NfcIf_NfcTapThread_11)
{
    //FLDHM 0
    get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8  = 0 ;
    get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b  = NFC_SERIAL_LEN;//15
    get_rbd_NFCVehIf_Table_as()[0].activeState_u8  = 0X48;//NFC_READER_TAP_ENTRY_DEVICE_AUTH_FAILED_STATE_E
    //WCPM2 2
    get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8  = READER_IN_SESSION ;
    get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b  = NFC_SERIAL_LEN;//15
    get_rbd_NFCVehIf_Table_as()[2].activeState_u8  = 0x14u;//NFC_READER_TAP_START_DEVICE_AUTH_FAILED_STATE_E
    call_rbd_NfcIf_NfcTapThread();
    // FLDHM 0
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8,0);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b ,NFC_SERIAL_LEN);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].activeState_u8 ,0X48);
    //WCPM2
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8,READER_IN_SESSION);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b,NFC_SERIAL_LEN);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].activeState_u8 ,0x16);//NFC_READER_TEAR_DOWN_TRIGGER_STATE_E
    // EXPECT_EQ(rbd_RfhmIf_ControlFd9Bus_fake.call_count,3);
    // EXPECT_EQ(rbd_RfhmIf_SendAuthStatus_fake.call_count,3);
}
/*
@rst
    Brief description of test case.
    :Description: if(((uint8)NFC_READER_TAP_ENTRY_CARD_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
        else if(((uint8)NFC_READER_TAP_ENTRY_DEVICE_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8))  ==> FALSE MCDC (FX)
        else if(((uint8)NFC_READER_TAP_ENTRY_DEVICE_INFO_WAIT_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
        else if(((uint8)NFC_READER_TAP_ENTRY_TOGGLE_RSP_WAIT_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
        else if((((uint8)NFC_READER_TAP_ENTRY_CARD_AUTH_FAILED_STATE_E == session_state_u8) || ((uint8)NFC_READER_TAP_ENTRY_DEVICE_AUTH_FAILED_STATE_E == session_state_u8))&& (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FXF)
        if(((uint8)NFC_READER_TAP_START_CARD_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (TF)
        else if(((uint8)NFC_READER_TAP_START_DEVICE_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (TF)
        else if(((uint8)NFC_READER_TAP_START_DEVICE_INFO_WAIT_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
        else if((((uint8)NFC_READER_TAP_START_CARD_AUTH_FAILED_STATE_E == session_state_u8) || ((uint8)NFC_READER_TAP_START_DEVICE_AUTH_FAILED_STATE_E == session_state_u8))&& (READER_IN_SESSION == readerConnection_state_u8)) ==> TRUE MCDC (TXF)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ResetNFCReaderSessionTag()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) )==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_UpdateNFCReaderState()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
        if(NULL != newDevRef_pu8) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NfcIf_NfcTapThread_12)
{
    //FLDHM 0
    get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8  = 0 ;
    get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b  = NFC_SERIAL_LEN;//15
    get_rbd_NFCVehIf_Table_as()[0].activeState_u8  = 0X48;//NFC_READER_TAP_ENTRY_DEVICE_AUTH_FAILED_STATE_E
    //WCPM2 2
    get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8  = 0 ;
    get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b  = NFC_SERIAL_LEN;//15
    get_rbd_NFCVehIf_Table_as()[2].activeState_u8  = 0x12u;//NFC_READER_TAP_START_CARD_AUTH_FAILED_STATE_E
    call_rbd_NfcIf_NfcTapThread();
    // FLDHM 0
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8,0);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b ,NFC_SERIAL_LEN);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].activeState_u8 ,0X48);
    //WCPM2
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8,0);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b,NFC_SERIAL_LEN);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].activeState_u8 ,0x12u);
    // EXPECT_EQ(rbd_RfhmIf_SendAuthStatus_fake.call_count,2);
}
/*
@rst
    Brief description of test case.
    :Description: if(((uint8)NFC_READER_TAP_ENTRY_CARD_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
        else if(((uint8)NFC_READER_TAP_ENTRY_DEVICE_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8))  ==> FALSE MCDC (FX)
        else if(((uint8)NFC_READER_TAP_ENTRY_DEVICE_INFO_WAIT_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
        else if(((uint8)NFC_READER_TAP_ENTRY_TOGGLE_RSP_WAIT_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> TRUE MCDC (TT)
        if(((uint8)NFC_READER_TAP_START_CARD_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
        else if(((uint8)NFC_READER_TAP_START_DEVICE_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
        else if(((uint8)NFC_READER_TAP_START_DEVICE_INFO_WAIT_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
        else if((((uint8)NFC_READER_TAP_START_CARD_AUTH_FAILED_STATE_E == session_state_u8) || ((uint8)NFC_READER_TAP_START_DEVICE_AUTH_FAILED_STATE_E == session_state_u8))&& (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FXF)
        else if (((uint8)NFC_READER_PHONE_ENABLE_DISABLE_WCP_AUTH_FINISH_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ResetNFCReaderSessionTag()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) )==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_UpdateNFCReaderState()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
        if(NULL != newDevRef_pu8) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NfcIf_NfcTapThread_13)
{
    //FLDHM 0
    get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8  = READER_IN_SESSION  ;
    get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b  = NFC_SERIAL_LEN;//15
    get_rbd_NFCVehIf_Table_as()[0].activeState_u8  = 0X6;//NFC_READER_TAP_ENTRY_DEVICE_AUTH_FAILED_STATE_E
    //WCPM2 2
    get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8  = 0 ;
    get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b  = NFC_SERIAL_LEN;//15
    get_rbd_NFCVehIf_Table_as()[2].activeState_u8  = 0X48;
    call_rbd_NfcIf_NfcTapThread();
    // FLDHM 0
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8,READER_IN_SESSION);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b ,NFC_SERIAL_LEN);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].activeState_u8 ,0X6);
    //WCPM2
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8,0);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b,NFC_SERIAL_LEN);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].activeState_u8 ,0X48);
    // EXPECT_EQ(rbd_RfhmIf_SendAuthStatus_fake.call_count,2);
}
/*
@rst
    Brief description of test case.
    :Description: if(((uint8)NFC_READER_TAP_ENTRY_CARD_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
        else if(((uint8)NFC_READER_TAP_ENTRY_DEVICE_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8))  ==> FALSE MCDC (FX)
        lse if(((uint8)NFC_READER_TAP_ENTRY_DEVICE_INFO_WAIT_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
        else if(((uint8)NFC_READER_TAP_ENTRY_TOGGLE_RSP_WAIT_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (TF)
        if(((uint8)NFC_READER_TAP_START_CARD_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
        else if(((uint8)NFC_READER_TAP_START_DEVICE_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
        else if(((uint8)NFC_READER_TAP_START_DEVICE_INFO_WAIT_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
        else if((((uint8)NFC_READER_TAP_START_CARD_AUTH_FAILED_STATE_E == session_state_u8) || ((uint8)NFC_READER_TAP_START_DEVICE_AUTH_FAILED_STATE_E == session_state_u8))&& (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FXF)
        else if (((uint8)NFC_READER_PHONE_ENABLE_DISABLE_WCP_AUTH_FINISH_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ResetNFCReaderSessionTag()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) )==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_UpdateNFCReaderState()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
        if(NULL != newDevRef_pu8) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NfcIf_NfcTapThread_14)
{
    //FLDHM 0
    get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8  = 0  ;
    get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b  = NFC_SERIAL_LEN;//15
    get_rbd_NFCVehIf_Table_as()[0].activeState_u8  = 0X6;//NFC_READER_TAP_ENTRY_DEVICE_AUTH_FAILED_STATE_E
    //WCPM2 2
    get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8  = 0 ;
    get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b  = NFC_SERIAL_LEN;//15
    get_rbd_NFCVehIf_Table_as()[2].activeState_u8  = 0X48;
    call_rbd_NfcIf_NfcTapThread();
    // FLDHM 0
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8,0);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b ,NFC_SERIAL_LEN);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].activeState_u8 ,0X6);
    //WCPM2
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8,0);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b,NFC_SERIAL_LEN);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].activeState_u8 ,0X48);
    // EXPECT_EQ(rbd_RfhmIf_SendAuthStatus_fake.call_count,2);
}
/*
@rst
    Brief description of test case.
     //FLDHM 0
    :Description: if(((uint8)NFC_READER_TAP_ENTRY_CARD_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (TF)
        else if(((uint8)NFC_READER_TAP_ENTRY_DEVICE_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8))  ==> FALSE MCDC (FX)
        else if(((uint8)NFC_READER_TAP_ENTRY_DEVICE_INFO_WAIT_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> TRUE MCDC (TT)
        if(RTE_E_OK == ret) ==> FALSE
        else if(RTE_E_INVALID == ret) ==> FALSE
         //WCPM2 2
        if(((uint8)NFC_READER_TAP_START_CARD_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (TF)
        else if(((uint8)NFC_READER_TAP_START_DEVICE_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
        else if(((uint8)NFC_READER_TAP_START_DEVICE_INFO_WAIT_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> TRUE MCDC (TT)
        if((RTE_E_OK == ret) ==> FALSE
        else if(RTE_E_INVALID == ret) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 270909
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

     Calling function rbd_NFCVehIf_ResetNFCReaderSessionTag()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) )==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_UpdateNFCReaderState()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
        if(NULL != newDevRef_pu8) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ResetNFCReaderSessionTag()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) )==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NfcIf_NfcTapThread_15)
{
    // rbdCdsTypes_KeyInfo_st keyInfo_S;
    //FLDHM 0
    get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8  = READER_IN_SESSION;
    get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b  = NFC_SERIAL_LEN;//15
    get_rbd_NFCVehIf_Table_as()[0].activeState_u8  = 0x07u;//NFC_READER_TAP_ENTRY_DEVICE_INFO_WAIT_STATE_E
    //WCPM2 2
     get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8  = READER_IN_SESSION;
    get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b  = NFC_SERIAL_LEN;//15
    get_rbd_NFCVehIf_Table_as()[2].activeState_u8  = 0x15u;//NFC_READER_TAP_START_DEVICE_INFO_WAIT_STATE_E
    get_keyInfo_S()->isFriendDev=FALSE;
    dummy_devMgr_OpStatus_u16=RBDPK_CCC_DEV_AUTHENTICATED;
    Dkm_DeviceMgr_GetStatus_Operation_fake.return_val=255;
    Dkm_DeviceMgr_GetStatus_Operation_fake.custom_fake=Dkm_DeviceMgr_GetStatus_Operation_custom_fake;
    call_rbd_NfcIf_NfcTapThread();
    // FLDHM 0
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8,READER_IN_SESSION);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b ,NFC_SERIAL_LEN);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].activeState_u8 ,0x07u);
    //WCPM2 2
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8,READER_IN_SESSION);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b,NFC_SERIAL_LEN);//15
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].activeState_u8 ,0x15u);
    EXPECT_EQ(rbd_RfhmIf_SendAuthStatus_fake.call_count,6);
}
/*
@rst
    Brief description of test case.
     //FLDHM 0
    :Description: if(((uint8)NFC_READER_TAP_ENTRY_CARD_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (TF)
        else if(((uint8)NFC_READER_TAP_ENTRY_DEVICE_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8))  ==> FALSE MCDC (FX)
        else if(((uint8)NFC_READER_TAP_ENTRY_DEVICE_INFO_WAIT_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> TRUE MCDC (TT)
        if(RTE_E_OK == ret) ==> FALSE
        else if(RTE_E_INVALID == ret) ==> TRUE
         //WCPM2 2
        if(((uint8)NFC_READER_TAP_START_CARD_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (TF)
        else if(((uint8)NFC_READER_TAP_START_DEVICE_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
        else if(((uint8)NFC_READER_TAP_START_DEVICE_INFO_WAIT_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> TRUE MCDC (TT)
        if((RTE_E_OK == ret) ==> FALSE
        else if(RTE_E_INVALID == ret) ==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 270909
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

     Calling function rbd_NFCVehIf_ResetNFCReaderSessionTag()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) )==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_UpdateNFCReaderState()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
        if(NULL != newDevRef_pu8) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ResetNFCReaderSessionTag()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) )==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NfcIf_NfcTapThread_16)
{
    // rbdCdsTypes_KeyInfo_st keyInfo_S;
    //FLDHM 0
    get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8  = READER_IN_SESSION;
    get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b  = NFC_SERIAL_LEN;//15
    get_rbd_NFCVehIf_Table_as()[0].activeState_u8  = 0x07u;//NFC_READER_TAP_ENTRY_DEVICE_INFO_WAIT_STATE_E
    //WCPM2 2
     get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8  = READER_IN_SESSION;
    get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b  = NFC_SERIAL_LEN;//15
    get_rbd_NFCVehIf_Table_as()[2].activeState_u8  = 0x15u;//NFC_READER_TAP_START_DEVICE_INFO_WAIT_STATE_E
    get_keyInfo_S()->isFriendDev=FALSE;
    dummy_devMgr_OpStatus_u16=RBDPK_CCC_DEV_AUTHENTICATED;
    Dkm_DeviceMgr_GetStatus_Operation_fake.return_val=RTE_E_INVALID;
    Dkm_DeviceMgr_GetStatus_Operation_fake.custom_fake=Dkm_DeviceMgr_GetStatus_Operation_custom_fake;
    call_rbd_NfcIf_NfcTapThread();
    // FLDHM 0
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8,READER_DISCONNECTED);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b ,RBDPK_KEYREF_INVALID);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].activeState_u8 ,0x00u);//NFC_READER_NOT_ACTIVE_STATE_E
    //EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].session_timeout_u16 ,6000u);//NFC_SESSION_TIMEOUT
    //WCPM2 2
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8,READER_IN_SESSION);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b,NFC_SERIAL_LEN);//15
    //EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].activeState_u8 ,0X30);//NFC_READER_TEAR_DOWN_TRIGGER_STATE_E
    EXPECT_EQ(rbd_RfhmIf_SendAuthStatus_fake.call_count,7);
}
/*
@rst
    Brief description of test case.
     //FLDHM 0
    :Description: if(((uint8)NFC_READER_TAP_ENTRY_CARD_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
        else if(((uint8)NFC_READER_TAP_ENTRY_DEVICE_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8))  ==> FALSE MCDC (FX)
        else if(((uint8)NFC_READER_TAP_ENTRY_DEVICE_INFO_WAIT_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (TF)
        else if(((uint8)NFC_READER_TAP_ENTRY_TOGGLE_RSP_WAIT_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (TF)
        else if((((uint8)NFC_READER_TAP_ENTRY_CARD_AUTH_FAILED_STATE_E == session_state_u8) || ((uint8)NFC_READER_TAP_ENTRY_DEVICE_AUTH_FAILED_STATE_E == session_state_u8))&& (READER_IN_SESSION == readerConnection_state_u8))==> FALSE MCDC (FFX)
         //WCPM2 2
        if(((uint8)NFC_READER_TAP_START_CARD_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
        else if(((uint8)NFC_READER_TAP_START_DEVICE_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
        else if(((uint8)NFC_READER_TAP_START_DEVICE_INFO_WAIT_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (TF)
        else if((((uint8)NFC_READER_TAP_START_CARD_AUTH_FAILED_STATE_E == session_state_u8) || ((uint8)NFC_READER_TAP_START_DEVICE_AUTH_FAILED_STATE_E == session_state_u8))&& (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FFX)
        else if (((uint8)NFC_READER_PHONE_ENABLE_DISABLE_WCP_AUTH_FINISH_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 270909
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

     Calling function rbd_NFCVehIf_ResetNFCReaderSessionTag()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) )==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_UpdateNFCReaderState()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
        if(NULL != newDevRef_pu8) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ResetNFCReaderSessionTag()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) )==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NfcIf_NfcTapThread_17)
{
    // rbdCdsTypes_KeyInfo_st keyInfo_S;
    //FLDHM 0
    get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8  = READER_DISCONNECTED;
    get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b  = NFC_SERIAL_LEN;//15
    get_rbd_NFCVehIf_Table_as()[0].activeState_u8  = 0x07u;//NFC_READER_TAP_ENTRY_DEVICE_INFO_WAIT_STATE_E
    //WCPM2 2
     get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8  = READER_DISCONNECTED;
    get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b  = NFC_SERIAL_LEN;//15
    get_rbd_NFCVehIf_Table_as()[2].activeState_u8  = 0x15u;//NFC_READER_TAP_START_DEVICE_INFO_WAIT_STATE_E
    get_keyInfo_S()->isFriendDev=FALSE;
    dummy_devMgr_OpStatus_u16=RBDPK_CCC_DEV_AUTHENTICATED;
    Dkm_DeviceMgr_GetStatus_Operation_fake.return_val=RTE_E_INVALID;
    Dkm_DeviceMgr_GetStatus_Operation_fake.custom_fake=Dkm_DeviceMgr_GetStatus_Operation_custom_fake;
    call_rbd_NfcIf_NfcTapThread();
    // FLDHM 0
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8,READER_DISCONNECTED);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b ,15);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].activeState_u8 ,0x07u);
    //WCPM2 2
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8,READER_DISCONNECTED);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b,NFC_SERIAL_LEN);//15
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].activeState_u8 ,0X15);
}
/*
@rst
    Brief description of test case.
    :Description: if(((uint8)NFC_READER_TAP_ENTRY_CARD_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (TF)
        else if(((uint8)NFC_READER_TAP_ENTRY_DEVICE_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8))  ==> FALSE MCDC (TF)
        else if(((uint8)NFC_READER_TAP_ENTRY_DEVICE_INFO_WAIT_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
        else if(((uint8)NFC_READER_TAP_ENTRY_TOGGLE_RSP_WAIT_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
        else if((((uint8)NFC_READER_TAP_ENTRY_CARD_AUTH_FAILED_STATE_E == session_state_u8) || ((uint8)NFC_READER_TAP_ENTRY_DEVICE_AUTH_FAILED_STATE_E == session_state_u8))&& (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FFX)
        if(((uint8)NFC_READER_TAP_START_CARD_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
        else if(((uint8)NFC_READER_TAP_START_DEVICE_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
        else if(((uint8)NFC_READER_TAP_START_DEVICE_INFO_WAIT_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
        else if((((uint8)NFC_READER_TAP_START_CARD_AUTH_FAILED_STATE_E == session_state_u8) || ((uint8)NFC_READER_TAP_START_DEVICE_AUTH_FAILED_STATE_E == session_state_u8))&& (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FFX)
        else if (((uint8)NFC_READER_PHONE_ENABLE_DISABLE_WCP_AUTH_FINISH_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (TF)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NfcIf_NfcTapThread_18)
{
    //FLDHM 0
    get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8  = NFC_SERIAL_LEN;//(15)
    get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b  = NFC_SERIAL_LEN;
    get_rbd_NFCVehIf_Table_as()[0].activeState_u8  = 0x04u;//NFC_READER_TAP_ENTRY_DEVICE_AUTH_SUCCESS_STATE_E
    //WCPM2 2
    get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8  = NFC_SERIAL_LEN;//(15)
    get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b  = NFC_SERIAL_LEN;
    get_rbd_NFCVehIf_Table_as()[2].activeState_u8  = 0x61;//NFC_READER_PHONE_ENABLE_DISABLE_WCP_AUTH_FINISH_STATE_E
    call_rbd_NfcIf_NfcTapThread();
    // FLDHM 0
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8,NFC_SERIAL_LEN);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b ,NFC_SERIAL_LEN);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].activeState_u8 ,0x04u);
    //WCPM2 2
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8,NFC_SERIAL_LEN);//(15)
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b,NFC_SERIAL_LEN);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].activeState_u8 ,0x61);
}
/*
@rst
    Brief description of test case.
    :Description: if(((uint8)NFC_READER_TAP_ENTRY_CARD_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (TF)
        else if(((uint8)NFC_READER_TAP_ENTRY_DEVICE_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8))  ==> FALSE MCDC (TF)
        else if(((uint8)NFC_READER_TAP_ENTRY_DEVICE_INFO_WAIT_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
        else if(((uint8)NFC_READER_TAP_ENTRY_TOGGLE_RSP_WAIT_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
        else if((((uint8)NFC_READER_TAP_ENTRY_CARD_AUTH_FAILED_STATE_E == session_state_u8) || ((uint8)NFC_READER_TAP_ENTRY_DEVICE_AUTH_FAILED_STATE_E == session_state_u8))&& (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FFX)
        if(((uint8)NFC_READER_TAP_START_CARD_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
        else if(((uint8)NFC_READER_TAP_START_DEVICE_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
        else if(((uint8)NFC_READER_TAP_START_DEVICE_INFO_WAIT_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
        else if((((uint8)NFC_READER_TAP_START_CARD_AUTH_FAILED_STATE_E == session_state_u8) || ((uint8)NFC_READER_TAP_START_DEVICE_AUTH_FAILED_STATE_E == session_state_u8))&& (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FFX)
        else if (((uint8)NFC_READER_PHONE_ENABLE_DISABLE_WCP_AUTH_FINISH_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> TRUE MCDC (TT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NfcIf_NfcTapThread_19)
{
    //FLDHM 0
    get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8  = NFC_SERIAL_LEN;//(15)
    get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b  = NFC_SERIAL_LEN;
    get_rbd_NFCVehIf_Table_as()[0].activeState_u8  = 0x04u;//NFC_READER_TAP_ENTRY_DEVICE_AUTH_SUCCESS_STATE_E
    //WCPM2 2
    get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8  = READER_IN_SESSION;//(15)
    get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b  = NFC_SERIAL_LEN;
    get_rbd_NFCVehIf_Table_as()[2].activeState_u8  = 0x61;//NFC_READER_PHONE_ENABLE_DISABLE_WCP_AUTH_FINISH_STATE_E
    call_rbd_NfcIf_NfcTapThread();
    // FLDHM 0
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8,NFC_SERIAL_LEN);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b ,NFC_SERIAL_LEN);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].activeState_u8 ,0x04u);
    //WCPM2 2
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8,READER_DISCONNECTED);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b,RBDPK_KEYREF_INVALID);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].activeState_u8,0x0);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].session_timeout_u16,NFC_SESSION_TIMEOUT);
}
/*
@rst
    Brief description of test case.
     //FLDHM 0
    :Description: if(((uint8)NFC_READER_TAP_ENTRY_CARD_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (TF)
        else if(((uint8)NFC_READER_TAP_ENTRY_DEVICE_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8))  ==> FALSE MCDC (FX)
        else if(((uint8)NFC_READER_TAP_ENTRY_DEVICE_INFO_WAIT_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> TRUE MCDC (TT)
        if(RTE_E_OK == ret) ==> TRUE
        if(TRUE == keyInfo_S.isFriendDev) ==> TRUE
        if(RefreshedDevKeyListCount_u8 > DevKeyListCount_u8) ==> TRUE
         //WCPM2 2
        if(((uint8)NFC_READER_TAP_START_CARD_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (TF)
        else if(((uint8)NFC_READER_TAP_START_DEVICE_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> FALSE MCDC (FX)
        else if(((uint8)NFC_READER_TAP_START_DEVICE_INFO_WAIT_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8)) ==> TRUE MCDC (TT)
        if((RTE_E_OK == ret) ==> TRUE
        if(TRUE == keyInfo_S.isFriendDev) ==> TRUE
        if(RefreshedDevKeyListCount_u8 > DevKeyListCount_u8) ==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 286698
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

     Calling function rbd_NFCVehIf_ResetNFCReaderSessionTag()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) )==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_UpdateNFCReaderState()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
        if(NULL != newDevRef_pu8) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

*/
TEST_F(Testrbd_NFCVehIf, testrbd_NfcIf_NfcTapThread_20)
{
    // rbdCdsTypes_KeyInfo_st keyInfo_S;
    //FLDHM 0
    get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8  = READER_IN_SESSION;
    get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b  = NFC_SERIAL_LEN;//15
    get_rbd_NFCVehIf_Table_as()[0].activeState_u8  = 0x07u;//NFC_READER_TAP_ENTRY_DEVICE_INFO_WAIT_STATE_E
    //WCPM2 2
    get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8  = READER_IN_SESSION;
    get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b  = NFC_SERIAL_LEN;//15
    get_rbd_NFCVehIf_Table_as()[2].activeState_u8  = 0x15u;//NFC_READER_TAP_START_DEVICE_INFO_WAIT_STATE_E
    get_keyInfo_S()->isFriendDev=TRUE;
    dummy_devMgr_OpStatus_u16=RBDPK_CCC_DEV_AUTHENTICATED;
    Dkm_DeviceMgr_GetStatus_Operation_fake.return_val=RTE_E_OK;
    Dkm_DeviceMgr_GetStatus_Operation_fake.custom_fake=Dkm_DeviceMgr_GetStatus_Operation_custom_fake;

    dummy_RefreshedDevKeyListCount_u8 = 0;
    Dkm_GetNumberOfKeyEntries_Operation_fake.custom_fake=Dkm_GetNumberOfKeyEntries_Operation_custom_fake;
    call_rbd_NfcIf_NfcTapThread();
    // FLDHM 0
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8,READER_IN_SESSION);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].Key_Card_Ref_b ,NFC_SERIAL_LEN);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].activeState_u8 ,0x06u);//(uint8)NFC_READER_TAP_ENTRY_TOGGLE_RSP_WAIT_STATE_E
    //WCPM2 2
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8,READER_IN_SESSION);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b,NFC_SERIAL_LEN);//15
    //EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].activeState_u8 ,0X30);//NFC_READER_TEAR_DOWN_TRIGGER_STATE_E
    EXPECT_EQ(rbd_RfhmIf_SendNfcToggleReq_fake.call_count,1);
}
//----------------------------------------------------------------------------
// Test Cases// static uint8 rbd_NFCVehIf_ResetNFCReaderSessionTag( const uint8 NfcReaderId_u8 )
//----------------------------------------------------------------------------
/*
@rst
    Brief description of test case.
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_ResetNFCReaderSessionTag_01)
{
    uint8 ret_val = call_rbd_NFCVehIf_ResetNFCReaderSessionTag(5);
    EXPECT_EQ(ret_val, FALSE);
}

//----------------------------------------------------------------------------
// Test Cases// static uint8 rbd_NFCVehIf_RegisterNFCReaderSession( const uint8 NfcReaderId_u8 )
//----------------------------------------------------------------------------
/*
@rst
    Brief description of test case.
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_RegisterNFCReaderSession_01)
{
    uint8 ret_val = call_rbd_NFCVehIf_RegisterNFCReaderSession(5);
    EXPECT_EQ(ret_val, FALSE);
}
//----------------------------------------------------------------------------
// Test Cases// static uint8 rbd_NFCVehIf_UpdateNFCReaderState( const uint8 NfcReaderId_u8, const uint8 newState_u8, const uint8 * newDevRef_pu8)
//----------------------------------------------------------------------------
/*
@rst
    Brief description of test case.
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_UpdateNFCReaderState_01)
{
    uint8 ret_val = call_rbd_NFCVehIf_UpdateNFCReaderState(5,6,NULL);
    EXPECT_EQ(ret_val, FALSE);
}
//----------------------------------------------------------------------------
// Test Cases// static void rbd_NFCVehIf_ReadNFCReaderStatusInfo( const uint8 NfcReaderId_u8,uint8 *sessionState_u8, uint8 *readerConnectState_u8, uint8 *deviceRef_u8 )
//----------------------------------------------------------------------------
/*
@rst
    Brief description of test case.
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> FALSE MCDC (TTF)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_ReadNFCReaderStatusInfo_01)
{
    uint8 sessionState_u8=10;
    uint8 deviceRef_u8=1;
   call_rbd_NFCVehIf_ReadNFCReaderStatusInfo(1,&sessionState_u8,NULL,&deviceRef_u8);
}
/*
@rst
    Brief description of test case.
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> FALSE MCDC (TFX)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_ReadNFCReaderStatusInfo_02)
{
    uint8 deviceRef_u8=10;
   call_rbd_NFCVehIf_ReadNFCReaderStatusInfo(1,NULL,NULL,&deviceRef_u8);
}
/*
@rst
    Brief description of test case.
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> FALSE MCDC (FXX)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_ReadNFCReaderStatusInfo_03)
{
    uint8 deviceRef_u8=10;
   call_rbd_NFCVehIf_ReadNFCReaderStatusInfo(5,NULL,NULL,&deviceRef_u8);
}

//----------------------------------------------------------------------------
// Test Cases//  FUNC(Std_ReturnType, rbd_NFCVehIf_CODE) rbd_NFCVehIf_GetNfcUID_Start_RequestResults(P2VAR(uint8, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR) ErrorCode)
//----------------------------------------------------------------------------
/*
@rst
    Brief description of test case.
    :Description: if ((rbd_NFCVehIf_CardData_st.routineStatus_u8 == (uint8)IN_PROGRESS) &&(rbd_NFCVehIf_getUID_active_b == TRUE)) ==> TRUE MCDC (TT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 270909
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_GetNfcUID_Start_RequestResults_01)
{
    uint8 Out_ResData[255];
    Dcm_NegativeResponseCodeType ErrorCode = DCM_E_GENERALREJECT;
    // get_rbd_NFCVehIf_CardData_st()->routineStatus_u8=(uint8)IN_PROGRESS;Code removed
    // *get_rbd_NFCVehIf_getUID_active_b () = TRUE;Code removed
    Std_ReturnType ret_val = call_rbd_NFCVehIf_GetNfcUID_Start_RequestResults(Out_ResData, &ErrorCode);
    // EXPECT_EQ(ret_val,RTE_E_NFC_Card_Serial_Number_Read_DCM_E_PENDING);
    // EXPECT_EQ(ErrorCode,DCM_E_GENERALREJECT);
}
/*
@rst
    Brief description of test case.
    :Description: if ((rbd_NFCVehIf_CardData_st.routineStatus_u8 == (uint8)IN_PROGRESS) &&(rbd_NFCVehIf_getUID_active_b == TRUE)) ==> FALSE MCDC (TF)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 270909
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ResetNFCReaderSessionTag()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_GetNfcUID_Start_RequestResults_02)
{
    uint8 Out_ResData[10];
    Dcm_NegativeResponseCodeType ErrorCode = DCM_E_GENERALREJECT;
    // get_rbd_NFCVehIf_CardData_st()->routineStatus_u8=(uint8)IN_PROGRESS;
    // get_rbd_NFCVehIf_CardData_st()->errorCode_u8=0;Code removed
    // *get_rbd_NFCVehIf_getUID_active_b () = FALSE;Code removed
    Std_ReturnType ret_val = call_rbd_NFCVehIf_GetNfcUID_Start_RequestResults(Out_ResData, &ErrorCode);
    EXPECT_EQ(ret_val,RTE_E_OK);
    EXPECT_EQ(ErrorCode,DCM_E_POSITIVERESPONSE);
    // EXPECT_EQ(Out_ResData[0], get_rbd_NFCVehIf_CardData_st()->routineStatus_u8);
    // EXPECT_EQ(Out_ResData[1], get_rbd_NFCVehIf_CardData_st()->errorCode_u8);
    // EXPECT_EQ(Out_ResData[2], get_rbd_NFCVehIf_CardData_st()->cardUID_au8[0]);
    // EXPECT_EQ(Out_ResData[3], get_rbd_NFCVehIf_CardData_st()->cardUID_au8[1]);
    // EXPECT_EQ(Out_ResData[4], get_rbd_NFCVehIf_CardData_st()->cardUID_au8[2]);
    // EXPECT_EQ(Out_ResData[5], get_rbd_NFCVehIf_CardData_st()->cardUID_au8[3]);
    // EXPECT_EQ(Out_ResData[6], get_rbd_NFCVehIf_CardData_st()->cardUID_au8[4]);
    // EXPECT_EQ(Out_ResData[7], get_rbd_NFCVehIf_CardData_st()->cardUID_au8[5]);
    // EXPECT_EQ(Out_ResData[8], get_rbd_NFCVehIf_CardData_st()->cardUID_au8[6]);Code removed
    // EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[(uint8)WCPM2].connectionStatus_u8,READER_DISCONNECTED);
    // EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[(uint8)WCPM2].Key_Card_Ref_b ,RBDPK_KEYREF_INVALID);
    // EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[(uint8)WCPM2].activeState_u8 ,0x00);//(uint8)NFC_READER_NOT_ACTIVE_STATE_E
    // EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[(uint8)WCPM2].session_timeout_u16 ,NFC_SESSION_TIMEOUT);
    // EXPECT_EQ(*get_rbd_NFCVehIf_getUID_active_b() ,FALSE);Code removed
}
/*
@rst
    Brief description of test case.
    :Description: if ((rbd_NFCVehIf_CardData_st.routineStatus_u8 == (uint8)IN_PROGRESS) &&(rbd_NFCVehIf_getUID_active_b == TRUE)) ==> FALSE MCDC (FX)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 270909
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ResetNFCReaderSessionTag()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_GetNfcUID_Start_RequestResults_03)
{
    uint8 Out_ResData[10];
    Dcm_NegativeResponseCodeType ErrorCode = DCM_E_GENERALREJECT;
    // get_rbd_NFCVehIf_CardData_st()->routineStatus_u8=(uint8)ROUTINE_FAILED;
    // get_rbd_NFCVehIf_CardData_st()->errorCode_u8=1;Code removed
    // *get_rbd_NFCVehIf_getUID_active_b () = FALSE;Code removed
    Std_ReturnType ret_val = call_rbd_NFCVehIf_GetNfcUID_Start_RequestResults(Out_ResData, &ErrorCode);
    EXPECT_EQ(ret_val,RTE_E_OK);
    EXPECT_EQ(ErrorCode,DCM_E_POSITIVERESPONSE);
    // EXPECT_EQ(Out_ResData[0], get_rbd_NFCVehIf_CardData_st()->routineStatus_u8);
    // EXPECT_EQ(Out_ResData[1], 2);
    // EXPECT_EQ(Out_ResData[2], get_rbd_NFCVehIf_CardData_st()->cardUID_au8[0]);
    // EXPECT_EQ(Out_ResData[3], get_rbd_NFCVehIf_CardData_st()->cardUID_au8[1]);
    // EXPECT_EQ(Out_ResData[4], get_rbd_NFCVehIf_CardData_st()->cardUID_au8[2]);
    // EXPECT_EQ(Out_ResData[5], get_rbd_NFCVehIf_CardData_st()->cardUID_au8[3]);
    // EXPECT_EQ(Out_ResData[6], get_rbd_NFCVehIf_CardData_st()->cardUID_au8[4]);
    // EXPECT_EQ(Out_ResData[7], get_rbd_NFCVehIf_CardData_st()->cardUID_au8[5]);
    // EXPECT_EQ(Out_ResData[8], get_rbd_NFCVehIf_CardData_st()->cardUID_au8[6]);Code removed
    // EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[(uint8)WCPM2].connectionStatus_u8,READER_DISCONNECTED);
    // EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[(uint8)WCPM2].Key_Card_Ref_b ,RBDPK_KEYREF_INVALID);
    // EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[(uint8)WCPM2].activeState_u8 ,0x00);//(uint8)NFC_READER_NOT_ACTIVE_STATE_E
    // EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[(uint8)WCPM2].session_timeout_u16 ,NFC_SESSION_TIMEOUT);
    // EXPECT_EQ(*get_rbd_NFCVehIf_getUID_active_b() ,FALSE);Code removed
}
//----------------------------------------------------------------------------
// Test Cases//  void rbd_NfcVehIf_ToggleOperationFinished(void)
//----------------------------------------------------------------------------
/*
@rst
    Brief description of test case.
    :Description: if(session_state_u8 == (uint8)NFC_READER_TAP_ENTRY_TOGGLE_RSP_WAIT_STATE_E) ==> FALSE
    :Arch ID: 81cff5e6-c95e-44ce-a38c-aee801138a22
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NfcVehIf_ToggleOperationFinished_01)
{
    get_rbd_NFCVehIf_Table_as()[0].activeState_u8  = 0x08u;
    call_rbd_NFCVehIf_ToggleOperationFinished();
    // Do Nothing
}

/*
@rst
    Brief description of test case.
    :Description: if(session_state_u8 == (uint8)NFC_READER_TAP_ENTRY_TOGGLE_RSP_WAIT_STATE_E) ==> TRUE
    :Arch ID: 81cff5e6-c95e-44ce-a38c-aee801138a22
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_NfcTeardown()
    :Description: switch((NfcEcuIds)nfcReaderId)
        case FLDHM:
        if((uint8)NFC_READER_TAP_ENTRY_TEAR_DOWN_STATE_E == session_state_u8) ==> TRUE
    :Arch ID: 307a4b14-a9de-4687-ba2e-5c65b174ce4a
    :REQ ID: NA
    :ALM Task ID: 286698
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NfcVehIf_ToggleOperationFinished_02)
{
    get_rbd_NFCVehIf_Table_as()[0].activeState_u8  = 0x06u;
    call_rbd_NFCVehIf_ToggleOperationFinished();
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].activeState_u8, 0);
}

//----------------------------------------------------------------------------
// Test Cases//  FUNC(Std_ReturnType, rbd_NFCVehIf_CODE) rbd_NFCVehIf_NFC_Card_Serial_Number_Read_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR) ErrorCode)
//----------------------------------------------------------------------------
/*
@rst
    Brief description of test case.
    :Description: if(KeysCountRead == FALSE) ==> TRUE
        if((0u != keyCardRef_paried_u8) && (rbd_NFCVehIf_CardIndex < keyCardRef_paried_u8)  && (FALSE == isKeyInfoReadInProgress)) ==> TRUE MCDC (TTT)
        if(RTE_E_OK == dkmRet_u8 ) ==> TRUE
        if(TRUE == isKeyInfoReadInProgress) ==> TRUE
        if((RTE_E_NFC_Card_Pairing_Start_E_OK == result) && ((uint16)RBDPK_CCC_DEV_AUTHENTICATED == errCode)) ==> FALSE MCDC (TF)
        else if(RTE_E_IF_NfcFlow_E_BUSY == result) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 92308
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NFC_Card_Serial_Number_Read_ConditionCheckRead_01)
{
    *get_keyCardRef_paried_u8() = 1;
    *get_rbd_NFCVehIf_CardIndex()=0;
    Dcm_NegativeResponseCodeType ErrorCode = DCM_E_GENERALREJECT;
    Dkm_GetNumberOfKeyEntries_Operation_fake.return_val = 1;
    Dkm_GetNumberOfKeyEntries_Operation_fake.arg3_val = get_keyCardRef_paried_u8();
    dummy_devMgr_OpStatus_u16=RBDPK_CCC_DEV_AUTHENTICATION_FAILED;
    Dkm_DeviceMgr_GetStatus_Operation_fake.return_val=RTE_E_NFC_Card_Pairing_Start_E_OK;
    Dkm_DeviceMgr_GetStatus_Operation_fake.custom_fake=Dkm_DeviceMgr_GetStatus_Operation_custom_fake;
    Std_ReturnType ret = call_rbd_NFCVehIf_NFC_Card_Serial_Number_Read_ConditionCheckRead(1, &ErrorCode);
    EXPECT_EQ(ret, RTE_E_NFC_Card_Serial_Number_Read_E_OK);
    EXPECT_EQ(ErrorCode , 0);
    EXPECT_EQ(Dkm_GetKeyInfoCard_Operation_fake.call_count,1);
}
/*
@rst
    Brief description of test case.
    :Description: if(KeysCountRead == FALSE) ==> TRUE
        if((0u != keyCardRef_paried_u8) && (rbd_NFCVehIf_CardIndex < keyCardRef_paried_u8)  && (FALSE == isKeyInfoReadInProgress)) ==> TRUE MCDC (TTT)
        if(RTE_E_OK == dkmRet_u8 ) ==> TRUE
        if(TRUE == isKeyInfoReadInProgress) ==> TRUE
        if((RTE_E_NFC_Card_Pairing_Start_E_OK == result) && ((uint16)RBDPK_CCC_DEV_AUTHENTICATED == errCode)) ==> TRUE MCDC (TT)
        if(rbd_NFCVehIf_CardIndex == keyCardRef_paried_u8) ==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 92308
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NFC_Card_Serial_Number_Read_ConditionCheckRead_02)
{
    *get_keyCardRef_paried_u8() = 1;
    *get_rbd_NFCVehIf_CardIndex()=0;
    Dcm_NegativeResponseCodeType ErrorCode = DCM_E_GENERALREJECT;
    Dkm_GetNumberOfKeyEntries_Operation_fake.return_val = 1;
    Dkm_GetNumberOfKeyEntries_Operation_fake.arg3_val = get_keyCardRef_paried_u8();
    dummy_devMgr_OpStatus_u16=RBDPK_CCC_DEV_AUTHENTICATED;
    Dkm_DeviceMgr_GetStatus_Operation_fake.return_val=RTE_E_NFC_Card_Pairing_Start_E_OK;
    Dkm_DeviceMgr_GetStatus_Operation_fake.custom_fake=Dkm_DeviceMgr_GetStatus_Operation_custom_fake;
    Std_ReturnType ret = call_rbd_NFCVehIf_NFC_Card_Serial_Number_Read_ConditionCheckRead(1, &ErrorCode);
    EXPECT_EQ(ret, RTE_E_NFC_Card_Serial_Number_Read_E_OK);
    EXPECT_EQ(ErrorCode , DCM_E_POSITIVERESPONSE);
    EXPECT_EQ(Dkm_GetKeyInfoCard_Operation_fake.call_count,1);
}
/*
@rst
    Brief description of test case.
    :Description: if(KeysCountRead == FALSE) ==> TRUE
        if((0u != keyCardRef_paried_u8) && (rbd_NFCVehIf_CardIndex < keyCardRef_paried_u8)  && (FALSE == isKeyInfoReadInProgress)) ==> TRUE MCDC (TTT)
        if(RTE_E_OK == dkmRet_u8 ) ==> TRUE
        if(TRUE == isKeyInfoReadInProgress) ==> TRUE
        if((RTE_E_NFC_Card_Pairing_Start_E_OK == result) && ((uint16)RBDPK_CCC_DEV_AUTHENTICATED == errCode)) ==> TRUE MCDC (TT)
        if(rbd_NFCVehIf_CardIndex == keyCardRef_paried_u8) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 92308
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NFC_Card_Serial_Number_Read_ConditionCheckRead_03)
{
    *get_keyCardRef_paried_u8() = 2;
    *get_rbd_NFCVehIf_CardIndex()=0;
    Dcm_NegativeResponseCodeType ErrorCode = DCM_E_GENERALREJECT;
    Dkm_GetNumberOfKeyEntries_Operation_fake.return_val = 1;
    Dkm_GetNumberOfKeyEntries_Operation_fake.arg3_val = get_keyCardRef_paried_u8();
    dummy_devMgr_OpStatus_u16=RBDPK_CCC_DEV_AUTHENTICATED;
    Dkm_DeviceMgr_GetStatus_Operation_fake.return_val=RTE_E_NFC_Card_Pairing_Start_E_OK;
    Dkm_DeviceMgr_GetStatus_Operation_fake.custom_fake=Dkm_DeviceMgr_GetStatus_Operation_custom_fake;
    Std_ReturnType ret = call_rbd_NFCVehIf_NFC_Card_Serial_Number_Read_ConditionCheckRead(1, &ErrorCode);
    EXPECT_EQ(ret, RTE_E_NFC_Card_Serial_Number_Read_DCM_E_PENDING);
    EXPECT_EQ(ErrorCode , DCM_E_GENERALREJECT);
    EXPECT_EQ(Dkm_GetKeyInfoCard_Operation_fake.call_count,1);
}
/*
@rst
    Brief description of test case.
    :Description: if(KeysCountRead == FALSE) ==> TRUE
        if((0u != keyCardRef_paried_u8) && (rbd_NFCVehIf_CardIndex < keyCardRef_paried_u8)  && (FALSE == isKeyInfoReadInProgress)) ==> TRUE MCDC (TTT)
        if(RTE_E_OK == dkmRet_u8 ) ==> TRUE
        if(TRUE == isKeyInfoReadInProgress) ==> TRUE
        if((RTE_E_NFC_Card_Pairing_Start_E_OK == result) && ((uint16)RBDPK_CCC_DEV_AUTHENTICATED == errCode)) ==> FALSE MCDC (FX)
        else if(RTE_E_IF_NfcFlow_E_BUSY == result) ==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 92308
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NFC_Card_Serial_Number_Read_ConditionCheckRead_04)
{
    *get_keyCardRef_paried_u8() = 2;
    *get_rbd_NFCVehIf_CardIndex()=0;
    Dcm_NegativeResponseCodeType ErrorCode = DCM_E_GENERALREJECT;
    Dkm_GetNumberOfKeyEntries_Operation_fake.return_val = 1;
    Dkm_GetNumberOfKeyEntries_Operation_fake.arg3_val = get_keyCardRef_paried_u8();
    dummy_devMgr_OpStatus_u16=RBDPK_CCC_DEV_AUTHENTICATED;
    Dkm_DeviceMgr_GetStatus_Operation_fake.return_val=RTE_E_IF_NfcFlow_E_BUSY;
    Dkm_DeviceMgr_GetStatus_Operation_fake.custom_fake=Dkm_DeviceMgr_GetStatus_Operation_custom_fake;
    Std_ReturnType ret = call_rbd_NFCVehIf_NFC_Card_Serial_Number_Read_ConditionCheckRead(1, &ErrorCode);
    EXPECT_EQ(ret, RTE_E_NFC_Card_Serial_Number_Read_DCM_E_PENDING);
    EXPECT_EQ(ErrorCode , DCM_E_GENERALREJECT);
    EXPECT_EQ(Dkm_GetKeyInfoCard_Operation_fake.call_count,1);
}
/*
@rst
    Brief description of test case.
    :Description: if(KeysCountRead == FALSE) ==> FALSE
        if((0u != keyCardRef_paried_u8) && (rbd_NFCVehIf_CardIndex < keyCardRef_paried_u8)  && (FALSE == isKeyInfoReadInProgress)) ==> FALSE MCDC (TTF)
        if(TRUE == isKeyInfoReadInProgress) ==> TRUE
        if((RTE_E_NFC_Card_Pairing_Start_E_OK == result) && ((uint16)RBDPK_CCC_DEV_AUTHENTICATED == errCode)) ==> FALSE MCDC (FX)
        else if(RTE_E_IF_NfcFlow_E_BUSY == result) ==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 92308
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NFC_Card_Serial_Number_Read_ConditionCheckRead_05)
{
    *get_keyCardRef_paried_u8() = 2;
    *get_rbd_NFCVehIf_CardIndex()=0;
    Dcm_NegativeResponseCodeType ErrorCode = DCM_E_GENERALREJECT;
    Dkm_GetNumberOfKeyEntries_Operation_fake.return_val = 1;
    Dkm_GetNumberOfKeyEntries_Operation_fake.arg3_val = get_keyCardRef_paried_u8();
    dummy_devMgr_OpStatus_u16=RBDPK_CCC_DEV_AUTHENTICATED;
    Dkm_DeviceMgr_GetStatus_Operation_fake.return_val=RTE_E_IF_NfcFlow_E_BUSY;
    Dkm_DeviceMgr_GetStatus_Operation_fake.custom_fake=Dkm_DeviceMgr_GetStatus_Operation_custom_fake;
    Std_ReturnType ret = call_rbd_NFCVehIf_NFC_Card_Serial_Number_Read_ConditionCheckRead(1, &ErrorCode);
    EXPECT_EQ(ret, RTE_E_NFC_Card_Serial_Number_Read_DCM_E_PENDING);
    EXPECT_EQ(ErrorCode , DCM_E_GENERALREJECT);
    call_rbd_NFCVehIf_NFC_Card_Serial_Number_Read_ConditionCheckRead(1, &ErrorCode);
}
/*
@rst
    Brief description of test case.
    :Description: if(KeysCountRead == FALSE) ==> FALSE
        if((0u != keyCardRef_paried_u8) && (rbd_NFCVehIf_CardIndex < keyCardRef_paried_u8)  && (FALSE == isKeyInfoReadInProgress)) ==> FALSE MCDC (TFX)
        if(TRUE == isKeyInfoReadInProgress) ==> TRUE
        if((RTE_E_NFC_Card_Pairing_Start_E_OK == result) && ((uint16)RBDPK_CCC_DEV_AUTHENTICATED == errCode)) ==> FALSE MCDC (FX)
        else if(RTE_E_IF_NfcFlow_E_BUSY == result) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 92308
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NFC_Card_Serial_Number_Read_ConditionCheckRead_06)
{
    *get_keyCardRef_paried_u8() = 1;
    *get_rbd_NFCVehIf_CardIndex()=1;
    Dcm_NegativeResponseCodeType ErrorCode = DCM_E_GENERALREJECT;
    Dkm_GetNumberOfKeyEntries_Operation_fake.return_val = 1;
    Dkm_GetNumberOfKeyEntries_Operation_fake.arg3_val = get_keyCardRef_paried_u8();
    dummy_devMgr_OpStatus_u16=RBDPK_CCC_DEV_AUTHENTICATED;
    Dkm_DeviceMgr_GetStatus_Operation_fake.return_val=5;
    Dkm_DeviceMgr_GetStatus_Operation_fake.custom_fake=Dkm_DeviceMgr_GetStatus_Operation_custom_fake;
    Std_ReturnType ret = call_rbd_NFCVehIf_NFC_Card_Serial_Number_Read_ConditionCheckRead(1, &ErrorCode);
    EXPECT_EQ(ret, RTE_E_NFC_Card_Serial_Number_Read_E_NOT_OK);
    EXPECT_EQ(ErrorCode , DCM_E_GENERALREJECT);

}
/*
@rst
    Brief description of test case.
    :Description: if(KeysCountRead == FALSE) ==> FALSE
        if((0u != keyCardRef_paried_u8) && (rbd_NFCVehIf_CardIndex < keyCardRef_paried_u8)  && (FALSE == isKeyInfoReadInProgress)) ==> FALSE MCDC (FXX)
        if(TRUE == isKeyInfoReadInProgress) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 92308
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NFC_Card_Serial_Number_Read_ConditionCheckRead_07)
{
    *get_keyCardRef_paried_u8() = 0;
    *get_rbd_NFCVehIf_CardIndex()=1;
    Dcm_NegativeResponseCodeType ErrorCode = DCM_E_GENERALREJECT;
    Dkm_GetNumberOfKeyEntries_Operation_fake.return_val = 1;
    Dkm_GetNumberOfKeyEntries_Operation_fake.arg3_val = get_keyCardRef_paried_u8();
    dummy_devMgr_OpStatus_u16=RBDPK_CCC_DEV_AUTHENTICATED;
    Dkm_DeviceMgr_GetStatus_Operation_fake.return_val=5;
    Dkm_DeviceMgr_GetStatus_Operation_fake.custom_fake=Dkm_DeviceMgr_GetStatus_Operation_custom_fake;
    Std_ReturnType ret = call_rbd_NFCVehIf_NFC_Card_Serial_Number_Read_ConditionCheckRead(1, &ErrorCode);
    EXPECT_EQ(ret, RTE_E_NFC_Card_Serial_Number_Read_E_OK);
    EXPECT_EQ(ErrorCode , DCM_E_POSITIVERESPONSE);
}
/*
@rst
    Brief description of test case.
    :Description: if(KeysCountRead == FALSE) ==> TRUE
        if((0u != keyCardRef_paried_u8) && (rbd_NFCVehIf_CardIndex < keyCardRef_paried_u8)  && (FALSE == isKeyInfoReadInProgress)) ==> TRUE MCDC (TTT)
        if(RTE_E_OK == dkmRet_u8 ) ==> TRUE
        if(TRUE == isKeyInfoReadInProgress) ==> TRUE
        if((RTE_E_NFC_Card_Pairing_Start_E_OK == result) && ((uint16)RBDPK_CCC_DEV_AUTHENTICATED == errCode)) ==> FALSE MCDC (TF)
        else if(RTE_E_IF_NfcFlow_E_BUSY == result) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 92212
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NFC_Card_Serial_Number_Read_ConditionCheckRead_08)
{
    *get_keyCardRef_paried_u8() = 1;
    *get_rbd_NFCVehIf_CardIndex()=0;
    Dcm_NegativeResponseCodeType ErrorCode = DCM_E_GENERALREJECT;
    Dkm_GetNumberOfKeyEntries_Operation_fake.return_val = 1;
    Dkm_GetNumberOfKeyEntries_Operation_fake.arg3_val = get_keyCardRef_paried_u8();
    dummy_devMgr_OpStatus_u16=RBDPK_CCC_DEV_AUTHENTICATION_FAILED;
    Dkm_DeviceMgr_GetStatus_Operation_fake.return_val=RTE_E_NFC_Card_Pairing_Start_E_OK;
    Dkm_DeviceMgr_GetStatus_Operation_fake.custom_fake=Dkm_DeviceMgr_GetStatus_Operation_custom_fake;
    Std_ReturnType ret = call_rbd_NFCVehIf_NFC_Card_Serial_Number_Read_ConditionCheckRead(1, &ErrorCode);
    EXPECT_EQ(ret, RTE_E_NFC_Card_Serial_Number_Read_E_OK);
    EXPECT_EQ(ErrorCode , 0);
    EXPECT_EQ(Dkm_GetKeyInfoCard_Operation_fake.call_count,1);
}
/*
@rst
    Brief description of test case.
    :Description: if(KeysCountRead == FALSE) ==> TRUE
        if((0u != keyCardRef_paried_u8) && (rbd_NFCVehIf_CardIndex < keyCardRef_paried_u8)  && (FALSE == isKeyInfoReadInProgress)) ==> TRUE MCDC (TTT)
        if(RTE_E_OK == dkmRet_u8 ) ==> FALSE
        if(TRUE == isKeyInfoReadInProgress) ==> FALSE
        if(RTE_E_OK == dkmRet_u8 ) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 92212
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NFC_Card_Serial_Number_Read_ConditionCheckRead_09)
{
    *get_keyCardRef_paried_u8() = 2;
    *get_rbd_NFCVehIf_CardIndex()=0;
    Dcm_NegativeResponseCodeType ErrorCode = DCM_E_GENERALREJECT;
    Dkm_GetNumberOfKeyEntries_Operation_fake.return_val = 1;
    Dkm_GetNumberOfKeyEntries_Operation_fake.arg3_val = get_keyCardRef_paried_u8();
    dummy_devMgr_OpStatus_u16=RBDPK_CCC_DEV_AUTHENTICATED;
    Dkm_DeviceMgr_GetStatus_Operation_fake.return_val=RTE_E_NFC_Card_Pairing_Start_E_OK;
    Dkm_DeviceMgr_GetStatus_Operation_fake.custom_fake=Dkm_DeviceMgr_GetStatus_Operation_custom_fake;
    Dkm_GetKeyInfoCard_Operation_fake.return_val = RTE_E_INVALID;
    Std_ReturnType ret = call_rbd_NFCVehIf_NFC_Card_Serial_Number_Read_ConditionCheckRead(1, &ErrorCode);
    EXPECT_EQ(ret, RTE_E_NFC_Card_Serial_Number_Read_DCM_E_PENDING);
    EXPECT_EQ(ErrorCode , DCM_E_GENERALREJECT);
    EXPECT_EQ(Dkm_GetKeyInfoCard_Operation_fake.call_count,1);
}
//----------------------------------------------------------------------------
// Test Cases//  void rbd_NFCVehIf_UpdateNFCReaderSessionTimeOut( const uint8 NfcReaderId_u8,const uint16 sessionTout_u16)
//----------------------------------------------------------------------------
/*
@rst
    Brief description of test case.
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS )  && (READER_IN_SESSION == rbd_NFCVehIf_Table_as[NfcReaderId_u8].connectionStatus_u8)) ==> TRUE MCDC(TT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_UpdateNFCReaderSessionTimeOut_01)
{
    get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8  = READER_IN_SESSION;
    call_rbd_NFCVehIf_UpdateNFCReaderSessionTimeOut(0, 1);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].session_timeout_u16, 1);
}

/*
@rst
    Brief description of test case.
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS )  && (READER_IN_SESSION == rbd_NFCVehIf_Table_as[NfcReaderId_u8].connectionStatus_u8)) ==> FALSE MCDC(FX)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_UpdateNFCReaderSessionTimeOut_02)
{
    call_rbd_NFCVehIf_UpdateNFCReaderSessionTimeOut(4, 1);
    //Do Nothing
}

//----------------------------------------------------------------------------
// Test Cases//  void rbd_NFCVehIf_NFCReaderSessionTimeOutManager(void)
//----------------------------------------------------------------------------
/*
@rst
    Brief description of test case.
    :Description: for ( NfcReaderId_u8 = 0u; NfcReaderId_u8 < NFC_NUM_READERS; NfcReaderId_u8++ ) ==> TRUE,FALSE
        if ( READER_IN_SESSION == rbd_NFCVehIf_Table_as[NfcReaderId_u8].connectionStatus_u8 ) ==> TRUE
        ( rbd_NFCVehIf_Table_as[NfcReaderId_u8].session_timeout_u16 != 0u ) ? ( rbd_NFCVehIf_Table_as[NfcReaderId_u8].session_timeout_u16 - (uint16)1u ) : (uint16)0u ==> TRUE,FALSE
        if(0u == rbd_NFCVehIf_Table_as[NfcReaderId_u8].session_timeout_u16) ==> TRUE,FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 153320
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_NFCReaderSessionTimeOutManager_01)
{
    get_rbd_NFCVehIf_Table_as()[0].connectionStatus_u8  = READER_IN_SESSION;
    get_rbd_NFCVehIf_Table_as()[0].session_timeout_u16  = 0;
    call_rbd_NFCVehIf_NFCReaderSessionTimeOutManager();
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[0].session_timeout_u16, NFC_SESSION_TIMEOUT);
    EXPECT_EQ(rbdSessionMgr_NfcDisconnected_fake.call_count, 1);
    // EXPECT_EQ(rbdSessionMgr_NfcDisconnected_fake.arg0_val, 0);
}
//----------------------------------------------------------------------------
// Test Cases// static Std_ReturnType rbd_NFCVehIf_WritePort(const uint8 dest_u8, const uint8 *request_pt, const uint16 length_u16)
//----------------------------------------------------------------------------
/*
@rst
    Brief description of test case.
    :Description: if(NFC_READER_GET_UID_STATE_E != session_state_u8) ==>FALSE
        if (dest_u8 == (uint8)FLDHM) ==> FALSE
        else if (dest_u8 == (uint8)FRDHM) ==> FALSE
        else if (dest_u8 == (uint8)WCPM2) ==> FALSE
    :Arch ID: 768d42bb-df4d-4b75-bd0c-10cdf4ab93ae
    :REQ ID: NA
    :ALM Task ID: 92308
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_WritePort_01)
{
    uint8 request_pt=0;
    get_rbd_NFCVehIf_Table_as()[3].activeState_u8  = 0X23;//NFC_READER_GET_UID_STATE_E
    get_rbd_NFCVehIf_Table_as()[3].connectionStatus_u8  = READER_IN_SESSION;
    get_rbd_NFCVehIf_Table_as()[3].session_timeout_u16  = 0;
    call_rbd_NFCVehIf_WritePort(3,&request_pt,1);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[3].activeState_u8,0X23);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[3].connectionStatus_u8,READER_IN_SESSION);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[3].session_timeout_u16,0);
}

//----------------------------------------------------------------------------
// Test Cases// FUNC(Std_ReturnType, rbd_NFCVehIf_CODE) rbd_NFCVehIf_WcpKeyAuthReq_Cbk(void)
//----------------------------------------------------------------------------
/*
@rst
    Brief description of test case.
    :Description: if ( READER_IN_SESSION == readerConnection_state_u8 ) ==> FALSE
    :Arch ID:
    :REQ ID: NA
    :ALM Task ID: 92212
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 92212
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_RegisterNFCReaderSession()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
        if ( READER_DISCONNECTED == rbd_NFCVehIf_Table_as[NfcReaderId_u8].connectionStatus_u8 ) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 92212
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_UpdateNFCReaderState()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
        if(NULL != newDevRef_pu8) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 92212
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_WcpKeyAuthReq_Cbk_01)
{
    get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8  = READER_DISCONNECTED;
    get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b  = NFC_SERIAL_LEN;//15
    get_rbd_NFCVehIf_Table_as()[2].activeState_u8  = 0x15u;//NFC_READER_TAP_START_DEVICE_INFO_WAIT_STATE_E
    Dkm_NfcFlow_Start_fake.return_val = RTE_E_OK;
    Std_ReturnType ret_val = call_rbd_NFCVehIf_WcpKeyAuthReq_Cbk();
    //EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].activeState_u8,0X40);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8,READER_IN_SESSION);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b,RBDPK_KEYREF_INVALID);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].session_timeout_u16,NFC_SESSION_TIMEOUT);
    EXPECT_EQ(ret_val, RTE_E_OK);
}
/*
@rst
    Brief description of test case.
    :Description: if ( READER_IN_SESSION == readerConnection_state_u8 ) ==> TRUE
    :Arch ID:
    :REQ ID: NA
    :ALM Task ID: 92212
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ReadNFCReaderStatusInfo()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 92212
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_RegisterNFCReaderSession()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
        if ( READER_DISCONNECTED == rbd_NFCVehIf_Table_as[NfcReaderId_u8].connectionStatus_u8 ) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 92212
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_UpdateNFCReaderState()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
        if(NULL != newDevRef_pu8) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 92212
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    Calling function rbd_NFCVehIf_ResetNFCReaderSessionTag()
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 92212
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_WcpKeyAuthReq_Cbk_02)
{
    get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8  = READER_IN_SESSION;
    get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b  = NFC_SERIAL_LEN;//15
    get_rbd_NFCVehIf_Table_as()[2].activeState_u8  = 0x15u;//NFC_READER_TAP_START_DEVICE_INFO_WAIT_STATE_E
    Dkm_NfcFlow_Start_fake.return_val = RTE_E_INVALID;
    Std_ReturnType ret_val = call_rbd_NFCVehIf_WcpKeyAuthReq_Cbk();
    //EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].activeState_u8, 0X40);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8, READER_IN_SESSION);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b, RBDPK_KEYREF_INVALID);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].session_timeout_u16, NFC_SESSION_TIMEOUT);
    EXPECT_EQ(rbdSessionMgr_NfcDisconnected_fake.call_count, 1);
    EXPECT_EQ(ret_val, RTE_E_INVALID);
}

//----------------------------------------------------------------------------
// Test Cases// static void rbd_NfcIf_NfcReaderCanTPPacketHeaderRead(const uint8 * packetDataIn, nfcReaderResponseHeader_t *  nfcReaderDataHeader_ps)
//----------------------------------------------------------------------------
/*
@rst
    Brief description of test case.
    :Description: if((NULL != packetDataIn) && (NULL != nfcReaderDataHeader_ps)) ==> FALSE MCDC (TF)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 92212
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NfcIf_NfcReaderCanTPPacketHeaderRead_01)
{
    uint8 packetDataIn = 1;
    call_rbd_NfcIf_NfcReaderCanTPPacketHeaderRead(&packetDataIn, NULL);
    //Do nothing
}

//----------------------------------------------------------------------------
// Test Cases// static void rbd_NfcIf_NfcReaderCanTPPacketHeaderWrite(uint8 * packetDataOut, const nfcReaderResponseHeader_t *  nfcReaderDataHeader_ps)
//----------------------------------------------------------------------------
/*
@rst
    Brief description of test case.
    :Description: if((NULL != packetDataOut) && (NULL != nfcReaderDataHeader_ps)) ==> FALSE MCDC (TF)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 92212
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NfcIf_NfcReaderCanTPPacketHeaderWrite_01)
{
    uint8 packetDataOut = 1;
    call_rbd_NfcIf_NfcReaderCanTPPacketHeaderWrite(&packetDataOut, NULL);
    //Do nothing
}
/*
@rst
    Brief description of test case.
    :Description: if((NULL != packetDataOut) && (NULL != nfcReaderDataHeader_ps)) ==> FALSE MCDC (FX)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 92212
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NfcIf_NfcReaderCanTPPacketHeaderWrite_02)
{
    call_rbd_NfcIf_NfcReaderCanTPPacketHeaderWrite(NULL, NULL);
    //Do nothing
}
// //----------------------------------------------------------------------------
// // Test Cases// static void rbd_NFCVehIf_checkDkmCardPairingRequest( void )
// //----------------------------------------------------------------------------
// /*
// @rst
//     Brief description of test case.
//     :Description: if(rbd_NFCVehIf_CardPairReq_st.requestCardPairing_b == TRUE) ==> TRUE
//         rbd_NFCVehIf_NfcCardTimer_u16 = (rbd_NFCVehIf_NfcCardTimer_u16 >= (uint16)NFC_CYCLE_TIME ) ?( rbd_NFCVehIf_NfcCardTimer_u16 - NFC_CYCLE_TIME ) : 0u ==> TRUE
//         if(checkDkmCardPair_u8 == RBD_SESSIONMGR_E_OK) ==> FALSE
//         else if ((checkDkmCardPair_u8 == RBD_SESSIONMGR_E_NOT_OK) || (0u == rbd_NFCVehIf_NfcCardTimer_u16)) ==> FALSE MCDC(FF)
//     :Arch ID: NA
//     :REQ ID: NA
//     :ALM Task ID: 92212
//     :Testing Method: Negative
//     :Justifications: Coverage / Bug (NA)
// */
// TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_checkDkmCardPairingRequest_01)
// {
//     // get_rbd_NFCVehIf_CardPairReq_st()->requestCardPairing_b = TRUE;Code removed
//     rbdSessionMgr_startNFCCardPairing_fake.return_val = 11;
//     *get_rbd_NFCVehIf_NfcCardTimer_u16() = 11;
//     call_rbd_NFCVehIf_checkDkmCardPairingRequest();
//     //Do nothing
// }Code removed
//----------------------------------------------------------------------------
// Test Cases// void rbd_NFCVehIf_DTC(void)
//----------------------------------------------------------------------------
/*
@rst
    Brief description of test case.
    :Description: if(max_auth_failure_counter_u8 <= wcpm2_auth_failure_counter_u8) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 252384
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_DTC_01)
{
    dummy_RteParameterRefTab.cp_NFC_Device_Request_Counter = 12;
    Rte_rbd_NFCVehIf_rbd_NFCVehIf_WCMP_FailedAttempts_Counter_MirrorBlock = 1;
    call_rbd_NFCVehIf_DTC();
    EXPECT_EQ(NvM_WriteBlock_fake.call_count, 1);
    //EXPECT_EQ(rbd_RfhmIf_ControlFd9Bus_fake.call_count, 1);
    EXPECT_EQ(Rte_rbd_NFCVehIf_PP_CanRequest_DkmNfc_ComRequest, FALSE);
    EXPECT_EQ(*get_rbd_NFCVehIf_DTCWCMP2Timer_active_b(), FALSE);
}

//----------------------------------------------------------------------------
// Test Cases// static uint8 rbd_NFCVehIf_IsRoutineInProgress(void)
//----------------------------------------------------------------------------
/*
@rst
    Brief description of test case.
    :Description: if ( ( rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_PLANT_PAIRING_E].nfcRoutineStatus == (uint8)NFC_ROUTINE_STATUS_IN_PROGRESS_E ) || ( rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_TEST_CARD_PAIRING_E].nfcRoutineStatus == (uint8)NFC_ROUTINE_STATUS_IN_PROGRESS_E ) || ( rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_GET_UID_E].nfcRoutineStatus == (uint8)NFC_ROUTINE_STATUS_IN_PROGRESS_E ) ) ==> TRUE MCDC(FFT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 288528
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_IsRoutineInProgress_01)
{
    get_rbd_NFCVehIf_RoutineData_S()[0].mock_nfcRoutineStatus = 0x01u;
    get_rbd_NFCVehIf_RoutineData_S()[1].mock_nfcRoutineStatus = 0x01u;
    get_rbd_NFCVehIf_RoutineData_S()[2].mock_nfcRoutineStatus = 0x02u;
    Std_ReturnType ret_val = call_rbd_NFCVehIf_IsRoutineInProgress();
    EXPECT_EQ(TRUE, ret_val);
}

//----------------------------------------------------------------------------
// Test Cases// static void rbd_NfcIf_TapStartTriggerCyclic( void )
//----------------------------------------------------------------------------
/*
@rst
    Brief description of test case.
    :Description: if ( ((uint8)NFC_READER_TAP_START_RFHM_TRIGGER_RX_STATE_E) == session_state_u8 ) ==> FALSE
        rbd_NFCVehIf_TapStartPollingTimeoutTimer_u16 = ( rbd_NFCVehIf_TapStartPollingTimeoutTimer_u16 >= (uint16)NFC_CYCLE_TIME ) ? ( rbd_NFCVehIf_TapStartPollingTimeoutTimer_u16 - NFC_CYCLE_TIME ) : 0u ==> TRUE
        if ( rbd_NFCVehIf_TapStartPollingTimeoutTimer_u16 > 0x00u ) ==> FALSE
        if ( ( READER_IN_SESSION == readerConnection_state_u8 ) && ( ((uint8)NFC_READER_TAP_START_FLOW_INIT_STATE_E) == session_state_u8 ) ) ==> TRUE MCDC(TT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 288528
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    rbd_NFCVehIf_ReadNFCReaderStatusInfo:
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 288528
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    rbd_NFCVehIf_ClearEvent:
    :Description: Verifying for the function rbd_NFCVehIf_ClearEvent()
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 288528
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    rbd_NFCVehIf_NfcTeardown:
    :Description: switch((NfcEcuIds)nfcReaderId)
        case WCPM2
        rbd_NFCVehIf_NFC_Count -= (rbd_NFCVehIf_NFC_Count > 0U) ? 1U : 0U ==> TRUE
        if(((uint8)NFC_READER_CARD_PLANT_PAIR_STATE_E == session_state_u8) ||
				   ((uint8)NFC_READER_CARD_PLANT_PAIR_TEAR_DOWN_STATE_E == session_state_u8) ||
					((uint8)NFC_READER_CARD_PLANT_TEST_STATE_E == session_state_u8) ||
				   ((uint8)NFC_READER_CARD_PLANT_TEST_TEAR_DOWN_STATE_E == session_state_u8)) ==> FALSE MCDC (FFFF)
        else if(((uint8)NFC_READER_TAP_START_TEAR_DOWN_STATE_E == session_state_u8) ||
					    ((uint8)NFC_READER_TAP_START_DEVICE_INFO_WAIT_STATE_E == session_state_u8)) ==> FALSE MCDC(FF)
        if(((uint8)NFC_READER_TAP_START_STOP_TRIGGER_STATE_E == session_state_u8) ||
					((uint8)NFC_READER_TAP_START_FLOW_INIT_STATE_E == session_state_u8) ||
				   ((uint8)NFC_READER_GET_UID_STATE_E == session_state_u8) ||
				   ((uint8)NFC_READER_GET_UID_TEAR_DOWN_STATE_E == session_state_u8)) ==> TRUE MCDC(FTXX)
    :Arch ID: 307a4b14-a9de-4687-ba2e-5c65b174ce4a
    :REQ ID: NA
    :ALM Task ID: 288528
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    rbd_NFCVehIf_ResetNFCReaderSessionTag:
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 288528
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NfcIf_TapStartTriggerCyclic_01)
{
    get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8 = 1;
    get_rbd_NFCVehIf_Table_as()[2].activeState_u8 = 16;
    get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b = 2;
    get_rbd_NFCVehIf_Table_as()[2].session_timeout_u16 = 255;
    *get_rbd_NFCVehIf_TapStartPollingTimeoutTimer_u16() = NFC_CYCLE_TIME;
    *get_rbd_NFCVehIf_EventFlag() = 1;
    *get_rbd_NFCVehIf_NFC_Count() = 1;
    call_rbd_NfcIf_TapStartTriggerCyclic();
    EXPECT_EQ(*get_rbd_NFCVehIf_EventFlag(), 0);
    EXPECT_EQ(*get_rbd_NFCVehIf_NFC_Count(), 0);
    EXPECT_EQ(rbdSessionMgr_NfcDisconnected_fake.call_count, 1);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8, 0);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].activeState_u8, 0);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b, 255);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].session_timeout_u16, 4000);
}
/*
@rst
    Brief description of test case.
    :Description: if ( ((uint8)NFC_READER_TAP_START_RFHM_TRIGGER_RX_STATE_E) == session_state_u8 ) ==> FALSE
        rbd_NFCVehIf_TapStartPollingTimeoutTimer_u16 = ( rbd_NFCVehIf_TapStartPollingTimeoutTimer_u16 >= (uint16)NFC_CYCLE_TIME ) ? ( rbd_NFCVehIf_TapStartPollingTimeoutTimer_u16 - NFC_CYCLE_TIME ) : 0u ==> TRUE
        if ( rbd_NFCVehIf_TapStartPollingTimeoutTimer_u16 > 0x00u ) ==> TRUE
        if ( ( NFC_WCPM_NOT_READY_EVENT == ( nfc_ReaderEvtMsg_u16 & NFC_WCPM_NOT_READY_EVENT ) ) ||
				( NFC_WCPM_DEVICEMOVED_EVENT == ( nfc_ReaderEvtMsg_u16 & NFC_WCPM_DEVICEMOVED_EVENT ) ) ||
				( NFC_WCPM_READER_TIMEOUT_EVENT == ( nfc_ReaderEvtMsg_u16 & NFC_WCPM_READER_TIMEOUT_EVENT ) ) ||
				( NFC_WCPM_READER_INVALID_MSG_EVENT == ( nfc_ReaderEvtMsg_u16 & NFC_WCPM_READER_INVALID_MSG_EVENT ) ) ||
				( NFC_WCPM_MULTIDEVICE_PRESENT_EVENT == ( nfc_ReaderEvtMsg_u16 & NFC_WCPM_MULTIDEVICE_PRESENT_EVENT ) ) ) ==> FALSE MCDC(FFFFF)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 288528
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    rbd_NFCVehIf_ReadNFCReaderStatusInfo:
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 288528
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    rbd_NFCVehIf_ReadEventWord:
    :Description: Verifying for the function rbd_NFCVehIf_ReadEventWord()
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 288528
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NfcIf_TapStartTriggerCyclic_02)
{
    get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8 = 1;
    get_rbd_NFCVehIf_Table_as()[2].activeState_u8 = 16;
    get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b = 2;
    get_rbd_NFCVehIf_Table_as()[2].session_timeout_u16 = 255;
    *get_rbd_NFCVehIf_TapStartPollingTimeoutTimer_u16() = 11;
    *get_rbd_NFCVehIf_EventFlag() = 1;
    call_rbd_NfcIf_TapStartTriggerCyclic();
    EXPECT_EQ(*get_rbd_NFCVehIf_TapStartPollingTimeoutTimer_u16(), 1);
}
/*
@rst
    Brief description of test case.
    :Description: if ( ((uint8)NFC_READER_TAP_START_RFHM_TRIGGER_RX_STATE_E) == session_state_u8 ) ==> FALSE
        rbd_NFCVehIf_TapStartPollingTimeoutTimer_u16 = ( rbd_NFCVehIf_TapStartPollingTimeoutTimer_u16 >= (uint16)NFC_CYCLE_TIME ) ? ( rbd_NFCVehIf_TapStartPollingTimeoutTimer_u16 - NFC_CYCLE_TIME ) : 0u ==> TRUE
        if ( rbd_NFCVehIf_TapStartPollingTimeoutTimer_u16 > 0x00u ) ==> TRUE
        if ( ( NFC_WCPM_NOT_READY_EVENT == ( nfc_ReaderEvtMsg_u16 & NFC_WCPM_NOT_READY_EVENT ) ) ||
				( NFC_WCPM_DEVICEMOVED_EVENT == ( nfc_ReaderEvtMsg_u16 & NFC_WCPM_DEVICEMOVED_EVENT ) ) ||
				( NFC_WCPM_READER_TIMEOUT_EVENT == ( nfc_ReaderEvtMsg_u16 & NFC_WCPM_READER_TIMEOUT_EVENT ) ) ||
				( NFC_WCPM_READER_INVALID_MSG_EVENT == ( nfc_ReaderEvtMsg_u16 & NFC_WCPM_READER_INVALID_MSG_EVENT ) ) ||
				( NFC_WCPM_MULTIDEVICE_PRESENT_EVENT == ( nfc_ReaderEvtMsg_u16 & NFC_WCPM_MULTIDEVICE_PRESENT_EVENT ) ) ) ==> TRUE MCDC(TXXXX)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 288528
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    rbd_NFCVehIf_ReadNFCReaderStatusInfo:
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 288528
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    rbd_NFCVehIf_RegisterNFCReaderSession:
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
        if ( READER_DISCONNECTED == rbd_NFCVehIf_Table_as[NfcReaderId_u8].connectionStatus_u8 ) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 288528
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    rbd_NFCVehIf_UpdateNFCReaderState:
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
        if(NULL != newDevRef_pu8) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 288528
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    rbd_NFCVehIf_ClearEvent:
    :Description: Verifying for the function rbd_NFCVehIf_ClearEvent()
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 288528
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NfcIf_TapStartTriggerCyclic_03)
{
    get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8 = 1;
    get_rbd_NFCVehIf_Table_as()[2].activeState_u8 = 1;
    get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b = 2;
    get_rbd_NFCVehIf_Table_as()[2].session_timeout_u16 = 255;
    *get_rbd_NFCVehIf_TapStartPollingTimeoutTimer_u16() = 11;
    *get_rbd_NFCVehIf_EventFlag() = 8;
    call_rbd_NfcIf_TapStartTriggerCyclic();
    EXPECT_EQ(*get_rbd_NFCVehIf_EventFlag(), 0);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].activeState_u8, 16);
    EXPECT_EQ(Dkm_NfcFlow_Start_fake.call_count, 1);
}
/*
@rst
    Brief description of test case.
    :Description: if ( ((uint8)NFC_READER_TAP_START_RFHM_TRIGGER_RX_STATE_E) == session_state_u8 ) ==> FALSE
        rbd_NFCVehIf_TapStartPollingTimeoutTimer_u16 = ( rbd_NFCVehIf_TapStartPollingTimeoutTimer_u16 >= (uint16)NFC_CYCLE_TIME ) ? ( rbd_NFCVehIf_TapStartPollingTimeoutTimer_u16 - NFC_CYCLE_TIME ) : 0u ==> TRUE
        if ( rbd_NFCVehIf_TapStartPollingTimeoutTimer_u16 > 0x00u ) ==> TRUE
        if ( ( NFC_WCPM_NOT_READY_EVENT == ( nfc_ReaderEvtMsg_u16 & NFC_WCPM_NOT_READY_EVENT ) ) ||
				( NFC_WCPM_DEVICEMOVED_EVENT == ( nfc_ReaderEvtMsg_u16 & NFC_WCPM_DEVICEMOVED_EVENT ) ) ||
				( NFC_WCPM_READER_TIMEOUT_EVENT == ( nfc_ReaderEvtMsg_u16 & NFC_WCPM_READER_TIMEOUT_EVENT ) ) ||
				( NFC_WCPM_READER_INVALID_MSG_EVENT == ( nfc_ReaderEvtMsg_u16 & NFC_WCPM_READER_INVALID_MSG_EVENT ) ) ||
				( NFC_WCPM_MULTIDEVICE_PRESENT_EVENT == ( nfc_ReaderEvtMsg_u16 & NFC_WCPM_MULTIDEVICE_PRESENT_EVENT ) ) ) ==> TRUE MCDC(FTXXX)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 288528
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    rbd_NFCVehIf_ReadNFCReaderStatusInfo:
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 288528
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    rbd_NFCVehIf_RegisterNFCReaderSession:
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
        if ( READER_DISCONNECTED == rbd_NFCVehIf_Table_as[NfcReaderId_u8].connectionStatus_u8 ) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 288528
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    rbd_NFCVehIf_UpdateNFCReaderState:
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
        if(NULL != newDevRef_pu8) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 288528
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    rbd_NFCVehIf_ClearEvent:
    :Description: Verifying for the function rbd_NFCVehIf_ClearEvent()
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 288528
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NfcIf_TapStartTriggerCyclic_04)
{
    get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8 = 1;
    get_rbd_NFCVehIf_Table_as()[2].activeState_u8 = 1;
    get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b = 2;
    get_rbd_NFCVehIf_Table_as()[2].session_timeout_u16 = 255;
    *get_rbd_NFCVehIf_TapStartPollingTimeoutTimer_u16() = 11;
    *get_rbd_NFCVehIf_EventFlag() = 16;
    call_rbd_NfcIf_TapStartTriggerCyclic();
    EXPECT_EQ(*get_rbd_NFCVehIf_EventFlag(), 0);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].activeState_u8, 16);
    EXPECT_EQ(Dkm_NfcFlow_Start_fake.call_count, 1);
}
/*
@rst
    Brief description of test case.
    :Description: if ( ((uint8)NFC_READER_TAP_START_RFHM_TRIGGER_RX_STATE_E) == session_state_u8 ) ==> FALSE
        rbd_NFCVehIf_TapStartPollingTimeoutTimer_u16 = ( rbd_NFCVehIf_TapStartPollingTimeoutTimer_u16 >= (uint16)NFC_CYCLE_TIME ) ? ( rbd_NFCVehIf_TapStartPollingTimeoutTimer_u16 - NFC_CYCLE_TIME ) : 0u ==> TRUE
        if ( rbd_NFCVehIf_TapStartPollingTimeoutTimer_u16 > 0x00u ) ==> TRUE
        if ( ( NFC_WCPM_NOT_READY_EVENT == ( nfc_ReaderEvtMsg_u16 & NFC_WCPM_NOT_READY_EVENT ) ) ||
				( NFC_WCPM_DEVICEMOVED_EVENT == ( nfc_ReaderEvtMsg_u16 & NFC_WCPM_DEVICEMOVED_EVENT ) ) ||
				( NFC_WCPM_READER_TIMEOUT_EVENT == ( nfc_ReaderEvtMsg_u16 & NFC_WCPM_READER_TIMEOUT_EVENT ) ) ||
				( NFC_WCPM_READER_INVALID_MSG_EVENT == ( nfc_ReaderEvtMsg_u16 & NFC_WCPM_READER_INVALID_MSG_EVENT ) ) ||
				( NFC_WCPM_MULTIDEVICE_PRESENT_EVENT == ( nfc_ReaderEvtMsg_u16 & NFC_WCPM_MULTIDEVICE_PRESENT_EVENT ) ) ) ==> TRUE MCDC(FFTXX)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 288528
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    rbd_NFCVehIf_ReadNFCReaderStatusInfo:
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 288528
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    rbd_NFCVehIf_RegisterNFCReaderSession:
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
        if ( READER_DISCONNECTED == rbd_NFCVehIf_Table_as[NfcReaderId_u8].connectionStatus_u8 ) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 288528
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    rbd_NFCVehIf_UpdateNFCReaderState:
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
        if(NULL != newDevRef_pu8) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 288528
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    rbd_NFCVehIf_ClearEvent:
    :Description: Verifying for the function rbd_NFCVehIf_ClearEvent()
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 288528
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NfcIf_TapStartTriggerCyclic_05)
{
    get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8 = 1;
    get_rbd_NFCVehIf_Table_as()[2].activeState_u8 = 1;
    get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b = 2;
    get_rbd_NFCVehIf_Table_as()[2].session_timeout_u16 = 255;
    *get_rbd_NFCVehIf_TapStartPollingTimeoutTimer_u16() = 11;
    *get_rbd_NFCVehIf_EventFlag() = 64;
    call_rbd_NfcIf_TapStartTriggerCyclic();
    EXPECT_EQ(*get_rbd_NFCVehIf_EventFlag(), 0);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].activeState_u8, 16);
    EXPECT_EQ(Dkm_NfcFlow_Start_fake.call_count, 1);
}
/*
@rst
    Brief description of test case.
    :Description: if ( ((uint8)NFC_READER_TAP_START_RFHM_TRIGGER_RX_STATE_E) == session_state_u8 ) ==> FALSE
        rbd_NFCVehIf_TapStartPollingTimeoutTimer_u16 = ( rbd_NFCVehIf_TapStartPollingTimeoutTimer_u16 >= (uint16)NFC_CYCLE_TIME ) ? ( rbd_NFCVehIf_TapStartPollingTimeoutTimer_u16 - NFC_CYCLE_TIME ) : 0u ==> TRUE
        if ( rbd_NFCVehIf_TapStartPollingTimeoutTimer_u16 > 0x00u ) ==> TRUE
        if ( ( NFC_WCPM_NOT_READY_EVENT == ( nfc_ReaderEvtMsg_u16 & NFC_WCPM_NOT_READY_EVENT ) ) ||
				( NFC_WCPM_DEVICEMOVED_EVENT == ( nfc_ReaderEvtMsg_u16 & NFC_WCPM_DEVICEMOVED_EVENT ) ) ||
				( NFC_WCPM_READER_TIMEOUT_EVENT == ( nfc_ReaderEvtMsg_u16 & NFC_WCPM_READER_TIMEOUT_EVENT ) ) ||
				( NFC_WCPM_READER_INVALID_MSG_EVENT == ( nfc_ReaderEvtMsg_u16 & NFC_WCPM_READER_INVALID_MSG_EVENT ) ) ||
				( NFC_WCPM_MULTIDEVICE_PRESENT_EVENT == ( nfc_ReaderEvtMsg_u16 & NFC_WCPM_MULTIDEVICE_PRESENT_EVENT ) ) ) ==> TRUE MCDC(FFFTX)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 288528
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    rbd_NFCVehIf_ReadNFCReaderStatusInfo:
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 288528
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    rbd_NFCVehIf_RegisterNFCReaderSession:
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
        if ( READER_DISCONNECTED == rbd_NFCVehIf_Table_as[NfcReaderId_u8].connectionStatus_u8 ) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 288528
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    rbd_NFCVehIf_UpdateNFCReaderState:
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
        if(NULL != newDevRef_pu8) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 288528
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    rbd_NFCVehIf_ClearEvent:
    :Description: Verifying for the function rbd_NFCVehIf_ClearEvent()
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 288528
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NfcIf_TapStartTriggerCyclic_06)
{
    get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8 = 1;
    get_rbd_NFCVehIf_Table_as()[2].activeState_u8 = 1;
    get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b = 2;
    get_rbd_NFCVehIf_Table_as()[2].session_timeout_u16 = 255;
    *get_rbd_NFCVehIf_TapStartPollingTimeoutTimer_u16() = 11;
    *get_rbd_NFCVehIf_EventFlag() = 128;
    call_rbd_NfcIf_TapStartTriggerCyclic();
    EXPECT_EQ(*get_rbd_NFCVehIf_EventFlag(), 0);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].activeState_u8, 16);
    EXPECT_EQ(Dkm_NfcFlow_Start_fake.call_count, 1);
}
/*
@rst
    Brief description of test case.
    :Description: if ( ((uint8)NFC_READER_TAP_START_RFHM_TRIGGER_RX_STATE_E) == session_state_u8 ) ==> FALSE
        rbd_NFCVehIf_TapStartPollingTimeoutTimer_u16 = ( rbd_NFCVehIf_TapStartPollingTimeoutTimer_u16 >= (uint16)NFC_CYCLE_TIME ) ? ( rbd_NFCVehIf_TapStartPollingTimeoutTimer_u16 - NFC_CYCLE_TIME ) : 0u ==> TRUE
        if ( rbd_NFCVehIf_TapStartPollingTimeoutTimer_u16 > 0x00u ) ==> TRUE
        if ( ( NFC_WCPM_NOT_READY_EVENT == ( nfc_ReaderEvtMsg_u16 & NFC_WCPM_NOT_READY_EVENT ) ) ||
				( NFC_WCPM_DEVICEMOVED_EVENT == ( nfc_ReaderEvtMsg_u16 & NFC_WCPM_DEVICEMOVED_EVENT ) ) ||
				( NFC_WCPM_READER_TIMEOUT_EVENT == ( nfc_ReaderEvtMsg_u16 & NFC_WCPM_READER_TIMEOUT_EVENT ) ) ||
				( NFC_WCPM_READER_INVALID_MSG_EVENT == ( nfc_ReaderEvtMsg_u16 & NFC_WCPM_READER_INVALID_MSG_EVENT ) ) ||
				( NFC_WCPM_MULTIDEVICE_PRESENT_EVENT == ( nfc_ReaderEvtMsg_u16 & NFC_WCPM_MULTIDEVICE_PRESENT_EVENT ) ) ) ==> TRUE MCDC(FFFFT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 288528
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    rbd_NFCVehIf_ReadNFCReaderStatusInfo:
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 288528
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    rbd_NFCVehIf_RegisterNFCReaderSession:
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
        if ( READER_DISCONNECTED == rbd_NFCVehIf_Table_as[NfcReaderId_u8].connectionStatus_u8 ) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 288528
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    rbd_NFCVehIf_UpdateNFCReaderState:
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
        if(NULL != newDevRef_pu8) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 288528
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    rbd_NFCVehIf_ClearEvent:
    :Description: Verifying for the function rbd_NFCVehIf_ClearEvent()
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 288528
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NfcIf_TapStartTriggerCyclic_07)
{
    get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8 = 1;
    get_rbd_NFCVehIf_Table_as()[2].activeState_u8 = 1;
    get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b = 2;
    get_rbd_NFCVehIf_Table_as()[2].session_timeout_u16 = 255;
    *get_rbd_NFCVehIf_TapStartPollingTimeoutTimer_u16() = 11;
    *get_rbd_NFCVehIf_EventFlag() = 32;
    call_rbd_NfcIf_TapStartTriggerCyclic();
    EXPECT_EQ(*get_rbd_NFCVehIf_EventFlag(), 0);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].activeState_u8, 16);
    EXPECT_EQ(Dkm_NfcFlow_Start_fake.call_count, 1);
}
/*
@rst
    Brief description of test case.
    :Description: if ( ((uint8)NFC_READER_TAP_START_RFHM_TRIGGER_RX_STATE_E) == session_state_u8 ) ==> TRUE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 288528
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    rbd_NFCVehIf_ReadNFCReaderStatusInfo:
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )&& ( NULL != readerConnectState_u8 ) ) ==> TRUE MCDC (TTT)
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 288528
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)

    rbd_NFCVehIf_UpdateNFCReaderState:
    :Description: if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) ) ==> TRUE
        if(NULL != newDevRef_pu8) ==> FALSE
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 288528
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)

    rbd_NFCVehIf_ClearEvent:
    :Description: Verifying for the function rbd_NFCVehIf_ClearEvent()
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 288528
    :Testing Method: Positive
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NfcIf_TapStartTriggerCyclic_08)
{
    get_rbd_NFCVehIf_Table_as()[2].connectionStatus_u8 = 1;
    get_rbd_NFCVehIf_Table_as()[2].activeState_u8 = 24;
    get_rbd_NFCVehIf_Table_as()[2].Key_Card_Ref_b = 2;
    get_rbd_NFCVehIf_Table_as()[2].session_timeout_u16 = 255;
    *get_rbd_NFCVehIf_EventFlag() = 31;
    dummy_RteParameterRefTab.KE_SPAAK_NfcVehicleStartPollingTimer = 11;
    call_rbd_NfcIf_TapStartTriggerCyclic();
    EXPECT_EQ(*get_rbd_NFCVehIf_EventFlag(), 0);
    EXPECT_EQ(get_rbd_NFCVehIf_Table_as()[2].activeState_u8, 16);
    EXPECT_EQ(Dkm_NfcFlow_Start_fake.call_count, 1);
    EXPECT_EQ(*get_rbd_NFCVehIf_TapStartPollingTimeoutTimer_u16(), 11);
}

//----------------------------------------------------------------------------
// Test Cases// static void rbd_NFCVehIf_CardPairingRoutine_Cyclic( void )
//----------------------------------------------------------------------------
/*
@rst
    Brief description of test case.
    :Description: switch ( rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_PLANT_PAIRING_E].DiagRoutine_State_en )
        case NFC_DIAG_ROUTINE_REQUEST_RX_STATE_E:
    :Arch ID: NA
    :REQ ID: NA
    :ALM Task ID: 288528
    :Testing Method: Negative
    :Justifications: Coverage / Bug (NA)
*/
TEST_F(Testrbd_NFCVehIf, testrbd_NFCVehIf_CardPairingRoutine_Cyclic_01)
{

    //call_rbd_NFCVehIf_CardPairingRoutine_Cyclic();

}
