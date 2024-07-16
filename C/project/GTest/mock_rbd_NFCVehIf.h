//mock_header
// COPYRIGHT RESERVED, 2022 Robert Bosch (Australia) Pty Ltd.
// All rights reserved.  The reproduction, distribution and utilisation of
// this document as well as the communication of its contents to others
// without explicit authorisation is prohibited.  Offenders will be held liable
// for the payment of damages.  All rights reserved in the event of the grant
// of a patent, utility model or design.
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
//! \file
//! \brief Mocked function declarations for the rbd_NFCVehIf module
//!
//----------------------------------------------------------------------------
#ifndef MOCK_RBD_NFCVEHLF_H
#define MOCK_RBD_NFCVEHLF_H
//============================================================================
// Include Files
//===========================================================================
//#include "<MODULE HEADER>"
#include "fff.h"
#include <string.h>
#include "Rte_Compiler_Cfg.h"
#include "rbd_Pk_Types.h"
#include "rbd_NFCVehIf.h"
#include "Rte_rbd_NFCVehIf_Type.h"
#include "rbdSessionMgr_Types.h"
#include "rbd_RfhmIf.h"
#include "Rte.h"
#include "Com_Types.h"
#include "Rte_Type.h"
#include "Rte_rbd_NFCVehIf.h"
uint8 data1_memcpy[31];
#define memcpy gtest_para_memcpy
void * gtest_para_memcpy(void* param_1, const void* param_2,size_t param_3);

# define Rte_TypeDef_NFC_READER_FLDHM_DEVICE_Sig
typedef uint8 NFC_READER_FLDHM_DEVICE_Sig[261];

typedef struct
{
	uint8 mock_reqRetryCount_u8;			/*!< Deselect Request Retry count in case of failure */
	uint8 mock_uRetryFinish_u8;   		/*!< Max attempts Reached */
	uint8 mock_typeDeselect_u8;			/*!< Deselect Type */
	NfcEcuIds mock_nfcReaderId_en;		/*!< NFC ReaderId */
	uint16 mock_retryTimer_u32;

}mock_nfcReaderDeselectInfo_t;

typedef struct
{
	uint8 nfcCardIdx;									/* 1 byte of cardIndex 			*/
	Rte_DT_rbdCdsTypes_NfcCardDat_st_1 nfcCardUid;		/* 7 bytes of UID 				*/
	sha1HashCetH keyIdentifier;							/* 20 bytes of keyIdentifier    */
	Rte_DT_rbdCdsTypes_KeyInfo_st_5 keyFriendlyName;	/* 30 bytes of key name 		*/
	Rte_DT_rbdCdsTypes_NfcCardDat_st_2 nfcCardSerNum;	/* 15 bytes of Serial Number 	*/
}nfcCard_Did5608_Info;

typedef struct
{
	uint8 mock_cmdId_u8;			 	/*!< Command Id */
	uint8 mock_rxEcu_u8;				/*!< Receiver ECU */
	uint8 mock_txEcu_u8;				/*!< Transmitter ECU */
	uint16 mock_payloadLength_u16;	/*!< Payload Length */
}mock_nfcReaderResponseHeader_t;

typedef enum
{
	/** @brief Routine Init State */
	mock_NFC_DIAG_ROUTINE_INIT_STATE_E,
	/** @brief Routine Request Received State */
	mock_NFC_DIAG_ROUTINE_REQUEST_RX_STATE_E,
	/** @brief Routine State FD9 Bus Active */
	mock_NFC_DIAG_ROUTINE_FD9_ACTIVE_STATE_E,
	/** @brief Routine State -Routine in Running State */
	mock_NFC_DIAG_ROUTINE_RUNNING_STATE_E,
	/** @brief Routine State FD9 Bus Not Active */
	mock_NFC_DIAG_ROUTINE_FD9_DEINIT_STATE_E,
}mock_NfcVehIf_DiagRoutineStates_EN_TYPE;
typedef struct
{
	uint8 mock_nfcRoutineStatus;			/*!< 1 byte of cardIndex 			*/
	uint8 mock_nfcRoutineErrorCode;		/*!< 7 bytes of UID 				*/
	uint8 mock_nfcRoutineKeyRef;			/*!< Store the Key Ref if required */
	mock_NfcVehIf_DiagRoutineStates_EN_TYPE mock_DiagRoutine_State_en;	/*!< Routine State */
	/*AXIVION Disable MisraC2012-19.2: The union members nfcRoutineUId and nfcRoutineSerialNumber are not used the same time */
	union
	{
			uint8 mock_nfcRoutineUId[NFC_CARD_UID_LEN];	/*!< Card UID of the Routine in process */
			uint8 mock_nfcRoutineSerialNumber[NFC_SERIAL_LEN];	/*!< Card Serial Number of the Routine in process */
	}mock_nfcCardData_t;
}mock_nfcRoutines_Info_t;

//============================================================================
// Mock function declarations
//============================================================================
//DECLARE_FAKE_VALUE_FUNC(<RETURN TYPE>, <FUNCTION NAME>, <ARG0 TYPE>, ...);
DECLARE_FAKE_VOID_FUNC(rbdSessionMgr_NfcDisconnected,const rbdPk_NfcReaderId_t);
DECLARE_FAKE_VALUE_FUNC(uint8,rbdSessionMgr_GetCardPairingReqResult);
DECLARE_FAKE_VOID_FUNC(rbdSessionMgr_initCardPairingTest,const rbdPk_NfcReaderId_t);
DECLARE_FAKE_VALUE_FUNC(rbdSessionMgr_Status_et,rbdSessionMgr_ProcessNfcMsg,const rbdPk_NfcReaderId_t, const uint16, const uint8*);
DECLARE_FAKE_VOID_FUNC(rbd_RfhmIf_SendNfcToggleReq,const uint8, const uint8, const rbdPk_KeyRef_t);
DECLARE_FAKE_VALUE_FUNC(rbdSessionMgr_Status_et,rbdSessionMgr_NfcReady,const rbdPk_NfcReaderId_t);
DECLARE_FAKE_VALUE_FUNC(rbdSessionMgr_Status_et,rbdSessionMgr_GetDkAccessProfile,rbdPk_KeyRef_t const, uint8*);
DECLARE_FAKE_VALUE_FUNC(rbdSessionMgr_Status_et,rbdSessionMgr_GetKeyRefByNfcReaderId,const rbdPk_NfcReaderId_t, uint8* const);
DECLARE_FAKE_VOID_FUNC(rbdSessionMgr_NfcConnected,const rbdPk_NfcReaderId_t, const bool, const rbdPk_NfcDevicetype_t);
DECLARE_FAKE_VALUE_FUNC(FUNC(Std_ReturnType, RTE_CODE),Rte_Write_rbd_NFCVehIf_rbd_NFCVehIf_NFC_PhoneKeyPariring_Result_NFCPhoneKeyPariring_Result,NFC_PhoneKeyPariring_Result);
DECLARE_FAKE_VALUE_FUNC(rbdSessionMgr_Status_et, rbdSessionMgr_ProvisionCert_Async,uint8 const*, uint8* const, uint16_t);
DECLARE_FAKE_VOID_FUNC(rbd_RfhmIf_SendAuthStatus, boolean, const uint8 *, const uint8 * );
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
DECLARE_FAKE_VALUE_FUNC(FUNC(Std_ReturnType, RTE_CODE),Rte_Send_rbd_NFCVehIf_NFC_READER_REQ_FLDHM_Sig_NFC_READER_DEVICE_2_Sig,P2CONST(uint8, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_DATA), uint16);
# else
DECLARE_FAKE_VALUE_FUNC(FUNC(Std_ReturnType, RTE_CODE),Rte_Send_rbd_NFCVehIf_NFC_READER_REQ_FLDHM_Sig_NFC_READER_DEVICE_2_Sig,P2CONST(uint8, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_DATA), uint16);
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
DECLARE_FAKE_VALUE_FUNC(FUNC(Std_ReturnType, RTE_CODE),Rte_Send_rbd_NFCVehIf_NFC_READER_REQ_FRDHM_Sig_NFC_READER_DEVICE_3_Sig,P2CONST(uint8, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_DATA), uint16);
# else
DECLARE_FAKE_VALUE_FUNC(FUNC(Std_ReturnType, RTE_CODE),Rte_Send_rbd_NFCVehIf_NFC_READER_REQ_FRDHM_Sig_NFC_READER_DEVICE_3_Sig,P2CONST(uint8, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_DATA), uint16);
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
DECLARE_FAKE_VALUE_FUNC(FUNC(Std_ReturnType, RTE_CODE),Rte_Send_rbd_NFCVehIf_NFC_READER_REQ_WCPM2_Sig_NFC_READER_DEVICE_1_Sig,P2CONST(uint8, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_DATA), uint16);
# else
DECLARE_FAKE_VALUE_FUNC(FUNC(Std_ReturnType, RTE_CODE),Rte_Send_rbd_NFCVehIf_NFC_READER_REQ_WCPM2_Sig_NFC_READER_DEVICE_1_Sig,P2CONST(uint8, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_DATA), uint16);
# endif
DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, rbdSessionMgr_startNFCCardPairing,const rbdPk_NfcReaderId_t, const uint16, const uint8*);
// DECLARE_FAKE_VALUE_FUNC(rbdSessionMgr_Status_et, rbdSessionMgr_ProvisionCert_Async,uint8 const* ,uint8 const* ,uint16_t );

#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
DECLARE_FAKE_VALUE_FUNC(FUNC(Std_ReturnType, RTE_CODE),Rte_Receive_rbd_NFCVehIf_NFC_READER_FLDHM_RES_Sig_NFC_READER_FLDHM_DEVICE_Sig,P2VAR(uint8, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR), P2VAR(uint16, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR));
# else
DECLARE_FAKE_VALUE_FUNC(FUNC(Std_ReturnType, RTE_CODE),Rte_Receive_rbd_NFCVehIf_NFC_READER_FLDHM_RES_Sig_NFC_READER_FLDHM_DEVICE_Sig,P2VAR(uint8, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR), P2VAR(uint16, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR));
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
DECLARE_FAKE_VALUE_FUNC(FUNC(Std_ReturnType, RTE_CODE),Rte_Receive_rbd_NFCVehIf_NFC_READER_FRDHM_RES_Sig_NFC_READER_FRDHM_DEVICE_Sig,P2VAR(uint8, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR), P2VAR(uint16, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR));
# else
DECLARE_FAKE_VALUE_FUNC(FUNC(Std_ReturnType, RTE_CODE),Rte_Receive_rbd_NFCVehIf_NFC_READER_FRDHM_RES_Sig_NFC_READER_FRDHM_DEVICE_Sig,P2VAR(uint8, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR), P2VAR(uint16, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR));
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
DECLARE_FAKE_VALUE_FUNC(FUNC(Std_ReturnType, RTE_CODE),Rte_Receive_rbd_NFCVehIf_NFC_READER_WCPM2_RES_Sig_NFC_READER_WCPM2_DEVICE_Sig,P2VAR(uint8, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR), P2VAR(uint16, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR));
# else
DECLARE_FAKE_VALUE_FUNC(FUNC(Std_ReturnType, RTE_CODE),Rte_Receive_rbd_NFCVehIf_NFC_READER_WCPM2_RES_Sig_NFC_READER_WCPM2_DEVICE_Sig,P2VAR(uint8, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR), P2VAR(uint16, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR));
# endif

DECLARE_FAKE_VALUE_FUNC(FUNC(uint8, COM_CODE),Com_ReceiveSignal,Com_SignalIdType , P2VAR(void, AUTOMATIC, COM_APPL_VAR) );
DECLARE_FAKE_VOID_FUNC(rbd_RfhmIf_ControlFd9Bus,boolean );
DECLARE_FAKE_VALUE_FUNC(FUNC(Std_ReturnType, rbdDkmRteWrapper_CODE),Dkm_NfcFlow_Start,VAR(rbdPk_NfcReaderId_t, AUTOMATIC) , VAR(Dkm_OperationType_en, AUTOMATIC) , VAR(Dkm_DataFieldTag_en, AUTOMATIC) , VAR(uint8, AUTOMATIC) , VAR(uint16, AUTOMATIC) , VAR(Dkm_transactioncode_en, AUTOMATIC) , P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) , P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) );
DECLARE_FAKE_VALUE_FUNC(FUNC(Std_ReturnType, RTE_RBDDKMRTEWRAPPER_APPL_CODE),Dkm_GetKeyInfoDevice_Operation,IDT_KeyRef , P2VAR(rbdCdsTypes_KeyInfo_st, AUTOMATIC, RTE_RBDDKMRTEWRAPPER_APPL_VAR) );
DECLARE_FAKE_VALUE_FUNC(FUNC(Std_ReturnType, RTE_NVM_APPL_CODE),NvM_WriteBlock,NvM_BlockIdType , dtRef_const_VOID );
DECLARE_FAKE_VOID_FUNC(rbd_RfhmIf_ControlFd1Bus,boolean );
DECLARE_FAKE_VALUE_FUNC(FUNC(Std_ReturnType, RTE_RBDDKMRTEWRAPPER_APPL_CODE),Dkm_DeviceMgr_GetStatus_Operation,P2VAR(uint16, AUTOMATIC, RTE_RBDDKMRTEWRAPPER_APPL_VAR) );
DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,Dkm_GetNumberOfKeyEntries_Operation,rbdCdsTypes_DeviceType_en , uint8* , uint32 , uint8* );
//DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,Dkm_GetKeyInfoCard_Operation,uint8 , rbdCdsTypes_KeyInfo_st* );
DECLARE_FAKE_VALUE_FUNC(FUNC(Std_ReturnType, RTE_RBDDKMRTEWRAPPER_APPL_CODE), Dkm_GetKeyInfoCard_Operation, uint8, P2VAR(rbdCdsTypes_KeyInfo_st, AUTOMATIC, RTE_RBDDKMRTEWRAPPER_APPL_VAR));
DECLARE_FAKE_VALUE_FUNC(Std_ReturnType,rbdDeviceMgr_GetStatus,uint16_t* );
DECLARE_FAKE_VOID_FUNC(rbd_VSM_WcpKeyAuthResult_Cbk, uint8, IDT_ConstUint8Ptr);
DECLARE_FAKE_VALUE_FUNC(FUNC(Std_ReturnType, RTE_CODE), Rte_Read_rbd_NFCVehIf_RP_AuthenticTimeManagementStatus_UtcTime, P2VAR(uint64, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR) );
DECLARE_FAKE_VALUE_FUNC(FUNC(Std_ReturnType, RTE_RBD_BACKENDIF_APPL_CODE), rbd_BackendIf_BackendKeyStatusUpdate_Cbk, IDT_BackendKeyStatusUpdate , P2CONST(uint8, AUTOMATIC, RTE_RBD_BACKENDIF_APPL_DATA) );
DECLARE_FAKE_VALUE_FUNC(FUNC(Std_ReturnType, RTE_DEMSATELLITE_APP_COREA_SM_P1_APPL_CODE), Dem_SetEventStatus, Dem_EventIdType , Dem_EventStatusType );
DECLARE_FAKE_VALUE_FUNC(FUNC(Std_ReturnType, RTE_CODE),Rte_Read_rbd_NFCVehIf_RP_drmServices_drmServices,P2VAR(drmServices_Type, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR) );
//============================================================================
// Static variable getter function declarations
//============================================================================
//<VAR TYPE> *const get_<VAR NAME>(void);
mock_nfcReaderDeselectInfo_t *const get_rbd_NFCVehIf_DeselectInfo_S(void);
nfcTagTableType *const get_rbd_NFCVehIf_Table_as(void);
// boolean *const get_rbd_NFCVehIf_NfcCardTimerIsActive_b(void);Code removed
// nfcCardPairDataType *const get_rbd_NFCVehIf_CardData_st(void);Code removed
uint16 *const get_rbd_NFCVehIf_NfcCardTimer_u16(void);
// uint8 *const get_rbd_NFCVehIf_NfcCardDefaultUid_au8(void);Code removed
// nfcCardPairReqType *const get_rbd_NFCVehIf_CardPairReq_st(void);Code removed
NFC_READER_DEVICE_1_Sig *const get_rbd_NFCVehIf_Request_au8(void);
uint8 *const get_rbd_NFCVehIf_NfcCardSuccessUid_au8(void);
uint8 *const get_triggerNfcCardPairStart(void);
rbdCdsTypes_KeyInfo_st *const get_keyInfo_S(void);
// boolean *const get_rbd_NFCVehIf_getUID_active_b(void);Code removed
uint8 *const get_keyCardRef_paried_u8(void);
nfcCard_Did5608_Info *const get_rbd_NFCVehIf_Did5608Info(void);
uint8 *const get_rbd_NFCVehIf_CardIndex(void);
uint16 *const get_rbd_NFCVehIf_DTCWCPMTimer_u16(void);
boolean *const get_rbd_NFCVehIf_DTCWCMP2Timer_active_b(void);
uint16 *const get_rbd_NFCVehIf_PollingTimeoutTimer_u16(void);
uint16 *const get_rbd_NFCVehIf_TapStartPollingTimeoutTimer_u16(void);
mock_nfcRoutines_Info_t *const get_rbd_NFCVehIf_RoutineData_S(void);
uint16 *const get_rbd_NFCVehIf_EventFlag(void);
uint8 *const get_rbd_NFCVehIf_NFC_Count(void);
//============================================================================
// Static function wrapper declarations
//============================================================================
//<RETURN TYPE> call_<FUNCTION NAME>(<ARG0>, ...);

void call_rbd_NFCVehIf_Cyclic(void);
FUNC(Std_ReturnType, rbd_NFCVehIf_CODE) call_rbd_NFCVehIf_GetNfcUID_Start_Start(P2VAR(uint8, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR) ErrorCode);
FUNC(void, rbd_NFCVehIf_CODE) call_rbd_NFCVehIf_Init(void);
FUNC(Std_ReturnType, rbd_NFCVehIf_CODE) call_rbd_NFCVehIf_NFC_Card_Pairing_Start_RequestResults(P2VAR(uint8, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR) ErrorCode);
FUNC(Std_ReturnType, rbd_NFCVehIf_CODE) call_rbd_NFCVehIf_NFC_Card_Pairing_Start_Start(P2CONST(uint8, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_DATA) In_ReqData, uint8 serialNumLen_u8, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR) ErrorCode) ;
FUNC(Std_ReturnType, rbd_NFCVehIf_CODE) call_rbd_NFCVehIf_NFC_Card_Serial_Number_Read_Operation(P2VAR(uint8, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR) Data);
FUNC(void, rbd_NFCVehIf_CODE) call_rbd_NFCVehIf_NFC_READER_FLDHM_DEVICE_Sig_Callback(void);
FUNC(void, rbd_NFCVehIf_CODE) call_rbd_NFCVehIf_NFC_READER_FRDHM_DEVICE_Sig_Callback(void);
FUNC(void, rbd_NFCVehIf_CODE) call_rbd_NFCVehIf_NFC_READER_WCPM2_DEVICE_Sig_Callback(void);
FUNC(Std_ReturnType, rbd_NFCVehIf_CODE) call_rbd_NFCVehIf_Test_SmartCard_Pairing_Start_RequestResults(P2VAR(uint8, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR) ErrorCode);
FUNC(Std_ReturnType, rbd_NFCVehIf_CODE) call_rbd_NFCVehIf_Test_SmartCard_Pairing_Start_Start(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR) ErrorCode);
void call_rbd_NFCVehIf_PrepNFCBuffer(uint8 *request_pt, const uint8 comId_u8, const uint8 dest_u8, const uint16 payLen_u16, const uint8* payload_pt);
Std_ReturnType call_rbd_NFCVehIf_WritePort(const uint8 dest_u8, const uint8 *request_pt, const uint16 length_u16);
uint8 call_rbd_NFCVehIf_MapCCCToNFC(const uint16 cccCommandId_u16);
void call_rbd_NFCVehIf_SetOwnerPairingMode(boolean const Enable);
void call_rbd_NFCVehIf_NfcTeardown(const rbdPk_NfcReaderId_t nfcReaderId);
boolean call_rbd_NFCVehIf_SendNfcMsg(const rbdPk_NfcReaderId_t nfcReaderId, const uint16 Length, const uint8* const Data);
void call_rbd_NFCVehIf_ReceiveNFCResponse(const uint8 *nfcResponse_pt, const uint16 nfcResponseLength_u16);
void call_rbd_NFCVehIf_ProcessCCCResponse(const uint8 *nfcResponse_pt);
void call_rbd_NFCVehIf_DkmStartPolling(const rbdPk_NfcReaderId_t nfcReaderId, const uint8* const DigitalKeyFrameworkId);
Std_ReturnType call_rbd_NFCVehIf_NfcFlow_NotifyAuthStatus(rbdPk_NfcReaderId_t ReaderId, Dkm_CccAuthStatus_en* CccAuthStatus, uint8 * DeviceRef);
void call_rbd_NFCVehIf_NfcFlow_FLDHM_AuthNotification(Dkm_CccAuthStatus_en Dkm_AuthStatus_en, uint8 DevRef_u8);
void call_rbd_NFCVehIf_NfcFlow_WCPM2_AuthNotification(Dkm_CccAuthStatus_en Dkm_AuthStatus_en, uint8 DevRef_u8);
FUNC(void, rbd_NFCVehIf_CODE) call_rbd_NFCVehIf_SendStopTrigger(void);
void call_rbd_NfcIf_NfcTapThread(void);
uint8 call_rbd_NFCVehIf_ResetNFCReaderSessionTag( const uint8 NfcReaderId_u8 );
uint8 call_rbd_NFCVehIf_RegisterNFCReaderSession( const uint8 NfcReaderId_u8 );
uint8 call_rbd_NFCVehIf_UpdateNFCReaderState( const uint8 NfcReaderId_u8, const uint8 newState_u8, const uint8 * newDevRef_pu8);
void call_rbd_NFCVehIf_ReadNFCReaderStatusInfo( const uint8 NfcReaderId_u8,uint8 *sessionState_u8, uint8 *readerConnectState_u8, uint8 *deviceRef_u8 );
FUNC(Std_ReturnType, rbd_NFCVehIf_CODE) call_rbd_NFCVehIf_GetNfcUID_Start_RequestResults(P2VAR(uint8, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR) ErrorCode);
FUNC(void, rbd_NFCVehIf_CODE) call_rbd_NFCVehIf_ToggleOperationFinished(void);
FUNC(void, rbd_NFCVehIf_CODE) call_rbd_NFCVehIf_SendStartTrigger(void);
FUNC(Std_ReturnType, rbd_NFCVehIf_CODE) call_rbd_NFCVehIf_NFC_Card_Serial_Number_Read_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR) ErrorCode);
void call_rbd_NFCVehIf_UpdateNFCReaderSessionTimeOut( const uint8 NfcReaderId_u8, const uint16 sessionTout_u16);
void call_rbd_NFCVehIf_NFCReaderSessionTimeOutManager(void);
FUNC(Std_ReturnType, rbd_NFCVehIf_CODE) call_rbd_NFCVehIf_WcpKeyAuthReq_Cbk(void);
void call_rbd_NfcIf_NfcReaderCanTPPacketHeaderRead(const uint8 * packetDataIn, mock_nfcReaderResponseHeader_t * nfcReaderDataHeader_ps);
void call_rbd_NfcIf_NfcReaderCanTPPacketHeaderWrite(uint8 * packetDataOut, const mock_nfcReaderResponseHeader_t *  nfcReaderDataHeader_ps);
// void call_rbd_NFCVehIf_checkDkmCardPairingRequest( void );Code removed
void call_rbd_NFCVehIf_DTC(void);
uint8 call_rbd_NFCVehIf_IsRoutineInProgress(void);
void call_rbd_NfcIf_TapStartTriggerCyclic(void);
void call_rbd_NFCVehIf_CardPairingRoutine_Cyclic(void);

#endif //
