// cmdYuxinPlugin.cpp : command file
//

#include "stdafx.h"
#include "YuxinFirstPluginPlugIn.h"

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//
// BEGIN YuxinPlugin command
//

#pragma region YuxinPlugin command

// Do NOT put the definition of class CCommandYuxinPlugin in a header
// file. There is only ONE instance of a CCommandYuxinPlugin class
// and that instance is the static theYuxinPluginCommand that appears
// immediately below the class definition.

class CCommandYuxinPlugin : public CRhinoCommand
{
public:

  CCommandYuxinPlugin() = default;
  ~CCommandYuxinPlugin() = default;

  UUID CommandUUID() override
  {
    // {D6304EA5-26E5-4769-B21C-4D1C9608B116}
    static const GUID YuxinPluginCommand_UUID = 
    {0xd6304ea5,0x26e5,0x4769,{0xb2,0x1c,0x4d,0x1c,0x96,0x08,0xb1,0x16}};
    return YuxinPluginCommand_UUID;
  }

  // Returns the English command name.
  // If you want to provide a localized command name, then override 
  // CRhinoCommand::LocalCommandName.
  const wchar_t* EnglishCommandName() override { 
      return L"YuxinHelloRhino"; 
  }

  // Rhino calls RunCommand to run the command.
  CRhinoCommand::result RunCommand(const CRhinoCommandContext& context) override;
};

// The one and only CCommandYuxinPlugin object
// Do NOT create any other instance of a CCommandYuxinPlugin class.
static class CCommandYuxinPlugin theYuxinPluginCommand;

CRhinoCommand::result CCommandYuxinPlugin::RunCommand(const CRhinoCommandContext& context)
{
  ON_wString str;
  str.Format(L"The \"%s\" command is under construction.\n", EnglishCommandName());
  const wchar_t* pszStr = static_cast<const wchar_t*>(str);
  if (context.IsInteractive())
    RhinoMessageBox(pszStr, YuxinFirstPluginPlugIn().PlugInName(), MB_OK);
  else
    RhinoApp().Print(pszStr);

  // TODO: Return one of the following values:
  //   CRhinoCommand::success:  The command worked.
  //   CRhinoCommand::failure:  The command failed because of invalid input, inability
  //                            to compute the desired result, or some other reason
  //                            computation reason.
  //   CRhinoCommand::cancel:   The user interactively canceled the command 
  //                            (by pressing ESCAPE, clicking a CANCEL button, etc.)
  //                            in a Get operation, dialog, time consuming computation, etc.

  return CRhinoCommand::success;
}

#pragma endregion

//
// END YuxinPlugin command
//
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
