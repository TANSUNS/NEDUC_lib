/**
 * @file PID.h  
 * @author Richard_Tang     
 * @brief 
 * @version 0.1
 * @date 2019-01-04
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef __PID_H__
#define __PID_H__
#include <stdio.h>
/**
 * @brief Define the PID Controler's Type
 * Alter: float,int,double,uint8_t...
 * 
 */
#define TEMPLETE float

/**
 * @brief compare the float num with 0
 * 
 */
#define EPS 0.000001


/**
 * @brief Out put the setting info ,and this only can used when TEMPLETE is uint8_t uint32_t....
 *        can not be used when TEMPLETE is float and double.
 * 
 */
#define PID_DEBUG

/**
 * @brief out put the value outputvalue and error 
 * 
 */
#define PID_PARAM_SETTING

#ifdef PID_DEBUG
    /**
     * @brief setting the output func
     * 
     */
    #define pid_debug printf
#endif //PID

/**
 * @brief Datastructure of pid controler
 * 
 */
typedef struct
{
    TEMPLETE kp;
    TEMPLETE ki;
    TEMPLETE kd;

    TEMPLETE target_point;
    TEMPLETE this_error;
    TEMPLETE last_error;
    TEMPLETE pre_error;

    TEMPLETE max;
    TEMPLETE min;
    
}pid;


static TEMPLETE pid_abs(TEMPLETE num);

/**
 * @brief init the pid controler    
 * 
 * @param controler  a pointer of pid controler
 * @param p  kp
 * @param i ki
 * @param d kd
 * @param Max the maxium output
 * @param Min  the minium output
 */
extern void pid_init(pid *controler,TEMPLETE p,TEMPLETE i,TEMPLETE d,TEMPLETE Max,TEMPLETE Min);

/**
 * @brief set the target point of pid controler
 *  
 * @param controler the pointer of pid controler 
 * @param target the value of target point
 * @return uint8_t  1 set success
 *                 -1 error
 */
extern int pid_set(pid *controler,TEMPLETE target);

/**
 * @brief pid caculation
 * 
 * @param controler the pointer of pid controler
 * @param value the current value
 * @return TEMPLETE the output of pid controler (Normalized)
 */
extern TEMPLETE pid_cal(pid *controler,TEMPLETE value);

#endif