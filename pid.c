#include "pid.h"

TEMPLETE pid_abs(TEMPLETE num)
{
    if(num >=EPS)
    {
        return num;
    }
    else
    {
        return -num;
    }
}

 void pid_init(pid *controler,TEMPLETE p,TEMPLETE i,TEMPLETE d,TEMPLETE Max,TEMPLETE Min)
{

    controler->kp = p;
    controler->ki = i;
    controler->kd = d;

    controler->max = Max;
    controler->min = Min;

    controler->target_point = 0;
    controler->this_error = 0;
    controler->last_error = 0;
    controler->pre_error = 0;

	#ifdef PID_DEBUG
    pid_debug("The controler param is:\n");
    pid_debug(" kp:%f\n ki:%f\n kd:%f\n max:%f\n min:%f\n target:%f\n this_error:%f\n last_error:%f\n pre_error:%f\n ",
    controler->kp, 
    controler->ki, 
    controler->kd,
    controler->max,
    controler->min,
    controler->target_point,
    controler->this_error,
    controler->last_error,
    controler->pre_error);
		#endif
}

int pid_set(pid *controler,TEMPLETE target)
{
    controler->target_point=target;
    
    if(controler ->target_point!=target)
    {
				#ifdef PID_DEBUG
        pid_debug("pid target setting error:\n");
        pid_debug("error with target:%f\n", controler->target_point);
				#endif
        return -1;
    }
		
      	#ifdef PID_DEBUG
        pid_debug("pid target:%f\n", controler->target_point);
		    #endif
    return 1;

}

TEMPLETE pid_cal(pid *controler,TEMPLETE value)
{
    double output;

    controler->this_error = controler->target_point - value;
    
    
	output = controler->kp*((controler->this_error) - (controler->last_error))+ \
		(controler->ki)*(controler->this_error )+\
		(controler->kd)*((controler->this_error) - 2 * (controler->last_error)+ (controler->pre_error));

    controler->pre_error =controler->last_error;
    controler->last_error = controler ->this_error;

	if (output >= controler->max)
	{
		output = controler->max;
	}
	if (output <= controler->min)
	{
		output = controler->min;
	}
    #ifdef PID_DEBUG
        pid_debug(" Output:%f\n Error:%f\n LastError:%f\n PreError:%f\n",output,controler->this_error,controler->last_error, controler->pre_error);
    #endif //PID_DEBUG

    #ifdef PID_PARAM_SETTING
    pid_debug("%f,%f,%f,%f\n",controler->this_error,output, controler->target_point,value);
    #endif //PID_PARAM_SETTI

    return output;

}
