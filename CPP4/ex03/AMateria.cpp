#include "AMateria.hpp"

AMateria::AMateria() : t("Materia") {}

AMateria::AMateria(std::string const & type) : t(type) {}

AMateria::AMateria(const AMateria& other)
{
	t = other.t;
}

AMateria& AMateria::operator=(const AMateria& other) {
	(void)other;
	return (*this);
}

AMateria::~AMateria() {}

std::string const & AMateria::getType() const { return(t); }

void AMateria::use(ICharacter& target)
{
	std::cout << target.getName() << "* uses unknown materia* " << std::endl;
}
