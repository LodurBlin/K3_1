#ifndef CL_BASE_H
#define CL_BASE_H
#include <vector>
#include <memory>
#include <string>


class cl_base {
	std::string ob_name; //наименование
	int sost=0; //состояние готовности
	std::string readiness = " is not ready"; //готовность строковая
public:
	cl_base* p_predok{}; //указатель на голову

	std::vector<std::unique_ptr<cl_base>> spinogrizi; //массив указателей

	cl_base(std::string name, cl_base* p_predok = 0) : ob_name{ name }, p_predok{ p_predok } {}; //конструктор

	void set_name(std::string name) { //opred imeni
		ob_name = name;
	}
	std::string get_name() const { //poluch imeni
		return ob_name;
	}
	void add_spinogriz(std::unique_ptr<cl_base>&&);

	void print_hierarchy(int offset); //vivod

	cl_base* kto_otez(); //poluch ukaz

	std::unique_ptr<cl_base> uproot(); //pereopred
	void move_to(cl_base* destination);//drugomu chelu

	cl_base* search(std::string wanted); //poisk ob po imeni

	void print_sost(int offset); //vivod otmetok

	void set(int n); //ustanovit otmetku

	void preparing();//ввод готовности
};
#endif
/*
Расширить функциональность базового класса:
 - метод поиска объекта на дереве иерархии по имени (метод возвращает указатель на найденный объект или nullptr);
 - метод вывода дерева иерархии объектов;
 - метод вывода дерева иерархии объектов и отметок их готовности;
 - метод установки готовности объекта реализовать (доработать) следующим образом.

 Готовность для каждого объекта устанавливается индивидуально. Готовность задается посредством любого отличного от нуля целого числового значения, которое
присваивается свойству состояния объекта. Объект переводится в состояние готовности, если все объекты вверх по иерархии до корневого включены, иначе установка
готовности игнорируется.
При отключении головного, отключаются все объекты от него по иерархии вниз по ветке. Свойству состояния объекта присваивается значение нуль.



*/
