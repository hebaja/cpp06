#include "Serializer.hpp"

uintptr_t	Serializer::serialize(Data *ptr)
{
	uintptr_t	addr;

	addr = (uintptr_t)ptr;
	return (addr);
}

Data	*Serializer::deserialize(uintptr_t raw)
{
	Data	*d;
	
	d = (Data*)raw;
	return (d);
}
