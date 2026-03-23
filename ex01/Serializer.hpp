#include <string>
#include <stdint.h>

typedef struct Data
{
	int			id;
	std::string	name;

} Data;

class Serializer
{
	public:
		static uintptr_t	serialize(Data *ptr);
		static Data			*deserialize(uintptr_t raw);
};
