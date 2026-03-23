#include "Serializer.hpp"
#include <iostream>

int	main()
{
	Data		data;
	Data		*ret_data;
	uintptr_t	ptr;

	data.id = 0;
	data.name = "Tux";

	std::cout << "Id: " << data.id << " / Name: " << data.name << " / Address: " << &data << std::endl;

	ptr = Serializer::serialize(&data);
	std::cout << "Id: " << data.id << " / Name: " << data.name << " / Int address: " << ptr << std::endl;
	
	ret_data = Serializer::deserialize(ptr);
	std::cout << "Id: " << ret_data->id << " / Name: " << ret_data->name << " / Int address: " << ret_data << std::endl;

	return (0);
}
