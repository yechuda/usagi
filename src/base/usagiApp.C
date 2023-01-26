#include "usagiApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
usagiApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  return params;
}

usagiApp::usagiApp(InputParameters parameters) : MooseApp(parameters)
{
  usagiApp::registerAll(_factory, _action_factory, _syntax);
}

usagiApp::~usagiApp() {}

void
usagiApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"usagiApp"});
  Registry::registerActionsTo(af, {"usagiApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
usagiApp::registerApps()
{
  registerApp(usagiApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
usagiApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  usagiApp::registerAll(f, af, s);
}
extern "C" void
usagiApp__registerApps()
{
  usagiApp::registerApps();
}
