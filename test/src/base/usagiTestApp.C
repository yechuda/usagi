//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "usagiTestApp.h"
#include "usagiApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
usagiTestApp::validParams()
{
  InputParameters params = usagiApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

usagiTestApp::usagiTestApp(InputParameters parameters) : MooseApp(parameters)
{
  usagiTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

usagiTestApp::~usagiTestApp() {}

void
usagiTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  usagiApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"usagiTestApp"});
    Registry::registerActionsTo(af, {"usagiTestApp"});
  }
}

void
usagiTestApp::registerApps()
{
  registerApp(usagiApp);
  registerApp(usagiTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
usagiTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  usagiTestApp::registerAll(f, af, s);
}
extern "C" void
usagiTestApp__registerApps()
{
  usagiTestApp::registerApps();
}
