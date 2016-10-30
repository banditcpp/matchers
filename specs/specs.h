#ifndef MATCHERS_SPECS
#define MATCHERS_SPECS

#include <matchers/matchers.h>
#include <functional>
#include <string>
#include <vector>

extern std::vector<std::function<void()>> specs;

struct spec_register {
	spec_register(std::function<void()> func) {
		specs.push_back(func);
	}
};

#define SPEC_BEGIN(name) static spec_register nanobandit([]{
#define SPEC_END });

extern void before_each(std::function<void()> func);
extern void describe(const std::string str, std::function<void()> func);
inline void xdescribe(const std::string str, std::function<void()> func) {};
extern void it(const std::string str, std::function<void()> func);

#define AssertThrows(EXCEPTION, CODE) { \
	bool caught = false; \
	try { \
		CODE; \
	} catch (EXCEPTION &e) { \
		caught = true; \
	} \
	if (!caught) throw std::runtime_error("test failed"); \
}

#endif
