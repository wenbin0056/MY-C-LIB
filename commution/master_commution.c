


#include <stdio.h>
#include "commution_common.h"




typedef enum
{
	USER_CMD_SENDDATA,
	USER_CMD_REQUIREDATA,

	USER_CMD_MAX,			
		
}USER_CMD_E;




//======================USER SAMPLE==============================
int USER_SAMPLE_FUN(APP_ID_E appId)
{
	int ret = 0;
	
	ret = COMMUTION_WB_init(appId);
	if(ret != 0)
	{
		printf("err %s:%d\n",__func__, __LINE__);
		return -1;
	}
	unsigned char tx_buff[128] = {0};
	unsigned int tx_len = 128;
	unsigned char rx_buff[128] = {0};
	unsigned int rx_len = 128;

	PRESENTATION_sendPack(appId,USER_CMD_SENDDATA, tx_buff, tx_len, rx_buff, rx_len);
	
	return ret;
}

//============================================================


static CommutionStructT  CommutionStruct;

int COMMUTION_WB_init(APP_ID_E appID)
{
	if(appID > APP_ID_MAX)
	{
		printf("param err %s:%d\n",__func__, __LINE__);
		return -1;
	}

	CommutionStruct.pTxBuff[appID] = malloc(MAX_TX_BUFF_SIZE);
	if(!CommutionStruct.pTxBuff[appID)
	{
		printf("malloc err %s:%d\n",__func__, __LINE__);
		return -1;		
	}

	CommutionStruct.pRxBuff[appID] = malloc(MAX_RX_BUFF_SIZE);	
	if(!CommutionStruct.pTxBuff[appID)
	{
		printf("malloc err %s:%d\n",__func__, __LINE__);
		return -1;		
	}	

	CommutionStruct.TxBuffLen[appID] = 0;
	CommutionStruct.RxBuffLen[appID] = 0;
	CommutionStruct.CurrentLayer[appID] = COMMUTION_LAYER_USER;
	CommutionStruct.bInit[appID] = 1;	

	return 0;
}

int COMMUTION_WB_deInit(APP_ID_E appID)
{
	if(appID > APP_ID_MAX)
	{
		printf("param err %s:%d\n",__func__, __LINE__);
		return -1;
	}

	free(CommutionStruct.pTxBuff[appID]);
	free(CommutionStruct.pRxBuff[appID]);
	CommutionStruct.bInit[appID] = 0;	

	return 0;
}


//======================PRESENTATION LAYER=====================

int PRESENTATION_recvPack()
{
	
}

int PRESENTATION_sendPack(APP_ID_E appId, USER_CMD_E cmdID, unsigned char *SendBuff, unsigned int SbuffLen, unsigned char *RxBuff,unsigned int RbuffLen)
{
	
	
	return 0;
}



//======================SESSION LAYER=====================

int SESSION_recvPack()
{
	
}

int SESSION_sendPack(APP_ID_E appId, USER_CMD_E cmdID, unsigned char *SendBuff, unsigned int SbuffLen, unsigned char *RxBuff,unsigned int RbuffLen)
{
	
	
	return 0;
}




//======================TRANSPORT LAYER=====================




//======================DATA LIN LAYER=====================
// send frame by frame, if slave respond err, send again.
// control bit flow 
int DATA_LINK_sendFrame()
{
	
}


int DATA_LINK_sendAck()
{
	
}

int DATA_LINK_RecvFrame()
{
	
}

int DATA_LINK_recvAck()
{
	
}



//======================PHY LAYER=====================

int Phy_send_data(char *pbuff, unsigned int size)
{
	
}

int Phy_recv_data(char *pbuff, unsigned int size)
{
	
}
