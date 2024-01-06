#include "Ring_Buffer.h"

void Add_Element(Ring_Buffer_t *ring_buffer, uint8_t data)
{
	//Input data to underlying buffer at location of the head
	ring_buffer->buffer[ring_buffer->head] = data;
	//Increment the head by 1
	ring_buffer->head++;

	//Check is head is the same size as the array, indicating it is at the end of the array
	if(ring_buffer->head == ring_buffer->size)
	{
		//If head is same size as array, reset its index value to 0
		ring_buffer->head = 0;
	}
}

uint8_t Get_Element(Ring_Buffer_t *ring_buffer)
{
	//Varibale to hold the data element
	const uint8_t data = ring_buffer->buffer[ring_buffer->tail];
	//Assigning the data element to the value in the array at index of tail

	//Check if the tail is same size as underlying buffer
	if(ring_buffer->tail == ring_buffer->size)
	{
		//If tail is same size as ring buffer, reset its position to 0
		ring_buffer->tail = 0;
	}

	return data;
}

uint8_t Peek_Element(const Ring_Buffer_t *ring_buffer)
{
	return ring_buffer->buffer[ring_buffer->tail];
}

uint8_t Buffer_Empty(const Ring_Buffer_t *ring_buffer)
{
	if((ring_buffer->head) == (ring_buffer->tail))
	{
		return 1;
	}

	else
	{
		return 0;
	}
}

uint8_t Buffer_Full(const Ring_Buffer_t *ring_buffer)
{
	uint8_t indx_after_head = (ring_buffer->head + 1);
	if(indx_after_head == ring_buffer->size)
	{
		indx_after_head = 0;
	}

	if(indx_after_head == (ring_buffer->tail))
	{
		return 1;
	}

	else
	{
		return 0;
	}
}


