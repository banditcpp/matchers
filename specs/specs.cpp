#include <iostream>
#include <specs/specs.h>

std::vector<std::function<void()>> specs;
static unsigned indent = 0;
static std::function<void()> the_one_before_each_func = []{};

void before_each(std::function<void()> func) {
	the_one_before_each_func = func;
}

static void output(const std::string str) {
	if (indent == 0) {
		std::cout << str << std::endl;
	} else {
		for (unsigned i = 0; i < indent-1; ++i) {
			std::cout << "   ";
		}
		std::cout << " * " << str << std::endl;
	}
}

void describe(const std::string str, std::function<void()> func) {
	output(str);
	the_one_before_each_func = []{};
	indent++;
	func();
	indent--;
}

void it(const std::string str, std::function<void()> func) {
	the_one_before_each_func();
	output(str);
	func();
}

int main() {
	for (auto spec : specs) {
		spec();
	}
	return 0;
}
