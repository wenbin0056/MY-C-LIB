


#include <stdio.h>



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
	
}PresemtatopmPackT;

typedef enum
{
	USER_MASTER_CMD_READY,
	USER_MASTER_CMD_GETDATA,
	USER_MASTER_CMD_SENDCMD_CMD1,
	USER_MASTER_CMD_SENDCMD_CMD2,	
	USER_MASTER_CMD_SENDCMD_CMD3,		
		
}USER_MASTER_CMD;




typedef enum
{
}MASTER_CMD;

//======================USER SAMPLE==============================
int USER_SAMPLE_FUN()
{
	int ret = 0;
	
	ret = COMMUTION_WB_init(APP_ID_1);
	if(ret != 0)
	{
		printf("err %s:%d\n",__func__, __LINE__);
		return -1;
	}

	
	
	
}

//============================================================
int COMMUTION_WB_init(APP_ID_E appID)
{
	
}


//======================PRESENTATION LAYER=====================

int PRESENTATION_recvPack()
{
	
}

int PRESENTATION_sendPack()
{
	
}



//======================SESSION LAYER=====================




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
