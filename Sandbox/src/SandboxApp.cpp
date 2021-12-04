#include <Positron.h>

class Sandbox : public Positron::Application
{
public:
	Sandbox() {}

	~Sandbox() {}
};

Positron::Application* Positron::CreateApplication()
{
	return new Sandbox();
}