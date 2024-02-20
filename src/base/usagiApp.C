#include "usagiApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
usagiApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

usagiApp::usagiApp(InputParameters parameters) : MooseApp(parameters)
{
  usagiApp::registerAll(_factory, _action_factory, _syntax);
}

usagiApp::~usagiApp() {}

void 
usagiApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<usagiApp>(f, af, s);
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
