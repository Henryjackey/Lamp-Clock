#include "tim.h"
#include "buzzer.h"


void music_tone(int *music_scale)//øÿ÷∆“Ùµ˜∫Ø ˝
{
	
	__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, music_scale[tone]); 
	
}


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)//≈–∂œΩ⁄≈ƒ
{
  if(htim->Instance == htim3.Instance)
	{
		if(type!=0)
		{
			beat_time+=1;
			if(beat_time==music_t[num_m])
			{
				beat_time=0;
			}else
			{
				__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 0);//Õ£÷π≤•∑≈
			}
		}
	}
 
}

void buzzer_start()
{
			//∂¡»Î∏Ë«˙

	switch(type){
				case 1:{
					int i;
					for(i=0;music_f[i]==0xff;i++)
					{
						music_f[i]=music_sky_city_f[i];
					
						music_t[i]=music_sky_city_t[i];
					}
								};break;
				case 2:{
					int i;
					for(i=0;music_f[i]==0xff;i++)
					{
						music_f[i]=music_two_tiger_f[i];
					
						music_t[i]=music_two_tiger_t[i];
					}						
								};break;
							}
}
 
void buzzer_music()
{ 


	while(1)
	{
		
		tone=music_f[num_m];
		music_tone(&music_scale[tone]);
		num_m=num_m+1;
		if(music_scale[tone]==0xff)
		{
			num_m =0;
		}
	}
}


