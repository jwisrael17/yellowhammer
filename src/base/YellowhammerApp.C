#include "YellowhammerApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
YellowhammerApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

YellowhammerApp::YellowhammerApp(const InputParameters & parameters) : MooseApp(parameters)
{
  YellowhammerApp::registerAll(_factory, _action_factory, _syntax);
}

YellowhammerApp::~YellowhammerApp() {}

void
YellowhammerApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAllObjects<YellowhammerApp>(f, af, syntax);
  Registry::registerObjectsTo(f, {"YellowhammerApp"});
  Registry::registerActionsTo(af, {"YellowhammerApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
YellowhammerApp::registerApps()
{
  registerApp(YellowhammerApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
YellowhammerApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  YellowhammerApp::registerAll(f, af, s);
}
extern "C" void
YellowhammerApp__registerApps()
{
  YellowhammerApp::registerApps();
}
