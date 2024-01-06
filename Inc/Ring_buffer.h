#include <stdint.h>

#ifndef RING_BUFFER_H_
#define RING_BUFFER_H_

typedef struct
{
	uint8_t *buffer;
	uint8_t size;
	uint8_t head;
	uint8_t tail;

}Ring_Buffer_t;

void Add_Element(Ring_Buffer_t *ring_buffer, uint8_t data);
uint8_t Get_Element(Ring_Buffer_t *ring_buffer);
uint8_t Peek_Element(const Ring_Buffer_t *ring_buffer);
uint8_t Buffer_Full(const Ring_Buffer_t *ring_buffer);
uint8_t Buffer_Empty(const Ring_Buffer_t *ring_buffer);

#endif /* RING_BUFFER_H_ */
