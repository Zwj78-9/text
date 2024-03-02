#include "Can_FileInit.h"
void CAN_FileInit(CAN_HandleTypeDef *hcan)
{
    CAN_FilterTypeDef fileter;
    
    fileter.FilterBank =0;//过滤器编号
    fileter.FilterMode =CAN_FILTERMODE_IDMASK;//模式
    fileter.FilterScale = CAN_FILTERSCALE_32BIT;//也能过滤扩展帧
    
    fileter.FilterIdHigh =0x0000;//什么也不过滤
    fileter.FilterIdLow =0x0000;//~
    fileter.FilterMaskIdHigh =0x0000;//~
    fileter.FilterMaskIdLow =0x0000;//~
    
    fileter.FilterFIFOAssignment =CAN_FILTER_FIFO0;//接收邮箱
    fileter.FilterActivation =ENABLE;//激活过滤器
    
    HAL_CAN_ConfigFilter(hcan,&fileter);//把上面的都用上
}
HAL_StatusTypeDef  CAN_Sent(CAN_HandleTypeDef *hcan,uint32_t StdId,uint8_t *msg)//发送函数
{
    CAN_TxHeaderTypeDef CAN_tx ={
        .StdId = StdId,//指定标准标识符。
        .ExtId = 0,//不用扩展帧
        .IDE =CAN_ID_STD,//标准帧
        .RTR =CAN_RTR_DATA,//数据帧
        .DLC =8,//发送的数据长度
        .TransmitGlobalTime  =ENABLE//启用
    };//发送句柄
    uint32_t Txmailbox =0;
    HAL_StatusTypeDef err = HAL_CAN_AddTxMessage(hcan,&CAN_tx,msg,&Txmailbox);
    return err;
}
