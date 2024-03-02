#ifndef _CAN_FILEINIT_H
#define _CAN_FILEINIT_H
#include "main.h"
#include "can.h"

void CAN_FileInit(CAN_HandleTypeDef *hcan);
HAL_StatusTypeDef  CAN_Sent(CAN_HandleTypeDef *hcan,uint32_t StdId,uint8_t *msg);

#endif
