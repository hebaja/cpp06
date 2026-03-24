#include "Serializer.hpp"

uintptr_t	Serializer::serialize(Data *ptr)
{
	uintptr_t	addr;

	addr = reinterpret_cast<uintptr_t>(ptr);
	return (addr);
}

Data	*Serializer::deserialize(uintptr_t raw)
{
	Data	*d;
	
	d = reinterpret_cast<Data*>(raw);
	return (d);
}
