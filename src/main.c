/*DERS_121*/
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

uint32_t myRandomNumber;
uint32_t yazi,tura,count;
float oranYazi,oranTura;

void RNG_Config()
{
	RCC_AHB2PeriphClockCmd(RCC_AHB2Periph_RNG,ENABLE);

	RNG_Cmd(ENABLE);
}

void Delay(uint32_t time)
{
	while(time--);
}

int main(void)
{
	RNG_Config();
  while (1)
  {
	  myRandomNumber = RNG_GetRandomNumber();
	  Delay(21000000);

	  count++;

	  if(count <= 1000000)
	  {
		  if(myRandomNumber < 2147483648)
			  yazi++;
		  else
			  tura++;
	  }
	  else
	  {
		  oranYazi = (float)yazi / 10000000;
		  oranTura = (float)tura / 10000000;
		  RNG_Cmd(DISABLE);
	  }
  }
}


/*
 * Callback used by stm32f4_discovery_audio_codec.c.
 * Refer to stm32f4_discovery_audio_codec.h for more info.
 */
void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer, uint32_t Size){
  /* TODO, implement your code here */
  return;
}

/*
 * Callback used by stm324xg_eval_audio_codec.c.
 * Refer to stm324xg_eval_audio_codec.h for more info.
 */
uint16_t EVAL_AUDIO_GetSampleCallBack(void){
  /* TODO, implement your code here */
  return -1;
}
