#include <string>

class	Zombie
{
	public:
		Zombie(void);
		Zombie(std::string name);
		~Zombie(void);
		void	setName(std::string name);
		void	announce( void ) const;

	private:
		std::string	_name;
};

Zombie*	zombieHorde(int N, std::string name);
