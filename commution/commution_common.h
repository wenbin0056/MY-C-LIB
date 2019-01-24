

#ifndef __COMMUTION_COMMON_H__
#define __COMMUTION_COMMON_H__

#define BYTE0(appId)	(appId)&0xff
#define BYTE1(appId)	(appId>>8)&0xff

typedef struct
{
	APP_ID_1,
	APP_ID_2,
	APP_ID_3,
	APP_ID_4,	
	
	APP_ID_MAX,	

	
}APP_ID_E;




typedef struct
{
	unsigned char CmdID;

};


typedef struct
{
	
}PresemtatopmPackT;

typedef enum
{
	//CMD_ID_WHIOUT_DATA
	USER_CMD_ID_START_WORK,
	USER_CMD_ID_STOP_WORK,		
	USER_CMD_ID_RESET,

	//
	USER_CMD_SENDDATA,

	//
	USER_CMD_REQUIRE_SLAVE_MACHINE_STATE,

	USER_CMD_MAX,			
		
}USER_CMD_E;


typedef enum 
{
	MACHINE_STATE_RUNNING,
	MACHINE_STATE_SLEEP,

	MACHINE_STATE_MAX,
	
}E_MACHINE_STATE;

typedef struct 
{
		
}SLAVE_MACHINE_STATE_T;


typedef enum
{

}MASTER_CMD;

typedef enum
{
	COMMUTION_LAYER_USER,
	COMMUTION_LAYER_PRESENTATION,
	COMMUTION_LAYER_SESSION,
	COMMUTION_LAYER_TRANSPORT,
	COMMUTION_LAYER_DATALIN,	
	COMMUTION_LAYER_PHY,

	COMMUTION_LAYER_MAX,	
	
}COMMUTION_LAYER_E;

#define MAX_APPID 10
#define MAX_TX_BUFF_SIZE	1024
#define MAX_RX_BUFF_SIZE	1024

typedef struct
{
	unsigned short AppID;
	unsigned short SessionID;
	unsigned short PackCmdID;
	
}PACK_HEADER_T;

typedef struct 
{
	
}ARK_PACK_T;


typedef struct 
{
	unsigned char bInit[MAX_APPID];
	unsigned char CurrentLayer[MAX_APPID];	
	PACK_HEADER_T TxpackHeader[MAX_APPID];
	unsigned char *pTxBuff[MAX_APPID];
	unsigned int TxBuffLen[MAX_APPID];	
	PACK_HEADER_T RxpackHeader[MAX_APPID];		
	unsigned char *pRxBuff[MAX_APPID];
	unsigned int RxBuffLen[MAX_APPID];	

	unsigned char *pRxTempBuff;
	unsigned char *pTxTempBuff;
	unsigned short RxTempBuffLen;
	unsigned short TxTempBuffLen;
	unsigned char bTempBuffInit;	

	ARK_PACK_T RxAckPack[MAX_APPID];
	ARK_PACK_T TxAckPack[MAX_APPID];	
	
}CommutionStructT;






#endif/* __COMMUTION_COMMON_H__ */

