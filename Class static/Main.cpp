#include <iostream>
#include <string>

// static - относительно элементов класса




class SequencesGenerator {
private:

	static int n; // переместьили переменную в глобальную память программы
	// неконстантные статические поля нельзя использовать без инициализации
	// и их определение должно происходить вне класса 

	// константные статические поля допустимо определять в теле класса
public:

	void M00()const{}

	static void M01(){}

	// позволяет создавать вызовы метода без создания объекта класса 
	static int NextNum() {
		//static int n;
		//M00(); нет доступа так как нет указателя на себя 
		M01();
		return n++;
	}

	// В статическом методе нельзя обращаться у нестатическим элементам класса 
};

// определение статических полей всегда выносим в файл кода
int SequencesGenerator::n{ 10 };



//такая функция будет запрещена для вызова других кодовых файлах программы 
static int NumSequense() {
	static int n{}; // переместьили переменную в глобальную память программы 
	return n++;
}

void DogDemo();

int main() {
	setlocale(0, "");
	

	for (int i = 0; i < 5; i++) {
		std::cout << NumSequense() << '\n';
	}

	//SequencesGenerator obj;
	for (int i = 0; i < 5; i++) {
		std::cout << SequencesGenerator::NextNum() << '\n';
	}


	DogDemo();









	return 0;
}


// создать класс который без создания объекта мог бы сообщать своё название 
// данный класс сделать на примере животного 
// включить в класс методы которые бы пользовались статическим методом для 
// формирования сообщения на экране

class Dog {
public:
	static void Name() {
		std::cout << name;
	}

	void Say()const {
		Name();
		std::cout << " Bark\n";
	}

	void Feed(std::string food)const {
		Name();
		std::cout << " eat: " << food << '\n';
	}

private:
	static std::string name; //объявление 

};

std::string Dog::name{"Dog"}; 


void DogDemo() {
	std::cout << "We have a ";
	Dog::Name();
	std::cout << '\n';
	Dog dog;
	dog.Feed("Bone");
	dog.Say();
}