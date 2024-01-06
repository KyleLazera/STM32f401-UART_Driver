#include "stm32f401_uart.h"
#include "Ring_buffer.h"
#include <stdint.h>

#define UART_BUFFER_SIZE (5)
uint8_t buffer[UART_BUFFER_SIZE];
Ring_Buffer_t Ring_Buffer_TX = {.buffer = buffer, .size = sizeof(buffer)};

/*
 * This example displays another form of UART transmission using interrupts. This is a significantly more effective method than
 * polling, and is recommended for more advanced programs. In this program, the interrupt handler is called whenever the TXE flag
 * (Transfer data register empty) is raised.
 *
 * This is a simple example where the output will be the message continously printed to the serial mointor, however, it can be used
 * much more efficiently to debug. For example, using this message to indicate a push-button is pressed.
 */


UART_Config_t UART2;

uint8_t read_data;

char message[50] = "Button is Pressed\r\n";



int main()
{


	//Configure the EXTI
	GPIO_EXTIConfig(EXTI_PortC, Pin13, EXTI_RisingTrigger);

	//Configuring UART2 to be in reciever mode and have a badrate of 115200.
	UART_Config(&UART2, USART2, UART_MODE_TX, 115200);

	UART_Init(&UART2);

	//Initiliaing the UART interrupt - This function must be called after UART_Init()
	UART_Interrupt_Init(&UART2, UART_TXEIE_Enable);

	while(1)
	{

	}
}

//Interrupt Handler Function
void USART2_IRQHandler(void)
{
	//Monitoring the TXE flag to ensure it is raised
	if((USART2->SR) & (UART_SR_TXE_Mask))
	{
		for(int i = 0; i < 16; i++)
		{
			WriteByte(&UART2, message[i]);
		}
		//PrintData(&UART2, message);
		RCC_APB1Cmd(USART2_Enable, DISABLE);
	}
}






