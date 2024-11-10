/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:13:38 by imontero          #+#    #+#             */
/*   Updated: 2023/12/22 13:16:16 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main()
{

/*Se crea un puntero a la interfaz IMateriaSource 
y se le asigna la dirección de un nuevo objeto de la clase MateriaSource. 
Esta clase implementa la interfaz IMateriaSource y proporciona funcionalidades 
para aprender y crear materiales.*/
		std::cout << std::endl << "*  IMateriaSource* src = new MateriaSource();" << std::endl << std::endl;
	IMateriaSource* src = new MateriaSource();
		std::cout << std::endl << "-------------------" << std::endl << std::endl;


/*Se aprenden dos tipos de materiales (Ice y Cure) y se almacenan 
en el objeto src (en array de materias). 
Esto significa que el objeto src ahora tiene conocimiento
sobre cómo crear estos materiales.*/
		std::cout << std::endl << "* src->learnMateria(new Ice());" << std::endl << std::endl;
	src->learnMateria(new Ice());
		std::cout << std::endl << "-------------------" << std::endl << std::endl;


		std::cout << std::endl << "* src->learnMateria(new Cure());" << std::endl << std::endl;
	src->learnMateria(new Cure());
		std::cout << std::endl << "-------------------" << std::endl << std::endl;
		

/*Se crea un puntero a la interfaz ICharacter y se le asigna la dirección 
de un nuevo objeto de la clase Character.
Se proporciona el nombre "PEPIÑO" al constructor.*/
		std::cout << std::endl << "* ICharacter* me = new Character('PEPIÑO');" << std::endl << std::endl;
	ICharacter* me = new Character("PEPIÑO");
		std::cout << std::endl << "------------------" << std::endl << std::endl;


/* Se declara un puntero a la clase AMAteria pero no se asigna nada a el */	
		std::cout << std::endl << "* AMateria* tmp;" << std::endl << std::endl;
	AMateria* tmp;
		std::cout << std::endl << "------------------" << std::endl << std::endl;
	
	
/*Se crea un material de tipo "ice" */
		std::cout << std::endl << "*  tmp = src->createMateria('ice');" << std::endl << std::endl;
	tmp = src->createMateria("ice");
		std::cout << std::endl << "-------------------" << std::endl << std::endl;
		

/*se equipa al personaje me(PEPIÑO)	en el inventario (array de materias)*/	
		std::cout << std::endl << "*  me->equip(tmp);" << std::endl << std::endl;
	me->equip(tmp);
		std::cout << std::endl << "-------------------" << std::endl << std::endl;
	
		std::cout << std::endl << "*  tmp = src->createMateria('cure');" << std::endl << std::endl;
	tmp = src->createMateria("cure");
		std::cout << std::endl << "-------------------" << std::endl << std::endl;

		std::cout << std::endl << "*  me->equip(tmp);" << std::endl << std::endl;
	me->equip(tmp);
		std::cout << std::endl << "-------------------" << std::endl << std::endl;
	
	
/*Se crea otro puntero a la interfaz ICharacter 
y se le asigna la dirección de un nuevo objeto de la clase Character. 
Se proporciona el nombre "MARIATERESA" al constructor.*/
		std::cout << std::endl << "*  ICharacter* bob = new Character('MARIATERESA');" << std::endl << std::endl;
	ICharacter* bob = new Character("MARIATERESA");
		std::cout << std::endl << "-------------------" << std::endl << std::endl;
	
	


/*El personaje me utiliza sus materiales en las posiciones 0 y 1 
del inventario en el personaje bob(MARIATERESA).*/
		std::cout << std::endl << "*  me->use(0, *bob);" << std::endl << std::endl;	
	me->use(0, *bob);
		std::cout << std::endl << "-------------------" << std::endl << std::endl;
	
		std::cout << std::endl << "*  me->use(1, *bob);" << std::endl << std::endl;
	me->use(1, *bob);
		std::cout << std::endl << "-------------------" << std::endl << std::endl;
	
	
/* Se liberan los recursos alocados */
		std::cout << std::endl << "*  delete bob;" << std::endl << std::endl;
	delete bob;
		std::cout << std::endl << "-------------------" << std::endl << std::endl;
	
	

		std::cout << std::endl << "*  delete me;" << std::endl << std::endl;
	delete me;
		std::cout << std::endl << "-------------------" << std::endl << std::endl;
	
	

		std::cout << std::endl << "*  delete src;" << std::endl << std::endl;
	delete src;
		std::cout << std::endl << "-------------------" << std::endl;
		std::cout << "-------------------" << std::endl << std::endl;
	
	return 0;
}
