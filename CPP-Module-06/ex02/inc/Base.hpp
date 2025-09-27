#ifndef BASE_HPP
# define BASE_HPP

class Base
{
    public:
		Base	*generate(void);
		void	identify(Base* p);
        virtual ~Base();

    private:
        Base();

};

#endif
