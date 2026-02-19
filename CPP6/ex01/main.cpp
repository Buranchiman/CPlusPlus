#include "Serializer.hpp"

int	main()
{
	Data	*data = new Data;
	uintptr_t	tmp;

	data->content = "banane";
	tmp = Serializer::serialize(data);
	std::cout << "content of data was " << data->content << std::endl;
	data = Serializer::deserialize(tmp);
	std::cout << "content of data is now " << data->content << std::endl;
	delete data;
}
