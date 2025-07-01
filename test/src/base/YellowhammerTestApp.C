//* This file is part of the MOOSE framework
//* https://mooseframework.inl.gov
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "YellowhammerTestApp.h"
#include "YellowhammerApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
YellowhammerTestApp::validParams()
{
  InputParameters params = YellowhammerApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

YellowhammerTestApp::YellowhammerTestApp(const InputParameters & parameters) : MooseApp(parameters)
{
  YellowhammerTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

YellowhammerTestApp::~YellowhammerTestApp() {}

void
YellowhammerTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  YellowhammerApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"YellowhammerTestApp"});
    Registry::registerActionsTo(af, {"YellowhammerTestApp"});
  }
}

void
YellowhammerTestApp::registerApps()
{
  registerApp(YellowhammerApp);
  registerApp(YellowhammerTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
YellowhammerTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  YellowhammerTestApp::registerAll(f, af, s);
}
extern "C" void
YellowhammerTestApp__registerApps()
{
  YellowhammerTestApp::registerApps();
}
